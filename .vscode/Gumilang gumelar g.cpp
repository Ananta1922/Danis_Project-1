    #include <iostream>
    #include <iomanip>
    #include <vector>
    #include <string>
    #include <map>

    using namespace std;

    const int JENIS_MOBIL = 4;
    const int DETAIL_MOBIL = 3;

    struct Pembelian {
        string jenisMobil;
        string modelMobil;
        int jumlahBeli;
        int totalHarga;
    };

    void tampilkanMenuUtama();
    void lihatJenisMobil(const string jenisMobil[], int jumlahMobil);
    void beliMobil(const string jenisMobil[], const string detailMobil[][DETAIL_MOBIL], const int hargaMobil[], vector<Pembelian>& riwayatPembelian, map<string, int>& stokMobil);
    void tampilkanRiwayatPembelian(const vector<Pembelian>& riwayatPembelian);
    void tampilkanTotalPenjualan(const vector<Pembelian>& riwayatPembelian);

    int main() {
        string jenisMobil[JENIS_MOBIL] = {"Sedan", "SUV", "Hatchback", "MPV"};
        string detailMobil[JENIS_MOBIL][DETAIL_MOBIL] = {
            {"Toyota Corolla", "Honda Civic", "Mazda 3"},
            {"Toyota RAV4", "Honda CR-V", "Ford Explorer"},
            {"Volkswagen Golf", "Ford Fiesta", "Renault Clio"},
            {"Toyota Innova", "Honda Odyssey", "Kia Carnival"}
        };
        int hargaMobil[JENIS_MOBIL] = {200000000, 300000000, 1800000000, 250000000};

        vector<Pembelian> riwayatPembelian;
        map<string, int> stokMobil;

        for (int i = 0; i < JENIS_MOBIL; ++i) {
            for (int j = 0; j < DETAIL_MOBIL; ++j) {
                stokMobil[detailMobil[i][j]] = 10;
            }
        }

        int pilihanJenis;

        cout << "=============================================" << endl;
        cout << "Selamat datang di Dealer Mobil KAYGUMAS" << endl;

        do {
            tampilkanMenuUtama();
            cout << "Pilih menu (1-5): ";
            cin >> pilihanJenis;

            switch (pilihanJenis) {
                case 1:
                    lihatJenisMobil(jenisMobil, JENIS_MOBIL);
                    break;
                case 2:
                    beliMobil(jenisMobil, detailMobil, hargaMobil, riwayatPembelian, stokMobil);
                    break;
                case 3:
                    tampilkanRiwayatPembelian(riwayatPembelian);
                    break;
                case 4:
                    tampilkanTotalPenjualan(riwayatPembelian);
                    break;
                case 5:
                    cout << "Terima kasih telah berkunjung. Sampai jumpa!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan pilih menu 1-5." << endl;
            }

        } while (pilihanJenis != 5);

       }

    void tampilkanMenuUtama() {
        cout << "------------------------------" << endl;
        cout << "         --- Menu ---        |" << endl;
        cout << "1. Lihat Jenis Mobil         |" << endl;
        cout << "2. Beli Mobil                |" << endl;
        cout << "3. Tampilkan Riwayat         |" << endl;
        cout << "4. Tampilkan Total Penjualan |" << endl;
        cout << "5. Keluar                    |" << endl;
        cout << "------------------------------" << endl;
    }

    void lihatJenisMobil(const string jenisMobil[], int jumlahMobil) {
        cout << "\nJenis Mobil yang Tersedia:" << endl;
        for (int i = 0; i < jumlahMobil; ++i) {
            cout << i + 1 << ". " << jenisMobil[i] << endl;
        }
    }

    void beliMobil(const string jenisMobil[], const string detailMobil[][DETAIL_MOBIL], const int hargaMobil[], vector<Pembelian>& riwayatPembelian, map<string, int>& stokMobil) {
        int pilihanDetail, jumlahBeli;

        cout << "\n---Pembelian Mobil---" << endl;
        cout << "Pilih jenis mobil (1-" << JENIS_MOBIL << "): ";
        cin >> pilihanDetail;

        if (pilihanDetail >= 1 && pilihanDetail <= JENIS_MOBIL) {
            --pilihanDetail;
            cout << "Pilih model mobil " << jenisMobil[pilihanDetail] << ":" << endl;

            for (int j = 0; j < DETAIL_MOBIL; ++j) {
                cout << j + 1 << ". " << detailMobil[pilihanDetail][j] << " (Stok: " << stokMobil[detailMobil[pilihanDetail][j]] << ")" << endl;
            }

            cout << "Pilihan model (1-" << DETAIL_MOBIL << "): ";
            cin >> pilihanDetail;

            if (pilihanDetail >= 1 && pilihanDetail <= DETAIL_MOBIL) {
                --pilihanDetail;
                cout << "Jumlah mobil yang akan dibeli: ";
                cin >> jumlahBeli;

                if (jumlahBeli > 0) {
                    string modelMobil = detailMobil[pilihanDetail][pilihanDetail];
                    int totalHarga = hargaMobil[pilihanDetail] * jumlahBeli;


                    if (jumlahBeli <= stokMobil[modelMobil]) {

                        stokMobil[modelMobil] -= jumlahBeli;

                        Pembelian pembelian = {jenisMobil[pilihanDetail], modelMobil, jumlahBeli, totalHarga};
                        riwayatPembelian.push_back(pembelian);

                        cout << "\nDetail Pembelian:" << endl;
                        cout << "Jenis Mobil: " << jenisMobil[pilihanDetail] << endl;
                        cout << "Model Mobil: " << modelMobil << endl;
                        cout << "Jumlah Beli: " << jumlahBeli << endl;
                        cout << "Total Harga: Rp" << totalHarga << endl;
                    } else {
                        cout << "Stok tidak mencukupi untuk jumlah beli yang diminta." << endl;
                    }
                } else {
                    cout << "Jumlah beli tidak valid." << endl;
                }
            } else {
                cout << "Pilihan model tidak valid." << endl;
            }
        } else {
            cout << "Pilihan jenis mobil tidak valid." << endl;
        }
    }

    void tampilkanRiwayatPembelian(const vector<Pembelian>& riwayatPembelian) {
        cout << "\n--- Riwayat Pembelian ---" << endl;
        if (riwayatPembelian.empty()) {
            cout << "Belum ada pembelian." << endl;
        } else {
            for (const auto& pembelian : riwayatPembelian) {
                cout << "Jenis Mobil: " << pembelian.jenisMobil << endl;
                cout << "Model Mobil: " << pembelian.modelMobil << endl;
                cout << "Jumlah Beli: " << pembelian.jumlahBeli << endl;
                cout << "Total Harga: Rp" << pembelian.totalHarga << endl;
                cout << "---------------------------" << endl;
            }
        }
    }

    void tampilkanTotalPenjualan(const vector<Pembelian>& riwayatPembelian) {
        cout << "\n--- Total Penjualan ---" << endl;
        int totalPenjualan = 0;

        for (const auto& pembelian : riwayatPembelian) {
            totalPenjualan += pembelian.totalHarga;
        }

        cout << "Total Penjualan: Rp" << totalPenjualan << endl;
    }




