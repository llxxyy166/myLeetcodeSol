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
#include <sstream>
#include <map>
#include <unordered_set>

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

vector<int> Solution::preorderTraversal144(TreeNode* root) {
    stack<TreeNode *> workingStack;
    vector<int> result;
    if (root) {
        workingStack.push(root);
    }
    while (!workingStack.empty()) {
        TreeNode *top = workingStack.top();
        workingStack.pop();
        result.push_back(top -> val);
        if (top -> right) {
            workingStack.push(top -> right);
        }
        if (top -> left) {
            workingStack.push(top -> left);
        }
    }
    return result;
}

vector<int> Solution::inorderTraversal94(TreeNode *root) {
    stack<TreeNode *> workingStack;
    vector<int> result;
    TreeNode *temp = root;
    while (temp || workingStack.size()) {
        while (temp) {
            workingStack.push(temp);
            temp = temp -> left;
        }
        if (workingStack.size()) {
            temp =workingStack.top();
            workingStack.pop();
            result.push_back(temp -> val);
        }
        temp = temp -> right;
    }
    return result;
}

vector<int> Solution::postorderTraversal145(TreeNode *root) {
    struct TreeNodeWithMark {
        TreeNode *tree;
        int mark;
    };
    stack<TreeNodeWithMark> workingStack;
    vector<int> result;
    TreeNode *temp = root;
    while (temp || workingStack.size()) {
        while (temp) {
            TreeNodeWithMark current;
            current.tree = temp;
            current.mark = 1;
            workingStack.push(current);
            temp = temp -> left;
        }
        if (workingStack.size()) {
            TreeNodeWithMark top = workingStack.top();
            workingStack.pop();
            if (top.mark == 1) {
                top.mark = 2;
                workingStack.push(top);
                temp = top.tree -> right;
            }
            else {
                result.push_back(top.tree -> val);
            }
        }
    }
    return result;
}


vector<int> Solution::twoSum(vector<int> &nums, int target) {
    vector<int> sortedNums = nums;
    vector<int> result;
    sort(sortedNums.begin(), sortedNums.end());
    int begin = 0, end = (int)nums.size() - 1;
    while (begin < end) {
        if (sortedNums[begin] + sortedNums[end] == target) {
            for (int i = 0; i < nums.size(); i++) {
                if (result.size() == 2) {
                    begin = (int)nums.size() - 1;
                    end = 0;
                    break;
                }
                if (nums[i] == sortedNums[begin] || nums[i] == sortedNums[end]) {
                    result.push_back(i + 1);
                }
            }
        }
        else if (sortedNums[begin] + sortedNums[end] > target) {
            end--;
        }
        else {
            begin++;
        }
    }
    return result;
}

ListNode* Solution::oddEvenList328(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode *oddP = head;
    ListNode *evenP = head -> next;
    ListNode *evenH = evenP;
    while (oddP -> next && evenP -> next) {
        oddP -> next = evenP -> next;
        if (oddP -> next) {
            evenP -> next = oddP -> next -> next;
        }
        oddP = oddP -> next;
        evenP = evenP -> next;
    }
    oddP -> next = evenH;
    return  head;
}

void Solution::sortColors75(vector<int> &nums) {
    if (nums.empty()) {
        return;
    }
    int a[3] = {0};
    for (int i = 0; i < nums.size(); i++) {
        a[nums[i]]++;
    }
    for (int i = 0; i < a[0]; i++) {
        nums[i] = 0;
    }
    for (int i = a[0]; i < a[0] + a[1]; i++) {
        nums[i] = 1;
    }
    for (int i = a[0] + a[1]; i < nums.size(); i++) {
        nums[i] = 2;
    }

}

ListNode* Solution::swapPairs24(ListNode *head) {
    if (!head || !head -> next) {
        return head;
    }
    else {
        ListNode *newHead = head -> next;
        ListNode *nextRec = newHead -> next;
        newHead -> next = head;
        head -> next = swapPairs24(nextRec);
        return newHead;
    }
}

