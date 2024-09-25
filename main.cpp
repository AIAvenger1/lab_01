//
// Created by Bohdan Petrov on 06.09.2024.
//

#include "files.h"
#include "obj.h"
#include <string>

void greetings() // func that returns information about author and assigment
{
  cout << "\nBohdan Petrov, K23, Lab_01, var_3\n\n";
  cout << "Press Enter to Continue...";
  char temp1 = ' ';
  while (temp1 != '\n')
    std::cin.get(temp1);

  cout << "\nGenerate a random number from given sequence with a given "
          "frequencies\n\n";
  cout << "Press Enter to Continue...";
  char temp2 = ' ';
  while (temp2 != '\n')
    std::cin.get(temp2);
}

const std::string DEFAULT_OUTPUT = "output.txt";
const std::string DEFAULT_INPUT = "input.txt";

bool argument(int argc_, char *argv[], std::string &Input,
              std::string &Output) {
  Input = DEFAULT_INPUT;
  Output = DEFAULT_OUTPUT;
  for (int i = 1; i < argc_; ++i) {
    if (strcmp(argv[i], "-i") == 0) {
      if (i >= argc_ - 1) {
        return false;
      }
      Input = argv[++i];
    }

    if (strcmp(argv[i], "-o") == 0) {
      if (i >= argc_ - 1) {
        return false;
      }
      Output = argv[++i];
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  greetings();
  std::string
      Input = DEFAULT_INPUT,
      Output = DEFAULT_OUTPUT; // change appropriately, or run -i file, -o file
  try {
    Reader inp(Input);
    Writer out(Output);
    Random obj(inp.read_inp());
    for (int i = 0; i < N; ++i) {
      out.append(obj());
    }
    calc(obj, Output);
  } catch (const std::exception &ex) {
    std::cerr << '\n' << "Error: " << ex.what() << '\n';
  }
  return 0;
}
