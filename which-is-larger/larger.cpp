#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void out(int x) {
  if (x) puts("Yes");
  else puts("No");
  exit(0);
}

int main() {
 // input
  string N, M;
  cin >> N >> M;

 // prog
  if (N[0] == '-' && M[0] != '-') {
    cout << "No" << endl;
    return 0;
  }
  if (N[0] != '-' && M[0] == '-') {
    cout << "Yes" << endl;
    return 0;
  }
  
  int mi = (N[0] == '-');

  string S = "", s = "", T = "", t = "";
  for (int i = mi, c = 0; i < (int)N.size(); i++) {
    if (N[i] == '.') {
      c = 1;
      continue;
    }
    if (!c) S += N[i];
    else s += N[i];
  }
  for (int i = mi, c = 0; i < (int)M.size(); i++) {
    if (M[i] == '.') {
      c = 1;
      continue;
    }
    if (!c) T += M[i];
    else t += M[i];
  }

 // output
  if (S.size() != T.size()) out(mi ^ (S.size() > T.size()));

  bool ch = true;
  if (S < T) ch = false;
  else if (S == T) if(s < t) ch = false;

  out(ch ^ mi);
  return 0;
}