int Solution::climbStairs79(int n) {
    if (n == 1 || n == 2) return n;
    int pre1 = 2, pre2 = 1;
    int current = 0;
    for (int i = 3; i <= n; i++) {
        current = pre1 + pre2;
        pre2 = pre1;
        pre1 = current;
    }
    return current;
}

//********************************************************************************************//
struct configuration {
    int num;
    int currentRow;
    vector<int> result;
    int resNum;
    vector<vector<string>> board;
};

vector<string> draw(vector<int> config) {
    vector<string> res;
    for (int i = 0; i < config.size(); i++) {
        string row;
        for (int j = 0; j < config.size(); j++) {
            if (config[i] == j) {
                row += "Q";
            }
            else {
                row += ".";
            }
        }
        res.push_back(row);
    }
    return res;
}

void track(configuration &config) {
    int row = config.currentRow;
    if (config.currentRow == config.num) {
        config.resNum++;
        vector<string> res = draw(config.result);
        config.board.push_back(res);
        return;
    }
    for (int i = 0; i < config.num; i++) {
        config.result[row] = i;
        int flag = 0;
        for (int j = 0; j < row; j++) {
            if (config.result[j] == config.result[row] || config.result[j] - config.result[row] == j - row || config.result[j] - config.result[row] == row - j) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            config.currentRow++;
            track(config);
            config.currentRow--;
        }
    }
}

vector<vector<string>> Solution::solveNQueens51(int n) {
    configuration config;
    config.num = n;
    config.currentRow = 0;
    config.resNum = 0;
    for (int i = 0; i < n; i++) {
        config.result.push_back(0);
    }
    track(config);
    return config.board;
}
//********************************************************************************************//

void Solution::MedianFinder::addNum(int num) {
    if (small.empty() || num < small.top()) {
        small.push(num);
    }
    else {
        large.push(num);
    }
    if ((int)small.size() - (int)large.size() > 1) {
        int n = small.top();
        small.pop();
        large.push(n);
    }
    if ((int)large.size() - (int)small.size() > 1) {
        int n = large.top();
        large.pop();
        small.push(n);
    }
}

double Solution::MedianFinder::findMedian() {
    int size = (int)small.size() + (int)large.size();
    if (size % 2 != 0) {
        return small.size() > large.size() ? small.top() : large.top();
    }
    return (double)(small.top() + large.top()) / 2;
}

string Solution::getHint299(string secret, string guess) {
    int bull = 0, cow = 0;
    map<char, int> maps;
    for (int i = 0; i < secret.size(); i++) {
        if (maps.find(secret[i]) == maps.end()) {
            maps.insert(pair<char, int> (secret[i], 1));
        }
        else {
            maps[secret[i]]++;
        }
    }
    for (int i = 0; i < secret.length(); i++) {
        if (secret[i] == guess[i]) {
            bull++;
            maps[secret[i]]--;
        }
    }
    for (int i = 0; i < guess.length(); i++) {
        if (maps.find(guess[i]) != maps.end()) {
            if (maps[guess[i]] && guess[i] != secret[i]) {
                cow++;
                maps[guess[i]]--;
            }
        }
    }
    stringstream rest;
    rest << bull << "A" << cow << "B";
    return rest.str();
}

void DFS(TreeNode *node, string &path, vector<string> &res) {
    stringstream val;
    val << node -> val << "->";
    path += val.str();
    if (!node -> left && !node -> right) {
        path.erase(path.end() - 2, path.end());
        res.push_back(path);
        if (path.length() > 3) {
            while (path[path.length() - 1] != '>') {
                path.erase(path.end() - 1);
            }
        }
        return;
    }
    if (node -> left) {
        DFS(node -> left, path, res);
    }
    if (node -> right) {
        DFS(node -> right, path, res);
    }
    path.erase(path.end() - 2, path.end());
    if (path.length() > 3) {
        while (path[path.length() - 1] != '>') {
            path.erase(path.end() - 1);
        }
    }
    return;
}

