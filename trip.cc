#include "trip.h"
using namespace std;

Trip::Trip():destination(""),origin(""),number(""),Operator(""),distance(0) {


}

Trip::Trip(const string& dest,const string& origin,const string& num,const string& op,int dis):destination(dest),origin(origin),number(num),Operator(op),distance(dis) {


}

string Trip::getRailNumber() {
    return number;
}
string Trip::getOrigin() {
    return destination;
}
string Trip::getOperator() {
    return Operator;
}
string Trip::getDestination() {
    return origin;
}
int Trip::getDistance() {
    return distance;
}
