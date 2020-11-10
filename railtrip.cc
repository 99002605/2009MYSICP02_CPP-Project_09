#include "railtrip.h"

RailTrip::RailTrip(const string& dest,const string& origin,const string& num,const string& op,int dis):Trip(dest,origin,num,op,dis),fnumber(num),OperatorD(op),distbcity(dis) {


}
RailTrip::RailTrip():Trip(),fnumber(""),OperatorD(""),distbcity(0) {


}

int RailTrip::computeFare() {
    return 10*distbcity;

}

int RailTrip::computeTravelTime() {
    return distbcity/(500/60.0);

}