vector<string> Solution::binaryTreePaths257(TreeNode *root) {
    vector<string> res;
    if (!root) {
        return res;
    }
    string path;
    DFS(root, path, res);
    return res;
}

void TrackPermute(vector<int> &nums, map<int, int> &count, vector<int> &permute, vector<vector<int>> &res) {
    if (permute.size() == nums.size()) {
        res.push_back(permute);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (count[nums[i]]) {
            count[nums[i]]--;
            permute.push_back(nums[i]);
            TrackPermute(nums, count, permute, res);
            permute.pop_back();
            count[nums[i]]++;
        }
    }
}

vector<vector<int>> Solution::permute46(vector<int> &nums) {
    vector<vector<int>> res;
    map<int, int> count;
    for (int i = 0; i < nums.size(); i++) {
        count.insert(pair<int, int> (nums[i], 1));
    }
    vector<int> permute;
    TrackPermute(nums, count, permute, res);
    return res;
}

int Solution::trailingZeroes172(int n) {
    int res = 0;
    while (n / 5) {
        n /= 5;
        res += n;
    }
    return res;
}

ListNode* Solution::insertionSortList147(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode *newHead = head;
    ListNode *temp = head -> next;
    newHead->next = nullptr;
    while (temp) {
        ListNode *op = temp;
        temp = temp -> next;
        ListNode *newListTemp = newHead;
        while (newListTemp) {
            if (newListTemp -> val <= op -> val && (newListTemp -> next == nullptr || newListTemp -> next ->val > op -> val)) {
                op -> next = newListTemp -> next;
                newListTemp -> next = op;
                break;
            }
            else if (newListTemp -> val > op -> val) {
                op -> next = newListTemp;
                newHead = op;
                break;
            }
            else {
                newListTemp = newListTemp -> next;
            }
        }
    }
    return newHead;
}

vector<vector<int>> Solution::generateMatrix59(int n) {
    int matrix[n][n];
    int mark[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mark[i][j] = 0;
        }
    }
    int row = 0, column = 0;
    string flag = "right";
    for (int i = 1; i <= n * n; i++) {
        matrix[row][column] = i;
        mark[row][column] = 1;
        if (flag == "right") {
            column++;
        }
        if (flag == "left") {
            column--;
        }
        if (flag == "up") {
            row--;
        }
        if (flag == "down") {
            row++;
        }
        if (flag == "right" && (column == n - 1 || mark[row][column + 1])) {
            flag = "down";
        }
        if (flag == "down" && (row == n - 1|| mark[row + 1][column])) {
            flag = "left";
        }
        if (flag == "left" && (column == 0 || mark[row][column - 1])) {
            flag = "up";
        }
        if (flag == "up" && (row == 0 || mark[row - 1][column])) {
            flag = "right";
        }
    }
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        vector<int> row(matrix[i], matrix[i] + n);
        res.push_back(row);
    }
    return res;
}

void Solution::MinStack::push(int x) {
    int min = workingStack.empty() ? x : std::min(workingStack.top().second, x);
    workingStack.push(std::make_pair(x, min));
}

void Solution::MinStack::pop() {
    workingStack.pop();
}

int Solution::MinStack::top() {
    return workingStack.top().first;
}

int Solution::MinStack::getMin() {
    return workingStack.top().second;
}

ListNode* Solution::getIntersectionNode160(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
//    unordered_set<ListNode *> set;
//    for (ListNode *temp = headA; temp; temp = temp -> next) {
//        set.insert(temp);
//    }
//    for (ListNode *temp = headB; temp; temp = temp -> next) {
//        if (set.find(temp) != set.end()) {
//            return temp;
//        }
//    }
//    return nullptr;
    ListNode *A = headA, *B = headB;
    while (A && B) {
        if (A == B) {
            return A;
        }
        A = A -> next;
        B= B -> next;
        if (A == B) {
            return A;
        }
        if (!A) {
            A = headB;
        }
        if (!B) {
            B = headA;
        }
    }
    return A;
}

