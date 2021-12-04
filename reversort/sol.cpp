#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

int calculateAnswer(vector<int> input) {
  int ans = 0;
  int min = 0;
  for (int i=0; i<input.size() - 1; i++) {
    vector<int>::iterator start_it = input.begin() + i;
    vector<int>::iterator end_it = input.end();
    vector<int>::iterator min_it = min_element(start_it, end_it);
    int min_index = min_it - input.begin();
    int cost = min_index - i + 1;
    ans += cost;

    reverse(start_it, min_it + 1);
  }
  return ans;
}

int main() {
  // #ifndef ONLINE_JUDGE
  //   auto start = chrono::steady_clock::now();
  // #endif

  int T, N, temp, ans;
  cin >> T;

  vector<int> input;
  for (int i=0; i<T; i++) {
    input.clear();

    cin >> N;
    for (int j = 0; j<N; j++) {
      cin >> temp;
      input.push_back(temp);
    }

    ans = calculateAnswer(input);

    cout << "Case #" << i+1 << ": " << ans << endl;
  }

  // #ifndef ONLINE_JUDGE
  //   auto end = chrono::steady_clock::now();
  //   auto diff = end - start;
  //   cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
  // #endif

  return 0;
}