# Project 03 — TMP36 Temperature-Triggered LEDs

**Board:** Arduino UNO R4 WiFi
**Status:** Complete

A TMP36 analog temperature sensor drives three red LEDs in stages: as the
measured temperature climbs above a baseline in 2 °C steps, more LEDs turn
on, giving a rough visual "thermometer."

## Why this project

Projects 01 and 02 were digital only — a pin is either HIGH or LOW. This
project introduces analog input: reading a continuous voltage, converting it
into a real-world unit (degrees Celsius), and making output decisions based
on ranges rather than a single boolean state.

## Hardware

| Item | Notes |
|---|---|
| Arduino UNO R4 WiFi | 5V logic |
| TMP36 temperature sensor | Analog output, powered from 5V |
| LED (red) | ×3 |
| Resistor | 220 Ω, one per LED |
| Breadboard | |
| Jumper wires | |

## Circuit

| Arduino pin | Role |
|---|---|
| A0 | Input — TMP36 analog output |
| D2 | Output — LED 1 |
| D3 | Output — LED 2 |
| D4 | Output — LED 3 |

See [photos/Project 3 photo.jpg](photos/Project%203%20photo.jpg) for the
actual wiring. The TMP36's three pins run to 5V, A0, and GND; each LED sits
behind its own 220 Ω current-limiting resistor on the breadboard, wired back
to D2–D4.

## How it works

`loop()` reads the TMP36 on A0 and converts the raw ADC value to a
temperature:

1. `voltage = (sensorVal / 1024.0) * 5.0` — ADC counts (0–1023) to volts (0–5V)
2. `temperature = (voltage - 0.5) * 100` — the TMP36's own transfer function
   (500 mV offset at 0 °C, 10 mV per °C)

The result is compared against a `baselineTemp` of 30.0 °C in four bands, each
2 °C wide:

- **< baseline + 2:** all LEDs off
- **≥ baseline + 2, < +4:** LED 1 on
- **≥ baseline + 4, < +6:** LEDs 1–2 on
- **≥ baseline + 6:** all three LEDs on

Each pass also prints the raw ADC value, voltage, and computed temperature
over serial for observation.

Code: [`code/tmp36_temperature_leds/tmp36_temperature_leds.ino`](code/tmp36_temperature_leds/tmp36_temperature_leds.ino)

## Concepts learned

- `analogRead()` and the ADC's 0–1023 count range
- Converting a raw ADC reading to a physical unit via a sensor's known
  transfer function
- Using a fixed baseline plus threshold bands to turn a continuous signal
  into discrete output stages
- Serial output as a debugging tool for values that can't be seen directly

## Connection to robotics theory

This is the first project in the repo that closes the loop from a physical
quantity to a control decision: sense → convert to engineering units →
threshold → actuate. Every sensor-driven behaviour later in this repo
(distance from an ultrasonic sensor, position from an encoder) follows the
same shape, just with more sensors and finer-grained output than "on/off."

## Possible improvements

- Replace the hardcoded `baselineTemp` with a calibration step (e.g. average
  the first few readings at power-on)
- Smooth the ADC reading (simple moving average) to reduce flicker from
  sensor/ADC noise near a threshold boundary
- Use `map()` or `analogWrite()` to fade LEDs proportionally to temperature
  instead of switching in fixed bands
- Replace `delay(1)` with non-blocking timing if this were combined with
  other sensors later

## Photos

![Breadboard build](photos/Project%203%20photo.jpg)
