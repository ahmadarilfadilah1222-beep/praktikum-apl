// Program 1: Hello World
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World! ";
    cout << "Belajar C++ sangat seru😀";
    return 0;
}

// Program 2: Input Nama
#include <iostream>
using namespace std;

int main() {
    string nama;
    cout << "Masukkan nama kamu: ";
    cin >> nama;
    cout << "Halo, " << nama;
    return 0;
}

// Program 3: Ukuran Tipe Data
#include <iostream>
using namespace std;

int main() {
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    return 0;
}

// Program 4: Operasi Aritmatika Dasar
#include <iostream>
using namespace std;

int main() {
    int a, b, hasil;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    // Penjumlahan
    hasil = a + b;
    cout << "Hasil penjumlahan: " << hasil << endl;
    // Pengurangan
    hasil = a - b;
    cout << "Hasil pengurangan: " << hasil << endl;
    // Perkalian
    hasil = a * b;
    cout << "Hasil perkalian: " << hasil << endl;
    // Pembagian
    hasil = a / b;
    cout << "Hasil pembagian: " << hasil << endl;
    // Modulus
    hasil = a % b;
    cout << "Hasil modulus: " << hasil << endl;
    return 0;
}

// Program 5: Operasi Aritmatika dengan Assignment
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    // Penjumlahan
    a += b;
    cout << "Hasil penjumlahan: " << a << endl;
    // Pengurangan
    a -= b;
    cout << "Hasil pengurangan: " << a << endl;
    // Perkalian
    a *= b;
    cout << "Hasil perkalian: " << a << endl;
    // Pembagian
    a /= b;
    cout << "Hasil pembagian: " << a << endl;
    // Modulus
    a %= b;
    cout << "Hasil modulus: " << a << endl;
    return 0;
}

