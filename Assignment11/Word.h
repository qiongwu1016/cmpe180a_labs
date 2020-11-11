#ifndef WORD_H_
#define WORD_H_

#include <string>

using namespace std;

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    /**
     * Default constructor.
     */
    Word() : text(""), count(0) {}

    /**
     * Constructor.
     * Create a word entry with the given text. Initialize the count to 1.
     * @param text the text of the word.
     */
    Word(string text) : text(text), count(1) {}

    /**
     * Destructor.
     */
    virtual ~Word() {}

    /**
     * Getter.
     * @return the text.
     */
    string get_text() const { return text; }

    /**
     * Getter.
     * @return the count.
     */
    int get_count() const { return count; }

    /**
     * Increment the count by 1.
     */
    void increment_count() { count++; }

    /**
     * Overloaded != operator. Two word entries are unequal
     * if either their texts or their counts are unequal.
     */
    inline friend bool operator !=(const Word w1, const Word w2)
    {
        return (w1.text != w2.text) || (w1.count != w2.count);
    }

private:
    string text;
    int count;
};

#endif /* WORD_H_ */
