#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define ld long double
#define pii pair<ll,ll>

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL

#define f(i,s,e) for(ll i=s;i<e;i++)
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

int getNumWins(vector<string> &lines, char c) {
    int wins = 0;
    f(i,0,3) {
        if (lines[i] == string(3, c)) wins++;
    }
    f(i,0,3) {
        bool allC = true;
        f(j,0,3) {
            if (lines[j][i] != c) allC = false;
        }
        if (allC) wins++;
    }
    bool allC = true;
    f(i,0,3) {
        if (lines[i][i] != c) allC = false;
    }
    if (allC) wins++;
    allC = true;
    f(i,0,3) {
        if (lines[i][2-i] != c) allC = false;
    }
    if (allC) wins++;
    return wins;
}

void solve() {
    vector<string> lines(3);
    f(i,0,3) {
        cin >> lines[i];
    }
    int contX = 0, contO = 0;
    f(i,0,3) {
        f(j,0,3) {
            if (lines[i][j] == 'X') contX++;
            if (lines[i][j] == 'O') contO++;
        }
    }
    if ((contX != contO) && (contX != contO+1)) {
        no();
        return;
    }

    int lastPlay = contX == contO ? 1 : 0;

    int winsX = getNumWins(lines, 'X'), winsO = getNumWins(lines, 'O');
    if ((lastPlay == 0 && winsO) || (lastPlay == 1 && winsX)) {
        no();
        return;
    }
    if (lastPlay == 0) {
        if (winsX) {
            f(i,0,3) {
                f(j,0,3) {
                    if (lines[i][j] == 'X') {
                        lines[i][j] = '.';
                        if (!getNumWins(lines, 'X')) {
                            yes();
                            return;
                        }
                        lines[i][j] = 'X';
                    }

                }
            }
        } else {
            yes();
            return;
        }
    }
    if (lastPlay == 1) {
        if (winsO) {
            f(i,0,3) {
                f(j,0,3) {
                    if (lines[i][j] == 'O') {
                        lines[i][j] = '.';
                        if (!getNumWins(lines, 'O')) {
                            yes();
                            return;
                        }
                        lines[i][j] = 'O';
                    }

                }
            }
        } else {
            yes();
            return;
        }
    }
    no();
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}