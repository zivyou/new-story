//
// Created by zivyou on 2021/4/21.
//

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class SolutionBak1 {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) return s.length();
    std::unordered_map<char, int> map;
    std::list<char> win;
    int re = 0;
    int begin = 0;
    for (int i=0; i<s.length(); i++) {
      if (map.find(s[i]) == map.end()) {
        map[s[i]] = i;
        win.push_back(s[i]);
      } else {
        /* 如果一个字符在之前就已经出现过，需要将窗口中所有在这个出现的位置之前的字符都弹出 */
        // 但是需要确保调整完的滑动窗口内的字符串也是符合规范的
        // abcabcbb, pwwkew, dvdf, abba, anviaj, tmmzuxt
        while (win.size() && win.front() != s[i]) {
          map.erase(win.front());
          win.pop_front();
        }
        if (win.size()) {
          map.erase(win.front());
          win.pop_front();
        }
        win.push_back(s[i]);
        map[s[i]] = i;
      }
      re = re > win.size() ? re : win.size();
    }
    re = re > win.size() ? re : win.size();
    return re;
  }
};

// 上面的解法中显示的使用了list来表示窗口，简单易懂，但是效率不高
// 尝试下只给出高低水位来描述窗口
class SolutionBak2 {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) return s.length();
    std::unordered_map<char, int> map;
    int begin = 0; int end = 0; int re = 0;
    for (int i=0; i<s.length(); i++) {
      if (map.find(s[i]) == map.end()) {
        map[s[i]] = i;
        end = i;
      } else {
        end = i;
        // 弹出和当前值相同的那个元素之前的所有元素
        while (begin < end && s[begin] != s[end]) {
          map.erase(s[begin]);
          begin++;
        }
        if (begin<end && s[begin] == s[end]) {
          map.erase(s[begin]);
          begin++;
        }
        map[s[i]] = i;
      }
      re = re > end - begin +1 ? re : end - begin + 1;
    }
    re = re > end - begin + 1 ? re : end - begin + 1;

    return re;
  }
};

// 上面的解法还是不够快
// 使用自制的map去除unordered_map试试
/*
 * 执行用时：
8 ms
, 在所有 C++ 提交中击败了
88.55%
的用户
内存消耗：
6.8 MB
, 在所有 C++ 提交中击败了
79.54%
的用户
 */
class Solution {
private:
  int map[256] = { 0 };
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) return s.length();
    for (int i=0; i<256; i++) map[i] = 0;
    int begin = 0; int end = 0; int re = 0;
    for (int i=0; i<s.length(); i++) {
      end = i;
      if (map[s[i]] == 1) {
        // 弹出和当前值相同的那个元素之前的所有元素
        while (begin < end && s[begin] != s[end]) {
          map[s[begin]] = 0;
          begin++;
        }
        if (begin<end && s[begin] == s[end]) {
          map[s[begin]] = 0;
          begin++;
        }
      }
      map[s[i]] = 1;
      re = re > end - begin +1 ? re : end - begin + 1;
    }
    re = re > end - begin + 1 ? re : end - begin + 1;
    return re;
  }
};

int main() {
  Solution s;
  std::string str;
  while (cin>>str) {
    cout<<s.lengthOfLongestSubstring(str)<<endl;
  }

  return 0;
}