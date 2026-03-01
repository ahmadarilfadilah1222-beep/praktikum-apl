#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string passwordBenar = "119";
    
    string namaUser, inputPassword;
    int percobaan = 0;
    bool loginBerhasil = false;

    
    cout << "============================" << endl;
    cout << "           LOGIN            " << endl;
    cout << "============================" << endl;

    while (percobaan < 3) {
        cout << "\nMasukkan Nama     : ";
        cin >> namaUser;
        
        cout << "Masukkan Password : ";
        cin >> inputPassword;

        if (inputPassword.length() != 3) {
            cout << "\n>>> Password harus 3 digit! <<<" << endl;
            continue;
        }

        if (inputPassword == passwordBenar) {
            loginBerhasil = true;
            break; 
        } else {
            cout << "\nPassword Salah!" << endl;
            percobaan++;
        }
    }

    if (loginBerhasil == false) {
        cout << "\nGagal login 3 kali. Program berhenti." << endl;
        return 0; 
    }

    system("cls");
    cout << "\n===================================" << endl;
    cout << "          Login Berhasil!"        << endl;
    cout << "       Selamat Datang, " << namaUser << endl;
    cout << "===================================" << endl;
    
    int pilihan;
    double nilai, hasil1, hasil2;
    char lanjut;

    while (true) {
        cout << "\n===================================" << endl;
        cout << "           MENU KONVERSI            " << endl;
        cout << "===================================" << endl;
        cout << "1. Meter Ke Kilometer Dan Centimeter" << endl;
        cout << "2. Kilometer Ke Meter Dan Centimeter" << endl;
        cout << "3. Centimeter Ke Meter Dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "===================================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
 
        if (pilihan == 1) {
            cout << "\n===================================" << endl;
            cout << "           Konversi Meter           " << endl;
            cout << "===================================" << endl;
            cout << "Masukkan nilai dalam Meter: ";
            cin >> nilai;
            
            hasil1 = nilai / 1000;
            hasil2 = nilai * 100;
            
            cout << "\n===================================" << endl;
            cout << "           Hasil Konversi           " << endl;
            cout << "===================================" << endl;
            cout << nilai << " Meter = " << hasil1 << " Kilometer" << endl;
            cout << nilai << " Meter = " << hasil2 << " Centimeter" << endl;
            
            cout << "\nTekan huruf a lalu Enter untuk lanjut... ";
            cin >> lanjut;
            system("cls");
        } 
        else if (pilihan == 2) {
            cout << "\n===================================" << endl;
            cout << "         Konversi Kilometer         " << endl;
            cout << "===================================" << endl;
            cout << "Masukkan nilai dalam Kilometer: ";
            cin >> nilai;
            
            hasil1 = nilai * 1000;
            hasil2 = nilai * 100000;
            
            cout << "\n===================================" << endl;
            cout << "           Hasil Konversi           " << endl;
            cout << "===================================" << endl;
            cout << nilai << " Kilometer = " << hasil1 << " Meter" << endl;
            cout << nilai << " Kilometer = " << hasil2 << " Centimeter" << endl;
            
            cout << "\nTekan huruf a lalu Enter untuk lanjut... ";
            cin >> lanjut;
            system("cls");
        } 
        else if (pilihan == 3) {
            cout << "\n===================================" << endl;
            cout << "        Konversi Centimeter         " << endl;
            cout << "===================================" << endl;
            cout << "Masukkan nilai dalam Centimeter: ";
            cin >> nilai;
            
            hasil1 = nilai / 100;
            hasil2 = nilai / 100000;
            
            cout << "\n===================================" << endl;
            cout << "           Hasil Konversi           " << endl;
            cout << "===================================" << endl;
            cout << nilai << " Centimeter = " << hasil1 << " Meter" << endl;
            cout << nilai << " Centimeter = " << hasil2 << " Kilometer" << endl;
            
            cout << "\nTekan huruf alalu Enter untuk lanjut... ";
            cin >> lanjut;
            system("cls");
        } 
        else if (pilihan == 4) {
            system("cls");
            cout << "\n============================" << endl;
            cout << "        Program Selesai       " << endl;
            cout << "         Terima kasih!        " << endl;
            cout << "============================" << endl;
            break; 
        } 
        else {
            cout << "\n>>> Anda harus memilih angka 1-4! <<<" << endl;
            cout << "\nTekan huruf a lalu Enter untuk lanjut... ";
            cin >> lanjut;
            system("cls");
        }
    }

    return 0;
}