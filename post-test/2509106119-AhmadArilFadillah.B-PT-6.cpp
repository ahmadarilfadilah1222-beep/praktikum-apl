#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

struct User{
    string nama;
    string nim;
    string role;
};

struct Penyewa{
    string nama;
    string nim;
};

struct Mobil{
    string plat;
    string nama;
    int harga;
    string status;
    Penyewa penyewa;
    Penyewa *ptrPenyewa;
};

int hitungMobil(int n){
    if(n==0) return 0;
    return 1 + hitungMobil(n-1);
}

void urutkanNamaMobilDesc(Mobil *mobil, int jumlahMobil) {
    for (int i = 0; i < jumlahMobil - 1; i++) {
        for (int j = 0; j < jumlahMobil - i - 1; j++) {
            if ((mobil + j)->nama < (mobil + j + 1)->nama) {
                Mobil temp = *(mobil + j);
                *(mobil + j) = *(mobil + j + 1);
                *(mobil + j + 1) = temp;
            }
        }
    }
}

void urutkanHargaMobilAsc(Mobil *mobil, int jumlahMobil) {
    for (int i = 0; i < jumlahMobil - 1; i++) {
        for (int j = 0; j < jumlahMobil - i - 1; j++) {
            if ((mobil + j)->harga > (mobil + j + 1)->harga) {
                Mobil temp = *(mobil + j);
                *(mobil + j) = *(mobil + j + 1);
                *(mobil + j + 1) = temp;
            }
        }
    }
}

void urutkanPlatMobilAsc(Mobil *mobil, int jumlahMobil) {
    for (int i = 0; i < jumlahMobil - 1; i++) {
        for (int j = 0; j < jumlahMobil - i - 1; j++) {
            if ((mobil + j)->plat > (mobil + j + 1)->plat) {
                Mobil temp = *(mobil + j);
                *(mobil + j) = *(mobil + j + 1);
                *(mobil + j + 1) = temp;
            }
        }
    }
}

void tampilkanSatuMobil(Mobil m){
     cout<<left<<setw(12)<<m.plat
         <<setw(25)<<m.nama
         <<setw(12)<<m.harga
         <<setw(15)<<m.status<<endl;
}

int cariMobilByNameLinear(Mobil *mobil, int jumlahMobil, string keyword) {
    for(int i=0; i<jumlahMobil; i++){
        if((mobil+i)->nama.find(keyword) != string::npos){
            return i;
        }
    }
    return -1;
}

int cariMobilByPlatBinary(Mobil *mobil, int jumlahMobil, string targetPlat) {
    urutkanPlatMobilAsc(mobil, jumlahMobil);

    int left = 0;
    int right = jumlahMobil - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if ((mobil + mid)->plat == targetPlat) {
            return mid;
        }

        if ((mobil + mid)->plat < targetPlat) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    return -1;
}

