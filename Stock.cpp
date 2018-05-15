#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include "Date.h"
#include "Stock.h"

using namespace std;

/*
void Market::slice(Date startdate, Date enddate, Market *market) {
	for (auto i = Returns.find(startdate); i != (Returns.find(enddate)); i++)
		market->Returns.insert(std::pair<Date, double>(i->first, i->second));
}
*/
void Stock::setReturns() {
	auto it = Prices.begin();
	for (it; it != Prices.end(); ) {
		double lstday = it->second;
		it++;
		if (it == Prices.end()) break;
		else Returns.insert(pair<Date, double>(it->first, (it->second - lstday) / lstday));
	}
}

