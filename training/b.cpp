#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
    int n, w, a;
    cin >> n >> w;
    int k = n/w;
    int half = (k+1)/2;
    vector<int> v(1001, 0);
    vector<int> blankets(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == -1) v[0]++;
        else v[a]++;
        blankets[i] = a;
    }
    multiset<pair<int, int>> s1;
    for (int i = 1; i <= 1000; i++) {
        while (v[i] > 0) {
            s1.insert({-min(half, v[i]), i});
            v[i] -= half;
        }
    }
    vector<pair<int,int>> res;
    while (!s1.empty()) {
        auto itFirst = s1.begin();
        auto itOther = s1.lower_bound({-(k-half), 0});
        if (itOther == itFirst) itOther++;
        int numFirst = (*itFirst).first * -1;
        if (numFirst < half) {
            v[0] -= half - numFirst;
        }
        if (itOther == s1.end()) {
            for (int i = 0; i < k; i++) res.push_back({(*itFirst).second, (*itFirst).second});
            v[0] -= k - half;
            s1.erase(itFirst);
        } else {
            for (int i = 0; i < k; i++) res.push_back({(*itFirst).second, (*itOther).second});
            int numOther = (*itOther).first * -1;
            if (numOther < k - half) {
                v[0] -= half - numOther;
            }
            s1.erase(itOther);
            s1.erase(s1.begin());
        }
    }
    if (v[0] < 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    while (v[0]--) {
        res.push_back({1,1});
    }
    
    vector<bool> visited(2000, false);
    vector<pair<int,int>> orderedRes(res.size());
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res.size(); j++) {
            if (i == 4) cout << blankets[i] << endl;
            if (visited[j]) continue;
            if (res[j].first == blankets[i] || res[j].second == blankets[i]) {
                visited[j] = true;
                orderedRes[i] = res[j];
                break;
            }
        }
    }
    for (int i = 0; i < res.size(); i++) {
        if (blankets[i] != -1) continue;
        for (int j = 0; j < res.size(); j++) {
            if (!visited[j])  {
                visited[j] = true;
                orderedRes[i] = res[j];
                break;
            }
        }
    }
    for (auto &el : orderedRes) {
        cout << el.first << " " << el.second << endl;
    }
    
    return 0;
}