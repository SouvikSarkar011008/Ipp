# Test v1.3.4 - File I/O

print("=== Testing v1.3.4 File I/O ===")

# ====== Write File ======
print("\n--- Write File ---")
var result = write_file("test_output_v134.txt", "Hello from Ipp v1.3.4!")
print("Write result:", result)
assert result == true, "write_file returns true on success"

# ====== Read File ======
print("\n--- Read File ---")
var content = read_file("test_output_v134.txt")
print("Read content:", content)
assert content == "Hello from Ipp v1.3.4!", "read_file returns correct content"

# ====== File Exists ======
print("\n--- File Exists ---")
print(file_exists("test_output_v134.txt"))
print(file_exists("nonexistent.txt"))
assert file_exists("test_output_v134.txt") == true, "File exists returns true for existing file"
assert file_exists("nonexistent.txt") == false, "File exists returns false for non-existing file"

# ====== Append File ======
print("\n--- Append File ---")
var append_result = append_file("test_output_v134.txt", "\nAppended line!")
print("Append result:", append_result)
assert append_result == true, "append_file returns true on success"

var appended = read_file("test_output_v134.txt")
print("After append:", appended)
assert appended == "Hello from Ipp v1.3.4!\nAppended line!", "Appended content is correct"

# ====== Delete File ======
print("\n--- Delete File ---")
var delete_result = delete_file("test_output_v134.txt")
print("Delete result:", delete_result)
assert delete_result == true, "delete_file returns true on success"
assert file_exists("test_output_v134.txt") == false, "File no longer exists after delete"

# ====== List Directory ======
print("\n--- List Directory ---")
var files = list_dir("tests")
print(files)
assert len(files) > 0, "list_dir returns non-empty list"

# ====== Mkdir ======
print("\n--- Mkdir ---")
var mkdir_result = mkdir("test_dir_v134")
print("Mkdir result:", mkdir_result)
assert mkdir_result == true, "mkdir returns true on success"
assert file_exists("test_dir_v134") == true, "Directory exists after mkdir"

# Clean up - skip directory delete on Windows
print("Directory created successfully, cleanup skipped on Windows")

print("\n=== v1.3.4 File I/O tests complete! ===")
