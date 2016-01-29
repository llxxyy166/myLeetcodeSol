//
//  main.cpp
//  LeetCodeSol
//
//  Created by xinye lei on 16/1/9.
//  Copyright © 2016年 xinye lei. All rights reserved.
//

#include <iostream>
#include <string>
#include "Solution.hpp"
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution ans;
    int a[] = {2, 3, 6, 7};
    vector<int> nums(a, a + 4);
    vector<vector<int>> res = ans.combinationSum39(nums, 7);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
