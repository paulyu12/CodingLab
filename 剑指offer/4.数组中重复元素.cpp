#include <iostream>
#include <vector>

using namespace std;

bool findDuplicate(vector<int> nums, int *duplicate) {
    int size = nums.size();

    for (int i = 0; i < size; i ++) {
        while (i != nums[i]) {

            int index = nums[i];
            if (index == nums[index]) {
                *duplicate = index;
                return true;
            }
            else {
                swap(nums[i], nums[index]);
            }
        }
    }

    return false;
}