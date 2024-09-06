#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

// Function to find prime numbers up to max using the sieve of Eratosthenes algorithm
void sieveOfEratosthenes(bool *primes, uint64_t max) {
    primes[0] = primes[1] = true; // 0 and 1 are not primes

    uint64_t maxRoot = sqrt(max);
    for (uint64_t i = 2; i <= maxRoot; ++i) {
        if (!primes[i]) {
            for (uint64_t j = i * i; j <= max; j += i) {
                primes[j] = true; // Mark multiples of i as non-prime
            }
        }
    }
}

// Miller-Rabin primality test function
bool millerRabin(uint64_t n, int k = 5) {
    if (n == 2 || n == 3) return true;
    if (n <= 1 || n % 2 == 0) return false;

    uint64_t s = 0;
    uint64_t r = n - 1;
    while ((r & 1) == 0) {
        s++;
        r >>= 1;
    }

    for (int i = 0; i < k; i++) {
        uint64_t a = 2 + rand() % (n - 3);
        uint64_t x = pow(a, r);
        if (x != 1 && x != n - 1) {
            bool j = false;
            for (int j = 1; j < s; j++) {
                x = pow(x, 2);
                if (x == 1) return false;
                if (x == n - 1) {
                    j = true;
                    break;
                }
            }
            if (!j) return false;
        }
    }
    return true;
}

int main() {
    uint64_t maxPrime = 1000000;
    bool* primes = (bool*)malloc((maxPrime + 1) * sizeof(bool));
    if (primes == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // Initialize all elements of the primes array to false (indicating prime)
    for (uint64_t i = 0; i <= maxPrime; ++i) {
        primes[i] = false;
    }

    // Measure start time
    clock_t startTime = clock();

    // Find prime numbers until 20 seconds have passed
    int primeCount = 0;
    while (((double)(clock() - startTime) / CLOCKS_PER_SEC) < 20.0) {
        // Find prime numbers using the sieve of Eratosthenes
        sieveOfEratosthenes(primes, maxPrime);

        // Count prime numbers
        for (uint64_t i = 2; i <= maxPrime; ++i) {
            if (!primes[i]) {
                primeCount++;
            }
        }

        // Test some numbers using the Miller-Rabin primality test
        for (uint64_t i = 2; i <= maxPrime; i += 1000) {
            if (millerRabin(i)) {
                printf("%llu is probably prime\n", i);
            }
        }
    }

    // Measure end time
    clock_t endTime = clock();

    // Calculate elapsed time in seconds
    double elapsedTime = ((double)(endTime - startTime) / CLOCKS_PER_SEC);

    // Print the quantity of primes generated and the elapsed time
    printf("Generated %d primes in %.2f seconds\n", primeCount, elapsedTime);

    free(primes);

    return 0;
}

