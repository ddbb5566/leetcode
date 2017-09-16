/*
Given an index k, return the k^th row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/



// others solution:
/*
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1, 1);

    for (int i = 1; i < rowIndex; ++i)
      for (int j = i; j > 0; --j)
	res[j] = res[j] + res[j - 1];

    return res;
  }
};

*🙂/

// my solution:
/*

呵呵，my submission is:
34 / 34 test cases passed.
Status: Accepted
Runtime: 0 ms
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> element;
        
        // check special case
        element.push_back(1);
        if(0 >= rowIndex) return element;
        
        element.push_back(1);
        if(1 == rowIndex) return element;

        for(int i = 2; i <= rowIndex; i++)
        {
            for(int j = i-1; j > 0; j--)
            {
                element[j] += element[j-1];
            }
            // push back the last no. : 1
            element.push_back(1);
        }
        
        return element;
    }
};


