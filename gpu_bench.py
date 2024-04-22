import taichi as ti
import time

@ti.kernel
def sieve_of_eratosthenes(primes: ti.template(), max_prime: int) -> None:
    ti.loop_config(block_dim=256)
    for i in range(2, int(max_prime ** 0.5) + 1):
        if not primes[i]:
            for j in range(i * i, max_prime + 1, i):
                primes[j] = True

@ti.kernel
def count_primes(primes: ti.template(), max_prime: int) -> int:
    ti.loop_config(block_dim=256)
    count = 0
    for i in range(2, max_prime + 1):
        if not primes[i]:
            count += 1
    return count

def main():
    max_prime = 1000000
    primes = ti.field(dtype=ti.i32, shape=max_prime + 1)
    primes.fill(0)  # Initialize all elements to 0 (indicating prime)

    start_time = time.time()

    prime_count = 0
    while time.time() - start_time < 20.0:
        sieve_of_eratosthenes(primes, max_prime)
        prime_count = count_primes(primes, max_prime)

    end_time = time.time()
    elapsed_time = end_time - start_time

    print(f"Generated {prime_count} primes in {elapsed_time:.2f} seconds")

if __name__ == "__main__":
    main()