void lihatMobil(Mobil *mobil, int jumlahMobil){
    clear();

    cout<<"\n========================================================="<<endl;
    cout<<"=                     DAFTAR MOBIL                     ="<<endl;
    cout<<"========================================================="<<endl;

    cout<<left<<setw(12)<<"Plat"
        <<setw(25)<<"Nama Mobil"
        <<setw(12)<<"Harga"
        <<setw(15)<<"Status"<<endl;

    cout<<"========================================================="<<endl;

    for(int i=0;i<jumlahMobil;i++){
        cout<<left<<setw(12)<<(mobil+i)->plat
            <<setw(25)<<(mobil+i)->nama
            <<setw(12)<<(mobil+i)->harga
            <<setw(15)<<(mobil+i)->status<<endl;
    }

    cout<<"========================================================="<<endl;
    cout<<"Total Mobil : "<<hitungMobil(jumlahMobil)<<endl;

    cout<<"\nTekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void lihatMobil(Mobil *mobil, int jumlahMobil, string status){
    clear();

    cout<<"\n========================================================="<<endl;
    cout<<"=               DAFTAR MOBIL ("<<status<<")             ="<<endl;
    cout<<"========================================================="<<endl;

    cout<<left<<setw(12)<<"Plat"
        <<setw(25)<<"Nama Mobil"
        <<setw(12)<<"Harga"
        <<setw(15)<<"Status"<<endl;

    cout<<"========================================================="<<endl;
    
    bool found = false;
    for(int i=0;i<jumlahMobil;i++){
        if((mobil+i)->status==status){
            cout<<left<<setw(12)<<(mobil+i)->plat
                <<setw(25)<<(mobil+i)->nama
                <<setw(12)<<(mobil+i)->harga
                <<setw(15)<<(mobil+i)->status<<endl;
            found = true;
        }
    }
    
    if(!found) {
        cout<<"Tidak ada mobil dengan status tersebut."<<endl;
    }

    cout<<"========================================================="<<endl;

    cout<<"\nTekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void lihatMobilAdminSorted(Mobil *mobil, int &jumlahMobil){
    int pilihSort;
    do {
        clear();
        cout<<"\n========================================================="<<endl;
        cout<<"=                 MENU SORTING ADMIN                    ="<<endl;
        cout<<"========================================================="<<endl;
        cout<<"1. Lihat Semua (Tanpa Urutan Khusus)"<<endl;
        cout<<"2. Urutkan Nama Mobil (Descending / Z-A)"<<endl;
        cout<<"3. Urutkan Harga Mobil (Ascending / Murah-Mahal)"<<endl;
        cout<<"4. Kembali ke Menu Utama"<<endl;
        cout<<"Pilih : ";
        cin>>pilihSort;

        if(pilihSort == 1){
        } 
        else if(pilihSort == 2){
            urutkanNamaMobilDesc(mobil, jumlahMobil);
            cout << "\n[INFO] Mobil diurutkan berdasarkan Nama (Descending)\n";
        }
        else if(pilihSort == 3){
            urutkanHargaMobilAsc(mobil, jumlahMobil);
            cout << "\n[INFO] Mobil diurutkan berdasarkan Harga (Ascending)\n";
        }

        if(pilihSort >= 1 && pilihSort <= 3){
            cout<<"\n========================================================="<<endl;
            cout<<left<<setw(12)<<"Plat"
                <<setw(25)<<"Nama Mobil"
                <<setw(12)<<"Harga"
                <<setw(15)<<"Status"<<endl;
            cout<<"========================================================="<<endl;
            for(int i=0;i<jumlahMobil;i++){
                tampilkanSatuMobil(*(mobil+i));
            }
            cout<<"========================================================="<<endl;
            cout<<"Total Mobil : "<<jumlahMobil<<endl;
            cout<<"\nTekan Enter untuk kembali...";
            cin.ignore(1000,'\n');
            cin.get();
        }

    } while(pilihSort != 4);
}

void cariMobilFitur(Mobil *mobil, int jumlahMobil){
    clear();
    int tipeSearch;
    
    cout<<"\n==================================="<<endl;
    cout<<"=         PENCARIAN MOBIL         ="<<endl;
    cout<<"==================================="<<endl;
    cout<<"1. Cari berdasarkan NAMA (Linear Search)"<<endl;
    cout<<"2. Cari berdasarkan PLAT (Binary Search)"<<endl;
    cout<<"Pilih Metode: ";
    cin >> tipeSearch;
    cin.ignore(1000, '\n');

    if (tipeSearch == 1) {
        string keyword;
        cout<<"Masukkan kata kunci nama mobil : ";
        getline(cin, keyword);

        cout<<"\nHasil Pencarian Linear untuk '"<<keyword<<"':\n";
        cout<<"========================================================="<<endl;
        cout<<left<<setw(12)<<"Plat"
            <<setw(25)<<"Nama Mobil"
            <<setw(12)<<"Harga"
            <<setw(15)<<"Status"<<endl;
        cout<<"========================================================="<<endl;

        bool foundAny = false;
        for(int i=0; i<jumlahMobil; i++){
            if((mobil+i)->nama.find(keyword) != string::npos){
                tampilkanSatuMobil(*(mobil+i));
                foundAny = true;
            }
        }

        if(!foundAny){
            cout<<"Mobil tidak ditemukan."<<endl;
        }

    } else if (tipeSearch == 2) {
        string targetPlat;
        cout<<"Masukkan Plat Nomor tepat (Contoh: KT1234AA) : ";
        getline(cin, targetPlat);

        cout<<"\nMelakukan Binary Search untuk Plat '"<<targetPlat<<"'...\n";
        
        int index = cariMobilByPlatBinary(mobil, jumlahMobil, targetPlat);

        cout<<"========================================================="<<endl;
        cout<<left<<setw(12)<<"Plat"
            <<setw(25)<<"Nama Mobil"
            <<setw(12)<<"Harga"
            <<setw(15)<<"Status"<<endl;
        cout<<"========================================================="<<endl;

        if(index != -1) {
            tampilkanSatuMobil(*(mobil + index));
            cout<<"\n[INFO] Ditemukan pada index ke-" << index << " setelah pengurutan." << endl;
        } else {
            cout<<"Mobil dengan plat tersebut TIDAK DITEMUKAN."<<endl;
        }
    } else {
        cout<<"Pilihan tidak valid."<<endl;
    }

    cout<<"========================================================="<<endl;
    cout<<"\nTekan Enter...";
    cin.get();
}

