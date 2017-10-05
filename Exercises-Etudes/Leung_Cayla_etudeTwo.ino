/**********************ETUDE 2 CART 360 2017*******************************
 * WELCOME! 
 * THE PURPOSE OF THIS EXERCISE IS TO DESIGN A VERY SIMPLE KEYBOARD (5 KEYS)
 * WHICH ALLOWS YOU TO PLAY LIVE, RECORD, AND PLAYBACK. 
 * THERE WILL BE A BUTTON WHICH WHEN PRESSED WILL TAKE THE USER TO THE NEXT MODE:
 * THERE ARE 5 POSSIBLE MODES
 * 0 ==  reset    ==   led off == also resets
 * 1 ==  live     ==   led BLUE
 * 2 ==  record   ==   led RED
 * 3 ==  play     ==   led GREEN
 * 4 ==  loopMODE ==   led PURPLE
 * 
 * ADDITIONALLY - WHEN THE USER CHANGES MODE, 
 * THE RGB LED WILL CHANGE COLOR (ACCORDING TO THE SPECIFICATIONS)

 * PLEASE FOLLOW THE INSTRUCTIONS IN THE COMMENTS:
 * DO NOT ADD ANY MORE FUNCTION DEFINITIONS 
 * ONLY IMPLEMENT THE FUNCTION DEFINITIONS SUPPLIED
 * THERE IS NO NEED TO ADD ANY NEW VARIABLES OR CONSTANTS
 * PROVIDE COMMENTS FOR ANY OF THE CODE IMPLEMENTED
 * GOOD LUCK!
 */
/**** CONSTANTS ********************************************************/

#define BUTTON_MODE_PIN 2 // Button to change the mode

// constants for RGB LED
#define LED_PIN_R 9 // R PIN 
#define LED_PIN_G 6 // G PIN
#define LED_PIN_B 5 // B PIN

// constant for note in (button-resistor ladder on breadboard)
# define NOTE_IN_PIN A0

//constant for max number of notes in array
#define MAX_NOTES 16

// a constant for duration
const int duration =200;

// constant for pin to output for buzzer 
#define BUZZER_PIN 3 // PWM

/******** VARIABLES *****************************************************/
// counter for how many notes we have
int countNotes =0;
// array to hold the notes played (for record/play mode)
int notes [MAX_NOTES]; 
int mode =0; // start at off

/*************************************************************************/


/**********************SETUP() DO NOT CHANGE*******************************/
// Declare pin mode for the single digital input
void setup()
{
  pinMode(BUTTON_MODE_PIN, INPUT);
  //IMPLEMENT
  
   //pinMode allows to output LED light
  
   pinMode(LED_PIN_R, OUTPUT);
   pinMode(LED_PIN_G, OUTPUT);
   pinMode(LED_PIN_B, OUTPUT);
   //Serial.begin(9600);
  //pinMode allows to output buzzer sound
   pinMode(BUZZER_PIN, OUTPUT);
}

/**********************LOOP() DO NOT CHANGE *******************************
 * INSTRUCTIONS: 
 * There is NO NEED to change the loop - it establishes the flow of the program
 * We call here 3 functions repeatedly:
 * 1: chooseMode(): this function will determine the mode that your program is in 
 * based on if the button (linked to the BUTTON_MODE_PIN) was pressed
 * 2: setRGB(): will set the color of the RGB LED based on the value of the mode variable
 * 3: selectMode(): will determine which function to call based on the value of the mode variable

**************************************************************************/
void loop()
{
  chooseMode();
  setRGB();
  selectMode();
}
/******************CHOOSEMODE(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * Read the value from the Button (linked to the BUTTON_MODE_PIN) and 
 * if is being pressed then change the mode variable.
 * REMEMBER:
 * mode == 0 is reset 
 * mode == 1 is live
 * mode == 2 is record
 * mode == 3 is play
 * mode == 4 is loopMode
 * Every time the user presses the button, the program will go to the next mode,
 * once it reaches 4, it should go back to mode == 0. 
 * (i.e. if mode ==2 and we press, then mode ==3) ...
**************************************************************************/
void chooseMode(){
  // IMPLEMENT
  
  int buttonState = digitalRead(BUTTON_MODE_PIN);
 // Serial.println(mode);

   // if button is clicked, go to mode 1,else go to mode 2 .... until it reaches mode 4, go back to mode 0. 
  if(buttonState == HIGH){
    if(mode == 0){
      mode = 1;
    }
    else if(mode == 1){
      mode = 2;
    }
    else if(mode == 2){
      mode = 3;
    }
    else if(mode == 3){
      mode = 4;
    }
    else if(mode == 4){
      mode = 0;
    }
    delay(200);
  }
}

