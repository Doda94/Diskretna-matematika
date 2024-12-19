#include <bits/stdc++.h>
using namespace std;

bool g[15][15];
bool visited[15];

bool dfs(int n, int k, int curr, int start, int len) {
    if (len == k - 1)
        return g[curr][start];
        
    for (int next = 0; next < n; next++) {
        if (!visited[next] && g[curr][next]) {
            visited[next] = true;
            if (dfs(n, k, next, start, len + 1))
                return true;
            visited[next] = false;
        }
    }
    return false;
}

bool trazi(int n, int k) {
    for (int start = 0; start < n; start++) {
        memset(visited, false, sizeof(visited));
        visited[start] = true;
        if (dfs(n, k, start, start, 0))
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cout << "Unesite ime datoteke: ";
    string dat;
	// cin >> dat;

	dat = "test.txt";

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