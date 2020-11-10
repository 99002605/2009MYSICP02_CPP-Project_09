#include "trip.h"
#include "railtrip.h"
#include "RailTripDatabase.h"
#include <gtest/gtest.h>
namespace {

class RailTripDbTest : public ::testing::Test {

  protected:
    void SetUp() {
        trips.addTrip("Hyderabad", "Pune", "6E500", "Rajadani", 350);
        trips.addTrip("Bengaluru", "Pune", "6E501","Rajadani", 500);
        trips.addTrip("Hyderabad", "Chennai", "AI850","Venkatadri", 400);
        trips.addTrip("Mumbai", "Bengaluru","SG301",  "Venkatadri", 600);
        trips.addTrip("Bengaluru", "Delhi", "SG302","Shatabdhi", 1200);
        trips.addTrip("Pune", "Bengaluru","AI900",  "Shatabdhi", 550);
    }
    void TearDown() {}
    RailTripDb trips;
};

TEST_F(RailTripDbTest, AddTripTest) {
    trips.addTrip("Chennai","Delhi", "SG304","Duranthu", 1300);
    EXPECT_NE((Trip*)NULL, trips.findTripById("SG304"));
    EXPECT_EQ(7, trips.countAll());
}
TEST_F(RailTripDbTest, RemoveTripTest) {
    trips.removeTrip("6E501");
    EXPECT_EQ(NULL, trips.findTripById("6E501"));
    EXPECT_EQ(5, trips.countAll());
}
TEST_F(RailTripDbTest, CountTest) {             //Just After Setup
    EXPECT_EQ(6, trips.countAll());
}
TEST_F(RailTripDbTest, CountByOperatorTest) {  //Just After Setup
    int count = trips.countTripsByOperator("Venkatadri");
    EXPECT_EQ(2, count);
}
TEST_F(RailTripDbTest, MaxFareTest) {           //Just After Setup
    double maxFare = trips.computeMaxFare();
    double minTime = trips.computeMinTravelTime();
    EXPECT_EQ(12000, maxFare);         //For trip with distance of 1200 miles
    EXPECT_EQ(42, minTime);            //For trip with distance of 350 miles
}
TEST_F(RailTripDbTest, AnotherTest) {         //Just After Setup
    trips.addTrip("Chennai","Delhi","SG308", "Venkatadri", 1300);
    trips.addTrip("Chennai","Bengaluru", "AI848", "Rajadani", 200);
    int count = trips.countTripsByOperator("Rajadani");
    double maxFare = trips.computeMaxFare();
    double minTime = trips.computeMinTravelTime();
    EXPECT_EQ(8, trips.countAll());
    EXPECT_EQ(3, count);
    EXPECT_EQ(13000, maxFare);
    EXPECT_EQ(24, minTime);
}
} // namespace
