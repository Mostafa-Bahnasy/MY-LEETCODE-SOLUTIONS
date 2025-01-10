struct TinyInt {
    unsigned int value :29 = 0; // 3 bits, can store values 0-7
};



class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        TinyInt maxDifficulty ;
        maxDifficulty.value= *max_element(difficulty.begin(), difficulty.end());
        vector<TinyInt> maxProfitUpToDifficulty(maxDifficulty.value + 1);

        for (int i = 0; i < difficulty.size(); ++i) {
            TinyInt tmp;
            tmp.value = profit[i];
            maxProfitUpToDifficulty[difficulty[i]].value = max(maxProfitUpToDifficulty[difficulty[i]].value,tmp.value);
        }

        for (int i = 1; i <= maxDifficulty.value; ++i) {
            maxProfitUpToDifficulty[i].value = max(maxProfitUpToDifficulty[i].value, maxProfitUpToDifficulty[i - 1].value);
        }

        unsigned int totalProfit =0;
        for (int ability : worker) {
            if (ability > maxDifficulty.value) {
                totalProfit += maxProfitUpToDifficulty[maxDifficulty.value].value;
            } else {
                totalProfit += maxProfitUpToDifficulty[ability].value;
            }
        }
        int ret = totalProfit;
        return ret;
    }
};