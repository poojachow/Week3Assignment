//
//  main.cpp
//  Week3Assignment
//
//  Created by Pooja Chowdhary on 7/29/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    if(A.size() == 0) {
        return 0;
    }
    int low = 0;
    int high = A.size()-1;
    long mid;
    
    while(low<=high) {
        mid = (low+high)/2;
        if(A[mid][0] == B) {
            return 1;
        }
        if(low==high){
            break;
        }
        if(A[mid][0] > B) {
            if(mid > 0) {
                high = mid-1;
            }
            else {
                return 0;
            }
        }
        else {
            if(mid < A.size()-1) {
                low = mid+1;
                if(A[low][0] > B) {
                    break;
                }
            }
            else {
                break;
            }
        }
    }
    long mid2;
    vector<int> temp = A[mid];
    low = 0;
    high = temp.size()-1;
    while(low<=high) {
        mid2 = (low+high)/2;
        if(temp[mid2] == B) {
            return 1;
        }
        if(temp[mid2] > B) {
            high = mid2-1;
        }
        else {
            low = mid2+1;
        }
    }
    return 0;
}
