//
// Created by Bohdan Petrov on 06.09.2024.
//
#pragma once

#include "files.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;

const int N = 10000; // number of elements to generate

class Random {
  map<int, int> numbers;
  mt19937 engine;
  discrete_distribution<int> dist;

public:
  Random();
  Random(const Random &) = default;
  Random(Random &&) = delete;
  Random &operator=(const Random &) = delete;
  Random &operator=(Random &&) = delete;

  ~Random() = default;

  Random(vector<int>); // constucts a Random obj from already read into
                       // vector<int> input

  int operator()(); // returns random number from given set of numbers

  vector<double> get_freq();

  map<int, int> get_numbers();
};

void calc(Random, const string);
