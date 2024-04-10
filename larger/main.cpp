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

  string s = "", ss = "", t = "", tt = "";
  for (int i = mi, c = 0; i < (int)n.size(); i++) {
    if (n[i] == '.') {
      c = 1;
      continue;
    }
    if (!c) s += n[i];
    else ss += n[i];
  }
  for (int i = mi, c = 0; i < (int)m.size(); i++) {
    if (m[i] == '.') {
      c = 1;
      continue;
    }
    if (!c) t += m[i];
    else tt += m[i];
  }

  out(mi ^ (s.size() < t.size()));

  int zss = ss.size(), ztt = tt.size();
  if (zss < ztt) for (int i = 0; i < ztt-zss; i++) ss += '0';
  if (ztt > zss) for (int i = 0; i < zss-ztt; i++) tt += '0';

  bool ch = true;
  if (s < t) ch = false;
  else if (s == t) if(ss < tt) ch = false;
  
  out(ch ^ mi);
  return 0;
}
