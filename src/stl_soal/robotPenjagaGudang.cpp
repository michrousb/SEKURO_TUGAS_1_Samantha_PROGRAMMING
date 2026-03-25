#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> koordinat(n);
    vector<int>id(n);
    vector<pair<int,int>>paket;
    int jumlah_paket = 0;
    map<int, bool> taken;
    for (int i = 0; i < n; i++) { /*input koordinat*/
        cin >> koordinat[i];
    }
    for (int i=0; i<n; i++){ /*input id*/
        cin >> id[i];
        paket.push_back(make_pair(koordinat[i],id[i]));
    }

    /*urutkan koordinat (dari yang terkecil))*/
    
    sort(paket.begin(), paket.end());

    for(int i = 0; i<n; i++){
        if (!taken[paket[i].second]){ /*jika id belum pernah diambil*/
            taken[paket[i].second] = true; /*tandai id sudah diambil*/
            jumlah_paket++; 
    }
    }
    cout << jumlah_paket << endl;

}

