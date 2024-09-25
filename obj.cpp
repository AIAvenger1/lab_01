//
// Created by Bohdan Petrov on 06.09.2024.
//

#include "obj.h"
#include <random>
#include <stdexcept>

using namespace std;

Random::Random() {
  random_device r;
  this->engine = mt19937(r());
}

Random::Random(vector<int> inp) {
  if (inp.size() == 0 || inp.size() % 2 == 1) {
    throw invalid_argument(
        "Wrong number of elements, should be even. Check input file.");
  }
  for (int i = 0; i < int(inp.size()) / 2; ++i) {
    this->numbers[i] = inp[i];
  }
  this->dist =
      discrete_distribution<int>(inp.begin() + inp.size() / 2, inp.end());
}

int Random::operator()() // generates random number
{
  return this->numbers[dist(engine)];
}

vector<double> Random::get_freq() { return this->dist.probabilities(); }

map<int, int> Random::get_numbers() { return this->numbers; }

void calc(Random obj, const string inp) // calculates probabilities
{
  map<int, double> num_freq; // sum up frequences for all numbers
  for (auto &it : obj.get_numbers()) {
    num_freq[it.second] += obj.get_freq()[it.first];
  }
  map<int, double> real_num_freq; // from output of the () operator
  for (auto it : num_freq) {
    real_num_freq[it.first] = 0;
  }
  Reader temp(inp);
  vector<int> num = temp.read_inp();
  for (auto &it : num) {
    real_num_freq[it] += (1. / num.size());
  }
  for (auto it : num_freq) {
    cout << it.first << "\t---\t" << "(prg:<" << it.second << "> real:<"
         << real_num_freq[it.first] << ">)\n";
  }
}
