#pragma once
#ifndef Stock_h
#define Stock_h
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <string>
#include "Date.h"

class Stock {
protected:
	std::string Ticker;
	std::string StartTime;
	std::string EndTime;
	double EPSactual;
	double EPSestimate;
	std::map<Date, double> Prices;
	std::map<Date, double> Returns;


public:

	Stock() {}
	Stock(std::string ticker, std::string starttime, std::string endtime, double eps_act, double eps_est)
		:Ticker(ticker), StartTime(starttime), EndTime(endtime), EPSactual(eps_act), EPSestimate(eps_est) {}
	Stock(const Stock& stock) :Ticker(stock.Ticker), StartTime(stock.StartTime), EndTime(stock.EndTime),
		EPSactual(stock.EPSactual), EPSestimate(stock.EPSestimate), Prices(stock.Prices), Returns(stock.Returns) {}
	virtual ~Stock() {} 

	void setPrices(const Date& date, const double& price) { Prices.insert(std::pair<Date, double>(date, price)); }
	void setReturns(const Date& date, const double& returna) { Prices.insert(std::pair<Date, double>(date, returna)); }
	std::string getTicker() const { return Ticker; }
	std::string getStartTime() { return StartTime; }
	std::string getEndTime() { return EndTime; }
	double getEPSactual() const { return EPSactual; }
	double getEPSestimate() const { return EPSestimate; }
	double getEPSbeat() { return (EPSactual / EPSestimate) - 1; }
	std::map<Date, double> GetReturns() { return Returns; }
	void setReturns();
	double getReturns(int t) { auto it = Returns.begin(); advance(it, t); return it->second; }
	double getPrices(int t) { auto it = Prices.begin(); advance(it, t); return it->second; }

};

class Market : public Stock {
public:
	Market() {}
	Market(std::string ticker, std::string starttime, std::string endtime, double eps_act, double eps_est)
		:Stock(ticker, starttime, endtime, eps_act, eps_est) {}
	Market(const Market& market) { Ticker = market.Ticker; StartTime = market.StartTime; EndTime = market.EndTime; EPSactual = market.EPSactual; EPSestimate = market.EPSestimate; Prices = market.Prices; Returns = market.Returns; }
//	void slice(Date startdate, Date enddate, Market* market);
	int dis(Date startdate) { int a = 0;
	auto it = Returns.begin();
	while (it->first < startdate) {
		it++;
		a++;
	}
	return a;
	}
};
#endif