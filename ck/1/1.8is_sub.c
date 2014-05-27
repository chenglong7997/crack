/*
 *Assume you have a method is_substring which checks if one word is a substring
 *of another.Given two strings, s1 and s2, write code to check if s2 is a rotation
 *of s1 using only one call to is_substring
 *
 * */

int is_rotation(string s1, string s2)
{
    string str = s1 + s1;
    return is_substring(s2, str);
}


int main()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat"
    printf("ret code: %d\n", is_rotation(s1, s2));
}
