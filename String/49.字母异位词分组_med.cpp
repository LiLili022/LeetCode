/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]
*/

/**
 * 思路一: (一般)
 * 1.使用 hash算法 使每个字符都可对计算的 hash值 产生影响
 * 2.使用 unordered_map<hash_num, vector<string>>容器存储
 */

class Soulation {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto arrayHash = [ fn = hash<int>{} ] (const array<int, 26> &arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc < 1) ^ fn(num);
            });
        }; // 确保string中的每一位char都对结果产生影响

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);

        for (string str : strs) {
            array<int, 26> counts{};
            int length = coutns.size();
            for (int i = 0; i < length; ++i) {
                ++counts[str[i] - 'a'];
            }
            mp[count].emplace_back(str);
        }

        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

/**
 * 思路二: (巧妙)
 * 1.将 string 排序
 * 2.用 unordered_map<string, int>容器存储索引, int代表vector中的索引
 * 3.map.count(str) 找到,就存入vetcor[index].emplace_back(str); 
 *   反之, unordered_map[str] = index++; 添加新单词
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int sub = 0;
        string tmp;
        unordered_map<string, int> mp;

        for (string str : strs) {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if (mp.count(tmp)) {
                res[mp[tmp]].emplace_back(str);
            } else {
                vector<string> vec(1, str);
                res.emplace_back(vec);
                mp[str] = sub++;
            }
        }
        
        return res;
    }
};