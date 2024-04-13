#include <iostream>
#include <stdlib.h>
#include <vector>
#include "TablePrinter.hpp"
using namespace std;

void printMainScreen();
int CONSOLEMAXLENGTH = 128;
int APPMAXLENGTH = 120;
int LEFTPADDINGLENGTH= (CONSOLEMAXLENGTH- APPMAXLENGTH)/2;
void centerPrint(string text="", string left_right_decoration="***", bool follow_input=false, int move_left=0){
    for(int i=0;i<LEFTPADDINGLENGTH;i++){
        cout<<" ";
    }
    cout<<left_right_decoration;
    int left_space_length = (APPMAXLENGTH - text.size())/2 - left_right_decoration.size() - move_left;
    for(int i=0;i<left_space_length;i++){
        cout<<" ";
    }
    cout<<text;
    if(left_right_decoration!="" && !follow_input){
        int right_space_length = APPMAXLENGTH - left_right_decoration.size() * 2 - text.size() - left_space_length;
        for(int i=0;i<right_space_length;i++){
            cout<<" ";  
        }
        cout<<left_right_decoration;

    }
    if(!follow_input)
        cout<<endl;     
}

void manyPrint(int n){
    for(int i=0;i<n;i++){
        centerPrint();
    }
}

class Student{
    public:
        int id;
        string firstName;
        string lastName;
        char gender;  ///'M' o r 'F
        string major;
        Student(int id, string firstName, string lastName, char gender, string major){
            this->id = id;
            this->firstName = firstName;
            this->lastName = lastName;
            this->gender = gender;
            this->major = major;
        }
};

vector<Student> records;

void addAStudent(int id, string firstName, string lastName, char gender, string major){
    Student stu = Student(id, firstName, lastName, gender, major);
    records.push_back(stu);
}
void deleteAStudent(int id){
    for(int i = 0; i < records.size(); i++){
        if(records[i].id == id){
            records.erase(records.begin() + i);
        }
    }
}
void updateAStudent(int id, string firstName, string lastName, char gender, string major){
    for(int i = 0; i < records.size(); i++){
        if(records[i].id == id){
            records[i].firstName = firstName;
            records[i].lastName = lastName;
            records[i].gender = gender;
            records[i].major = major;

        }
    }
}

void printStudent(Student stu){
    cout << stu.id << " " << stu.firstName << " " << stu.lastName << " " << stu.gender << " " << stu.major << std::endl;
}

void printAddRecordScreen(){
    system("clear");
    manyPrint(10);
    centerPrint( " Add a new student ");
    manyPrint(10);
    centerPrint( " Enter student id: ", "", true, 20);
    int id;
    cin >> id;
    centerPrint( " Enter student first name: ", "", true, 20);
    string firstName;
    cin >> firstName;
    centerPrint( " Enter student last name: ", "", true, 20);
    string lastName;
    cin >> lastName;
    centerPrint( " Enter student gender: ", "", true, 20);
    char gender;
    cin >> gender;
    centerPrint( " Enter student major: ", "", true, 20);
    string major;
    cin >> major;
    addAStudent(id, firstName, lastName, gender, major);
    centerPrint();
    centerPrint();
    centerPrint(" Add student successfully! ");
    centerPrint( " Enter any key to return to main screen: ", "", true, 20);
    string choice;
    cin >> choice;
    printMainScreen();
}

void printDeleteRecordScreen(){
    system("clear");
    manyPrint(12);
    centerPrint(" Delete a student ");
    manyPrint(12);
    centerPrint( " Enter student id: ", "", true, 20);
    int id;
    cin >> id;
    centerPrint( " Delete student successfully! ");
    deleteAStudent(id);
    centerPrint( " Enter any key to return to main screen: ", "", true, 20);
    string choice;
    cin >> choice;
    printMainScreen();
}
void printUpdateScreen(){
    system("clear");
    centerPrint();
    centerPrint();
    centerPrint();
    centerPrint();
    centerPrint();
    centerPrint();
    centerPrint(" Update a student ");
    centerPrint();
    centerPrint();
    centerPrint();
    centerPrint( " Enter student id: ", "", true, 20);
    int id;
    cin >> id;
    centerPrint( " Enter student first name: ", "", true, 20);
    string firstName;
    cin >> firstName;
    centerPrint( " Enter student last name: ", "", true, 20);
    string lastName;
    cin >> lastName;
    centerPrint( " Enter student gender: ", "", true, 20);
    char gender;
    cin >> gender;
    centerPrint( " Enter student major: ", "", true, 20);
    string major;
    cin >> major;
    updateAStudent(id, firstName, lastName, gender, major);
    centerPrint(" Update student successfully! ");
    centerPrint();
    centerPrint( " Enter any key to return to main screen: ", "", true, 20);
    string choice;
    cin >> choice;
    printMainScreen();
}
void printViewScreen();

void printMainScreen(){
    system("clear");
    manyPrint(10);
    centerPrint(" Welcome to Student Management System ");
    manyPrint(3);

    centerPrint("1. View all students");
    centerPrint("2. Add a new student");
    centerPrint("3. Delete a student");
    centerPrint("4. Update a student");
    manyPrint(10);

    centerPrint(" Enter your choice: ", "", true, 20);
    int choice;
    cin >> choice;
    switch (choice){
        case 1:
            printViewScreen();
            break;
        case 2:
            printAddRecordScreen();
            break;
        case 3:
            printDeleteRecordScreen();
            break;
        case 4:
            printUpdateScreen();
            break;
        default:
            break;
    }
}

void printStudentList_old(vector<Student> stu_vec){
    for(int i = 0; i < stu_vec.size(); i++){
        printStudent(stu_vec[i]);
    }
}

void printStudentList(vector<Student> stu_vec){
    trl::TablePrinter tp;
    tp.AddColumn("id", 10);
    tp.AddColumn("firstName", 20);
    tp.AddColumn("lastName", 20);
    tp.AddColumn("gender", 10);
    tp.AddColumn("major", 30);
    tp.PrintHeader();

    for(int i = 0; i < stu_vec.size(); i++){
        tp<<stu_vec[i].id
        <<stu_vec[i].firstName
        <<stu_vec[i].lastName
        <<stu_vec[i].gender
        <<stu_vec[i].major;
    }
    tp.PrintFooter();
    
}

void printViewScreen(){
    system("clear");
    centerPrint("View all students");
    // cout << " View all students " << endl;
    printStudentList(records);
    cout << " Enter any key to return to main screen: ";
    string choice;
    cin >> choice;
    printMainScreen();
}


int add(int a, int b){
    return a+b;
}

int main(){
    Student stu = Student(1001, "Anhua", "Dong", 'F', "Computer Science");
    Student stu2 = Student(1002, "Bing", "Guo", 'M', "Physics");
    
    records.push_back(stu);
    records.push_back(stu2);
    printMainScreen();
}