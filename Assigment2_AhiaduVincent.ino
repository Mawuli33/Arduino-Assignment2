int segmentPins[] = {2,3,4,6,7,9,10};
int numSegments = 7;
int buzzerPin = 8;

byte digits[10][7] = {
  {1,1,1,0,1,1,1},
  {0,0,1,0,0,0,1},
  {1,1,0,1,0,1,1},
  {0,1,1,1,0,1,1},
  {0,0,1,1,1,0,1},
  {0,1,1,1,1,1,0},
  {1,1,1,1,1,1,0},
  {0,0,1,0,0,1,1},
  {1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1}
};

void showDigit(int n){
  if(n < 0 || n > 9) return;

  for(int i = 0; i < numSegments; i++){
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);

  for(int i=0; i<numSegments; i++){
   pinMode(segmentPins[i], OUTPUT);
  }

  Serial.println("=== Beeping Coutdown Starting ===");

  int count = 8;

  while(count >= 0){
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);

    tone(buzzerPin,440,200);
    delay(1000);

    count = count - 1;
  }

  showDigit(count);
  tone(buzzerPin, 440, 1000);

  Serial.println("=== Countdown Complete ===");
 

}

void loop() {



}
