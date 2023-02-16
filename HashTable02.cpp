#include <iostream>
#define M 7
using namespace std;
// Phuong phap noi ket hop nhat - giam thieu kha nang dung do
struct Item{
    int value;
    int next;
};
struct HashTable{
    Item h[M];
    int last;
};
void init(HashTable &t){
    for (int i = 0; i < M; i++)
    {
        t.h[i].value = -1;
        t.h[i].next = -1;
    }
    t.last = M - 1;
}
void insertHashTable(HashTable &t){
    
}
//int main(){
//    HashTable t;
//    init(t);
//    return 0;
//}