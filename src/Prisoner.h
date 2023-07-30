#pragma once

#include <cstdlib>
#include <iostream>
#include <ctime>

class Prisoner {
 private:
   int index, N, value;

 public:
    Prisoner(int _index, int _N) {
      index = _index;
      N = _N;
      value = _index;
    }

    int guess() {
      return value;
    }
    
    void report(int _value) {
      value = _value;
    }
};

