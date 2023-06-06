// JAAR
// 06/06/2023
// C++ Primer Plus 6th Ed
// CH 8 Program Ex 7
// Version 2

// TODO: Calculate number of elements in an array instead of hard code value.

// ------------------------------ Prompt---------------------------------------
// Modify Listing 8.14 to use two template functions called sumArray() return
// the sum of the contents. returns the sum instead of displaying the contents.
// Program now should report the total number of things and the sum of all
// debts.
// ------------------------------ Prompt---------------------------------------

// tempover.cpp -- template overloading
#include <iostream>
template <typename T> // template A
void ShowArray(T arr[], int n);
template <typename T> // template B
void ShowArray(T* arr[], int n);
template <typename T>
auto sum(T* arr[], int arr_size) -> T;
template <typename T>
auto sum(T arr[], int arr_size) -> T;

struct debts
{
	char name[50];
	double amount;
};
int main()
{
	using namespace std;
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] =
	{
	{"Ima Wolfe", 2400.0},
	{"Ura Foxe", 1300.0},
	{"Iby Stout", 1800.0}
	};
	double* pd[3];
	// set pointers to the amount members of the structures in mr_E
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;
	cout << "Total number of things is: 6\n"
		"Sum of all things: " << sum(things, 6) << endl;

	cout << "Total number of Mr E's debt: 3\n"
		"Mr E's debts: " << sum(pd, 3) << endl;

	/* ______ Original Program _____	
	cout << "Listing Mr. E's counts of things:\n";
	// things is an array of int
	ShowArray(things, 6); // uses template A
	cout << "Listing Mr. E's debts:\n";
	// pd is an array of pointers to double
	ShowArray(pd, 3); // uses template B (more specialized)
	*/
}

// Calculates the total for an array of size arr_size
// Param: type T arr[], int arr_size
// Return: T total_debt
template <typename T>
auto sum(T arr[], int arr_size) -> T
{
	int total_debt = 0;
	for (int i = 0; i < arr_size; i++)
	{
		total_debt += arr[i];
	}
	return total_debt;
}

// Calculates the total for an array of size arr_size.
// Param: type T* arr[], int arr_size
/// Return T total_debt
template <typename T>
auto sum(T* arr[], int arr_size)-> T
{
	int total_debt = 0;
	for (int i = 0; i < arr_size; i++)
	{
		total_debt += *arr[i];
	}
	return total_debt;
}


// Displays all elements in an array of size n
// Param: type T arr[], int n
template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "template A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}


// Displays all elements in an array of size n
// Param: type T* arr[], int n
template <typename T>
void ShowArray(T* arr[], int n)
{
	using namespace std;
	cout << "template B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}