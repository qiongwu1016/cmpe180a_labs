#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <stdlib.h>
#include "Word.h"
#include "WordVector.h"
#include "WordList.h"
#include "WordMap.h"

using namespace std;

const string INPUT_FILE_NAME = "USConstitution.txt";
const int    MAX_SEARCHES    = 100000;

/**
 * Insert words into the concordances.
 * Time this operation.
 * @param in the input stream.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void time_word_insertions(ifstream& in, WordVector& v, WordList& l, WordMap& m);

/**
 * Perform spot checks of some words.
 * Make sure the vector and map concordances agree with each other.
 * Throw an exception if they don't agree.
 */
void make_spot_checks(WordVector& v, WordList& l, WordMap& m) throw(string);

/**
 * Iterate over the vector, list, and map concordances in parallel and
 * ensure that all agree over all the entries and in the same order.
 * Throw an exception if they don't agree.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void check_concordances(WordVector& v, WordList& l, WordMap& m) throw(string);

/**
 * Perform random searches of words in the concordances.
 * Time this operation.
 * Throw an exception if a word isn't found.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void time_word_searches(WordVector& v, WordList& l, WordMap& m) throw(string);

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n);

/**
 * The main.
 */
int main()
{
    ifstream in;
    in.open(INPUT_FILE_NAME);
    if (in.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    WordVector v;  // the concordance based on an STL vector
    WordList   l;  // the concordance based on an STL list
    WordMap    m;  // the concordance based on an STL map

    try
    {
        time_word_insertions(in, v, l, m);
        make_spot_checks(v, l, m);
        check_concordances(v, l, m);
        time_word_searches(v, l, m);
    }
    catch (string& msg)
    {
        cout << endl << "***** " << msg << endl;
    }

    cout << endl << "Done!" << endl;
   // for (int i =0; i < v.size(); i++) cout<<v[i].get_text()<<"   "<<endl;
    return 0;


}

void time_word_insertions(ifstream& in, WordVector& v, WordList& l, WordMap& m)
{
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;

    cout << "Timed insertions" << endl;
    cout << "----------------" << endl;

    // Loop once per line of the input file.
    while (getline(in, line))
    {
        ++line_count;

        int i = 0;
        int line_length = line.length();
        string text = "";

        character_count += line_length;

        // Loop once per character of the line.
        while (i < line_length)
        {
            // Have we found a word?
            if (isalpha(line[i]))
            {
                // Make the word all lower case.
                do
                {
                    text += tolower(line[i]);
                    i++;
                } while ((i < line_length) && (isalpha(line[i])));

                word_count++;

                // Insert the word into the concordances.
                v.insert(text);

                l.insert(text);

                m.insert(text);


                text = "";  // get ready for the next word
            }


            i++;
        }
    }

    cout << "      Lines: " << setw(6) << commafy(line_count) << endl;
    cout << " Characters: " << setw(6) << commafy(character_count) << endl;
    cout << "      Words: " << setw(6) << commafy(word_count) << endl;
    cout << endl;
    cout << "Vector size: " << commafy(v.size()) << endl;
    cout << "  List size: " << commafy(l.size()) << endl;
    cout << "   Map size: " << commafy(m.size()) << endl;
    cout << endl;
    cout << "Vector total insertion time: " << setw(7)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "  List total insertion time: " << setw(7)
         << commafy(l.get_elapsed_time()) << " usec" << endl;
    cout << "   Map total insertion time: " << setw(7)
         << commafy(m.get_elapsed_time()) << " usec" << endl;


}

void make_spot_checks(WordVector& v, WordList& l, WordMap& m) throw(string)
{
    cout << endl;
    cout << "Spot checks of word counts" << endl;
    cout << "--------------------------" << endl;

    // Words to check.
    vector<string> texts;
	texts.push_back("amendment");
	texts.push_back("article");
	texts.push_back("ballot");
	texts.push_back("citizens");
	texts.push_back("congress");
	texts.push_back("constitution");
	texts.push_back("democracy");
	texts.push_back("electors");
	texts.push_back("government");
	texts.push_back("law");
	texts.push_back("legislature");
	texts.push_back("people");
	texts.push_back("president");
	texts.push_back("representatives");
	texts.push_back("right");
	texts.push_back("trust");
	texts.push_back("united");
	texts.push_back("vice");
	texts.push_back("vote");



    // Loop over each word.
    for (string text : texts)
    {
        cout << setw(15) << text << ": ";

        // Search all concordances.
        vector<Word>::iterator      itv = v.search(text);
        list<Word>::iterator        itl = l.search(text);
        map<string, Word>::iterator itm = m.search(text);

        int vcount = 0;
        int lcount = 0;
        int mcount = 0;

        // If the word exists, get the counts from all concordances.
        if (itv != v.end()) vcount = itv->get_count();
        if (itl != l.end()) lcount = itl->get_count();
        if (itm != m.end()) mcount = itm->second.get_count();

        cout << "vector:" << setw(3) << vcount
             << "\tlist:" << setw(3) << lcount
             << "\tmap:"  << setw(3) << mcount;
        if (vcount == 0) cout << "\t!!!";
        cout << endl;

        // Do the counts match?
        if ((vcount != lcount) || ((vcount != mcount)))
        {
            throw "Count mismatch: " + text + ": "
                      + to_string(vcount) + " (vector) vs "
                      + to_string(lcount) + " (list) vs "
                      + to_string(mcount) + " (map)";
        }
    }
}

void check_concordances(WordVector& v, WordList& l, WordMap& m) throw(string)
{
    cout << endl;
    cout << "Checking concordance versions" << endl;
    cout << "-----------------------------" << endl;

    int vsize = v.size();
    int lsize = l.size();
    int msize = m.size();

    if (vsize == 0) throw "Empty vector.";
    if (lsize == 0) throw "Empty list.";
    if (msize == 0) throw "Empty map.";

    // Do the number of unique words agree?
    if ((vsize != lsize) || (vsize != msize))
    {
        throw "Size mismatch: "
                  + to_string(vsize) + " (vector) vs "
                  + to_string(lsize) + " (list) vs "
                  + to_string(msize) + " (map)";
    }

    vector<Word>::iterator      itv = v.begin();
    list<Word>::iterator        itl = l.begin();
    map<string, Word>::iterator itm = m.begin();

    // Iterate over all concordances in parallel.
    while (itv != v.end())
    {
        // Does each word agree?
        if ((*itv != *itl) || (*itv != itm->second))
        {
            throw "Data mismatch: "
                    + itv->get_text() + ":"
                    + to_string(itv->get_count())
                    + " (vector) vs " + itl->get_text() + ":"
                    + to_string(itl->get_count())
                    + " (list) vs " + itm->second.get_text() + ":"
                    + to_string(itm->second.get_count()) + " (map)";
        }

        ++itv;
        ++itl;
        ++itm;
    }

    cout << "All match!" << endl;
}

void time_word_searches(WordVector& v, WordList& l, WordMap& m) throw(string)
{
    cout << endl;
    cout << "Timed searches (" << commafy(MAX_SEARCHES)
         << " searches)" << endl;
    cout << "--------------" << endl;

    int size = v.size();
    srand(time(NULL));

    v.reset_elapsed_time();
    l.reset_elapsed_time();
    m.reset_elapsed_time();

    // Loop to perform searches.
    for (int i = 1; i <= MAX_SEARCHES; i++)
    {
        // Pick a random word in the concordance.
        int index = rand()%size;
        string text = v[index].get_text();

        // Is it in the vector concordance?
        if (v.search(text) == v.end())
        {
            throw string("Not found in vector: ") + text;
        }

        // Is it in the list concordance?
        if (l.search(text) == l.end())
        {
            throw string("Not found in list: ") + text;
        }

        // Is it in the map concordance?
        if (m.search(text) == m.end())
        {
            throw string("Not found in map: ") + text;
        }
    }

    cout << "Vector total search time: " << setw(9)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "  List total search time: " << setw(9)
         << commafy(l.get_elapsed_time()) << " usec" << endl;
    cout << "   Map total search time: " << setw(9)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}

string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
