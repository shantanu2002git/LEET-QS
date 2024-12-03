class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int n = sentence.size(), k = searchWord.size();
        // sentence=" "+sentence;
        int spcae = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 && sentence.substr(i , k) == searchWord)
            {
               // cout << sentence.substr(i , k);
                    return spcae + 1;
            }
            if ((sentence[i] == ' '))
            {
                spcae++;
                if (sentence.substr(i + 1, k) == searchWord)
                {
                  //  cout << sentence.substr(i + 1, k);
                    return spcae + 1;
                }
            }
        }
        return -1;
    }
};