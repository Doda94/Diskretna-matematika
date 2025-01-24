#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool jeSigurno(int vrh, int boja, const vector<vector<int>>& graf, vector<int>& boje) {
    for (int i = 0; i < graf.size(); i++) {
        if (graf[vrh][i] == 1 && boje[i] == boja) {
            return false;
        }
    }
    return true;
}

bool bojanjeGrafaPomocno(int vrh, int k, const vector<vector<int>>& graf, vector<int>& boje, int max_boja) {
    if (vrh == graf.size()) {
        return true;
    }

    // Optimizacija: iteriramo samo do min(max_boja + 1, k)
    for (int b = 1; b <= min(max_boja + 1, k); b++) {
        if (jeSigurno(vrh, b, graf, boje)) {
            boje[vrh] = b;
            if (bojanjeGrafaPomocno(vrh + 1, k, graf, boje, max(max_boja, b))) {
                return true;
            }
            boje[vrh] = 0;
        }
    }
    return false;
}

bool bojanjeGrafa(int k, const vector<vector<int>>& graf) {
    vector<int> boje(graf.size(), 0);
    return bojanjeGrafaPomocno(0, k, graf, boje, 0); // Počinjemo s max_boja = 0
}

int main() {
    string imeDatoteke;
    cout << "Unesite ime datoteke: ";
    cin >> imeDatoteke;

    ifstream datoteka(imeDatoteke);
    if (!datoteka.is_open()) {
        cerr << "Greska: Ne mogu otvoriti datoteku." << endl;
        return 1;
    }

    int n, k;
    datoteka >> n >> k;

    vector<vector<int>> graf(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        string linija;
        datoteka >> linija;
        for (int j = 0; j < n; j++) {
            graf[i][j] = linija[j] - '0';
        }
    }

    datoteka.close();

    bool rjesenje = bojanjeGrafa(k, graf);
    cout << "Rjesenje: " << (rjesenje ? 1 : 0) << endl;

    return 0;
}