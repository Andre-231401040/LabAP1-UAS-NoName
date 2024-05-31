#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "struct.h"

#define cls system("cls");

class Dompet {
    private:
        double saldo = 0;
        vector<Transaksi> pendapatan, pengeluaran;

    public:
        void ambilData(fstream &data_saldo, fstream &data_pendapatan, fstream &data_pengeluaran){
            data_saldo.open("saldo.txt", ios::in);
            data_pendapatan.open("pendapatan.txt", ios::in);
            data_pengeluaran.open("pengeluaran.txt", ios::in);

            int size_pendapatan, size_pengeluaran;
            if(data_saldo && data_pendapatan && data_pengeluaran){
                size_pendapatan = pendapatan.size();
                size_pengeluaran = pengeluaran.size();

                while(data_saldo) {
                    if(size_pendapatan != 0 || size_pengeluaran != 0) break;
                    string saldo_sementara;
                    getline(data_saldo, saldo_sementara);
                    if(saldo_sementara == "") break;
                    saldo = stod(saldo_sementara);
                }
                data_saldo.close();

                int i = 1;
                Transaksi temp;
                while(data_pendapatan){
                    if(size_pendapatan != 0) break;
                    string jumlah_sementara;

                    if(i % 4 == 1){
                        getline(data_pendapatan, jumlah_sementara);
                        if(jumlah_sementara == "") break;
                        temp.jumlah = stod(jumlah_sementara);  
                    }else if(i % 4 == 2){
                        getline(data_pendapatan, temp.tanggal);
                    }else if(i % 4 == 3){
                        getline(data_pendapatan, temp.kategori);
                    }else{
                        getline(data_pendapatan, temp.deskripsi);
                        pendapatan.push_back(temp);
                    }

                    i++;
                }
                data_pendapatan.close();

                i = 1;
                while(data_pengeluaran){
                    if(size_pengeluaran != 0) break;
                    string jumlah_sementara;

                    if(i % 4 == 1){
                        getline(data_pengeluaran, jumlah_sementara);
                        if(jumlah_sementara == "") break;
                        temp.jumlah = stod(jumlah_sementara);  
                    }else if(i % 4 == 2){
                        getline(data_pengeluaran, temp.tanggal);
                    }else if(i % 4 == 3){
                        getline(data_pengeluaran, temp.kategori);
                    }else{
                        getline(data_pengeluaran, temp.deskripsi);
                        pengeluaran.push_back(temp);
                    }

                    i++;
                }
                data_pengeluaran.close();
            }
        }

        void lihatData() {            
            int size_pendapatan, size_pengeluaran;
            size_pendapatan = pendapatan.size();
            size_pengeluaran = pengeluaran.size();
            cout << "Saldo Anda: " << saldo << endl;
            cout << endl << "Riwayat Pendapatan" << endl;
            for(int i = 0; i < (size_pendapatan < 5 ? size_pendapatan : 5); i++){
                cout << i + 1 << "." << endl;
                cout << "Jumlah     : " << pendapatan[i].jumlah << endl;
                cout << "Tanggal    : " << pendapatan[i].tanggal << endl;
                cout << "Kategori   : " << pendapatan[i].kategori << endl;
                cout << "Deskripsi  : " << pendapatan[i].deskripsi << endl;
            }
            cout << endl << "Riwayat Pengeluaran" << endl;
            for(int i = 0; i < (size_pengeluaran < 5 ? size_pengeluaran : 5); i++){
                cout << i + 1 << "." << endl;
                cout << "Jumlah     : " << pengeluaran[i].jumlah << endl;
                cout << "Tanggal    : " << pengeluaran[i].tanggal << endl;
                cout << "Kategori   : " << pengeluaran[i].kategori << endl;
                cout << "Deskripsi  : " << pengeluaran[i].deskripsi << endl;
            }

            system("pause");
        }

        void tambahPendapatan() {
            Transaksi pendapatan_sementara;

            cout << "Jumlah Pendapatan: Rp ";
            cin >> pendapatan_sementara.jumlah;
            cout << "Tanggal Pendapatan (dd-mm-yyyy): ";
            cin >> pendapatan_sementara.tanggal;
            cout << "Kategori Pendapatan: ";
            cin.ignore();
            getline(cin, pendapatan_sementara.kategori);
            cout << "Deskripsi Pendapatan: ";
            getline(cin, pendapatan_sementara.deskripsi);

            saldo += pendapatan_sementara.jumlah;

            pendapatan.insert(pendapatan.begin(), pendapatan_sementara);
        }

