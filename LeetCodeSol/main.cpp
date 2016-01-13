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
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *ans;
    int a[4] = {1,3,2,4};
    std::vector<int> v(a, a + 4);
    std::vector<int> test = ans -> productExceptSelf238(v);
    std::cout << test[2];
    return 0;
}
