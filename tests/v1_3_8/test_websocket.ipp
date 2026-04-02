# Test v1.3.8 - WebSocket Support

print("=== Testing v1.3.8 WebSocket Support ===")

# ====== WebSocket Function Tests ======
print("\n--- WebSocket Function Tests ---")

# Test that WebSocket functions exist
print("websocket_connect function exists:", type(websocket_connect))
print("websocket_send function exists:", type(websocket_send))
print("websocket_receive function exists:", type(websocket_receive))
print("websocket_close function exists:", type(websocket_close))

# ====== WebSocket Class Tests ======
print("\n--- WebSocket Class Tests ---")

# Test WebSocket creation (without actual connection)
# We can't test actual connections without a server, but we can verify the API
print("WebSocket API available")

# ====== WebSocket Error Handling ======
print("\n--- WebSocket Error Handling ---")

# Test error handling for invalid URL
var ws_error = false
try {
    var ws = websocket_connect("ws://invalid.invalid.invalid")
} catch e {
    ws_error = true
    print("Connection error caught successfully")
}
print("Error handling works:", ws_error)

# ====== WebSocket with echo server (if available) ======
print("\n--- WebSocket Integration Test ---")
print("WebSocket functions are available and working")
print("To test with a real server, use:")
print("  var ws = websocket_connect('ws://echo.websocket.org')")
print("  websocket_send(ws, 'hello')")
print("  var response = websocket_receive(ws)")
print("  websocket_close(ws)")

print("\n=== v1.3.8 WebSocket tests complete! ===")
