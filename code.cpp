// EagleI_Data_Converter.cpp : Defines the entry point for the console application.
//
#include <stdafx.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <Windows.h>

using namespace std;

string header_row[736];
string filename;
string output;
int i=0;
int n=0;
ifstream inData;
ofstream outData;


int main ()
{
  cout << "Please note this program only parses Eagle I output data for the Intrepid.  It checks DI134 (VWaferON) and removes any rows where DI134 is 0." << endl;
	cout << "NOTE: THIS FILE MUST NOT BE OPENED BY ANY OTHER SOFTWARE!" << endl;
	cout << endl << "Please enter the filename to parse: (e.g. TrendRC4_201204010000000.csv)" << endl;
	
	cin >> filename;
	
	inData.open( filename.c_str() );
	while( !inData ) 
	{ 
		cerr << endl << "Couldn't open " << filename << "\n";
		cout << "Try again (or ctrl + c to quit): " ;
		cin >> filename;
		inData.clear();
		inData.open( filename.c_str()  );
	} 
	
	cout << endl << "Please enter the name of the output file: (i.e. output.csv)" << endl;
	cin >> output;

	outData.open(output.c_str() );

	inData.ignore(1000, '\n');				//ignores first line VerX.XXx, Always, RC4,,Date: 20xx/XX/XX,,Time: XX:XX
	
	for ( i=1; i<=736; i++ )
	{
		getline (inData, header_row[i], ',');
		outData << header_row[i] << ",";
		cout << "i = " << i << endl;		
	}

	//cout << header_row[736];
	//cout << header_row[737];

	//while (!inData.eof())
	//{
	
	//}
	
	
system ("PAUSE");
return 0;
}