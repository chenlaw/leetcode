#include<string>
#include<vector>
using namespace std;
vector<string> summaryRanges(vector<int> nums) {
    vector<string> v;
    int i = 0, j = 1;
    int l = nums.size();
    for (; j<l; j++) {
        if (nums[j] - nums[j - 1] == 1)
            continue;
        if (j-1 == i)
            v.push_back(to_string(nums[i]));
        else
            v.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
        i = j;

    }
    if (j-1 == i)
        v.push_back(to_string(nums[i]));
    else
        v.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1] ));
    return v;
}
int main() {
    vector<int> nums = { 0,1,2,4,5,7 };
    //vector<string> res = summaryRanges(nums);
    int a = 5;
    int& b = a;
    b = 4;
    auto s=[b](const int& a) {
        return a + b;
        };
    int res=s(4);
}