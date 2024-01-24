extern "C" void kernel_main() {
  // Function to print a string to the screen
  void print_string(const char* str);

  // Print "Hello, World!" to the screen
  const char* hello_world = "Hello, World!";
  print_string(hello_world);

  // Hang indefinitely
  while (1) {}
}

extern "C" void print_char(char character) {
  // Function to print a character to the screen
  volatile char* video_memory = (volatile char*)0xB8000;
  *video_memory = character;
}

void print_string(const char* str) {
  // Print each character in the string
  while (*str != '\0') {
    print_char(*str);
    str++;
  }
}
