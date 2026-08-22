# Project 01 — LED Circuit

**Board:** Arduino UNO R4
**Status:** Complete
**Time:** ~1 hour

An LED on a breadboard, blinking at 1 Hz under software control.

## Why this project

This is deliberately the simplest thing that can be built. It isn't here to be
impressive — it's here to establish the loop that every later project follows:
build it, observe it, write down what happened, connect it to theory.

It's also the first time in this repo that a line of code causes something
physical to occur. That transition is the actual subject of the project.

## Hardware

| Item | Notes |
|---|---|
| Arduino UNO R4 | 5V logic |
| LED | Standard 5mm |
| Resistor | 220 Ω |
| Breadboard | |
| Jumper wires | ×2 |

## Circuit

```
  Arduino
  ┌────────┐
  │     D9 ├───────[ 220Ω ]───────▶|───────┐
  │        │                     LED       │
  │    GND ├───────────────────────────────┘
  └────────┘
```

Current path: pin D9 → resistor → LED anode → LED cathode → GND.

The LED is polarised. The long leg (anode) goes toward the resistor and D9; the
short leg (cathode) goes to ground. Reversed, no current flows and nothing
happens — the LED is not damaged, it simply stays dark.

The resistor position doesn't matter electrically — it can sit on either side of
the LED. It's in series either way, so the same current passes through both.

### Why the resistor is required

An LED is not a resistor. Its voltage drop is roughly constant once conducting
(~2V for a red LED), so it does not limit its own current. Connected straight
across 5V, the current is bounded only by wiring resistance — enough to destroy
the LED, and potentially to exceed the pin's current rating.

The series resistor sets the current:

```
        V_supply − V_LED       5V − 2V
I  =  ────────────────────  =  ─────────  ≈  13.6 mA
             R                   220Ω
```

Comfortably within the LED's rating and within what an Arduino output pin can
source.

## How it works

`pinMode(LED_PIN, OUTPUT)` configures the pin to actively drive a voltage rather
than sense one. `digitalWrite(LED_PIN, HIGH)` drives it to ~5V; current flows
and the LED lights. `LOW` drives it to 0V and the LED goes dark. `delay()`
blocks for a given number of milliseconds between the two.

Code: [`code/led_blink/led_blink.ino`](code/led_blink/led_blink.ino)

## Predicted vs. actual

| Predicted | Actual |
|---|---|
| LED blinks once per second | Confirmed |
| Reversing the LED stops it working | Confirmed — no light, no damage |

*(Replace with your own observations, including anything that surprised you.)*

## Problems encountered

*To fill in from your own build — common ones:*

- LED inserted backwards; nothing happens until the legs are swapped
- Breadboard rows misunderstood; components not actually connected in series
- Wrong port selected in the IDE, so the upload fails

## Concepts learned

- Breadboard row/rail topology
- LED polarity and forward voltage
- Series current limiting and Ohm's law in practice
- `pinMode()`, `digitalWrite()`, `delay()`
- The upload cycle: compile → flash → run on hardware

## Connection to robotics theory

Thin, but real, and worth naming explicitly:

**Actuation is just controlled current.** Every actuator in this repo — servos,
DC motors, the wheels of a differential-drive robot — is a variation on the same
idea: software decides, a pin changes state, current flows, something physical
happens. The LED is that chain with all the complexity removed.

**`delay()` is a control-loop antipattern.** This sketch blocks. Nothing else can
run during those 500ms. Real control loops need to sample sensors and update
outputs on a predictable schedule, which is why later projects move to
`millis()`-based timing and eventually to fixed-rate loops. Meeting `delay()`
here makes the reason for abandoning it concrete later.

## Possible improvements

- Replace `delay()` with `millis()` timing so the loop is non-blocking
- Fade the LED with `analogWrite()` — introduces PWM, which is how DC motor
  speed is controlled in project 06
- Drive the LED from a potentiometer reading, linking analog input to output

## Photos

*Add a photo of the built circuit here. Proof it was actually assembled, and a
useful reference if you rebuild it later.*

```
![LED circuit on breadboard](photos/build.jpg)
```
