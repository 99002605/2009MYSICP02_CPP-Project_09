#include "RailTripDatabase.h"
void RailTripDb ::removeTrip(string id) {
    list<RailTrip>::iterator iter;
    for(iter=trip.begin(); iter!=trip.end(); ++iter) {
        if(iter->getRailNumber()== id) {
            trip.erase(iter);
            break;
        }
    }
}

RailTrip* RailTripDb ::findTripById(string id) {
    list<RailTrip>::iterator iter;
    for(iter=trip.begin(); iter!=trip.end(); ++iter) {
        if(iter->getRailNumber()== id) {
            return &(*iter);
        }
    }
    return NULL;
}
int RailTripDb ::countAll() {
    return trip.size();
}
double RailTripDb ::computeMaxFare() {
    list<RailTrip>::iterator iter;
    auto maxIter = iter;
    for(iter=trip.begin(); iter!=trip.end(); ++iter) {
        if(iter->computeFare()>maxIter->computeFare() ) {
            maxIter=iter;
        }

    }
    return maxIter->computeFare();
}
void RailTripDb::addTrip(string source,string dest,string number,string op,int dis) {
    trip.push_back(RailTrip(source,dest,number,op,dis));
}


double RailTripDb ::computeMinTravelTime() {
    list<RailTrip>::iterator iter;
    auto minIter = iter;
    for(iter=trip.begin(); iter!=trip.end(); ++iter) {
        if(iter->computeTravelTime()<minIter->computeTravelTime() ) {
            minIter=iter;
        }

    }
    return minIter->computeTravelTime();
}

int RailTripDb ::countTripsByOperator(string op) {
    int c=0;
    list<RailTrip>::iterator iter;
    for(iter=trip.begin(); iter!=trip.end(); ++iter) {
        if(iter->getOperator()==op) {
            c++;
        }

    }
    return c;
}
