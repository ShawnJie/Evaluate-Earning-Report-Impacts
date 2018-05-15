#include <iostream>
#include <string>
#include "Date.h"

bool Date::operator>(const Date& obj) const {
	if (Year > obj.Year) {
		return true;
	}
	else if (Year == obj.Year) {
		if (Month > obj.Month) {
			return true;
		}
		else if (Month == obj.Month) {
			return (Day > obj.Day);
		}
	}
	return false;
}

bool Date::operator<(const Date& obj) const {
	if (Year < obj.Year) {
		return true;
	}
	else if (Year == obj.Year) {
		if (Month < obj.Month) {
			return true;
		}
		else if (Month == obj.Month) {
			return (Day < obj.Day);
		}
	}
	return false;
}

bool Date::operator==(const Date& obj) const {
	if (Year == obj.Year && Month == obj.Month && Day == obj.Day) {
		return true;
	}
	return false;
}

bool Date::operator<=(const Date & obj) const {
	return ((*this) < obj || (*this) == obj);
}

bool Date::operator>=(const Date & obj) const {
	return ((*this) > obj || (*this) == obj);
}

int Date::getYear() const {
	return Year;
}
int Date::getMonth() const {
	return Month;
}
int Date::getDay() const {
	return Day;
}

void Date::setYear(int year) {
	Year = year;
}
void Date::setMonth(int month) {
	Month = month;
}
void Date::setDay(int day) {
	Day = day;
}

std::string Date::toString() const {
	return std::to_string(Year) + "-" + std::to_string(Month) + "-" + std::to_string(Day);
}
