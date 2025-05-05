class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int, vector<int>> n;
           for(int i=0; i<nums.size(); i++){
            n[nums[i]].push_back(i);
           }
           int another_n;
           vector<int> tn;
           for(const auto& en:n){
            if(en.second.size() == 2) {
                if(en.first * 2 == target) {
                    tn.push_back(en.second[0]);
                    tn.push_back(en.second[1]);
                    break;
                }
                else continue;
            }else{
                another_n = target - en.first;
                if(n.count(another_n) == 0) continue;
                else if(en.first == another_n && en.second.size() != 2) continue;
                else{
                    tn.push_back(en.second[0]);
                    tn.push_back(n[another_n][0]);
                    break;
                }
            }
           }
           return tn;
        }
    };