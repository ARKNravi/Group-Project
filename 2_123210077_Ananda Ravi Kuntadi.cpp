#include <iostream>
#include <fstream>
using namespace std;

char kembali;

typedef struct
{
	string nomorpendaftaran ;
	string nama;
    string umur;
	string jeniskelamin;
	string kabupaten;
	string golongan;
	string tahap;
	string suhu;
	string riwayat;
	
}masyarakat;

void haldepan();
void menuatas();
void menubawah();
void menuutama();
void daftar(fstream &dataorang, fstream &jumlah, int jumlahorang);
void sorting(fstream &dataorang, fstream &jumlah, int jumlahorang);
void updatetahap(fstream &dataorang, fstream &jumlah, int jumlahorang);

int main()
{
    int jumlahorang, pilih;
    fstream dataorang, jumlah;

    haldepan();

	do {
	system("CLS");

	jumlah.open("jumlahorang.txt");
	jumlah >> jumlahorang;
	jumlah.close();
	
    menuatas();
	menuutama();
	cout << "\nMasukkan Pilihan  : ";
	cin >> pilih;
	if (pilih == 1){
		system("CLS");
		daftar(dataorang, jumlah, jumlahorang);
	}
	else if (pilih == 2) {
		system("CLS");
		updatetahap(dataorang, jumlah, jumlahorang);
	}
	else if (pilih == 3) {
		system("CLS");
		sorting(dataorang, jumlah, jumlahorang);
	}
	else if (pilih == 4) {
		exit(0);
	}
    menubawah();
	} while (kembali == 'y' || kembali == 'Y');   
}

void haldepan()
{
    cout << " =============================================================" << endl;
    cout << "|                                                             |" << endl;
    cout << "|                PROGRAM VAKSINASI COVID-19                   |" << endl;
    cout << "|                (Jenis vaksin : Sinovac)                     |" << endl;
    cout << "|                                                             |" << endl;
    cout << "| ----------------------------------------------------------- |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|     Universitas Pembangunan Nasional Veteran Yogyakarta     |" << endl;
    cout << "|                                                             |" << endl;
    cout << " =============================================================" << endl;
    cout << endl;
	system("PAUSE");
	system("CLS");
}
    
void menuatas()
{
    cout << " _____________________________________________________________" << endl;
    cout << "    Universitas Pembangunan Nasional Veteran Yogyakarta" << endl;
    cout << " =============================================================" << endl;
}

void menubawah()
{
    cout << endl;
    cout << "=============================================================" << endl;
    cout << " Kembali ke Menu Utama? (y/n) : "; cin >> kembali;
	system("CLS");
}

void menuutama()
{
	cout << "              MENU UTAMA PROGRAM VAKSINASI COVID-19";
    cout << "\n ------------------------------------------------------------- \n";
	cout << "\n1. PENDAFTARAN";
	cout << "\n2. UPDATE TAHAP";
	cout << "\n3. TAMPILKAN DATA";
	cout << "\n4. EXIT";
}

void daftar(fstream &dataorang, fstream &jumlah, int jumlahorang)
{
    system("CLS");

	masyarakat daftar;

	menuatas();
	cout << "            daftar DATA PROGRAM VAKSINASI COVID-19";
	cout << "\n ------------------------------------------------------------- \n";

    cout << "Golongan 1 : Dosen\n";
    cout << "Golongan 2 : Orang dengan penyakit berat\n";
    cout << "Golongan 3 : Mahasiswa\n";
    cout << "Golongan 4 : Staff\n";
	cout << " ------------------------------------------------------------- \n";

	cin.ignore();
	cout << "\nNomor Pendaftaran       = ";
	getline(cin, daftar.nomorpendaftaran );
	cout << "        Nama            = ";
	getline(cin, daftar.nama);
    cout << "        Umur            = ";
    getline(cin, daftar.umur);
	cout << "        Jenis Kelamin   = ";
    getline(cin, daftar.jeniskelamin);
	cout << "        Kabupaten       = ";
	getline(cin, daftar.kabupaten);
	cout << "        Golongan        = ";
	getline(cin, daftar.golongan);
	cout << endl;
	jumlahorang++;
	daftar.tahap = "1";

	cout << "Selamat, anda telah terdaftar!";
	cout << "\nDiharuskan bagi anda untuk mengisi tes kesehatan terlebih dahulu.";
	cout << endl;
	cout << "        Suhu tubuh            = ";
	getline(cin, daftar.suhu);
    cout << "        Riwayat penyakit      = ";
    getline(cin, daftar.riwayat);
	
	dataorang.open("dataorang.txt", ios::app | ios::out);
		dataorang << daftar.nomorpendaftaran  << endl;
		dataorang << daftar.nama << endl;
        dataorang << daftar.umur << endl;
		dataorang << daftar.jeniskelamin << endl;
		dataorang << daftar.kabupaten << endl;
		dataorang << daftar.golongan << endl;
		dataorang << daftar.tahap << endl;
		dataorang << daftar.suhu << endl;
		dataorang << daftar.riwayat << endl;
	dataorang.close();

	jumlah.open("jumlahorang.txt", ios::out | ios::trunc);
	jumlah << jumlahorang;
	jumlah.close();

	cout << "\nBerhasil ditambahkan.\n";
}

