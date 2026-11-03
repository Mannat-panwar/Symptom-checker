# Symptom Checker – Know Before You Go

A simple command-line symptom checker written in C, built as a mini project for **Introduction to Programming**.

> **Disclaimer:** This tool does not provide medical diagnosis. It is for awareness only. Always consult a certified doctor.

## How it works
1. The user enters up to 3 symptoms.
2. The program compares them with a built-in database of 15 conditions.
3. The condition with the most matching symptoms is shown, along with basic advice.
4. A safety disclaimer is always printed.

## Concepts used
- Structs (`struct Disease`) and arrays of structs
- 2D character arrays (strings)
- Functions and prototypes
- Loops, conditionals, `scanf`, `strcmp`, `strcpy`
- Case-insensitive matching with a custom `toLowerCase()`

## Build and run
```bash
gcc symptom_checker.c -o symptom_checker
./symptom_checker          # on Windows: symptom_checker.exe
```

## Sample run
```
How many symptoms would you like to enter? (max 3): 2
Symptom 1: fever
Symptom 2: cough
-------------------------------------
Possible Condition: Common Cold/Flu
Advice: Rest, stay hydrated.
-------------------------------------
```

## Project structure
```
Symptom-checker/
├── symptom_checker.c
├── README.md
└── .gitignore
```

## Limitations / future work
- Symptoms must match the database wording exactly (e.g. "sore throat"); extra spaces and capital letters are handled.
- Only the single best match is shown.
- Database is small and for demonstration only.

## Author
Mannat – B.Tech CSE (AI/ML) with EY
