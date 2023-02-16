//
// Created by Nguyen Tien on 12-Feb-23.
//
#include <iostream>
using namespace std;
int binarySearch(int a[],int n, int gtri){
    int left = 0;
    int right = n-1; //4 1
    // 2
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == gtri) return mid;
        if(a[mid] > gtri){
            right = mid - 1;
        }else left = mid +1;
    }
    return -1;
}
//int main(){
//    int a[] = {1,2,3,5,7,8};
//    int n = sizeof(a) / sizeof(a[0]);
//    cout << binarySearch(a, n, 1);
//}