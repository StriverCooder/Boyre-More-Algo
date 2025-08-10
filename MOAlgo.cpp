#include <bits/stdc++.h>
using namespace std;

struct Query {
    int L, R, idx;
};

// Mo's algorithm comparator
int block_size;
bool cmp(Query a, Query b) {
    if (a.L / block_size != b.L / block_size)
        return a.L / block_size < b.L / block_size;
    return a.R < b.R;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].idx = i;
    }

    block_size = sqrt(n);
    sort(queries.begin(), queries.end(), cmp);

    vector<long long> ans(q);
    long long curr_sum = 0;
    int currL = 0, currR = -1;

    auto add = [&](int pos) {
        curr_sum += arr[pos];
    };

    auto remove = [&](int pos) {
        curr_sum -= arr[pos];
    };

    for (auto &qu : queries) {
        int L = qu.L, R = qu.R;

        while (currL > L) add(--currL);
        while (currR < R) add(++currR);
        while (currL < L) remove(currL++);
        while (currR > R) remove(currR--);

        ans[qu.idx] = curr_sum;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}
