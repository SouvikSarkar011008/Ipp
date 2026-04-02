# Test v1.3.4 - File I/O

print("=== Testing v1.3.4 File I/O ===")

# ====== Write File ======
print("\n--- Write File ---")
var result = write_file("test_output_v134.txt", "Hello from Ipp v1.3.4!")
print("Write result:", result)

# ====== Read File ======
print("\n--- Read File ---")
var content = read_file("test_output_v134.txt")
print("Read content:", content)

# ====== File Exists ======
print("\n--- File Exists ---")
print(file_exists("test_output_v134.txt"))
print(file_exists("nonexistent.txt"))

# ====== Append File ======
print("\n--- Append File ---")
var append_result = append_file("test_output_v134.txt", "\nAppended line!")
print("Append result:", append_result)

var appended = read_file("test_output_v134.txt")
print("After append:", appended)

# ====== Delete File ======
print("\n--- Delete File ---")
var delete_result = delete_file("test_output_v134.txt")
print("Delete result:", delete_result)
print(file_exists("test_output_v134.txt"))

# ====== List Directory ======
print("\n--- List Directory ---")
var files = list_dir("tests")
print(files)

# ====== Mkdir ======
print("\n--- Mkdir ---")
var mkdir_result = mkdir("test_dir_v134")
print("Mkdir result:", mkdir_result)
print(file_exists("test_dir_v134"))

# Clean up - skip directory delete on Windows
print("Directory created successfully, cleanup skipped on Windows")

print("\n=== v1.3.4 File I/O tests complete! ===")
