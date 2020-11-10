#include <iostream>
using namespace std;
#include "railtrip.h"
#include <list>
#include <iterator>

class RailTripDb {
    list<RailTrip> trip;
  public:
    void addTrip(string,string,string,string,int);
    void removeTrip(string);
    RailTrip* findTripById(string);
    int countAll();
    double computeMaxFare();
    double computeMinTravelTime();
    int countTripsByOperator(string);
};
