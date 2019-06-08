int en[3] = {10,5,11};
int in1[3] = {9,7,13};
int in2[3] = {8,6,12};

void setup() {
    for(int i = 0; i < 3; i++){
        pinMode(en[i], OUTPUT);
        pinMode(in1[i], OUTPUT);
        pinMode(in2[i], OUTPUT);
    }
    Serial.begin(9600);
}

void goForward(int speed, int time) {
    digitalWrite(in1[0], HIGH);
    digitalWrite(in2[0], LOW);
    digitalWrite(in1[1], LOW);
    digitalWrite(in2[1], HIGH);
    digitalWrite(in1[2], LOW);
    digitalWrite(in2[2], LOW);
    for(int i = 0; i < 3; i++){
        analogWrite(en[i], speed);
    }
    delay(time);
}

void goBack(int speed, int time) {
    digitalWrite(in1[0], LOW);
    digitalWrite(in2[0], HIGH);
    digitalWrite(in1[1], HIGH);
    digitalWrite(in2[1], LOW);
    digitalWrite(in1[2], LOW);
    digitalWrite(in2[2], LOW);
    for(int i = 0; i < 3; i++){
        analogWrite(en[i], speed);
    }
    delay(time);
}

void goLeft(int speed, int time) {
    digitalWrite(in1[0], LOW);
    digitalWrite(in2[0], HIGH);
    analogWrite(en[0], speed/5);
    digitalWrite(in1[1], LOW);
    digitalWrite(in2[1], HIGH);
    analogWrite(en[1], speed/5);
    digitalWrite(in1[2], LOW);
    digitalWrite(in2[2], HIGH);
    analogWrite(en[2], speed);
    delay(time);
}

void goRight(int speed, int time) {
    digitalWrite(in1[0], HIGH);
    digitalWrite(in2[0], LOW);
    analogWrite(en[0], speed/5);
    digitalWrite(in1[1], HIGH);
    digitalWrite(in2[1], LOW);
    analogWrite(en[1], speed/5);
    digitalWrite(in1[2], HIGH);
    digitalWrite(in2[2], LOW);
    analogWrite(en[2], speed);
    delay(time);
}

void goUpLeft(int speed, int time) {
    digitalWrite(in1[0], HIGH);
    digitalWrite(in2[0], LOW);
    analogWrite(en[0], speed/7);
    digitalWrite(in1[1], LOW);
    digitalWrite(in2[1], HIGH);
    analogWrite(en[1], speed);
    digitalWrite(in1[2], LOW);
    digitalWrite(in2[2], HIGH);
    analogWrite(en[2], speed/3);
    delay(time);
}

void goUpRight(int speed, int time) {
    digitalWrite(in1[0], HIGH);
    digitalWrite(in2[0], LOW);
    analogWrite(en[0], speed);
    digitalWrite(in1[1], LOW);
    digitalWrite(in2[1], HIGH);
    analogWrite(en[1], speed/7);
    digitalWrite(in1[2], HIGH);
    digitalWrite(in2[2], LOW);
    analogWrite(en[2], speed/3);
    delay(time);
}

void goDownLeft(int speed, int time) {
    digitalWrite(in1[0], LOW);
    digitalWrite(in2[0], HIGH);
    analogWrite(en[0], speed);
    digitalWrite(in1[1], HIGH);
    digitalWrite(in2[1], LOW);
    analogWrite(en[1], speed/7);
    digitalWrite(in1[2], LOW);
    digitalWrite(in2[2], HIGH);
    analogWrite(en[2], speed/3);
    delay(time);
}

void goDownRight(int speed, int time) {
    digitalWrite(in1[0], LOW);
    digitalWrite(in2[0], HIGH);
    analogWrite(en[0], speed/7);
    digitalWrite(in1[1], HIGH);
    digitalWrite(in2[1], LOW);
    analogWrite(en[1], speed);
    digitalWrite(in1[2], HIGH);
    digitalWrite(in2[2], LOW);
    analogWrite(en[2], speed/3);
    delay(time);
}

void moveStop(int time) {
    for(int i = 0; i < 3; i++){
        digitalWrite(in1[i], LOW);
        digitalWrite(in2[i], LOW);
    }
    delay(time);
}

void demoActions() {
    moveStop(3000);
    goForward(100,1000);
    moveStop(1000);
    goBack(100,1000);
    moveStop(1000);
    goLeft(100,1000);
    moveStop(1000);
    goRight(100,1000);
    moveStop(1000);
    goUpRight(100,1000);
    moveStop(1000);
    goUpLeft(100,1000);
    moveStop(1000);
    goDownRight(100,1000);
    moveStop(1000);
    goDownLeft(100,1000);
    moveStop(1000);
}

void loop() {
    demoActions();
    delay(1000);
}
