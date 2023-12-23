#include "BridgeOutage.h"
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

int main() {

  int choice, outageType;
  double cost, totalCost = 0.0;
  string date, buildings, roads;

  vector<CampusOutage*> outages;

  do {
  cout << "                                      )                             "
          "(               \n"
       << "   (                               ( /(          )                  "
          ")\\ )            \n"
       << "   )\\     )    )           (       )\\())   (  ( /(   ) (  (    (  "
          " (()/(     (  (   \n"
       << " (((_) ( /(   (    `  )   ))\\ (   ((_)\\   ))\\ )\\()( /( )\\))(  "
          "))\\   /(_)) (  )\\))(  \n"
       << " )\\___ )(_))  )\\  '/(/(  /((_))\\    ((_) /((_(_))/)(_)((_))\\ "
          "/((_) (_))   )\\((_))\\  \n"
       << "((/ __((_)_ _((_))((_)_\\(_))(((_)  / _ \\(_))(| |_((_)_ (()(_(_))  "
          " | |   ((_)(()(_) \n"
       << " | (__/ _` | '  \\(| '_ \\| || (_-< | (_) | || |  _/ _` / _` |/ -_) "
          " | |__/ _ / _` |  \n"
       << "  \\___\\__,_|_|_|_|| .__/ \\_,_/__/  \\___/ \\_,_|\\__\\__,_\\__, "
          "|\\___|  |____\\___\\__, |  \n"
       << "                  |_|                                 |___/         "
          "        |___/   \n";
     cout <<
          "***********************************************************************************\n"
          << "**    Please enter choice :                                                      **\n"
          << "** 1) Record campus outage                                                       **\n"
          << "** 2) Display all outages                                                        **\n"
          << "** 3) Exit                                                                       **\n"
          << "***********************************************************************************\n>> ";
    cin >> choice;
    switch (choice) {
     // Choice 1 - Record campus outage
    case 1:
     cout << "Enter 1 for Campus Outage (Power) or 2 for Bridge Outage >> ";
      cin >> outageType;
     cout << "Enter date               >> ";
      cin.ignore(INT_MAX, '\n');
      getline(cin, date);
     cout << "Enter buildings affected >> ";
      getline(cin, buildings);
     cout << "Enter cost               >> $";
      cin >> cost;

      totalCost += cost;
     // If user selected bridge outage:
      if(outageType == 1)
        outages.push_back(new CampusOutage(date, buildings, cost));
      else{
     cout << "Enter roads affected     >> ";
        cin.ignore(INT_MAX, '\n');
        getline(cin, roads);
     cout << endl;
        outages.push_back(new BridgeOutage(date, buildings, cost, roads));
      }
      break;

     // Choice 2 - Display all outages
      case 2:
     cout << "***********************************************************************************\n"
          << "**                               Log of All Outages                              **\n"
          << "***********************************************************************************\n"
          << "| Id # | Date       | Buildings Affected    | Cost        | Roads Affected        |\n"
          << "***********************************************************************************\n";

        for (auto disasters : outages)
          cout << *disasters << endl;


     cout << "\nThe total cost of all outages = $" << fixed << setprecision(2) << totalCost;
     cout << "\n(+5 points extra credit) The outage with the most buildings "
             "affected:\n";
      break;

     // Choice 3 - Exit
      case 3:
     cout << "Have a great winter break! Thanks for enduring the outages and succeeding :)\n";
      break;
    }
  } while (choice != 3);

  for (auto disasters : outages)
    delete disasters;

}