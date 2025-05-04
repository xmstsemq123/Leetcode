#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    unordered_map<string, int> T;
    int big, small;
    string key;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(auto& pair:dominoes) {
            big = pair.at(0);
            if(pair.at(1) > big){
                big = pair.at(1);
                small = pair.at(0);
            } else small = pair.at(1);
            key = to_string(big) + "," + to_string(small);

            if(T.count(key) == 0) T[key] = 1;
            else T[key] += 1;
        }
        int num=0;
        for(auto& ee:T){
            if(ee.second >= 2) {
                num += ee.second * (ee.second-1) / 2;
            }
        }
        return num;
    }
};