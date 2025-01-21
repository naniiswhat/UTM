/* DETAILS OF US
    //*Program Title: Assignment 2
    //*PROGRAMMING TECHNIQUE 1 (SECJ1013)
    //*SECTION 04, SEM 1 (2024/2025)

    Lecturer: LIZAWATI BINTI MI YUSUF

    Name: ABDURRAFIQ BIN ZAKARIA
    Matric Number: A24CS0031

    Name: DANIEL IMAN HAQIMIE BIN YUSOFF
    Matric Number: A24CS0063

    Date of completion: 09 January 2025
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

//!TASK2
int readInput(string name[], float ass[], float lab[], float mid[], float fin[]){

    //opening files
    ifstream input("input.txt");

    //Check if file is open or not
    if (!input) {
        cout << "Error opening file" << endl;
        cin.get();
    }
    
    //set initialize variables to 0
    int StudentNum = 0;

    //declare a variable to read each line from the file
    string line;

    //!!!!!!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!
    //This code works but it must use sstream library
    //If not, it change the output formatting

    while (getline(input, line)) {
        if (!line.empty()) {
            stringstream ss(line);

            // Extract the name
            getline(ss, name[StudentNum], ',');

            // Extract the rest of the marks
            ss >> ass[StudentNum] >> lab[StudentNum] >> mid[StudentNum] >> fin[StudentNum];

            StudentNum++;
        }
    }

    //Close file
    input.close();

    //Returns the total number of students
    return StudentNum;
}

//!TASK3
void calculateTotalAndGrade(string name[], float ass[], float lab[], float mid[], float fin[], float totalMark[], char grade[], int& Studentnum){

    //calculate total mark each student has and store them into an array
    for(int i=0;i<Studentnum;i++){

        //Total mark = sum all marks
        totalMark[i] = ass[i] + lab[i] + mid[i] + fin[i];

        //assign grades based on their total mark
        if(totalMark[i]  >=85)                      {grade[i]='A';} else
        if(totalMark[i] >= 70 && totalMark[i] <= 84){grade[i]='B';} else
        if(totalMark[i] >= 55 && totalMark[i] <= 69){grade[i]='C';} else
        if(totalMark[i] >= 40 && totalMark[i] <= 54){grade[i]='D';} else
                                                    {grade[i]='F';}

    }  
}

//!TASK4
void displayOutput(int studentNum, string name[], float ass[], float lab[], float mid[], float fin[], float totalMark[], char grade[]){

    //Display header
    cout << left << setw(20) << "Student Name"          
                 << setw(14) << "Assignments"          
                 << setw(16) << "Lab Exercises"      
                 << setw(16) << "Midterm Tests"         
                 << setw(14) << "Final Exams"           
                 << setw(14) << "Total Marks"           
                             << "Grade"
                             << endl
                             << string(100, '-')
                             << endl;

    //display output to terminal
    for (int i=0;i<studentNum;i++){
            
            //Output formatting
            cout << left << fixed << setprecision(1) << setw(23)  <<      name[i] 
                 << right                            << setw(4)   <<       ass[i] 
                                                     << setw(16)  <<       lab[i] 
                                                     << setw(16)  <<       mid[i] 
                                                     << setw(15)  <<       fin[i] 
                         << fixed << setprecision(2) << setw(14)  << totalMark[i] 
                                                     << setw(9)   <<     grade[i]
                                                                  <<         endl;
                         
    }

    //new line before go to grade histogram
    cout << endl;
}

//!TASK5
void displayAnalysis(string name[], float totalMark[], char grade[], int& Studentnum){

    //*Calculate highest marks

    float max = -9999.00;
    for (int i=0;i<Studentnum;i++){
        (totalMark[i]>max) ? max = totalMark[i] : max=max;}

    //Find whos got the highest marks
    string highest;
    for (int i=0;i<Studentnum;i++){ 
        if (max == totalMark[i]) {
            highest=name[i]; break;}}

    //*Calculate lowest marks
    float min = 9999.00;
    for(int i=0;i<Studentnum;i++){
        (totalMark[i]<min) ? min = totalMark[i] : min=min;}

    //Find whos got the lowest marks
    string lowest;
    for (int i=0;i<Studentnum;i++){ 
        if (min == totalMark[i]) {
            lowest=name[i]; break;}}

    //*Calculate average marks

    //Initialize sum
    float sum = 0;
    
    //Sum up all total marks
    for(int i=0;i<Studentnum;i++){
        sum += totalMark[i];}

    //Calculate average mark
    float avg = sum/Studentnum;

    cout << fixed << setprecision(2) << "Class Average Marks: " << avg
                                                                << endl;

    cout << "Highest Score: " << highest << " (" << max << ")"  << endl;
    cout << "Lowest Score: "  << lowest  << " (" << min << ")"  << endl;

    //*Calculate how many A's, etc.

    //initialize counters using struct
    struct counter{
        int A=0,
            B=0,
            C=0,
            D=0,
            F=0;
    };

    //Count how many gred for each letter grade
    counter c;
    for (int i=0; i<Studentnum; i++){
        switch (grade[i]){
            case 'A': c.A++;break;
            case 'B': c.B++;break;
            case 'C': c.C++;break;
            case 'D': c.D++;break;
            default:  c.F++;break;}
    }

    //*Calculate percentages
    //initialise percentage variables using struct

    struct percentage{
        float a=0,
              b=0,
              c=0,
              d=0,
              f=0;
    };

    //Percentage variable
    percentage p;
    for (int i=0; i<Studentnum; i++){

        //we do (c.A*100.0)/Studentnum because we want to get float values
        // this 100.0 we use here so that we can get decimal places

        switch (grade[i]){
            case 'A': p.a=(c.A*100.0)/Studentnum;break;
            case 'B': p.b=(c.B*100.0)/Studentnum;break;
            case 'C': p.c=(c.C*100.0)/Studentnum;break;
            case 'D': p.d=(c.D*100.0)/Studentnum;break;
            case 'F': p.f=(c.F*100.0)/Studentnum;break;
            default:  break;}
    }

    //*Print histogram
    
/*    //! make it better
    //!count how many type of grades are there
    //! and put it in declaire GRADE array to make it generalized
    //!and use it as a parameter for histogram function

    //Declaire grade array
    char GRADE[5]={'A','B','C','D','F'};

    //count how many gred it has
    //initialize counter
    int cnt = 0;
    for (int i=0; i<GRADE[i]; i++){
            cnt++;
    }
    ana << cnt << endl;
*/
      //! If you can generalize it, change it with "cnt" instead of "6"
    
    cout << endl << "Grade Histogram" << endl;
    
    //Declaire grade array and percentage array
    //Total type of gred is "6"
    char GRADE[6] = {'A', 'B', 'C', 'D', 'F'};
    float percentages[6] = {p.a, p.b, p.c, p.d, p.f};
    int countGrades[6] = {c.A, c.B, c.C ,c.D, c.F};

    //print histogram

    for (int i = 0; i < 5; i++) {
        if (percentages[i] > 0.0) {
            cout << GRADE[i] << ": ";
        
        //set up number symbol to be present as percentage weights
        int plus = countGrades[i]*2;

        //print the symbols
        for (int j = 0; j < plus; j++) {
            cout << "+" ;
            }

            cout << " " << "(" << percentages[i] << "%)" ;
            cout << endl;

            }
        }
}

//!TASK1
int main(){
    //* Declare the necessary parallel arrays as specified in Task 1 with a maximum size of 50 elements.

    int NUM_STUDENT = 50;
    //Declare arrays that will hold information about students
    string  name[NUM_STUDENT];
    float    ass[NUM_STUDENT] = {0.0},
             lab[NUM_STUDENT] = {0.0},
             mid[NUM_STUDENT] = {0.0},
             fin[NUM_STUDENT] = {0.0};
    float   totalMark[NUM_STUDENT] = {0.0};
    char   grade[NUM_STUDENT];

    //!TASK 6
    //Read data from input file
    //Get actual number of students in class
    NUM_STUDENT = readInput(name, ass, lab, mid, fin);

    //Calculate Total Mark and Grade for Each Student
    calculateTotalAndGrade(name, ass, lab, mid, fin, totalMark, grade, NUM_STUDENT);

    //To display output to screen
    displayOutput(NUM_STUDENT, name, ass, lab, mid, fin, totalMark, grade);

    //To display analysis data to screen
    displayAnalysis(name, totalMark, grade, NUM_STUDENT);

    system("pause");
    return 0;
}