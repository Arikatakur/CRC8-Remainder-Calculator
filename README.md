# CRC8-Remainder-Calculator

A simple C program to compute the CRC8 remainder for a binary input using the polynomial \(x^8 + x^6 + x^4 + x^2 + 1\) (binary representation: `101010101`). This implementation is designed to demonstrate the basics of CRC (Cyclic Redundancy Check) algorithms and can be adapted for educational or practical purposes.

## How It Works
1. **Input Binary Sequence**: The program accepts a binary string as input (e.g., `110101101011`).
2. **Conversion**: The binary string is converted into a byte array for processing.
3. **CRC Calculation**: The remainder is calculated using bitwise operations and the specified polynomial.
4. **Output**: The program displays the input data (in hexadecimal) and the 9-bit CRC remainder (in binary).

---

## Getting Started

### Prerequisites
- A C compiler (e.g., `gcc`).
- Basic understanding of binary arithmetic and CRC.

### Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/CRC8-Remainder-Calculator.git
