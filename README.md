# Word analysis
Here is my school project (2021) on analyzing texts by counting numbers of matches of all strings of fixed length in this text.

## Hypothesis
In English texts all letters have their supposed frequensy (as example, in text of 1000 symbols there would be about 100 letters 'O', 80 letters 'E' etc.). So purpose of this project is to figure out whether it is possible to determine "correctness" of given text by calculating for each string of fixed length, how many times does it occurs in this text, & compare this frequency distribution with frequency distribution of real, 100% correct text.

## Correctness of our hypothesis
To figure our whether our hypothesis is correct, and in how many cases it works correct. To do it, I've taken random part of analysed text (about 3000 words, you can find them in [file](https://github.com/andzh1/words-analysis/blob/main/wordsForCheck.txt)). Then for each word I checked whether it is correct (in terms of our hypothesis it means that it has biggest sum of matches via all strings that can be obtained by encryption of our word with Caesar's cipher). You can see results on following diagram:

 ![alt text](https://github.com/andzh1/words-analysis/blob/main/Diagramm%20of%20correctness.png) 
 
 As we see, our hypothesis works, and it's correctness grows up as words' length increases. Correctness of our algorithm is 75% in average; for words of length >= 8 it is 85%. 
 
 ## Process and implementation
 
 ### Algorithm of collecting matches: 
 For each substring of `SEQUENCE_SIZE` of given text, which contains only letters, we add to number of it's matches 1 when we meet it in the text.
 
 ### Algorighm of checking correctness:
 For each word in given list of words we calculate it's sum of matches (as sum of matches in our dataset of all substrings of `SEQUENCE_SIZE` of our word); then for each  *[shifted](#### Definitions)*
 
 You can find implementation of collecting matches from the text [in this file](https://github.com/andzh1/words-analysis/blob/main/getMatchesFromText.cpp), and implementation of checking correctness [here](https://github.com/andzh1/words-analysis/blob/main/wordCheck.h).

#### Definitions
- "match, matches" - pair of string & integer, represents how many times does this strings occurs in the text.
- "word" (occurs in program files) - can be not just a word, but also line or even text itself.
- "shifted" - 

**First part** of project was to collect database of matches from any big English text ([Lord Of The Rings](https://en.wikipedia.org/wiki/The_Lord_of_the_Rings) was chosen as enough big for our goal); you can check [resulting file](https://github.com/andzh1/words-analysis/blob/main/LordMatches.txt), [user interface](https://github.com/andzh1/words-analysis/blob/main/getMatchesFromText.cpp) and it's [implementation](https://github.com/andzh1/words-analysis/blob/main/getMatchesFromText.cpp)

**Second part** of project was to check out [hypothesis](#Hypothesis) - does it work at all and how correct is it.

## How to use it:
- You can set `SEQUENCE_SIZE` constant in [matches.h](https://github.com/andzh1/words-analysis/blob/main/matches.h)
- If you want to analyze your text (to get number of matches in it for all strings of fixed length), you should open [getMatchesFromText.cpp](https://github.com/andzh1/words-analysis/blob/main/getMatchesFromText.cpp) and read description how to run it there
- If you have already analyzed your text, or you want to have an exapmle of how does decoder works - open [main.cpp](https://github.com/andzh1/words-analysis/blob/main/main.cpp) and read description how to run it there
