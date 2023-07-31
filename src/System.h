#include <algorithm>
#include <vector>
#include <string>
#include <random>

#include "Prisoner.h"

using namespace std;

class System {
 private:
   vector<Prisoner> prisoners;
   vector<int> boxes;

 public:
    System(vector<Prisoner> _prisoners) {
      prisoners = _prisoners;
      boxes.resize(prisoners.size());
      for (int i = 1; i <= prisoners.size(); i++) {
        boxes[i - 1] = i;
      }
    }

    void show() {
      cout << "boxes: [ ";
      for (int i = 0; i < boxes.size(); i++) {
        cout << boxes[i] << " ";
      }
      cout << "]" << endl;
    }

    void shuffle() {
      random_shuffle(std::begin(boxes), std::end(boxes));
    }

    bool run() {
      int index = 1;
      for (int i = 0; i < prisoners.size(); i++) {
        bool found = false;
        for (int j = 0; j < boxes.size() / 2; j++) {
          int box = prisoners[i].guess();
          int value = boxes[box - 1];
          prisoners[i].report(value);

          if (value == index) {
            found = true; 
            break;
          }
        }
        if (found == false) {
          return false;
        }
        index++;
      }
      return true;
    }
};