void tambahMobil(Mobil *mobil, int &jumlahMobil){
    clear();

    cin.ignore(1000,'\n');
    cout<<"\n==================================="<<endl;
    cout<<"=          Tambah Mobil           ="<<endl;
    cout<<"==================================="<<endl;

    cout<<"Plat : ";
    getline(cin,(mobil+jumlahMobil)->plat);

    cout<<"Nama Mobil : ";
    getline(cin,(mobil+jumlahMobil)->nama);

    cout<<"Harga : ";
    cin>>(mobil+jumlahMobil)->harga;

    (mobil+jumlahMobil)->status="Tersedia";

    (mobil+jumlahMobil)->ptrPenyewa = &((mobil+jumlahMobil)->penyewa);

    jumlahMobil++;

    cout<<"Mobil berhasil ditambahkan\n";

    cout<<"Tekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void updateMobil(Mobil *mobil, int jumlahMobil){
    clear();

    string plat;
    cout<<"\n==================================="<<endl;
    cout<<"\n      Daftar Mobil Saat Ini      \n";
    cout<<"\n==================================="<<endl;
    for(int i=0;i<jumlahMobil;i++){
        cout<<(i+1)<<". "<<(mobil+i)->plat<<" - "<<(mobil+i)->nama<<endl;
    }

    cout<<"\nMasukkan plat mobil yang mau diupdate : ";
    cin>>plat;

    for(int i=0;i<jumlahMobil;i++){
        if((mobil+i)->plat==plat){

            cin.ignore(1000,'\n');

            cout<<"Nama baru : ";
            getline(cin,(mobil+i)->nama);

            cout<<"Harga baru : ";
            cin>>(mobil+i)->harga;

            cout<<"Status (Tersedia/Disewa): ";
            cin>>(mobil+i)->status;

            cout<<"Data berhasil diupdate\n";

            cout<<"Tekan Enter...";
            cin.ignore(1000,'\n');
            cin.get();

            return;
        }
    }

    cout<<"Mobil tidak ditemukan\n";

    cout<<"Tekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void hapusMobil(Mobil *mobil, int &jumlahMobil){
    clear();

    string plat;
    
    cout<<"\n==================================="<<endl;
    cout<<"\n      Daftar Mobil Saat Ini      \n";
    cout<<"\n==================================="<<endl;
    for(int i=0;i<jumlahMobil;i++){
        cout<<(i+1)<<". "<<(mobil+i)->plat<<" - "<<(mobil+i)->nama<<endl;
    }

    cout<<"\nMasukkan plat mobil yang mau dihapus : ";
    cin>>plat;

    for(int i=0;i<jumlahMobil;i++){
        if((mobil+i)->plat==plat){

            for(int j=i;j<jumlahMobil-1;j++){
                *(mobil+j)=*(mobil+j+1);
            }

            jumlahMobil--;

            cout<<"Mobil berhasil dihapus\n";

            cout<<"Tekan Enter...";
            cin.ignore(1000,'\n');
            cin.get();

            return;
        }
    }

    cout<<"Mobil tidak ditemukan\n";

    cout<<"Tekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void sewaMobil(Mobil *mobil, int jumlahMobil, string nama,string nim){
    clear();

    string plat;

    for(int i=0;i<jumlahMobil;i++){
        if((mobil+i)->ptrPenyewa->nama==nama && (mobil+i)->status=="Disewa"){
            cout<<"Anda masih menyewa mobil "<<(mobil+i)->nama<<endl;
            cout<<"Harap kembalikan mobil tersebut terlebih dahulu.\n";
            cout<<"Tekan Enter...";
            cin.ignore(1000,'\n');
            cin.get();
            return;
        }
    }
    cout<<"\n============================================================"<<endl;
    cout<<"\n                   Mobil Tersedia      \n";
    cout<<"\n============================================================"<<endl;
    cout<<left<<setw(12)<<"Plat"
        <<setw(25)<<"Nama Mobil"
        <<setw(12)<<"Harga"
        <<setw(15)<<"Status"<<endl;
    cout<<"\n============================================================"<<endl;
    for(int i=0;i<jumlahMobil;i++){
        if((mobil+i)->status == "Tersedia"){
             tampilkanSatuMobil(*(mobil+i));
        }
    }
    cout<<"\n============================================================"<<endl;
    cout<<"\nMasukkan plat mobil yang ingin disewa : ";
    cin>>plat;

    for(int i=0;i<jumlahMobil;i++){
        if((mobil+i)->plat==plat){

            if((mobil+i)->status=="Tersedia"){
                (mobil+i)->status="Disewa";
                (mobil+i)->ptrPenyewa->nama=nama;
                (mobil+i)->ptrPenyewa->nim=nim;
                cout<<"Mobil berhasil disewa\n";
            }else{
                cout<<"Mobil sedang disewa oleh orang lain\n";
            }

            cout<<"Tekan Enter...";
            cin.ignore(1000,'\n');
            cin.get();
            return;
        }
    }

    cout<<"Mobil tidak ditemukan\n";

    cout<<"Tekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void kembalikanMobil(Mobil *mobil, int jumlahMobil, string nama){
    clear();

    bool found = false;
    for(int i=0;i<jumlahMobil;i++){
        if((mobil+i)->ptrPenyewa->nama==nama && (mobil+i)->status=="Disewa"){
            (mobil+i)->status="Tersedia";
            (mobil+i)->ptrPenyewa->nama="";
            (mobil+i)->ptrPenyewa->nim="";
            cout<<"Mobil "<<(mobil+i)->nama<<" berhasil dikembalikan\n";
            found = true;
            
            cout<<"Tekan Enter...";
            cin.ignore(1000,'\n');
            cin.get();
            return;
        }
    }

    if(!found) {
        cout<<"Anda tidak sedang menyewa mobil apapun\n";
        cout<<"Tekan Enter...";
        cin.ignore(1000,'\n');
        cin.get();
    }
}

