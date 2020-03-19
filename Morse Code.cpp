#include <iostream>
using namespace std;
int StrCmp( const char *s1, const char *s2 ){
	int i=0;
	while (s1[i]!='\0')
	{
		if (s2[i]=='\0')  // if s2 ended before s1, s1 will be greater 
		return 1;
		if ((int (s2[i]))> (int (s1[i]))) //if s2 is greater than s1
		return -1;
		if (int (s2[i])<int (s1[i])) // if s1 is greater than s2
		return 1;
		i++;
	}
	if (s2[i]!='\0') //if still elements of s2 not ended or not equal to null then s2 is greater
	return -1;
	return 0; // if all conditions fail then both strings are equal
}
void EngToMorsecode(char ***ptr)
{
	short count = 0, index, maxinput = 100;
    char *input=new char[maxinput];
	for (int i=0;i<100;i++)
	input[i]=NULL;
	cout << "Enter the English text: ";
	cin.ignore();
	cin.getline(input,maxinput);
	for (int i = 0; input[i]!='\0'; i++)
	{
		for (int k = 0; k<45; k++)
		{
			if (input[i] == ptr[k][0][0])
			{
				cout << ptr[k][1] << " ";
			}
		}
	}
	delete []input;
}
void MorsecodeToEng(char ***ptr)
{
	char *storeinput= new char [7];
	for (int i=0;i<7;i++)
	{
		storeinput[i]=NULL;
	}
	int maxinput=100;
	char *input=new char[maxinput];
	for (int i=0;i<100;i++)
	input[i]=NULL;
	cout<<"Enter the morse code : "<<endl;
	cin.ignore();
    cin.getline(input,maxinput);
	int i=0;
	int count;
	bool check=1;
	for (int j=0;input[i]!='\0';i++)
	{
		if (input[i]!=' ')
		{
			storeinput[j]=input[i];
			j++;
		}
		else
		{
			j=0;
			for (int k=0;k<45;k++)
			{
				if (StrCmp(storeinput,ptr[k][1])==0)
				{
					cout<<ptr[k][0][0];
				}	
			}
			
			for (int m=0;m<7;m++)
		    storeinput[m]=NULL;
		}
	}
		for (int k=0;k<45;k++)
		{
			if (StrCmp(storeinput,ptr[k][1])==0)
			cout<<ptr[k][0][0];
		}
		delete []storeinput;
		delete []input;
}
int main()
{
	short totalpages = 45, rows = 2, cols = 7, option;
	//making 3d pointer array
	char ***ptr = NULL;
	ptr = new char **[totalpages];
	for (int i = 0; i<totalpages; i++)
	{
		*(ptr + i) = new char *[rows];
		for (int j = 0; j<rows; j++)
		{
			*(*(ptr + i) + j) = new char[cols];
		}
	}
	// storing English alphabets 
	*(*(*(ptr + 0) + 0) + 0) = 'A';
	*(*(*(ptr + 1) + 0) + 0) = 'B';
	*(*(*(ptr + 2) + 0) + 0) = 'C';
	*(*(*(ptr + 3) + 0) + 0) = 'D';
	*(*(*(ptr + 4) + 0) + 0) = 'E';
	*(*(*(ptr + 5) + 0) + 0) = 'F';
	*(*(*(ptr + 6) + 0) + 0) = 'G';
	*(*(*(ptr + 7) + 0) + 0) = 'H';
	*(*(*(ptr + 8) + 0) + 0) = 'I';
	*(*(*(ptr + 9) + 0) + 0) = 'J';
	*(*(*(ptr + 10) + 0) + 0) = 'K';
	*(*(*(ptr + 11) + 0) + 0) = 'L';
	*(*(*(ptr + 12) + 0) + 0) = 'M';
	*(*(*(ptr + 13) + 0) + 0) = 'N';
	*(*(*(ptr + 14) + 0) + 0) = 'O';
	*(*(*(ptr + 15) + 0) + 0) = 'P';
	*(*(*(ptr + 16) + 0) + 0) = 'Q';
	*(*(*(ptr + 17) + 0) + 0) = 'R';
	*(*(*(ptr + 18) + 0) + 0) = 'S';
	*(*(*(ptr + 19) + 0) + 0) = 'T';
	*(*(*(ptr + 20) + 0) + 0) = 'U';
	*(*(*(ptr + 21) + 0) + 0) = 'V';
	*(*(*(ptr + 22) + 0) + 0) = 'W';
	*(*(*(ptr + 23) + 0) + 0) = 'X';
	*(*(*(ptr + 24) + 0) + 0) = 'Y';
	*(*(*(ptr + 25) + 0) + 0) = 'Z';
	*(*(*(ptr + 26) + 0) + 0) = '0';
	*(*(*(ptr + 27) + 0) + 0) = '1';
	*(*(*(ptr + 28) + 0) + 0) = '2';
	*(*(*(ptr + 29) + 0) + 0) = '3';
	*(*(*(ptr + 30) + 0) + 0) = '4';
	*(*(*(ptr + 31) + 0) + 0) = '5';
	*(*(*(ptr + 32) + 0) + 0) = '6';
	*(*(*(ptr + 33) + 0) + 0) = '7';
	*(*(*(ptr + 34) + 0) + 0) = '8';
	*(*(*(ptr + 35) + 0) + 0) = '9';
	*(*(*(ptr + 36) + 0) + 0) = '.';
	*(*(*(ptr + 37) + 0) + 0) = ',';
	*(*(*(ptr + 38) + 0) + 0) = '?';
	*(*(*(ptr + 39) + 0) + 0) = '\'';
	*(*(*(ptr + 40) + 0) + 0) = '!';
	*(*(*(ptr + 41) + 0) + 0) = '/';
	*(*(*(ptr + 42) + 0) + 0) = '(';
	*(*(*(ptr + 43) + 0) + 0) = ')';
	*(*(*(ptr + 44) + 0) + 0) = '&';

	//storing Mores code
	*(*(ptr + 0) + 1) = ".-";
	*(*(ptr + 1) + 1) = "-...";
	*(*(ptr + 2) + 1) = "-.-.-";
	*(*(ptr + 3) + 1) = "-..";
	*(*(ptr + 4) + 1) = ".";
	*(*(ptr + 5) + 1) = "..-.";
	*(*(ptr + 6) + 1) = "--.";
	*(*(ptr + 7) + 1) = "....";
	*(*(ptr + 8) + 1) = "..";
	*(*(ptr + 9) + 1) = ".---";
	*(*(ptr + 10) + 1) = "-.-";
	*(*(ptr + 11) + 1) = ".-..";
	*(*(ptr + 12) + 1) = "--";
	*(*(ptr + 13) + 1) = "-.";
	*(*(ptr + 14) + 1) = "---";
	*(*(ptr + 15) + 1) = ".--.";
	*(*(ptr + 16) + 1) = "--.-";
	*(*(ptr + 17) + 1) = ".-.";
	*(*(ptr + 18) + 1) = "...";
	*(*(ptr + 19) + 1) = "-";
	*(*(ptr + 20) + 1) = "..-";
	*(*(ptr + 21) + 1) = "...-";
	*(*(ptr + 22) + 1) = ".--";
	*(*(ptr + 23) + 1) = "-..-";
	*(*(ptr + 24) + 1) = "-.--";
	*(*(ptr + 25) + 1) = "--..";
	*(*(ptr + 26) + 1) = "-----";
	*(*(ptr + 27) + 1) = ".----";
	*(*(ptr + 28) + 1) = "..---";
	*(*(ptr + 29) + 1) = "...--";
	*(*(ptr + 30) + 1) = "....-";
	*(*(ptr + 31) + 1) = ".....";
	*(*(ptr + 32) + 1) = "-....";
	*(*(ptr + 33) + 1) = "--...";
	*(*(ptr + 34) + 1) = "---..";
	*(*(ptr + 35) + 1) = "----.";
	*(*(ptr + 36) + 1) = ".-.-.-";
	*(*(ptr + 37) + 1) = "--..--";
	*(*(ptr + 38) + 1) = "..--..";
	*(*(ptr + 39) + 1) = ".----.";
	*(*(ptr + 40) + 1) = "-.-.--";
	*(*(ptr + 41) + 1) = "-..-.";
	*(*(ptr + 42) + 1) = "-.--.";
	*(*(ptr + 43) + 1) = "-.--.-";
	*(*(ptr + 44) + 1) = ".-...";
	
	cout << "Choose one of the following options: \n";
	cout << "1. Change English Text To Morse Code." << endl;
	cout << "2. Change Morse Code to English Text." << endl;
	cout << "3. Quit" << endl;
	cin >> option;
	if (option == 1)
	{
		EngToMorsecode(ptr);
	}
	else if (option == 2)
	{
		MorsecodeToEng(ptr);
	}
	else if (option==3)
	{
		cout<<"Thank you for using Morse code converter";
	}
	else
	{
		cout<<"Invalid option\n";
		//main();
	}
	for (int i = 0; i<totalpages; i++)
	{
		for (int j = 0; j<rows-1; j++)
		{
			delete [] *(*(ptr + i) + j);
		}
		delete [] *(ptr + i);
	}
	delete []ptr;
}
