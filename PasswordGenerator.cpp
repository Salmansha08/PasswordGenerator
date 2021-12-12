#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

int getPilihanMenu ();
void Program();
void About();

int main () {
    Ngulang_Balik_lagi:
    int input_2 = getPilihanMenu();
    enum opsi{Program_Generator = 1, Tentang_Program, Keluar}; 
    if (input_2 < 1 || input_2 > 3){
        cout << "___________" << endl;
        cout << "Pilihan Tidak Ditemukan, PILIH YANG BENER DONGGGGGGGG!!!" << endl;
        cout << "___________" << endl;
    }
        else if (input_2 == Program_Generator){
            Program();
        }
        else if (input_2 == Tentang_Program){
            About();
        }
        else if (input_2 == Keluar){
            char lanjut_or_enggak;
            Takut_Ada_Yang_Usil:
            cout << "___________" << endl;
            cout << "Apakah Anda Ingin Melanjutkan Keluar Dari Program Ini ? (y/n) = ";
            cin >> lanjut_or_enggak;
            if ((lanjut_or_enggak == 'y' | lanjut_or_enggak == 'Y')){
                cout << "___________" << endl;
                cout << "Bye Bye.., Sampai Jumpa Kembali" << endl;
                cout << "Terima Kasih Telah Memakai Program Kami..." << endl;
                cout << "___________" << endl;
                }
                else if ((lanjut_or_enggak == 'n' | lanjut_or_enggak == 'N')){
                    goto Ngulang_Balik_lagi; 
                }
                else {
                    goto Takut_Ada_Yang_Usil;
                }
    }
    return 0;
}


int getPilihanMenu (){
    int input;
    cout << "SELAMAT DATANG DI PROGRAM RANDOM GENERATOR PASSWORD" << endl; 
	cout << "1. Program Random Generator Password" << endl;
    cout << "2. Tentang Program Kami" << endl;
	cout << "3. Keluar" << endl;
	cout << "____________________________________________________" << endl;
	cout << "Silahkan Pilih Menu [1-3] = ";
	cin >> input;
    return input;
}

