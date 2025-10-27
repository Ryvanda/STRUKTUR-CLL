#ifndef CLL_H
#define CLL_H
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    int umur;
    Mahasiswa* next;
};

struct List {
    Mahasiswa* first;
    Mahasiswa* last;
};
    
struct Group {
    Mahasiswa* ketua;
    Mahasiswa* bendahara;
};

void createList(List &L);
bool isEmpty(List L);
Mahasiswa* createNewElmt(string nim, string nama, int umur);
void tambahAnggota(List &L, string nim, string nama, int umur);
void pemilihan(List L, Group &G);
void printList(List L);

#endif