#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {
    auto temp = arr;
    auto sorted = arr;
    sort(sorted.begin(), sorted.end());
    auto reversed = arr;
    sort(reversed.begin(), reversed.end(), greater<int>());

    int count_sorted = 0;
    int preValue;
    unordered_map<int, int> m;
    for(auto i = 0; i < arr.size(); i++){
        m[arr[i]] = i;
    }
    for(auto i= 0; i < arr.size(); i++){
        if(sorted[i] != temp[i]){
            preValue = temp[i];
            swap(temp[i], temp[m[sorted[i]]]);
            m[preValue] = m[sorted[i]];
            count_sorted++;
        }
    }

    int count_reversed = 0;
    temp = arr;
    for(auto i = 0; i < arr.size(); i++){
        m[arr[i]] = i;
    }
    for(auto i= 0; i < arr.size(); i++){
        if(reversed[i] != temp[i]){
            preValue = temp[i];
            swap(temp[i], temp[m[reversed[i]]]);
            m[preValue] = m[reversed[i]];
            count_reversed++;
            if(count_reversed > count_sorted){
                return count_sorted;
            }
        }
    }

    return count_reversed;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
