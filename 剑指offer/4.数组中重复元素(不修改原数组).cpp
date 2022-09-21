#include <iostream>
#include <vector>

using namespace std;

int countRange(const vector<int> &nums, int left, int right) {
    int counter = 0;
    for (const auto &num : nums) {
        if (num >= left && num <= right) {
            counter ++;
        }
    }

    return counter;
}

bool findDuplicate(vector<int> nums, int *duplicate) {
    int size = nums.size();

    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        int counter = countRange(nums, left, mid);

        if (left == right) {
            if (counter > 1) {
                *duplicate = left;
                return true;
            }
            else {
                break;
            }
        }

        if (counter > mid - left + 1) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return false;
}