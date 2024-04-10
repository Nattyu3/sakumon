waribiki解説
-----

ABC_B,200点の想定問題です。 \
割引率が高いものを高い値段に割り当てればよいです。二つの配列を降順にソートするのが扱いやすいです。 \
$Y$割を引いた後の値段は$X(1 - \frac{Y}{10})$なので、割引券の枚数分ループを回して$X$の値段を更新し、最後に和を求めればよいです。
ソートをする場合の計算量は$O(NlogN)$です。

-----

C++での実装例
``` cpp
#include <bits/extc++.h>
using namespace std;

int main() {
 // input
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  int m;
  cin >> m;
  vector<int> y(m);
  for (int i = 0; i < m; i++) cin >> y[i];
  
 // prog
  sort(x.rbegin(), x.rend());
  sort(y.rbegin(), y.rend());
  for (int i = 0; i < m; i++) x[i] -= x[i] / 10 * y[i];
  int ans = accumulate(x.begin(), x.end(), 0);
  
 // output
  cout << ans << endl;
  return 0;
}
```