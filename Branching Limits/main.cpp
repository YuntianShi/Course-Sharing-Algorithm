#include <iostream>
#include <vector>

using namespace std;

// ����ȫ�ֱ��������ڴ洢��ѽ�
vector<int> bestSubset;
int bestSum = 0;

// �����Ӽ��ĺ�
int calculateSum(const vector<int>& subset) {
    int sum = 0;
    for (int num : subset) {
        sum += num;
    }
    return sum;
}

// ��֧�޽編����Ӽ���������
void subsetSum(const vector<int>& numbers, vector<int>& subset, int currentIndex, int currentSum, int targetSum) {
    // �����ǰ�Ӽ��ĺ͵���Ŀ��ͣ�������ѽ�
    if (currentSum == targetSum) {
        bestSubset = subset;
        bestSum = currentSum;
    }

    // ����Ѿ�����������Ԫ�ػ��ߵ�ǰ�Ӽ��ĺʹ���Ŀ��ͣ����֦����
    if (currentIndex >= numbers.size() || currentSum > targetSum) {
        return;
    }

    // ������ǰԪ�ص����
    subset.push_back(numbers[currentIndex]);
    subsetSum(numbers, subset, currentIndex + 1, currentSum + numbers[currentIndex], targetSum);
    subset.pop_back(); // ���ݣ��Ƴ�����ӵ�Ԫ��

    // ��������ǰԪ�ص����
    subsetSum(numbers, subset, currentIndex + 1, currentSum, targetSum);
}

int main() {
    int n; // Ԫ�ظ���
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

    // �����ѽ�
    cout << "when sum of subsets equals to target:" << endl;
    for (int num : bestSubset) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
