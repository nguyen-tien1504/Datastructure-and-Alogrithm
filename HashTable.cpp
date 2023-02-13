//
// Created by Nguyen Tien on 13-Feb-23.
//
#include <iostream>
#define M 17
using namespace std;
struct Node{
    int value;
    Node *next;
};
void initHash(Node *heads[]){
    for (int i = 0; i < M; ++i) {
        heads[i] == NULL;
    }
}
Node *CreateNode(int x){
    Node *p = new Node;
    p->value = x;
    p->next = NULL;
    return p;
}
int hashFunction(int value){
    return value % M;
}
void InsertNode(Node *heads[], int value){
    int h = hashFunction(value);
    Node *head = heads[h];

}
int main(){
    Node *heads[M];
    initHash(heads);
    return 0;
}