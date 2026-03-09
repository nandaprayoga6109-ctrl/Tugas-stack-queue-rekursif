#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* top = NULL;

void tambahStack(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;  

    cout << value << " masuk ke Stack.\n";
}

void hapusStack() {

    if (top == NULL) {
        cout << "Stack Kosong!\n";
        return;
    }

    Node* temp = top;
    top = top->next;

    cout << temp->data << " dihapus dari Stack.\n";
    delete temp;
}

void tampil() {
    Node* temp = top;

    if (temp == NULL) {
        cout << "Stack kosong!\n";
        return;
    }

    cout << "Isi Stack:\n";

    while (temp) {
        cout << "  " << temp->data << endl;
        cout << "  v" << endl;
        temp = temp->next;
    }
}

int main() {
    int pil, data;

    do {
        cout << endl;
        cout << "1. Tambah" << endl;
        cout << "2. Hapus" << endl;
        cout << "3. Tampil" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih : "; 
        cin >> pil;

        if (pil == 1) {
            cout << "Data : ";
            cin >> data;
            tambahStack(data);

        } else if (pil == 2) {
            hapusStack();

        } else if (pil == 3) {
            tampil();

        } else if (pil == 4) {
            break;
        }

    } while (pil != 0);

    return 0;
}