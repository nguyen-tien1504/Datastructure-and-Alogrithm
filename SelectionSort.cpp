//
// Created by Nguyen Tien on 12-Feb-23.
//
#include <iostream>

using namespace std;
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
void SelectionSort(int a[], int n){
    // Big-O = O(n^2)
    for (int j = 0; j < n - 1; ++j) {
        int minPos;
        for (int i = j + 1; i < n; ++i) {
            if(a[i] < a[j]) {
                minPos = i;
                swap(a[i], a[j]);
            }
        }
    }
}
void Insertionsort(int a[], int n){
    // Big-O = O(n^2)
    for (int i = 1; i < n; ++i) {
        int temp = a[i];
        int pos = i - 1;
        while(pos >= 0 && a[pos] > temp){
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = temp;
    }
}
void BubleSort(int a[], int n){
    // Big-O = O(n^2)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; j--) {
            if(a[j] < a[j-1]) swap(a[j], a[j-1]);
        }
    }
}
void QuickSort(int a[], int left, int right){
    // Big-O = O(n^2)
    int pivot = a[(left + right) / 2];
    int l = left, r = right;
    do {
        while(a[l] < pivot) l++;
        while(a[r] > pivot) r--;
        if(l <= r) {
            swap(a[l], a[r]) ;
            l++;
            r--;
        };
    }while(l <= r);
    if(left < r){
        QuickSort(a, left, r);
    }
    if(l < right){
        QuickSort(a, l, right);
    }
}
int *merge(int *a, int n1, int *b, int n2){
    int *c = new int[n1 + n2];
    int i = 0, j = 0, dem = 0;
    while(i < n1 && j <n2){
        if(a[i] < b[j]){
            c[dem++] = a[i++];
        }else{
            c[dem++] = b[j++];
        }
    }
    //Chay tiep tu doan a
    for (int k = i; k < n1; ++k) {
        c[dem++] = a[k];
    }
    //Chay tiep tu doan b
    for (int k = j; k < n2; ++k) {
        c[dem++] = b[k];
    }
    return c;
}
int* MergeSort(int a[], int n){
    // Big-O = O(nlogn)
    if(n == 1) return a;
    int mid = n / 2;
    int *m1 = new int[mid];
    int *m2 = new int[n - mid];
    for (int i = 0; i < mid; ++i) {
        m1[i] = a[i];
    }
    for (int i = 0; i < n - mid; ++i) {
        m2[i] = a[mid + i];
    }
    m1 = MergeSort(m1, mid);
    m2 = MergeSort(m2, n - mid);
    return merge(m1, mid, m2, n - mid);
}
int main(){
    int a[] = {2,1,4,5,6,4, 1000,3,-8,2,7,5,4,5,9, 100};
    int n = sizeof(a) / sizeof(a[0]);
//    SelectionSort(a, n);
//    Insertionsort(a, n);
//    BubleSort(a, n);
//    QuickSort(a,0, n-1);
    int *b = MergeSort(a, n);
//    int a1[] = {1,2,3,4,5};
//    int a2[] = {7,8,9,10};
//    int *a3 = merge(a1,5,a2,4);
//    for (int i = 0; i < 9; ++i) {
//        cout << a3[i] << "\t";
//    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << "\t";
    }
    return 0;
}