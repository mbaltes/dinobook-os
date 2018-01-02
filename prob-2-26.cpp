#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char**argv) {
  std::string infile, outfile;
  std::cout << "Enter input filename: " << std::endl;
  std::cin >> infile;
  std::cout << "Enter output filename: " << std::endl;
  std::cin >> outfile;

  int input_filedesc = open(infile.c_str(), O_RDONLY);
  int output_filedesc = open(outfile.c_str(), O_RDONLY);

  std::cout << input_filedesc << " + " << output_filedesc << std::endl;
  return 0;
}
