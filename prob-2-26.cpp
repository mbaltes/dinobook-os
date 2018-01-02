#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char**argv) {
  // Get file information from user.
  std::string infile, outfile;
  std::cout << "Enter input filename: " << std::endl;
  std::cin >> infile;
  std::cout << "Enter output filename: " << std::endl;
  std::cin >> outfile;

  int input_filedesc, output_filedesc;

  // Checking file existence and responding accordingly.
  if (access(infile.c_str(), F_OK) != -1) {
    // Exists
    input_filedesc = open(infile.c_str(), O_RDONLY);
  } else {
    std::cout << "Input file doesn't exist. Exiting." << std::endl;
    exit(1);
  }
  if (access(outfile.c_str(), F_OK) != -1) {
    // Exists
    std::cout << "Output file already exits. Exiting." << std::endl;
    exit(1);
  } else { // Create file with correct permissions.
    output_filedesc = open(outfile.c_str(),
                           O_CREAT | O_WRONLY,
                           S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  }

  // Copy file1 into file2.
  char data[128];
  int size = read(input_filedesc, data, 128);
  while (size > 0) {
    write(output_filedesc, data, size);
    size = read(input_filedesc, data, 128);
  }

  close(input_filedesc);
  close(output_filedesc);
  return 0;
}

