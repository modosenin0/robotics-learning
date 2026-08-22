# Learning Context

Background and approach for this repository. Written primarily as context for
AI assistants, but readable as a statement of intent.

## Who I am

A working software engineer moving toward robotics. Programming is not the
bottleneck — I can write and structure code. The gaps I'm closing are robotics
mathematics, control theory, electronics, embedded work, and the practical
experience of making physical things behave.

## The approach

```
Learn the theory
      ↓
Understand what it means physically
      ↓
Build something that demonstrates it
      ↓
Document what actually happened
      ↓
Increase complexity
```

Two tracks running in parallel: **Modern Robotics** (theory) and **Arduino**
(hardware lab). They are deliberately connected — Arduino is not a separate
hobby track, it's where the maths becomes observable.

## Where I am now

**Theory:** Modern Robotics specialization, Course 1, nearly complete.

Course 1 has taken a while. That's intentional, not a problem. The material —
coordinate frames, rotation matrices, homogeneous transformations, exponential
coordinates, screw axes — reappears constantly in later courses. Rushing it
would be false economy.

The standard I hold myself to: I should be able to explain what a piece of
notation represents physically, not just manipulate it. For

```
T = [ R  p ]
    [ 0  1 ]
```

the test isn't reproducing the block structure. It's being able to say that this
describes the pose of one frame relative to another — orientation and position
together — and to predict what happens when I compose two of them.

**Hardware:** Arduino UNO R4. Project 01 (LED circuit) complete.

## Hardware I own

- Arduino UNO R4
- Breadboard, jumper wires
- LEDs, resistors

Everything else gets bought when a project needs it, not in advance.

## Documentation standard

Each project directory contains:

- `README.md` — the writeup
- `code/` — the sketch

The README should cover:

1. What was built and why
2. Hardware used
3. Circuit description
4. How it works
5. **What I predicted vs. what actually happened**
6. Problems hit and how they were solved
7. Concepts learned
8. Connection to robotics theory
9. What I'd improve

Item 5 is the one that's easy to skip and most valuable in hindsight. For an LED
it's trivial. For a PID loop it is the entire lesson.

## Working agreements

- **Don't rush.** Depth over course-completion speed.
- **Build while learning.** Don't wait until the theory is finished.
- **Start simple.** An LED is a legitimate Project 01.
- **Understand before abstracting.** Use libraries once I know what they're
  doing underneath, not instead of knowing.
- **Write down the failures.** The debugging is the content.

## Time budget

Roughly 8–10 hours per week, split between theory on some days and hardware on
others, with a longer combined session at weekends. Flexible. The principle that
matters is not doing everything at once.

## Direction

Long term: robotics software engineering. The existing software engineering
background is an asset to build on, not something to replace.

The path runs Arduino → sensors and actuators → closed-loop control →
differential-drive robot → ROS 2 and simulation → perception and autonomy.
ROS 2 is deliberately later; the fundamentals come first.

The goal for the portfolio is to eventually show one substantial project done
properly — custom kinematics, encoder odometry, PID control, sensor fusion,
autonomous navigation, tested in both simulation and hardware — rather than a
list of completed courses.
