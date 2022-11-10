class FoodRatings
{
    public:
    unordered_map<string, int> mp; // for ratings
    unordered_map<string, string> mp2; // for cuisins
    unordered_map<string, set<pair<int, string>>> hrating;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector< int > &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            mp[foods[i]] = ratings[i]; // O(N)
            mp2[foods[i]] = cuisines[i]; // O(N)
            hrating[cuisines[i]].insert({ -ratings[i], foods[i] }); // O(N log M) M => size(set)
        }
    }

    void changeRating(string food, int newRating)
    {
        string t = mp2[food];  // O(1)
        int tmp = mp[food]; //  O(1)
        mp[food] = newRating; // O(1)
        hrating[t].erase(hrating[t].find({ -tmp, food }));  // O(log M)
        hrating[t].insert({ -newRating, food }); // O(log M)
    }

    string highestRated(string cuisine)
    {

        string res = "";
        auto anss = *(hrating[cuisine].begin());  // O(1)
        res = anss.second;
        return res;
    }
};

/*
    Time Complexity => ~ O(N log N)
    Space Complexity => 3 * O(N)
*/


// class Food
// {
//     int rating;
//     string name, cuisine;
//     Food(string name, string cuisine, int rating)
//     {
//         name = name; rating = rating; cuisine = cuisine;
//     }
// }

/**
 *Your FoodRatings object will be instantiated and called as such:
 *FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 *obj->changeRating(food,newRating);
 *string param_2 = obj->highestRated(cuisine);
 */