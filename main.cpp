#include <iostream>
//#include <windows.h>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

struct detal
{
    string tov;
    string chena; //решить вопрос с неправильным вводом для int
    int indTov;
};

struct human
{   
    string email;
    string name;
    string surname;
};

struct zakazi
{
    string name;
    int indx;
    int colTov;
    struct size {
        int indTov;
        int couTov;
    }w[10];
    
};

class detl
{
private:
    detal to[10] = {
        {"Станок", "10", 1},
        {"Деталь", "20", 2},
        {"Колесо", "30", 3},
    };

public:
    ofstream fout;
    ifstream fin;
    int n = 3;
    void Print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "----------------------------------------------------" << endl;
            cout << "Наименование детали: " << setw(10) << (to + i)->tov << endl;;
            cout << "Цена: " << setw(25) << (to + i)->chena << endl;
            cout << "Индекс детали: " << setw(16) << (to + i)->indTov << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }

    void add()
    {
        if (n == 10)
        {
            cout << "Список деталей полон!" << endl;
            return;
        }
        cout << "Наименование детали:" << endl;
        string toname;
        cin >> toname;
        int status = 1;
        for (int i = 0; i < n; i++)
        {
            if (toname == to[i].tov)
            {
                status = 0;
                cout << "Данная деталь уже существует!" << endl;
                break;
            }
            
        }
        if (status){
            to[n].tov = toname;
            cout << "Цена:" << endl;
            cin >> to[n].chena;
            to[n].indTov = to[n-1].indTov + 1;
            n++;
        }    
    }

    void del()
    {
        if (n == 0)
        {
            cout << "Добавленных деталей нет!" << endl;
            return;
        }
        cout << "Индекс детали: " << endl;
        int ind;
        cin >> ind;
        int ito = -1;
        for (int i = 0; i < n; i++)
        {
            if (ind == to[i].indTov)
            {
                ito = i;
                break;
            }
        }
        if (ito == -1)
        {
            cout << "Такогой детали нет!" << endl;
            return;
        }
        to[ito] = to[n - 1];
        n--;
        cout << "Деталь успешно удалена!" << endl;
    }

    void change()
    {
        if (n == 0)
        {
            cout << "Деталей в списке нет!" << endl;
            return;
        }
        cout << "Введите индекс детали" << endl;
        int ind;
        cin >> ind;
        int ito = -1;
        for (int i = 0; i < n; i++)
        {
            if (ind == to[i].indTov)
            {
                cout << "Наименование детали: " << endl;
                cin >> to[i].tov;
                cout << "Цена: " << endl;
                cin >> to[i].chena;
                ito = i;
                break;
            }
        }
        if (ito == -1)
        {
            cout << "Такой детали нет!" << endl;
            return;
        }
        cout << "Данные успешно отредактированы!" << endl;
    }

    void wrfile()
    {
        fout.open("Детали.txt");
        fout << n << endl;
        for (int i = 0; i < n; i++)
        {
            fout << to[i].tov << endl;
            fout << to[i].chena << endl;
            fout << to[i].indTov << endl;
        }
        fout.close();
    }

    void rdfileZ()
    {
        fin.open("Детали.txt");
        fin >> n;
        fin.ignore();
        for (int i = 0; i < n; i++)
        {
            getline(fin, to[i].tov);
            cin >> (fin, to[i].chena);
            cin >> (fin, to[i].indTov);
            fin.ignore();
        }
        fin.close();
    }
};

