# Test 7: File I/O
print("=== File I/O ===")
write_file("test_output.txt", "Hello from Ipp!\nLine 2\nLine 3")
print("File written")

var content = read_file("test_output.txt")
print(content)

append_file("test_output.txt", "\nAppended line")
var content2 = read_file("test_output.txt")
print(content2)