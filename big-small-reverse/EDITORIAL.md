big-small-reverse解説
-----

ABC_B、200点の想定問題です。\
問題文、サンプルケースの通りに実装すればよいです。

-----
C++での実装例
```cpp
#include <bits/extc++.h>
using namespace std;

int main() {
 // input
  string s;
  cin >> s;

 // prog
  for (int i = 0; i < (int)s.size(); i++) {
    if ('A' <= s[i] && s[i] <= 'Z') s[i] = tolower(s[i]);
    else if ('a' <= s[i] && s[i] <= 'z') s[i] = toupper(s[i]);
  }
  reverse(s.begin(), s.end());

 // output
  cout << s << endl;
  return 0;
}
```