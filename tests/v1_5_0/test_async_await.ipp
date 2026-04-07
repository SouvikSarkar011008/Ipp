# Test v1.5.0 - Async/Await

print("=== Testing v1.5.0 Async/Await ===")

# ====== Async Function Declaration ======
print("\n--- Async Function Declaration ---")
async func fetch_data(url) {
    print("Fetching:", url)
    sleep(0.01)
    return "data from " + url
}

# ====== Coroutine Creation ======
print("\n--- Coroutine Creation ---")
var coro = fetch_data("https://example.com")
print("coroutine:", coro)
print("is_coroutine:", is_coroutine(coro))

# ====== Async Run ======
print("\n--- Async Run ---")
async func quick_task() {
    print("Task started")
    sleep(0.01)
    print("Task done")
    return 42
}

var coro2 = quick_task()
print("coro2:", coro2)
var result = async_run(coro2)
print("async_run result:", result)
print("result type:", type(result))

# ====== Sleep ======
print("\n--- Sleep ---")
print("Before sleep")
sleep(0.01)
print("After sleep")

# ====== Multiple Coroutines ======
print("\n--- Multiple Coroutines ---")
async func worker(name, delay) {
    print(name, "started")
    sleep(delay)
    print(name, "finished")
    return name + " done"
}

var w1 = worker("Worker1", 0.01)
var w2 = worker("Worker2", 0.02)
var r1 = async_run(w1)
var r2 = async_run(w2)
print("Results:", r1, r2)

# ====== Async with Return ======
print("\n--- Async with Return ---")
async func compute(n) {
    var total = 0
    var i = 0
    while i < n {
        total = total + i
        i = i + 1
    }
    return total
}

var sum_result = async_run(compute(100))
print("Sum 0..99:", sum_result)

print("\n=== v1.5.0 Async/Await tests complete! ===")
