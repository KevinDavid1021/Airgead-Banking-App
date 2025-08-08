//InvestmentCalculator.h
//Author: Kevin David
//SNHU: CS-210 - Project 2: Airgead Banking App
//Description: Header file for the InvestmentCalculator class
//	This class handles investment calculations with and without monthly deposits.

#ifndef AIRGEAD_INVESTMENT_CALCULATOR_H
#define AIRGEAD_INVESTMENT_CALCULATOR_H

class InvestmentCalculator {
private:
	//member variables for initial values provided by the user
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_numYears;

public:
	//constructor to initialize investment data
	InvestmentCalculator(double initial, double monthly, double interest, int years);
	
	//displays year-end balance without and with monthly deposits
	void calculateWithoutMonthlyDeposit() const;
	void calculateWithMonthlyDeposit() const;
};

#endif //AIRGEAD_INVESTMENT_CALCULATOR_H
