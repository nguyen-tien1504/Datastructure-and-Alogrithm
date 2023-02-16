//
// Created by Nguyen Tien on 12-Feb-23.
//
#include <iostream>
#define MAX 100
using namespace std;
struct Stack{
    int a[MAX];
    int top;
};
void init(Stack &s){
    s.top = -1;
}
void push(Stack &s, int x){
    s.a[++s.top] = x;
}
int pop(Stack &s){
//    int top = s.a[s.top];
//    s.top--;
    return s.a[s.top--];
}
bool isEmpty(Stack s){
    return s.top < 0;
}
bool isFull(Stack s){
    return s.top == MAX;
}
void outPut(Stack s){
    for (int i = 0; i <= s.top; ++i) {
        cout << s.a[i] << "\t";
    }
}
void convertToBinary(int x){
    Stack a;
    init(a);
    while(x != 0){
        int d = x % 2;
        push(a, d);
        x = x / 2;
    }
    while(!isEmpty(a)){
        cout << pop(a) << "\t";
    }
    cout << endl;
}
//int main(){
////    Stack s;
////    init(s);
////    push(s, 10);
////    push(s, 20);
////    push(s, 30);
////    push(s, 40);
////    pop(s);
////    outPut(s);
//    convertToBinary(25);
//    return 0;
//}