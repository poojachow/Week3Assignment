//
//  FlattenBinaryTree.cpp
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

TreeNode* flatten(TreeNode* A) {
if(A==nullptr) {
        return nullptr;
    }
    flatten(A->left);
    TreeNode *temp;
    if(A->left != nullptr) {
        temp = A->left;
        while(temp->right != nullptr) {
            temp = temp->right;
        }
        temp->right = A->right;
        A->right = A->left;
        A->left = nullptr;
    }
    flatten(A->right);
    
    return A;
}
