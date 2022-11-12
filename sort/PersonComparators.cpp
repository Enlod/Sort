#include "PersonComparators.h"
#include <algorithm>
#include <map>

namespace PersonComparators
{
	void removeRedundantChars(std::string& str)
	{
		str.erase(std::remove(str.begin(), str.end(), '’'), str.end());
	}

	char correctedChar(char original) {
		using Position = int;
		static std::map<char, Position> specialCharacters{
			{ '¯', -54 },
			{ '¿', -22 },
			{ '²', -55 },
			{ '³', -23 },
			{ '¥', -60 },
			{ '´', -28 },
			{ 'ª', -58 },
			{ 'º', -26 }
		};

		auto replacement = specialCharacters.find(original);
		if (replacement != specialCharacters.end())
		{
			return replacement->second;
		}
		else {
			return original;
		}
	}

	int compare(char lhs, char rhs)
	{
		lhs = correctedChar(lhs);
		rhs = correctedChar(rhs);
		if (lhs == rhs)
		{
			return 0;
		}
		return lhs < rhs ? -1 : 1;
	}

	int compare(std::string lhs, std::string rhs)
	{
		removeRedundantChars(lhs);
		removeRedundantChars(rhs);

		for (auto i = 0; i < lhs.size(); ++i)
		{
			if (i == rhs.size())
			{
				return 1;
			}
			auto charsCompareResult{ compare(lhs[i], rhs[i]) };
			if (charsCompareResult != 0)
			{
				return charsCompareResult;
			}
		}

		if (lhs.size() == rhs.size())
		{
			return 0;
		}
		else if (lhs.size() < rhs.size()) 
		{
			return -1;
		}
		else {
			return 1;
		}
	}

	bool ID::operator () (const Person& lhs, const Person& rhs) const
	{
		return lhs.id < rhs.id;
	}

#define FALLFACK_TO_ID(result)\
	static_assert(std::is_same_v<decltype(result), int>);\
	if (result != 0)\
	{\
		return result < 0;\
	}\
	else {\
		return ID{}(lhs, rhs);\
	}\

	bool FirstName::operator () (const Person& lhs, const Person& rhs) const
	{
		FALLFACK_TO_ID(compare(lhs.firstName, rhs.firstName))
	}

	bool SecondName::operator () (const Person& lhs, const Person& rhs) const
	{
		FALLFACK_TO_ID(compare(lhs.secondName, rhs.secondName))
	}

	bool Birth::operator () (const Person& lhs, const Person& rhs) const
	{
		FALLFACK_TO_ID(lhs.birth.compare(rhs.birth))
	}
};