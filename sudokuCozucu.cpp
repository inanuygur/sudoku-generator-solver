#include <bits/stdc++.h>
#include <time.h>

using namespace std;

// create board
vector<vector<int>> tabloUret(int zorluk);
// sudoku solver
vector<vector<int>> sudokuCozucu(vector<vector<int>> tablo);
// check if a value is okay at a position
bool degerPozisyonUygun(int deger, int satir, int sutun, vector<vector<int>> &tablo);
// partial sudoku solver
bool sudokuKismiCozucu(int satir, int sutun, vector<vector<int>> &tablo);
// try a value
bool degerDene(int satir, int sutun, vector<vector<int>> &tablo);
// fill diagonal 3 subgrids
void caprazDoldur(vector<vector<int>> &tablo, vector<int> sayilar);
// display board
void tabloGoster(vector<vector<int>> tablo);

int main(){
    cout << "\nSudoku Generator & Solver\n";
    cout << "-----------------------------\n\n";

    int zorluk;
    cout << "Zorluk seviyesi giriniz [1(en kolay) - 100(en zor)]: ";
    cin >> zorluk;
    cout << "\n";

    // alinan zorluk seviyesinde bir tablo yarat
    // create a board with given difficulty level
    vector<vector<int>> uretilenTablo = tabloUret(zorluk);
    
    // tablo goster
    // display board
    tabloGoster(uretilenTablo);
    
    // uretilen tabloyu coz
    // solve the generated board
    vector<vector<int>> tabloSonuc = sudokuCozucu(uretilenTablo);
    
    // tablo goster
    // display board
    tabloGoster(tabloSonuc);

    return 0;
}

// display board
/*
*/
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
// --------------- GENERATİON PART --------------- //
// generate baard
/*
 * This function takes a diffuculty level as its input and generates a board.
 * Process: 
 *      1. Fill the diagonal 3 subgrids with random digits accordingly (without using same digit twice).
 *      2. Solve the half created board.
 *      3. Try to remove random numbers and make sure the resulting board 
 *          doesn't change with removed number.
 */
vector<vector<int>> tabloUret(int zorluk){
    vector<vector<int>> tablo = {};
    vector<int> sifirlar = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> sayilar = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    srand(time(NULL));

    for(int i = 0; i < 9; i++){
        tablo.push_back(sifirlar);
    }

    // fill the diagonal subgrids
    caprazDoldur(tablo, sayilar);
    // solve created board
    vector<vector<int>>doluTablo = sudokuCozucu(tablo);
    // try to remove elements randomly and check if it is solveable and the resulting
    // boarad is the same with previously filled board. 
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

// fill diagonal 3 subgrids
/*
 * This funstion takes a board and an array of digits as its input and fills 
 *  the board's diagonal 3 subgrids. 
 * Process:
 *      1. Mix the digit array.
 *      2. Change the value of empty board as going along the mixed digits. 
 */
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
// ---------------- URETICI KISIM SONU ---------------- //
// -------------- END OF GENERATİON PART -------------- //


// ---------------- COZUCU KISIM ---------------- //
// ----------------- SOLVER PART ---------------- //
// main solver function
vector<vector<int>> sudokuCozucu(vector<vector<int>> tablo){
    sudokuKismiCozucu(0, 0, tablo);
    return tablo;
}

// partial sudoku solver
/*
 * This function takes a row, a column and a board as its input and tries 
 *  to fill the the given row and column recursively.
 * Process: 
 *      1. Check if given row and column is empty, if so, try a digit. 
 *      2. If a value is set to given row and column, go next number in the same row.
 *          If row is ended, go next row.
 *      3. Try to do 1. and 2. for every row beginning with first.
 *      4. Once you acheive last row and column, it means you filled the board. 
 */
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

// try a value
/*
 * This function tries to find an appropriate number for given row and column 
 *  for that state of the board.
 * Process: 
 *      1. Try a digit from 1 to 9, check if it is okay. 
 *      2. If a digit is okay, go back to partial solver. 
 *      3. If any number is not okay, some number is misplaced.
 */
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

// check if a value is okay at a position
/*
 * This function checks if a value is okay for given row, column and subgrid.
 * Process:
 *      1. Check if row is okay.
 *      2. Check if column is okay.
 *      3. Check if subgrid is okay.
 *      4. Any problem will return false.
 */
bool degerPozisyonUygun(int deger, int satir, int sutun, vector<vector<int>> &tablo){

    // satir uygunluk kontrolu
    // row control
    bool satirUygun = find(tablo[satir].begin(), tablo[satir].end(), deger) == tablo[satir].end();
    bool sutunUygun = true;
    // sutun uygunluk kontrolu
    // column control
    for(auto anlikSatir : tablo){
        if(anlikSatir[sutun] == deger){
            sutunUygun = false;
            break;
        }
    }

    if(!satirUygun || !sutunUygun)
        return false;

    // kucuk kare kontrolu
    // subgrid control
    int kucukKareSatirBaslangici = (satir / 3) * 3;
    int kucukKareSutunBaslangici = (sutun / 3) * 3;
    for(int satirIndeks = 0; satirIndeks < 3; satirIndeks++){
        for(int sutunIndeks = 0; sutunIndeks < 3; sutunIndeks++){
            // eklemek istenilen deger kucuk kare icerisinde var ise false don
            // if given value is in the subgrid, return false
            if (tablo[kucukKareSatirBaslangici + satirIndeks][kucukKareSutunBaslangici + sutunIndeks] == deger){
                return false;
            }
        }
    }

    return true;
}
// ---------------- COZUCU KISIM ---------------- //
// ------------- END OF SOLVER PART ------------- //

// SON
// END
