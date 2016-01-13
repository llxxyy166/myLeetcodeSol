//
//  Solution.cpp
//  LeetCodeSol
//
//  Created by xinye lei on 16/1/9.
//  Copyright © 2016年 xinye lei. All rights reserved.
//

#include "Solution.hpp"
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <cctype>
using namespace std;

bool Solution:: canWinNim292(int n) {
    if(!(n % 4)) {
        return false;
    }
    return true;
}

int Solution:: singleNumber136(vector<int> &nums) {
    int res = 0;
    unsigned long numsSize = nums.size();
    for(int i = 0; i < numsSize; i++){
        res ^= nums[i];
    }
    return res;
}

int Solution:: addDigits258(int num) {
    if (num < 10) {
        return num;
    }
    if(!(num % 9)) {
        return 9;
    }
    return num % 9;
}

int Solution:: maxDepth104(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int l = maxDepth104(root -> left);
    int r = maxDepth104(root ->right);
    return l > r ? l + 1 : r + 1;
}

void Solution:: deleteNode237(ListNode *node) {
    ListNode *temp = node -> next;
    node -> val = temp -> val;
    node -> next = temp -> next;
    delete temp;
}

void Solution:: moveZeros283(std::vector<int> &nums) {
    unsigned long numsSize = nums.size();
    int i = 0;
    int j = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i]) {
            nums[j] = nums[i];
            j++;
        }
    }
    for (i = j; i < numsSize; i++) {
        nums[i] = 0;
    }
}

TreeNode* Solution::invertTree226(TreeNode *root) {
    if (!root) {
        return nullptr;
    }
    TreeNode *temp = root -> left;
    root -> left =  invertTree226(root -> right);
    root -> right = invertTree226(temp);
    return root;
}

bool Solution::isSameTree100(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q) {
        return false;
    }
    return p -> val == q -> val && isSameTree100(p->left, q->left) && isSameTree100(p -> right, q -> right);
}

bool Solution::isAnagram242(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    int countArray[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        countArray[s[i] - 'a']++;
        countArray[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (countArray[i]) {
            return false;
        }
    }
    return true;
}

bool Solution::containsDuplicate217(std::vector<int> &nums) {
    if (!nums.size()) {
        return false;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int Solution::majorityElement169(vector<int> &nums) {
//    long maximumIteration = INT16_MAX;
//    int iteration = 0;
//    do {
//        int index = rand() % nums.size();
//        int candidate = nums[index];
//        int count = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] == candidate) {
//                count++;
//            }
//            if (count > nums.size() / 2) {
//                return candidate;
//            }
//            iteration++;
//        }
//    } while(iteration < maximumIteration);
//    return INT32_MAX;
    sort(nums.begin(), nums.end());
    long majorNumber = nums.size() / 2;
    int count = 0;
    int candidate = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (count > majorNumber) {
            return candidate;
        }
        if (nums[i] != candidate) {
            candidate = nums[i];
            count = 0;
        }
        count++;
    }
    return candidate;
}

int Solution::bulbSwitch319(int n) {
    return sqrt(n);
}

int Solution::missingNumber268(std::vector<int> &nums) {
    int numsSize = (int)nums.size();
    int totalSum = numsSize * (numsSize + 1) / 2;
    int currentSum = 0;
    for (int i = 0; i < numsSize; i++) {
        currentSum += nums[i];
    }
    return totalSum - currentSum;
}

int Solution::hammingWeight191(uint32_t n) {
    int size = 0;
    while (n) {
        if (n & 1) {
            size++;
        }
        n >>= 1;
    }
    return size;
}

ListNode* Solution::reverseList206(ListNode *head) {
    if (!head || !head -> next) {
        return head;
    }
    ListNode *root = reverseList206(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
    return  root;
}

bool Solution::hasCycle141(ListNode *head) {
    if (!head) {
        return false;
    }
    ListNode *fast, *slow;
    fast = head;
    slow = head;
    while (fast -> next && fast -> next -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
        if (fast == slow) {
            return  true;
        }
    }
    return false;
}

int Solution::maxSubArray53(vector<int> &nums) {
    int numsSize = (int)nums.size();
    int M[numsSize];
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (!i) {
            M[i] = nums[i];
            max = M[i];
        }
        else {
            M[i] = M[i - 1] + nums[i] > nums[i] ? M[i - 1] + nums[i] : nums[i];
            if (M[i] > max) {
                max = M[i];
            }
        }
    }
    return max;
}

bool Solution::isUgly263(int num) {
    if (num <= 0) {
        return false;
    }
    if (num == 1) {
        return true;
    }
    while (num > 1) {
        if (!(num % 2)) {
            num = num / 2;
        }
        else if (!(num % 3)) {
            num = num / 3;
        }
        else if (!(num % 5)) {
            num = num / 5;
        }
        else {
            break;
        }
    }
    if (num == 1 || num == 2 || num == 3 || num == 5) {
        return true;
    }
    return false;
}

bool Solution::isHappy202(int n) {
    vector<int> squareSum;
    int sum = 0;
    int num = n;
    while (1) {
        while (num) {
            int digit = num % 10;
            sum += digit * digit;
            num = num / 10;
        }
        if (sum == 1) {
            return true;
        }
        squareSum.push_back(sum);
        sort(squareSum.begin(), squareSum.end());
        for (int i = 0; i < squareSum.size() - 1; i++) {
            if (squareSum[i] == squareSum[i + 1]) {
                return false;
            }
        }
        num = sum;
        sum = 0;
    }
}

bool Solution::isPowerOfTwo231(int n) {
    if (n <= 0) {
        return false;
    }
    while (n >= 2) {
        if (n % 2) {
            return false;
        }
        n = n / 2;
    }
    return true;
}

int Solution::maxProfit122(std::vector<int> &prices) {
    if (!prices.size() || prices.size() == 1) {
        return 0;
    }
    int profit = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
        if (prices[i] < prices[i + 1]) {
            profit -= prices[i];
            profit += prices[i + 1];
        }
    }
    return profit;
}

int Solution::maxProfit121(std::vector<int> &prices) {
    if (!prices.size() || prices.size() == 1) {
        return 0;
    }
    int minimum = prices[0];
    int profit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] > minimum) {
            int localProfit = prices[i] - minimum;
            profit = localProfit > profit ? localProfit : profit;
        }
        if (prices[i] < minimum) {
            minimum = prices[i];
        }
    }
    return profit;
}

