#include <iostream>			// to use cin and cout
#include <typeinfo>			// to be able to use operator typeid

// use abs()
#include <cmath>			

using namespace std;

// function prototypes
void pause();
void showMenu();
void add();
void subtract(); 
void AddRational(int & anum, int & aden, int num1, int den1, int num2, int den2);
void SubtractRational(int & anum, int & aden, int num1, int den1, int num2, int den2);
void GetRational(int& num, int& den);
void DisplayRational(int num, int den);
void reduce(int & num, int & den);

int main()
{
// declare char variable to get users input 
	char letter;
	// do while loop for the user to have multiple attempts
	 do
	 {
		system("clear");
		showMenu();
		cin >> letter;

	 	if(letter == 'A' || letter == 'a')
		{
			system("clear");
	 		add();
	 	}
	 	else if(letter == 'S' || letter == 's')
	 	{
			system("clear");
	 		subtract();
		}
	} while(letter != 'Q' && letter != 'q');


	cout << endl;
	pause();
	return 0;
}

// Prints menu 
void showMenu()
{
	// Display the name of the program
	cout << "Rational numbers calculator" << endl << endl;
	// Display the option Addition 
	cout << "(A)ddition" << endl;
	// Display the option Subtraction
	cout << "(S)ubtraction" << endl;
	// Display quit
	cout << "(Q)uit" << endl << endl;
	// promt the user to enter an option
	cout << "Enter your option: "; 
}



// Function to define the adding part in the calculator 
void add()
{

// Declare variable to hold the first numerator 
	int num1;
// Declare variable to hold the first denominator
	int den1;
// Declare variable to hold the second numerator
	int num2;
// Declare variable to hold the second denominator 
	int den2;
// Declare variable to hold the average num
	int anum;
// Declare varible to hold the avergae 
	int aden; 
// declare variable answer to get user input
	char answer; 
// Display the title 
  	cout << "Addition of rational numbers" << endl;
// call GetRational twice to get both fractions
	GetRational(num1, den1);
	GetRational(num2, den2);
// call AddRational to add both fraction
	AddRational(anum, aden, num1, den1, num2, den2);
// call DisplayRational to show the fractions
	cout << endl << "The result of ";
	DisplayRational(num1, den1);
	cout << " + ";
	DisplayRational(num2, den2);
	cout << " = ";
	DisplayRational(anum, aden);
	cout << endl << endl << "Do you want to do more additiionas? (Y/N): ";
	cin >> answer;
	if(answer == 'y' || answer == 'Y')
	{
		system("clear");
		add();
	}
}



// Function to define the subtracting of the calculator
void subtract()
{
// Declare variable to hold the first numerator 
	int num1;
// Declare variable to hold the first denominator
	int den1;
// Declare variable to hold the second numerator
	int num2;
// Declare variable to hold the second denominator 
	int den2;
// Declare variable to hold the average num
	int anum;
// Declare varible to hold the avergae den
	int aden;
// declare variable answer for user input
	char answer;
// Display the title 
  cout << "Subtraction of rational numbers" << endl;
// call GetRational twice to get both fractions
	GetRational(num1, den1);
	GetRational(num2, den2);
	// call SubtractRational to subtract
	SubtractRational(anum, aden, num1, den1, num2, den2);
	// call display to add the results
	cout << endl << "The result of ";
	DisplayRational(num1, den1);
	cout << " - ";
	DisplayRational(num2, den2);
	cout << " = ";
	DisplayRational(anum, aden);
	// display keep going
	cout << endl << endl << "Do you want to do more subtractions? (Y/N): ";
	cin >> answer;
	if(answer == 'y' || answer == 'Y')
	{
		system("clear");
		subtract();
	}
		
}



// function to get the users input
void GetRational(int & num, int & den)
{
	den = 0;
	while(den == 0)
	{
	char slash;
	// promt the user to a numerator and denomantor 
	cout << endl << "Please enter a fraction (n/d): ";
	// get the value from the keyboard
	cin >> num >> slash >> den;
	// if den == 0 then display cant dive by zero
	if(den == 0)
	    {
		    cout << endl << "Sorry, division by zero is not allowed!" << endl << endl;
		    pause();
	    }
	}
}



// fucntion to add the fractions recieved
void AddRational(int & anum, int & aden, int num1, int den1, int num2, int den2)
{
	// Adds the fractions received
	anum = (num1 * den2) + (num2 * den1);
	aden = (den1 * den2); 
	//  call reduce function to reduce the fractions 
	reduce(anum, aden);

}


// function to subtracct the fractions recieved
void SubtractRational(int & anum, int & aden, int num1, int den1, int num2, int den2)
{
	// subtracts the fractions
	anum = (num1 * den2) - (num2 * den1);
	aden = (den1 * den2);
	//  call reduce function to reduce the fractions 
	reduce(anum, aden);
}


// Function displays the results
void DisplayRational(int num, int den)
{
	// if den is 1 we show the numertor only
	if(den == 1)
	{
		cout << num;
	}
	// else show both fractions 
	else
	{
		cout << num << "/" << den; 
	}
	
}

// Function to reduce the fractions 
void reduce(int& num, int& den)
{
	// Declare variable to hold num
	int A;
	// Declare variable to hold den
	int B;
	// Declare variable to hold the remainder
	int R;

	// Store the value in num into A
	A = abs(num);
	// Store the value in den into B
	B = abs(den);
	// Store the remainder of the fraction into R
	R = (A % B);
	
	while(R != 0)
	{
		A = B;
		B = R;
		R = (A % B);
	}
	// divide the numerator recieved by the Greatest common factor
	num = num / B;
	// divide the den recieved by the greastest common
	den = den / B; 

}



// This function pauses the execution of the program
void pause()
{
	cout << "Press Enter to continue ...";
	cin.sync();
	cin.ignore();
	cin.get();
}
