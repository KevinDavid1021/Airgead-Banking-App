//InvestmentCalculator.cpp
//Author: Kevin David
//SNHU: CS-210 - Project 2: Airgead Banking App
//Description: Implementation file for the InvestmentCalculator class
//	This file contains the methods for computing investment growth.

#include <iostream>
#include <iomanip>
#include "InvestmentCalculator.h"

using namespace std;

//constructor initialized all investment inputs
InvestmentCalculator::InvestmentCalculator(double initial, double monthly, double interest, int years)
	: m_initialInvestment(initial), m_monthlyDeposit(monthly), m_annualInterest(interest), m_numYears(years) {}

//prints details for each year with formatted columns
void printDetails(int year, double yearEndBalance, double interestEarned) {
	cout << fixed << setprecision(2);
	cout << setw(4) << year << "        $" << setw(7) << yearEndBalance << "                $" << setw(6) << interestEarned << endl;
}

//calculates compound interest without additional monthly deposits
void InvestmentCalculator::calculateWithoutMonthlyDeposit() const {
	double balance = m_initialInvestment;
	double monthlyRate = (m_annualInterest / 100.0) / 12.0;
	double interestEarned = 0.0, monthlyInterest = 0.0;

	//display table header
	cout << "\n   Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl;
	cout << "Year        Year End Balance        Interest Earned" << endl;

	//loop through each year
	for (int year = 1; year <= m_numYears; ++year) {
		interestEarned = 0.0;

		//compound interest monthly
		for (int month = 0; month < 12; ++month) {
			monthlyInterest = balance * monthlyRate;
			balance += monthlyInterest;
			interestEarned += monthlyInterest;
		}
		
		//print results for the year
		printDetails(year, balance, interestEarned);
	}
}

//calculates compound interest including monthly deposits
void InvestmentCalculator::calculateWithMonthlyDeposit() const {
	double balance = m_initialInvestment;
	double monthlyRate = (m_annualInterest / 100.0) / 12.0;
	double interestEarned = 0.0, monthlyInterest = 0.0;

	//display table header
	cout << "\n   Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "==========================================================" << endl;
	cout << "Year        Year End Balance        Interest Earned" << endl;

	//loop through each year
	for (int year = 1; year <= m_numYears; ++year) {
		interestEarned = 0.0;

		//apply monthly interest, then add monthly deposit
		for (int month = 0; month < 12; ++month) {
			monthlyInterest = balance * monthlyRate;
			balance += monthlyInterest;
			interestEarned += monthlyInterest;
			balance += m_monthlyDeposit;
		}

		//print results for the year
		printDetails(year, balance, interestEarned);
	}
}

