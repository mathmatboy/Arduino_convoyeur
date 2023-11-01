

//Define the pins for the start and stop buttons
#define startButton 2
#define stopButton 3
#define stopButton2 8

//Define the pins for the conveyors
#define conveyor1 4
#define conveyor2 5
#define conveyor3 6
#define conveyor4 7

//Define the time intervals for the conveyors
#define conveyor1Time 3000
#define conveyor2Time 5000
#define conveyor3Time 7000
#define conveyor4Time 10000

bool isRunning = false;
unsigned long startTime;
unsigned long elapsedTime;

int startButtonState = 0;
int stopButtonState = 0;
int stopButtonState2 = 0;

void setup() {
  Serial.begin(9600);

  pinMode(startButton, INPUT);
  pinMode(stopButton, INPUT);
  
  pinMode(conveyor1, OUTPUT);
  pinMode(conveyor2, OUTPUT);
  pinMode(conveyor3, OUTPUT);
  pinMode(conveyor4, OUTPUT);
  Serial.println("Initialisation OK....");
}

void loop() {

  startButtonState = digitalRead(startButton);
  stopButtonState = digitalRead(stopButton);
  stopButtonState2 = digitalRead(stopButton2);
  
  if (startButtonState == HIGH) {
    digitalWrite(conveyor1, HIGH);
    startTime = millis();
    isRunning = true;
  }

  if (isRunning) {
    elapsedTime = millis() - startTime;
    
    if (elapsedTime >= conveyor2Time) {
      digitalWrite(conveyor2, HIGH);
      //Serial.println("Convoyeur 2 actived");
    }

    if (elapsedTime >= conveyor3Time) {
      digitalWrite(conveyor3, HIGH);
      //Serial.println("Convoyeur 3 actived");
    }

    if (elapsedTime >= conveyor4Time) {
      digitalWrite(conveyor4, HIGH);
      //Serial.println("Convoyeur 4 actived");
    }
  }
  //LOW for NC contact
  if (stopButtonState == LOW || stopButtonState2 == LOW) {
    isRunning = false;
    digitalWrite(conveyor1, LOW);
    digitalWrite(conveyor2, LOW);
    digitalWrite(conveyor3, LOW);
    digitalWrite(conveyor4, LOW);
    Serial.println("Stop button ACTIVÉE");

  }
}
