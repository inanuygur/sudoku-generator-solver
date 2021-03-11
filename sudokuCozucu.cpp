#include <bits/stdc++.h>
#include <time.h>

using namespace std;

vector<vector<int>> tabloUret(int zorluk);
vector<vector<int>> sudokuCozucu(vector<vector<int>> tablo);
bool degerPozisyonUygun(int deger, int satir, int sutun, vector<vector<int>> &tablo);
bool sudokuKismiCozucu(int satir, int sutun, vector<vector<int>> &tablo);
bool degerDene(int satir, int sutun, vector<vector<int>> &tablo);
void caprazDoldur(vector<vector<int>> &tablo, vector<int> sayilar);
void tabloGoster(vector<vector<int>> tablo);

int main(){

    // 80 zorlugu olan bir sudoku tablosu yarat
    vector<vector<int>> uretilenTablo = tabloUret(80);
    // tablo goster
    tabloGoster(uretilenTablo);
    // uretilen tabloyu coz
    vector<vector<int>> tabloSonuc = sudokuCozucu(uretilenTablo);
    // tablo goster
    tabloGoster(tabloSonuc);

    return 0;
}

void tabloGoster(vector<vector<int>> tablo){
    for(int satirIdx = 0; satirIdx < tablo.size(); satirIdx++){
        vector<int> satir = tablo[satirIdx];
        for(int sutunIdx = 0; sutunIdx < satir.size(); sutunIdx++){
            int deger = satir[sutunIdx];
            cout << deger << " ";
            if((sutunIdx + 1) % 3 == 0 && sutunIdx != satir.size() - 1)
                cout << "| ";
        }
        cout << "\n";
        if((satirIdx + 1) % 3 == 0 && satirIdx != tablo.size() - 1){
            for(int i = 0; i < 21; i++){
                cout << "-";
            }
            cout << "\n";
        }
    }
    cout << "\n\n";
}

// ---------------- URETICI KISIM ---------------- //
//
vector<vector<int>> tabloUret(int zorluk){
    vector<vector<int>> tablo = {};
    vector<int> sifirlar = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> sayilar = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    srand(time(NULL));

    for(int i = 0; i < 9; i++){
        tablo.push_back(sifirlar);
    }

    // 
    caprazDoldur(tablo, sayilar);
    // 
    vector<vector<int>>doluTablo = sudokuCozucu(tablo);
    //
    for(int i = 0; i < zorluk; i++){
        int rastgeleSatir = rand() % 9;
        int rastgeleSutun = rand() % 9;
        int geciciDeger = doluTablo[rastgeleSatir][rastgeleSutun];
        doluTablo[rastgeleSatir][rastgeleSutun] = 0;
        if(sudokuCozucu(doluTablo) != sudokuCozucu(tablo)){
            doluTablo[rastgeleSatir][rastgeleSutun] = geciciDeger;
        }
    }

    return doluTablo;
}

void caprazDoldur(vector<vector<int>> &tablo, vector<int> sayilar){

    int sayiIdx = 0;
    for(int caprazSatir = 0; caprazSatir < 9; caprazSatir++){
        
        if(caprazSatir % 3 == 0){
            for(int i = 0; i < 9; i++){
                swap(sayilar[rand() % 9], sayilar[rand() % 9]);
            }
            sayiIdx = 0;
        }

        for(int caprazSutun = 0; caprazSutun < 3; caprazSutun++){
            int satirIdx = caprazSatir;
            int sutunIdx = (caprazSatir / 3) * 3 + caprazSutun;
            tablo[satirIdx][sutunIdx] = sayilar[sayiIdx];
            // cout << sayiIdx << " "; 
            sayiIdx += 1;
        }
    }
    
    // cout << "\n\n";
}
// ---------------- URETICI KISIM ---------------- //


// ---------------- COZUCU KISIM ---------------- //
vector<vector<int>> sudokuCozucu(vector<vector<int>> tablo){
    sudokuKismiCozucu(0, 0, tablo);
    return tablo;
}

//
bool sudokuKismiCozucu(int satir, int sutun, vector<vector<int>> &tablo){
    
    int suankiSatir = satir;
    int suankiSutun = sutun;

    if (suankiSutun == tablo[suankiSatir].size()){
        suankiSatir++;
        suankiSutun = 0;
        if(suankiSatir == tablo.size())
            return true;
    }

    if (tablo[suankiSatir][suankiSutun] == 0){
        return degerDene(suankiSatir, suankiSutun, tablo);
    }

    return sudokuKismiCozucu(suankiSatir, suankiSutun + 1, tablo);
}

//
bool degerDene(int satir, int sutun, vector<vector<int>> &tablo){

    for (int rakam = 1; rakam < 10; rakam++){
        if (degerPozisyonUygun(rakam, satir, sutun, tablo)){
            tablo[satir][sutun] = rakam;
            if(sudokuKismiCozucu(satir, sutun + 1, tablo)){
                return true;
            }
        }   
    }

    tablo[satir][sutun] = 0;
    return false;
}

//
bool degerPozisyonUygun(int deger, int satir, int sutun, vector<vector<int>> &tablo){

    // satir uygunluk kontrolu
    bool satirUygun = find(tablo[satir].begin(), tablo[satir].end(), deger) == tablo[satir].end();
    bool sutunUygun = true;
    // sutun uygunluk kontrolu
    for(auto anlikSatir : tablo){
        if(anlikSatir[sutun] == deger){
            sutunUygun = false;
            break;
        }
    }

    if(!satirUygun || !sutunUygun)
        return false;

    // kucuk kare kontrolu
    int kucukKareSatirBaslangici = (satir / 3) * 3;
    int kucukKareSutunBaslangici = (sutun / 3) * 3;
    for(int satirIndeks = 0; satirIndeks < 3; satirIndeks++){
        for(int sutunIndeks = 0; sutunIndeks < 3; sutunIndeks++){
            // eklemek istenilen deger kucuk kare icerisinde var ise false don
            if (tablo[kucukKareSatirBaslangici + satirIndeks][kucukKareSutunBaslangici + sutunIndeks] == deger){
                return false;
            }
        }
    }

    return true;
}
// ---------------- COZUCU KISIM ---------------- //

// SON