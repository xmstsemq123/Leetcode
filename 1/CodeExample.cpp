class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map<int, int> sum_dict;
            std::vector<int> ret;
            for(int i = 0; i < nums.size(); i++){
                if(sum_dict.count(target - nums[i])){
                    ret = {sum_dict[target - nums[i]], i};
                    return ret;
                }
                sum_dict[nums[i]] = i;
            }
            return ret;
        }
    };