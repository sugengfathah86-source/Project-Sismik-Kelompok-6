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

---

## ⚡ Wiring / Skematik

![alt text](https://github.com/BillyUdin/Project-Sismik-Kelompok-6/blob/main/Project%20Sistem%20Mikrokontroller%20kelompok%206/Dokumen/Skematik%20Kipas%20Otomatis.png?raw=true)

**Koneksi utama:**
- **Sensor TMP** → Pin Analog (A0) Arduino
- **LCD I2C** → SDA & SCL Arduino (Pin A4 & A5)
- **Basis TIP120** → Pin Digital PWM Arduino (mis. Pin 9) melalui resistor
- **Motor DC** → Kolektor TIP120; Emitor → GND
- **VCC Motor** → 5V Arduino; **GND** bersama (common ground)

---

## 💻 Logika Program

### Rentang Kecepatan Kipas

| Suhu (°C) | Status | PWM Value |
|---|---|---|
| < 30 | OFF | 0 |
| 30 – 34 | LOW | ~85 |
| 35 – 39 | MEDIUM | ~170 |
| ≥ 40 | HIGH | 255 |

### Pseudocode

```
loop:
  baca nilai ADC dari sensor TMP
  konversi ke suhu (°C)
  
  if suhu < 30:
    kipas = OFF  (PWM = 0)
  else if suhu < 35:
    kipas = LOW  (PWM = 85)
  else if suhu < 40:
    kipas = MEDIUM (PWM = 170)
  else:
    kipas = HIGH (PWM = 255)
  
  tampilkan suhu & status kipas di LCD
  delay 500ms
```

---

## 📁 Struktur Repository

```
📦 Project SIstem Mikrokontroller kelompok6/
├── 📂 Dokumen/
│    └── Skematik_Kipas_Otomatis.png 
├── 📂 Sourcecode/
│   └── Source Code.ino
└── 📄 README.md
```

---

## 📚 Konsep yang Diterapkan

- ✅ **Percabangan & Perulangan** — `if-else` untuk logika kecepatan kipas, `loop()` utama Arduino
- ✅ **GPIO** — Analog input (sensor suhu), Digital PWM output (motor kipas)
- ✅ **Protokol I2C** — Komunikasi Arduino ke LCD 16×2
- ✅ **ADC** — Konversi sinyal analog suhu ke nilai digital
- ✅ **PWM** — Kontrol kecepatan motor kipas
- ⬜ **Interrupt Eksternal** *(opsional — poin bonus jika ditambahkan)*

---

## 📝 Lisensi

Proyek ini dibuat untuk keperluan akademik — **Project I Sistem Mikrokontroler**, Fakultas Teknik, Universitas Jenderal Soedirman.
