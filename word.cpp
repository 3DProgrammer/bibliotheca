//
// Created by miles on 11/6/22.
//

#include <bibliotheca.h>
#include <map>
#include "word.h"

std::map<std::pair<bibliotheca::Case, bibliotheca::Number>, std::string> endings[5] = { //TODO: Macrons.
        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, "a"},  {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "am"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "ae"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "ae"}, {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "a"},
                {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "ae"}, {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "as"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "arum"}, {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "is"},   {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "is"}},

        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, "us"}, {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "um"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "i"},  {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "o"},  {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "o"},
                {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "i"},  {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "os"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "orum"}, {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "is"},   {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "is"}},

        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, ""},   {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "em"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "is"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "i"},  {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "e"},
                {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "es"}, {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "es"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "um"},   {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "ibus"}, {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "ibus"}},

        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, "us"}, {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "um"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "us"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "ui"}, {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "u"}, //TODO: 4th dec neuter.
                {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "us"}, {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "us"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "uum"},  {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "ibus"}, {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "ibus"}},

        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, "es"}, {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "em"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "ei"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "ei"}, {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "e"},
                {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "es"}, {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "es"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "erum"}, {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "ebus"}, {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "ebus"}},
};

std::string bibliotheca::Noun::noun(bibliotheca::Case nounCase, bibliotheca::Number number) {
    if (nounCase == Case::nom && number == Number::singular) {
        return spelling[0];
    }
    if (gender == Gender::n && number == Number::plural &&
        (nounCase == Case::nom || nounCase == Case::acc || nounCase == Case::voc)) {
        return stem + "a";
    }
    if (gender==Gender::n && number == Number::singular && (nounCase == Case::acc || nounCase == Case::voc)&&declension==3) {
        return spelling[0];
    }
    if (gender==Gender::n && number == Number::singular && (nounCase == Case::acc || nounCase == Case::voc)) {
        return stem+endings[declension-1][{Case::acc, Number::singular}];
    }
    if (nounCase == Case::voc) {
        if (number==Number::plural) {
            return noun(Case::nom, Number::plural);
        }
        if (declension == 2 && spelling[0][spelling[0].size() - 3] == 'i' &&
            spelling[0][spelling[0].size() - 2] == 'u'&&spelling[0][spelling[0].size() - 1] == 's') {
            std::string returnValue = spelling[0];
            returnValue.resize(returnValue.size() - 2);
            returnValue[returnValue.size() - 1] = 'i';
            return returnValue;
        }
        if (declension == 2 && spelling[0][spelling[0].size() - 2] == 'u' &&
            spelling[0][spelling[0].size() - 1] == 's') {
            std::string returnValue = spelling[0];
            returnValue.resize(returnValue.size() - 1);
            returnValue[returnValue.size() - 1] = 'e';
            return returnValue;
        }
        return noun(Case::nom, number);
    }
    return stem + endings[declension-1][{nounCase, number}];
}

std::string bibliotheca::Noun::getEnglish() {
    std::string result;
    for (int i = 0; i < english.size() - 1; i++) {
        result += english[i];
        result += ", ";
    }
    return result + english[english.size() - 1];
}

std::string bibliotheca::Noun::getLatin() {
    return spelling[0] + ", " + spelling[1] + " (" + (gender == Gender::m ? "m" : gender == Gender::f ? "f" : "n") +
           ")";
}

bibliotheca::Noun::Noun(const std::string &_nomSing, const std::string &_genSing, bibliotheca::Gender _gender,
                        const bibliotheca::Translations &_english, int _declension) {
    spelling[0]=_nomSing;
    spelling[1]=_genSing;
    gender=_gender;
    english=_english;
    declension=_declension;
    stem=_genSing;
    stem.resize(stem.size()-endings[declension-1][{Case::gen, Number::singular}].size());
}
