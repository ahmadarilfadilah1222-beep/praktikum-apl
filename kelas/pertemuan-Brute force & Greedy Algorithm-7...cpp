#include <iostream>
#include <algorithm>
using namespace std;

struct Barang {
    int id;
    float berat;
    float nilai;
    float rasio;
};

bool bandingkanBarang(const Barang& a, const Barang& b) {
    return a.rasio > b.rasio;
}

int main() {
    Barang items[] = {
        {1, 10, 60, 0}, // A
        {2, 20, 100, 0} // B
    };
    int n = 2;
    float kapasitas = 15;
    float totalNilai = 0;

    for (int i = 0; i < n; i++) {
        items[i].rasio = items[i].nilai / items[i].berat;
    }

    sort(items, items + n, bandingkanBarang);

    cout << " = FRACTIONAL KNAPSACK (GREEDY) =" << endl;
    cout << "Kapasitas Tas: " << kapasitas << " kg" << endl << endl;

    for (int i = 0; i < n; i++) {
        if (kapasitas <= 0) break;

        if (items[i].berat <= kapasitas) {
            cout << "Ambil Barang " << items[i].id << " utuh (" << items[i].berat << " kg)" << endl;
            totalNilai += items[i].nilai;
            kapasitas -= items[i].berat;
        } else {
            float bagian = kapasitas / items[i].berat;
            cout << "Ambil Barang " << items[i].id << " sebagian (" << kapasitas << " kg dari " << items[i].berat << " kg)" << endl;
            totalNilai += items[i].nilai * bagian;
            kapasitas = 0;
        }
    }

    cout << "\nTotal Nilai Maksimum: " << totalNilai << endl;
    cout << "Sisa Kapasitas Tas: " << kapasitas << " kg" << endl;

    return 0;
}