//
// Created by zivyou on 2021/4/21.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  // 使用std::map大约需要28ms的AC时间，而改用std::unordered_map大约只需要8ms的AC时间
  // std::map有序表的时间花费应该主要是插入和查找的时间增加了
  std::unordered_map<int, int> m;
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i=0; i<nums.size(); i++) {
      int a = nums[i]; int b = target - nums[i];
      if (m.find(b) != m.end()) {
        return vector<int>({i, m[b]});
      } else {
        if (m.find(a) == m.end()) {
          m[a] = i;
        } else {
          // 重复的a
          if (a == target -a) {
            return vector<int>({i, m[a]});
          }
        }
      }
    }
    return vector<int>();
  }
};

int main() {
  vector<int> data = {0, 1, 3, -3};
  Solution s;
  vector<int> re = s.twoSum(data, 0);
  for (auto e : re) {
    cout<<e<<", ";
  }
  cout<<endl;
  return 0;
}