#include "cll.h"
#include <iostream>
#include <string>

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

bool isEmpty(List L) {
    return L.first == NULL;
}

Lagu* createNewElm(string judul, string penyanyi) {
    Lagu* p = new Lagu;
    if (p != NULL) {
        p->judul = judul;
        p->penyanyi = penyanyi;
        p->next = p;
        p->prev = p;
    }
    return p;
}

void insertLast(Lagu* p, List &L) {
    if (isEmpty(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        p->next = L.first;
        L.last->next = p;
        L.first->prev = p;
        L.last = p;
    }
}

void add(string judul, string penyanyi, List &L) {
    Lagu* p = createNewElm(judul, penyanyi);
    if (p != NULL) {
        insertLast(p, L);
    }
}

void deleteFirst(List &L, Lagu* &p) {
    if (L.first == L.last) {
        p = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        p = L.first;
        L.first = p->next;
        L.first->prev = L.last;
        L.last->next = L.first;
    }
}

void deleteAfter(Lagu* q, Lagu* &p) {
    p = q->next;
    q->next = p->next;
    p->next->prev = q;
}

Lagu* searchLagu(string judul, string penyanyi, List L) {
    if (isEmpty(L)) return NULL;
    Lagu* p = L.first;
    do {
        if (p->judul == judul && p->penyanyi == penyanyi) {
            return p;
        }
        p = p->next;
    } while (p != L.first);
    return NULL;
}

void moveToEnd(string judul, string penyanyi, List &L) {
    Lagu* p = searchLagu(judul, penyanyi, L);
    if (p == NULL || L.first == NULL || p == L.last) return;

    if (p == L.first) {
        deleteFirst(L, p);
    } else {
        deleteAfter(p->prev, p);
    }

    insertLast(p, L);
}

void playLaguToLagu(string judul1, string penyanyi1, string judul2, string penyanyi2, List L) {
    if (isEmpty(L)) {
        cout << "Playlist kosong\n";
        return;
    }

    Lagu* start = searchLagu(judul1, penyanyi1, L);
    Lagu* stop = searchLagu(judul2, penyanyi2, L);

    if (start == NULL || stop == NULL) {
        cout << "Lagu tidak ditemukan\n";
        return;
    }

    Lagu* p = start;
    do {
        cout << "Memutar: " << p->judul << " - " << p->penyanyi << endl;
        if (p == stop) break;
        p = p->next;
    } while (p != start);
}

void printPlaylist(List L) {
    if (isEmpty(L)) {
        cout << "Playlist kosong\n";
        return;
    }
    Lagu* p = L.first;
    cout << "\n=== Daftar Lagu ===\n";
    do {
        cout << p->judul << " - " << p->penyanyi << endl;
        p = p->next;
    } while (p != L.first);
}