#include <SPI.h>
#include "printf.h"
#include "RF24.h"

#define CE_PIN 7
#define CSN_PIN 8
// instantiate an object for the nRF24L01 transceiver
RF24 radio(CE_PIN, CSN_PIN);

uint64_t address[6] = { 0x7878787878LL,
                        0xB3B4B5B6F1LL,
                        0xB3B4B5B6CDLL,
                        0xB3B4B5B6A3LL,
                        0xB3B4B5B60FLL,
                        0xB3B4B5B605LL };

struct PayloadStruct {
  unsigned long nodeID;
  unsigned long payloadID;
  uint8_t counter;
  char message[7];
};
PayloadStruct payload;

// Function Protoype
void setRole();


// Dummy example variables
char role = 'R';
int graphValue[3] = {100};
int Value = 0;

void setup(){
  if (!radio.begin()) {while (1) {}}
  radio.setPALevel(RF24_PA_LOW);
  radio.enableDynamicPayloads();
  radio.enableAckPayload();
  radio.setAutoAck("TRUE");
  radio.setPayloadSize(sizeof(payload));
  setRole();


  gBegin(34236); 

}


void loop(){
  // **** Main update call for the guino
  guino_update();

      if (role == 'R'){

        uint8_t pipe;
        int n;
            if (radio.available(&pipe)) {              // is there a payload? get the pipe number that recieved it
              uint8_t bytes = radio.getDynamicPayloadSize();  // get the size of the payload
              PayloadStruct received;
              radio.read(&received, bytes);             // fetch payload from FIFO
              n = int(received.nodeID);
              graphValue[n] = int(received.payloadID);
              //Value = int(received.payloadID);
            
              payload.counter = received.counter + 70;
              // load the payload for the first received transmission on pipe 0
              payload.payloadID = 0;
              payload.counter = 0;
              
              radio.writeAckPayload(1, &payload, sizeof(payload));
            
            }
      //gUpdateValue(&Value);
      gUpdateValue(&graphValue[n]);
      
      }
  

      //role = 0;
      //setrole();
      //delay(5000);

}




// This is where you setup your interface 
void gInit(){
  //gAddToggle("MODE",&roleToggle);
  //gAddSpacer(1); 

  //gAddSpacer(1);
  //flexLabelId = gAddLabel("LIVE LABEL",2);
  //gAddSpacer(1);

  
  //gAddSlider(3,127,"AMPLITUDE", &amplitude);


  //gAddColumn();

  gAddLabel("GRAPHS",1);
  gAddSpacer(1);

  // Last parameter in moving graph defines the size 10 = normal
  //gAddMovingGraph("Robot 1",0,255, &Value, 10);
  //gAddMovingGraph("Robot 1",0,255, &graphValue[1], 10);
  //gAddMovingGraph("Robot 1",0,255, &graphValue[2], 10);

  gAddMovingGraph("Robot 1",0,255, &graphValue[0], 10);
  gAddMovingGraph("Robot 2",0,255, &graphValue[1], 10);
  gAddMovingGraph("Robot 3",0,255, &graphValue[2], 10);

  
  
  
  //gAddFixedGraph("Latency",0,255,100,&graphValue[1],10);

  //gAddMovingGraph("POTMETER",0,1023, &potMeter, 10);
  
  //gAddSlider(0,1023,"POTMETER",&potMeter);

}

// Method called everytime a button has been pressed in the interface.
void gButtonPressed(int id){}

void gItemUpdated(int id){}

void setRole() {
  if (role == 'R') {
    // For the RX node

    // Set the addresses for all pipes to TX nodes
    for (uint8_t i = 0; i < 6; ++i)
      radio.openReadingPipe(i, address[i]);

    radio.startListening();  // put radio in RX mode

  } else {
    // For the TX node

    // set the payload's nodeID & reset the payload's identifying number
    payload.nodeID = role;
    payload.payloadID = 0;

    // Set the address on pipe 0 to the RX node.
    radio.stopListening();  // put radio in TX mode
    radio.openWritingPipe(address[role]);

    // According to the datasheet, the auto-retry features's delay value should
    // be "skewed" to allow the RX node to receive 1 transmission at a time.
    // So, use varying delay between retry attempts and 15 (at most) retry attempts
    radio.setRetries(((role * 3) % 12) + 3, 15);  // maximum value is 15 for both args
  }
}  // setRole

