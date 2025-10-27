#include "cll.h"
#include "cll.cpp"
#include <iostream>

using namespace std;

int main() {
    List L;
    Group G;
    createList(L);

    tambahAnggota(L, "1130501", "Andi", 19);
    tambahAnggota(L, "1130502", "Tono", 21);
    tambahAnggota(L, "1130503", "Ayu", 24);
    tambahAnggota(L, "1130504", "Budi", 18);

    printList(L);
    pemilihan(L, G);

    cout << "\nKetua: " << G.ketua->nama << " (" << G.ketua->umur << ")\n";
    cout << "Bendahara: " << G.bendahara->nama << " (" << G.bendahara->umur << ")\n";

    return 0;
}