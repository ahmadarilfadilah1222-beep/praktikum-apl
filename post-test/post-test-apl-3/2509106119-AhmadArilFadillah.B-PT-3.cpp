#include <iostream>
#include <iomanip>
#include <cstdlib>
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
};

int hitungMobil(int n){
    if(n==0) return 0;
    return 1 + hitungMobil(n-1);
}

void lihatMobil(Mobil mobil[], int jumlahMobil){
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
        cout<<left<<setw(12)<<mobil[i].plat
            <<setw(25)<<mobil[i].nama
            <<setw(12)<<mobil[i].harga
            <<setw(15)<<mobil[i].status<<endl;
    }

    cout<<"========================================================="<<endl;
    cout<<"Total Mobil : "<<hitungMobil(jumlahMobil)<<endl;

    cout<<"\nTekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void lihatMobil(Mobil mobil[], int jumlahMobil, string status){
    clear();

    cout<<"\n========================================================="<<endl;
    cout<<"=           DAFTAR MOBIL ("<<status<<")              ="<<endl;
    cout<<"========================================================="<<endl;

    cout<<left<<setw(12)<<"Plat"
        <<setw(25)<<"Nama Mobil"
        <<setw(12)<<"Harga"
        <<setw(15)<<"Status"<<endl;

    cout<<"========================================================="<<endl;

    for(int i=0;i<jumlahMobil;i++){
        if(mobil[i].status==status){
            cout<<left<<setw(12)<<mobil[i].plat
                <<setw(25)<<mobil[i].nama
                <<setw(12)<<mobil[i].harga
                <<setw(15)<<mobil[i].status<<endl;
        }
    }

    cout<<"========================================================="<<endl;

    cout<<"\nTekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void tambahMobil(Mobil mobil[], int &jumlahMobil){
    clear();

    cin.ignore(1000,'\n');
    cout<<"\n==================================="<<endl;
    cout<<"=          Tambah Mobil           ="<<endl;
    cout<<"==================================="<<endl;

    cout<<"Plat : ";
    getline(cin,mobil[jumlahMobil].plat);

    cout<<"Nama Mobil : ";
    getline(cin,mobil[jumlahMobil].nama);

    cout<<"Harga : ";
    cin>>mobil[jumlahMobil].harga;

    mobil[jumlahMobil].status="Tersedia";
    jumlahMobil++;

    cout<<"Mobil berhasil ditambahkan\n";

    cout<<"Tekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void updateMobil(Mobil mobil[], int jumlahMobil){
    clear();

    string plat;

    lihatMobil(mobil, jumlahMobil);

    cout<<"\nMasukkan plat mobil : ";
    cin>>plat;

    for(int i=0;i<jumlahMobil;i++){
        if(mobil[i].plat==plat){

            cin.ignore(1000,'\n');

            cout<<"Nama baru : ";
            getline(cin,mobil[i].nama);

            cout<<"Harga baru : ";
            cin>>mobil[i].harga;

            cout<<"Status (Tersedia/Disewa): ";
            cin>>mobil[i].status;

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

void hapusMobil(Mobil mobil[], int &jumlahMobil){
    clear();

    string plat;

    lihatMobil(mobil, jumlahMobil);

    cout<<"\nMasukkan plat mobil : ";
    cin>>plat;

    for(int i=0;i<jumlahMobil;i++){
        if(mobil[i].plat==plat){

            for(int j=i;j<jumlahMobil-1;j++){
                mobil[j]=mobil[j+1];
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

void sewaMobil(Mobil mobil[], int jumlahMobil, string nama,string nim){
    clear();

    string plat;

    for(int i=0;i<jumlahMobil;i++){
        if(mobil[i].penyewa.nama==nama){
            cout<<"Anda masih menyewa mobil "<<mobil[i].nama<<endl;
            cout<<"Tekan Enter...";
            cin.ignore(1000,'\n');
            cin.get();
            return;
        }
    }

    lihatMobil(mobil, jumlahMobil, "Tersedia");

    cout<<"\nMasukkan plat mobil : ";
    cin>>plat;

    for(int i=0;i<jumlahMobil;i++){
        if(mobil[i].plat==plat){

            if(mobil[i].status=="Tersedia"){
                mobil[i].status="Disewa";
                mobil[i].penyewa.nama=nama;
                mobil[i].penyewa.nim=nim;
                cout<<"Mobil berhasil disewa\n";
            }else{
                cout<<"Mobil sedang disewa\n";
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

void kembalikanMobil(Mobil mobil[], int jumlahMobil, string nama){
    clear();

    for(int i=0;i<jumlahMobil;i++){
        if(mobil[i].penyewa.nama==nama){
            mobil[i].status="Tersedia";
            mobil[i].penyewa.nama="";
            mobil[i].penyewa.nim="";
            cout<<"Mobil berhasil dikembalikan\n";

            cout<<"Tekan Enter...";
            cin.ignore(1000,'\n');
            cin.get();
            return;
        }
    }

    cout<<"Anda tidak menyewa mobil\n";

    cout<<"Tekan Enter...";
    cin.ignore(1000,'\n');
    cin.get();
}

void menuAdmin(Mobil mobil[], int &jumlahMobil){
    int pilih;

    do{
        clear();
        cout<<"\n==================================="<<endl;
        cout<<"=             MENU ADMIN          ="<<endl;
        cout<<"==================================="<<endl;

        cout<<"1. Lihat Mobil\n";
        cout<<"2. Tambah Mobil\n";
        cout<<"3. Update Mobil\n";
        cout<<"4. Hapus Mobil\n";
        cout<<"5. Logout\n";

        cout<<"Pilih : ";
        cin>>pilih;

        if(pilih==1) lihatMobil(mobil, jumlahMobil);
        else if(pilih==2) tambahMobil(mobil, jumlahMobil);
        else if(pilih==3) updateMobil(mobil, jumlahMobil);
        else if(pilih==4) hapusMobil(mobil, jumlahMobil);

    }while(pilih!=5);
}

void menuUser(Mobil mobil[], int jumlahMobil, string nama,string nim){
    int pilih;

    do{
        clear();
        cout<<"\n==================================="<<endl;
        cout<<"=             MENU USER           ="<<endl;
        cout<<"==================================="<<endl;

        cout<<"1. Lihat Mobil\n";
        cout<<"2. Sewa Mobil\n";
        cout<<"3. Kembalikan Mobil\n";
        cout<<"4. Logout\n";

        cout<<"Pilih : ";
        cin>>pilih;

        if(pilih==1) lihatMobil(mobil, jumlahMobil, "Tersedia");
        else if(pilih==2) sewaMobil(mobil, jumlahMobil, nama,nim);
        else if(pilih==3) kembalikanMobil(mobil, jumlahMobil, nama);

    }while(pilih!=4);
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

void login(User users[], int jumlahUser, Mobil mobil[], int &jumlahMobil){
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