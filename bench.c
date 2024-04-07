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
