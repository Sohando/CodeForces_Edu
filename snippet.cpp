#include<bits/stdc++.h>
using namespace std;
int dp[1<<21];
int fib(long long int a, int b) {
  if (dp[a % b] != -1) return dp[a % b];
  if (a % b == 0) return 0 % b;
  else if (a % b == 1) return 1 % b;
  return dp[a % b] = ((fib(a - 2, b) % b + fib(a - 1, b) % b) % b);
}
inline int mod(long long int a, int b) {
  return fib(a, b);
}
void solve(long long int n, int m) {
  memset(dp, -1, sizeof dp);
  function<int(int, int)> _pow = [&](int a, int b) {    
    int ret = 1;
    while (b > 0) {
      if (b & 1) {
        ret = ret * a;
      }
      a = a * a;
      b >>= 1;
    }
    return ret;
  };
  int p = _pow(2, m);
  cout << mod(n, p) << "\n"; 
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  long long int n;
  while (cin >> n >> m) {
    solve(n, m);
  }
  return 0;
}