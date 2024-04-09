#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define all(x) x.begin(),x.end()

bool p1wins(string a, string b) {
    if (a == "rock" && b == "scissors") return true;
    if (a == "scissors" && b == "paper") return true;
    if (a == "paper" && b == "rock") return true;
    return false;
}

int main() {
    optimize;
    
    int n, k, p1, p2;
    bool first = true;
    while (cin >> n, n) {
        if (first) first = false;
        else cout << endl;
        cin >> k;
        string a, b;
        vector<int> totalWins(n, 0);
        vector<int> totalLosses(n, 0);

        for (int i = 0; i < k*(n*(n-1)/2); i++) {
            cin >> p1 >> a >> p2 >> b;p1--;p2--;
            if (p1wins(a,b)) {
                totalWins[p1]++;
                totalLosses[p2]++;
            } else if (p1wins(b,a)) {
                totalWins[p2]++;
                totalLosses[p1]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!totalWins[i] && !totalLosses[i]) cout << fixed << "-" << endl;
            else cout << fixed << setprecision(3) << (double)totalWins[i]/(double)(totalWins[i]+totalLosses[i]) << endl;
        }
    }

    return 0;
}