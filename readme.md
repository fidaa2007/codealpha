# CodeAlpha C Programming Internship Tasks

This repository contains my solutions for the C Programming Internship tasks assigned by **CodeAlpha**. The project includes three menu-driven C programs covering core programming concepts, 2D dynamic arrays, file handling, structures, and modular design.

---

## 📁 Repository Structure

* `task1_calculator.c` — **Task 1: Basic Calculator Program**
* `task2_matrix.c` — **Task 2: Matrix Operations**
* `task4_banking.c` — **Task 4: Banking System (Mini Project)**

---

## 🛠️ Task Summaries

### 1. Task 1: Basic Calculator Program
* **Description:** A menu-driven arithmetic calculator.
* **Features:** Performs Addition, Subtraction, Multiplication, and Division with error handling for division by zero.
* **Concepts Used:** Functions, `switch-case` control flow, basic standard I/O.

### 2. Task 2: Matrix Operations
* **Description:** Performs fundamental matrix operations on user-input matrices.
* **Features:** Matrix Addition, Subtraction, Multiplication, and Transpose with validation for matching dimensions.
* **Concepts Used:** Dynamic memory allocation (`malloc`/`free`), 2D pointer-to-pointer structures (`int**`), user input validation.

### 3. Task 4: Banking System (Mini Project)
* **Description:** A persistent bank account management system.
* **Features:** Account Creation, Money Deposit, Money Withdrawal, Balance Enquiry, and Data Persistence.
* **Concepts Used:** C Structures (`struct`), File Handling (`fopen`, `fread`, `fwrite`, `fseek`), binary storage (`.dat`).

---

## 🚀 How to Run the Code

### Prerequisites
Ensure you have a C compiler installed (such as `gcc` via MinGW on Windows or standard build tools on Linux/macOS).

### Compilation and Execution

1. **Compile a task (e.g., Banking System):**
   ```bash
   gcc task4_banking.c -o banking_system