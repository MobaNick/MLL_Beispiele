        #define FASTLED_INTERNAL // Disable version number message in FastLED library (looks like an error)
#include "FastLED.h"     // The FastLED library must be installed in addition if you got the error message "..fatal error: FastLED.h: No such file or directory"
                         // Arduino IDE: Sketch / Include library / Manage libraries                    Deutsche IDE: Sketch / Bibliothek einbinden / Bibliothek verwalten
                         //              Type "FastLED" in the "Filter your search..." field                          "FastLED" in das "Grenzen Sie ihre Suche ein" Feld eingeben
                         //              Select the entry and click "Install"                                         Gefundenen Eintrag auswaehlen und "Install" anklicken

#include "MobaLedLib.h"  // Use the Moba Led Library

#define NUM_LEDS     5  // Number of LEDs with some spare channels (Maximal 256 RGB LEDs could be used)
#define LED_DO_PIN   6   // Pin D6 is connected to the LED stripe
#define SWITCH_PIN_Disco   7   // Pin D7 is connected to the switch

//House
#define HOUSE_MIN_T  5  // Minimal time [s] to the next event (1..255) //DEFAULT: 50
#define HOUSE_MAX_T 15  // Maximal random time [s]   //DEFAULT: 150

#define Disco_OFF 150
#define Disco_ON 151



//*******************************************************************
// *** Configuration array which defines the behavior of the LEDs ***
MobaLedLib_Configuration()
  {
    //   LED:                   First LED number in the stripe
   //    |    InCh:            Input channel. Here the special input 1 is used which is always on
   //    |    |    On_Min:     Minimal number of active rooms. At least two rooms are illuminated.
   //    |    |    |   On_Max: Number of maximal active lights.
   //    |    |    |   |       rooms: List of room types (see documentation for possible types).
   //    |    |    |   |       |

  //µlopkRGB_Heartbeat(NUM_LEDS-4)
  Flash(0, C1, Disco_ON, 201, 100 ms, 750 ms)
  Flash(0, C2, Disco_ON, 202, 150 ms, 800 ms)
  Flash(0, C3, Disco_ON, 203, 75 ms, 900 ms)
  Flash(1, C1, Disco_ON, 204, 100 ms, 750 ms)
  Flash(1, C2, Disco_ON, 205, 150 ms, 800 ms)
  Flash(1, C3, Disco_ON, 206, 75 ms, 900 ms)
  Flash(2, C1, Disco_ON, 207, 100 ms, 750 ms)
  Flash(2, C2, Disco_ON, 208, 150 ms, 800 ms)
  Flash(2, C3, Disco_ON, 209, 75 ms, 900 ms)
  Flash(3, C1, Disco_ON, 210, 100 ms, 750 ms)
  Flash(3, C2, Disco_ON, 211, 150 ms, 800 ms)
  Flash(3, C3, Disco_ON, 212, 75 ms, 900 ms)

  House(0, Disco_OFF,1,1,ROOM_BRIGHT)
  House(1, Disco_OFF,1,1,ROOM_BRIGHT)
  House(2, Disco_OFF,1,1,ROOM_BRIGHT)
  House(3, Disco_OFF,1,1,ROOM_BRIGHT)
  House(4, Disco_OFF,1,1,ROOM_BRIGHT)
  
  EndCfg // End of the configuration
  };
//*******************************************************************


CRGB leds[NUM_LEDS];     // Define the array of leds

MobaLedLib_Create(leds); // Define the MobaLedLib instance

LED_Heartbeat_C LED_Heartbeat(LED_BUILTIN); // Use the build in LED as heartbeat
//----------
void setup(){
//----------
// This function is called once to initialize the program
//
  FastLED.addLeds<NEOPIXEL, LED_DO_PIN>(leds, NUM_LEDS); // Initialize the FastLED library

  pinMode(SWITCH_PIN_Disco, INPUT_PULLUP); // Activate an internal pullup resistor for the input pin
}

//---------
void loop(){
//---------
// This function contains the main loop which is executed continuously
//
  MobaLedLib.Set_Input(Disco_ON, digitalRead(SWITCH_PIN_Disco));
  MobaLedLib.Set_Input(Disco_OFF, !digitalRead(SWITCH_PIN_Disco));

  MobaLedLib.Update();    // Update the LEDs in the configuration

  FastLED.show();         // Show the LEDs (send the leds[] array to the LED stripe)

  LED_Heartbeat.Update(); // Update the heartbeat LED. This must be called periodically in the loop() function.
}
