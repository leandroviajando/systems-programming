
/**
 * @file UnorderedMapExercises.cpp
 * University of Illinois CS 400, MOOC 3, Week 1: Unordered Map
 * Spring 2019
 *                        STUDENT STARTER FILE
 *
 * @author Eric Huber - University of Illinois staff
 *
 **/

#include <iostream>

#include "UnorderedMapCommon.h"

// makeWordCounts: Given a vector of (non-unique) strings, returns a
// StringIntMap where each string is mapped to its number of occurences.
StringIntMap makeWordCounts(const StringVec& words) {
  StringIntMap wordcount_map;

  for (const std::string& word : words)
    wordcount_map[word]++;

  return wordcount_map;
}

// The lookupWithFallback function is a wrapper function for safely
// performing lookups on a read-only std::unordered_map object.
//
// People commonly use the [] operator with maps to conveniently do both
// assignments and lookups, but the [] operator will insert a new key with a
// default value when the key is not found. Sometimes that is not desirable!
// (Also, if the map is marked "const", you will not be able to use the []
// operator on it, because the map is read-only.)
int lookupWithFallback(const StringIntMap& wordcount_map, const std::string& key, int fallbackVal) {
  return wordcount_map.count(key)
             ? wordcount_map.at(key)
             : fallbackVal;
}

// This is the memoized version of a recursive function for finding the
// maximum palindrome substring length.
//
// The startTime and maxDuration parameters are used by the grader to make
// sure your function doesn't accidentally run very slow.
int memoizedLongestPalindromeLength(LengthMemo& memo, const std::string& str, int leftLimit, int rightLimit, timeUnit startTime, double maxDuration) {
  // Check validity of indices for debugging. The indices shouldn't be negative
  // unless it's the special base case where they cross during recursion.
  // We handle that case further below.
  if (leftLimit < 0 && leftLimit <= rightLimit)
    throw std::runtime_error("leftLimit negative, but it's not the base case");
  if (rightLimit < 0 && leftLimit <= rightLimit)
    throw std::runtime_error("rightLimit negative, but it's not the base case");

  // Apart from that, in the following code, the std::string::at() function
  // will throw an exception if an index is out of bounds.

  if (false) {
    int range = rightLimit - leftLimit + 1;
    if (range < 0) range = 0;
    std::cout << "Considering substring: " << str.substr(leftLimit, range) << std::endl;
    std::cout << " because l/r limits are: " << leftLimit << " " << rightLimit << std::endl;
  }

  // It's possible that a student could make a mistake in this function that
  // would cause it to take even longer than brute force (or never finish).
  const auto currentTime = getTimeNow();
  const auto timeElapsed = getMilliDuration(startTime, currentTime);
  if (timeElapsed > maxDuration)
    throw TooSlowException("taking too long");

  // Here's the memoization key for this pair of limit integers.
  // IntPair is our type alias for std::pair<int, int>
  const IntPair pairKey = std::make_pair(leftLimit, rightLimit);

  // The count() function of unordered_map tells us if the key is already in the map.
  // It returns 1 if found and otherwise 0. (These values convert to true and false.)
  // (It's important to not just use memo[pairKey] in this check, because that will
  // create the entry with a default value if it doesn't already exist!)
  if (memo.count(pairKey))
    return memo.at(pairKey);

  // If the memoization table didn't have an entry for this key yet,
  // then we're solving this subproblem for the first time.
  // Below, we'll record our result to make sure we don't have to solve it again.

  // Base case: Return 0 as the longest palindrome length when the indices cross.
  // This case could be triggered during our recursive steps defined below.
  if (leftLimit > rightLimit) {
    // Since this case already returns in constant time (that is, O(1) time)
    // without recursing further, we don't really need to memoize it,
    // but we will anyway as an example. In practice, we could save memory
    // by not memoizing unless necessary. Another reason why you might want
    // to memoize every subproblem is to help in reconstructing what the
    // optimal solution was, after the algorithm finishes running.

    // ====================================================================
    // EXAMPLE: This base case has already been memoized!
    memo[pairKey] = 0;
    return 0;
    // ====================================================================
  }

  // A single-character substring is a palindrome of size 1.
  // We include the character check with .at() to make sure the string isn't
  // empty and that the indices are valid.
  if (leftLimit == rightLimit && str.at(leftLimit) == str.at(rightLimit)) {
    // Another O(1) return case that we'll memoize anyway for completeness.

    // ====================================================================
    // EXAMPLE: This base case has already been memoized!
    memo[pairKey] = 1;
    return 1;
    // ====================================================================
  }

  // If the first and last character match, then...
  if (str.at(leftLimit) == str.at(rightLimit)) {
    int newLeft = leftLimit + 1;
    int newRight = rightLimit - 1;

    // Solve the middle subproblem.
    int middleSubproblemResult = memoizedLongestPalindromeLength(memo, str, newLeft, newRight, startTime, maxDuration);

    // (Base case note: Suppose that str had length 2, so after moving the indices,
    // now newLeft > newRight. Because we handled the crossing case already,
    // in that situation, middleSubproblemResult correctly gets value 0.)

    // For reference, let's calculate the longest length possible in the
    // middle substring range.
    int middleMaxLength = newRight - newLeft + 1;
    // In the base case situation when the indices cross,
    // we force this value to be 0 instead of negative.
    if (middleMaxLength < 0) middleMaxLength = 0;

    // If the middle subproblem result equals the entire length
    // of the middle substring, then the middle substring is a palindrome.
    // So, since the first and last outer characters match each other,
    // the entire string between leftLimit and rightLimit is a palindrome.
    if (middleSubproblemResult == middleMaxLength) {
      int result = 2 + middleSubproblemResult;

      // This result, which we should memoize, is for the range between the
      // original leftLimit and rightLimit. (It's not for the inner range
      // between newLeft and newRight. The recursive call already memoized
      // that.)

      // ==================================================================
      // EXAMPLE: This recursive case has already been memoized!
      memo[pairKey] = result;
      return result;
      // ==================================================================
    }
  }

  // If we've reached this line (i.e. not returned yet), we know the entire
  // string between leftLimit and rightLimit, inclusive, is NOT a palindrome.
  // That means we still need to try moving in each of the left limit
  // and right limit, separately, and compare the results.

  int leftSubproblemResult = memoizedLongestPalindromeLength(memo, str, leftLimit, rightLimit - 1, startTime, maxDuration);
  int rightSubproblemResult = memoizedLongestPalindromeLength(memo, str, leftLimit + 1, rightLimit, startTime, maxDuration);
  int greaterResult = std::max(leftSubproblemResult, rightSubproblemResult);

  memo[pairKey] = greaterResult;
  return greaterResult;
}
