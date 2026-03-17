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

int main(){

    User users[100];
    Mobil mobil[100];

    int jumlahUser = 1;
    int jumlahMobil = 5;

    // DATA AWAL
    users[0] = {"Aril","119","admin"};

    mobil[0]={"KT1234AA","Toyota Alphard",1500000,"Tersedia",{"",""}};
    mobil[1]={"DA5678BB","BMW i8",2500000,"Tersedia",{"",""}};
    mobil[2]={"KH8765CC","Mercedes Benz S-Class",2800000,"Tersedia",{"",""}};
    mobil[3]={"KB4321DD","Range Rover Evoque",2000000,"Tersedia",{"",""}};
    mobil[4]={"KU9999EE","Porsche Cayenne",3000000,"Tersedia",{"",""}};

    int menu;

    do{
        clear();
        cout<<"\n===== SISTEM RENTAL MOBIL =====\n";
        cout<<"1. Login\n";
        cout<<"2. Register\n";
        cout<<"3. Keluar\n";
        cout<<"Pilih: ";
        cin>>menu;

        if(menu==2){
            cin.ignore();
            cout<<"Nama: ";
            getline(cin, users[jumlahUser].nama);
            cout<<"NIM: ";
            getline(cin, users[jumlahUser].nim);
            users[jumlahUser].role="user";
            jumlahUser++;

            cout<<"Register berhasil!\n";
            cin.get();
        }

        else if(menu==1){

            string nama,nim;
            int percobaan=0;
            bool loginSukses=false;

            while(percobaan<3){
                cin.ignore();
                cout<<"Nama: ";
                getline(cin,nama);
                cout<<"NIM: ";
                getline(cin,nim);

                for(int i=0;i<jumlahUser;i++){
                    if(users[i].nama==nama && users[i].nim==nim){

                        loginSukses=true;

                        // ===== MENU ADMIN =====
                        if(users[i].role=="admin"){
                            int pilih;
                            do{
                                clear();
                                cout<<"\n=== MENU ADMIN ===\n";
                                cout<<"1. Lihat Mobil\n";
                                cout<<"2. Tambah Mobil\n";
                                cout<<"3. Hapus Mobil\n";
                                cout<<"4. Logout\n";
                                cout<<"Pilih: ";
                                cin>>pilih;

                                if(pilih==1){
                                    cout<<"\nDAFTAR MOBIL\n";
                                    for(int j=0;j<jumlahMobil;j++){
                                        cout<<mobil[j].plat<<" - "
                                            <<mobil[j].nama<<" - "
                                            <<mobil[j].harga<<" - "
                                            <<mobil[j].status<<endl;
                                    }
                                    cin.ignore();
                                    cin.get();
                                }

                                else if(pilih==2){
                                    cin.ignore();
                                    cout<<"Plat: ";
                                    getline(cin,mobil[jumlahMobil].plat);
                                    cout<<"Nama: ";
                                    getline(cin,mobil[jumlahMobil].nama);
                                    cout<<"Harga: ";
                                    cin>>mobil[jumlahMobil].harga;
                                    mobil[jumlahMobil].status="Tersedia";
                                    jumlahMobil++;
                                }

                                else if(pilih==3){
                                    string plat;
                                    cout<<"Plat: ";
                                    cin>>plat;

                                    for(int j=0;j<jumlahMobil;j++){
                                        if(mobil[j].plat==plat){
                                            for(int k=j;k<jumlahMobil-1;k++){
                                                mobil[k]=mobil[k+1];
                                            }
                                            jumlahMobil--;
                                            break;
                                        }
                                    }
                                }

                            }while(pilih!=4);
                        }

                        // ===== MENU USER =====
                        else{
                            int pilih;
                            do{
                                clear();
                                cout<<"\n=== MENU USER ===\n";
                                cout<<"1. Lihat Mobil\n";
                                cout<<"2. Sewa Mobil\n";
                                cout<<"3. Kembalikan Mobil\n";
                                cout<<"4. Logout\n";
                                cout<<"Pilih: ";
                                cin>>pilih;

                                if(pilih==1){
                                    for(int j=0;j<jumlahMobil;j++){
                                        cout<<mobil[j].plat<<" - "
                                            <<mobil[j].nama<<" - "
                                            <<mobil[j].status<<endl;
                                    }
                                    cin.ignore();
                                    cin.get();
                                }

                                else if(pilih==2){
                                    string plat;
                                    cout<<"Plat: ";
                                    cin>>plat;

                                    for(int j=0;j<jumlahMobil;j++){
                                        if(mobil[j].plat==plat && mobil[j].status=="Tersedia"){
                                            mobil[j].status="Disewa";
                                            mobil[j].penyewa.nama=nama;
                                            mobil[j].penyewa.nim=nim;
                                        }
                                    }
                                }

                                else if(pilih==3){
                                    for(int j=0;j<jumlahMobil;j++){
                                        if(mobil[j].penyewa.nama==nama){
                                            mobil[j].status="Tersedia";
                                            mobil[j].penyewa={"",""};
                                        }
                                    }
                                }

                            }while(pilih!=4);
                        }

                        break;
                    }
                }

                if(loginSukses) break;

                percobaan++;
                cout<<"Login gagal!\n";
            }
        }

    }while(menu!=3);

    cout<<"Terima kasih!\n";
}