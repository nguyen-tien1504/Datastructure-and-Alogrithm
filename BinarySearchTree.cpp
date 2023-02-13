//
// Created by Nguyen Tien on 13-Feb-23.
//
#include <iostream>

using namespace std;
struct Node{
    int key;
    Node *left;
    Node *right;
};
Node *CreateNode(int value){
    Node *p = new Node;
    p->key = value;
    p->left = p->right = NULL;
    return p;
}

void InsertNode(Node *&root, int value){
    if(root == NULL){
        root = CreateNode(value);
    }else{
        Node *p = root;
        Node *prev = NULL;
        while(p != NULL && p->key != value){
            prev = p;
            if(p->key > value) p = p->left;
            else p = p->right;
        }
        if(p == NULL){
            p = CreateNode(value);
            if(prev->key < value) prev->right = p;
            else prev->left = p;
        }
    }
}
void lnr(Node *root){
    if(root != NULL){
        lnr(root->left);
        cout << root->key << "\t";
        lnr(root->right);
    }
}
void Search(Node *root, int cantim){
    if(root == NULL) {
        cout << "Chua co phan tu trong cay" << endl;
        return;
    }
    Node *p = root;
    while(p != NULL && p->key != cantim){
        if(p->key > cantim) p=p->left;
        else p=p->right;
    }
    if(p != NULL) cout << "Co gia tri can tim" << endl;
    else cout << "Khong co gia tri can tim" << endl;
}
void DeleteNode(Node *root, int value){
    if(root == NULL){
        cout << "Khong co phan tu trong cay" << endl;
        return;
    }
    Node *p = root;
    Node *prev = NULL;
    while (p != NULL && p->key != value){
        prev = p;
        if(p->key > value) p=p->left;
        else p=p->right;
    }
    //Nut co 2 cay con
    if(p->left != NULL && p->right != NULL){
        prev = p;
        Node *r = p->right;
        while(r->left != NULL){
            prev = r;
            r = r->left;
        }
        p->key = r->key;
        p = r;
    }

    //Xoa nut la hoac nut co 1 nut con
    Node *t;
    if(p->right == NULL) t = p->left;
    else if(p->left == NULL) t = p->right;
    if(prev->key > p->key) prev->left = t;
    else prev->right = t;
    delete(p);


    //Kiem tra vi tri can xoa la 1 nut la
//    if(p->left == NULL && p->right == NULL){
//        if(prev->left == p){
//            prev->left = NULL;
//        } prev->right = NULL;
//        delete(p);
//        return;
//    }
    //Kiem tra vi tri can xoa la 1 nut don
//    if(p->left != NULL && p->right == NULL){
//       if(p->key < prev->key){
//           prev->left = p->left;
//       }else{
//           prev->right = p->left;
//       }
//        p->left = NULL;
//       delete(p);
//    }else if(p->left == NULL && p->right != NULL){
//       if(p->key < prev->key){
//           prev->left = p->right;
//       }
//       else {
//           prev->right = p->right;
//       }
//       p->right = NULL;
//       delete(p);
//    }

}
int main(){
    Node *root = NULL;
    InsertNode(root, 20);
    InsertNode(root, 15);
    InsertNode(root, 10);
    InsertNode(root, 50);
    InsertNode(root, 30);
    InsertNode(root,55);
    InsertNode(root,16);
    InsertNode(root,25);
    InsertNode(root,54);


//    Search(root, 30);
    DeleteNode(root,50);
    lnr(root);
    return 0;
}