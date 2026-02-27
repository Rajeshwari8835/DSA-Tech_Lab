#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        build(nums, 0, 0, n-1);
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if(start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        build(nums, 2*node+1, start, mid);
        build(nums, 2*node+2, mid+1, end);

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if(idx <= mid)
            update(2*node+1, start, mid, idx, val);
        else
            update(2*node+2, mid+1, end, idx, val);

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    int query(int node, int start, int end, int L, int R) {
        if(R < start || L > end)
            return INT_MIN;

        if(L <= start && end <= R)
            return tree[node];

        int mid = (start + end) / 2;

        return max(
            query(2*node+1, start, mid, L, R),
            query(2*node+2, mid+1, end, L, R)
        );
    }
};