#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for(int i = 0; i < nums.size(); i++) {

        // Remove out of window
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();

        // Remove smaller elements
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if(i >= k-1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}