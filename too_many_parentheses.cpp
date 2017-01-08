#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string inputString;
	getline(cin,inputString);
	int numParentheses = 0;
	int numItems = 0;
	int seeker;
	for(int x = 0; x < inputString.length(); x++)
	{
		if(inputString[x] == '(')
		{
			cout << "Found Opening\n";
			if(inputString[x+1] == ')') //bonus
			{
				inputString.erase(x,2);
				x--;
				cout << "I erased and backed up\n";
			}
			else
			{
				x++;
				//Figuring out if the parentheses is extra or not, if
				//numParentheses comes back higher or equal to num items, it is extra
				for(seeker = x; seeker < inputString.length(); seeker++)
				{
					if(inputString[seeker] == ')')
					{
						cout << "Case 1\n";
						break;
					}
					else if(inputString[seeker] == '(')
					{
						cout << "Case 2\n";
						numParentheses++;
					}
					else
					{
						cout << "Case 3\n";
						numItems++;
					}
				}
				//erasing the extra parentheses
				if(numParentheses >= numItems && numParentheses >0)
					{
						cout << "removing: " << inputString[x] <<" and " << inputString[seeker] << "\n";
						inputString.erase(x,1);
						inputString.erase(seeker-1,1);
					}	
				//resetting the num variables for the next pass
				numItems = 0;
				numParentheses = 0;
			}
		}


	}
	cout << inputString <<"\n";
}