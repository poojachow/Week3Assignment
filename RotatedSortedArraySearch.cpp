//
//  RotatedSortedArraySearch.cpp
//  Week3Assignment
//
//  Created by Pooja Chowdhary on 8/2/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int> &A, int B) {
    if(A.size() == 0) {
        return -1;
    }
    int low = 0, pivot = -1;
    int high = A.size()-1;
    long mid;
    bool linearSearch = false;
    while(low <= high) {
        mid = (low + high) / 2;
        if(A[mid] == B) {
            return mid;
        }
        if(A[mid] > A[high]) {
            //pivot mid-hig
            low = mid+1;
            if(A[mid] > A[low]) {
                pivot = low;
                break;
            }
            
        }
        else if (A[mid] < A[high]) {
            //pivot low-mid
            high = mid-1;
            if(A[high] > A[mid]) {
                pivot = mid;
                break;
            }
            
        }
        else {
            linearSearch = true;
            break;
        }
    }
    
    if (linearSearch == true) {
        for(int i = 0; i < A.size(); i++) {
            if (A[i] == B) {
                return i;
            }
        }
    }
    else {
        if (pivot > -1) {
            if(A[A.size()-1] > B) {
                low = pivot;
                high = A.size()-1;
            }
            else {
                low = 0;
                high = pivot-1;
            }
            
            while(low<=high) {
                mid = (low+high) / 2;
                if(A[mid] == B) {
                    return mid;
                }
                else if (A[mid] > B) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
        }
    }
    return -1;
}
