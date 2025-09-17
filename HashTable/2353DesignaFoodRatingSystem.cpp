#include <bits/stdc++.h>
using namespace std;

// 2353. Design a Food Rating System

class FoodRatings
{
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int, string>>> cuisineToFoods;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); ++i)
        {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        cuisineToFoods[cuisine].erase({-oldRating, food});
        cuisineToFoods[cuisine].insert({-newRating, food});
        foodToRating[food] = newRating;
    }

    string highestRated(string cuisine)
    {
        return cuisineToFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main()
{
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings *obj = new FoodRatings(foods, cuisines, ratings);

    cout << obj->highestRated("korean") << "\n";   // kimchi
    cout << obj->highestRated("japanese") << "\n"; // ramen

    obj->changeRating("sushi", 16);

    cout << obj->highestRated("japanese") << "\n"; // sushi

    obj->changeRating("ramen", 16);

    cout << obj->highestRated("japanese") << "\n"; // ramen (lexicographically smaller than sushi)

    delete obj; // clean up
    return 0;
}