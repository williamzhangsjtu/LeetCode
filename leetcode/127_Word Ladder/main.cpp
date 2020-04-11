#include <vector>
#include <string>
#include <queue>
using namespace std;
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
//     {
//         int tran_num = 0;
//         if (!wordList.size()) return 0;
//         bool found = false;
//         for (string word : wordList)
//         {
//             if (word == endWord) {found = true; break;}
//         }
//         if (!found) return 0;
//         tran_num = ladder(beginWord, endWord, wordList);
//         return tran_num >= wordList.size() + 1 ? 0 : tran_num;
//     }
//     int ladder(string begin, string &end, vector<string> &wordList)
//     {
//         if (begin == end) return 0;
//         int count;
//         int num = wordList.size() + 1;
//         for (int j = 0; j < wordList.size() && wordList[j].size() == begin.size(); ++j)
//         {
//             string word = wordList[j];
//             count = 0;
//             for (int i = 0; i < word.size(); ++i)
//             {
//                 if (word[i] != begin[i]) ++count;
//                 if (count > 1) break;
//             }
//             if (count == 1)
//             {
//                 wordList[j] = "";
//                 num = min(ladder(word, end, wordList), num);
//                 wordList[j] = word;
//             }
             
//         }
//         if (num != wordList.size() + 1) num++;
        
//         return num;
        
//     }
// };


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue <string> Q;
        Q.push(beginWord);
        string tmp;
        int index, current_height = 1, layer_num = 1, next_num = 0;
        while(!Q.empty())
        {
            tmp = Q.front();
            Q.pop();
            if (tmp == endWord) return current_height;
            for (int i = 0; i < tmp.size(); i++)
            {
                char ch = tmp[i];
                for (int j = 0; j < 26; ++j)
                {
                    tmp[i] = 'a' + j;
                    if (dict.find(tmp) != dict.end()) 
                    {
                        Q.push(tmp);
                        dict.erase(tmp);
                        next_num++;
                    }
                }
                tmp[i] = ch;
            }
            if (!--layer_num) 
            {
                layer_num = next_num;
                current_height++;
                next_num = 0;
            }
                

        }
        return 0;
    }
};