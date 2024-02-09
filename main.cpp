#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string getLongestCommonSubstring(const std::string &s1, const std::string &s2) {
    int len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<int> > dp(len1+1, std::vector<int>(len2+1, 0));
    int maxLength = 0, endPos;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i;
                }
            }
        }
    }

    std::string lcs;
    while (dp[endPos][maxLength] != 0) {
        lcs = s1[endPos-1] + lcs;
        --endPos;
        --maxLength;
    }

    return lcs;
}

int main() {
    std::string s1, s2;
    std::cout << "String 1:";
    std::cin >> s1;
    std::cout << "String 2: ";
    std::cin >> s2;

    std::string lcs = getLongestCommonSubstring(s1, s2);
    std::cout << "The longest common substring is: " << lcs << std::endl;
    return 0;
}
