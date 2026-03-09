#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* depan = NULL;
Node* belakang = NULL;

void tambah(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (belakang == NULL) {
        depan = belakang = baru;
    } else {
        belakang->next = baru;
        belakang = baru;
    }

    cout << nilai << " ditambahkan ke queue.\n";
}

void hapus() {
    if (depan == NULL) {
        cout << "Queue kosong.\n";
        return;
    }

    Node* hapus = depan;
    depan = depan->next;

    if (depan == NULL)
        belakang = NULL;

    cout << hapus->data << " dihapus dari queue.\n";
    delete hapus;
}

void tampil() {
    if (depan == NULL) {
        cout << "Queue kosong.\n";
        return;
    }

    Node* bantu = depan;

    cout << "Isi queue : ";
    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    int pilih, data;

    do {
        cout << "\n1. Tambah\n";
        cout << "2. Hapus\n";
        cout << "3. Tampil\n";
        cout << "0. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan data : ";
            cin >> data;
            tambah(data);

        } else if (pilih == 2) {
            hapus();

        } else if (pilih == 3) {
            tampil();

        } else if (pilih == 0) {
            cout << "Program selesai.\n";

        } else {
            cout << "Pilihan tidak tersedia.\n";
        }

    } while (pilih != 0);

    return 0;
}