int Solution::titleToNumber171(string s) {
    int length = (int)s.length();
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum +=  (s[i] - 'A' + 1) * pow(26, length - 1 - i);
    }
    return sum;
}

std::string Solution::convertToTitle168(int n) {
    string title;
    while (n) {
        int res = n % 26;
        if (!res) {
            res = 26;
        }
        string c;
        c = 'A' + res - 1;
        title = c + title;
        n = (n - res) / 26;
    }
    return title;
}

int Solution::romanToInt13(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I') {
            sum++;
        }
        if (s[i] == 'V') {
            sum += 5;
        }
        if (s[i] == 'X') {
            sum += 10;
        }
        if (s[i] == 'L') {
            sum += 50;
        }
        if (s[i] == 'C') {
            sum += 100;
        }
        if (s[i] == 'D') {
            sum += 500;
        }
        if (s[i] == 'M') {
            sum += 1000;
        }
    }
    if (s.find("IX") != string::npos || s.find("IV") != string::npos ) {
        sum -= 2;
    }
    if (s.find("XL") != string::npos || s.find("XC") != string::npos ) {
        sum -= 20;
    }
    if (s.find("CD") != string::npos || s.find("CM") != string::npos ) {
        sum -= 200;
    }
    return sum;
}

string Solution::intToRoman12(int num) {
    static string list[][9] = {"I" ,"II", "III", "IV", "V", "VI", "VII", "VIII","IX", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M", "MM", "MMM"};
    string result;
    int index = 3;
    for (int i = 1000; i >= 1; i /= 10) {
        if (num / i) {
            int res = num / i;
            result = result + list[index][res - 1];
            num -= res * i;
        }
        index--;
    }
    return result;
}

int Solution::searchInsert35(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return (int)nums.size();
}

ListNode* Solution::deleteDuplicates(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    int currentValue = head -> val;
    int num = 0;
    ListNode *temp = head;
    ListNode *pre = head;
    while (temp) {
        ListNode *next = temp -> next;
        if (temp -> val == currentValue) {
            num++;
            if (num > 1) {
                delete temp;
            }
        }
        else {
            num = 1;
            currentValue = temp -> val;
            pre -> next = temp;
            pre = temp;
        }
        temp = next;
        if (!temp) {
            pre -> next = nullptr;
        }
    }
    return head;
}
//*******************************************************************************************//
int operation1PriorToOperation2(string op1, string op2) {
    int a1 = -1, a2 = -1;
    if (op1 == "(") {
        a1 = 0;
    }
    if (op1 == "*" || op1 == "/") {
        a1 = 2;
    }
    if (op1 == "+" || op1 == "-") {
        a1 = 1;
    }
    if (op2 == "(") {
        a2 = 0;
    }
    if (op2 == "*" || op2 == "/") {
        a2 = 2;
    }
    if (op2 == "+" || op2 == "-") {
        a2 = 1;
    }
    if (a1 == -1 || a2 == -1) {
        return -1; //error
    }
    return a1 >= a2 ? 1 : 0;
}

bool isOperationSymbol(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

double evalSurfix(vector<string> surfix) {
    stack<double> workingStack;
    for (int i = 0; i < surfix.size(); i++) {
        if (surfix[i] == "+" || surfix[i] == "-" || surfix[i] == "*" || surfix[i] == "/") {
            if (workingStack.size() < 2) {
                return INT32_MAX;
            }
            double o1 = workingStack.top();
            workingStack.pop();
            double o2 = workingStack.top();
            workingStack.pop();
            char op = surfix[i][0];
            switch (op) {
                case '+' :
                    workingStack.push(o1 + o2);
                    break;
                case '-' :
                    workingStack.push(o2 - o1);
                    break;
                case '*' :
                    workingStack.push(o1 * o2);
                    break;
                case '/' :
                    workingStack.push(o2 / o1);
                    break;
            }
        }
        else {
            double num = stod(surfix[i]);
            workingStack.push(num);
        }
    }
    return workingStack.top();
}

double Solution::eval(string s) {
    vector<string> suffixExpression;
    stack<string> workingStack;
    if (!s.size()) {
        return 0;
    }
    string number;
    for (int i = 0; i < s.length(); i++) {
        string c(1, s[i]);
        if (isspace(s[i])) {
            continue;
        }
        if (isdigit(s[i]) || s[i] == '.') {
            number = number + s[i];
        }
        else {
            if (number.length()) {
                suffixExpression.push_back(number);
                number = "";
            }
        }
        if (isOperationSymbol(s[i])) {
            while (!workingStack.empty()) {
                string stackTop = workingStack.top();
                if (operation1PriorToOperation2(stackTop, c)) {
                    workingStack.pop();
                    suffixExpression.push_back(stackTop);
                }
                else {
                    break;
                }
            }
            workingStack.push(c);
        }
        if (s[i] == '(') {
            workingStack.push(c);
        }
        if (s[i] == ')') {
            while (!workingStack.empty()) {
                string current = workingStack.top();
                workingStack.pop();
                if (current == "(") {
                    break;
                }
                suffixExpression.push_back(current);
            }
        }
    }
    if (number.length()) {
        suffixExpression.push_back(number);
    }
    while (!workingStack.empty()) {
        suffixExpression.push_back(workingStack.top());
        workingStack.pop();
    }
    string a = "";
    for (int i = 0; i < suffixExpression.size(); i++) {
        a = a + suffixExpression[i];
        cout << suffixExpression[i] << endl;
    }
    return evalSurfix(suffixExpression);
}
//********************************************************************************************//

int Solution::countNodes222(TreeNode *root) {
    int height = 0;
    TreeNode *left, *right;
    for (left = root, right = root ;left && right; height++) {
        left=left->left;
        right=right->right;
    }
    if(!left && !right) return (1 << height) - 1;
    return countNodes222(root->left) + countNodes222(root->right) + 1;
}

vector<int> Solution::productExceptSelf238(vector<int> &nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (!i) {
            result.push_back(1);
        }
        else {
            result.push_back(result[i - 1] * nums[i - 1]);
        }
    }
    int current = 1;
    for (int i = (int)result.size() - 1; i >= 0; i--) {
        result[i] *= current;
        current *= nums[i];
    }
    return result;
}

TreeNode* Solution::lowestCommonAncestor235(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q) {
        return nullptr;
    }
    TreeNode *temp = root;
    while (temp) {
        if (p -> val < temp -> val && q -> val < temp -> val) {
            temp = temp -> left;
        }
        else if (p -> val > temp -> val && q -> val > temp -> val) {
            temp = temp -> right;
        }
        else {
            break;
        }
    }
    return temp;
}

