
/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

*/

// others:
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int res = 0;
        while(i < nums.size()){
            while(i<nums.size() && nums[i] == val) ++i;
            if(i<nums.size()) nums[res++] = nums[i++];
        }
        
        return res;
    }
};

*/

// my answer:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(val != nums[i])
            {
                nums[cnt++] = nums[i];
            }
        }
        
        return cnt;
    }
};
