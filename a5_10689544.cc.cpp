#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct studentdetail     //DECLEAR STRUCT TO CONTAIN DETAIL FOR EACH STUDENT
    {
        int id;
        string name;
        int age;
        string gender;
        float score;
        char grade;

    };


int main()
{
    int n,i,j,k=1,l=1, malecount=0, femalecount=0;
    float sumscore=0,sumage=0;
    float avgage, avgscore;
    studentdetail student[5];

    cout<<"                ENTER STUDENT DETAILS"<<endl<<endl<<endl;
    cout<< "ENTER NUMBER OF STUDENTS IN THE CLASS: ";
    while(!(cin>>n)){
        cin.clear();
        cin.ignore(999,'\n');
        cout<< "invalid"<<endl<< "ENTER NUMBER OF STUDENTS IN THE CLASS: ";
    }
    cout<<endl<<endl;

for (i=0; i<n; i++)   // TO COLLECT STUDENT DETAILS
    {   cout <<"          STUDENT: "<<k<<endl<<endl;
                         k++;
        cout<<"ID: ";
         while(!(cin>>student[i].id)){
        cin.clear();
        cin.ignore(999,'\n');
        cout<< "invalid"<<endl<< "ID: ";}

        cout<<"NAME: "; cin>>student[i].name;

        cout<<"AGE: ";
        while(!(cin>>student[i].age)){
        cin.clear();
        cin.ignore(999,'\n');
        cout<< "invalid"<<endl<< "AGE: ";}
        sumage = sumage + student[i].age;

        cout<<"GENDER: "; cin>>student[i].gender;
        if(student[i].gender=="MALE" || student[i].gender=="male" || student[i].gender=="m" || student[i].gender=="M" )// TO COUNT THE NUMBER OF MALES AND FEMALES
        {
            malecount++;
        }
            else
                femalecount++;


        cout<<"SCORE: ";
        while(!(cin>>student[i].score)){
        cin.clear();
        cin.ignore(999,'\n');
        cout<< "invalid"<<endl<< "SCORE: ";}

         sumscore = sumscore + student[i].score;
        if (student[i].score>=80)//FOR GRADING EACCH STUDENT
            student[i].grade='A';
        else if (student[i].score>=70)
           student[i].grade='B';
        else if (student[i].score>=60)
            student[i].grade='C';
            else if (student[i].score>=50)
            student[i].grade='D';
            else if (student[i].score>=40)
            student[i].grade='E';
            else if (student[i].score<40)
            student[i].grade='F';
        cout<< "GRADE: "<<student[i].grade;
        cout<<endl<<endl<<endl;

    }

avgage=sumage/n; // AVERAGE AGE
avgscore=sumscore/n; //AVERAGE SCORE



ofstream outf("student.txt"); //CREATE A .TXT FILE CALLED STUDENT


// WRITE TO THE STUDENT FILE
outf<<"                            STUDENT RECORD"<<endl<<endl;
outf<< "        ID NUMBER       "<< "NAME       "<< "AGE       "<<  "GENDER       "<<   " SCORE       "<<    "GRADE       "<<endl;
outf<< "       **************************************************************************"<<endl;
for (j=0; j<n; j++){
    outf<<l<<".  "<<"   "<<"   "<<student[j].id<<"       "<<student[j].name <<"       "<<"   "<<student[j].age <<"       "<<"   "<<student[j].gender <<"       "<<"   "<<student[j].score <<"       "<<"   "<<student[j].grade<< "       "<<endl<<endl<<endl;
    l++;}
outf<< "       **************************************************************************"<<endl;
outf<< "number of males:"<<malecount<<endl;
outf<<"number of females:"<<femalecount<<endl;
outf<< "average age: "<<avgage <<endl;
outf<< "average score: "<<avgscore<<endl;

cout<<"OPEN .TXT FILE NAMED 'STUDENT' IN DIRECTORY TO VIEW"<<endl;
return 0;
}






