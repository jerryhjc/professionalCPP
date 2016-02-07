// reorder string to be palindrome

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void foundPalindrome()
{

string str = "abd";

map<char, int> mp; 
for(int i = 0; i < str.size(); i++)
    mp[str[i]]++;

int i = 0;
int j = str.size() - 1;
int mid = str.size() / 2; 
int k = 1;

if(str.size() == 0)
{
        cout << "no found palindrome string" << endl;
        return;
}  

// check corner case string with all single char "abcd"
for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
{   
    static int count; 
    if(it->second == 1)
        count++;
    if(count > 1 && mp.size() > 1)
    {
        cout << "no found palindrome string" << endl;
        return;
    }   
}


for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
{
    //if count number is even, 
    while(it->second % 2 == 0 && it->second != 0)
    {  
        str[i] = it->first;
        str[j] = it->first;
        it->second -= 2;
        i++, j--; 
    }
    
    // if count number is odd, 
    while(it->second % 2 != 0 && it->second != 0)
    {
    	// if string size is even
        if(str.size() % 2 == 0)
        {
     	    str = "";
            return;
        }
        
        // if count number is 1
        if(it->second == 1)
        {
            str[mid] = it->first;
            it->second -= 1;
        }
        else  // if count number odd number other than 1
        {
            
            str[mid - k] = it->first;
            str[mid + k] = it->first;
            k++;
            it->second -= 2;
        }
    }
            
 }
 
 cout << str << endl;

}



int main() {
	// your code goes here
	function(); 
	return 0;
}
