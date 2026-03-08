#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }

        //Using four nested loops
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    for (int l = k + 1; l < nums.size(); l++) {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> newArray = {nums[i], nums[j], nums[k], nums[l]};
                            //Sorting each quadruplet before storing it : So duplicates look identical when compared
                            sort(newArray.begin(), newArray.end());
                            result.push_back(newArray);
                        }
                    }
                }
            }
        }

        //print for debug.
        cout<<"-----------------"<<endl;
        for (const auto& arr : result) {
            for (const int& element : arr) {
                cout << element << " ";
            }
            cout << "\n";
        }

        //Sorting the result so duplicate quadruplets are adjacent.
        sort(result.begin(), result.end());


        //print for debug.
        cout<<"-----------------"<<endl;
        for (const auto& arr : result) {
            for (const int& element : arr) {
                cout << element << " ";
            }
            cout << "\n";
        }


        // Remove duplicates...
        vector<vector<int>> final_result;
        for (int i = 0; i < result.size(); i++) {
            // Skip if this quadruplet is same as previous one
            if (i == 0 || result[i] != result[i - 1]) {
                final_result.push_back(result[i]);
            }
        }

        //print for debug.
        cout<<"-----------------"<<endl;
        for (const auto& arr : final_result) {
            for (const int& element : arr) {
                cout << element << " ";
            }
            cout << "\n";
        }

        return final_result;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    s1.fourSum(nums, target);
    return 0;
}
