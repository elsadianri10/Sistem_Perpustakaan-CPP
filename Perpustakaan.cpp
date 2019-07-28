#include <iostream> //Include Library Iostream
#include <string> //Include Library String
#include <conio.h> //Include Library Conih.h
#include <fstream> //Include Library Fstream (Input & Output Ke atau Dari File)
#include <cstdlib> //Include Library Cstdlib
using namespace std;

//Deklarasi Untuk Pemanggilan Modul - Begin
void input();
void inputbuku();
void inputpinjam();
void inputkembali();

void cari();
void caribuku();
void caripinjam();
void carikembali();

void showbuku();
void showpinjam();
void showkembali();

void menuawal();
void keluar();
//Deklarasi Untuk Pemanggilan Modul - End
 
int main() // Main
{
    system("title Sistem Perpustakaan By : Elsa Diana Putri "); // Ngerubah Title Saat Di Running
    system("cls");
    system("color F0"); // Ngerubah Warna Tampilan CLI
   	cout<<"      ||===================================================================||"<<endl;
	cout<<"        \t\t      SYSTEM PERPUSTAKAAN "<<endl;
	cout<<"      ||===================================================================||"<<endl;
	cout<<endl<<endl<<"Silahkan Tekan Apa Saja Untuk Lanjut"<<endl;
    cin.get();
    menuawal();
}
void menuawal(){
    system("cls");
        int choice; // Deklarasi pilihan
        cout<<"             Sistem Informasi Perpustakaan               "<<endl;
    cout<<"1.Input Data"<<endl;
    cout<<"2.Cari Data"<<endl;
    cout<<"3.Keluar"<<endl;
    cout<<"Silahkan Pilih Menu [1-3] : ";
    cin>>choice;
    switch (choice){
        case 1:
            input(); //Memanggil Modul Input
            break;
        case 2:
            cari(); //Memanggil Modul Cari
            break;
        case 3:
            keluar(); //Memanggil Modul Keluar
            break;
    }
}
//Modul Untuk Ngerubah Spasi Kebentuk Underscore Agar Bisa Disimpan di Database - Begin
string space2underscore(string text) {
    for(string::iterator it = text.begin(); it != text.end(); ++it) {
        if(*it == ' ') {
            *it = '_';
        }
    }
    return text;
}
string underscore2space(string text) {
    for(string::iterator it = text.begin(); it != text.end(); ++it) {
        if(*it == '_') {
            *it = ' ';
        }
    }
    return text;
}
//Modul Untuk Ngerubah Spasi Kebentuk Underscore Agar Bisa Disimpan di Database - Begin

void input() //Modul Input
{
    int choice2; //Deklarasi Pilihan
    system("cls");
    cout<<"1.Input Peminjaman"<<endl;
    cout<<"2.Input Pengembalian"<<endl;
    cout<<"3.Input Buku"<<endl;
    cout<<"4.Kembali Ke Awal"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Pilih Menu Diatas [1-5] : ";
    cin>>choice2;
    switch (choice2){
    
        case 1:
            inputpinjam(); //Memanggil Modul inputpinjam
            break;;
        case 2:
            inputkembali(); //Memanggil Modul inputkembali
            break;
        case 3:
            inputbuku(); //Memanggil Modul inputbuku
            break;
        case 4:
            menuawal(); //Memanggil Modul menuawal (Kembali ke Menu Awal)
            break;
        case 5:
            keluar(); //Memanggil Modul Keluar
            break;
    }
}

