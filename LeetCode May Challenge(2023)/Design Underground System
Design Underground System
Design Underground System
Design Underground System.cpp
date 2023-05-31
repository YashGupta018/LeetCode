class UndergroundSystem {
public:
  unordered_map<int, pair<string, int>> mp1;
  unordered_map<string, pair<double, int>> mp2;
  UndergroundSystem() {}
  void checkIn(int id, string stationName, int t) {
    mp1[id] = {stationName, t};
  }
  void checkOut(int id, string stationName, int t) {
    auto checkIn = mp1[id];
    mp1.erase(id);
    string routeName = checkIn.first + "_" + stationName;
    mp2[routeName].first += t - checkIn.second;
    mp2[routeName].second += 1;
  }
  double getAverageTime(string startStation, string endStation) {
    string routeName = startStation + "_" + endStation;
    auto &route = mp2[routeName];
    return route.first / route.second;
  }
};
