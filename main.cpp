#include <iostream>
using namespace std;
int main()
{
    string nama, nim;
    int angka_tbk, pilih_menu;
    int angka_benar = 5;
    bool login = false, isFirstLogin = true;
    cout << "=== Selamat Datang ===" << endl;
    do
    {
        if (isFirstLogin == false)
        {
            cout << "Login gagal, silahkan coba lagi" << endl;
        }

        cout << "Silahkan masukkan nama anda : ";
        cin >> nama;
        cout << "Silahkan masukkan nim anda : ";
        cin >> nim;
        cout << endl;

        login = nama == "fariz" && nim == "150";
        isFirstLogin = false;
    } while (login == false);
    cout << "Selamat datang " << nama << " dengan NIM " << nim << endl;

    cout << "Menu : " << endl;
    cout << "1. Game" << endl;
    cout << "2. Keluar" << endl;
    cout << "Pilih menu : ";
    cin >> pilih_menu;

    switch (pilih_menu)
    {
    case 1:
        cout << "=== Game ===" << endl;
        cout << "Tebak angka" << endl;
        cout << "Masukkan angka tebakan : ";
        cin >> angka_tbk;
        do
        {
            if (angka_tbk < angka_benar)
            {
                cout << "Angkane Kurang Gede" << endl;
            }
            else if (angka_tbk > angka_benar)
            {
                cout << "Wuohh, Kegeden iki" << endl;
            }
            cout << "Masukkan angka tebakan : ";
            cin >> angka_tbk;
        } while (angka_tbk != angka_benar);
        cout << "Selamat, angka yang anda tebak benar" << endl;
        break;
    case 2:
        cout << "=== Keluar ===" << endl;
        cout << "Terima kasih telah menggunakan program ini" << endl;
        break;
    }
}