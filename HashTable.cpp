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
        heads[i] = NULL;
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
void InsertNode(Node *heads[], int gtri){
    int h = hashFunction(gtri);
    Node *p = heads[h];
    Node *prev = NULL;
    while(p != NULL && p->value < gtri){
        prev = p;
        p = p->next;
    }

    Node *newNode = CreateNode(gtri);
    if(prev == NULL){
        newNode->next = p;
        heads[h] = newNode;
        return;
    }
    prev->next = newNode;
    newNode->next = p;
}
void Output(Node *head[]){
    for (int i = 0; i < M; ++i) {
        if(head[i] != NULL){
            Node *p = head[i];
            while (p != NULL){
              cout << p->value << "\t";
              p = p->next;
            }
            cout << endl;
        }
    }
}
void Search(Node *heads[], int gtri){
//    int h = hashFunction(gtri);
//    Node *p = heads[h];
//    if(p == NULL){
//        cout << "Khong co gia tri can tim" << endl;
//        return;
//    }
//    while(p != NULL && p->value < gtri){
//        p = p->next;
//    }
//    if(p->next == NULL && p->value != gtri) cout << "Khong co gia tri can tim" << endl;
//    if((p->next == NULL && p->value == gtri) || p->next != NULL)
//     cout << "Co gia tri can tim" << endl;

    int h = hashFunction(gtri);
    Node *p = heads[h];
    while(p != NULL && p->value != gtri) p = p->next;
    if(p == NULL){
        cout << "Khong co gia tri can tim" << endl;
        return;
    }
    cout <<  "Co gia tri can tim" << endl;
}
int main(){
    Node *heads[M];
    initHash(heads);
    InsertNode(heads, 53);
    InsertNode(heads, 2);
    InsertNode(heads, 36);
    InsertNode(heads, 19);
    InsertNode(heads, 70);
    InsertNode(heads, 12);
    InsertNode(heads, 14);
    InsertNode(heads, 17);
    InsertNode(heads, 80);
    InsertNode(heads, 15);
    Output(heads);
    Search(heads, 111);
    return 0;
}