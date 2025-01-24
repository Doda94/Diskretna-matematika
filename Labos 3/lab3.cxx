#include <bits/stdc++.h>

using namespace std;

bool valid_coloring(const vector<vector<int> >& graph, vector<int>& colors, int vertex, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[vertex][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool obojaj(const vector<vector<int> >& graph, vector<int>& colors, int vertex, int k, int maxColor) {
    if (vertex == graph.size())
        return true;  
    
    for (int color = 1; color <= min(maxColor+1, k); color++) {
        if (valid_coloring(graph, colors, vertex, color)) {
            colors[vertex] = color;
            if (obojaj(graph, colors, vertex + 1, k, max(maxColor, color)))
                return true;
            colors[vertex] = 0; 
        }
    }
    return false;
}

int main() {
    string filename;
    cout << "Unesite ime datoteke: ";
//    cin >> filename;
    filename = "graf.txt";

    freopen(filename.c_str(), "r", stdin);

    int n, k;
    cin >> n >> k;

    vector<vector<int> > graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            graph[i][j] = (c == '1');
        }
    

    vector<int> colors(n, 0);

    (obojaj(graph, colors, 0, k, 0)? cout << 1 : cout << 0) << endl;

    return 0;
}