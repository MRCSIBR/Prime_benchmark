import time
import taichi as ti
ti.init(arch=ti.gpu)
NUM_OPERATIONS = 10000000

@ti.kernel
def integer_multiplication_taichi(result: ti.types.ndarray()):
    for i in range(NUM_OPERATIONS):
        result[i] = (i + 1) * (i + 2)

def integer_multiplication_benchmark_taichi():
    result = ti.ndarray(shape=NUM_OPERATIONS, dtype=ti.int32)
    start_time = time.perf_counter()
    integer_multiplication_taichi(result)
    end_time = time.perf_counter()
    execution_time = end_time - start_time
    operations_per_second = NUM_OPERATIONS / execution_time
    return operations_per_second

@ti.kernel
def float_multiplication_taichi(result: ti.types.ndarray()):
    for i in range(NUM_OPERATIONS):
        result[i] = (i + 1.0) * (i + 2.0)

def float_multiplication_benchmark_taichi():
    result = ti.ndarray(shape=NUM_OPERATIONS, dtype=ti.float32)
    start_time = time.perf_counter()
    float_multiplication_taichi(result)
    end_time = time.perf_counter()
    execution_time = end_time - start_time
    operations_per_second = NUM_OPERATIONS / execution_time
    return operations_per_second

if __name__ == "__main__":
    int_ops_per_second = integer_multiplication_benchmark_taichi()
    print(f"Integer operations per second (Taichi): {int_ops_per_second:.2f}")

    float_ops_per_second = float_multiplication_benchmark_taichi()
    print(f"Floating-point operations per second (Taichi): {float_ops_per_second:.2f}")

# Integer operations per second (Taichi): 288237492.01
# Floating-point operations per second (Taichi): 637636480.47
#
