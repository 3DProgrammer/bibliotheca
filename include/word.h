#ifndef BIBLIOTHECA_WORD_H
#define BIBLIOTHECA_WORD_H

#include <string>
#include <vector>
#include <array>

namespace bibliotheca {
    /*! Enum representing grammatical gender. */
    enum class Gender {
        m,
        f,
        n
    };
    /*! Enum representing case of a noun. */
    enum class Case {
        nom,
        acc,
        gen,
        dat,
        abl,
        voc
    };
    /*! Enum representing grammatical number. */
    enum class Number {
        singular,
        plural
    };
    template<size_t N>
    using PrincipalParts = std::array<std::string, N>;
    typedef std::vector<std::string> Translations;

    /*!
     * Abstract class representing a word. This should never be used directly.
     */
    class Word {
    public:
        virtual std::string getEnglish() = 0; //!<Returns the dictionary form of the word, in English.
        virtual std::string getLatin() = 0; //!<Returns the dictionary form of the word, in Latin.
    };

    /*!
     * Class representing a noun.
     */
    class Noun : public Word {
    private:
        std::string stem;
    public:
        PrincipalParts<2> spelling; //!<The nominative singular and genitive singular form of the word.
        Translations english; //!<The singular English translations of the word.
        Gender gender; //!<The grammatical gender of the noun.
        int declension; //!<The declension of the noun.
        /*!
         * Declines the noun in the specified case and number.
         * @param nounCase The grammatical case of the noun.
         * @param number The grammatical number of the noun.
         * @return The spelling of the noun.
         */
        std::string noun(Case nounCase, Number number);
    };
}
#endif //BIBLIOTHECA_WORD_H
