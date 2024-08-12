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
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

string convert(int x, int y) {
    string s(2, ' ');
    s[0] = y + 'a';
    s[1] = x + '1';
    return s;
}

void solve() {
    int r = 8, c = 8;
    string s;
    cin >> s;
    int gr = s[1]-'1';
    int gc = s[0]-'a';
    vector<vector<bool>> visited(r, vector<bool>(c, 0));
    visited[gr][gc] = 1;
    queue<tuple<int,int,int>> q;
    q.push({gr, gc, 0});
    map<int, vector<string>> res;
    while(!q.empty()) {
        auto el = q.front(); q.pop();
        int x = get<0>(el);
        int y = get<1>(el);
        int dist = get<2>(el);
        // cout << convert(x,y) << " " << dist << endl;
        res[-dist].push_back(convert(x,y));
        int dx[] = {-1,-2,-2,-1, 1, 2, 2, 1};
        int dy[] = {-2,-1, 1, 2, 2, 1,-1,-2};
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 or nx >= r) continue;
            if (ny < 0 or ny >= c) continue;
            if (!visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push({nx, ny, dist+1});
            }
        }
    }
    auto curr = (*(res.begin()));
    cout << -curr.first;
    sort(curr.second.begin(), curr.second.end(), [](const string &a, const string &b){
        if (a[1] > b[1]) return true;
        if (a[1] == b[1]) return (a[0] < b[0]);
        return false;
    });
    for (auto el : curr.second) {
        cout << " " << el;
    }
    cout << endl;
}

int main() {
    optimize;
    int n; cin >> n;
    while (n--) solve();

    return 0;
}