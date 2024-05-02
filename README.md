

Description:
This script utilizes the sieve of Eratosthenes algorithm to generate prime numbers. It has been modified to function as a timed benchmark, measuring the time taken to generate prime numbers for 20 seconds. After the benchmark, it displays the total quantity of primes generated and the elapsed time.

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
      - 1. add visual feedback
      - 2. add user input
