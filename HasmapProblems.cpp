#include <unordered_map>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int highestFreq(int *arr, int n)
{
    unordered_map<int, int> freq;
    int maxNum = 0, maxF = 0;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        if (maxF < freq[arr[i]])
        {
            maxNum = arr[i];
            maxF = freq[arr[i]];
        }
    }
    return maxNum;
}
void intersection(int input1[], int input2[], int size1, int size2)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    unordered_map<int, int> freq;
    for (int i = 0; i < size1; i++)
    {
        freq[input1[i]]++;
    }
    for (int i = 0; i < size2; i++)
    {
        if (freq.count(input2[i]) == 0)
        {
            continue;
        }
        else
        {
            cout << input2[i] << endl;
            if (freq[input2[i]] == 0)
            {
                freq.erase(input2[i]);
            }
            else
            {
                freq[input2[i]]--;
            }
        }
    }
}
vector<int> removeDuplicates(vector<int> v)
{
    unordered_map<int, bool> map;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (map.count(v[i]) > 0)
        {
            continue;
        }
        map[v[i]] = true;
        ans.push_back(v[i]);
    }
    return ans;
}
void printPairSumTo0(int *arr, int size)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        int p = 0 - arr[i];
        if (freq[arr[i]] > 0 && freq[p] > 0)
        {
            int print = freq[arr[i]] * freq[p];
            while (print--)
            {
                cout << p << " " << arr[i] << endl;
            }
        }
        freq[arr[i]] = 0;
        freq[p] = 0;
    }
}
char *uniqueChar(char *str)
{
    // Write your code here

    unordered_map<char, int> freq;
    for (int i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]]++;
    }
    char *out = new char[freq.size()];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (freq[str[i]] > 0)
        {
            out[j] = str[i];
            j++;
        }
        freq[str[i]] = 0;
    }
    out[j] = '\0';
    return out;
}
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> pres;
    for (int i = 0; i < n; i++)
    {
        pres[arr[i]] = true;
    }
    int maxL = 0, maxS = arr[0];
    for (int i = 0; i < n; i++)
    {
        int maxC = 0, j = 1;
        while (pres.count(arr[i] + j) > 0)
        {
            maxC++;
            j++;
        }
        if (maxC > maxL)
        {
            maxL = maxC;
            maxS = arr[i];
        }
    }
    vector<int> out;
    for (int i = 0; i <= maxL; i++)
    {
        out.push_back(maxS + i);
    }
    return out;
}
int LongestSubseqSumTo0(int* arr, int n){
    unordered_map<int,int> cum;
    int max = 0;
    int sum = 0;
    for(int i = 0 ; i < n; i++){
        sum+=arr[i];
        if(cum.count(sum)>0){
            int cur = i - cum[sum];
            if(cur > max){
                max = cur;
            }
        }else{
            cum[sum]=i;
        }
    }
    return max;
}
void printPairs(int *input, int n, int k)
{
    // Write your code here
    unordered_map<int, int> freq;
    if(freq.size()==1)
    {
        int print = freq[input[0]]*2;
        print = print -2;
        while (print--)
        {
        cout << input[0] << " " << input[0] << endl;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        freq[input[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        int after = input[i] - k;
        int before = k - input[i];

        if (freq.count(after) > 0)
        {
            int print = freq[after] * freq[input[i]];
            while (print--)
            {
                if (after <= input[i])
                    cout << after << " " << input[i] << endl;
                else
                    cout << input[i] << " " << after << endl;
            }
        }
        if (freq.count(before) > 0)
        {
            int print = freq[before] * freq[input[i]];
            while (print--)
            {
                
                if (before <= input[i])
                    cout << before << " " << input[i] << endl;
                else
                    cout << input[i] << " " << before << endl;
            }
        }
    }
}
int main()
{
    /*int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        input.push_back(element);
    }
    vector<int> output = removeDuplicates(input);
   // cout << output.size() << endl;
    for (int  i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int output = highestFreq(arr,size);
    cout << output << endl;
    */
    int n2;
    cin >> n2;
    int *arr2 = new int[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    cout << "****output****" << endl;
    printPairSumTo0(arr2, n2);
    //intersection(arr, arr2, size, n2);
    //delete[] arr;
    delete[] arr2;
}