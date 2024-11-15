#include <cstdio>
#include <iostream>

typedef long long ll;

#define pb push_back

using namespace std;

string cajevi[5] = {"Bohea", "Congou", "Souchong", "Singlo", "Hyso"};
char parametar[5] = {'a', 'b', 'c', 'd', 'e'};
int broj_cajeva[5], n;

const int MAX_N = 15000;

ll dp[15001];

void input() {
  // test case iz primjera
  // freopen("test.txt", "r", stdin);

  for (int i = 0; i < 5; i++) {
    cout << "Unesite broj vrecica caja " << cajevi[i] << " (parametar "
         << parametar[i] << "): ";
    cin >> broj_cajeva[i];
  }

  cout << "Unesite broj n: ";
  cin >> n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  input();

  dp[0] = 1;

  for (int caj : broj_cajeva) {
    for (int i = n; i >= 0; --i) {
      int max = (caj == -1 || caj > n) ? n - i : caj;
      for (int j = 1; j <= max && i + j <= n; ++j) {
        dp[i + j] += dp[i];
      }
    }
  }

  //   for (int i = 0; i <= n; i++) {
  // cout << "dp[" << i << "] = " << dp[i] << endl;
  //   }

  //   cout << dp[n];

  cout << "Gradjani Bostona mogu napraviti " << dp[n] << " razlicitih cajanki.";

  return 0;
}