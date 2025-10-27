#include "cll.h"
#include <iostream>


void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

bool isEmpty(List L) {
    return L.first == NULL;
}

Mahasiswa* createNewElmt(string nim, string nama, int umur) {
    Mahasiswa* p = new Mahasiswa;
    if (p != NULL) {
        p->nim = nim;
        p->nama = nama;
        p->umur = umur;
        p->next = p;
    }
    return p;
}

void tambahAnggota(List &L, string nim, string nama, int umur) {
    Mahasiswa* p = createNewElmt(nim, nama, umur);
    if (isEmpty(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.last->next = p;
        L.first = p;
    }
}

void pemilihan(List L, Group &G) {
    if (isEmpty(L)) {
        G.ketua = NULL;
        G.bendahara = NULL;
        return;
    }

    Mahasiswa* p = L.first;
    G.ketua = p;
    G.bendahara = p;
    do {
        if (p->umur > G.ketua->umur)
            G.ketua = p;
        if (p->umur < G.bendahara->umur)
            G.bendahara = p;
        p = p->next;
    } while (p != L.first);
}

void printList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong\n";
        return;
    }
    Mahasiswa* p = L.first;
    do {
        cout << p->nim << " - " << p->nama << " (" << p->umur << ")\n";
        p = p->next;
    } while (p != L.first);
}