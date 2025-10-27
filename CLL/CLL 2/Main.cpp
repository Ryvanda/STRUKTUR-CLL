#include "cll.h"
#include "cll.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    List playlist;
    createList(playlist);

    add("Alone", "Marsmellow", playlist);
    add("Pamit", "Tulus", playlist);
    add("Kali Kedua", "Raisa", playlist);

    printPlaylist(playlist);

    cout << "\n== Setelah memindahkan 'Pamit' ke akhir ==\n";
    moveToEnd("Pamit", "Tulus", playlist);
    printPlaylist(playlist);

    cout << "\n== Simulasi memutar lagu dari 'Alone' ke 'Kali Kedua' ==\n";
    playLaguToLagu("Alone", "Marsmellow", "Kali Kedua", "Raisa", playlist);

    return 0;
}