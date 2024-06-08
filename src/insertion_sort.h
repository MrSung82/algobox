#ifndef ALGOBOX_INSERTION_SORT_H
#define ALGOBOX_INSERTION_SORT_H



// Copyright(c) 2024 algobox MrSung82
// MIT License

#include <algorithm>

namespace abl
{
	
	template <typename RandomAccessIter, typename ComparePred = std::less<typename std::iterator_traits<RandomAccessIter>::value_type>>
	constexpr void insertion_sort(RandomAccessIter first, RandomAccessIter last, ComparePred cmp = ComparePred())
	{
		if (first == last)
			return;

		auto dist = std::distance(first, last);
		if (dist == 1)
			return;

		RandomAccessIter it = { first + 1 };
		
		for (; it != last; ++it)
		{
			auto value{ *it };
			auto sortedIt{ it - 1 };
			decltype(sortedIt + 1) placeIt;
			bool bEnd{};
			while (!bEnd && !cmp(*sortedIt, value))
			{
				placeIt = sortedIt + 1;
				*placeIt = *sortedIt;
				bEnd = (first == sortedIt);
				if (!bEnd)
				{
					--sortedIt;
				}
			}
			
			placeIt = (bEnd ? sortedIt : sortedIt + 1);
			*placeIt = value;
		}
	}


} // abl
#endif // ALGOBOX_INSERTION_SORT_H