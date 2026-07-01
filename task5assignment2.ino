 int buzzPin =8;
int segmentPins[]={2,3,4,5,6,7,9};
int numSegments = 7;
//a b c d e f g
byte digits[10][7]={
{1,1,1,1,1,1,0},// to on 0
{0,1,1,0,0,0,0},// to on 1
{1,1,0,1,1,0,1},// to on 2
{1,1,1,1,0,0,1},// to on 3
{0,1,1,0,0,1,1},// to on 4
{1,0,1,1,0,1,1},//to on 5
{1,0,1,1,1,1,1},// to on 6
{1,1,1,0,0,0,0},// to on 7
{1,1,1,1,1,1,1},// to on 8
{1,1,1,1,0,1,1}, // to on 9
};


void showDigit (int n){
if (n < 0 || n > 9) return;


for (int i = 0; i < numSegments; i++){
  digitalWrite(segmentPins[i], digits[n][i]);
 }
} 
void setup() {
  Serial.begin(9600);

  pinMode(buzzPin, OUTPUT);
  for (int i = 0; i<numSegments; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  Serial.println("===Beeping Countdown Starting===");
  int count = 9;
  while(count>=1){
    Serial.print("Counting: ");
    Serial.println(count);
    showDigit(count);

    // short beep
    tone(buzzPin,1000,200);
    delay(1000);
    count = count - 1;
  }
//displaying zero and tone completion
showDigit(0);
tone(buzzPin,1500,1000);
Serial.println("=== Countdown Complete ===");
}

void loop() {
  //empty
}
