#include <iostream>
#include <string>
using namespace std;

#define MAX 100
string data1[MAX];
int pos = 0;

void Tampil() {
    if (pos > 0) {
        cout << "Data ATK/S Ditampilkan\n";
        for (int i = 0; i < pos; i++) {
            cout << i + 1 << ". " << data1[i] << endl;
        }
    } else {
        cout << "=== Data Masih Kosong ===\n";
    }
}

void Tambah() {
    if (pos < MAX) {
        cin.ignore();
        cout << "Tambah Data ATK/S yang di inginkan: ";
        getline (cin, data1[pos++]);
    } else {
        cout << "<-- GUDANG ATK/S TELAH PENUH -->\n";
    }
    Tampil();
}

void Ubah() {
    Tampil();
    cout << "Ubah Data Ke: ";
    int y;
    cin >> y;
    if (y > 0 && y <= pos) {
        cin.ignore();
        cout << "Ubah Menjadi: ";
        getline(cin, data1[y - 1]);
    }
    Tampil();
}

void Hapus() {
    Tampil();
    cout << "Hapus Data ke: ";
    int x;
    cin >> x;
    if (x > 0 && x <= pos) {
        for (int i = x; i < pos; i++) {
            data1[i - 1] = data1[i];
        }
        pos--;
    }
    Tampil();
}

bool Login() {
    string Username, Password;
    cout << "=== Login ===\n";
    cout << "Username: ";
    getline(cin, Username);
    cout << "Password: ";
    getline(cin, Password);
    return Username == "nanda" && Password == "2309106022";
}

int main() {
    int percobaan = 0;
    while (percobaan < 3 && !Login()) {
        cout << "Login gagal. Kesempatan mencoba: " << 2 - percobaan << " kali\n";
        percobaan++;
    }

    if (percobaan == 3) {
        cout << "Percobaan Login telah melebihi batas, percobaan berhenti\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== GUDANG PENDATAAN ATK/S ===\n"
             << "1. Tambah Data ATK/S\n"
             << "2. Ubah Data ATK/S\n"
             << "3. Hapus Data ATK/S\n"
             << "4. Tampilkan Data ATK/S\n"
             << "5. Keluar\n"
             << "Pilih menu yang tertera diatas (1/2/3/4/5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
                Tambah(); 
                break;
            case 2: 
                Ubah(); 
                break;
            case 3: 
                Hapus(); 
                break;
            case 4: 
                Tampil(); 
                break;
            case 5: 
                cout << "Terima kasih telah mendata program ATK/S\n"; 
                return 0;
            default: 
                cout << "Pilihan Invalid\n";
        }
    } while (true);

    return 0;
}
