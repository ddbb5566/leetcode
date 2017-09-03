/*
26. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/


//others:
/*

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<2) return nums.size();
        int index=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]) 
            {
                nums[index]=nums[i];
                index++;
            }           
        }
        return index;
    }
};
*/

//my solution:

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //int j = 1;
        
        //check special case
        if(0 == nums.size()) return 0;
        if(1 == nums.size()) return 1;
        
        vector<int>::iterator it = nums.begin();
        //for(i = 0, j = 1; i < nums.size() -1; i++)
        while((it+1) != nums.end())
        {
            if(*it != *(it+1))
            {
                //j++;
                it++;
            }
            else{
                nums.erase(it+1);
            }
        }
        return nums.size();
    }
};

