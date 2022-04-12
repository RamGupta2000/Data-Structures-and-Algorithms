#include <bits/stdc++.h>
using namespace std;

string wordsToNumber(string s)
{
    vector<string> numbers{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> times{"double", "triple"};

    string temp;
    string ans = "";
    int flag = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (i == s.length() - 1)
        {
            temp.push_back(s.at(i));
        }
        if (isspace(s[i]) || i == s.length() - 1)
        {
            auto it = find(numbers.begin(), numbers.end(), temp);

            if (it != numbers.end())
            {
                if (flag > 0)
                {
                    for (int j = 0; j < flag; j++)
                    {
                        ans += to_string(it - numbers.begin());
                    }
                    flag = 0;
                }
                else
                    ans += to_string(it - numbers.begin());
            }
            else
            {
                it = find(times.begin(), times.end(), temp);
                if (it != times.end())
                {
                    flag = (it - times.begin()) + 2;
                }
            }
            temp = "";
        }
        else
            temp.push_back(s.at(i));
    }
    cout << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = wordsToNumber(s);

    fout << result << "\n";

    fout.close();

    return 0;
}