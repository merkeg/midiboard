#include <Arduino.h>
#include <Control_Surface.h>

USBMIDI_Interface midi;

CCPotentiometer pot1 { A0, {MIDI_CC::General_Purpose_Controller_1, CHANNEL_1} };
CCPotentiometer pot2 { A1, {MIDI_CC::General_Purpose_Controller_2, CHANNEL_1} };
CCPotentiometer pot3 { A2, {MIDI_CC::General_Purpose_Controller_3, CHANNEL_1} };
CCPotentiometer pot4 { A3, {MIDI_CC::General_Purpose_Controller_4, CHANNEL_1} };

const AddressMatrix<4, 4> buttonAddresses = {{
  { 1, 5, 9, 13},
  { 2,  6, 10, 14},
  { 3,  7, 11, 15},
  { 4,  8, 12, 16}
}};

CCButtonMatrix<4, 4> buttonMatrix = {
  {6, 7, 8, 9}, 
  {2, 3, 4, 5}, 
  buttonAddresses,    
  CHANNEL_2 
};


void setup() {
  Control_Surface.begin();
}

void loop() {
  Control_Surface.loop();
}