void inputbuku() //Modul Input Buku
{
    ofstream databaru("bukuDB.txt", ios::app);
    system("cls");
    int n;
    cout<<"Masukkan Banyak Data :";
    cin>>n;
    string nama[n],pengarang[n];
    int id[n];
    for (int i=0;i<n;i++){
    cout<<"Masukkan Nama Buku Ke-"<<i+1<<" : ";
    cin.ignore();
    getline(cin, nama[i]);
    nama[i] = space2underscore(nama[i]);
    system("cls");
    cout<<"Masukkan ID Buku Ke-"<<i+1<<" : ";
    cin>>id[i];
    system("cls");
    cout<<"Masukkan Pengarang Buku Ke-"<<i+1<<" : ";
    cin.ignore();
    getline(cin, pengarang[i]);
    pengarang[i] = space2underscore(pengarang[i]);     
    databaru<<nama[i]<<' '<<id[i]<<' '<<pengarang[i]<<endl;
    }
    databaru.close();
    system("cls");
        cout<<"Input Buku Success"<<endl;
        system("pause");
    menuawal();
 
}
void inputpinjam() //Modul Input Peminjaman
{
    ofstream databaru("pinjamDB.txt", ios::app);
    system("cls");
    string nama,tp,tk;
    int id_buku,id_anggota,id_pinjam;
    cout<<"Masukkan NIM Peminjam : ";
    cin>>id_anggota;
    system("cls");
    cout<<"Masukkan ID Buku :";
    cin>>id_buku;  
    system("cls");
    cout<<"Masukkan ID Peminjaman :";
    cin>>id_pinjam;
    system("cls");
    cout<<"Masukkan Tanggal Peminjaman [dd-mm-yyyy] : ";
    cin>>tp;
    cout<<"Masukkan Tanggal Pengembalian  [dd-mm-yyyy] : ";
    cin>>tk;
    system("cls");
    databaru<<id_anggota<<' '<<id_buku<<' '<<id_pinjam<<' '<<tp<<' '<<tk<<endl;
    databaru.close();
    system("cls");
    cout<<"Input Peminjaman Success"<<endl;
        system("pause");
    menuawal();
}
//Fungsi Merubah Tanggal menjadi Integer
int rdn(int y, int m, int d) {
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
void inputkembali() //Modul Input Pengembalian
{
    ofstream databaru("kembaliDB.txt", ios::app);
    system("cls");
    string nama,th,tp,tk;
    int id_pinjaman,selisih,id_anggota,id_buku,id_pinjam;
    cout<<"Masukkan ID Peminjaman :";
    cin>>id_pinjaman;
    system("cls");
    cout<<"Masukkan Tanggal Pengembalian (Hari Ini) [dd-mm-yyyy] : ";
    cin>>th;
    system("cls");
 
    databaru<<id_pinjaman<<' '<<th<<endl;
    databaru.close();
    ifstream ambiltgl("pinjamDB.txt"); //Ifstream : Fungsi Untuk Membaca File
        while(ambiltgl>>id_anggota>>id_buku>>id_pinjam>>tp>>tk){
        if (id_pinjaman == id_pinjam){
            system("cls");
            int tglh = atoi(th.substr(0,2).c_str()); //Memecah String Untuk Mengambil Tanggal Hari Ini
            int bulh = atoi(th.substr(3,2).c_str()); //Memecah String Untuk Mengambil Bulan Hari Ini
            int tahh = atoi(th.substr(7,4).c_str()); //Memecah String Untuk Mengambil Tahun Hari Ini
            int tglk = atoi(tk.substr(0,2).c_str()); //Memecah String Untuk Mengambil Tanggal Kembali
            int bulk = atoi(tk.substr(3,2).c_str()); //Memecah String Untuk Mengambil Bulan Kembali
            int tahk = atoi(tk.substr(7,4).c_str()); //Memecah String Untuk Mengambil Tahun Kembali
            int selisihk = rdn(tahh, bulh, tglh) - rdn(tahk, bulk, tglk); //Menghitung Selisih Hari
            if (selisihk >= 1)
            {
                int denda = selisihk*2000; //Denda 2000 / Hari
                            cout<<"Pengembalian Buku Selesai"<<endl;
            cout<<"==================="<<endl;
            cout<<"ID Peminjaman : "<<id_pinjaman<<endl;
            cout<<"Total Hari Telat Pengembalian : "<<selisihk<<endl;
            cout<<"Total Denda Yang Harus Dibayar : "<<denda<<endl;
            cout<<"==================="<<endl;
            }else{
                int denda = 0;
                            cout<<"Pengembalian Buku Selesai"<<endl;
            cout<<"==================="<<endl;
            cout<<"ID Peminjaman : "<<id_pinjaman<<endl;
            cout<<"Total Hari Telat Pengembalian : "<<selisihk<<endl;
            cout<<"Total Denda Yang Harus Dibayar : "<<denda<<endl;
            cout<<"==================="<<endl;
            }
        }
    }
    while(ambiltgl >> id_pinjam){ //Jika Ga Nemu ID Nya
        if (id_pinjaman != id_pinjam){
            system("cls");
            cout<<"Ga Nemu"<<endl;
        }
    }
    system("pause");
    menuawal();
}

void caribuku() //Modul Cari Buku
{
    ifstream caridata("bukuDB.txt");
    string pengarang,nama;
    int id;
    int fbuku;
    system("cls");
    cout<<"Masukkan ID Buku : ";
    cin>>fbuku;
    while(caridata>>nama>>id>>pengarang){
        if (fbuku == id){
            system("cls");
            cout<<"Data Ditemukan"<<endl;
            cout<<"NAMA"<<' '<<"                NIM     "<<"PENGARANG   "<<' '<<endl;
            cout<<"---------------------------------------------------------------------------"<<endl;
            cout<<underscore2space(nama)<<"\t\t"<<id<<"\t\t"<<underscore2space(pengarang)<<endl;
        }
    }
    while(caridata >> id){
        if (fbuku != id){
            system("cls");
            cout<<"Data TIdak ada"<<endl;
        }
    }
    system("pause");
    menuawal();
}
void caripinjam() //Modul Cari Pinjaman
{
    ifstream caridata("pinjamDB.txt");
    string tp,tk;
    int id,nim,id_buku;
    int cid;
    system("cls");
    cout<<"Masukkan ID Peminjaman : ";
    cin>>cid;
    while(caridata>>nim>>id_buku>>id>>tp>>tk){
        if (cid == id){
            system("cls");
            cout<<"Data Ditemukan"<<endl;
            cout<<"NIM Anggota"<<' '<<"ID Buku"<<' '<<"Id Peminjaman"<<' '<<"Tanggal Pinjam"<<' '<<"    Tanggal Janji Kembali   "<<' '<<endl;
            cout<<"----------------------------------------------------------------------"<<endl;
            cout<<nim<<"\t"<<id_buku<<"\t"<<id<<"\t"<<tp<<"\t"<<tk<<"\t"<<endl;
        }
    }
    while(caridata >> id){
        if (cid != id){
            system("cls");
            cout<<"Data TIdak ada"<<endl;
        }
    }
    system("pause");
    menuawal();
}
void carikembali() //Modul Cari Pengembalian
{
    ifstream caridata("kembaliDB.txt");
    string tk;
    int id;
    int fkembali;
    system("cls");
    cout<<"Masukkan ID Peminjaman : ";
    cin>>fkembali;
    while(caridata>>id>>tk){
        if (fkembali == id){
            system("cls");
            cout<<"Data Ditemukan"<<endl;
            cout<<"ID Peminjaman"<<' '<<"   Tanggal Pengembalian"<<' '<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<id<<"\t"<<"\t"<<tk<<endl;
        }
    }
    while(caridata >> id){
        if (fkembali != id){
            system("cls");
            cout<<"Data TIdak ada"<<endl;
        }
    }
    system("pause");
    menuawal();
}
void keluar(){ //Modul Keluar
    system("cls");
    cout<<"Terima Kasih Telah Menggunakan SIP [ SISTEM INFORMASI PERPUSTAKAAN ]"<<endl;
    cin.get();
}
void showbuku(){ //Modul Menampilkan Semua Data Buku
    ifstream caridata("bukuDB.txt");
    int id;
    string nama,pengarang;
    system("cls");
            cout<<"Show All Data"<<endl;
            cout<<"NAMA"<<' '<<"                NIM     "<<"PENGARANG   "<<' '<<endl;
            cout<<"---------------------------------------------------------------------------"<<endl;
    while(caridata>>nama>>id>>pengarang){
cout<<underscore2space(nama)<<"\t\t"<<id<<"\t\t"<<underscore2space(pengarang)<<endl;
    }
    system("pause");
    cin.get();
    menuawal();
}
void showpinjam(){ //Modul Menampilkan Semua Data Pinjaman
    ifstream caridata("pinjamDB.txt");
    int nim,id,id_buku;
    string tp,tk;
    system("cls");
            cout<<"Show All Data"<<endl;
            cout<<"NIM Anggota"<<' '<<"ID Pinjaman"<<' '<<"Id Buku"<<' '<<"Tanggal Pinjam"<<' '<<"  Tanggal Janji Kembali   "<<' '<<endl;
            cout<<"----------------------------------------------------------------------"<<endl;
    while(caridata>>nim>>id>>id_buku>>tp>>tk){
            cout<<nim<<"\t"<<id<<"\t"<<id_buku<<"\t"<<tp<<"\t"<<tk<<"\t"<<endl;
    }
    system("pause");
    cin.get();
    menuawal();
}
void showkembali(){ //Modul Menampilkan Semua Data Pengembalian
    ifstream caridata("kembaliDB.txt");
    int id;
    string tk;
    system("cls");
            cout<<"Data Ditemukan"<<endl;
            cout<<"ID Peminjaman"<<' '<<"   Tanggal Pengembalian"<<' '<<endl;
            cout<<"-----------------------------------"<<endl;;
    while(caridata>>id>>tk){
        cout<<id<<"\t"<<"\t"<<tk<<endl;
    }
    system("pause");
    cin.get();
    menuawal();
}
void cari() //Modul Pencarian dan Tampilkan Semua
{
    int choice2;
    system("cls");
    cout<<"1.Cari Buku"<<endl;
    cout<<"2.Cari Data Peminjaman"<<endl;
    cout<<"3.Cari Data Pengembalian"<<endl;
    cout<<"4.Tampilkan Data Buku"<<endl;
    cout<<"5.Tampilkan Data Peminjaman"<<endl;
    cout<<"6.Tampilkan Data Pengembalian"<<endl;
    cout<<"7.Menu Awal"<<endl;
	cout<<"8.Exit"<<endl;
    cout<<"Pilih Menu Diatas [1-8] : ";
    cin>>choice2;
    switch (choice2){
        case 1:
            caribuku(); //Panggil Modul
            break;;
        case 2:
            caripinjam(); //Panggil Modul
            break;
        case 3:
            carikembali(); //Panggil Modul
            break;
        case 4:
            showbuku(); //Panggil Modul
            break;
        case 5:
            showpinjam(); //Panggil Modul
            break;
        case 6:
            showkembali(); //Panggil Modul
            break; 
        case 7:
            menuawal(); //Memanggil Modul menuawal (Kembali ke Menu Awal)
            break;
        case 8:
            keluar(); //Panggil Modul
            break;
        default:
            menuawal(); //Panggil Modul
            break;
    }
}
