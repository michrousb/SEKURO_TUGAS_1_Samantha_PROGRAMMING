#include "mobil.hpp"
#include <iostream>

using namespace std;

// === Implementasi Class mobil ===

mobil::mobil(int kapasitas_mesin, string name, string merk, int top_speed, string bahan_bakar) {
    this -> kapasitas_mesin = kapasitas_mesin;
    this -> name = name;
    this -> merk = merk;
    this -> top_speed = top_speed;
    this -> bahan_bakar = bahan_bakar;
    cout << name << " keluar dari pabrik " << merk << " nih gaspol ah" << endl;

    /* [TODO] : Inisialisasi atribut kapasitas_mesin, name, merk, top_speed, dan bahan_bakar
    dan menghasilkan output: <nama_mobil> keluar dari pabrik <merk> nih gaspol ah
    */
}

void mobil::jalan(int jarak) {
    cout << "Mobil " << name << " sedang jalan sejauh " << jarak << " kilometer" << endl;

    /* [TODO] : Implementasikan fungsi ini agar menghasilkan output:
    Mobil <nama_mobil> sedang jalan sejauh <jarak> kilometer
    */
}

void mobil::pamer_mesin() {
    if (kapasitas_mesin < 2000){
        cout << "Yah " << name << " kagak bisa meraung CC mesinnya kurang" << endl;

    }
    else{
        cout << "WRAAAUR " << name << " meraung dengan kerennya" << endl;
    }
    /* [TODO] : Implementasikan fungsi ini agar menghasilkan output:
    jika kapasitas_mesin < 2000 CC maka menghasilkan output:
    Yah <nama_mobil> kagak bisa ngeraung CC mesinnya kurang
    jika kapasitas_mesin >= 2000 CC maka menghasilkan output:
    WRAAAUR <nama_mobil> meraung dengan kerennya
    */
}

// Implementasi Penuh (Base Class) sebagai referensi
void mobil::cek_spesifikasi() {
    cout << "=== Spesifikasi Standar " << name << " ===" << endl;
    cout << "Merk: " << merk << " | Mesin: " << kapasitas_mesin << " CC" << endl;
    cout << "Top Speed: " << top_speed << " km/jam | BBM: " << bahan_bakar << endl;
}

mobil::~mobil() {
    cout << "BOOM " << name << " Dihancurin" << endl;
    /* [TODO] : Implementasikan fungsi ini agar menghasilkan output:
    BOOM <nama_mobil> Dihancurin
    */
}

// === Implementasi Class mobil_sport (Inheritance) ===

mobil_sport::mobil_sport(int kapasitas_mesin, string name, string merk, int top_speed, string bahan_bakar)
    : mobil(kapasitas_mesin, name, merk, top_speed, bahan_bakar) {
        turbo_aktif = false;
    /* [TODO] : Inisialisasi atribut turbo_aktif menjadi false */
}

void mobil_sport::jalan(int jarak){
    cout << "Wuzzz!"<< name << " melesat sejauh " << jarak << " km!" << endl;

    /* [TODO] : Implementasikan fungsi ini agar menghasilkan output:
    Wuzzz! mobil_sport <nama_mobil> melesat sejauh <jarak> km!
    */
}

void mobil_sport::cek_spesifikasi() {
    cout << " === Spesifikasi High-Performance " << name << " ===" << endl;
    cout << "Merk: " << merk << " | Mesin: " << kapasitas_mesin << " CC" << endl;
    cout << "Kecepatan Maksimum: " << top_speed << " km/jam | BBM: " << bahan_bakar << endl;
    cout << "Status Turbo: " << (turbo_aktif ? "Aktif" : "Non-aktif") << endl;
    /* [TODO] : Implementasikan fungsi ini agar menghasilkan output spesifik:
    1. Baris pertama: === Spesifikasi High-Performance <nama_mobil> ===
    2. Baris kedua: Merk: <merk> | Mesin: <kapasitas_mesin> CC
    3. Baris ketiga: Kecepatan Maksimum: <top_speed> km/jam | BBM: <bahan_bakar>
    4. Baris keempat: Status Turbo: (Tampilkan "Aktif" jika turbo_aktif true, "Non-aktif" jika false)
    */
}

void mobil_sport::aktifkan_turbo() {
    turbo_aktif = true;
    cout << "Turbo diaktifkan! Power " << name << " meningkat drastis!" << endl;
    /* [TODO] : Set turbo_aktif menjadi true dan berikan output konfirmasi bahwa turbo aktif */
}