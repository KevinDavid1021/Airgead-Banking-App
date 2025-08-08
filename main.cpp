//main.cpp
//Author: Kevin David
//SNHU: CS-210 - Project 2: Airgead Banking App
//Description: Main driver for the Airgead Banking App
//	This file collects user input and drives the investment simulation.

#include <iostream>
#include "InvestmentCalculator.h"

using namespace std;

int main() {
	//user input variables
	double initialInvestment, monthlyDeposit, annualInterest;
	int numYears;

	//welcome message
	cout << "**********************************" << endl;
	cout << "** Welcome to Airgead Banking!" << endl;
	cout << "**********************************\n" << endl;

	//collect user input for investment parameters
	cout << "Enter Initial Investment Amount: $";
	cin >> initialInvestment;

	cout << "Enter Monthly Deposit: $";
	cin >> monthlyDeposit;

	cout << "Enter Annual Interest Rate (percent): ";
	cin >> annualInterest;

	cout << "Enter Number of Years: ";
	cin >> numYears;

	//wait for user to proceed
	cout << "\nPress Enter to continue...";
	cin.ignore();
	cin.get();

	//create investment calculator object with user inputs
	InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numYears);
	
	//run reports
	calculator.calculateWithoutMonthlyDeposit();
	calculator.calculateWithMonthlyDeposit();

	//exit message
	cout << "\nThank you for using the Airgead Banking App!" << endl;
	return 0;
}



