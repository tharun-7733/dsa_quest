class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string S_hour = "", S_minutes = "", S_seconds = "";
        string E_hour = "", E_minutes = "", E_seconds = "";
        int n = startTime.length();

        S_hour += startTime.substr(0, 2);
        S_minutes += startTime.substr(3, 2);
        S_seconds += startTime.substr(6, 2);

        E_hour += endTime.substr(0, 2);
        E_minutes += endTime.substr(3, 2);
        E_seconds += endTime.substr(6, 2);

        return ((stoi(E_hour) - stoi(S_hour)) * 3600) + 
                ((stoi(E_minutes) - stoi(S_minutes)) * 60) + 
                (stoi(E_seconds) - stoi(S_seconds));
    }
};