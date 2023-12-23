#include "CampusOutage.h"

int CampusOutage::sNextId = 1;

string CampusOutage::print() const {
  stringstream ss;
  ss << left << "| " << setw(5) << mId << "| " << setw(11) << mDate << "| " << setw(22) << mBuildingsAffected << "| " << setw(12)  << fixed << setprecision(2) << mCost << "| ";
  return ss.str();
}