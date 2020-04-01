#include <iostream>
#include <list>

class Student {
public:
    std::string name;
    double grade;

    Student(double grade, std::string name) : name(name),grade(grade){}
};

class Functor{
public:
    bool operator() (Student& student1, Student& student2){
        if (student1.grade == student2.grade){
            return student1.name < student2.name;
        }
        else{
            return student1.grade < student2.grade;
        }
    }
};

int main(){
    std::list<Student> listofStudents = { Student(30, "Sid"),
									Student(3, "Laura"),
									Student(43, "Riti"),
									Student(30, "Angel"),
									Student(2, "Laura"),};

/////////Lambda
/*     listofStudents.sort([](Student& student1, Student& student2){
        if (student1.grade == student2.grade){
            return student1.name < student2.name;
        }
        else{
            return student1.grade < student2.grade;
        }
    }); */

    listofStudents.sort(Functor());
    for (auto s : listofStudents)
        std::cout << s.name << " " << s.grade << std::endl;
}