void updatetahap(fstream &dataorang, fstream &jumlah, int jumlahorang)
{

	system("CLS");

	masyarakat update[jumlahorang];

	int ubahtahap;
	bool found = false;
    int ubah;
	string cari;

	dataorang.open("dataorang.txt");
	for (int i = 0; i < jumlahorang; i++)
	{
		getline(dataorang, update[i].nomorpendaftaran );
		getline(dataorang, update[i].nama);
		getline(dataorang, update[i].umur);
		getline(dataorang, update[i].jeniskelamin);
		getline(dataorang, update[i].kabupaten);
		getline(dataorang, update[i].golongan);
		getline(dataorang, update[i].tahap);
		getline(dataorang, update[i].suhu);
		getline(dataorang, update[i].riwayat);
	}
	dataorang.close();

	menuatas();
	cout << "             MENCARI DATA PESERTA VAKSIN COVID-19" << endl;
	cout << " =============================================================" << endl;
	cout << endl;

	cin.ignore();
	cout << "Cari Nomor Pendaftaran  Peserta = ";
	getline(cin, cari);

    // updatetahap
    for (int i = 0; i < jumlahorang; i++)
    {
        if(update[i].nomorpendaftaran  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
		cout << "\n INFORMASI DATA PESERTA VAKSIN COVID-19" << endl;
		cout << " -------------------------------------------------------------" << endl;
				cout << "Nomor Pendaftaran = " << update[ubah].nomorpendaftaran  << endl;
            	cout << "Nama Peserta      = " << update[ubah].nama << endl;
				cout << "Umur              = " << update[ubah].umur << endl;
				cout << "Jenis Kelamin     = " << update[ubah].jeniskelamin << endl;
				cout << "Kabupaten         = " << update[ubah].kabupaten << endl;
				cout << "Golongan          = " << update[ubah].golongan << endl;
				cout << "Tahap             = " << update[ubah].tahap << endl;
				cout << "Suhu tubuh        = " << update[ubah].suhu << endl;
				cout << "Riwayat penyakit  = " << update[ubah].riwayat << endl;
				
		cout << "\n Data Apa Yang ingin diubah ? : \n";
		cout<<" 1. Nama Peserta\n";
		cout<<" 2. Umur\n";
		cout<<" 3. Jenis Kelamin\n";
		cout<<" 4. Kabupaten\n";
		cout<<" 5. Tahap menjadi tahap 2\n";
		cout<<" Pilih no :";
		cin >> ubahtahap;

		if (ubahtahap == 1){
			cin.ignore();
			cout<< "Nama Peserta diubah menjadi : ";
			getline(cin, update[ubah].nama);
			}
		else if (ubahtahap == 2){
			cin.ignore();
			cout<< "Umur diubah menjadi : ";
			getline(cin, update[ubah].umur);
			}
		else if (ubahtahap == 3){
			cin.ignore();
			cout<< "Jenis Kelamin diubah menjadi : ";
			getline(cin, update[ubah].jeniskelamin);
			}
		else if (ubahtahap == 4){
			cin.ignore();
			cout<< "Kabupaten diubah menjadi : ";
			getline(cin, update[ubah].kabupaten);
			}
		else if (ubahtahap == 5){
			cin.ignore();
			update[ubah].tahap = "2";
			}
        	dataorang.open("dataorang.txt", ios::trunc | ios::out);
			for (int i = 0; i < jumlahorang; i++)
			{
				dataorang << update[i].nomorpendaftaran  << endl;
				dataorang << update[i].nama << endl;
				dataorang << update[i].umur << endl;
				dataorang << update[i].jeniskelamin << endl;
				dataorang << update[i].kabupaten << endl;
				dataorang << update[i].golongan << endl;
				dataorang << update[i].tahap << endl;
				dataorang << update[i].suhu << endl;
				dataorang << update[i].riwayat << endl;
			}
			dataorang.close();

			cout << "\nData berhasil dirubah !" << endl;
            cout << "Nomor Pendaftaran = " << update[ubah].nomorpendaftaran  << endl;
        	cout << "Nama Peserta      = " << update[ubah].nama << endl;
			cout << "Umur              = " << update[ubah].umur << endl;
			cout << "Jenis Kelamin     = " << update[ubah].jeniskelamin << endl;
			cout << "Kabupaten         = " << update[ubah].kabupaten << endl;
			cout << "Golongan          = " << update[ubah].golongan << endl;
			cout << "Tahap             = " << update[ubah].tahap << endl;
			cout << "Suhu tubuh        = " << update[ubah].suhu << endl;
			cout << "Riwayat penyakit  = " << update[ubah].riwayat << endl;
		
    }
	cout << endl;
}

void sorting(fstream &dataorang, fstream &jumlah, int jumlahorang)
{
	masyarakat sorting[jumlahorang], tempat;
	int pilih2;

	dataorang.open("dataorang.txt");
    for (int i = 0; i < jumlahorang; i++)
    {
    getline(dataorang, sorting[i].nomorpendaftaran );
	getline(dataorang, sorting[i].nama);
	getline(dataorang, sorting[i].umur);
    getline(dataorang, sorting[i].jeniskelamin);
	getline(dataorang, sorting[i].kabupaten); 
	getline(dataorang, sorting[i].golongan);
	getline(dataorang, sorting[i].tahap);
	getline(dataorang, sorting[i].suhu);
	getline(dataorang, sorting[i].riwayat);
    }
    dataorang.close();
    
    cout << "            TAMPILAN DATA PESERTA VAKSINASI COVID-19";
	cout << "\n ------------------------------------------------------------- \n";
	cout << endl;
    cout << "1. Tampilkan Data Berdasarkan Nomor Pendaftaran\n";
    cout << "2. Tampilkan Data Berdasarkan Golongan\n";

	cout << " Masukkan Pilihan : "; cin >> pilih2; 
	
	if (pilih2 == 1) {
		for (int i = 0; i < jumlahorang; i++) {
        for (int j = i+1; j < jumlahorang; j++) {
            if (sorting[i].nomorpendaftaran > sorting[j].nomorpendaftaran) {
                tempat = sorting[i];
                sorting[i] = sorting[j];
                sorting[j] = tempat; } } } } 
                
    else if (pilih2 == 2) {
		for (int i = 0; i < jumlahorang; i++) {
			for (int j = i+1; j < jumlahorang; j++) {
				if (sorting[i].golongan > sorting[j].golongan) {
					tempat = sorting[i];
					sorting[i] = sorting[j];
					sorting[j] = tempat; } } } }

	dataorang.open("dataorang.txt", ios::trunc | ios::out);
	for (int i = 0; i < jumlahorang; i++)
	{
		dataorang << sorting[i].nomorpendaftaran  << endl;
		dataorang << sorting[i].nama << endl;
        dataorang << sorting[i].umur << endl;
		dataorang << sorting[i].jeniskelamin << endl;
		dataorang << sorting[i].kabupaten << endl;
		dataorang << sorting[i].golongan << endl;
		dataorang << sorting[i].tahap << endl;
		dataorang << sorting[i].suhu << endl;
		dataorang << sorting[i].riwayat << endl;
	}
	dataorang.close();
	
	for (int i = 0; i < jumlahorang; i++)
    {
	cout << "\n ------------------------------------------------------------- \n";
    cout << " Nomor Pendaftaran = " << sorting[i].nomorpendaftaran  << endl;
	cout << " Nama Peserta      = " << sorting[i].nama << endl;
	cout << " Umur              = " << sorting[i].umur << endl;
    cout << " Jenis Kelamin     = " << sorting[i].jeniskelamin << endl;
	cout << " Kabupaten         = " << sorting[i].kabupaten << endl; 
	cout << " Golongan          = " << sorting[i].golongan << endl;
    cout << " Tahap             = " << sorting[i].tahap << endl;
	cout << " Suhu tubuh        = " << sorting[i].suhu << endl;
	cout << " Riwayat penyakit  = " << sorting[i].riwayat << endl;
    }
    
}
	
