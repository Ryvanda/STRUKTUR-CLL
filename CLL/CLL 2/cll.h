#ifndef CLL_H
#define CLL_H
#include <iostream>
#include <string>

using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    Lagu* next;
    Lagu* prev;
};

struct List {
    Lagu* first;
    Lagu* last;
};

void createList(List &L);
bool isEmpty(List L);
Lagu* createNewElm(string judul, string penyanyi);
void insertLast(Lagu* p, List &L);
void add(string judul, string penyanyi, List &L);
void deleteFirst(List &L, Lagu* &p);
void deleteAfter(Lagu* q, Lagu* &p);
Lagu* searchLagu(string judul, string penyanyi, List L);
void moveToEnd(string judul, string penyanyi, List &L);
void playLaguToLagu(string judul1, string penyanyi1, string judul2, string penyanyi2, List L);
void printPlaylist(List L);

#endif