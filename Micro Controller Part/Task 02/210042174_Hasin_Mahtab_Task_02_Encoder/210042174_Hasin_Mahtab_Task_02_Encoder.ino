#define ENC_COUNT_REV 100


#define ENC_IN 3 
#define PWM 10 
#define DIR 12 


int speedcontrol = 0;
volatile long encoderValue = 0;
int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;
int rpm = 0;
int motorPwm = 0;

void setup()
{
  Serial.begin(9600); 
  
  pinMode(ENC_IN, INPUT_PULLUP); 

  pinMode(PWM, OUTPUT);
  pinMode(DIR, OUTPUT);
  

  attachInterrupt(digitalPinToInterrupt(ENC_IN), updateEncoder, RISING);
  

  previousMillis = millis();
}

void loop()
{
  
    // Control motor with potentiometer
    motorPwm = map(analogRead(speedcontrol), 0, 1023, 0, 255);
    
    // Write PWM to controller
    analogWrite(PWM, motorPwm);
  
  // Update RPM value every second
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;


    // Calculate RPM
    rpm = (float)(encoderValue * 60 / ENC_COUNT_REV);

    // Only update display when there is a reading
    if (motorPwm > 0 || rpm > 0) {
      Serial.print("PWM VALUE: ");
      Serial.print(motorPwm);
      Serial.print('\t');
      Serial.print(" PULSES: ");
      Serial.print(encoderValue);
      Serial.print('\t');
      Serial.print(" SPEED: ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
    
    encoderValue = 0;
  }
}

void updateEncoder()
{
  // Increment value for each pulse from encoder
  encoderValue++;
}
