/*
 * Tester.cpp
 * Andre Barajas
 * 
 *
 *  Created on: Aug 31, 2018
 *  This program creates a structure with two array
 *  one with ints and another with chars
 *  the int array keeps track of the # of chars in the
 *  corresponding index to the char array.
 *  Programming assignment #1 structure with array of pointers; with dynamically allocated memory and several functionality options for user.
 */
//Libraries Deployed/References
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
//Map DataStructure to speed up semi-recursive function
map<int, int> data;
//Structure that will contain data available to the user.
struct myObject
{
	char* charArray[20];
	int intArray[20];
	bool checkRecycleBin; //Simulates wether user already trashed the memory or not
};//Ending myObject structure
//Declaring prototypes.
//Program Requirements
void deleteCharsAtPtr(myObject, int);
void print10Chars(myObject, int);
void showMenu(myObject);
void showMenu2(myObject);
void listDealMem(myObject);
void delAllMemory(myObject);
int recurs(int);
void allocate(int, myObject, int, bool);

//U.I.
int main()
{
	cout << "Initiating Program..." << endl;
	myObject structure;
	structure.checkRecycleBin = false;
	//Begin allocating memory to structure with pointers.
	const string bankOfCapLetters = "OPQRSTABXYZFGHICDEUVWJKLMN";
	for(int i = 0; i < 20; i++)
	{
		int size = recurs(i);
		structure.intArray[i] = size;
		cout << "\t\t**********Allocating Memory at index " << i << ".... " << endl;
		structure.charArray[i] = new char[size];
		for(int j = 0; j < size; j++)
		{
						int random = rand() % 26;
						char l = bankOfCapLetters.at(random);
						structure.charArray[i][j] = l;
							//cout <<  structure.charArray[index] << ", ";
		}//Ending nested for loops
		//cout <<  structure.charArray[i] << ", " << endl;

		//print10Chars(structure, i);
	}//Ending for loop
	//show menu #1 to user.
	showMenu( structure );
	//Deallocating Memory used for program, if not already removed by user.
	if(structure.checkRecycleBin == false)
	{
		delete[]  structure.intArray;
		delete[]  structure.charArray;
	}//End if statement
	return 0;f
}//Ending main


//Recursion function that determines how much memory each pointer needs
int recurs(int x)
{
	if (x==0)
		{
			data[0] = 2700;
			return 2700;
		}
		else
		{
			int result = data[x-1] * 2;		data[x] = result;	return  result;
		}
		//Ending if else statement
	//Ending if else statement
}//Ending recursive statement
//Method to present index, if it exists, where memory has been deallocated.
void listDealMem(myObject structure)
{
		cout << "\t\t*********Listing Deallocated Memory***********" << endl;
	    //Traverse structure charArray to located any sign of deleted data.
		for (int i=0; i < 20; i++)
	    {
	          if (NULL == structure.charArray[i])      {         cout << "Located Null Ptr at index: " << i-1 << endl;  } //ending if statement
	    }//Ending for traverse
		showMenu(structure);
}//Ending listDealMem function
//First menu presents to user
//Program requirements are respective to uses choices(i.e. 0-3)
void showMenu(myObject structure)
{
	int userInput;
	cout << "(0)Access a pointer" << endl;
	cout << "(1)List deallocated memory(index)" << endl;
	cout << "(2)Deallocate all memory" << endl;
	cout << "(3)Exit program" << endl;
	cin >> userInput;
	if(userInput < 0 || userInput > 3)
	{
		cout << "ERROR: Wrong Entry, Try Again." << endl;
		showMenu(structure);
	}
	else
	{
		switch(userInput)
		{
				case 0:showMenu2(structure); break;
				case 1: listDealMem(structure); break;
				case 2: delAllMemory(structure); structure.checkRecycleBin = true; break;
				case 3: break;
		}//End Switch
	}//ending if else statement
}//Ending showMenu function
//Second Menu option after user indicated a pointer access request
//Program requirements are respective to uses choices(i.e. 0-3)
void showMenu2(myObject structure)
{
	cout << "Choose an index from 0-19: " << endl;
	int indexChoice;
	cin >> indexChoice;
	if(indexChoice < 1 && indexChoice > 20)
	{
		cout << "ERROR: not an option, try again." << endl;
		showMenu2(structure);
	}else
	{
		int userInput;
		cout << "(0)Print the first 10 char's in the chosen array." << endl;
		cout << "(1) Delete all the char's associated with this pointer" << endl;
		cout << "(2)Return to main menu. When your";
		cout << " user chooses to delete the char's, deallocate memory (physically). " << endl;
		//cout << "(3)Exit program" << endl;
		cin >> userInput;
		if(userInput< 0 or userInput > 2)
		{
			cout << "Error: Wrong Choice, Try Again..." << endl;
			showMenu2(structure);
		}
		//fetch user request(function
		switch(userInput)
		{
				case 0: print10Chars(structure, indexChoice); break;
				case 1: deleteCharsAtPtr(structure, indexChoice); break;
				case 2: showMenu(structure); break;
				case 3: break;
		}//Ending Switch
	}//ending if else statementS
}//ending showMenu2 function

//deleteCharsAtPtr function will take the structure, which by this point has pst the
//initialization phase of the program, and a userChoice from 0-19
//if the ptr is null it must reallocate chars
void deleteCharsAtPtr(myObject structure, int userChoice)
{
	 cout << "\t\t*********Deleting Chars***********" << endl;

	 delete structure.charArray[userChoice];
	 structure.charArray[userChoice] = NULL;
	 cout << "\t\t*********Ptr Is Now Empty***********" << endl;
	 showMenu(structure);

}//Ending deleteCharsAtPtr function
//Function to print elements in charArray
void print10Chars(myObject structure, int indexChoice)
{
	const string bankOfCapLetters = "OPQRSTABXYZFGHICDEUVWJKLMN";
	//check if ptr was previously dumped
	if(structure.charArray[indexChoice] != NULL )
	{
		cout << "Printing first ten characters at index " << indexChoice << endl;
		for (int k=0; k < 10; k++)
	    cout << structure.charArray[indexChoice][k];
		cout << endl;
		showMenu2(structure);
	}else
	{
		int size = structure.intArray[indexChoice];
		cout << "\t\t**********Index " << indexChoice << " Has Been Dumped...." << endl;
		structure.charArray[indexChoice] = new char[size];
				for(int j = 0; j < size; j++)
				{
								int random = rand() % 26;
								char l = bankOfCapLetters.at(random);
								structure.charArray[indexChoice][j] = l;
									//cout <<  structure.charArray[index] << ", ";
				}//Ending nested for loops
		cout << "\t\t**********Reallocating New Memory To Index...." << indexChoice << " " << endl;
		showMenu2(structure);
	}//Ending if else statement
}//ending print10Chars function
//Function to locate and remove any data remaining
void delAllMemory(myObject structure)
{
	cout << "\t\t*********Deallocating All Memory***********" << endl;

	for (int i=0; i < 20; i++)
	{
	                    if(structure.charArray[i] != NULL)
	                    delete structure.charArray[i];
	                    structure.charArray[i] = NULL;
	}//Ending traversal
	showMenu(structure);
}//ending delAllMemory Function
