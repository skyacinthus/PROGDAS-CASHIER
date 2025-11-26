
# 🍩 Dopiyo Donuts: Self-Service Cashier (Proyek Akhir Pemrograman Dasar)

Dopiyo Donuts adalah **sistem kasir mandiri** yang dibuat sebagai proyek akhir mata kuliah *Pemrograman Dasar*.
Proyek ini terdiri dari **versi prototipe (console)** serta **versi GUI** yang dibuat menggunakan **Qt Framework**.

Sistem memungkinkan pelanggan melakukan pemesanan, melihat total belanja, melakukan pembayaran via QR, hingga mencetak nota.

---
## 👥 Anggota Tim
25/556038/TK/62703 | Ayesha Nabiha Arrizany H.
25/555699/TK/62657 | Refa Rahmawati
25/556423/TK/62761 | Salma Karimah Kamal


## 📁 Struktur Proyek

```
.
├── PROTOTYPE/
│   └── Kode dasar tanpa GUI (versi console)
│
└── DOPIYO-FINAL/
    └── Versi GUI menggunakan Qt Framework
```

### **PROTOTYPE**

* Implementasi C++ murni
* Tanpa GUI
* Menjadi dasar logika untuk versi final

### **DOPIYO-FINAL**

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

## 🚀 Cara Menjalankan (Hanya Windows)

Saat ini, aplikasi GUI menghasilkan **eksekutabel PE32** yang hanya berjalan di Windows.

1. Unduh ZIP repository atau hanya folder **`DOPIYO-FINAL`**.
2. Ekstrak ZIP.
3. Masuk ke dalam folder.
4. Jalankan file berikut:

```
Progdas-Final-Project.exe
```

> ⚠️ **Catatan:**
> Aplikasi hanya dapat dijalankan di **Windows** karena file executable dibuat menggunakan MinGW dan tidak dapat dieksekusi secara native di Linux atau macOS.

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
