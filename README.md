# STM32 Scientific Calculator (IR Controlled)

A **Scientific Calculator** built on STM32 microcontroller, fully controlled via an **IR remote** (using **NVIC interrupts** for real-time input) and displaying results on a **TFT screen**.  
This calculator supports **basic arithmetic operations** and **scientific functions** such as `sin`, `cos`, `tan`, `log`, and `exp`.

---

## **Key Features**
- **Basic Arithmetic**
  - Addition (+)
  - Subtraction (−)
  - Multiplication (×)
  - Division (÷)
- **Scientific Functions**
  - `sin(x)` → Sine function
  - `cos(x)` → Cosine function
  - `tan(x)` → Tangent function
  - `log(x)` → Logarithm (base e)
  - `exp(x)` → Exponential function e^x
  - Power function (x^y)
- **IR Remote Control (with NVIC)**
  - Uses **NVIC interrupts** to handle IR remote input in real-time.
  - No busy waiting; CPU can process other tasks while waiting for IR signal.
- **TFT Display**
  - Graphical UI for input expression and results.

---

## **How it Works**
1. **IR Input (NVIC Based):**
   - IR sensor connected to external interrupt (EXTI line).
   - NVIC interrupt triggers on every IR signal edge.
   - Decoded IR data is pushed to the calculator logic instantly.
2. **Expression Parsing:**
   - Input expression converted to Postfix (Reverse Polish Notation).
3. **Evaluation:**
   - Stack-based evaluation algorithm handles operators and scientific functions.
4. **Display:**
   - Results and active cursor shown on TFT screen.

---

## **Remote Control Mapping (Example)**
| Button          | Action                    |
|-----------------|---------------------------|
| 0 – 9           | Numbers                   |
| +, −, ×, ÷      | Arithmetic operators      |
| .               | Decimal point             |
| ( , )           | Parentheses               |
| Menu Button     | Open scientific functions |
| OK              | Calculate (=)             |
| C               | Clear / Reset             |
| Arrow keys      | Move cursor inside input  |

---

## **Advantages of NVIC Based IR Input**
- Non-blocking input.
- Allows smooth TFT rendering while receiving IR signals.
- Better response time compared to polling.

---

## **Limitations**
- Trigonometric functions work in **radians**.
- No error handling for division by zero or malformed input.
- Floating-point precision limited to 4 decimal digits.

---

## **Future Enhancements**
- Add degrees mode for trig functions.
- More scientific functions (sqrt, sinh, cosh, etc.).
- Error handling & improved UI feedback.
---
