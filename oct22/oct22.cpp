// oct22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

bool isValidDate(int day, int month, int year)
{
	if (year < 1900 || year > 2025)
		return false;

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = {
	31, 28, 31, 30,
	31, 30, 31, 31, 30, 31, 30, 31
	};

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

int calculateAge(int birthDay, int birthMonth, int birthYear,
	int currentDay, int currentMonth, int currentYear)
{
	int age = currentYear - birthYear;

	if (currentMonth < birthMonth ||
		(currentMonth == birthMonth && currentDay < birthDay))
	{
		age--;
	}

	return age;
}

int main()
{
	int birthDay, birthMonth, birthYear;
	int currentDay, currentMonth, currentYear;

	while (true)
	{
		cout << "Enter your birth datee (DD-MM-YYYY): ";
		char dash1, dash2;
		string birthInput;
		getline(cin, birthInput);

		stringstream birthStream(birthInput);

		if (!(birthStream >> birthDay >> dash1 >> birthMonth
			>> dash2 >> birthYear) ||
			dash1 != '-' || dash2 != '-' ||
			birthStream.peek() != EOF ||
			!isValidDate(birthDay, birthMonth, birthYear))
		{
			cout << "Invalid birth date. Please try again.\n";
			continue;
		}

		break;
	}

	while (true)
	{
		cout << "Enter the current date (DD-MM-YYYY): ";

		char dash1, dash2;
		string currentInput;
		getline(cin, currentInput);

		stringstream currentStream(currentInput);

		if (!(currentStream >> currentDay >> dash1 >> currentMonth
			>> dash2 >> currentYear) ||
			dash1 != '-' || dash2 != '-' ||
			currentStream.peek() != EOF ||
			!isValidDate(currentDay, currentMonth, currentYear))
		{
			cout << "Invalid current date. Try again.\n";
			continue;
		}

		if (currentYear < birthYear ||
			(currentYear == birthYear && currentMonth < birthMonth) ||
			(currentYear == birthYear && currentMonth == birthMonth &&
				currentDay < birthDay))
		{
			cout << "Current date cannot be before your birth date.\n";
			continue;
		}

		break;
	}

	int age = calculateAge(birthDay, birthMonth, birthYear,
		currentDay, currentMonth, currentYear);

	cout << "\nYour age is: " << age << " years old.\n";

	return ;
}