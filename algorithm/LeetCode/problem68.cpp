#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int num = words.size();
        vector<int>word_lengths(num),line_index;
        line_index.insert(line_index.end(),0);
        for (int i = 0; i < num; ++i)
            word_lengths[i] = words[i].size();
        int index = 0,sum=0;
        while (index < num){
            sum+=word_lengths[index];
            sum+=1;
            if (sum >= maxWidth+1){
                line_index.insert(line_index.end(),index);
                sum = word_lengths[index];
            }
            index++;
        }
        if (line_index[line_index.size()-1]!=num)line_index.insert(line_index.end(),num);
        vector<string>ans;
        for (int i = 1; i < line_index.size()-1; ++i) {
            int cur_cum = accumulate(word_lengths.begin()+line_index[i-1],word_lengths.begin()+line_index[i],0);
            int sub = maxWidth - cur_cum;
            int sub_index = line_index[i] - line_index[i-1];
            string cur_str;
            for (int j = line_index[i-1]; j < line_index[i]-1; ++j) {
                cur_str.append(words[j]);
                cur_str.append(" ");
                sub--;
            }
            while (sub--)
                cur_str.append(" ");
            cur_str.append(words[line_index[i]-1]);
            ans.insert(ans.end(),cur_str);
        }
        string cur_str;
        for (int j = line_index[line_index.size()-2]; j < line_index[line_index.size()-1]; ++j) {
            cur_str.append(words[j]);
            cur_str.append(" ");
        }
        ans.insert(ans.end(),cur_str);
        return ans;
    }
};