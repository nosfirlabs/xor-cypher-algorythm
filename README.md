
# Prime Number XOR Cipher

This repository contains a C implementation of an encryption and decryption algorithm based on prime numbers and the XOR cipher. The algorithm is intended for educational purposes and is not recommended for high-security applications.

## Overview

The algorithm combines the XOR cipher with a prime number sequence generator. The key used for encryption and decryption is a prime number. The algorithm encrypts or decrypts each byte of the input data by XOR-ing it with a prime number from the sequence. The sequence is generated starting with the given prime key and generating the next prime number in the sequence for each byte.

## Files

-   `prime_xor_cipher.c`: The main C source file containing the implementation of the encryption and decryption algorithm.

## Building and Running

To compile the C code, use the following command:

bash

`gcc -o prime_xor_cipher prime_xor_cipher.c` 

To run the compiled binary:

bash

`./prime_xor_cipher` 

## Usage

The main function in `prime_xor_cipher.c` demonstrates how to use the `encrypt_decrypt` function to encrypt and decrypt a string:

c

`uint8_t data[] = "Your message here";
size_t data_len = strlen((char *)data);
uint32_t key = 101; // Key should be a prime number

encrypt_decrypt(data, data_len, key); // Encrypt
encrypt_decrypt(data, data_len, key); // Decrypt` 

Replace `"Your message here"` with the desired message and choose a prime number as the key. The same `encrypt_decrypt` function is used for both encryption and decryption, as the XOR operation is its own inverse.