class client
{
private:

public:
    human hu[20] = {
        {"cc@gmail.com", "Геннадий", "Персиков"},
        {"sdf@gmail.com","Елизавета", "Горская"},
        {"ddd@gmail.com","Валерий", "Арюпкин"},
    };
    ofstream fout;
    ifstream fin;
    int n = 3;
    void Print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "----------------------------------------------------" << endl;
            cout << "Email/ИНН (что-то уникальное): " << setw(11) << (hu + i)->email << endl;
            cout << "Имя заказчика:" << setw(11) << (hu + i)->name << endl;
            cout << "Фамилия заказчика:" << setw(11) << (hu + i)->surname << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }

    void add()
    {
        if (n == 10)
        {
            cout << "Список заказчиков полон!" << endl;
            return;
        }
        cout << "Имя заказчика:" << endl;
        cin >> hu[n].name;
        cout << " Фамилия заказчика:" << endl;
        cin >> hu[n].surname;
        cout << "Email/ИНН (что-то уникальное): " << endl;
        cin >> hu[n].email;
        n++;
    }

    void del()
    {
        if (n == 0)
        {
            cout << "Добавленных заказчиков нет!" << endl;
            return;
        }
        cout << "Email/ИНН (что-то уникальное): " << endl;
        string email;
        cin >> email;
        int ihu = -1;
        for (int i = 0; i < n; i++)
        {
            if (email == hu[i].email)
            {
                ihu = i;
                break;
            }
        }
        if (ihu == -1)
        {
            cout << "Такого заказчика нет!" << endl;
            return;
        }
        hu[ihu] = hu[n - 1];
        n--;
        cout << "Заказчик успешно удален!" << endl;
    }

    void change()
    {
        if (n == 0)
        {
            cout << "Добавленных заказчиков нет!" << endl;
            return;
        }
        cout << "Email/ИНН (что-то уникальное): " << endl;
        string email;
        cin >> email;
        int ihu = -1;
        for (int i = 0; i < n; i++)
        {
            if (email == hu[i].email)
            {
                cout << "Имя заказчика:" << endl;
                cin >> hu[i].name;
                cout << "Фамилия заказчика:" << endl;
                cin >> hu[i].surname;
                cout << "Email/ИНН (что-то уникальное): ";
                cin >> hu[i].email;
                ihu = i;
                break;
            }
        }
        if (ihu == -1)
        {
            cout << "Такого email нет!" << endl;
            return;
        }
        cout << "Заказчик успешно отредактирован!" << endl;
    }

    void wrfile()
    {
        fout.open("Zakazchiki.txt");
        fout << n << endl;
        for (int i = 0; i < n; i++)
        {
            fout << hu[i].name << endl;
            fout << hu[i].email << endl;
            fout << hu[i].surname << endl;
        }
        fout.close();
    }

    void rdfileZ()
    {
        fin.open("Заказчики.txt");
        fin >> n;
        fin.ignore();
        for (int i = 0; i < n; i++)
        {
            getline(fin, hu[i].name);
            getline(fin, hu[i].email);
            getline(fin, hu[i].surname);
            fin.ignore();
        }
        fin.close();
    }
};

