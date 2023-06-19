#include <bits/stdc++.h>

using namespace std;

void backtrack(vector<int>& nums, int target, vector<int>& currSet, int index, int currSum, vector<vector<int>>& result) {
    if (currSum == target) {
        result.push_back(currSet);
        return;
    }

    // 剪枝条件：当前和加上剩余数字的最小值大于目标和，或当前和加上剩余数字的最大值小于目标和
    if (currSum > target || (index < nums.size() && currSum + nums[index] > target)) {
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1]) {
            continue;  // 剪枝条件：避免重复元素导致的重复解
        }
        currSet.push_back(nums[i]);
        backtrack(nums, target, currSet, i + 1, currSum + nums[i], result);
        currSet.pop_back();
    }
}

vector<vector<int>> subsetSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> currSet;
    sort(nums.begin(), nums.end());  // 首先对数字样本进行排序
    backtrack(nums, target, currSet, 0, 0, result);
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> subsets = subsetSum(nums, target);

    cout << "Subsets with sum " << target << ":" << endl;
    for (const auto& subset : subsets) {
        for (const auto& num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
