#include <bits/stdc++.h>

using namespace std;

void backtrack(vector<int>& nums, int target, vector<int>& currSet, int index, int currSum, vector<vector<int>>& result) {
    if (currSum == target) {
        result.push_back(currSet);
        return;
    }

    // ��֦��������ǰ�ͼ���ʣ�����ֵ���Сֵ����Ŀ��ͣ���ǰ�ͼ���ʣ�����ֵ����ֵС��Ŀ���
    if (currSum > target || (index < nums.size() && currSum + nums[index] > target)) {
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1]) {
            continue;  // ��֦�����������ظ�Ԫ�ص��µ��ظ���
        }
        currSet.push_back(nums[i]);
        backtrack(nums, target, currSet, i + 1, currSum + nums[i], result);
        currSet.pop_back();
    }
}

vector<vector<int>> subsetSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> currSet;
    sort(nums.begin(), nums.end());  // ���ȶ�����������������
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
