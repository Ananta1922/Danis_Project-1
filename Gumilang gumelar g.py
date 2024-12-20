def tampilkan_menu():
    print("=== Selamat Datang di Program Kasir Sederhana ===")
    print("1. Tambah Barang")
    print("2. Hapus Barang")
    print("3. Lihat Keranjang")
    print("4. Checkout")
    print("5. Keluar")


def tambah_barang(keranjang):
    nama_barang = input("ROKOK SAMPURNA: ")
    harga = float(input("250000: "))
    jumlah = int(input("20: "))
    keranjang.append({"nama": nama_barang, "harga": harga, "jumlah": jumlah})
    print(f"{nama_barang} berhasil ditambahkan ke keranjang.")


def hapus_barang(keranjang):
    lihat_keranjang(keranjang)
    if keranjang:
        indeks = int(input("Masukkan nomor barang yang ingin dihapus: ")) - 1
        if 0 <= indeks < len(keranjang):
            barang = keranjang.pop(indeks)
            print(f"{barang['nama']} berhasil dihapus dari keranjang.")
        else:
            print("Nomor barang tidak valid.")


def lihat_keranjang(keranjang):
    print("\n=== Isi Keranjang ===")
    if not keranjang:
        print("Keranjang kosong.")
    else:
        for i, barang in enumerate(keranjang, start=1):
            print(f"{i}. {barang['nama']} - {barang['jumlah']} x Rp{barang['harga']:.2f}")
    print("====================\n")


def checkout(keranjang):
    lihat_keranjang(keranjang)
    if keranjang:
        total = sum(barang['harga'] * barang['jumlah'] for barang in keranjang)
        print(f"Total belanja Anda adalah: Rp{total:.2f}")
        bayar = float(input("Masukkan jumlah uang yang dibayarkan: "))
        if bayar >= total:
            kembalian = bayar - total
            print(f"Pembayaran berhasil. Kembalian Anda: Rp{kembalian:.2f}")
            keranjang.clear()
        else:
            print("Uang yang Anda masukkan kurang.")


def main():
    keranjang = []
    while True:
        tampilkan_menu()
        pilihan = input("Pilih menu: ")

        if pilihan == "1":
            tambah_barang(keranjang)
        elif pilihan == "2":
            hapus_barang(keranjang)
        elif pilihan == "3":
            lihat_keranjang(keranjang)
        elif pilihan == "4":
            checkout(keranjang)
        elif pilihan == "5":
            print("Terima kasih telah menggunakan program kasir sederhana.")
            break
        else:
            print("Pilihan tidak valid. Silakan coba lagi.")


if __name__ == "__main__":
    main()
