#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Return CRC remainder using x^8 + x^6 + x^4 + x^2 + 1 polynomial (101010101). */
uint16_t Crc8(const void *vptr, int len)
{
    const uint8_t *data = vptr;
    uint16_t crc = 0; // Initial CRC value (16 bits to hold the 9-bit remainder)
    int i, j;

    for (j = len; j; j--, data++) {
        crc ^= (*data << 8); // XOR the current byte into the high bits of CRC
        for (i = 0; i < 8; i++) { // Process each bit
            if (crc & 0x8000) { // Check if the highest bit is set
                crc ^= (0x155 << 7); // XOR with the polynomial
            }
            crc <<= 1; // Shift CRC left by 1 bit
        }
    }

    return (crc >> 7) & 0x1FF; // Extract and return the 9-bit remainder
}

void convert_binary(const char *str, uint8_t *binary, int *size_binary)
{
    // Convert binary string into a byte array
    int size_str = strlen(str);
    if (size_str % 8 != 0) {
        fprintf(stderr, "Binary input must be a multiple of 8 bits.\n");
        exit(1);
    }

    *size_binary = size_str / 8;

    for (int i = 0; i < *size_binary; i++) {
        char substr[9];
        strncpy(substr, &str[i * 8], 8);
        substr[8] = '\0';

        binary[i] = strtol(substr, NULL, 2); // Convert binary substring to a byte
    }
}

void print_binary(uint16_t value, int bits)
{
    // Print a binary value as a string
    for (int i = bits - 1; i >= 0; i--) {
        putchar((value & (1 << i)) ? '1' : '0');
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "USAGE: crc8 [binary sequence]\n");
        return 1;
    }

    char *word = argv[1];
    int len;
    uint8_t binary_data[strlen(word) / 8];

    convert_binary(word, binary_data, &len);
    uint16_t crc = Crc8(binary_data, len);

    printf("Data: ");
    for (int i = 0; i < len; i++) {
        printf("%02X ", binary_data[i]);
    }
    printf("\nRemainder (CRC8 - 9 bits): ");
    print_binary(crc, 9); // Print the 9-bit remainder as binary
    printf("\n");

    return 0;
}
