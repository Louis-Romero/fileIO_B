#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

int main ()
{
    char theDataFileName[12];
    ifstream fin;
    ofstream fout;
    string firstName, lastName, highestFirstName, highestLastName;
    double g1, g2, g3, g4, g5, g6;
    double maximum = -50000.0;
    double sum = 0;
    double average;
    
    cout << "Please enter the name of the text file you would like to open: " << endl;
    cin >> theDataFileName;
    
    fin.open(theDataFileName);
    fout.open("results.txt");
    
    if(fin.fail())
    {
        cout << "Error opening input file!" << endl;
        exit(1);
    }
    if(fout.fail())
    {
        cout << "Error opening output file!" << endl;
        exit(1);
    }
    
    while(fin >> firstName >> lastName >> g1 >> g2 >> g3 >> g4 >> g5 >> g6)
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(1);
        fout.setf(ios::left);
        sum = g1 + g2 + g3 + g4 + g5 + g6;
        average = sum / 6.0;
        
        
        if(average > maximum)
        {
            highestFirstName = firstName;
            highestLastName = lastName;
            maximum = average;
        }
        
        fout << setw(10) << firstName << setw(10) << lastName << setw(5) << g1 << setw(5) << g2 << setw(5) << g3 << setw(5) << g4 << setw(5) << g5 << setw(5) << g6 << endl;
    
    }
    
    fout << endl;
    fout << "Highest Score: " << highestFirstName << " " << highestLastName << " " << maximum << endl;  
      
    fin.close();
    fout.close();
    return 0;
}

