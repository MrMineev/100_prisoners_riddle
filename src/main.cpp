#include "System.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int Q = stoi(argv[1]);
  int N = stoi(argv[2]);

  cout << "N: " << N << " Q: " << Q << endl;

  int live = 0, die = 0;

  for (int i = 0; i < Q; i++) {
    vector<Prisoner> prisoners(0, Prisoner(0, 0));
    for (int j = 0; j < N; j++) {
      Prisoner p(j + 1, N);
      prisoners.push_back(p);
    }

    System prison(prisoners);
    prison.shuffle();

    bool res = prison.run();
    cout << "res: " << res << endl;
    if (res == true) {
      live++;
    } else {
      die++;
    }
  }

  cout << "LIVE: " << live << " DIE: " << die << endl;
}


