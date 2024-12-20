def tambah(x, y):
    return x + y

def kurang(x, y):
    return x - y

def kali(x, y):
    return x * y

def bagi(x, y):
    if y == 0:
        return "Error: Tidak bisa dibagi dengan nol!"
    else:
        return x / y

print("Selamat Datang di Kalkulator Sederhana Python!")

while True:
    print("\nPilih operasi:")
    print("1. Tambah")
    print("2. Kurang")
    print("3. Kali")
    print("4. Bagi")
    print("5. Keluar")

    pilihan = input("Masukkan pilihan (1/2/3/4/5): ")

    if pilihan == '5':
        print("Terima kasih telah menggunakan kalkulator!")
        break

    if pilihan in ('1', '2', '3', '4'):
        try:
            num1 = float(input("Masukkan angka pertama: "))
            num2 = float(input("Masukkan angka kedua: "))
        except ValueError:
            print("Input tidak valid. Harap masukkan angka.")
            continue # Kembali ke awal loop

        if pilihan == '1':
            print("Hasil:", tambah(num1, num2))
        elif pilihan == '2':
            print("Hasil:", kurang(num1, num2))
        elif pilihan == '3':
            print("Hasil:", kali(num1, num2))
        elif pilihan == '4':
            print("Hasil:", bagi(num1, num2))
    else:
        print("Pilihan tidak valid.")