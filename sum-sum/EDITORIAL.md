sum-sum解説
-----

ABC_A,100点の想定問題です。 \
和を求めて引き算すればよいです。

-----

C++での実装例
``` cpp
#include <bits/extc++.h>
using namespace std;

int main() {
 // input
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  
 // prog
  int A, B;
  A = accumulate(a.begin(), a.end(), 0);
  B = accumulate(b.begin(), b.end(), 0);
  
 // output
  cout << A - B << endl;
  return 0;
}
```