#ifndef BRIDGEOUTAGE_H
#define BRIDGEOUTAGE_H

#include "CampusOutage.h"

class BridgeOutage : public CampusOutage {
private:
  string mRoadsAffected;

public:
  BridgeOutage(string date, string buildingsAffected, double cost, string roadsAffected) : 
 CampusOutage(date,buildingsAffected, cost), mRoadsAffected(roadsAffected) {}

  string getRoadsAffected() const { return mRoadsAffected; }
  void setRoadsAffected(const string &roadsAffected) {mRoadsAffected = roadsAffected;}

bool operator==(const BridgeOutage& o) {
  return CampusOutage::operator==(o) && mRoadsAffected == o.mRoadsAffected;
}

string print() const;

friend ostream& operator<<(ostream& os, const BridgeOutage& b) {
  return os << b.print();
}
};

#endif