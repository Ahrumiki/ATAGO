#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


class Suatchieu {
    private:
    string Stt;
    string maphim;
    string TimeBegin;
    int price;

    public:
    Suatchieu(string = "",string = "", string = "", int = 0);
    ~Suatchieu();

    void setTimeBegin();
    void setprice();
    void setstt();
    
    static void themsuatchieu();
    static void insuatchieucuaphim();
    static void insuatchieucuaphim(string = "");
    static string** inseat();
}; 