        void tambahPengeluaran() {
            Transaksi pengeluaran_sementara;

            cout << "Jumlah Pengeluaran: Rp ";
            cin >> pengeluaran_sementara.jumlah;
            cout << "Tanggal Pengeluaran (dd-mm-yyyy): ";
            cin >> pengeluaran_sementara.tanggal;
            cout << "Kategori Pengeluaran: ";
            cin.ignore();
            getline(cin, pengeluaran_sementara.kategori);
            cout << "Deskripsi Pengeluaran: ";
            getline(cin, pengeluaran_sementara.deskripsi);

            saldo -= pengeluaran_sementara.jumlah;

            pengeluaran.insert(pengeluaran.begin(), pengeluaran_sementara);
        }


        void update(){
            Transaksi pembaruan_data;
            string pilihan;

            cout << "Pendapatan atau pengeluaran : ";
            cin.ignore();
            cin >> pilihan;

            //transform(pilihan.begin(), pilihan.end(), pilihan.begin(), tolower);
            for(int i = 0; i < pilihan.length(); i++){
                pilihan[i] = tolower(pilihan[i]);
            }

            if(pilihan == "pendapatan"){
                cls;
                cout << "Input data pendapatan yang ingin diubah." << endl;
                cout << "masukan jumlah pendapatan : Rp ";
                cin.ignore();
                cin >> pembaruan_data.jumlah;
                cout << "masukan tanggal pendapatan (dd-mm-yyyy) :"; 
                cin.ignore();
                getline(cin,pembaruan_data.tanggal);
                cout << "masukan kategori pendapatan :";
                getline(cin,pembaruan_data.kategori);
                cout << "masukan deskripsi pendapatan :";
                getline(cin,pembaruan_data.deskripsi);

                for(auto &pendapatan_sementara : pendapatan){
                    if(pembaruan_data.tanggal == pendapatan_sementara.tanggal && pembaruan_data.kategori == pendapatan_sementara.kategori && pembaruan_data.deskripsi == pendapatan_sementara.deskripsi && pembaruan_data.jumlah == pendapatan_sementara.jumlah){
                        cls;
                        cout << " Data Sebelumnya" << endl;
                        cout << "Jumlah Pendapatan: Rp " << pendapatan_sementara.jumlah << endl;
                        cout << "Tanggal Pendapatan (dd-mm-yyyy): " << pendapatan_sementara.tanggal << endl;
                        cout << "Kategori Pendapatan: " << pendapatan_sementara.kategori << endl;
                        cout << "Deskripsi Pendapatan: " << pendapatan_sementara.deskripsi << endl;
                        saldo -= pendapatan_sementara.jumlah;

                        cout << endl;

                        cout << "Masukan Data Terbaru " << endl;
                        cout << "Jumlah Pendapatan: Rp ";
                        cin >> pendapatan_sementara.jumlah;
                        cout << "Tanggal Pendapatan (dd-mm-yyyy): ";
                        cin >> pendapatan_sementara.tanggal;
                        cout << "Kategori Pendapatan: ";
                        cin.ignore();
                        getline(cin, pendapatan_sementara.kategori);
                        cout << "Deskripsi Pendapatan: ";
                        getline(cin, pendapatan_sementara.deskripsi);
                        saldo += pendapatan_sementara.jumlah;

                        break;
                    } 
                }
           }else if (pilihan == "pengeluaran"){
                cls;
                cout << "Input data pengeluaran yang ingin diubah." << endl;
                cout << "masukan jumlah pengeluaran : Rp ";
                cin.ignore();
                cin >> pembaruan_data.jumlah;
                cout << "masukan tanggal pengeluaran (dd-mm-yyyy) :"; 
                cin.ignore();
                getline(cin,pembaruan_data.tanggal);
                cout << "masukan kategori pengeluaran :";
                getline(cin,pembaruan_data.kategori);
                cout << "masukan deskripsi pengeluaran :";
                getline(cin,pembaruan_data.deskripsi);

                for(auto &pengeluaran_sementara : pengeluaran){
                    if (pembaruan_data.tanggal == pengeluaran_sementara.tanggal && pembaruan_data.kategori == pengeluaran_sementara.kategori && pembaruan_data.deskripsi == pengeluaran_sementara.deskripsi && pembaruan_data.jumlah == pengeluaran_sementara.jumlah){
                        cls;
                        cout << "Data Sebelumnya" << endl;
                        cout << "Jumlah Pengeluaran: Rp " << pengeluaran_sementara.jumlah << endl;
                        cout << "Tanggal Pengeluaran (dd-mm-yyyy): " << pengeluaran_sementara.tanggal << endl;
                        cout << "Kategori Pengeluaran: " << pengeluaran_sementara.kategori << endl;
                        cout << "Deskripsi Pengeluaran: " << pengeluaran_sementara.deskripsi << endl;
                        saldo += pengeluaran_sementara.jumlah;

                        cout << endl;

                        cout << "Masukan Data Terbaru" << endl;
                        cout << "Jumlah Pengeluaran: Rp ";
                        cin >> pengeluaran_sementara.jumlah;
                        cout << "Tanggal Pengeluaran (dd-mm-yyyy): ";
                        cin >> pengeluaran_sementara.tanggal;
                        cout << "Kategori Pengeluaran: ";
                        cin.ignore();
                        getline(cin, pengeluaran_sementara.kategori);
                        cout << "Deskripsi Pengeluaran: ";
                        getline(cin, pengeluaran_sementara.deskripsi);
                        saldo -= pengeluaran_sementara.jumlah;

                        break;
                    }
                }
           }else{
                cls;
                cout << "Pilihan tidak ditemukan." << endl;
           }

           system("pause");
        }
        
