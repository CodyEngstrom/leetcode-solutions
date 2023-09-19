#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

// 9/18/2023
// 217. Contains Duplicate
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        
        std::unordered_set<int> temp;

        for(int i = 0; i < nums.size(); i++) {
            if (!(temp.find(nums[i]) == temp.end())) {
                return true;
            } 
            temp.insert(nums[i]);
        }
        return false;
    }
};


// class Solution {
//   public:
//       bool containsDuplicate(vector<int>& nums) {
//           unordered_map<int,int> mp;
//           for(auto i : nums) mp[i]++;
//           bool flag = false;
//           for(auto i : mp){
//               if(i.second >= 2) return true;
//           }
//           return flag;
//       }
//   };

// 242 Valid Anagram 
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> map;
        
        for(int i = 0; i < s.length(); i++) {
            map[s[i]]++;
            map[t[i]]--;
        }
        
        for (auto i : map) {
            if(i.second != 0) {
                return false;
            }
        }
        return true;

    }
};

// Two Sum 
