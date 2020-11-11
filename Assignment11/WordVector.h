

#ifndef WORDVECTOR_H_
#define WORDVECTOR_H_

#include <vector>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

/**
 * A sorted vector implementation for the concordance
 * that inherits a timer.
 */
class WordVector : public vector<Word>, public TimedContainer
{
public:
    /**
     * Default constructor.
     */
    WordVector() {}

    /**
     * Destructor.
     */
    virtual ~WordVector() {}

    /**
     * Getter.
     * @return the frequency count.
     */
    int get_count(const string text) const;

    /**
     * Insert a new word into the sorted vector,
     * or increment the count of an existing word.
     * Time this operation.
     * @param text the text of the word to insert or increment.
     */
    void insert(const string text);

    /**
     * Search the vector for a word entry with the given text.
     * Time this operation.
     * @param text the text of the word to find.
     * @return an iterator pointing to the word entry if found,
     *         or data.end() if not.
     */
    vector<Word>::iterator search(const string text);

private:
    /**
     * Helper function that performs a binary search of the sorted vector.
     * @param text the text of the target word.
     * @param low the lower index of the subrange to search.
     * @param high the upper index of the subrange to search.
     * @return the index of the match if found.
     */
    int find(const string text, int low, int high) const;
};

#endif /* WORDVECTOR_H_ */
