// tsf-csv.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <fstream>
 
using namespace std;
 
 
int main(int argc, char **argv)
{
    //string contents = file_get_contents("images_southern_calif_with_amazon.tsv");
   char *del;
   string line, creds[3];
   int x = 0;
   int ID=0;
    ifstream myfile;
	ofstream outfile;
   myfile.open("images_southern_calif_with_amazon.tsv");
	//myfile.open("test.tsv");
   outfile.open("result.csv");
   outfile<< "Image1ID";
   outfile<<",";
   outfile<< "Image1URL";
   outfile<<",";
   outfile<< "Image1Info";
    outfile<<",";
   outfile<< "Image2ID";
   outfile<<",";
   outfile<< "Image2URL";
   outfile<<",";
   outfile<< "Image2Info";
    outfile<<",";
   outfile<< "Image3ID";
   outfile<<",";
   outfile<< "Image3URL";
   outfile<<",";
   outfile<< "Image3Info";
    outfile<<",";
   outfile<< "Image4ID";
   outfile<<",";
   outfile<< "Image4URL";
   outfile<<",";
   outfile<< "Image4Info";
    outfile<<",";
   outfile<< "Image5ID";
   outfile<<",";
   outfile<< "Image5URL";
   outfile<<",";
   outfile<< "Image1Info";
    outfile<<",";
   outfile<<"ANSWER1";
   outfile<<",";
   outfile<< "ANSWER2";
   outfile<<",";
   outfile<<"ANSWER3";
   outfile<<",";
   outfile<< "ANSWER4";
     outfile<< "\n";
  if (myfile.is_open())
  {
	  int lineNum;
    while (!myfile.eof())
    {
		for( lineNum=0;lineNum<5;lineNum++)
		{
			if(!myfile.eof())
			{
				char oneline[1000];
				getline(myfile,line);
				char *oneline1;
				strcpy_s(oneline,line.c_str());
				del = strtok_s(oneline,"\t",&oneline1);
				x=0;
				while(del!=NULL)
				{	
					creds[x++] = del;
					del = strtok_s(NULL,"\t", &oneline1);
					//x++;
				}
				if(outfile.is_open()){
				outfile<<ID;
				outfile<<",";
				outfile<< creds[2];//image URL
				outfile<<",";
				outfile<< creds[1];//imageInfo
				outfile<<",";
				}
				ID++;
			}
			else if(lineNum<5)
			{
				for(int i=lineNum; i<5;i++ ) {outfile<<ID++;
				outfile<<",";
				outfile<< "no picture";//image URL
				outfile<<",";
				outfile<< "no resource";//imageInfo
				outfile<<",";
				}
				lineNum=5;
				break;

			}
		}
		if(outfile.is_open()){
			if(lineNum==5){
			outfile<<"Photo of ONE person";
				outfile<<",";
				outfile<<"Photo of MULTIPLE people";
				outfile<<",";
				outfile<<"Photo WITHOUT people";
				outfile<<",";
				outfile<<"Not a photo, e.g.logo or graphics";
				outfile<<"\n";
			}
		}
			
    }
	
		outfile.close();
		myfile.close();
  }
  else 
      cout << "Unable to open file"; 
  return 0;
}
