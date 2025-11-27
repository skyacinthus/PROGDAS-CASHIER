
# 🍩 Dopiyo Donuts: Self-Service Cashier (Proyek Akhir Pemrograman Dasar)

Dopiyo Donuts adalah **sistem kasir mandiri** yang dibuat sebagai proyek akhir mata kuliah *Pemrograman Dasar*.
Proyek ini terdiri dari **versi console** serta **versi GUI** yang dibuat menggunakan **Qt Framework**.

Sistem memungkinkan pelanggan melakukan pemesanan, melihat total belanja, melakukan pembayaran via QR, hingga mencetak nota.

---
## 👥 Anggota Tim
* 25/556038/TK/62703 | Ayesha Nabiha Arrizany H.
* 25/555699/TK/62657 | Refa Rahmawati
* 25/556423/TK/62761 | Salma Karimah Kamal


## 📁 Struktur Proyek

```
.
├── PROTOTYPE/
│   └── Kode dasar tanpa GUI (versi console)
│
└── DOPIYO-FINAL/
    └── Versi GUI menggunakan Qt Framework
```

### **DOPIYO-CONSOLE**

* Implementasi C++ murni
* Tanpa GUI
* Menjadi dasar logika untuk versi final

### **DOPIYO-GUI**

* Aplikasi GUI lengkap menggunakan Qt
* Versi final yang digunakan untuk presentasi
* Berisi UI, pembacaan menu, dan fitur cetak PDF

---

## 🧩 Fitur

### **F-01 — Input Customer Name**

Fitur untuk menambahkan identitas pelanggan sebelum memulai pemesanan.

### **F-02 — Order Food Items**

Fitur untuk menambahkan pesanan dari pelanggan berdasarkan menu yang tersedia.

### **F-03 — File Input for Menu**

Fitur untuk memuat menu makanan dari file **`menu.txt`** sehingga menu dapat diperbarui tanpa mengubah kode.

### **F-04 — View Total Order**

Fitur untuk menampilkan total pembelian, termasuk rincian harga setiap item.

### **F-05 — Payment (QR Display)**

Fitur yang menampilkan **QR Code** sebagai metode pembayaran digital. (QR yang digunakan berupa placeholder, bukan QR code pembayaran)

### **F-06 — Receipt**

Fitur untuk menampilkan nota setelah pembayaran dilakukan.

### **F-07 — Print Receipt (PDF Export)**

Fitur untuk mencetak nota ke dalam file **PDF**.

---

## 🚀 Cara Menjalankan

### **Console**
1. Unduh ZIP repository atau hanya folder **`DOPIYO-CONSOLE`**.
2. Ekstrak ZIP.
3. Masuk ke dalam folder.
4. Jalankan file berikut:
```
Progdas-Final-Project.exe
```


### **GUI (Hanya Windows)**

Saat ini, aplikasi GUI menghasilkan **PE32 executable** yang hanya berjalan di Windows.

1. Unduh ZIP repository atau hanya folder **`DOPIYO-GUI`**.
2. Ekstrak ZIP.
3. Masuk ke dalam folder **`Build`**.
3. Masuk ke dalam folder **`Desktop_Qt_6_10_0_MinGW_64_bit-Release`**.
4. Jalankan file berikut:

```
Progdas-Final-Project.exe
```

> ⚠️ **Catatan:**
> Aplikasi GUI hanya dapat dijalankan di **Windows** karena file executable dibuat menggunakan MinGW dan tidak dapat dieksekusi secara native di Linux atau macOS.

### **Menu Input (Console & GUI Version)**

Baik versi console maupun GUI menggunakan file menu.txt sebagai sumber menu.

Format file:

```
Nama Donut;Harga
```

Contoh:

```
Tripple Choco Boom;20000
Tiramisu Lotus Ring;25000
Matcha Red Bean;30000
American Cheese Boom;20000
Red Velvet Cheese Boom;25000
```

Cara Mengubah / Menambah Menu

1. Buka file Menu.txt
2. Tambahkan baris baru dengan format yang sama:

```
Nama Produk;Harga
```
3. Simpan
4. Jalankan ulang program

Program akan secara otomatis memuat menu terbaru saat dijalankan. Tidak perlu mengedit kode C++ sama sekali.

---

## ▶️ Demo & Screenshots


---

## 🏗️ Teknologi yang Digunakan

* **C++**
* **Qt 6 Framework**
* **MinGW 64-bit Compiler**
* File handling (`menu.txt`)
* PDF printing dengan Qt

---

## 🍩 Tentang Proyek

Proyek ini dibuat untuk tujuan pembelajaran dan mencakup:

* Pengembangan GUI dengan Qt
* Dasar-dasar pemrograman C++
* File I/O
* Pemrograman berbasis objek
* Simulasi pembayaran
* Pembuatan PDF
* Perancangan antarmuka yang ramah pengguna

Toko fiksi yang digunakan dalam sistem adalah **Dopiyo Donuts**.
