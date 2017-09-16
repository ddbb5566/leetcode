/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/



// others solution:
/*
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
};

*/

// my solution:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> element;
        
        // check special case
        if(0 == numRows) return result;
 
        element.push_back(1);
        result.push_back(element);
        if(1 == numRows) return result;
        
        element.push_back(1);
        result.push_back(element);
        if(2 == numRows) return result;
        
        for(int i = 2; i < numRows; i++)
        {
            for(int j = 0; j < i-1; j++)
            {
                element[j] += element[j+1];
            }
            // insert the first no. : 1
            element.insert(element.begin(),1);// 难道是这里浪费了时间？
            result.push_back(element);
        }
        
        return result;
    }
};


