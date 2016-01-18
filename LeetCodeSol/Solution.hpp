//
//  Solution.hpp
//  LeetCodeSol
//
//  Created by xinye lei on 16/1/9.
//  Copyright © 2016年 xinye lei. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <iostream>
#include <vector>
#include <string>

struct TreeNode {       // Binary Tree Node
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

struct ListNode {       // Linked List Node
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {};
};

class Solution {
public:
    
    bool canWinNim292(int n); //1
    
    int singleNumber136(std::vector<int> &nums); //2
    
    int addDigits258(int nums); //3
    
    int maxDepth104(TreeNode *root); //4
    
    void deleteNode237(ListNode *node); //5
    
    void moveZeros283(std::vector<int> &nums); //6
    
    TreeNode* invertTree226(TreeNode *root); //7
    
    bool isSameTree100(TreeNode *p, TreeNode *q); //8
    
    bool isAnagram242(std::string s, std::string t); //9
    
    bool containsDuplicate217(std::vector<int> &nums); //10
    
    int majorityElement169(std::vector<int> &nums); //11
    
    int bulbSwitch319(int n); //12
    
    int missingNumber268(std::vector<int> &nums);//13
    
    int hammingWeight191(uint32_t n); //14
    
    ListNode* reverseList206(ListNode* head); //15
    
    bool hasCycle141(ListNode *head); //16
    
    int maxSubArray53(std::vector<int> &nums); //17
    
    bool isUgly263(int num); //18
    
    bool isHappy202(int n); //19
    
    bool isPowerOfTwo231(int n); //20
    
    int maxProfit122(std::vector<int> &prices); //21
    
    int maxProfit121(std::vector<int> &prices); //22
    
    int titleToNumber171(std::string s); //23
    
    std::string convertToTitle168(int n); //24
    
    int romanToInt13(std::string s); //25
    
    std::string intToRoman12(int num); //26
    
    int searchInsert35(std::vector<int> &nums, int target); //27
    
    ListNode* deleteDuplicates(ListNode* head); //28
    
    double eval(std::string s); //29, 30 (224 and 227)
                                //imporved can process parenthese， +，-，*，/ and double number
    int countNodes222(TreeNode* root); // 31
    
    std::vector<int> productExceptSelf238(std::vector<int> &nums); //32
    
    TreeNode* lowestCommonAncestor235(TreeNode* root, TreeNode* p, TreeNode* q); //33
    
    std::vector<int> preorderTraversal144(TreeNode* root); //34
    
    std::vector<int> inorderTraversal94(TreeNode* root); //35
    
    std::vector<int> postorderTraversal145(TreeNode* root); //36
    
    std::vector<int> twoSum(std::vector<int> &nums, int target); //37
    
    ListNode* oddEvenList328(ListNode* head); //37
    
    void sortColors75(std::vector<int>& nums); //38
    
    ListNode* swapPairs24(ListNode* head); //39
    
    int climbStairs79(int n); //40 (Fibonacci)
    
    int totalNQueens52(int n); //41. Not implemented, refer to 42 where the sol number is also stored
    
    std::vector<std::vector<std::string>> solveNQueens51(int n); //42
};
#endif /* Solution_hpp */
