

Description:
This script utilizes the sieve of Eratosthenes algorithm to generate prime numbers. It has been modified to function as a timed benchmark, measuring the time taken to generate prime numbers for 20 seconds. After the benchmark, it displays the total quantity of primes generated and the elapsed time.

The Miller-Rabin primality test function millerRabin takes an integer n and an optional parameter k (defaulting to 5) as input. It returns true if n is probably prime, and false otherwise. The function works by repeatedly testing whether n is a witness to the compositeness of n. If n is composite, then there is a high probability that a randomly chosen number a will be a witness to the compositeness of n. The function repeats this test k times, and if no witness is found, then n is probably prime. Note that the Miller-Rabin primality test is a probabilistic test, meaning that there is a small chance of returning a false positive (i.e., a composite number that is reported as prime). However, the probability of this occurring decreases rapidly as the number of iterations k increases.

Compilation Flags:
- `-lm`: This flag links the math library, which is necessary because the script uses math functions such as `sqrt`.

- `-o`: This flag specifies the output executable name.
- `-Wall`: This flag enables all compiler warnings for better code quality.
- `-Wextra`: This flag enables extra compiler warnings for additional code checks.

Example Compilation Command:
```
gcc -O2 -Wall -Wextra -lm prime_counter.c -o prime_counter
```

## Bench Taichi
      $ pip install taichi

TODO: 

+ 1. add visual feedback
+ 2. add user input
