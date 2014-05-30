/*
 *given two words s1 and s2, find the minimum number of steps required to conevert s1 to s2.
 *
 *you have the following 3 operations permitted on a word
 *
 * insert a char
 * delete a char
 * replace a char
 *
 *
 *dp[i][j] = dp[i - 1][j - 1] if (a[i] == b[j])
 *       or = min(dp[i][j - 1], dp[i -  1][j], dp[i - 1][j - 1]) + 1;
 *
 * dp[0][j] = j and dp[i][0] = i
 * */

int min_dis(string s1, string s2)
{
    int size1 = s1.size();
    int size2 = s2.size();
    if (size1 == 0) return s2;
    if (size2 == 0) return s1;
    vector<vector<int> > w(size1 + 1, vector<int>(size2 + 1, 0));

    for (int i = 0; i <= size1; i++) w[i][0] = i;
    for (int i = 0; i <= size2; i++) w[0][i] = i;

    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
	{
            w[i][j] = min(w[i - 1][j] + 1, w[i][j - 1] + 1);
	    if (s1[i - 1] == s2[j - 1])
		    w[i][j] = min(w[i - 1][j - 1], w[i][j]);
	    else
		    w[i][j] = min(w[i - 1][j - 1] + 1, w[i][j]);
	}
    }
}


int main()
{

}
