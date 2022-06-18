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
    /*! Enum representing verb tense. */
    enum class Tense {
        pluperfect,
        perfect,
        imperfect,
        present,
        future,
        futureperfect
    };
    /*! Enum representing verb voice. */
    enum class Voice {
        active,
        passive
    };
    /*! Enum representing verb mood. */
    enum class Mood {
        indicative,
        imperative,
        infinitive,
        subjunctive
    };
    /*! Enum representing adjective degree. */
    enum class Degree {
        positive,
        comparative,
        superlative
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

        std::string getEnglish() override; //!<Returns a list of English translations, in the singular.
        std::string getLatin() override; //!<Returns the nominative singular, genitive singular, and gender, in Latin.
        /*!
         * Constructor for noun.
         * @param _nomSing The nominative singular form of the noun.
         * @param _genSing The genitive singular form of the noun.
         * @param _gender The grammatical gender of the noun.
         * @param _english The English translations of the noun.
         * @param _declension The declension of the noun.
         */
        Noun(const std::string &_nomSing, const std::string &_genSing, Gender _gender, const Translations &_english,
             int _declension);
    };
    class Verb : public Word {
    public:
        PrincipalParts<4> spelling; //!<The active indicative 1st person singular present, active infinitive present, active indicative 1st person singular perfect, masculine singular perfect passive participle.
        Translations english; //!<The english translation of the verb.
        int conjugation; //!<The conjugation of the verb
        /*!
         * Conjugates a verb.
         * @param person The person of the verb (1st, 2nd or 3rd).
         * @param number The number of the verb (singular or plural).
         * @param tense The tense of the verb.
         * @param mood The mood of the verb (active or passive).
         * @param voice The voice of the verb.
         * @return The spelling of the verb.
         */
        std::string verb(int person, Number number, Tense tense, Mood mood, Voice voice);
        /*!
         * Conjugates a verb as a participle.
         * @param participleCase The case of the participle.
         * @param gender The grammatical gender of the participle.
         * @param number The number of the participle (singular or plural).
         * @param mood The mood of the participle (active or passive).
         * @param degree The degree of the participle.
         * @return The spelling of the participle.
         */
        std::string participle(Case participleCase, Gender gender, Number number, Mood mood, Degree degree);
        /*!
         * Constructor for a regular verb.
         * @param principalParts
         */
        Verb(PrincipalParts<4> principalParts);
        /*!
         * Constructor for a deponent verb.
         * @param principalParts
         */
        Verb(PrincipalParts<3> principalParts);
    };
}
#endif //BIBLIOTHECA_WORD_H
