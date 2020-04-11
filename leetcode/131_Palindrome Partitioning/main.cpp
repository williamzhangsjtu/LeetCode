#include <vector>
#include <unordered_map>
using namespace std;
// class Solution {
// public:
//     vector<vector<string>> partition(string s) 
//     {
//         vector<vector<string>> result;
//         vector<string> tmp(1, s.substr(s.size() - 1, 1));
//         vector<vector<vector<string>>> dp(s.size());
//         if (!s.size()) return result;
//         int size = s.size();
//         // unordered_map <int, bool> MAP;
//         // for (int start = 1; start < s.size(); ++start)
//         // {
//         //     if (ifPalindrome(s, start, size - 1))
//         //     {
//         //         MAP[start] = 1;
//         //     }
//         // }
//         dp[s.size() - 1].push_back(tmp);
//         P(s, dp, 0);
//         return dp[0];
//     }

//     bool ifPalindrome(string &s, int start, int end)
//     {
//         while(start <= end)
//         {
//             if (s[start++] != s[end--]) return false;
//         }
//         return true;

//     }
//     vector<vector<string>>* P(string &s, vector<vector<vector<string>>> &dp, int start)
//     {
//         vector<vector<string>> *tmp_return;
//         int tmp_size;
//         if (start >= s.size()) return NULL;
//         if (dp[start].size()) return &dp[start];
//         for (int i = start; i < s.size(); ++i)
//         {
//             if (ifPalindrome(s, start, i))
//             {
//                 tmp_return = P(s, dp, i + 1);
//                 if (tmp_return)
//                 {
//                     for (auto v : *tmp_return)
//                     {
//                         dp[start].push_back(v);
//                         dp[start][dp[start].size() - 1].insert(dp[start][dp[start].size() - 1].begin(), s.substr(start, i - start + 1))
//                     }
//                 } 
//                 else
//                 {
                
//                     dp[start].push_back(vector<string>(1, s.substr(start, i - start + 1)));
//                 }
                
                
//             }
//         }
//         return &dp[start];
//     }
// };

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pars;
        vector<string> par;
        partition(s, 0, par, pars);
        return pars;
    }
private: 
    void partition(string& s, int start, vector<string>& par, vector<vector<string>>& pars) {
        int n = s.length();
        if (start == n) {
            pars.push_back(par);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalindrome(s, start, i)) {
                    par.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1, par, pars);
                    par.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};