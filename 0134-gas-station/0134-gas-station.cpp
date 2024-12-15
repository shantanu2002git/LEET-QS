class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int total_gas = 0, total_cost = 0, tank = 0, start = 0;

    // Step 1: Calculate total gas and total cost
    for (int i = 0; i < gas.size(); i++) {
        total_gas += gas[i];
        total_cost += cost[i];
    }

    // Step 2: Check if the trip is possible
    if (total_gas < total_cost) {
        return -1;
    }

    // Step 3: Find the starting station
    for (int i = 0; i < gas.size(); i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) { // If tank is negative, reset start and tank
            start = i + 1;
            tank = 0;
        }
    }

    return start;
    }
};