#include <iostream>
#include <string>
using namespace std;

void getNextNumber(string& alice_word)
{
    string::size_type pos = alice_word.find(" ");
    if (pos != string::npos)
    {
        alice_word = alice_word.substr(pos + 1);
    }
}

int main()
{
    string alice_word, final_word = ""s;
    int count_symbol;
    int W = 0;
    cin >> count_symbol;
    getline(cin, alice_word);
    getline(cin, alice_word);
    for (int i = 0; i < count_symbol; ++i)
    {
        int temp_W = W;
        W = stoi(alice_word);
        int temp_num = temp_W ^ W;
        temp_num = static_cast<int>(log2(temp_num));
        if (temp_num == 26)
        {
            final_word += " "s;
        }
        else
        {
            final_word += static_cast<char>(temp_num + 'a');
        }
        getNextNumber(alice_word);
    }
    cout << final_word << endl;
    return 0;
}