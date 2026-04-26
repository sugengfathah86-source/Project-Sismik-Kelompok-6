# 🌀 Kipas Otomatis Berbasis Suhu — Arduino Uno
 
> **Mata Kuliah:** Sistem Mikrokontroler (TK244004)  
> **Program Studi:** S1 Teknik Komputer — Universitas Jenderal Soedirman  
> **Dosen Pengampu:** Ucky Pradestha Novettralita, S.Pd., M.Kom  
> **Deadline:** 27 April 2026 pukul 23.59 WIB
 
---
 
## 📋 Deskripsi Proyek
 
Sistem kipas otomatis yang mengatur kecepatan kipas DC secara otomatis berdasarkan pembacaan suhu dari sensor TMP. Suhu ditampilkan secara real-time pada layar LCD I2C 16×2, dan kecepatan kipas dikendalikan menggunakan teknik PWM melalui transistor TIP120 sebagai driver.
 
---
 
## 🎯 Tujuan
 
1. Mengimplementasikan konsep percabangan (`if-else`) untuk menentukan kecepatan kipas berdasarkan rentang suhu.
2. Mengontrol GPIO sebagai input (sensor suhu via ADC) dan output (PWM untuk motor kipas).
3. Menggunakan protokol komunikasi **I2C** untuk mengoperasikan LCD.
4. Menerapkan konversi **ADC** dari sensor analog dan teknik **PWM** untuk mengontrol kecepatan motor.
---
 
## 🔧 Komponen yang Digunakan
 
| Komponen | Fungsi |
|---|---|
| Arduino Uno | Mikrokontroler utama |
| Sensor Suhu TMP | Membaca suhu lingkungan (input analog/ADC) |
| LCD I2C 16×2 | Menampilkan suhu dan status kecepatan kipas |
| Transistor TIP120 | Driver/penguat arus untuk motor kipas (PWM) |
| Motor DC (Kipas) | Output — kecepatan dikontrol via PWM |
| Resistor | Pembatas arus pada basis transistor |
| Breadboard & Jumper | Perakitan rangkaian |
 
---
