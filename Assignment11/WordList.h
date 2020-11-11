

#ifndef WORDLIST_H_
#define WORDLIST_H_

#include <list>
#include "TimedContainer.h"


using namespace std;

/**
 * A sorted list implementation for the concordance
 * that inherits a timer.
 */
class WordList : public list<Word>, public TimedContainer
{
public:
    /**
     * Default constructor.
     */
    WordList() {}

    /**
     * Destructor.
     */
    virtual ~WordList() {}

    /**
     * Getter.
     * @return the frequency count.
     */
    int get_count(const string text);

    /**
     * Insert a new word into the sorted list,
     * or increment the count of an existing word.
     * Time this operation.
     * @param text the text of the word to insert or increment.
     */
    void insert(const string text);

    /**
     * Search the list for a word entry with the given text.
     * Time this operation.
     * @param text the text of the word to find.
     * @return an iterator pointing to the word entry if found,
     *         or data.end() if not.
     */
    list<Word>::iterator search(const string text);
};

#endif /* WORDLIST_H_ */
