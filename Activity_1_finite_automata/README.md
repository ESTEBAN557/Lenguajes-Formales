# Finite Automaton Simulator

## Environment and Tools

The program was developed using the following environment:

- **Operating System:** Windows 11  
- **Programming Language:** C++  
- **Compiler:** g++ (MinGW / GCC)  
- **Editor/IDE:** Visual Studio Code  
- **Terminal:** PowerShell

---

## Project Description

This project implements a **Deterministic Finite Automaton (DFA)** that evaluates whether a string composed of the alphabet **{a, b}** belongs to the language defined by the automaton.

The program reads a string entered by the user, processes it symbol by symbol through the automaton states, and determines whether the string is **accepted or rejected**.

The user can test multiple strings without restarting the program.

---


## How to Compile and Run the Program

Follow these steps to compile and execute the program.

### 1. Open a terminal
Navigate to the folder where the file `automata.cpp` is located.

Example:
```bash
cd path/to/the/project
```


### 2. Compile the program

Use the following command:

```bash
g++ automata.cpp -o automata.exe
```

This will generate the executable file `automata.exe`.

### 3. Run the program

Execute the program with:

 ```bash
./automata.exe
```

or in Windows PowerShell:

 ```bash
.\automata.exe
```


### 4. Input strings

The program will prompt the user to enter a string using the alphabet **{a, b}**.

Example:
 ```bash
--- Finite Automaton Simulator ---

Enter a string (alphabet {a,b}) or 'exit':abba
RESULT: The string IS accepted.
 ```

To terminate the program, type:

salir
 ```

The program will evaluate the string and indicate whether it is **accepted** or **rejected** by the automaton.

---


---

## Algorithm Explanation

The program simulates a **Deterministic Finite Automaton (DFA)** using an enumeration of states and a transition system implemented with a `switch` statement.

### 1. State Representation

The automaton states are represented using an **enum** called `Estado`, which includes:

- `ESTADO_0137`
- `ESTADO_247`
- `ESTADO_7`
- `ESTADO_8`
- `ESTADO_58`
- `ESTADO_68`
- `ESTADO_RECHAZO`

These states correspond to the states defined in the automaton diagram.

### 2. Processing the Input String

The function `perteneceAlLenguaje(string cadena)` evaluates whether the input string belongs to the language.

The algorithm works as follows:

1. The automaton starts in the **initial state `ESTADO_0137`**.
2. The input string is processed **character by character** using a `for` loop.
3. For each symbol (`a` or `b`), the program determines the next state using a **switch statement** that defines the transitions.
4. If a symbol does not correspond to a valid transition, the automaton moves to the **rejection state (`ESTADO_RECHAZO`)**.
5. After processing the entire string, the program checks whether the final state is an **accepting state**.

### 3. Acceptance Condition

A string is accepted if the final state is one of the following:

- `ESTADO_247`
- `ESTADO_8`
- `ESTADO_68`
- `ESTADO_58`

If the final state matches one of these states, the function returns `true`; otherwise, it returns `false`.

### 4. Interactive Execution

The `main()` function allows the user to evaluate multiple strings using a `while(true)` loop. The program continues running until the user types **"salir"**, which terminates the program.

---

## Program Structure

The program contains three main components:

1. **State definition** using an `enum`.
2. **Language verification function** (`perteneceAlLenguaje`).
3. **Main loop** that allows continuous input from the user.

This structure allows the automaton simulation to remain clear, modular, and easy to understand.