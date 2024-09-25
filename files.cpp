#include "files.h"
#include <stdexcept>

Reader::Reader(const string addr) : file() {
  this->file = ifstream(addr); // why operator=(const ifstream&) deleted?
  if (!this->file.is_open()) {
    throw invalid_argument("Something wrong with input file");
  }
}

vector<int> Reader::read_inp() {
  vector<int> res;
  int tmp = 0;
  while (this->file >> tmp && !this->file.eof()) {
    res.push_back(tmp);
  }
  if (!this->file.eof() && !(this->file >> tmp)) {
    throw invalid_argument("Wrong character or type, check input file");
  }
  return res;
}

Writer::Writer(const string addr) : file(ofstream(addr)) {
  if (!this->file.is_open()) {
    throw invalid_argument("Output file cannot be opened");
  }
}

void Writer::append(int val) { this->file << val << '\n'; }
