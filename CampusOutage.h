#ifndef CAMPUSOUTAGE_H
#define CAMPUSOUTAGE_H

#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

class CampusOutage{

protected:

int mId;
string mDate;
string mBuildingsAffected;
double mCost;

static int sNextId;

public:

 CampusOutage(string date, string buildingsAffected, double cost) : mId(sNextId++), mDate(date), mBuildingsAffected(buildingsAffected), mCost(cost) {}

virtual ~CampusOutage() {}

  string getDate() const { return mDate; }
  void setDate(const string &date) { mDate = date; }

  string getBuildingsAffected() const { return mBuildingsAffected; }
  void setBuildingsAffected(const string &buildingsAffected) { mBuildingsAffected = buildingsAffected; }

  double getCost() const { return mCost; }
  void setCost(double cost) { mCost = cost; }

bool operator==(const CampusOutage &o) {
  return mId == o.mId && mDate == o.mDate &&
         mBuildingsAffected == o.mBuildingsAffected && mCost == o.mCost; 
}

virtual string print() const;

friend ostream &operator<<(ostream &os, const CampusOutage &c) {
  return os << c.print();
}

};

#endif