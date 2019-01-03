#include <iostream>
#include <vector>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

int minMeetingRooms(vector<Interval>& intervals) {
	if (intervals.size() <= 1) return true;
        
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
       return a.start < b.start;
    });



	return true;
}

int main() {
	vector<Interval> test{Interval(5, 6), Interval(1, 4)};
	cout << minMeetingRooms(test) << '\n';
	return 0;
}