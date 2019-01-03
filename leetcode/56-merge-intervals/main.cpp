#include <vector>
using std::vector;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size() <= 1)
        return intervals;
    
    vector<Interval> merged;
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start;});
    
    int cur_start=intervals[0].start;
    int cur_end=intervals[0].end;
    
    for (Interval curInt : intervals) {
        if (curInt.start <= cur_end && curInt.start >= cur_start) {
            cur_end = max(cur_end, curInt.end);
        }
        else {
            merged.push_back(Interval(cur_start, cur_end));
            cur_start = curInt.start;
            cur_end = curInt.end;
        }
    }
    merged.push_back(Interval(cur_start, cur_end));
    
    return merged;
}

int main() {

    return 0;
}