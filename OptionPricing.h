#pragma once

#define NEAR_ZERO 1.e-14

class OptionPricing
{
	
public:
	OptionPricing( double assetPrice, double strikePrice, double maturity, double rate, double sigma);	// standard constructor

public:
	double CallOptionPrice();
	double PutOptionPrice();
private:
		double m_assetPrice = 0;
		double m_maturity = 0;
		double m_rate = 0;
		double m_strikePrice = 0;
		double m_sigma = 0;
		
		double normalCDF(double x);
		double d1();
		double d2();
};
//END CLASS
