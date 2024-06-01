# Judul Program: Dompet Digital

## Nama Anggota Kelompok:
1. Andre (231401040)
2. Felicia Jennifer Febiola Simarmata (231401046)
3. Hana Katharine Putri Pratama Sunmacher (231401049)

## Deskripsi Program
Aplikasi dompet digital yang kami buat ini memiliki beberapa fitur yaitu:
1. Lihat Data Transaksi
Di fitur lihat transaksi, user bisa melihat data pendapatan dan pengeluaran mereka. Data tersebut meliputi jumlah transaksi, tanggal transaksi, kategori transaksi, dan deskripsi transaksi. 
2. Tambah Data Pendapatan
Di fitur tambah data pendapatan, user akan memasukkan jumlah pendapatan, tanggal transaksi, kategori pendapatan, dan deskripsi pendapatan. 
3. Tambah Data Pengeluaran
Di fitur tambah data pengeluaran, user akan memasukkan jumlah pengeluaran, tanggal transaksi, kategori pengeluaran, dan deskripsi pengeluaran.
4. Memperbarui Data
Di fitur ini, user bisa memperbarui data yang sudah ada dengan memasukkan jumlah, tanggal, kategori, dan deskripsi untuk data lama yang ingin diubah. Kemudian, user akan diminta untuk memasukkan jumlah, tanggal, kategori, dan deskripsi data baru jika data lama yang diinput valid.
5. Mencari Data
Di fitur mencari data ini, user bisa mencari riwayat pendapatan atau pengeluaran berdasarkan tanggal dan kategorinya.
6. Menyimpan Data
Di fitur ini, user akan menyimpan secara permanen semua data sementaranya ke file saldo.txt (menyimpan saldo), pendapatan.txt (menyimpan data pendapatan), dan pengeluaran.txt (menyimpan data pengeluaran).

## Hasil Program
### 1. Tampilan Awal

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/dcea6ea6-e92d-4707-b868-9748abaefca9)

### 2. Tampilan Fitur Lihat Data

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/a80d3f18-f789-4627-97c8-7a32d024c902)

**Note:** Jika data pendapatan atau pengeluaran lebih dari lima, maka yang ditampilkan hanyalah 5 data yang terbaru saja.

### 3. Tampilan Fitur Tambah Pendapatan

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/85d26c4e-11c0-437d-96e0-e0311494f269)


### 4. Tampilan Fitur Tambah Pengeluaran

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/19b69869-39a9-4969-b803-a470fd86b468)

### 5. Tampilan Fitur Update Data

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/94324af7-8cf1-4856-a77e-7a7a5926ec59)

Misalkan kita mengambil data yang sudah disimpan seperti diatas dari saldo.txt, pendapatan.txt, dan pengeluaran.txt kemudian ingin mengubah salah satu datanya, maka kita bisa menggunakan fitur update data. Misalkan kita ingin mengubah data pengeluaran yang pertama menjadi jumlah (5000.50), tanggal (27-05-2024), kategori (Beli Jajan), dan deskripsi (Sosis Goreng). Berikut adalah caranya

**1. Pilih Menu 4 untuk Update Data**

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/e8bb74e9-cb45-43be-9020-8f2d2e018aff)

**2. Masukkan Jenis Data yang ingin diubah (pendapatan atau pengeluaran)**

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/c577f88f-bb54-4033-8686-40ffbc461f93)

**3. Masukkan Data Lama yang Ingin Diubah (jumlah, tanggal, kategori, dan deskripsi)**

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/148abf31-074b-4064-ba66-56041129ecf3)

**4. Masukkan Data Baru (jumlah, tanggal, kategori, dan deskripsi)**

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/6b74877b-cd31-4bf4-9a00-5bec7d64ad57)

**Hasil**


![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/31aefacc-8575-4b69-b340-a2d31a3c097e)


### 6. Tampilan Fitur Cari Data

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/f15a3e21-93cf-42c2-8bdb-8155374a353b)


![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/d0308689-bd9a-4618-838a-47d354e1336d)

**Note:** Jika bulan, tahun, dan kategori diisi dengan (-), maka data pendapatan atau pengeluaran akan ditampilkan seluruhnya. Jika bulan dan tahun diisi(-), maka akan ditampilkan data pendapatan atau pengeluaran berdasarkan kategorinya. Jika kategori diisi(-), maka akan ditampilkan data pendapatan atau pengeluaran berdasarkan bulan dan tahun transaksinya. 

### 7. Tampilan Fitur Simpan Data

Jika sebelumnya user belum pernah menyimpan data, maka file saldo.txt, pendapatan.txt, dan pengeluaran.txt belum ada.

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/6d8b0e4b-0016-4b28-aca7-14148a26c2d5)

Setelah user menyimpan data, maka file saldo.txt, pendapatan.txt, dan pengeluaran.txt akan otomatis muncul.

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/175d4ecf-4525-4737-858a-1cda774e26e3)

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/aacd3c6b-5e61-48f7-8f39-7662b6d3bf2d)

**Note:** Jika user sudah pernah menyimpan data, maka data tersebut akan diambil pada awal program dijalankan. Kemudian user akan menimpa data yang lama dengan data yang baru.  

### 8. Tampilan Jika User Keluar dari Program

![image](https://github.com/Andre-231401040/LabAP1-UAS-NoName/assets/147403392/fb42da00-20a8-481d-89ea-a248ae75440d)


## Link Video Presentasi ()
