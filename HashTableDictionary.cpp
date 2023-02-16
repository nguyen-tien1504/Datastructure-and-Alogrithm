#include <iostream>
#include <string>
#define M 101
using namespace std;
struct Word{
    string English;
    string type;
    string Vietnamese;
};
struct Node{
    Word w;
    Node *next;
};
void initHashTable(Node *heads[]){
    for (int i = 0; i < M; i++)
    {
        heads[i] = NULL;
    }
}
int hashFunction(Word w){
    int h = 0;
        for (int i = 0; i < w.English.length(); i++)
        {
            h += (int)tolower(w.English[i]) * (i + 1);
        }
    return h % M;
}
Node* createNode(Word w){
    Node *p = new Node;
    p->w = w;
    p->next = NULL;
    return p;
}
void addWord(Node *heads[], Word word){
    int h = hashFunction(word);
    Node *p = heads[h];
    Node *newNode = createNode(word);
    if(p == NULL){
        heads[h] = newNode;
        return;
    }
    while(p->next != NULL && p->w.English != word.English){
        p = p->next;
    }
    int t = hashFunction(p->w);
    if(t == h){
        return;
    }
    p->next = newNode;
}
void outPut(Node *heads[]){
    for (int i = 0; i < M; i++)
    {
        if(heads[i] != NULL){
            Node *p = heads[i];
            while(p != NULL){
                cout << p->w.English << " (" << p->w.type << "): " << p->w.Vietnamese << endl;
                p = p->next;
            }
        }
    }
}
int main(){
    Node *heads[M];
    initHashTable(heads); 
    Word w1;
    w1.English = "Go";
    w1.type = "verb";
    w1.Vietnamese = "Di bo";

    Word w2;
    w2.English = "Go";
    w2.type = "verb";
    w2.Vietnamese = "Di bo";
    Word w3;
    w3.English = "Run";
    w3.type = "verb";
    w3.Vietnamese = "Chay";
    addWord(heads, w1);
    addWord(heads, w2);
    addWord(heads, w3);

    outPut(heads);
    return 0;
}