// BAGIAN HEADER / LIBRARY
#include <iostream> // library berisi perintah standar input/output 
#include <string> // lib untuk mengoprasikan objek string
#include <windows.h> // lib fungsi sistem operasi windows
#include <queue> // mengimplementasikan antrean

using namespace std; // import fungsi-fungsi lib standar cpp, ex: tanpa menuliskan std:: pada baris kode

// Menentukan/mendefinisikan struktur(struct) utk setiap pertanyaan
struct Pertanyaan {
    // deklarasi variable
    string kategori; 
    string pertanyaan;
    string pilihan[4];
    int jawaban;
};

// Tentukan fungsi untuk menampilkan pertanyaan
void tampilkanPertanyaan(Pertanyaan q) {
    cout << "Kategori: " << q.kategori << endl;
    cout << "Pertanyaan: " << q.pertanyaan << endl;
    for (int i = 0; i < 4; i++) { 
        cout << i+1 << ". " << q.pilihan[i] << endl;
    }
}

// Tentukan fungsi untuk memeriksa jawabannya
bool periksaJawaban(Pertanyaan q, int ans) {
    return (q.jawaban == ans);
}

int main() {
    // Tentukan pertanyaan untuk setiap kategori
    // data pertanyaan dibuat menggunakan array
    // array dibawah ini berisi, kolom 1 : kategori, kolom 2 : pertanyaan, kolom selanjutnya pilihan jawaban, dan jawaban benar dengan isi angka sesuai urut.
    Pertanyaan pengetahuanUmum[3] = {
        {"Pengetahuan Umum", "Apa ibukota Indonesia?", {"Jakarta", "Bandung", "Surabaya", "Medan"}, 1},
        {"Pengetahuan Umum", "Apa planet terbesar di tata surya kita?", {"Jupiter", "Saturnus", "Uranus", "Neptunus"}, 1},
        {"Pengetahuan Umum", "Apa negara terkecil di dunia?", {"Monako", "Kota Vatikan", "San Marino", "Liechtenstein"}, 2}
    };
    
    Pertanyaan sejarah[3] = {
        {"Sejarah", "Pada tahun berapa Perang Dunia II berakhir?", {"1943", "1944", "1945", "1946"}, 3},
        {"Sejarah", "Siapa presiden pertama Indonesia?", {"Soekarno", "Soeharto", "BJ Habibie", "Gus Dur"}, 1},
        {"Sejarah", "Siapa manusia pertama yang berjalan di bulan?", {"Neil Armstrong", "Buzz Aldrin", "Yuri Gagarin", "Alan Shepard"}, 1}
    };
    
    Pertanyaan olahraga[3] = {
        {"Olahraga", "Negara mana yang memenangkan Piala Dunia FIFA pada tahun 2018?", {"Brazil", "Germany", "France", "Spain"}, 3},
        {"Olahraga", "Siapa yang memenangkan medali emas di tenis tunggal putra di Olimpiade Tokyo 2021?", {"Novak Djokovic", "Alexander Zverev", "Pablo Carreno Busta", "Karen Khachanov"}, 2},
        {"Olahraga", "Tim mana yang memenangkan kejuaraan NBA pada tahun 2021?", {"Los Angeles Lakers", "Brooklyn Nets", "Milwaukee Bucks", "Golden State Warriors"}, 3}
    };
    
    // Tentukan antrean untuk menyimpan pertanyaan
    queue<Pertanyaan> q;
    
    // Tambahkan pertanyaan ke antrean berdasarkan input pengguna
    int pilihan;
    char y,n;
    awal:
    cout << "* Selamat Datang di Permainan Quiz *" << endl;
    cout << endl;
    cout << "Pilih kategori:" << endl;
    cout << "[1] Pengetahuan Umum" << endl;
    cout << "[2] Sejarah" << endl;
    cout << "[3] Olahraga" << endl;
    cin >> pilihan;
    
    switch (pilihan) {
        case 1:
            for (int i = 0; i < 3; i++) {
                q.push(pengetahuanUmum[i]); // menambahkan pertanyaan kat. pengetahuan umum kedlm antrean
            }
            break;
        case 2:
            for (int i = 0; i < 3; i++) { 
                q.push(sejarah[i]); // menambahkan pertanyaan kat. sejarah kedlm antrean
            }
            break;
        case 3:
            for (int i = 0; i < 3; i++) {
                q.push(olahraga[i]); // menambahkan pertanyaan kat. olahraga kedlm antrian
            }
            break;
        default:
            cout << "Pilihan tidak sah." << endl;
            return 0;
    }
    
    // Ulangi setiap pertanyaan dalam antrean dan tanyakan
    int nilai = 0;
    while (!q.empty()) { 
        Pertanyaan pertanyaanSaatIni = q.front(); // mengambil element pertama pertanyaan
        q.pop(); // menghapus pertanyaan terakhir 
        
        tampilkanPertanyaan(pertanyaanSaatIni);
        
        int jawaban;
        cout << "\nMasukkan jawaban anda (1-4): ";
        cin >> jawaban;
        
        if (periksaJawaban(pertanyaanSaatIni, jawaban)) {
            cout << "\nBenar!" << endl;
            nilai++;
        } else {
            cout << "\nSalah." << endl; 
        }
        
        cout << "\nTekan enter untuk melanjutkan..." << endl;
        cin.ignore();
        cin.get();
        
        system("CLS"); // membersihkan layar
    }
    
    // Menampilkan nilai akhir
    cout << "* Quiz Berakhir *" << endl;
    cout << "\nNilai anda: " << nilai << "/3" << endl;
    cout << "Ingin diulang? (y/n) ";cin>>y;
            switch(y){
                case 'y':
                case 'Y':
                    system("CLS");
                    goto awal;
                    break;
                case 'n':
                case 'N':
                break;
            }
}