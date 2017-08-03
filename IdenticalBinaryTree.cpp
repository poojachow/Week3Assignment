//
//  IdenticalBinaryTree.cpp
//  Week3Assignment
//
//  Created by Pooja Chowdhary on 8/2/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int isSameTree(TreeNode* A, TreeNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int boolVal;
    if(A==nullptr && B==nullptr) {
        return 1;
    }
    if(A==nullptr || B==nullptr) {
        return 0;
    }
    boolVal=isSameTree(A->left, B->left);
    if(boolVal==0) {
        return 0;
    }
    if(A->val != B->val) {
        return 0;
    }
    boolVal=isSameTree(A->right, B->right);
    return boolVal;
}
