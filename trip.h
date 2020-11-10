#ifndef TRIP_H_INCLUDED
#define TRIP_H_INCLUDED
#include <iostream>
using namespace std;

class Trip {
    string destination;
    string origin;
    string number;
    string Operator;
    int distance;
  public:
    Trip();
    Trip(const string&,const string&,const string&,const string&,int);
    virtual int computeFare()=0;
    virtual int computeTravelTime()=0;
    string getRailNumber();
    string getOrigin();
    string getOperator();
    string getDestination();
    int getDistance();
};

#endif // TRIP_H_INCLUDED
