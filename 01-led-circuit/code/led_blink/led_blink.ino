/*
 * Project 01 — LED Circuit
 * Board: Arduino UNO R4
 *
 * Blinks an external LED on a breadboard at 1 Hz.
 *
 * Circuit:
 *   D9 ──[ 220Ω ]── LED anode (long leg)
 *                   LED cathode (short leg) ── GND
 *
 * The resistor is in series with the LED and limits current through it.
 * See README.md for the calculation.
 */

const int LED_PIN     = 9;    // digital output driving the LED
const int ON_TIME_MS  = 500;  // how long the LED stays lit
const int OFF_TIME_MS = 500;  // how long it stays dark

void setup() {
  // Configure the pin as an output. Without this the pin defaults to an
  // input and cannot source enough current to light the LED.
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // pin driven to ~5V, current flows, LED lights
  delay(ON_TIME_MS);            // blocking wait

  digitalWrite(LED_PIN, LOW);   // pin driven to 0V, no current, LED dark
  delay(OFF_TIME_MS);
}
