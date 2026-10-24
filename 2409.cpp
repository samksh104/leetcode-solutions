class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        auto getDay = [&](string s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));

            int total = day;
            for (int i = 0; i < month - 1; i++)
                total += days[i];

            return total;
        };

        int start = max(getDay(arriveAlice), getDay(arriveBob));
        int end = min(getDay(leaveAlice), getDay(leaveBob));

        return max(0, end - start + 1);
    }
};