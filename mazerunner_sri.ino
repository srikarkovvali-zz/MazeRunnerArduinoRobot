const int LEFT_MOTOR_POWER = 6;
const int RIGHT_MOTOR_POWER = 11;
const int LEFT_MOTOR_FORWARD = 13;
const int LEFT_MOTOR_BACKWARD = 10;
const int RIGHT_MOTOR_FORWARD = 2;
const int RIGHT_MOTOR_BACKWARD = 7;
const int LDR_LEFT = 5;
const int LDR_CENTER = 4;
const int LDR_RIGHT = 2;
int left;
int center;
int right;
int count = 0;
boolean stray = false;
boolean nextRight = false;
boolean confirmRight = false;

void activate ()
{
  analogWrite (LEFT_MOTOR_POWER, 250);
  analogWrite (RIGHT_MOTOR_POWER, 210);
}

void activateTurns ()
{
  analogWrite (LEFT_MOTOR_POWER, 250);
  analogWrite (RIGHT_MOTOR_POWER, 250);
}

void kill ()
{
  digitalWrite (LEFT_MOTOR_POWER, LOW);
  digitalWrite (RIGHT_MOTOR_POWER, LOW);
}

void setup() {
  pinMode (LEFT_MOTOR_POWER, OUTPUT);
  pinMode (RIGHT_MOTOR_POWER, OUTPUT);
  pinMode (LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode (LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode (RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode (RIGHT_MOTOR_BACKWARD, OUTPUT);
  Serial.begin (9600);
  /*while (true)
  {
    updateSensorReadings ();
    Serial.print (left);
    Serial.print ("  ");
    Serial.print (center);
    Serial.print ("  ");
    Serial.println (right);
  }*/
  delay (2000);
  activate ();
}

void forward ()
{
  digitalWrite (LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite (RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite (LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite (RIGHT_MOTOR_BACKWARD, LOW);
}

void backward ()
{
  digitalWrite (LEFT_MOTOR_FORWARD, LOW);
  digitalWrite (RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite (LEFT_MOTOR_BACKWARD, HIGH);
  digitalWrite (RIGHT_MOTOR_BACKWARD, HIGH); 
}

void adjustLeft ()
{
  digitalWrite (LEFT_MOTOR_FORWARD, LOW);
  digitalWrite (RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite (LEFT_MOTOR_BACKWARD, HIGH);
  digitalWrite (RIGHT_MOTOR_BACKWARD, LOW);
}

void adjustRight ()
{
  digitalWrite (LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite (RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite (LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite (RIGHT_MOTOR_BACKWARD, LOW);
}

void turnLeft ()
{
  digitalWrite (LEFT_MOTOR_FORWARD, LOW);
  digitalWrite (RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite (LEFT_MOTOR_BACKWARD, HIGH);
  digitalWrite (RIGHT_MOTOR_BACKWARD, LOW);
  delay (800);
}

void turnRight ()
{
  digitalWrite (LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite (RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite (LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite (RIGHT_MOTOR_BACKWARD, HIGH);
  delay (1400);
}

void updateSensorReadings ()
{
  left = analogRead (LDR_LEFT) + 30;
  center = analogRead (LDR_CENTER);
  right = analogRead (LDR_RIGHT);
}


void rightUntilLine ()
{
  while (!(left - center > 150 && right - center > 150) && !(center - right > 150 && left - right > 150) && !(center - left > 150 && right - left > 150))
  {
    digitalWrite (LEFT_MOTOR_FORWARD, HIGH);
    digitalWrite (RIGHT_MOTOR_FORWARD, LOW);
    digitalWrite (LEFT_MOTOR_BACKWARD, LOW);
    digitalWrite (RIGHT_MOTOR_BACKWARD, HIGH);
    updateSensorReadings ();
  }
  digitalWrite (LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite (RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite (LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite (RIGHT_MOTOR_BACKWARD, HIGH);
  delay (350);
}

void loop() {
  forward ();

 
}
