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
} // namespace
