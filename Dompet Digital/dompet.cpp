#include "class.h" 

void garis() {
    cout << "==============================" << endl;
}

int main() {
    Dompet dompetKu;
    fstream data_saldo, data_pendapatan, data_pengeluaran;
    int pilih;
    dompetKu.ambilData(data_saldo, data_pendapatan, data_pengeluaran);

    cout << fixed << setprecision(2) << endl;

    awal:
    do {
        cls;
        garis();
        cout << "             MENU           " << endl;
        garis();
        cout << "1. Lihat Data" << endl;
        cout << "2. Tambah Pendapatan" << endl;
        cout << "3. Tambah Pengeluaran " << endl;
        cout << "4. Perbarui Data" << endl;
        cout << "5. Cari Informasi Transaksi" << endl;
        cout << "6. Simpan Data" << endl;
        cout << "7. Keluar" << endl;
        garis();
        cout << "Pilihan Anda [1-7]: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cls;
                dompetKu.lihatData();
                break;
            case 2:
                cls;
                dompetKu.tambahPendapatan();
                break;
            case 3:
                cls;
                dompetKu.tambahPengeluaran();
                break;
            case 4:
                cls;
                cout << "Perbarui Data." << endl;
                dompetKu.update();
                break;
            case 5:
                cls;
                cout << "Cari Informasi Transaksi." << endl;
                dompetKu.cariTransaksi();
                break;
            case 6:
                dompetKu.simpanData(data_saldo, data_pendapatan, data_pengeluaran);
                break;
            case 7:
                cls;
                cout << "Terima kasih telah menggunakan aplikasi kami." << endl;
                break;
            default:
                cls;
                cout << "Pilihan tidak tersedia. Silakan coba lagi." << endl;
                system("pause");
                goto awal;
        }
    } while (pilih != 7);

    return 0;
}