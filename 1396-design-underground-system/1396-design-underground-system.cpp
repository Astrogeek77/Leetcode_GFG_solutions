class UndergroundSystem {
	public:
		unordered_map<string, pair<double, int>> avg; // travelName => {overallTime, numberOfTravels}
		unordered_map<int, pair<string, int>>checkin; // id => {entryStation, entryTime}
    
		UndergroundSystem() {}

		void checkIn(int id, string stationName, int t) {
			checkin[id] = {stationName, t};
		}

		void checkOut(int id, string stationName, int t) {
			string str = checkin[id].first + "->" + stationName;
			double time = t - checkin[id].second;
			avg[str].first += time;
			avg[str].second++;
		}

		double getAverageTime(string startStation, string endStation) {
			string s = startStation + "->" + endStation;
			return avg[s].first / avg[s].second;
		}
	};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */