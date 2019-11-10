#include "pch.h"
#include "OptionPricing.h"

#include <iostream>
#include <math.h>

OptionPricing::OptionPricing(double assetPrice, double strikePrice, double maturity, double rate, double sigma)
{
	m_assetPrice = assetPrice;
	m_strikePrice = strikePrice;
	m_maturity = maturity;
	m_rate = rate;
	m_sigma = sigma;
}

double OptionPricing::CallOptionPrice()
{
	
	if (m_assetPrice < NEAR_ZERO)
	{
		return 0.;
	}

	if (m_sigma < NEAR_ZERO)
	{
		if (m_assetPrice < m_strikePrice * exp(-m_rate * (m_maturity))) return 0.;
		else return m_assetPrice - m_strikePrice * exp(-m_rate * (m_maturity));
	}

	if (fabs(m_maturity) < NEAR_ZERO) // if we are at maturity
	{
		if (m_assetPrice < m_strikePrice) return 0.;
		else return m_assetPrice - m_strikePrice;
	}

	
	double d1 = OptionPricing::d1();
	double d2 = OptionPricing::d2();

	// calculate option price
	return normalCDF(d1) * m_assetPrice - normalCDF(d2) * m_strikePrice * exp(-m_rate * (m_maturity));
}

double OptionPricing::PutOptionPrice()
{
	double d1 = OptionPricing::d1();
	double d2 = OptionPricing::d2();

	// calculate option price
	//return normalCDF(d1) * m_assetPrice - normalCDF(d2) * m_strikePrice * exp(-m_rate * (m_maturity));
	return m_strikePrice * exp(-m_rate * m_maturity) * normalCDF(-d2) - m_assetPrice * normalCDF(-d1);
}

double OptionPricing::normalCDF(double x)
{
	return erfc(-x / sqrt(2)) / 2;
}

double OptionPricing::d1()
{
	return (log(m_assetPrice / m_strikePrice) + (m_rate + m_sigma * m_sigma / 2.) * (m_maturity)) / (m_sigma * sqrt(m_maturity));
}

double OptionPricing::d2()
{
	return (log(m_assetPrice / m_strikePrice) + (m_rate - m_sigma * m_sigma / 2.) * (m_maturity)) / (m_sigma * sqrt(m_maturity));
}
