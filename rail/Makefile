all: 
	g++ trip-test.cpp trip.cc railtrip.cc -o s1.out -lgtest -lgtest_main -lpthread
	g++ tripdb-test.cpp RailTripDatabase.cc trip.cc railtrip.cc -o s2.out -lgtest -lgtest_main -lpthread

run:
	.\/s1.out
	.\/s2.out


