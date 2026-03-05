// Contoh array 2 dimensi (matriks)
int matriks[3][3] = {
    {1, 2, 3}, // Baris ke-0
    {4, 5, 6}, // Baris ke-1
    {7, 8, 9}  // Baris ke-2
};

// Mengakses elemen
cout << matriks[0][1] << endl;
cout << matriks[2][0] << endl;

// Menampilkan seluruh matriks dengan nested loop
for (int i = 0; i < 3; i++) { // Loop baris
    for (int j = 0; j < 3; j++) { // Loop kolom
        cout << matriks[i][j] << " ";
    }
    cout << endl;
}

// Iterasi menggunakan range-based for
for (auto &baris : matriks) { // Iterasi setiap baris (array 1D)
    for (auto &elemen : baris) { // Iterasi setiap elemen dalam baris
        cout << elemen << " ";
    }
    cout << endl;
}
// Contoh array 3 dimensi untuk nilai mahasiswa per kelas
#include <iostream>
using namespace std;

void tampilkanNilaiMahasiswa() {
    int nilai[2][2][2] = {
        { {80, 85}, {75, 90} }, // Kelas A
        { {88, 92}, {70, 78} }  // Kelas B
    };
    cout << " = DATA NILAI MAHASISWA =\n\n";
    for (int k = 0; k < 2; k++) {
        cout << "Kelas " << char('A' + k) << endl;
        for (int m = 0; m < 2; m++) {
            cout << " Mahasiswa " << m + 1 << endl;
            cout << "  UTS : " << nilai[k][m][0] << endl;
            cout << "  UAS : " << nilai[k][m][1] << endl;
        }
        cout << endl;
    }
}

#include <iostream>
#include <string>
using namespace std;

struct Alamat {
    string jalan;
    int nomor;
    string kota;
};

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
    Alamat alamat;
};

#define MAX_MAHASISWA 100
int panjang = 0;
Mahasiswa mhs[MAX_MAHASISWA];

void tampilkanMahasiswa() {
    if (panjang == 0) {
        cout << "Belum ada data mahasiswa." << endl;
    } else {
        cout << "Daftar Mahasiswa:" << endl;
        cout << "================================" << endl;
        for (int i = 0; i < panjang; i++) {
            cout << "Mahasiswa ke-" << i + 1 << endl;
            cout << "Nama    : " << mhs[i].nama << endl;
            cout << "Umur    : " << mhs[i].umur << endl;
            cout << "Jurusan : " << mhs[i].jurusan << endl;
            cout << "Alamat  : " << mhs[i].alamat.jalan
                 << " No. " << mhs[i].alamat.nomor
                 << ", " << mhs[i].alamat.kota << endl;
            cout << "--------------------------------" << endl;
        }
    }
}

void tambahMahasiswa() {
    if (panjang < MAX_MAHASISWA) {
        cout << "Masukkan nama    : ";
        cin.ignore();
        getline(cin, mhs[panjang].nama);
        cout << "Masukkan umur    : ";
        cin >> mhs[panjang].umur;
        cin.ignore();
        cout << "Masukkan jurusan : ";
        getline(cin, mhs[panjang].jurusan);
        cout << " - Alamat -" << endl;
        cout << "Jalan  : "; getline(cin, mhs[panjang].alamat.jalan);
        cout << "Nomor  : "; cin >> mhs[panjang].alamat.nomor;
        cin.ignore();
        cout << "Kota   : "; getline(cin, mhs[panjang].alamat.kota);
        panjang++;
        cout << "Data berhasil ditambahkan!" << endl;
    } else {
        cout << "Kapasitas penuh!" << endl;
    }
}

void ubahMahasiswa() {
    if (panjang == 0) {
        cout << "Belum ada mahasiswa untuk diubah." << endl;
    } else {
        cout << "Daftar Mahasiswa" << endl;
        cout << "==================" << endl;
        for (int i = 0; i < panjang; i++) {
            cout << "Mahasiswa ke-" << i + 1 << ": " << mhs[i].nama << endl;
        }
        int index;
        cout << "Masukkan nomor mahasiswa yang akan diubah: ";
        cin >> index;
        if (index > 0 && index <= panjang) {
            cin.ignore();
            cout << "Masukkan nama mahasiswa baru    : ";
            getline(cin, mhs[index - 1].nama);
            cout << "Masukkan umur mahasiswa baru    : ";
            cin >> mhs[index - 1].umur;
            cin.ignore();
            cout << "Masukkan jurusan mahasiswa baru : ";
            getline(cin, mhs[index - 1].jurusan);
            cout << "Masukkan alamat mahasiswa baru:" << endl;
            cout << "Jalan  : "; getline(cin, mhs[index - 1].alamat.jalan);
            cout << "Nomor  : "; cin >> mhs[index - 1].alamat.nomor;
            cin.ignore();
            cout << "Kota   : "; getline(cin, mhs[index - 1].alamat.kota);
            cout << "Mahasiswa berhasil diubah" << endl;
        } else {
            cout << "Nomor mahasiswa tidak valid" << endl;
        }
    }
}

void hapusMahasiswa() {
    if (panjang == 0) {
        cout << "Belum ada mahasiswa untuk dihapus." << endl;
    } else {
        cout << "Daftar Mahasiswa" << endl;
        cout << "==================" << endl;
        for (int i = 0; i < panjang; i++) {
            cout << "Mahasiswa ke-" << i + 1 << ": " << mhs[i].nama << endl;
        }
        int index;
        cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
        cin >> index;
        if (index > 0 && index <= panjang) {
            for (int i = index - 1; i < panjang - 1; i++) {
                mhs[i] = mhs[i + 1];
            }
            panjang--;
            cout << "Mahasiswa berhasil dihapus" << endl;
        } else {
            cout << "Nomor mahasiswa tidak valid" << endl;
        }
    }
}

int main() {
    int pilihan;
    do {
        cout << "==============================" << endl;
        cout << " Menu Manajemen Mahasiswa " << endl;
        cout << "==============================" << endl;
        cout << "1. Tampilkan Data Mahasiswa" << endl;
        cout << "2. Tambah Data Mahasiswa" << endl;
        cout << "3. Ubah Data Mahasiswa" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilkanMahasiswa(); break;
            case 2: tambahMahasiswa(); break;
            case 3: ubahMahasiswa(); break;
            case 4: hapusMahasiswa(); break;
            case 5: cout << "Sampai jumpa!" << endl; break;
            default: cout << "Pilihan tidak valid!" << endl; break;
        }
    } while (pilihan != 5);
    return 0;
}
