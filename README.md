
# CRC8-Remainder-Calculator

A simple C program to compute the CRC8 remainder for a binary input using the polynomial \(x^8 + x^6 + x^4 + x^2 + 1\) (binary representation: `101010101`). This implementation demonstrates the basics of CRC (Cyclic Redundancy Check) algorithms and can be customized for educational or practical purposes.

---

## How It Works

1. **Input Binary Sequence**: The program accepts a binary string as input (e.g., `110101101011`).
2. **Conversion**: The binary string is converted into a byte array for processing.
3. **CRC Calculation**: The remainder is calculated using bitwise operations and the specified polynomial.
4. **Output**: The program displays:
   - The input data in hexadecimal format.
   - The CRC remainder as a 9-bit binary value.

---

## Getting Started

### Prerequisites

- A C compiler (e.g., `gcc`).
- Basic understanding of binary arithmetic and CRC algorithms.

### Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/CRC8-Remainder-Calculator.git
   ```
2. Navigate to the project directory:
   ```bash
   cd CRC8-Remainder-Calculator
   ```
3. Compile the program:
   ```bash
   gcc -o crc8 main.c
   ```

---

## Usage

### Running the Program

Run the program by providing a binary sequence as input:
```bash
./crc8 [binary_sequence]
```

### Input Format

- The input must be a binary string with a length that is a multiple of 8.
- Example valid input: `110101101011101010111000`.

### Example

#### Input:
```bash
./crc8 110101101011101010111000
```

#### Output:
```
Data: D6 BA B8 
Remainder (CRC8 - 9 bits): 101011011
```

---

## Customization

### Polynomial

The polynomial used for CRC calculations is hardcoded as `101010101` (hexadecimal: `0x155`). To change it:
- Modify the `Crc8` function in the source code:
  ```c
  crc ^= (0x155 << 7); // Replace 0x155 with your desired polynomial
  ```

### Initial CRC Value

The initial CRC value is set to `0`:
```c
uint16_t crc = 0;
```
To use a different initial value, replace `0` with your desired value (e.g., `0xFFFF`).

### Input Format

The program currently expects the binary string to have a length that is divisible by 8. To handle non-aligned binary sequences, you can modify the `convert_binary` function to pad or process incomplete bytes.

### Output Format

The CRC remainder is displayed as a 9-bit binary value. To change the output format (e.g., to hexadecimal or decimal):
- Replace the `print_binary` function with:
  ```c
  printf("Remainder (CRC8 - hex): %X\n", crc);
  ```

---

## Detailed Example

### Input Binary Sequence

```bash
./crc8 110101101011001010100111
```

### Step-by-Step Explanation

1. **Conversion to Hexadecimal**:
   - Input binary: `11010110 10110010 10100111`
   - Hexadecimal equivalent: `D6 B2 A7`

2. **CRC Calculation**:
   - Using the polynomial \(x^8 + x^6 + x^4 + x^2 + 1\), the remainder is calculated.

3. **Output**:
   ```
   Data: D6 B2 A7
   Remainder (CRC8 - 9 bits): 100011101
   ```

---

## Learning Objectives

- Understand how CRC algorithms work for error detection.
- Learn the importance of polynomial selection in CRC calculations.
- Explore bitwise operations and binary data manipulation in C.

---

## Contributions

Contributions are welcome! If you find any issues or have ideas for improvements, feel free to:
- Fork the repository.
- Submit a pull request with your changes.
- Open an issue to discuss new features or fixes.

---

## License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/Arikatakur/CRC8-Remainder-Calculator/tree/main?tab=MIT-1-ov-file) file for details.

---

## Acknowledgments

This project is a simple, educational implementation of CRC algorithms. Thanks to the open-source community for fostering learning and collaboration!
