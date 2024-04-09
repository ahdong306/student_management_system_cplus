#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void printMainScreen();

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
    cout << " Add a new student " << endl;
    cout << " Enter student id: ";
    int id;
    cin >> id;
    cout << " Enter student first name: ";
    string firstName;
    cin >> firstName;
    cout << " Enter student last name: ";
    string lastName;
    cin >> lastName;
    cout << " Enter student gender: ";
    char gender;
    cin >> gender;
    cout << " Enter student major: ";
    string major;
    cin >> major;
    addAStudent(id, firstName, lastName, gender, major);
    cout<<" Add student successfully! "<<endl;
    cout << " Enter any key to return to main screen: ";
    cout << " Enter your choice: ";
    string choice;
    cin >> choice;
    printMainScreen();
}

void printDeleteRecordScreen(){
    cout<<" Delete a student "<<endl;
    cout << " Enter student id: ";
    int id;
    cin >> id;
    cout<<" Delete student successfully! "<<endl;
    deleteAStudent(id);
    cout << " Enter any key to return to main screen: ";
    cout << " Enter your choice: ";
    string choice;
    cin >> choice;
    printMainScreen();
}
void printUpdateScreen(){
    cout<<" Update a student "<<endl;
    cout << " Enter student id: ";
    int id;
    cin >> id;
    cout << " Enter student first name: ";
    string firstName;
    cin >> firstName;
    string lastName;
    cout << " Enter student last name: ";
    cin >> lastName;
    char gender;
    cout << " Enter student gender: ";
    cin >> gender;
    string major;
    cout << " Enter student major: ";
    cin >> major;
    updateAStudent(id, firstName, lastName, gender, major);
    cout<<" Update student successfully! "<<endl;
    cout << " Enter any key to return to main screen: ";
    cout << " Enter your choice: ";
    string choice;
    cin >> choice;
    printMainScreen();
}
void printViewScreen();

void printMainScreen(){
    system("clear");
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << " Welcome to Student Management System " << endl;
    cout << " 1. View all students" << endl;
    cout << " 2. Add a new student" << endl;
    cout << " 3. Delete a student" << endl;
    cout << " 4. Update a student" << endl;
    cout << " Enter your choice: ";
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

void printStudentList(vector<Student> stu_vec){
    for(int i = 0; i < stu_vec.size(); i++){
        printStudent(stu_vec[i]);
    }
}

void printViewScreen(){
    system("clear");
    cout << " View all students " << endl;
    printStudentList(records);
    cout << " Enter any key to return to main screen: ";
    cout << " Enter your choice: ";
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