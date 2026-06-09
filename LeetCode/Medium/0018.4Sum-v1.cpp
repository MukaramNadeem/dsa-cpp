#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        for(int i = 0;i<nums.size(); i++){
            for(int j = i + 1; j<nums.size();j++){
                int left = j + 1;
                int right = nums.size() - 1;
                long long  sum = nums[i]+nums[j]+nums[left]+nums[right];
                if(sum==target){
                    
                }
            }




        }
        return result;
    }
};


int main(){
   Solution s1;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    s1.fourSum(nums, target); 
    return 0;
}