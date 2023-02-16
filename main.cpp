#include <iostream>
using namespace std;
struct Node{
    int value;
    struct Node *next;
};
void init(Node *&head){
    head = NULL;
}
Node* CreateNode(int x){
    Node *p = new Node;
    p->value=x;
    p->next=NULL;
    return p;
}
void AddFirst(Node *&head, int x){
    Node *p = CreateNode(x);
    p->next = head;
    head=p;
}
void AddLast(Node *&head, int x){
    Node *p = CreateNode(x);
    Node *last = head;
    if(head == NULL){
        //p->next = head;
        head = p;
    }else{
        while(last->next != NULL){
            last = last->next;
        }
        //Chen phan tu vao cuoi cung
        last->next = p;
    }
}
void OutPut(Node *head){
    Node *p = head;
    while(p != NULL){
        cout << p->value << "\t";
        p = p->next;
    }
}
void ThemVaoGiuaDS(Node *head, int value, int x){
    Node *newNode = CreateNode(x);
    Node *p = head;
    while(p->value != value){
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}
void XoaPhanTuDauTien(Node *&head){
    Node *p = head;
    head = head->next;
    p->next = NULL;
    delete(p);
}
void XoaPhanTuCuoi(Node *head){
    Node *last = head;
    Node *prev = NULL;
    while (last->next != NULL){
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = NULL;
    delete(last);
}
void XoaPhanTuBatKi(Node *&head, int gtri){
    if(head != NULL){
        Node *p = head;
        Node *prev = NULL;
        while(p->value != gtri && p->next != NULL){
            prev = p;
            p = p->next;
        }
        if(prev == NULL){
            //Ds chi co 1 phan tu hoac xoa phan tu dau tien
            XoaPhanTuDauTien(head);
        } else if(p->value != gtri && p->next == NULL){
            cout << "ko co gia tri can xoa" << endl;
        }else if(p->value == gtri && p->next == NULL){
            XoaPhanTuCuoi(head);
        } else{
            prev->next = p->next;
            p->next = NULL;
            delete(p);
        }
    }

}
//int main() {
//    Node *head;
//    init(head);
//    AddLast(head, 50);
//    AddFirst(head, 10);
//    XoaPhanTuCuoi(head);
////    XoaPhanTuDauTien(head);
//    AddFirst(head, 14);
//    AddFirst(head, 22);
//    AddLast(head, 99);
//    ThemVaoGiuaDS(head, 10, 100);
////    XoaPhanTuCuoi(head);
//    OutPut(head);
////    XoaPhanTuDauTien(head);
//    XoaPhanTuBatKi(head, 993);
//    cout << endl << "=======" << endl;
//    OutPut(head);
//    return 0;
//}
