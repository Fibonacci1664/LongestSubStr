#include<iostream>
#include<map>

int lengthOfLongestSubstring(std::string s)
{
	if (s.size() == 0)
	{
		return 0;
	}

	// Use a map as this will only be able to store unique elements
	std::map<char, bool> preVisited;

	// Keep track of our current count substring size
	int counter = 0;

	// Keep track of largest substring found
	int largest = 0;

	// Have a bool to check whether insertion happened
	bool insertionHappened = false;

	auto iterator = s.begin();

	while (iterator != s.end())
	{
		// Loop over all chars in string
		for (auto iter = iterator; iter != s.end(); ++iter)
		{
			// Emplace returns a pair, first = iterator to position of element, second = bool on whether or not insertion happened
			auto it = preVisited.emplace(*iter, true);
			insertionHappened = it.second;

			// If the insertion didn't happen then it's because the char already exists in the map, so break
			if (!insertionHappened)
			{
				break;
			}

			// Keep current count
			++counter;
		}

		// Set/reset largest value found so far
		if (counter > largest)
		{
			largest = counter;
		}

		counter = 0;
		++iterator;

		// Make sure we wipe the map, so we can start again at the next iteration
		preVisited.clear();
	}

	return largest;
}

int main()
{
	// TEST CASES
	std::string test1 = "abcabcbb";
	std::string test2 = "bbbbb";
	std::string test3 = "pwwkew";

	int ans = lengthOfLongestSubstring(test3);

	std::cout << "The longest substring of " << test3 << " is " << ans << '\n';

	return 0;
}