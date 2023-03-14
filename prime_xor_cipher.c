#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_prime(uint32_t n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (uint32_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

uint32_t next_prime(uint32_t n) {
    while (!is_prime(++n));
    return n;
}

void encrypt_decrypt(uint8_t *data, size_t data_len, uint32_t key) {
    uint32_t prime = key;

    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= (uint8_t)(prime & 0xFF);
        prime = next_prime(prime);
    }
}

int main() {
    uint8_t data[] = "Hello, World!";
    size_t data_len = strlen((char *)data);
    uint32_t key = 101; // Key should be a prime number

    printf("Original: %s\n", data);
    
    encrypt_decrypt(data, data_len, key);
    printf("Encrypted: %s\n", data);

    encrypt_decrypt(data, data_len, key);
    printf("Decrypted: %s\n", data);

    return 0;
}
