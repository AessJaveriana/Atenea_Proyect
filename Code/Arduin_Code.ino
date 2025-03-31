void setup() {
    pinMode(2, INPUT);   // tilt D2
    pinMode(4, OUTPUT);  // Servo D4 (señal PWM)
    digitalWrite(4, LOW); // Ini 0°
  }
  
  void loop() {
    if (digitalRead(2) == HIGH) {  // tilt inclinado (HIGH)
      for (int i = 0; i < 50; i++) { // pulso ~1.5ms (90°)
        digitalWrite(4, HIGH);
        delayMicroseconds(19000);   // pulso 180°
        digitalWrite(4, LOW);
        delayMicroseconds(20000);  // Completa 20ms (50Hz)
      }
    } else {                      // Si el sensor pos normal (LOW)
      for (int i = 0; i < 50; i++) { // Genera pulso de ~1ms (0°)
        digitalWrite(4, HIGH);
        delayMicroseconds(17000);   // pulso 0°
        digitalWrite(4, LOW);
        delayMicroseconds(18000);  // Completa 20ms (50Hz)
      }
    }
  }