//
// Created by Nguyen Tien on 12-Feb-23.
//
#include <iostream>
#include <string>
using namespace std;
struct HocVien{
    int maHV;
    string tenHV;
    int namSinh;
};
struct NodeHV{
    HocVien HV;
    NodeHV *next;
};
NodeHV* createNodeHV(HocVien HV){
    NodeHV *p = new NodeHV;
    p->HV = HV ;
    p->next = NULL;
    return p;
}
void addFirst(NodeHV *&head, HocVien HV){
    NodeHV *newHV = createNodeHV(HV);
    newHV->next = head;
    head = newHV;
}
void outPut(NodeHV *head){
    NodeHV *p = head;
    while (p != NULL){
        cout << "{ma HV: " << p->HV.maHV << ", ten HV: " << p->HV.tenHV << ", Nam sinh: " << p->HV.namSinh << "}" << endl;
        p=p->next;
    }
}
int main(){
    HocVien h1;
    h1.maHV = 123;
    h1.tenHV = "Tien";
    h1.namSinh = 2000;

    HocVien h2;
    h2.maHV = 456;
    h2.tenHV = "Lien";
    h2.namSinh = 2003;


    NodeHV *head = NULL;
    addFirst(head, h1);
    addFirst(head, h2);
    outPut(head);
    return 0;
}