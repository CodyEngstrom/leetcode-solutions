#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <array>

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



// 49 Group Anagrams

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        
        // strs = ["eat", "tan"]
        // output : [['eat'], ['tan']]

        // strs = ["eat", "tan", "ate"]
        // output : [['eat'], ['tan']]

        // eat : [e: 1] [a: 1] [t: 1]
        // tan : [t: 1] [a: 1] [n: 1]
        // ate : [a: 1] [t: 1] [e: 1]
        // tea : [t: 1] [e: 1] [a: 1]

        // BRAINSTORMING SPACE
        // Vector < Map > layout to index of returning vector string
        // For (str in strs)
        // Construct a map of str 
        // Check str against vector map
        // If not there, insert a new Map into vector and insert into following vector 
        // If map is the same, insert into the same index. 


        std::vector<std::unordered_map<char ,int>> map;
        // std::unordered_map<char, int> map;
        std::vector<std::vector<std::string>> result;

        for (int i = 0; i < strs.size(); i++) {
                for (auto c : strs[i]) {
                    map_index[i][c]++;
                }
            }

        for (int i = 0; i < strs.size(); i++) {
            std::vector<std::string> vec = {strs[i]};

            for (int j = i+1; j < strs.size(); j++) {
                if (map[i] == map[j]) {
                    vec.push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                    j--;
                }
           }
           result.push_back(vec);
        }

        return result;



        // Start at index 0... ++ 
        for (int i = 0; i < strs.size(); i++) {
            std::vector<std::string> vec = {strs[i]};
            
            int str1;
            if(strs[i].empty()) {
                str1 = 0;
            } else {
                str1 = stoi(strs[i]);
            }

            // Second for loop
            // Compare all of the other strings and add them to the vector if matched. 
            int str2;
            for (int j = i+1; j < strs.size(); j++) {
                int str2 = stoi(strs[j]);
                
                if(strs[i].empty()) {
                    str2 = 0;
                } else {
                    str2 = stoi(strs[i]);
                }

                if (str1 == str2) {
                    vec.push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                    j--;
                }

            }
            
            result.push_back(vec);
        }
        return result;
        
    }
};