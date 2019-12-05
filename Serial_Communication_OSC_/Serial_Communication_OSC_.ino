/*
 Sending button data over Serial from Arduino to an OSC supported application 
 Created on 15 May 2019
 Tamanda Msosa 
*/

const int buttonPin = 2; // button pin 
const int buttonPin2 = 4; //second button pin


int buttonState = 0; // initial state of button 
int buttonState2 = 0; // inital state of second button 
int lastButtonState = 0; // debouncing variable for first button 
int lastButtonState2 = 0; // debouncing variable for second button 

 
void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // sets button pin to input 
  pinMode(buttonPin2, INPUT_PULLUP); // sets button pin to input 
  Serial.begin(9600);  // opens serial channel at 9600 baud 

}

void loop() {
buttonState = digitalRead(buttonPin); // read state of first button
buttonState2 = digitalRead(buttonPin2); // read state of second button 

if( buttonState != lastButtonState) { // check whether the button is being pressed or not by comparing it with debounce state

  if(buttonState == HIGH) { // if button is pressed send A1 to serial monitor
     delay(50); // delays 50 miliseconds 
     Serial.print("A "); // print A with a space before the second line
     Serial.println(buttonState, DEC); // print the decimal value of button
  }
  else {  // if button is not high output A0 to serial monitor 
    delay(50); // delays 50 miliseconds 
    Serial.print("A "); // print A with a space before the second line
    Serial.println(buttonState, DEC); // print the decimal value of button
    
  }
  lastButtonState = buttonState; // set it back to zero once its done 
  
}
  if(buttonState2 != lastButtonState2) { // check whether the button is being pressed or not by comparing it with debounce state
 
  if(buttonState2 == HIGH) { //if button is pressed send B1 to serial monitor
    delay(50); //delays 50 miliseconds 
    Serial.print("B "); // print B with a space before the second line
    Serial.println(buttonState2, DEC); // print the decimal value of button
  }
  else { //if button is not high output B0 to serial monitor
    delay(50); //delays 50 miliseconds 
    Serial.print("B "); // print B with a space before the second line
    Serial.println(buttonState2, DEC); // if button is not high output B0 to serial monitor 
  }
    lastButtonState2 = buttonState2; // set it back to zero once its done
    }
  
}
