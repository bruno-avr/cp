#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

struct waveletTree {
    int lo, hi; // Range of elements
    waveletTree *l, *r; // Left and Right child
    vector<int> b; // Freq array

    // Array is in range [x, y]
    // Indices are in range [from, to]
    waveletTree(vector<int>::iterator from, vector<int>::iterator to, int x, int y) {
        lo = x, hi = y;

        // Array is of 0 length
        // Or a is homogeneous, like {1,1,1,1}
        if(from == to or hi == lo) return;

        b.reserve(to - from + 1);
        b.push_back(0);

        int mid = (lo+hi)/2;
        // Lambda function to check if a number
        // is less than or equal to mid
        auto f = [mid](int x){
			return x <= mid;
		};

        for(auto it = from; it != to; it++)
			b.push_back(b.back() + f(*it));

        auto pivot = stable_partition(from, to, f);
		l = new waveletTree(from, pivot, lo, mid);
		r = new waveletTree(pivot, to, mid+1, hi);
    }

    // count of elements in [l, r] equal to k
    // the interval is 1-indexed
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}

    // kth smallest element in [l, r]
    // the interval is 1-indexed
	int kth(int l, int r, int k){
		if(l > r) return 0;
		if(lo == hi) return lo;
		int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left 
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		int inLeft = rb - lb;
		if(k <= inLeft) return this->l->kth(lb+1, rb , k); // kth is in the left child
		return this->r->kth(l-lb, r-rb, k-inLeft); // kth is the in right child
	}

    // count of nos in [l, r] that are <= k
    // the interval is 1-indexed
	int lte(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l-1], rb = b[r];
		return this->l->lte(lb+1, rb, k) + this->r->lte(l-lb, r-rb, k);
	}

    // swap element with index (i) with element with index (i+1)
    // the index is 1-indexed
    void swap(int i) {
        if (lo == hi or i >= b.size() or i <= 0) return;
        bool iLeft = b[i] > b[i-1];
        bool i1Left = b[i+1] > b[i];
        if (iLeft && i1Left) this->l->swap(b[i]);
        if (!iLeft && !i1Left) this->r->swap(i-b[i]);
        if (iLeft && !i1Left) b[i]--;
        if (!iLeft && i1Left) b[i]++;
    }
};

int main() {
    optimize;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<int> aux(v.begin(), v.end());
    unordered_map<int, int> compress;
    unordered_map<int, int> decompress;
    int idx = 0;
    for (auto &el : aux) {
        compress[el] = ++idx;
        decompress[idx] = el;
    }
    for (int i = 0; i < n; i++) {
        v[i] = compress[v[i]];
    }

    waveletTree wt(v.begin(), v.end(), 1, idx);

    string query;
    int a, b, k;
    for (int i = 0; i < q; i++) {
        cin >> query;
        if (query == "Q") {
            cin >> a >> b >> k;
            cout << decompress[wt.kth(a,b,k)] << endl;
        } else {
            cin >> k;
            wt.swap(k);
        }
    }

    return 0;
}