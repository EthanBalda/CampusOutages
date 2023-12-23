#include "BridgeOutage.h"

string BridgeOutage::print() const {
  stringstream ss;
  ss << CampusOutage::print() << setw(22) << mRoadsAffected << "|";
  return ss.str();
}