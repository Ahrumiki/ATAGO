#include "suatchieu.h"




Suatchieu::Suatchieu(string MaMovie, string Begin, int price) {
    this->maphim = MaMovie;
    this->TimeBegin = Begin;
    this->price = price;
} 

Suatchieu::~Suatchieu(){

}

void Suatchieu::setTimeBegin(){
    cout << "Thoi gian bat dau: ";
    string begin;
    cin >> begin;
    this->TimeBegin = begin;
    cout << endl;
}

void Suatchieu::setprice() {
    cout << "Gia: ";
    int price;
    cin >> price;
    this->price = price;
    cout << endl;
}


bool Checkmaphim(const std::string& filename, const std::string& prefix) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Không thể mở tệp " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.compare(0, prefix.size(), prefix) == 0) {
            file.close(); 
            return true;
        }
    }

    file.close(); 
    return false;
}


void Insuatchieuvaotrongfile(string& filename, string& line) {
    // Đọc toàn bộ nội dung từ tệp vào một chuỗi.
    ifstream inFile(filename);
    string fileContent((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    // kiểm tra phim đó đã có suất chiếu nào chưa
    std::string prefixToFind = line.substr(0, 3); // 3 tức là kiểm tra 3 kí tự đầu tiên mỗi hàng
    size_t foundPosition = fileContent.find(prefixToFind);
    if (foundPosition != string::npos) {
        // nếu có rồi thì thêm suất chiếu mới vào ngay bên dưới các suất chiếu mới của phim đó trong file txt
        size_t nextLinePosition = fileContent.find("\n", foundPosition);
        if (nextLinePosition != string::npos) {
            // Thêm hàng mới xuống phía dưới của hàng trùng đó.
            fileContent.insert(nextLinePosition, "\n" + line);
        }
    } else {
        // nếu chưa có suất chiếu nào thì thêm vào cuối file .txt
        fileContent += "\n" + line;
    }

    // Ghi lại toàn bộ nội dung của chuỗi vào tệp văn bản.
    ofstream outFile(filename);
    outFile << fileContent;
    outFile.close();
}





void Suatchieu::themsuatchieu(){
    string filephim = "Movie_information.txt"; // file thông tin các phim đã tồn tại
    string filesuatchieu = "suatchieu.txt"; // file thông tin các suất chiếu của các phim
    cout << "Nhap ma phim: "; // nhập mã phim cần thêm suất chiếu mới
    string maphim;
    cin >>maphim;
    Suatchieu New;
    if(Checkmaphim(filephim, maphim) == true) { // hàm kiểm tra phim muốn thêm suất chiếu có tồn tại trong danh sách movie_information hay không
        cout << "Vui long nhap thong tin suat chieu cua ma phim " << maphim << endl;
        New.setTimeBegin();
        New.setprice();
        string Thongtinsuatchieu = maphim + ";" + New.TimeBegin + ";" + to_string(New.price);
        Insuatchieuvaotrongfile(filesuatchieu, Thongtinsuatchieu); // thêm thông tin vô file suatchieu.txt
    } 
    else cout << "Chua co phim do trong danh sach phim"; // nếu phim chưa tồn tại trong file movie_information thì hiện ra thông báo
}