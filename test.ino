#define BUTTON_PIN 12
#define DIH_LIGHT 2
#define DAH_LIGHT 3

bool buttonPressed, buttonWasPressed;
int buttonStateDuration;

void setup() {   
  Serial.begin(9600);
  delay(10);
  clearSerialOutput();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(DIH_LIGHT, OUTPUT);
  pinMode(DAH_LIGHT, OUTPUT);
  buttonPressed = buttonWasPressed = 0;
  buttonStateDuration = 0;
}

void clearSerialOutput(){
  Serial.write(27);
  Serial.write("[2J");
  Serial.write(27);
  Serial.write("[H");
}

void updateButtonBehave(){
  Serial.print(buttonWasPressed ? 'v' : '^');
  Serial.println(buttonStateDuration);
  buttonWasPressed = buttonPressed;
  buttonStateDuration = 0;
}

void loop() {
  buttonPressed = !digitalRead(BUTTON_PIN);
  if (buttonPressed != buttonWasPressed)
    updateButtonBehave();
  buttonStateDuration++;
  delay(10);
}
