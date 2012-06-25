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
int wanted_rows[] = {0,65,66,67,68,73,74,75,76,77,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,151,152,153,154,155,156,157,158,159,160,161,163,169,170,171,172,173,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,193,196,207,208,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,246,247,248,249,250,251,252,253,254,255,256,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,289,290,291,292,293,295,296,299,300,301,302,303,304,306,307,309,310,311,315,317,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,351,352,391,401,402,403,404,405,406,421,422,423,424,429,430,431,432,434,435,497,498,499,500,501,502,503,504,505,506,507,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,537,538,539,540,541,542,543,544,545,546,550,551,552,553,554,555,556,557,558,559,560,561,562,563,566,567,568,569,571,577,578,579,580,581,583,585,586,587,588,589,590,591,593,594,595,597,598,601,605,607,608,611,612,613,614,615,616,617,618,619,620,621,622,625,626,627,629,630,631,641,642,643,644,645,646,647,648,649,650,653,734,735,736};
int wanted_row_count=351;   //change this number when you change the wanted_row count in the above array.  Either subtract or add to the number to get it equal to the total entries in the wanted_rows array

string filename;
string output;
string line;

ifstream inData;
ofstream outData;

int i=0;
int j=0;
int k=0;
int l=0;
int m=0;
int n=0;
int z=0;
int total_column_number=737;          //total column number 1->??


int main ()
{
	cout << "Please note this program only parses Eagle I output data for the Intrepid."  << endl;
	cout << "Note: The file you enter for parsing must not be actively open by another program." << endl;
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
	cout << endl << "Working..this takes about ~60s per file (33,000 lines of data)." << endl;

	outData.open(output.c_str() );

	inData.ignore(1000, '\n');				//ignores first line VerX.XXx, etc

		
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

				for(j=0; j<wanted_row_count; j++)
				{
					for(l=0; l<total_column_number; l++)
					{
						if(l==wanted_rows[j])  //compare current count to wanted rows, if = then spit out that value in time_row
						{
							outData << time_row[l] << ",";
						}

					}
				}
				outData << endl;
			}
			else if( i == 1)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					name_row[n]=cell;
					n++;
				}
			for(j=0; j<wanted_row_count; j++)
				{
					for(l=0; l<total_column_number; l++)
					{
						if(l==wanted_rows[j])  //compare current count to wanted rows, if = then spit out that value in time_row
						{
							outData << name_row[l] << ",";
						}

					}
				}
				outData << endl;
			}

			else if( i == 2)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					max_row[n]=cell;
					n++;
				}
			for(j=0; j<wanted_row_count; j++)
				{
					for(l=0; l<total_column_number; l++)
					{
						if(l==wanted_rows[j])  //compare current count to wanted rows, if = then spit out that value in time_row
						{
							outData << max_row[l] << ",";
						}

					}
				}
				outData << endl;
			}

			else if( i == 3)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					unit_row[n]=cell;
					n++;
				}
			for(j=0; j<wanted_row_count; j++)
				{
					for(l=0; l<total_column_number; l++)
					{
						if(l==wanted_rows[j])  //compare current count to wanted rows, if = then spit out that value in time_row
						{
							outData << unit_row[l] << ",";
						}

					}
				}
				outData << endl;
			}
		
			else if( i == 4)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					name_row[n]=cell;
					n++;
				}
			for(j=0; j<wanted_row_count; j++)
				{
					for(l=0; l<total_column_number; l++)
					{
						if(l==wanted_rows[j])  //compare current count to wanted rows, if = then spit out that value in time_row
						{
							outData << name_row[l] << ",";
						}

					}
				}
				outData << endl;
			}

			else if( i > 4)
			{
				n=0;
				while(getline(lineStream,cell,',')) // within our line, go through each field ending at , 
				{
					data_row[n]=cell;
					n++;
				}
			
				if(data_row[391]=="1")
				{
				
					for(j=0; j<wanted_row_count; j++)
					{
						for(l=0; l<total_column_number; l++)
						{
							if(l==wanted_rows[j])  //compare current count to wanted rows, if = then spit out that value in time_row
							{
								outData << data_row[l] << ",";
								z++;
							}
	
						}
					}
					outData << endl;
				}
			}
			i++;

		}
	
	
	
if(z==0)
{
	cout << endl << endl << "There were no columns in this file that were flagged for a wafer being in the chamber." << endl;
}	
	
cout << endl << "Parsing complete!" << endl << endl;	
	
	
system ("PAUSE");
return 0;
}