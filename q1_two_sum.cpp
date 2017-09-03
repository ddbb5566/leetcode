/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/
#include <iostream>
#include<math.h> 
#include<vector> 
#include <algorithm>
using namespace std;

/*
// others solution:
class Solution {
public:
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}
};

*/


//my solution:
class Solution {
public:
    Solution():firstIdx(0),secondIdx(0){
	tgtIdx.clear();}
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator it = nums.begin();
        while(it != nums.end())
        {
            firstIdx ++;
            if (find(it+1, nums.end(), target - *it) != nums.end() )
            {
                secondIdx = firstIdx;
                vector<int>::iterator it_second = it+1;
                while(it_second != nums.end())
                {
                    secondIdx++;
                    if(*it_second + *it == target)
                    {
                        break;
                    }
                    it_second++;
                }
                
                return fill_result();
            }
            it++;
        }

    }
    int firstIdx;
    int secondIdx;

    vector<int> tgtIdx;    

    vector<int> fill_result(){
        //vector<int> tgtIdx;
        tgtIdx.push_back(firstIdx-1);
        tgtIdx.push_back(secondIdx-1);
        return tgtIdx;
    }
};

#define MAX_NUM_LEN 4
int main(){
	int num[MAX_NUM_LEN] = {0};
	vector<int> srcNum;
	int tgtNum = 0;
	Solution sl;
		
	for(int i=0; i<MAX_NUM_LEN; i++)
	{
		cout << "please input the " << i+1 << "/" << MAX_NUM_LEN <<"st"<< " num:";
		cin >> num[i];
		srcNum.push_back(num[i]);	
	}
	
	cout << "please input the target num:";
	cin >> tgtNum;


	sl.twoSum(srcNum, tgtNum);

	for(int i = 0; i < sl.tgtIdx.size(); i++){
		cout << sl.tgtIdx[i] << " ";
	}
	
	cout << endl;
}