class Zakazes: public client
{
private:
    zakazi zak[20] = {
        {"cc@gmail.com", 1, 2, {{2, 1}, {1, 3}}},
        {"sdf@gmail.com", 2, 2, {{3, 3}, {2, 4}}},
        {"ddd@gmail.com", 3, 2, {{1, 3}, {2, 4}}}};

public:
    ofstream fout;
    ifstream fin;
    int n = 3, indx = 3;
    void Print()
    {
        cout << "----------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Email заказчика: " << setw(22) << (zak + i) -> name << endl;
            cout << "Заказ номер:" << setw(22) << (zak + i) -> indx << endl;
            cout << "Количество различных товаров:" << setw(5) << (zak + i)->colTov << endl;
            for (int j = 0; j < zak[i].colTov; j++){
                cout << "Индекс товара:" << setw(20) << zak[i].w[j].indTov << endl;
                cout << "Количество товара:" << setw(16) << zak[i].w[j].couTov << endl;
                cout << "----------------------------------------------------" << endl;
            }
            cout << "----------------------------------------------------" << endl;
        }
    }

    void add()
    {
        int status = 0;
        string email;
        if (n == 10)
        {
            cout << "Список заказов полон!" << endl;
            return;
        }
        cout << "Email/ИНН (что-то уникальное): ";
        cin >> email;
        for (int i = 0; i < client::n; i++){
            if (email == client::hu[i].email){
                status = 1;
                break;
            }
        }
        if (status){
            indx++;
            zak[n].name = email;
            zak[n].indx = indx;
            cout << "Количество различных товаров: ";
            cin >> zak[n].colTov;
            for (int j = 0; j < zak[n].colTov; j++){
                cout << "Индекс детали: ";
                cin >> zak[n].w[j].indTov;
                cout << "Количество данного вида деталей: ";
                cin >> zak[n].w[j].couTov;
                }
            n++;
        } else {cout << "Заказчика с таким email нет" << endl;}
    }

    void del()
    {
        if (n == 0)
        {
            cout << "Добавленных заказов нет!" << endl;
            return;
        }
        cout << "Email заказчика:" << endl; //использовать индекс заказа?
        string email;
        cin >> email;
        int iza = -1;
        for (int i = 0; i < n; i++)
        {
            if (email == zak[i].name)
            {
                iza = i;
                break;
            }
        }
        if (iza == -1)
        {
            cout << "Такого заказа нет!" << endl;
            return;
        }
        zak[iza] = zak[n - 1];
        n--;
        cout << "Заказ успешно удален!" << endl;
    }

    void change()
    {
        if (n == 0)
        {
            cout << "Добавленных заказов нет!" << endl;
            return;
        }
        cout << "Введите email заказчика" << endl;
        string email;
        cin >> email;
        int iza = -1;
        for (int i = 0; i < n; i++)
        {
            if (email == zak[i].name)
            {
            for (int j = 0; j < zak[n].colTov; j++){
                cout << "Индекс детали: ";
                cin >> zak[i].w[j].indTov;
                cout << "Количество данного вида деталей: ";
                cin >> zak[i].w[j].couTov;
                }
                iza = i;
                break;
            }
        }
        if (iza == -1)
        {
            cout << "Такого заказа нет!" << endl;
            return;
        }
        cout << "Заказ успешно отредактирован!" << endl;
    }

    void wrfile()
    {
        fout.open("Заказы.txt");
        fout << n << endl;
        for (int i = 0; i < n; i++)
        {
            fout << zak[i].name << endl;
            fout << zak[i].indx << endl;
            fout << zak[i].colTov << endl;
            for (int j = 0; j < zak[i].colTov; j++){
                fout << zak[i].w[j].indTov;
                fout << zak[i].w[j].couTov;
            }
        }
        fout.close();
    }

    void rdfileZ()
    {
        fin.open("Заказы.txt");
        fin >> n;
        fin.ignore();
        for (int i = 0; i < n; i++)
        {
            getline(fin, zak[i].name);
            fin >> zak[i].indx;
            fin >> zak[i].colTov;
            for (int j = 0; j < zak[i].colTov; j++){
                fin >> zak[i].w[j].indTov;
                fin >> zak[i].w[j].couTov;
            }
            fin.ignore();
        }
        fin.close();
    }
};
class mainall : public Zakazes, public detl
{
private:
    bool work;

public:
    mainall()
    {
        work = 1;
    }
    bool getwork()
    {
        return work;
    }
    void menu()
    {
        cout << "Меню:" << endl
             << "(1) Заказчики:" << endl
             << "(2) Заказ:" << endl
             << "(3) Детали:" << endl
             << "(0) Выход из программы:" << endl;

        while (option() == -1)
            ;
    }
    void menu1()
    {
        cout << "Меню:" << endl
             << "(1) Вывод всех заказчиков:" << endl
             << "(2) Добавление нового заказчика:" << endl
             << "(3) Удаление заказчика с указанным именем:" << endl
             << "(4) Редактирование заказчика с указанным именем:" << endl
             << "(5) Запись списка заказчиков в файл:" << endl
             << "(6) Считывание списка заказчиков из файла:" << endl
             << "(7) Выход в главное меню" << endl
             << "(0) Выход из программы:" << endl;

        while (option1() == -1)
            ;
    }
    void menu2()
    {
        cout << "Меню:" << endl
             << "(1) Вывод всех заказов:" << endl
             << "(2) Добавление нового заказа:" << endl
             << "(3) Удаление заказа с указанным именем:" << endl
             << "(4) Редактирование заказа с указанным именем:" << endl
             << "(5) Запись списка в файл:" << endl
             << "(6) Считывание списка заказов из файла:" << endl
             << "(7) Выход в главное меню" << endl
             << "(0) Выход из программы:" << endl;

        while (option2() == -1)
            ;
    }
    void menu3()
    {
        cout << "Меню:" << endl
             << "(1) Вывод всех деталей:" << endl
             << "(2) Добавление новой детали:" << endl
             << "(3) Удаление детали с указанным индексом:" << endl
             << "(4) Редактирование детали с указанным индексом:" << endl
             << "(5) Запись списка в файл:" << endl
             << "(6) Считывание списка деталей из файла:" << endl
             << "(7) В главное меню" << endl
             << "(0) Выход из программы:" << endl;

        while (option3() == -1)
            ;
    }
    int option()
    {
        char c;
        cin >> c;

        if (c == '1')
        {
            menu1();
            return 1;
        }
        else if (c == '2')
        {
            menu2();
            return 2;
        }
        else if (c == '3')
        {
            menu3();
            return 3;
        }
        else if (c == '0')
        {
            work = 0;
            return 0;
        }

        else
        {
            return -1;
        }
    }
    int option1()
    {
        char c;
        cin >> c;

        if (c == '1')
        {
            client::Print();
            return 1;
        }
        else if (c == '2')
        {
            client::add();
            return 2;
        }
        else if (c == '3')
        {
            client::del();
            return 3;
        }
        else if (c == '4')
        {
            client::change();
            return 4;
        }
        else if (c == '5')
        {
            client::wrfile();
            return 5;
        }
        else if (c == '6')
        {
            client::rdfileZ();
            return 6;
        }
        else if (c == '7')
        {
            menu();
            return 7;
        }
        else if (c == '0')
        {
            work = 0;
            return 0;
        }
        else
        {
            return -1;
        }
    }
    int option2()
    {
        char c;
        cin >> c;

        if (c == '1')
        {
            Zakazes::Print();
            return 1;
        }
        else if (c == '2')
        {
            Zakazes::add();
            return 2;
        }
        else if (c == '3')
        {
            Zakazes::del();
            return 3;
        }
        else if (c == '4')
        {
            Zakazes::change();
            return 4;
        }
        else if (c == '5')
        {
            Zakazes::wrfile();
            return 5;
        }
        else if (c == '6')
        {
            Zakazes::rdfileZ();
            return 6;
        }
        else if (c == '7')
        {
            menu();
            return 7;
        }
        else if (c == '0')
        {
            work = 0;
            return 0;
        }
        else
        {
            return -1;
        }
    }
    int option3()
    {
        char c;
        cin >> c; //switch
        if (c == '1')
        {
            detl::Print();
            return 1;
        }
        else if (c == '2')
        {
            detl::add();
            return 2;
        }
        else if (c == '3')
        {
            detl::del();
            return 3;
        }
        else if (c == '4')
        {
            detl::change();
            return 4;
        }
        else if (c == '5')
        {
            detl::wrfile();
            return 5;
        }
        else if (c == '6')
        {
            detl::wrfile();
            return 6;
        }
        else if (c == '7')
        {
            menu();
            return 7;
        }
        else if (c == '0')
        {
            work = 0;
            return 0;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    //system("chcp 1251");
    // setlocale(LC_ALL, "rus");
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    mainall mn;
    while (mn.getwork())
        mn.menu();
    return 0;
}
