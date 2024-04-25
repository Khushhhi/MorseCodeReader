int led = 13;

// letters
char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", //A to I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", //J to R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." //S to Z
};

// Numbers
char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-", ".....",
"-....", "--...", "---..", "----."
};
int dotDelay = 500;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
     Serial.println("Start");
    char ch = Serial.read(); // Read a single character from the serial
    Serial.print("Received: ");
    Serial.println(ch); 
    if (ch >= 'a' && ch <= 'z') {
      flashSequence(letters[ch - 'a']);
    } else if (ch >= 'A' && ch <= 'Z') {
      flashSequence(letters[ch - 'A']);
    } else if (ch >= '0' && ch <= '9') {
      flashSequence(numbers[ch - '0']);
    } else if (ch == ' ') {
      delay(dotDelay * 7); // Increase delay for spaces
    }
     Serial.println("End");
     delay(1000);
  }

 
}

void flashSequence(char* sequence) {
  int i = 0;
  for (int i = 0; sequence[i] != '\0'; i++) {
    flashDotOrDash(sequence[i]);
  }
  delay(dotDelay * 3);
}


void flashDotOrDash(char dotOrDash) {
  digitalWrite(led, HIGH); 
  if (dotOrDash == '.') {
      delay(dotDelay);
  }
  else if (dotOrDash == '-') {
  // must be a - 
    delay(dotDelay * 3); 
  }
  digitalWrite(led, LOW); 
  delay(dotDelay);
}
