#include <bits/stdc++.h>
using namespace std;

class bank {
public:
    string name;
    int netAmount;
    set<string> types;
};

int getMinIndex(bank listOfNetAmounts[], int numBanks) {
    int mn = INT_MAX, minIndex = -1;
    for (int i = 0; i < numBanks; i++) {
        if (listOfNetAmounts[i].netAmount == 0) continue;
        if (listOfNetAmounts[i].netAmount < mn) {
            minIndex = i;
            mn = listOfNetAmounts[i].netAmount;
        }
    }
    return minIndex;
}

int getSimpleMaxIndex(bank listOfNetAmounts[], int numBanks) {
    int mx = INT_MIN, maxIndex = -1;
    for (int i = 0; i < numBanks; i++) {
        if (listOfNetAmounts[i].netAmount == 0) continue;
        if (listOfNetAmounts[i].netAmount > mx) {
            maxIndex = i;
            mx = listOfNetAmounts[i].netAmount;
        }
    }
    return maxIndex;
}

pair<int, string> getMaxIndex(bank listOfNetAmounts[], int numBanks, int minIndex, bank input[], int maxNumTypes) {
    int mx = INT_MIN, maxIndex = -1;
    string matchingType;

    for (int i = 0; i < numBanks; i++) {
        if (listOfNetAmounts[i].netAmount == 0) continue;
        if (listOfNetAmounts[i].netAmount < 0) continue;

        vector<string> v(maxNumTypes);
        auto ls = set_intersection(
            listOfNetAmounts[minIndex].types.begin(), listOfNetAmounts[minIndex].types.end(),
            listOfNetAmounts[i].types.begin(), listOfNetAmounts[i].types.end(),
            v.begin()
        );

        if ((ls - v.begin()) != 0 && mx < listOfNetAmounts[i].netAmount) {
            mx = listOfNetAmounts[i].netAmount;
            maxIndex = i;
            matchingType = *(v.begin());
        }
    }

    return make_pair(maxIndex, matchingType);
}

void printAns(vector<vector<pair<int, string>>> ansGraph, int numBanks, bank input[]) {
    cout << "\n=== Settlements for this test start here ===\n\n";
    cout << "The transactions for minimum cash flow are as follows:\n\n";
    for (int i = 0; i < numBanks; i++) {
        for (int j = 0; j < numBanks; j++) {
            if (i == j) continue;
            if (ansGraph[i][j].first != 0 && ansGraph[j][i].first != 0) {
                if (ansGraph[i][j].first == ansGraph[j][i].first) {
                    ansGraph[i][j].first = 0;
                    ansGraph[j][i].first = 0;
                }
                else if (ansGraph[i][j].first > ansGraph[j][i].first) {
                    ansGraph[i][j].first -= ansGraph[j][i].first;
                    ansGraph[j][i].first = 0;
                    cout << input[i].name << " pays Rs " << ansGraph[i][j].first
                         << " to " << input[j].name << " via " << ansGraph[i][j].second << endl;
                }
                else {
                    ansGraph[j][i].first -= ansGraph[i][j].first;
                    ansGraph[i][j].first = 0;
                    cout << input[j].name << " pays Rs " << ansGraph[j][i].first
                         << " to " << input[i].name << " via " << ansGraph[j][i].second << endl;
                }
            }
            else if (ansGraph[i][j].first != 0) {
                cout << input[i].name << " pays Rs " << ansGraph[i][j].first
                     << " to " << input[j].name << " via " << ansGraph[i][j].second << endl;
            }
            else if (ansGraph[j][i].first != 0) {
                cout << input[j].name << " pays Rs " << ansGraph[j][i].first
                     << " to " << input[i].name << " via " << ansGraph[j][i].second << endl;
            }
            ansGraph[i][j].first = 0;
            ansGraph[j][i].first = 0;
        }
    }
    cout << "\n=== Settlements for this test end here ===\n\n";
}