void menuAdmin(Mobil *mobil, int &jumlahMobil){
    int pilih;

    do{
        clear();
        cout<<"\n==================================="<<endl;
        cout<<"=             MENU ADMIN          ="<<endl;
        cout<<"==================================="<<endl;

        cout<<"1. Lihat & Urutkan Mobil (Sorting)\n";
        cout<<"2. Tambah Mobil\n";
        cout<<"3. Update Mobil\n";
        cout<<"4. Hapus Mobil\n";
        cout<<"5. Cari Mobil (Search Features)\n";
        cout<<"6. Logout\n";

        cout<<"Pilih : ";
        cin>>pilih;

        if(pilih==1) lihatMobilAdminSorted(mobil, jumlahMobil);
        else if(pilih==2) tambahMobil(mobil, jumlahMobil);
        else if(pilih==3) updateMobil(mobil, jumlahMobil);
        else if(pilih==4) hapusMobil(mobil, jumlahMobil);
        else if(pilih==5) cariMobilFitur(mobil, jumlahMobil);

    }while(pilih!=6);
}

void menuUser(Mobil *mobil, int jumlahMobil, string nama,string nim){
    int pilih;

    do{
        clear();
        cout<<"\n==================================="<<endl;
        cout<<"=             MENU USER           ="<<endl;
        cout<<"==================================="<<endl;

        cout<<"1. Lihat Mobil Tersedia\n";
        cout<<"2. Sewa Mobil\n";
        cout<<"3. Kembalikan Mobil\n";
        cout<<"4. Cari Mobil (Search Features)\n";
        cout<<"5. Logout\n";

        cout<<"Pilih : ";
        cin>>pilih;

        if(pilih==1) lihatMobil(mobil, jumlahMobil, "Tersedia");
        else if(pilih==2) sewaMobil(mobil, jumlahMobil, nama,nim);
        else if(pilih==3) kembalikanMobil(mobil, jumlahMobil, nama);
        else if(pilih==4) cariMobilFitur(mobil, jumlahMobil);

    }while(pilih!=5);
}

