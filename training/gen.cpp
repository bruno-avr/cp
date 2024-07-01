#include "bits/stdc++.h"

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ld long double
#define vp vector<pair<ld,int>>

using namespace std;

int L = -20000000;
int R = 20000000;

pair<ld,int> INF = {100, 0};
pair<ld,int> NINF = {-100, 0};

vp lis(vp &v) {
	int n = v.size(), m = -1;
	vp d(n+1, INF);
	vector<int> l(n);
	d[0] = NINF;

	for (int i = 0; i < n; i++) {
		int t = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
		d[t] = v[i], l[i] = t, m = max(m, t);
	}

	int p = n;
	vp ret;
	while (p--) if (l[p] == m) {
		ret.push_back(v[p]);
		m--;
	}
	reverse(ret.begin(),ret.end());

	return ret;
}

int main() {
    optimize;
    vector<pair<ld,int>> v;
    for (int i = L; i < R; i+=10) {
		v.push_back({sinl(i), i});
    };
    auto res = lis(v);
	bool first = true;
	// cout << "{";
	// for (auto el : res) {
	// 	if (first) first = false;
	// 	else cout << ",";
	// 	cout << el.second;
	// }
	// cout << "}" << endl;

    cout << res.size() << endl;
    

    return 0;
}