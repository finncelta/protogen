#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 3, 2);

int btn1 = A0;
int btn2 = A1;
int btn3 = A2;
int btn4 = A3;
int btn5 = A4;

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  if (!driver.init()) {
    Serial.println("init failed");
  }

}
bool buttonState(int pin) {
  int state = digitalRead(pin);
  if (state == HIGH) {
    return true;
  } else {
    return false;
  }
}

void loop() {
  if (buttonState(btn1)) {
    const char *msg = "01";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
  } else if (buttonState(btn2)) {
    const char *msg = "02";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
  } else if (buttonState(btn3)) {
    const char *msg = "03";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
  } else if (buttonState(btn4)) {
    const char *msg = "04";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
  } else if (buttonState(btn5)) {
    const char *msg = "05";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
  }
}
