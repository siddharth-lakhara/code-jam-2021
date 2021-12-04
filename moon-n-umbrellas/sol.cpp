#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

int calculateAnswer(int X, int Y, string str) {
  int cost = 0;
  
  for (int i=1; i<str.size(); i++) {
    if (str[i] == '?') {
      str[i] = str[i-1];
    }
    // str[i-1] + str[i]
    string substr = str.substr(i-1, 2);
    if (substr == "CJ") {
      cost += X;
    } else if (substr == "JC") {
      cost += Y;
    }
  }

  return cost;
}

int main() {
  // #ifndef ONLINE_JUDGE
  //   auto start = chrono::steady_clock::now();
  // #endif

  // freopen("in", "r", stdin);

  int T, ans;
  cin >> T;

  int X, Y;
  string inputString;
  for (int i=0; i<T; i++) {
    cin >> X;
    cin >> Y;
    cin >> inputString;

    ans = calculateAnswer(X, Y, inputString);

    cout << "Case #" << i+1 << ": " << ans << endl;
  }

  // #ifndef ONLINE_JUDGE
  //   auto end = chrono::steady_clock::now();
  //   auto diff = end - start;
  //   cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
  // #endif

  return 0;
}