struct configurationForFindingWord {
    bool find;
    int maxRow;
    int maxColumn;
    int currentBoardRow;
    int currentBoardColumn;
    int currentStringIndex;
    int maxStringIndex;
    vector<vector<int>> mark;
};

void findWord(vector<vector<char>> &board, string word, configurationForFindingWord &config) {
    if (config.currentStringIndex == config.maxStringIndex) {
        config.find = true;
    }
    if (config.find) {
        return;
    }
    if (config.currentBoardRow > config.maxRow - 1 || config.currentBoardRow < 0) {
        return;
    }
    if (config.currentBoardColumn > config.maxColumn - 1 || config.currentBoardColumn < 0) {
        return;
    }
    int row = config.currentBoardRow;
    int column = config.currentBoardColumn;
    if (board[row][column] == word[config.currentStringIndex] && !config.mark[row][column]) {
        config.mark[row][column] = 1;
        config.currentStringIndex++;
        
        config.currentBoardRow++;
        findWord(board, word, config);
        config.currentBoardRow--;
        
        config.currentBoardRow--;
        findWord(board, word, config);
        config.currentBoardRow++;
        
        config.currentBoardColumn++;
        findWord(board, word, config);
        config.currentBoardColumn--;
        
        config.currentBoardColumn--;
        findWord(board, word, config);
        config.currentBoardColumn++;
        
        config.mark[row][column] = 0;
        config.currentStringIndex--;
    }
    return;
}

bool Solution::exist79(vector<vector<char>> &board, string word) {
    configurationForFindingWord config;
    config.find = false;
    config.maxRow = (int)board.size();
    config.maxColumn = (int)board[0].size();
    config.currentStringIndex = 0;
    config.maxStringIndex = (int)word.size();
    for (int i = 0; i < config.maxRow; i++) {
        vector<int> a;
        for (int j = 0; j < config.maxColumn; j++) {
            a.push_back(0);
        }
        config.mark.push_back(a);
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            config.currentBoardRow = i;
            config.currentBoardColumn = j;
            findWord(board, word, config);
        }
    }
    return config.find;
}

void Solution::Trie::insert(string word) {
    TrieNode *temp = root;
    for (int i = 0; i < word.length(); i++) {
        if (!temp -> children.count(word[i])) {
            TrieNode *newNode = new TrieNode;
            newNode -> isWord = false;
            temp -> children[word[i]] = newNode;
        }
        temp = temp -> children[word[i]];
    }
    temp -> isWord = true;
}
bool Solution::Trie::search(string word) {
    TrieNode *temp = root;
    int i = 0;
    while (temp && i < word.length()) {
        if (!temp -> children.count(word[i])) {
            return false;
        }
        temp = temp -> children[word[i]];
        i++;
    }
    if (!temp -> isWord) {
        return false;
    }
    return true;
}
bool Solution::Trie::startsWith(string prefix) {
    TrieNode *temp = root;
    int i = 0;
    while (temp && i < prefix.length()) {
        if (!temp -> children.count(prefix[i])) {
            return false;
        }
        temp = temp -> children[prefix[i]];
        i++;
    }
    return true;
}

vector<int> Solution::plusOne66(vector<int> &digits) {
    int index = (int)digits.size() - 1;
    while (index >= 0) {
        if (digits[index] == 9) {
            digits[index] = 0;
            index--;
        }
        else {
            digits[index]++;
            break;
        }
    }
    if (index == -1) {
        digits.emplace(digits.begin(), 1);
    }
    return digits;
}

int Solution::minimumTotal120(vector<vector<int>> &triangle) {
    vector<int> M;
    M.push_back(triangle[0][0]);
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = (int)triangle[i].size() - 1; j >= 0; j--) {
            if (j == 0) {
                M[0] = M[0] + triangle[i][j];
            }
            else if (j == triangle[i].size()) {
                M.push_back(M[M.size() - 1] + triangle[i][j]);
            }
            else {
                int min = std::min(M[j], M[j - 1]);
                M[j] = min + triangle[i][j];
            }
        }
    }
    return *min_element(M.begin(), M.end());
}

