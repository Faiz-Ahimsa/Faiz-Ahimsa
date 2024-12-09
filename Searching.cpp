#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void search_angka(const vector<int> &arr, int target){ // buat fungsi untuk mencari angka
    bool found = false; // Menandai apakah angka ditemukan atau tidak
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target){
            if(!found) { // Jika ini pertama kalinya ditemukan
                cout<< "Angka ditemukan di indeks ke-" << i + 1;
            } else { // Jika sudah ditemukan sebelumnya
                cout << " dan ke-" << i + 1;
            }
            found = true; // Tandai angka sudah ditemukan
        }
    }
    if (!found) { // Jika tidak ditemukan
        cout << "Angka tidak ditemukan.\n";
    } else {
        cout << endl; // Baris baru setelah daftar indeks
    }
}

void search_kata(const vector<string> &arr, const string &target){
    bool found = false;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target){
            if(!found){
                cout<< "Kata ditemukan pada indeks ke-"<< i + 1;
            } else {
                cout << " dan ke-" << i + 1;
            }
                found = true;
        }
    }
    if (!found) {
        cout << "Kata tidak ditemukan.\n";
    } else {
        cout << endl;
    }
}

void view_array(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}

void view_array(const vector<string> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}

int main(){
    char ulang;

    do{
        int choose;
        cout<< "Ingin mencari apa?\n1.Angka\n2.Kata\npilih: ";
        cin>> choose;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(choose == 1){
            string input;
            cout<< "Inputkan angka-angka dan pisahkan dengan spasi: ";
            getline(cin, input);

            vector<int> array_angka;
            stringstream ss(input); 
            int angka;

            while(ss >> angka){
                array_angka.push_back(angka);
            }

            cout<< "Angka tersimpan: ";
            view_array(array_angka);

            cout<< "Input angka yang ingin anda cari: ";
            cin>> angka;

            search_angka(array_angka, angka);
        } else if(choose == 2){
            string input;
            cout<< "Inputkan kata-kata atau  huruf dan pisahkan dengan spasi: ";
            getline(cin, input);

            vector<string> array_kata;
            stringstream ss(input);
            string kata;

            while(ss >> kata){
                array_kata.push_back(kata);
            }

            cout<< "Array yang tersimpan: ";
            view_array(array_kata);

            cout<< "Input kata yang ingin anda cari: ";
            cin>> kata;

            search_kata(array_kata, kata);
        } else{
            cout<< "Pilihan tidak valid.\n";
        }

        cout<< "Apakah anda ingin mengulang? ";
        cin>> ulang;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (ulang == 'y' || ulang == 'Y');

    cout<< "\n\t=== Program selesai, Terimakasih! ==="<< endl;
    return 0;
}
