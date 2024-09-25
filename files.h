#pragma once

#include <fstream>
#include <vector>

using namespace std;

class Reader {
  ifstream file;

public:
  Reader() = default;
  Reader(const Reader &) = delete;
  Reader(Reader &&) = delete;
  Reader &operator=(const Reader &) = delete;
  Reader &operator=(Reader &&) = delete;

  ~Reader() = default;

  Reader(string);

  vector<int> read_inp();
};

class Writer {
  ofstream file;

public:
  Writer() = default;
  Writer(const Writer &) = delete;
  Writer(Writer &&) = delete;
  Writer &operator=(const Writer &) = delete;
  Writer &operator=(Writer &&) = delete;

  ~Writer() = default;

  Writer(const string);

  void append(int); // const int or not?

  void closure() { this->file.close(); }
};
