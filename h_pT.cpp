/*
Based on IAPW IF97
Code by Yakai Bai
footballses@163.com
*/

#include"IF97.h"
#include<iostream>

using namespace std;

void usage()
{
    cout << "Error: Wrong number of arguments." << endl;
    cout << "h_pT 0.1(MPa) 300(K)"<<endl;
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        usage();
        return 0;
    }
    
    double p = atof(argv[1]);
    double T = atof(argv[2]);

    double h;

    h=IF97::h_pT(p,T);
    
    cout<<h<<endl;
    
    return 0;
}