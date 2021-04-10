#include<iomanip>
#include<string>
#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<iomanip>
using namespace std;
int search(vector<int>& nums, int target) {
    int s = nums.size();
    if (s == 0)return -1;
    if (s == 1)return target == nums[0] ? 0 : -1;
    int l = 0;
    int r = s - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target)return mid;
        if (nums[l] < nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        else {
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }
    return -1;
}
int main() {
    vector<int> v = { 3,1 };
    search(v, 1);
}