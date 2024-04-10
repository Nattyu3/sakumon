#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define all(x) (x).begin(), (x).end()

void out(int x) {
  if (x) puts("Yes");
  else puts("No");
  exit(0);
}

int main() {
  string n, m;
  cin >> n >> m;

  if (n[0] == '-' && m[0] != '-') {
    cout << "No" << endl;
    return 0;
  }
  if (n[0] != '-' && m[0] == '-') {
    cout << "Yes" << endl;
    return 0;
  }
  
  int mi = (n[0] == '-');

  string s = "", t = "";
  string ss = "", tt = "";
  for (int i = mi, ch = 0; i < (int)n.size(); i++) {
    if (n[i] == '.') {
      ch = 1;
      continue;
    }
    if (!ch) s += n[i];
    else ss += n[i];
  }
  for (int i = mi, ch = 0; i < (int)m.size(); i++) {
    if (m[i] == '.') {
      ch = 1;
      continue;
    }
    if (!ch) t += m[i];
    else tt += m[i];
  }

  out(mi ^ (s.size() < t.size());

  int zss = ss.size(), ztt = tt.size();
  if (zss < ztt) rep(i, ztt-zss) ss += '0';
  if (ztt > zss) rep(i, zss-ztt) tt += '0';

  bool ch = true;
  if (s < t) ch = false;
  else if (s == t) if(ss < tt) ch = false;
  
  out(ch ^ mi);
  return 0;
}
