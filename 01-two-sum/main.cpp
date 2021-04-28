//
// Created by zivyou on 2021/4/19.
//

/**
 * 使用快速排序来调整数组，在调整的过程中记录下标的变化
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
  void swap(vector<int>& data, int i, int j, vector<int>& index) {
    if (index[i] == -1) index[i] = i;
    if (index[j] == -1) index[j] = j;
    int tIndex = index[i];
    index[i] = index[j];
    index[j] = tIndex;
    using std::swap;
    std::swap(data[i], data[j]);
  }

  int part(vector<int>& data, int L, int R, vector<int>& index) {
    // 用re指向'大于sign的数字中最左边的下标'
    int re = L;
    int sign = data[R];
    /*如果这里i<=R的话，接下来的判断必定成立，可能会导致re>R的情况出现（数组已排好序的情况）*/
    for (int i=L; i<R ; i++) {
      if (data[i] <= sign) {
        swap(data, i, re, index);
        re++;
      }
    }
    swap(data, re, R, index);
    return re;
  }
  void quickSort(vector<int>& data, int L, int R, vector<int>& index) {
    if (L >= R) return;
    int mid = part(data, L, R, index);
    quickSort(data, L, mid-1, index);
    quickSort(data, mid, R, index);
  }
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> index(nums.size(), -1);
    quickSort(nums, 0, nums.size()-1, index);

    int i=0; int j=nums.size()-1;
    while (i<j) {
      int sum = nums[i] + nums[j];
      if (sum == target) {
        return {index[i], index[j]};
      } else if (sum < target) {
        i++;
      } else {
        j--;
      }
    }
    return vector<int>();
  }
};

int main() {
  Solution s;
  vector<int> data = {2, 7, 11, 15};
  vector<int> re = s.twoSum(data, 9);
  for (auto e : re) {
    cout<<e<<", ";
  }
  cout<<endl;
  return 0;
}