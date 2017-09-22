/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/



// others solution:
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        while ( numbers[i]+numbers[j]!=target ){
            if ( numbers[i]+numbers[j]>target ){
                j -= 1;
            }
            else{
                i += 1;
            }
        }
        return {i+1,j+1};
    }
};

*/

// my solution:
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int idx1 = 0;
        
        if(2 > numbers.size()) return result;
        
        do{
            if(numbers[idx1] == numbers[idx1+1])
            {
                if(target == 2*numbers[idx1])
                {
                    // not zero-based
                    result.push_back(idx1+1);
                    result.push_back(idx1+1+1);
                    
                    return result;
                }
                
                idx1++;
                continue;
            }
            
            for(int idx2 = idx1+1; idx2 < numbers.size(); idx2++)
            {
                if(target < numbers[idx1]+numbers[idx2])
                {
                    continue;
                }
                else if(target == numbers[idx1]+numbers[idx2])
                {
                    // not zero-based
                    result.push_back(idx1+1);
                    result.push_back(idx2+1);
                    
                    return result;
                }
            }
            
        }while(++idx1 < numbers.size());
        
        return result;
    }
};


