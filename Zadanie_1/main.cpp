#include <iostream>
#include <string>
#include<fstream>
using namespace std;


struct Student{
    string imie;
    string nazwisko;
    int numer_albumu;
    string data_urodzenia; //  R/M/D
};

struct BazaStudentow{
    string nazwa_uczelni;
    Student Stud[100];
    int l_studentow = 0;
};

void display_student(Student Student){
    cout<< "Imie: "<< Student.imie<<endl;
    cout<< "Nazwisko: "<< Student.nazwisko<<endl;
    cout<< "Numer albumu: "<< Student.numer_albumu<<endl;
    cout<< "Data urodzenia: "<< Student.data_urodzenia<<endl<<endl;
}

void display_all_students(Student *Student_tab , int tab_size){
    for(int i = 0; i < tab_size; i++)
        display_student(Student_tab[i]);
}
int add_student(BazaStudentow *Baza , Student Stud_new){
    if(Baza->l_studentow == 100)
        return 1;
    Baza->Stud[Baza->l_studentow] = Stud_new;
    Baza->l_studentow++;
    return 0;
}
int find_student(BazaStudentow Baza , int numer_indeksu){
    for(int i=0;i<Baza.l_studentow;i++){
        if(Baza.Stud[i].numer_albumu == numer_indeksu){
            return i;
        }
    }
    return -1;
}
int remove_student(BazaStudentow Baza , int numer_indeksu){
    int n = find_student(Baza , numer_indeksu); //n-ty student od zera w bazie
    if(n!=-1)
    {
        for (int i = n; i < Baza.l_studentow; i++) {
            Baza.Stud[n] = Baza.Stud[n + 1];
        }
        Baza.l_studentow--;
        return 0;
    }
    return -2;
}
int load_students(const char *filename , BazaStudentow *Baza){
    int i = 0;
    string tmp;
    fstream file;
    file.open(filename , ios::in);
    if(!file.good())
        return -3;
    while(!file.eof()){
            getline(file , Baza->Stud[i].imie);
            getline(file , Baza->Stud[i].nazwisko);
            getline(file , tmp);
                Baza->Stud[i].numer_albumu = stoi(tmp); //konwersja z wczytanego stringa do inta
            getline(file , Baza->Stud[i].data_urodzenia);
            i++;
         }
    file.close();
    return 0;
}
int save_students(const char *filename , BazaStudentow Baza){
    int i = 0;
    fstream file;
    file.open(filename , ios::out);
    if(!file.good())
        return -3;
    while(i<Baza.l_studentow){
        file<<Baza.Stud[i].imie<<endl;
        file<<Baza.Stud[i].nazwisko<<endl;
        file<<Baza.Stud[i].numer_albumu<<endl;
        file<<Baza.Stud[i].data_urodzenia<<endl;
        file<<endl;
        i++;
    }
    file.close();
    return 0;
}
Student read_student(){
    Student Student;
    cout<<"Podaj imie: "<<endl;
    cin>>Student.imie;
    cout<<endl;

    cout<<"Podaj nazwisko: "<<endl;
    cin>>Student.nazwisko;
    cout<<endl;

    cout<<"Podaj numer albumu: "<<endl;
    cin>>Student.numer_albumu;
    cout<<endl;

    cout<<"Podaj date urodzenia: "<<endl;
    cin>>Student.data_urodzenia;
    cout<<endl;

    return Student;
}
int fill_students(Student *Student_tab){
    Student_tab[0].imie = "Marcin";
    Student_tab[1].imie = "Ania";
    Student_tab[2].imie = "John";
    Student_tab[3].imie = "Kuba";
    Student_tab[4].imie = "Michal";

    Student_tab[0].nazwisko = "Min";
    Student_tab[1].nazwisko = "Afea";
    Student_tab[2].nazwisko = "Doe";
    Student_tab[3].nazwisko = "Kwa";
    Student_tab[4].nazwisko = "Lan";

    Student_tab[0].numer_albumu = 123456;
    Student_tab[1].numer_albumu = 987654;
    Student_tab[2].numer_albumu = 462684;
    Student_tab[3].numer_albumu = 258546;
    Student_tab[4].numer_albumu = 658946;

    Student_tab[0].data_urodzenia = "123456";
    Student_tab[1].data_urodzenia = "987654";
    Student_tab[2].data_urodzenia = "462684";
    Student_tab[3].data_urodzenia = "258546";
    Student_tab[4].data_urodzenia = "658946";
return 0;
}
int main(){
/*Etap 1*/
    Student Student_1;
    Student Student_2;
    Student Student_3;
    BazaStudentow Baza;

    Student_1.imie = "Anna";
    Student_1.nazwisko = "Kowalska";
    Student_1.numer_albumu = 398420;
    Student_1.data_urodzenia = "01.01.03";

    Student_2.imie = "Piotr";
    Student_2.nazwisko = "Kowalski";
    Student_2.numer_albumu = 337420;
    Student_2.data_urodzenia = "18.10.24";

    display_student(Student_1);    //testowe wyswietlenie studentow
    display_student(Student_2);

    Student_3 = read_student();   //wczytanie studenta z stdin
    display_student(Student_3);

/*Etap 2*/
    Student Student_tab[5];
    fill_students(Student_tab);
    display_student(Student_tab[2]);
    display_all_students(Student_tab , 5);   //test 1

    Student Student_tab_2[2];
        Student_tab_2[0] = Student_1;
        Student_tab_2[1] = Student_2;
    display_all_students(Student_tab_2 , 2);    //test2

/*Etap 3 - wszystkie pudpunkty zrealizowane jako funkcje i struktury*/

}