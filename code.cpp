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


string time_row[736];
string name_row[736];
string max_row[736];
string period_row[736];
string unit_row[736];
string data_row[736];

string filename;
string output;
string line;

ifstream inData;
ofstream outData;

int i=0;
int j=0;
int n=0;


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

	for (j=0; j<5; j++)
		{
		
		while(getline(inData,line)) // grab a line, end at the /n character
		{
			stringstream lineStream(line);
			string cell;
		
			if(i == 0)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					time_row[n]=cell;
					n++;
				}
			}
		
			else if( i == 1)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					name_row[n]=cell;
					n++;
				}
			}

			else if( i == 2)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					max_row[n]=cell;
					n++;
				}
			}

			else if( i == 3)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					unit_row[n]=cell;
					n++;
				}
			}
		
			else if( i == 4)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					name_row[n]=cell;
					n++;
				}
			}
			i++;
		}
		}
	
	
	
	
	
	
	
	
	
system ("PAUSE");
return 0;
}