vector<int> Solution::getRow119(int rowIndex) {
    vector<int> res;
    res.push_back(1);
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            if (!j) {
                res[j] = 1;
            }
            else {
                res[j] = res[j] + res[j - 1];
            }
        }
        res.push_back(1);
    }
    return res;
}

vector<vector<int>> Solution::generate118(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i <numRows; i++) {
        vector<int> row;
        if (!i) {
            row.push_back(1);
        }
        else{
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.push_back(1);
                }
                else {
                    row.push_back(res[i - 1][j] + res[i - 1][j - 1]);
                }
            }
        }
        res.push_back(row);
    }
    return res;
}

bool Solution::isPalindrome125(string s) {
    if (s.empty()) {
        return true;
    }
    int i = 0, j = (int)s.length() - 1;
    while (i < j) {
        while (!isalnum(s[i]) && i < j) {
            i++;
        }
        while (!isalnum(s[j]) && i < j) {
            j--;
        }
        char a = toupper(s[i]);
        char b = toupper(s[j]);
        if (a != b) {
            return false;
        }
        i++, j--;
    }
    return true;
}


int Solution::coinChange(vector<int> &coins, int amount) {
    vector<int> a(amount + 1, INT32_MAX);
    sort(coins.begin(), coins.end());
    a[0] = 0;
    for (int i = 1; i <= amount; i++) {
        int minimum = INT32_MAX;
        for (int j = 0; j < coins.size(); j++) {
            if (i < coins[j]) {
                continue;
            }
            if (coins[j] == i) {
                a[i] = 1;
                minimum = a[i];
                break;
            }
            if (a[i - coins[j]] != -1) {
                minimum = a[i - coins[j]] + 1 < minimum ? a[i - coins[j]] + 1 : minimum;
            }
        }
        a[i] = minimum == INT32_MAX ? -1 : minimum;
    }
    return a[amount] == INT32_MAX ? -1 : a[amount];
}

int Solution::compareVersion165(string version1, string version2) {
    vector<int> split1;
    vector<int> split2;
    size_t pos = 0;
    while (pos != string::npos) {
        pos = version1.find('.');
        string head = version1.substr(0, pos);
        string tail = version1.substr(pos + 1);
        split1.push_back(stoi(head));
        version1 = tail;
    }
    pos = 0;
    while (pos != string::npos) {
        pos = version2.find('.');
        string head = version2.substr(0, pos);
        string tail = version2.substr(pos + 1);
        split2.push_back(stoi(head));
        version2 = tail;
    }
    int i = 0;
    while (i < split1.size() || i < split2.size()) {
        if (i < split1.size() && i < split2.size()) {
            if (split1[i] > split2[i]) {
                return 1;
            }
            if (split1[i] < split2[i]) {
                return -1;
            }
            i++;
            continue;
        }
        if (i < split1.size()) {
            int j = i;
            while (j < split1.size()) {
                if (split1[j]) {
                    return 1;
                }
            }
            return 0;
        }
        if (i < split2.size()) {
            int j = i;
            while (j < split2.size()) {
                if (split2[j]) {
                    return -1;
                }
            }
        }
        return 0;
    }
    return 0;
}

bool Solution::isPowerOfThree326(int n) {
    double power = log(n) / log(3);
    cout << (double)(int)(power+0.1);
    if (fabs(power - (int)(power+0.6)) < 1e-10) {
        return true;
    }
    return false;
}

bool isBadVersion(int version) {
    if (version > 1702766179) {
        return true;
    }
    return false;
}
int Solution::firstBadVersion278(int n) {
    int left = 1, right = n;
    int mid = (double)left / 2 + (double)right / 2;
    while (mid != left && mid != right) {
        if (isBadVersion(mid)) {
            right = mid;
            mid = (double)mid / 2 + (double)left / 2;
        }
        else {
            left = mid;
            mid = (double)mid / 2 + (double)right / 2;
        }
            
    }
    return isBadVersion(mid) ? mid : mid + 1;
}

