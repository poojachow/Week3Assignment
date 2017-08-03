//
//  LeastCommonAncestor.cpp
//  Week3Assignment
//
//  Created by Pooja Chowdhary on 8/2/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool getPath(TreeNode *A, int value, vector<int>&path) {
    if(A==nullptr) {
        return false;
    }
    path.push_back(A->val);
    if(A->val == value) {
        return true;
    }
    
    if((A->left && getPath(A->left, value, path)) || (A->right && getPath(A->right, value, path))) {
        return true;
    }
    path.pop_back();
    return false;
}

int lca(TreeNode* A, int val1, int val2) {
    if(A==nullptr){
        return -1;
    }
    
    vector<int> path1, path2;
    if(!getPath(A,val1,path1) || !getPath(A,val2,path2)) {
        return -1;
    }
    int minSize = path1.size() > path2.size() ? path2.size() : path1.size();
    int i;
    for (i = 0; i < minSize; i++) {
        if(path1[i] != path2[i]) {
            break;
        }
    }
    return path1[i-1];
}
