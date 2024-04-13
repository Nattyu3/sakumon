larger解説
-----

ABC_BかC、250点程度の想定問題です。\
制約がとても大きいため、(C++では)文字列型を用いて処理する必要があります。
この問題は $N$ の整数部分 $S$ 、小数部分 $s$ 、 $M$ の整数部分 $T$ 、小数部分 $t$ を用いて次のような手順で解くことができます。

- $N,M$ の正負が異なり、 $N$ が正ならYesを、負ならNoを出力
- $S,T$ の桁数が異なり、 $S$ の方が桁数が大きい場合、 $N,M$ の双方が正ならYesを、負ならNoを出力
- $S,T$ を辞書順比較して $S < T$ で正ならNoを、負ならYesを、 $S>T$ で正ならYesを、負ならNoを出力
- $S,T$ が等しい場合、 $s < t$ で正ならNoを、負ならYesを、 $s>t$ で正ならYesを、負ならNoを出力

実装例では、 $N,M$ の双方の符号がどちらかというフラグと、 $N,M$ の絶対値を比べた時にどちらの方が大きいかを持つフラグを持っておき、xor演算を用いることで答えを出力しています。

C++での実装例
``` cpp
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

```

### 不正解となる解法
- $N,M$ を整数型や実数型でそのまま比較する → オーバーフローや小数点以下の精度の問題でWAとなります。
- $N,M$ を文字列型にしてそのまま比較する → 辞書順の比較では $"9" > "11"$ となってしまい、WAとなります。