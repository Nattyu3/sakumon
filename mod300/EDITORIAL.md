mod300解説
-----

ABC_Cの過去問の類題です。 \
「$A_i−A_j$が$300$の倍数である」ということは、「$A_i$を$300$で割った余りと$A_j$を$300$で割った余りが一致する」と言い換えられます。 \
まずは入力の$A_i$をすべて$300$で割り、$0$から$299$までの余りの数を記録しておく配列に記録します。 \
組み合わせの数は $\frac{N \times (N-1)}{2}$であることから、余りの個数に対しての組み合わせ数の総和が答えになります。

-----
C++での実装例
```cpp
#include <bits/extc++.h>

using namespace std;

int main(){
 // input
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
 
 // prog
  vector<long long> b(300, 0);
  for (int i = 0; i < n; i++) b[a[i] % 300]++;

  long long ans = 0;
  for(int k = 0; k < 300; k++){
    ans += (b[k] * (b[k] - 1)) / 2; // nCr
  }
  
 // output
  cout << ans << endl;
  return 0;
}
```