/******************SETRGB(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * Depending on the value of the mode variable:
 * if the mode is 0 - RGB LED IS OFF
 * if the mode is 1 - RGB LED IS BLUE
 * if mode is 2 - RGB LED IS RED
 * if mode is 3 - RGB LED IS GREEN
 * if mode is 4 - RGB LED iS PURPLE
 * YOU MUST USE A SWITCH CASE CONSTRUCT (NOT A SERIES OF IF / ELSE STATEMENTS
**************************************************************************/
void setRGB()
{
  
  // LED for case 0 = no color.
  switch (mode){
    case 0:
    digitalWrite(LED_PIN_R, LOW);
    digitalWrite(LED_PIN_G, LOW);
    digitalWrite(LED_PIN_B, LOW);
   
    break;
  // LED for case 1 = blue.
    case 1:
    digitalWrite(LED_PIN_R, LOW);
    digitalWrite(LED_PIN_G, LOW);
    digitalWrite(LED_PIN_B, HIGH);
    break;
  //LED for case 2 = red.
    case 2:
    digitalWrite(LED_PIN_R, HIGH);
    digitalWrite(LED_PIN_G, LOW);
    digitalWrite(LED_PIN_B, LOW);
   
    break;
  //LED for case 3 = green.
    case 3:
    digitalWrite(LED_PIN_R, LOW);
    digitalWrite(LED_PIN_G, HIGH);
    digitalWrite(LED_PIN_B, LOW);
    
    break;
  //LED for case 4 = pink.
    case 4:
    // analog write is for numbers. I choose 20 to obtain a fuschia color: the higher the number the closer to colour red.
    analogWrite(LED_PIN_R, 20);  
    digitalWrite(LED_PIN_G, LOW);
    analogWrite(LED_PIN_B, HIGH);
   
    break;
  }
}
/**********************SELECTMODE() DO NOT CHANGE *******************************
 * INSTRUCTIONS: 
 * There is NO NEED to change this function - it selects WHICH function should run based on the mode variable
 * There are 4 possibilities
 * 1: reset(): this function will reset any arrays etc, and will do nothing else
 * 2: live(): this function will play the corresponding notes 
 * to the user pressing the respective buttons. 
 * NOTE:: the notes played are NOT stored
 * 3: record(): this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * AND will STORE up to 16 consecutive notes in an array.
 * 4: play(): this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * 5: loopMode(): this function will playback any notes stored in the array that were recorded, 
 * BUT unlike the previous mode, you can choose in which sequence the notes are played.
 * REQUIRED: only play notes from the array (no live stuff)

******************************************************************************/
void selectMode()
{
  //selectMode indicates the arduino to do the following : reset, live, play,loopMode. And finally go back to mode 0.
  if(mode ==0) { 
    reset();
  }
  else if(mode ==1) {
    live();
  }
  else if(mode ==2) {
    record();
  }
  
  else if(mode ==3) {
    play();
  }
   
   else if(mode ==4) {
    loopMode();
  }
}
/******************RESET(): IMPLEMENT **************************************
 * INSTRUCTIONS:
 * this function should ensure that any notes recorded are no longer available
**************************************************************************/
void reset()
{
  // IMPLEMENT
  // This allows the arduino to erase and reset at 0. All the notes which were played previously will be deleted.
  countNotes = 0;
  for( int i = 0; i < sizeof(notes)/sizeof(int);  ++i ){
   notes[i] = 0;
   }
  
}
/******************LIVE(): IMPLEMENT **************************************
 * INSTRUCTIONS:
 * this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * NOTE:: the notes played are NOT stored
 * SO: you need read in the input from the analog input (linked to the button-resistor ladder combo)
 * THEN - output the note to the buzzer using the tone() function
**************************************************************************/
void live()
{
    //This allows the user to play their tune. Up to 16 notes because of MAX_NOTES in constants.
    int soundValue;
    soundValue = analogRead(NOTE_IN_PIN);
    //Serial.println(soundValue);
    //Buzzer_pin= button, soundValue = frequency
    tone(BUZZER_PIN, soundValue, duration);
}
/******************RECORD(): IMPLEMENT **********************************
 * INSTRUCTIONS:
 * this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * AND will STORE up to 16 consecutive notes in an array.
 * SO:you need read in the input from the analog input (linked to the button-resistor ladder combo)
 * AND - output the note to the buzzer using the tone() function
 * THEN store that note in the array  - BE CAREFUL - you can only allow for up to MAX_NOTES to be stored
**************************************************************************/
void record()
{
  // IMPLEMENT
   int soundValue;
  soundValue = analogRead(NOTE_IN_PIN);

    // To find 145,click upload and then the serial output, press mode button, then the fifth button. 
   //shows the lowest frequency of the fifth button 
   //This will record the tune, but can only record up to 16 notes.
  if (countNotes < MAX_NOTES && soundValue >= 145 ){  
    //Serial.println(soundValue);
    notes[countNotes] = soundValue;
    countNotes++;
    tone(BUZZER_PIN, soundValue, duration);
    delay(duration);
  }
}
/******************PLAY(): IMPLEMENT ************************************
 * INSTRUCTIONS:
 * this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * SO: you need to go through the array of values (be careful - the user may not have put in MAX_NOTES)
 * READ each value IN ORDER
 * AND output each note to the buzzer using the tone() function
 * ALSO: as long as we are in this mode, the notes are played over and over again
 * BE CAREFUL: make sure you allow for the user to get to another mode from the mode button...
**************************************************************************/
void play()
{
  // IMPLEMENT
  boolean  repeatSound = true;

// This allows the arduino to replay what was recorded previously.
  while (repeatSound){
    for(int i = 0; i <= countNotes; i++){
      tone(BUZZER_PIN, notes[i], duration);
      delay(duration);
      //if mode button is pressed, repeat sound will stop.
       if (digitalRead(BUTTON_MODE_PIN) == HIGH){
       repeatSound = false;
       break;
        }
    }
    
  }
  
}
/******************LOOPMODE(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * SO: you need to go through the array of values (be careful - the user may not have put in MAX_NOTES)
 * READ values IN ANY ORDERING (You MUST use the array - but you can determine your own sequence)
 * AND output each note to the buzzer using the tone() function
 * ALSO: as long as we are in this mode, the notes are played over and over again
 * BE CAREFUL: make sure you allow for the user to get to another mode from the mode button...
**************************************************************************/
void loopMode()
{
  //IMPLEMENT
   boolean  playTune = true;

   //This will play my notes randomly.
   while (playTune){
    for(int i = 0; i <= countNotes; i++){
      // This will allow the notes to play randomly because the value choosen from 0 to i.
      int number = random(0,i);
      tone(BUZZER_PIN, notes[number], duration);
      delay(duration);
      //If mode button is pressed, playTune will stop.
       if (digitalRead(BUTTON_MODE_PIN) == HIGH){
       playTune = false;
       break;
       }
    }
  }
}

/**************************************************************************/
//Multiline comment section.
/* The behaviour of the resistor will vary depending on Ohms. The higher the resistance
 * is, the bigger the voltage drop will be, the lower the frequency. 
 * The button which provides the low frequency sound, uses all the resistors. 
 * This results in the lowest voltage at the output, and thus the lower frequency.
 * The button providing the highest frequency sound is only uses the last resistor. 
 * This results in the highest voltage at the output, and thus the highest frequency.
 * The lower the resistence the more current there is which allows the sound to vary between
 * high pitch and low pitch. The voltage will only change because of the value of the resistors.
 */



