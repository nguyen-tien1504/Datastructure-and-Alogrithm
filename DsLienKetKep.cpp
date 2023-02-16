//
// Created by Nguyen Tien on 12-Feb-23.
//
#include <iostream>

using namespace std;
struct Node{
    int value;
    Node *next;
    Node *prev;
};
struct LinkedList{
    Node *head = NULL;
    Node *tail = NULL;
};
Node* createNode(int value){
    Node *p = new Node;
    p->value = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void addFirst(LinkedList &ds, int x){
    Node *p = createNode(x);
    if(ds.head == NULL){
        //Danh sach chua co phan tu nao
        ds.tail = ds.head = p;
    } else {
        p->next = ds.head;
        ds.head->prev = p;
        ds.head = p;
    }
}
void addLast(LinkedList &ds, int x){
    Node *p = createNode(x);
    if(ds.head == NULL){
        //Danh sach chua co phan tu nao
        ds.head = ds.tail = p;
    } else{
        ds.tail->next = p;
        p->prev = ds.tail;
        ds.tail = p;
    }
}
void outPutFromHead(LinkedList ds){
    Node *p = ds.head;
    while(p != NULL){
        cout << p->value << "\t";
        p=p->next;
    }
    cout << endl;
}
void outPutFromTail(LinkedList ds){
    Node *p = ds.tail;
    while(p != NULL){
        cout << p->value << "\t" ;
        p=p->prev;
    }
    cout << endl;
}
void ThemVaoGiuaDs(LinkedList &ds, int gtri, int vitri){
    Node *newNode = createNode(gtri);
    Node *p = ds.head;
    // kiem tra danh sach rong
    if(p != NULL){
        while(p->value != vitri && p->next != NULL){
            p = p->next;
        }
        // kiem tra vi tri co phai la vi tri cuoi cung
        if(p->next == NULL && p->value == vitri) addLast(ds, gtri);
        else if(p->value != vitri){
            cout << "ko co vi tri can chen" << endl;
        }else{
            Node *nextNode = p->next;
            newNode->next = nextNode;
            newNode->prev = p;
            p->next = newNode;
            nextNode->prev = newNode;
        }
    } else ds.head = ds.tail = newNode;

}
void Delete(LinkedList &ds, int gtri){
    if(ds.head == NULL) {
        cout << "Khong co phan tu nao";
        return;
    }
    Node *p = ds.head;
    while(p->value != gtri && p->next != NULL){
        p = p->next;
    }
    Node *prevNode = p->prev;
    Node *nextNode = p->next;
    if(prevNode == NULL && nextNode == NULL){
        //Kiem tra danh sach co 1 phan tu hay ko
        if(p->value == gtri){
            ds.head = ds.tail = NULL;
            delete(p);
        } else cout << "khong co gia tri can xoa" << endl;
        return;
    }
    if(prevNode == NULL){
        //vi tri can xoa la phan tu dau
        ds.head = nextNode;
        ds.head->prev = NULL;
        p->next = NULL;
        delete(p);
        return;
    }
    if(nextNode == NULL){
        // vi tri can xoa la phan tu cuoi
        if(p->value == gtri){
            ds.tail = prevNode;
            ds.tail->next = NULL;
            p->prev = NULL;
            delete(p);

        }else cout << "khong co gia tri can xoa" << endl;
        return;
    }
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    p->next = p->prev = NULL;
    delete(p);
}
//int main(){
//    LinkedList ds;
////    addFirst(ds, 10);
////    addFirst(ds, 20);
////    addFirst(ds, 30);
////    addFirst(ds, 40);
//////    outPutFromHead(ds);
////    addLast(ds, 100);
//    ThemVaoGiuaDs(ds, 15, 100);
//    outPutFromHead(ds);
//    Delete(ds, 15);
//    outPutFromHead(ds);
//    return 0;
//}