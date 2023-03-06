#include <iostream>
#include <string>
using namespace std;
struct Student{
    string imie;
    string nazwisko;
    int numer_albumu;
    string data_urodzenia; //  R/M/D
};

void display_student(Student Student){
    cout<< "Imie: "<< Student.imie<<endl;
    cout<< "Nazwisko: "<< Student.nazwisko<<endl;
    cout<< "Numer albumu: "<< Student.numer_albumu<<endl;
    cout<< "Data urodzenia: "<< Student.data_urodzenia<<endl<<endl;
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
    cin>>Student->numer_albumu;
    cout<<endl;

    cout<<"Podaj date urodzenia: "<<endl;
    cin>>Student->data_urodzenia;
    cout<<endl;

    return 0;
}
int fill_students(Student *Student_tab){
    Student_tab[0].imie = "Marcin";
    Student_tab[1].imie = "Ania";
    Student_tab[2].imie = "Ola";
    Student_tab[3].imie = "Kuba";
    Student_tab[4].imie = "Michal";

}
int main(){
/*Etap 1*/
    Student Student_1;
    Student Student_2;
    Student Student_3;

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

    read_student(&Student_3);   //wczytanie studenta z stdin
    display_student(Student_3);

/*Etap 2*/
    Student Student_tab[5];



}