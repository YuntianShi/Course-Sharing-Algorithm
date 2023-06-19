#include <iostream>
#include <vector>

using namespace std;

// 定义全局变量，用于存储最佳解
vector<int> bestSubset;
int bestSum = 0;

// 计算子集的和
int calculateSum(const vector<int>& subset) {
    int sum = 0;
    for (int num : subset) {
        sum += num;
    }
    return sum;
}

// 分支限界法求解子集和数问题
void subsetSum(const vector<int>& numbers, vector<int>& subset, int currentIndex, int currentSum, int targetSum) {
    // 如果当前子集的和等于目标和，更新最佳解
    if (currentSum == targetSum) {
        bestSubset = subset;
        bestSum = currentSum;
    }

    // 如果已经处理完所有元素或者当前子集的和大于目标和，则剪枝返回
    if (currentIndex >= numbers.size() || currentSum > targetSum) {
        return;
    }

    // 包含当前元素的情况
    subset.push_back(numbers[currentIndex]);
    subsetSum(numbers, subset, currentIndex + 1, currentSum + numbers[currentIndex], targetSum);
    subset.pop_back(); // 回溯，移除刚添加的元素

    // 不包含当前元素的情况
    subsetSum(numbers, subset, currentIndex + 1, currentSum, targetSum);
}

int main() {
    int n; // 元素个数
    cout << "Sum of elements:";
    cin >> n;
    vector<int> numbers(n);
    cout << "Value of elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int targetSum;
    cout << "target Sum:";
    cin >> targetSum;

    vector<int> subset;
    subsetSum(numbers, subset, 0, 0, targetSum);

    // 输出最佳解
    cout << "when sum of subsets equals to target:" << endl;
    for (int num : bestSubset) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
