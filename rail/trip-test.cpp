#include "trip.h"
#include "railtrip.h"
#include <gtest/gtest.h>
namespace {

class TripTest : public ::testing::Test {

  protected:
    void SetUp() { // override {
        ptr = new RailTrip("Mumbai", "Delhi", "6E123", "Rajadani", 800);
    }
    void TearDown() {
        delete ptr;
    }
    Trip *ptr;
};

TEST_F(TripTest, DefaultConstructor) {
    RailTrip ft;
    EXPECT_EQ(0, ft.getRailNumber().length());
    EXPECT_EQ(0, ft.getOrigin().length());
    EXPECT_EQ(0, ft.getDestination().length());
    EXPECT_EQ(0, ft.getOperator().length());
    EXPECT_EQ(0, ft.getDistance());
}
TEST_F(TripTest, ParameterizedConstructor) {
    RailTrip *fptr = dynamic_cast<RailTrip*>(ptr);
    EXPECT_STREQ("Mumbai", fptr->getOrigin().c_str());
    EXPECT_STREQ("Delhi", fptr->getDestination().c_str());
    EXPECT_STREQ("6E123", fptr->getRailNumber().c_str());
    EXPECT_STREQ("Rajadani", fptr->getOperator().c_str());
    EXPECT_EQ(800, fptr->getDistance());
}
TEST_F(TripTest, ComputationTest) {
    EXPECT_EQ(8000, ptr->computeFare());      //800 * 10, INR 10 for each mile
    EXPECT_EQ(96, ptr->computeTravelTime());  //96 mins, if speed in 500 miles per hr
}
TEST_F(TripTest, AnotherTest) {
    RailTrip ft("Bengaluru", "Chennai", "SG401", "Venkatadri", 200);
    Trip *pt = &ft;
    EXPECT_STREQ("Bengaluru", ft.getOrigin().c_str());
    EXPECT_STREQ("Chennai", ft.getDestination().c_str());
    EXPECT_STREQ("SG401", ft.getRailNumber().c_str());
    EXPECT_STREQ("Venkatadri", ft.getOperator().c_str());
    EXPECT_EQ(200, ft.getDistance());
    EXPECT_EQ(2000, pt->computeFare());        //200 * 10 = 2000
    EXPECT_EQ(24, pt->computeTravelTime());    //24 mins, if speed is 500 miles per hr
}
} // namespace
