# robotics-learning

Documentation for my transition from software engineering into robotics.

I'm a software engineer learning robotics properly — theory first, then build
something physical that demonstrates it. This repo is the record of that.

Programming isn't the hard part. The parts I'm building are the robotics
mathematics, control theory, electronics, and the habit of connecting equations
to hardware that actually moves.

## Current tracks

| Track | What | Status |
|---|---|---|
| Theory | [Modern Robotics](https://www.coursera.org/specializations/modernrobotics) (Northwestern / Lynch & Park) | Course 1, nearly complete |
| Hardware | Arduino UNO R4 experiments | Project 04 complete |

## Projects

| # | Project | Concepts | Status |
|---|---|---|---|
| 01 | [LED circuit](01-led-circuit/) | Digital output, current limiting, LED polarity | Complete |
| 02 | [Button-controlled LEDs](02-button-controlled-led/) | Digital input, pull-up resistors, debouncing | Complete |
| 03 | [TMP36 temperature-triggered LEDs](03-tmp36-temperature-leds/) | Analog input, ADC, sensor transfer functions | Complete |
| 04 | [Color-mixing lamp](04-color-mixing-lamp/) | Multi-channel analog input, PWM output, proportional sensing | Complete |
| 05 | Ultrasonic sensor | Timing, distance measurement, sensor noise | Planned |
| 06 | DC motor + driver | H-bridge, PWM speed control, power | Planned |
| 07 | Encoder | Interrupts, pulse counting, RPM | Planned |
| 08 | PID motor control | Closed-loop control, tuning, steady-state error | Planned |
| 09 | Differential drive | Wheel odometry, forward kinematics | Planned |

## How each project is documented

Every project — including trivial ones — gets a README covering what was built,
what was predicted, what actually happened, what broke, and how it connects to
the theory. See [01-led-circuit](01-led-circuit/README.md) for the template in
practice.

The point isn't to make small projects look impressive. It's to build the habit
now, so the documentation is already good by the time the projects are hard.

## Context

[LEARNING_CONTEXT.md](LEARNING_CONTEXT.md) — background, approach, and the
longer-term plan. Useful as context for AI assistants working in this repo.