void Program()
{
    cout << "___________" << endl;
    cout << "___________" << endl;
    char alphanum[] = "0123456789!#$%&*()/-+abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int length_alphanum = sizeof(alphanum)-1;
    int panjang_password;
    srand(time(0));
    
    cout << "Beberapa Character yang Akan Dijadikan Password" << endl;
    for (int i = 0; i < length_alphanum; i++){
       for (int j = 0; j < length_alphanum-i-1; j++){
           if (alphanum[j]>alphanum[j+1]){
               char tmp = alphanum[j];
               alphanum[j] = alphanum[j+1];
               alphanum[j+1]= tmp;
           }
       }
    }
    for (int k = 0; k < length_alphanum; k++){
        cout << alphanum[k] << " ";
    }
    cout << endl;
    cout << "___________" << endl;

    cout << "Masukkan Panjang Password yang Diinginkan = ";
    cin >> panjang_password;
    cout << "___________" << endl;

    char tmp_pass_char[panjang_password];
    string data_pass_str = "";
    char data_pass_char[panjang_password];
    //RAW Random pilihan hasil ke-1
    cout<<"Pilihan ke-1 Hasil Random Generated Password = ";
    for(int i = 0; i < panjang_password; i++){
        int acak = rand() % length_alphanum;
        tmp_pass_char[i] = alphanum[acak];
    }

        //char to string
        for(int i = 0; i < panjang_password; i++){
            data_pass_str = data_pass_str + tmp_pass_char[i];
        }
        cout << data_pass_str;
        cout << endl;
        //string to char
        int n = data_pass_str.length();
        char char_array[n+1];
        strcpy(char_array, data_pass_str.c_str());

        ofstream fileResult_1;
            fileResult_1.open("Pilihan ke-1_Generator_Password.txt");
                fileResult_1 << "Hasil Pilihan ke-1 dari Program Generator Password Adalah : "<< endl;
                fileResult_1 << "___________________________________________________________"<< endl;
                    fileResult_1 << data_pass_str;
            fileResult_1.close();
        
    
    //Ascending pilihan hasil ke-2
    cout << "Pilihan ke-2 Hasil Random Generated Password = ";
    for (int i = 0; i < panjang_password; i++){
       for (int j = 0; j < panjang_password-i-1; j++){
           if (char_array[j]>char_array[j+1]){
               char tmp = char_array[j];
               char_array[j] = char_array[j+1];
               char_array[j+1]= tmp;
           }
       }
    }
    for (int k = 0; k < panjang_password; k++){
        cout << char_array[k];
    }
    cout << endl;
        ofstream fileResult_2;
            fileResult_2.open("Pilihan ke-2_Generator_Password.txt");
                fileResult_2 << "Hasil Pilihan ke-2 dari Program Generator Password Adalah : "<< endl;
                fileResult_2 << "___________________________________________________________"<< endl;
                    for (int k = 0; k < panjang_password; k++){
                    fileResult_2 << char_array[k];
                } 
            fileResult_2.close();

    //Descensing pilihan hasil ke-3
    cout << "Pilihan ke-3 Hasil Random Generated Password = ";
    for (int i = 0; i < panjang_password; i++){
       for (int j = 0; j < panjang_password-i-1; j++){
           if (char_array[j]<char_array[j+1]){
               char tmp = char_array[j];
               char_array[j] = char_array[j+1];
               char_array[j+1]= tmp;
           }
       }
    }
    for (int k = 0; k < panjang_password; k++){
        cout << char_array[k];
    }
    ofstream fileResult_3;
            fileResult_3.open("Pilihan ke-3_Generator_Password.txt");
                fileResult_3 << "Hasil Pilihan ke-3 dari Program Generator Password Adalah : "<< endl;
                fileResult_3 << "___________________________________________________________"<< endl;
                    for (int k = 0; k < panjang_password; k++){
                    fileResult_3 << char_array[k];
                } 
            fileResult_3.close();

    //Nilai tertinggi di tengah pilihan hasil ke-4
    cout << endl;
    cout << "Pilihan ke-4 Hasil Random Generated Password = ";
    if(panjang_password%2==1){
        for (int i = 0; i < panjang_password; i++){
        for (int j = 0; j < panjang_password-i-1; j++){
           if (char_array[j]>char_array[j+1]){
               char tmp = char_array[j];
               char_array[j] = char_array[j+1];
               char_array[j+1]= tmp;
                }
            }
        }
        for (int k = 0; k < panjang_password; k++){
            if(k%2==0){
                cout << char_array[k];
            }
        }
        ofstream fileResult_4;
            fileResult_4.open("Pilihan ke-4_Generator_Password.txt");
                fileResult_4 << "Hasil Pilihan ke-4 dari Program Generator Password Adalah : "<< endl;
                fileResult_4 << "___________________________________________________________"<< endl;
                    for (int k = 0; k < panjang_password; k++){
                        if(k%2==0){
                            fileResult_4 << char_array[k];
                        }
                    } 
        for (int i = 0; i < panjang_password; i++){
            for (int j = 0; j < panjang_password-i-1; j++){
                if (char_array[j]<char_array[j+1]){
                    char tmp = char_array[j];
                    char_array[j] = char_array[j+1];
                    char_array[j+1]= tmp;
                }
            }
        }
        for (int k = 0; k < panjang_password; k++){
            if(k%2==1){
                cout << char_array[k];
            }
        }   
                    for (int k = 0; k < panjang_password; k++){
                        if(k%2==1){
                            fileResult_4 << char_array[k];
                        }
                    } 
            fileResult_4.close();
    }
    else if (panjang_password%2==0){
        for (int i = 0; i < panjang_password-1; i++){
        for (int j = 0; j < panjang_password-i-2; j++){
           if (char_array[j]>char_array[j+1]){
               char tmp = char_array[j];
               char_array[j] = char_array[j+1];
               char_array[j+1] = tmp;
                }
            }
        }
        for (int k = 0; k < panjang_password; k++){
            if(k%2==0){
                cout << char_array[k];
            }
        }
        ofstream fileResult_5;
            fileResult_5.open("Pilihan ke-4_Generator_Password.txt");
                fileResult_5 << "Hasil Pilihan ke-4 dari Program Generator Password Adalah : "<< endl;
                fileResult_5 << "___________________________________________________________"<< endl;
                    for (int k = 0; k < panjang_password; k++){
                        if(k%2==0){
                            fileResult_5 << char_array[k];
                        }
                    } 
        for (int i = 0; i < panjang_password; i++){
            for (int j = 0; j < panjang_password-i-1; j++){
                if (char_array[j]<char_array[j+1]){
                    char tmp = char_array[j];
                    char_array[j] = char_array[j+1];
                    char_array[j+1]= tmp;
                }
            }
        }
        for (int k = 0; k < panjang_password; k++){
            if(k%2==1){
                cout << char_array[k];
            }
        }
                    for (int k = 0; k < panjang_password; k++){
                        if(k%2==1){
                            fileResult_5 << char_array[k];
                        }
                    } 
            fileResult_5.close();
    }

    //Nilai terendah di tengah pilihan hasil ke-5
    cout << endl;
    cout << "Pilihan ke-5 Hasil Random Generated Password = ";
    if(panjang_password%2==1){
        for (int i = 0; i < panjang_password; i++){
        for (int j = 0; j < panjang_password-i-1; j++){
           if (char_array[j]<char_array[j+1]){
               char tmp = char_array[j];
               char_array[j] = char_array[j+1];
               char_array[j+1]= tmp;
                }
            }
        }
        for (int k = 0; k < panjang_password; k++){
            if(k%2==0){
                cout << char_array[k];
            }
        }
        ofstream fileResult_6;
            fileResult_6.open("Pilihan ke-5_Generator_Password.txt");
                fileResult_6 << "Hasil Pilihan ke-5 dari Program Generator Password Adalah : "<< endl;
                fileResult_6 << "___________________________________________________________"<< endl;
                    for (int k = 0; k < panjang_password; k++){
                        if(k%2==0){
                            fileResult_6 << char_array[k];
                        }
                    } 
        for (int i = 0; i < panjang_password; i++){
            for (int j = 0; j < panjang_password-i-1; j++){
                if (char_array[j]>char_array[j+1]){
                    char tmp = char_array[j];
                    char_array[j] = char_array[j+1];
                    char_array[j+1]= tmp;
                }
            }
        }
        for (int k = 0; k < panjang_password; k++){
            if(k%2==1){
                cout << char_array[k];
            }
        }   
                    for (int k = 0; k < panjang_password; k++){
                        if(k%2==1){
                            fileResult_6 << char_array[k];
                        }
                    } 
            fileResult_6.close();
    }
    else if (panjang_password%2==0){
        for (int i = 0; i < panjang_password-1; i++){
        for (int j = 0; j < panjang_password-i-2; j++){
           if (char_array[j]<char_array[j+1]){
               char tmp = char_array[j];
               char_array[j] = char_array[j+1];
               char_array[j+1] = tmp;
                }
            }
        }
        for (int k = 0; k < panjang_password; k++){
            if(k%2==0){
                cout << char_array[k];
            }
        }
        ofstream fileResult_7;
            fileResult_7.open("Pilihan ke-5_Generator_Password.txt");
                fileResult_7 << "Hasil Pilihan ke-5 dari Program Generator Password Adalah : "<< endl;
                fileResult_7 << "___________________________________________________________"<< endl;
                    for (int k = 0; k < panjang_password; k++){
                        if(k%2==0){
                            fileResult_7 << char_array[k];
                        }
                    } 
        for (int i = 0; i < panjang_password; i++){
            for (int j = 0; j < panjang_password-i-1; j++){
                if (char_array[j]>char_array[j+1]){
                    char tmp = char_array[j];
                    char_array[j] = char_array[j+1];
                    char_array[j+1]= tmp;
                }
            }
        }
        for (int k = 0; k < panjang_password; k++){
            if(k%2==0){
                cout << char_array[k];
            }
        }
                    for (int k = 0; k < panjang_password; k++){
                        if(k%2==0){
                            fileResult_7 << char_array[k];
                        }
                    } 
            fileResult_7.close();
    }
    
    cout << endl;
    cout << "___________" << endl;
    cout << "Bye Bye.., Sampai Jumpa Kembali" << endl;
    cout << "Terima Kasih Telah Memakai Program Kami & Silahkan Check File Txt nya..." << endl;
}

void About (){
    cout << "___________" << endl;
    cout << "___________" << endl;
    cout << "__________________________________________________________" << endl;
    cout << R"(
    Program ini di develop oleh kelompok 1 yang beranggotakan Dhimaz Purnama Adjhi dan Salman untuk memenuhi tugas UAS pada mata kuliah Stuktur Data dan Algoritma prodi Teknik Komputer. Program ini nantinya diharapkan untuk membuat password random agar sang pengguna meminimalisir terjadinya terkena serangan bruteforce pada kredensial pengguna. Karena emakin random password yang kita gunakan, makan akan semakin sulit password kita untuk ditembus oleh serangan bruteforce.
)" << endl;
    cout << "_______" << endl;
}