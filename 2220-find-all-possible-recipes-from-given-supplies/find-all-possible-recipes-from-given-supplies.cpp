#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_set<string> supplySet;
    unordered_set<string> readyItems;
    unordered_set<string> cantMakeItem;
    unordered_set<string> preparing;
    unordered_map<string, vector<string>> preRequisite;

    bool canMake(string key) {

        if (supplySet.count(key) || readyItems.count(key)) {
            return true;
        }
        if (cantMakeItem.count(key) ||
            preRequisite.find(key) == preRequisite.end() ||
            preparing.count(key)) {
            return false;
        }
        // Mark recipe as preparing to avoid cycles
        preparing.insert(key);
        // Check prerequisites recursively
        bool complete = true;
        for (const string& s : preRequisite[key]) {
            complete = complete && canMake(s);
            if (!complete) {
                break;
            }
        }
        if (complete) {
            readyItems.insert(key);
        } else {
            cantMakeItem.insert(key);
        }
        // Remove recipe from preparing list
        preparing.erase(key);
        return complete;
    }

    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        supplySet.insert(supplies.begin(), supplies.end());

        for (int i = 0; i < recipes.size(); ++i) {
            preRequisite[recipes[i]] = ingredients[i];
        }

        for (const auto& entry : preRequisite) {
            canMake(entry.first);
        }

        return vector<string>(readyItems.begin(), readyItems.end());
    }
};
