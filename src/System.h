#include <algorithm>
#include <vector>

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
        boxes[i] = i;
      }

      cout << "box size: " << boxes.size() << " prisoners size: " << prisoners.size() << endl;
    }

    void shuffle() {
      random_shuffle(boxes.begin(), boxes.end());
    }

    bool run() {
      cout << "RUNNING!" << endl;
      int index = 1;
      for (int i = 0; i < prisoners.size(); i++) {
        bool found = false;
        for (int j = 0; j < boxes.size() / 2; j++) {
          int box = prisoners[i].guess();
          if (box > boxes.size()) {
            cout << "ERROR" << endl;
          }
          int value = boxes[box - 1];
          if (value > 100) {
            cout << "AAAA" << endl;
          }
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