ListNode* Solution::addTwoNumbers2(ListNode *l1, ListNode *l2) {
    ListNode *t1 = l1, *t2 = l2;
    int carry = 0;
    int headflag = 1;
    ListNode *newHead = nullptr;
    ListNode *current = nullptr;
    while (t1 || t2) {
        int a = 0, b = 0;
        if (t1) {
            a = t1 -> val;
            t1 = t1 -> next;
        }
        if (t2) {
            b = t2 -> val;
            t2 = t2 -> next;
        }
        int sum = a + b + carry;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        ListNode *newNode = new ListNode(sum);
        if (headflag) {
            newHead = newNode;
            headflag = 0;
        }
        else {
            current -> next = newNode;
        }
        current = newNode;
    }
    if (carry) {
        ListNode *newNode = new ListNode(1);
        current -> next = newNode;
        current = current -> next;
    }
    current -> next = nullptr;
    return newHead;
}

int Solution::search33(vector<int> &nums, int target) {
    int left = 0, right = (int)nums.size() - 1;
    int pivot = (double)left / 2 + (double)right / 2;
    while (pivot != left && pivot != right) {
        if (nums[pivot] > nums[right]) {
            left = pivot;
            pivot = (double)left / 2 + (double)right / 2;
        }
        else {
            right = pivot;
            pivot = (double)left / 2 + (double)right / 2;
        }
    }
    left = 0, right = pivot;
    int mid = double(left) / 2 + (double)right / 2;
    while (mid != left && mid != right) {
        if (nums[mid] > target) {
            right = mid;
            mid = (double)right / 2 + (double)left / 2;
        }
        else if (nums[mid] < target) {
            left = mid;
            mid = (double)left / 2 + (double)right / 2;
        }
        else {
            return mid;
        }
    }
    if (nums[mid] == target) {
        return mid;
    }
    if (nums[mid + 1] == target && mid + 1 < nums.size()) {
        return mid + 1;
    }
    left = pivot + 1, right = (int)nums.size() - 1;
    mid = double(left) / 2 + (double)right / 2;
    while (mid != left && mid != right) {
        if (nums[mid] > target) {
            right = mid;
            mid = (double)right / 2 + (double)left / 2;
        }
        else if (nums[mid] < target) {
            left = mid;
            mid = (double)left / 2 + (double)right / 2;
        }
        else {
            return mid;
        }
    }
    if (nums[mid] == target) {
        return mid;
    }
    if (nums[mid + 1] == target && mid + 1 < nums.size()) {
        return mid + 1;
    }
    return -1;
}

void Solution::rotate189(vector<int> &nums, int k) {
    int num = k % nums.size();
    reverse(nums.begin(), nums.begin() + nums.size() - num);
    reverse(nums.begin() + nums.size() - num, nums.end());
    reverse(nums.begin(), nums.end());
}

struct configuration39 {
    int target;
    int currentIndex;
    int currentSum;
    vector<int> currentSol;
    vector<vector<int>> res;
};

void search39(vector<int> &candidate, configuration39 &config) {
    if (config.currentSum == config.target) {
        config.res.push_back(config.currentSol);
        return;
    }
    if (config.currentSum == config.target) {
        config.res.push_back(config.currentSol);
    }
    for (int i = 0; i < candidate.size(); i++) {
        if (config.currentSol.size() && candidate[i] < config.currentSol[config.currentSol.size() - 1]) {
            continue;
        }
        if (config.currentSum + candidate[i] > config.target) {
            continue;
        }
        config.currentSum += candidate[i];
        config.currentSol.push_back(candidate[i]);
        search39(candidate, config);
        config.currentSum -= candidate[i];
        config.currentSol.pop_back();
    }
    return;
}

vector<vector<int>> Solution::combinationSum39(vector<int> &candidates, int target) {
    configuration39 config;
    config.target = target;
    config.currentSum = 0;
    config.currentIndex = 0;
    search39(candidates, config);
    return config.res;
}