void minimizeCashFlow(int numBanks, bank input[], unordered_map<string,int>& indexOf,
                      int numTransactions, vector<vector<int>>& graph, int maxNumTypes) {
    bank listOfNetAmounts[numBanks];

    for (int b = 0; b < numBanks; b++) {
        listOfNetAmounts[b].name = input[b].name;
        listOfNetAmounts[b].types = input[b].types;
        int amount = 0;
        for (int i = 0; i < numBanks; i++) amount += graph[i][b];
        for (int j = 0; j < numBanks; j++) amount -= graph[b][j];
        listOfNetAmounts[b].netAmount = amount;
    }

    vector<vector<pair<int, string>>> ansGraph(
        numBanks, vector<pair<int, string>>(numBanks, {0, ""}));

    int numZeroNetAmounts = 0;
    for (int i = 0; i < numBanks; i++) if (listOfNetAmounts[i].netAmount == 0) numZeroNetAmounts++;

    while (numZeroNetAmounts != numBanks) {
        int minIndex = getMinIndex(listOfNetAmounts, numBanks);
        auto maxAns = getMaxIndex(listOfNetAmounts, numBanks, minIndex, input, maxNumTypes);
        int maxIndex = maxAns.first;

        if (maxIndex == -1) {
            ansGraph[minIndex][0].first += abs(listOfNetAmounts[minIndex].netAmount);
            ansGraph[minIndex][0].second = *(input[minIndex].types.begin());
            int simpleMaxIndex = getSimpleMaxIndex(listOfNetAmounts, numBanks);
            ansGraph[0][simpleMaxIndex].first += abs(listOfNetAmounts[minIndex].netAmount);
            ansGraph[0][simpleMaxIndex].second = *(input[simpleMaxIndex].types.begin());
            listOfNetAmounts[simpleMaxIndex].netAmount += listOfNetAmounts[minIndex].netAmount;
            listOfNetAmounts[minIndex].netAmount = 0;
            if (listOfNetAmounts[minIndex].netAmount == 0) numZeroNetAmounts++;
            if (listOfNetAmounts[simpleMaxIndex].netAmount == 0) numZeroNetAmounts++;
        }
        else {
            int transactionAmount = min(abs(listOfNetAmounts[minIndex].netAmount),
                                        listOfNetAmounts[maxIndex].netAmount);
            ansGraph[minIndex][maxIndex].first += transactionAmount;
            ansGraph[minIndex][maxIndex].second = maxAns.second;
            listOfNetAmounts[minIndex].netAmount += transactionAmount;
            listOfNetAmounts[maxIndex].netAmount -= transactionAmount;
            if (listOfNetAmounts[minIndex].netAmount == 0) numZeroNetAmounts++;
            if (listOfNetAmounts[maxIndex].netAmount == 0) numZeroNetAmounts++;
        }
    }

    printAns(ansGraph, numBanks, input);
}

bool isCommentOrEmpty(const string& line) {
    for (char c : line) {
        if (isspace(c)) continue;
        return (c == '#');
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    vector<string> tokens;

    auto nextToken = [&]() -> bool {
        while (getline(cin, line)) {
            if (isCommentOrEmpty(line)) continue;
            tokens.clear();
            istringstream iss(line);
            string w;
            while (iss >> w) tokens.push_back(w);
            return !tokens.empty();
        }
        return false;
    };

    while (true) {
        if (!nextToken()) break;
        int numBanks = stoi(tokens[0]);

        vector<bank> input(numBanks);
        unordered_map<string,int> indexOf;
        int maxNumTypes = 0;

        for (int i = 0; i < numBanks; ++i) {
            nextToken();
            input[i].name = tokens[0];
            indexOf[tokens[0]] = i;
            int numTypes = stoi(tokens[1]);
            maxNumTypes = max(maxNumTypes, numTypes);
            for (int j = 0; j < numTypes; ++j)
                input[i].types.insert(tokens[2 + j]);
        }

        nextToken();
        int numTransactions = stoi(tokens[0]);

        vector<vector<int>> graph(numBanks, vector<int>(numBanks, 0));
        for (int t = 0; t < numTransactions; ++t) {
            nextToken();
            graph[indexOf[tokens[0]]][indexOf[tokens[1]]] = stoi(tokens[2]);
        }

        minimizeCashFlow(numBanks, input.data(), indexOf, numTransactions, graph, maxNumTypes);
    }

    return 0;
}
