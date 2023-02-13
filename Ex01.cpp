//
// Created by Nguyen Tien on 13-Feb-23.
//
#include <iostream>

using namespace std;
struct Element{
    double heSo;
    int bac;
};
struct Node{
    Element value;
    Node *next;
};
Node* CreateNode(Element el){
    Node *p = new Node;
    p->value = el;
    p->next = NULL;
    return p;
}
void InsertNode(Node *&head, Element el){
    if(head == NULL){
        Node *p = CreateNode(el);
        head = p;
        return;
    }
    Node *r = head;
    Node *prev = NULL;
    while(r != NULL && r->value.bac <= el.bac){
        if(r->value.bac == el.bac){
            r->value = el;
            return;
        }
        prev = r;
        r = r->next;
    }
    Node *p = CreateNode(el);
    if(r == NULL) prev->next = p;
    else{
        p->next = r;
        if(prev == NULL){
            head = p;
        }else prev->next = p;
    }
}
void OutPut(Node *head){
    Node *p = head;
    while(p != NULL){
        cout << p->value.bac << "\t";
        p = p->next;
    }
}
int main(){
    Node *head = NULL;
    Element el0, el1, el2, el3;
    el0.heSo = 1;
    el0.bac = 2;
    el1.bac = 5;
    el2.bac = 7;
    el3.bac = 4;
    InsertNode(head,el0);
    InsertNode(head,el1);
    InsertNode(head,el2);
    InsertNode(head,el3);
    OutPut(head);
    return 0;
}