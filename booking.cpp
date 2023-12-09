#include "booking.h"

void Booking::Datve(string nameStaff)
{
    // khai báo biến
    staffManager staff_manager;
    movieManagement movie;
    suatchieumanager manager;
    manager.readFile();
    manager.resetseat();
    // in thong tin phim
    system("cls");
    movie.readFile();
    movie.printListMovies();

    // nhập thông tin khách hàng
    string customer;
    cout << "Customer Name: ";
    cin.ignore();
    getline(cin, customer);
    
    string id;
    cout << "Put in movie ID: ";
    cin >> id;

    // check movie id
    while (movie.checkPrimarykey(id) == true)
    {
        cout << "Movie not found. Try Again! :";
        cin >> id;
    }
    system("cls");

    // kiểm tra suất chiếu
    manager.checkId(id);

    // chọn suất chiếu
    string stt;
    cout << "Pick showtime you desire: ";
    cin >> stt;

    while (stoi(stt) > 6)
    { 
        cout << "Showtime you picked doesn't exist. Please pick again!: ";
        cin >> stt;
    }

    // chọn ghế , số lượng vé
    string m = manager.readseat(id, stt);
    // manager.print_Pre_seat(m);
    cout << "Ticket's quantity: ";
    int count;
    cin >> count;

    // chọn ghế
    system("cls");
    ticket s[count];
    string seat;
    for (int i = 0; i < count; i++)
    {
        manager.print_Pre_seat(m);
        if (i > 0)
            cout << "Booked successed! " << seat << endl;
        seat = manager.pickseat();
        m = m + ";" + seat;
        s[i].setId(to_string(i)); 
        s[i].setCustomer(customer);
        s[i].setMovieName(manager.getmoviename(id));
        s[i].setMovieTime(manager.getmovietime(id, stt));
        s[i].setSeat(seat);
        s[i].setPrice(55000);
        s[i].setBuyTime();
        s[i].setNameStaff(nameStaff);
       s[i].setStaff_id(staff_manager.getStaffId(nameStaff));
        system("cls");
    }
    system("cls");

    // in thông tin vé , lưu thông tin vé vô csdl
    manager.setmovieseat(id, stt, m);
    for (int i = 0; i < count; i++)
    {
        s[i].show();
        cout << endl;
    }

    cout << "The total amount you need to pay is " << 55000 * count << "VND.    Y/N" << endl;
    char temp;
    cin >> temp;

    if (temp == 'y' || temp == 'Y')
    {
        system("cls");
        cout << "\t\t\t Paid successed!. Thank you for chose our service!" << endl;
        system("pause");
        for (int i = 0; i < count; i++)
        {
            s[i].SaveToFile();
        }
        manager.writeFile();
    }
    else if (temp == 'n' || temp == 'N')
    {
        cout << "You have cancelled the payment." << endl;
        system("pause");
    }
}
