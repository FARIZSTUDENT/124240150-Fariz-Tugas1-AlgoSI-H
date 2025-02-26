#include <iostream>
using namespace std;

struct Batalyon
{
    int id;
    string nama_general;
    string tipe_pasukan;
    int jumlah_pasukan;
};

Batalyon batalyon_list[100];
string tipe_pasukan_tersedia[] = {"Infantry", "Kavaleri", "Archer"};
int batalyon_count = 0;

bool isNamaGeneralExist(string nama)
{
    int i = 0;
    while (i < batalyon_count)
    {
        if (batalyon_list[i].nama_general == nama)
            return true;
        i++;
    }
    return false;
}

bool isTipePasukanValid(string tipe)
{
    int i = 0;
    while (i < 3)
    {
        if (tipe_pasukan_tersedia[i] == tipe)
            return true;
        i++;
    }
    return false;
}

void tambahBatalyon()
{
    Batalyon newBatalyon;
    cout << "Masukkan ID: ";
    cin >> newBatalyon.id;
    cout << "Masukkan Nama General: ";
    cin >> newBatalyon.nama_general;

    if (isNamaGeneralExist(newBatalyon.nama_general))
    {
        cout << "Error: Nama general sudah terdaftar.\n";
        return;
    }

    cout << "Masukkan Tipe Pasukan (Infantry/Kavaleri/Archer): ";
    cin >> newBatalyon.tipe_pasukan;
    if (!isTipePasukanValid(newBatalyon.tipe_pasukan))
    {
        cout << "Error: Tipe pasukan tidak valid.\n";
        return;
    }

    cout << "Masukkan Jumlah Pasukan: ";
    cin >> newBatalyon.jumlah_pasukan;
    if (newBatalyon.jumlah_pasukan < 1)
    {
        cout << "Error: Jumlah pasukan harus lebih dari 0.\n";
        return;
    }

    batalyon_list[batalyon_count++] = newBatalyon;
    cout << "Batalyon berhasil ditambahkan!\n";
}

void binarySearchBatalyon()
{
    if (batalyon_count == 0)
    {
        cout << "Tidak ada batalyon yang terdaftar.\n";
        return;
    }

    string nama;
    cout << "Masukkan Nama General yang dicari: ";
    cin >> nama;
    int left = 0, right = batalyon_count - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (batalyon_list[mid].nama_general == nama)
        {
            cout << "Batalyon ditemukan:\n";
            cout << "ID: " << batalyon_list[mid].id << "\n";
            cout << "Nama General: " << batalyon_list[mid].nama_general << "\n";
            cout << "Tipe Pasukan: " << batalyon_list[mid].tipe_pasukan << "\n";
            cout << "Jumlah Pasukan: " << batalyon_list[mid].jumlah_pasukan << "\n";
            return;
        }
        if (batalyon_list[mid].nama_general < nama)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "Batalyon tidak ditemukan.\n";
}

int main()
{
    int pilihan;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Batalyon\n";
        cout << "2. Cari Batalyon\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBatalyon();
            break;
        case 2:
            binarySearchBatalyon();
            break;
        case 3:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);

    return 0;
}
