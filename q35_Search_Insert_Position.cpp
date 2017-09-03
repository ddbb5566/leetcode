/*
35 search Insert Position   
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/



// others solution:
/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index=0;
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
            else if(nums[i]>target){
                return i;
            }
            else if(i==nums.size()-1 && nums[nums.size()-1]<target){
                return nums.size();
            }
        }
    }
};

*/

// my solution:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int highIdx = nums.size()-1;
        int lowIdx = 0;
        int midIdx;

        // check input para
        if(0 == nums.size()) return 0;
        
        if(target <= nums[0]) return 0;
        else if(target > nums[highIdx]) return (highIdx+1);

        while(1)
        {
            midIdx = (highIdx + lowIdx)/2;
            
            if(target < nums[midIdx]){
                if(midIdx == lowIdx+1){
                    return midIdx;
                }
                // update high index
                highIdx = midIdx;
            }
            else if(target > nums[midIdx]){
                if(midIdx == highIdx-1){
                    return highIdx;
                }
                // update index
                lowIdx = midIdx;
            }
            else{ 
                return midIdx;
            }
        
        }
    }
};