void registerUser(User users[], int &jumlahUser){
    clear();

    cin.ignore(1000,'\n');
    cout<<"\n==================================="<<endl;
    cout<<"=             REGISTER            ="<<endl;
    cout<<"==================================="<<endl;

    cout<<"Nama : ";
    getline(cin, users[jumlahUser].nama);

    cout<<"NIM : ";
    getline(cin, users[jumlahUser].nim);

    users[jumlahUser].role="user";
    jumlahUser++;

    cout<<"Register berhasil!\n";

    cout<<"Tekan Enter...";
    cin.get();
}

void login(User users[], int jumlahUser, Mobil *mobil, int &jumlahMobil){
    string nama,nim;
    int percobaan=0;

    while(percobaan<3){
        clear();
        cout<<"\n==================================="<<endl;
        cout<<"=             LOGIN               ="<<endl;
        cout<<"==================================="<<endl;

        cin.ignore(1000,'\n');

        cout<<"Nama : ";
        getline(cin,nama);

        cout<<"NIM : ";
        getline(cin,nim);

        for(int i=0;i<jumlahUser;i++){
            if(users[i].nama==nama && users[i].nim==nim){
                if(users[i].role=="admin")
                    menuAdmin(mobil, jumlahMobil);
                else
                    menuUser(mobil, jumlahMobil, nama,nim);
                return;
            }
        }

        percobaan++;
        cout<<"Login gagal! Sisa "<<3-percobaan<<endl;

        cout<<"Tekan Enter...";
        cin.get();
    }

    cout<<"Login gagal 3 kali\n";
    exit(0);
}

int main(){

    User users[100];
    Mobil mobil[100];

    int jumlahUser = 1;
    int jumlahMobil = 5;

    users[0]={"Aril","119","admin"};

    mobil[0]={"KT1234AA","Toyota Alphard",1500000,"Tersedia",{"",""}};
    mobil[1]={"DA5678BB","BMW i8",2500000,"Tersedia",{"",""}};
    mobil[2]={"KH8765CC","Mercedes Benz S-Class",2800000,"Tersedia",{"",""}};
    mobil[3]={"KB4321DD","Range Rover Evoque",2000000,"Tersedia",{"",""}};
    mobil[4]={"KU9999EE","Porsche Cayenne",3000000,"Tersedia",{"",""}};

    for(int i=0;i<jumlahMobil;i++){
        mobil[i].ptrPenyewa = &mobil[i].penyewa;
    }

    int menu;

    do{
        clear();
        cout<<"\n==================================="<<endl;
        cout<<"=       SISTEM RENTAL MOBIL       ="<<endl;
        cout<<"==================================="<<endl;

        cout<<"1. Login\n";
        cout<<"2. Register\n";
        cout<<"3. Keluar\n";

        cout<<"Pilih : ";
        cin>>menu;

        if(menu==1) login(users, jumlahUser, mobil, jumlahMobil);
        else if(menu==2) registerUser(users, jumlahUser);

    }while(menu!=3);

    cout<<"Terima kasih sudah menggunakan program saya !!\n";
}
