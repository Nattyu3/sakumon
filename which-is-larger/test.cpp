#include <bits/extc++.h>
using namespace std;
#define repp(i, m, n) for(int i = (int)m; i < (int)n; i++)
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define fore(x, a) for (auto &x : a)
#define rall(x) (x).rbegin(),(x).rend()
#define all(x) (x).begin(),(x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int main() {
	random_device rd;
  mt19937 mt(rd());
	uniform_int_distribution<int> d1(INT_MIN, INT_MAX);
	uniform_int_distribution<int> d2(0, INT_MAX);

  cout  << "652.";
  rep(i, 300) cout << d2(rd);
	cout << endl;
	
  cout  << "652.";
  rep(i, 300) cout << d2(rd);
	cout  << endl;
}
