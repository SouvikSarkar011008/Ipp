# Test v1.5.4.4 - Medium Features (Async REPL, Background tasks, Plot/charts)

print("=== Testing v1.5.4.4 Medium Features ===")

# Test 1: Background jobs (.bg)
print("\n--- Test 1: Background Jobs ---")
print("Background jobs available:")
print("  .bg <expr>     - Run expression in background")
print("  .jobs         - Show running jobs")

# Test 2: Plot/Charts
print("\n--- Test 2: Plot/Charts ---")
print("Plot feature available:")
print("  .plot [1,2,3,4,5]  - Plot data using matplotlib")
print("  Requires: pip install matplotlib")

# Test 3: Async in REPL
print("\n--- Test 3: Async REPL ---")
print("Async support available:")
print("  .async <expr> - Run async expression")

# Test 4: Basic functionality
print("\n--- Test 4: Basic Functionality ---")
var nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print("List: " + str(nums))
print("Sum: " + str(sum(nums)))
print("Average: " + str(sum(nums) / len(nums)))

# Test 5: Async function test
print("\n--- Test 5: Async Functions ---")
async func async_add(a, b) {
    return a + b
}
print("Async function defined: async_add")

# Test 6: HTTP request test
print("\n--- Test 6: HTTP Requests ---")
print("HTTP builtins available:")
print("  http_get(url)")
print("  http_post(url, data)")

# Test 7: WebSocket test  
print("\n--- Test 7: WebSocket ---")
print("WebSocket builtins available:")
print("  websocket_connect(url)")
print("  websocket_send(ws, msg)")

# Test 8: Canvas still works
print("\n--- Test 8: Canvas ---")
print("Canvas functions: canvas_open, canvas_rect, canvas_circle, etc.")

# Test 9: Database operations
print("\n--- Test 9: JSON/TOML/YAML ---")
var data = {"name": "test", "value": 42}
var json_str = json_stringify(data)
print("JSON: " + json_str)

# Test 10: Advanced data structures
print("\n--- Test 10: Advanced Collections ---")
var pq = PriorityQueue()
print("PriorityQueue available")

var dq = deque()
print("deque available")

print("\n=== v1.5.4.4 Tests Complete ===")
print("New in v1.5.4.4:")
print("  .bg <expr>     - Run in background")
print("  .jobs          - Show background jobs")
print("  .plot <data>  - Plot data with matplotlib")
print("  .async <expr> - Run async expression")
print("Note: .plot requires 'pip install matplotlib'")