        void cariTransaksi(){
            string bulan, kategori, pilihan;
            cout << "Masukkan bulan (mm-yyyy) atau '-' untuk melewati: ";
            cin.ignore();
            getline(cin, bulan);
            cout << "Masukkan kategori atau '-' untuk melewati: ";
            getline(cin, kategori);

            cout << "Pendapatan atau pengeluaran : ";
            cin >> pilihan;
            
            //transform(pilihan.begin(), pilihan.end(), pilihan.begin(), tolower);
            for(int i = 0; i < pilihan.length(); i++){
                pilihan[i] = tolower(pilihan[i]);
            }

            if(pilihan == "pendapatan"){
                cls;
                cout << "Hasil pencarian transaksi pendapatan:" << endl;
                for (const auto& trans : pendapatan) {
                    bool bulanCocok = (bulan == "-" || trans.tanggal.substr(3, 7) == bulan);
                    bool kategoriCocok = (kategori == "-" || trans.kategori == kategori);
                    if (bulanCocok && kategoriCocok) {
                        cout << "Tanggal: " << trans.tanggal << ", Kategori: " << trans.kategori
                            << ", Deskripsi: " << trans.deskripsi << ", Jumlah: Rp " << trans.jumlah << endl;
                    }
                }
            }else if(pilihan == "pengeluaran"){
                cls;
                cout << "Hasil pencarian transaksi pengeluaran:" << endl;
                for (const auto& trans : pengeluaran) {
                    bool bulanCocok = (bulan == "-" || trans.tanggal.substr(3, 7) == bulan);
                    bool kategoriCocok = (kategori == "-" || trans.kategori == kategori);
                    if (bulanCocok && kategoriCocok) {
                        cout << "Tanggal: " << trans.tanggal << ", Kategori: " << trans.kategori
                            << ", Deskripsi: " << trans.deskripsi << ", Jumlah: Rp " << trans.jumlah << endl;
                    }
                }
            }else{
                cls;
                cout << "Pilihan tidak ditemukan" << endl;
            }

            system("pause");
        }

        void simpanData(fstream &data_saldo, fstream &data_pendapatan, fstream &data_pengeluaran){
            data_saldo.open("saldo.txt", ios::trunc | ios::out);
            data_saldo << fixed << setprecision(2) << saldo;
            data_saldo.close();
            
            data_pendapatan.open("pendapatan.txt", ios::trunc | ios::out);
            for(int i = 0; i < pendapatan.size(); i++){
                data_pendapatan << fixed << setprecision(2) << pendapatan[i].jumlah << endl;
                data_pendapatan << pendapatan[i].tanggal << endl;
                data_pendapatan << pendapatan[i].kategori << endl;
                data_pendapatan << pendapatan[i].deskripsi << endl;
            }
            data_pendapatan.close();

            data_pengeluaran.open("pengeluaran.txt", ios::trunc | ios::out);
            for(int i = 0; i < pengeluaran.size(); i++){
                data_pengeluaran << fixed << setprecision(2) << pengeluaran[i].jumlah << endl;
                data_pengeluaran << pengeluaran[i].tanggal << endl;
                data_pengeluaran << pengeluaran[i].kategori << endl;
                data_pengeluaran << pengeluaran[i].deskripsi << endl;
            }
            data_pengeluaran.close();

            cout << "Data anda berhasil ditambahkan." << endl;

            system("pause");
        }
};