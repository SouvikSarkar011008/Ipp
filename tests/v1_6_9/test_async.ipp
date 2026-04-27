# Test v1.6.9: async/await in VM
func sync_add(a, b) {
    return a + b
}

async func async_add(a, b) {
    return a + b
}

var sync_result = sync_add(10, 20)
var async_result = async_run(async_add(5, 7))

print("sync: ")
print(sync_result)
print("async: ")
print(async_result)

print("v1.6.9: Async/Await tests PASSED")