# word-analysis
Here is my school project on analyzing texts by counting numbers of matches of all strings of fixed length in this text.

## Hypothesis
In English texts all letters have their supposed frequensy (as example, in text of 1000 symbols there would be about 100 letters 'O', 80 letters 'E' etc.). So purpose of this project is to figure out whether it is possible to determine "correctness" of given text by calculating for each string of fixed length, how many times does it occurs in this text, & compare this frequency distribution with frequency distribution of real, 100% correct text.

#### Definitions
- "match, matches" - pair of string & integer, represents how many times does this strings occurs in the text.
- "word" (occurs in program files) - can be not just a word, but also line or even text itself.

**First part** of project was to collect a big database of matches from any big English text ([Lord Of The Rings](https://en.wikipedia.org/wiki/The_Lord_of_the_Rings) was chosen as enough big for our goal); you can check [resulting file](https://github.com/andzh1/words-analysis/blob/main/LordMatches.txt).

**Second part** of project was to check out [hypothesis](#Hypothesis) - does it work at all and how correct is it.

## How to use it:
- You can set `SEQUENCE_SIZE` constant in [matches.h](https://github.com/andzh1/words-analysis/blob/main/matches.h)
- If you want to analyze your text (to get number of matches in it for all strings of fixed length), you should open [getMatchesFromText.cpp](https://github.com/andzh1/words-analysis/blob/main/getMatchesFromText.cpp) and read description how to run it there
- If you have already analyzed your text, or you want to have an exapmle of how does decoder works - open [main.cpp](https://github.com/andzh1/words-analysis/blob/main/main.cpp) and read description how to run it there
