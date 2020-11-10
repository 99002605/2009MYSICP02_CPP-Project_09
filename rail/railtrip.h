#ifndef RAILTRIP_H_INCLUDED
#define RAILTRIP_H_INCLUDED

#include <iostream>
using namespace std;
#include "trip.h"
class RailTrip: public Trip {
    string fnumber;
    string OperatorD;
    int distbcity;
  public:
    RailTrip();
    RailTrip(const string&,const string&,const string&,const string&,int);
    int computeFare() override;
    int computeTravelTime() override;
};






#endif // SAF_H_INCLUDED
