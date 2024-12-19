#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool g[15][15];
int sol[15][1<<15];

bool solve(int n, int k, int pos, int mask, int len, int start){
	if (len == k-1)
		return g[pos][start];	

	if (sol[pos][mask] != -1)
		return sol[pos][mask];

	for (int next = 0; next < n; next++)
		if (!(mask & (1 << next)) && g[pos][next])
			if (solve(n, k, next, mask | (1 << next), len+1, start))
				return sol[pos][mask] = true;

	return sol[pos][mask] = false;
}

bool trazi(int n,int k){
	memset (sol, -1, sizeof(sol));
	
	for (int start = 0; start<n; start++)
		if (solve(n, k, start, 1 << start, 0, start))
			return true;
	
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cout << "Unesite ime datoteke: ";
	// string dat; cin >> dat;

	string dat = "test.txt";

	freopen(dat.c_str(), "r", stdin);

	int n, k; cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j)
            g[i][j] = s[j] - '0';
    }

    cout << "\nRjesenje: " << trazi(n, k);
	
	return 0;
}