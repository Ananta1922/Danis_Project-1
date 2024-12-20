    # print ("===============================================")
# print ("==[ Program konversi celcius ke satuan lain ]==")
# print ("===============================================")

print("\nPROGRAM KONVERSI TEMPERATURE\n")

celcius = float(input('Masukkan suhu dalam celcius :'))
print("\nSuhu Celcius adalah : ", celcius, "Celcius",type(celcius))

# reamur
reamur = (4/5) * celcius
print("Suhu dalam reamur adalah: ", reamur, "Reamur")

# fahrenheit
fahrenheit = ((9/5)* celcius) + 32
print("Suhu dalam fahrenheit adalah: ", fahrenheit, "Fahrenheit")

# kelvin
kelvin = celcius + 273
print("Suhu dalam Kelvin adalah: ", kelvin, "Kelvin")


# print ("\n================================================")
# print ("==[ Program konversi Reamur ke satuan lain ]======")
# print ("==================================================")

reamur = float(input('Masukkan suhu dalam reamur :'))
print("\nSuhu Reamur adalah : ", reamur, "Reamur")


# celcius
celcius = (5/4)* reamur
print("Suhu dalam celcius adalah: ", celcius, "Celcius")

# fahrenheit
fahrenheit = ((9/4)* reamur) + 32
print(" Suhu fahrenheit adalah: ", fahrenheit, "Fahrenheit")

# kelvin
kelvin = ((5/4)* reamur) + 273 # atau bisa dituliskan dengan rumus: celcius + 273
print(" Suhu kelvin adalah: ", kelvin, "Kelvin")


print ("\n====================================================")
print ("==[ Program konversi Fahrenheit ke satuan lain ]======")
print ("======================================================")

fahrenheit = float(input('Masukkan suhu dalam fahrenheit :'))
print("\nSuhu fahrenheit adalah: ", fahrenheit, "Fahrenheit")

# celcius
celcius = 5/9 * (fahrenheit-32)
print("\nSuhu celcius adalah: ", celcius, "Celcius")

# reamur
reamur = 4/9 * (fahrenheit-32)
print("\nSuhu reamur adalah: ", reamur, "Reamur")

# kelvin
kelvin = celcius + 273
print("\nSuhu kelvin adalah: ", kelvin, "Kelvin")


print ("\n====================================================")
print ("==[ Program konversi Kelvin ke satuan lain ]======")
print ("======================================================")

kelvin = float(input('Masukkan suhu dalam kelvin: '))
print("\nSuhu kelvin adalah: ", kelvin, "Kelvin")

# celcius
celcius = kelvin - 273
print("\nSuhu celcius adalah: ", celcius, "Celcius")

# reamur
reamur = 4/5 * (kelvin - 273) # atau 4/5 * celcius
print("\nSuhu reamur adalah: ", reamur, "Reamur")

#fahrenheit
fahrenheit = (9/5 * celcius) + 32 
print("\nSuhu fahrenheit adalah: ", fahrenheit, "Fahrenheit")
