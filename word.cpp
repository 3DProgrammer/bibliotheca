//
// Created by miles on 11/6/22.
//

#include "word.h"
#include <bibliotheca.h>
#include <map>
std::string imperfectEsse(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "eram";
            case 2:
                return "eras";
            case 3:
                return "erat";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "eramus";
            case 2:
                return "eratis";
            case 3:
                return "erant";
        }
    }
    return "";
}
std::string subjunctiveEsse(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "sim";
            case 2:
                return "sis";
            case 3:
                return "sit";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "simus";
            case 2:
                return "sitis";
            case 3:
                return "sint";
        }
    }
    return "";
}
std::string imperfectSubjunctiveEsse(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "essem";
            case 2:
                return "esses";
            case 3:
                return "esset";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "essemus";
            case 2:
                return "essetis";
            case 3:
                return "essent";
        }
    }
    return "";
}
std::string presentEsse(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "sum";
            case 2:
                return "es";
            case 3:
                return "est";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "sumus";
            case 2:
                return "estis";
            case 3:
                return "sunt";
        }
    }
    return "";
}
std::string futureEsse(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "ero";
            case 2:
                return "eris";
            case 3:
                return "erit";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "erimus";
            case 2:
                return "eritis";
            case 3:
                return "erunt";
        }
    }
    return "";
}
std::string perfectEndings(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "i";
            case 2:
                return "isti";
            case 3:
                return "it";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "imus";
            case 2:
                return "istis";
            case 3:
                return "erunt";
        }
    }
    return "";
}
std::string standardVerbEndings(bibliotheca::Number number, int person, bool o) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return o ? "o" : "m";
            case 2:
                return "s";
            case 3:
                return "t";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "mus";
            case 2:
                return "tis";
            case 3:
                return "nt";
        }
    }
    return "";
}
std::string firstSecondFutureEndings(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "bo";
            case 2:
                return "bis";
            case 3:
                return "bit";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "bimus";
            case 2:
                return "bitis";
            case 3:
                return "bunt";
        }
    }
    return "";
}
std::string thirdFourthFutureEndings(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "am";
            case 2:
                return "et";
            case 3:
                return "et";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "emus";
            case 2:
                return "etis";
            case 3:
                return "ent";
        }
    }
    return "";
}
std::string futurePerfectEndings(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "ero";
            case 2:
                return "eris";
            case 3:
                return "erit";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "erimus";
            case 2:
                return "eritis";
            case 3:
                return "erint";
        }
    }
    return "";
}
std::string passiveEndings(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "r";
            case 2:
                return "ris";
            case 3:
                return "tur";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "mur";
            case 2:
                return "mini";
            case 3:
                return "ntur";
        }
    }
    return "";
}
std::string futurePassiveFirstSecondPresuffixes(bibliotheca::Number number, int person) {
    if (number == bibliotheca::Number::singular) {
        switch (person) {
            case 1:
                return "bo";
            case 2:
                return "be";
            case 3:
                return "bi";
        }
    }
    else if (number == bibliotheca::Number::plural) {
        switch (person) {
            case 1:
                return "bi";
            case 2:
                return "bi";
            case 3:
                return "bu";
        }
    }
    return "";
}
std::map<std::pair<bibliotheca::Case, bibliotheca::Number>, std::string> endings[5] = {
        //TODO: Macrons.
        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, "a"}, {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "am"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "ae"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "ae"}, {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "a"}, {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "ae"}, {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "as"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "arum"}, {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "is"}, {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "is"}},

        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, "us"}, {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "um"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "i"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "o"}, {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "o"}, {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "i"}, {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "os"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "orum"}, {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "is"}, {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "is"}},

        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, ""}, {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "em"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "is"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "i"}, {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "e"}, {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "es"}, {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "es"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "um"}, {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "ibus"}, {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "ibus"}},

        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, "us"}, {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "um"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "us"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "ui"}, {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "u"},//TODO: 4th dec neuter.
         {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "us"},
         {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "us"},
         {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "uum"},
         {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "ibus"},
         {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "ibus"}},

        {{{bibliotheca::Case::nom, bibliotheca::Number::singular}, "es"}, {{bibliotheca::Case::acc, bibliotheca::Number::singular}, "em"}, {{bibliotheca::Case::gen, bibliotheca::Number::singular}, "ei"}, {{bibliotheca::Case::dat, bibliotheca::Number::singular}, "ei"}, {{bibliotheca::Case::abl, bibliotheca::Number::singular}, "e"}, {{bibliotheca::Case::nom, bibliotheca::Number::plural}, "es"}, {{bibliotheca::Case::acc, bibliotheca::Number::plural}, "es"}, {{bibliotheca::Case::gen, bibliotheca::Number::plural}, "erum"}, {{bibliotheca::Case::dat, bibliotheca::Number::plural}, "ebus"}, {{bibliotheca::Case::abl, bibliotheca::Number::plural}, "ebus"}},
};

std::string bibliotheca::Noun::noun(bibliotheca::Case nounCase, bibliotheca::Number number) {
    if (nounCase == Case::nom && number == Number::singular) {
        return spelling[0];
    }
    if (gender == Gender::n && number == Number::plural &&
        (nounCase == Case::nom || nounCase == Case::acc || nounCase == Case::voc)) {
        return stem + "a";
    }
    if (gender == Gender::n && number == Number::singular && (nounCase == Case::acc || nounCase == Case::voc) &&
        declension == 3) {
        return spelling[0];
    }
    if (gender == Gender::n && number == Number::singular && (nounCase == Case::acc || nounCase == Case::voc)) {
        return stem + endings[declension - 1][{Case::acc, Number::singular}];
    }
    if (nounCase == Case::voc) {
        if (number == Number::plural) {
            return noun(Case::nom, Number::plural);
        }
        if (declension == 2 && spelling[0][spelling[0].size() - 3] == 'i' &&
            spelling[0][spelling[0].size() - 2] == 'u' && spelling[0][spelling[0].size() - 1] == 's') {
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
    return stem + endings[declension - 1][{nounCase, number}];
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
    return spelling[0] + ", " + spelling[1] + " (" + (gender == Gender::m ? "m" : gender == Gender::f ? "f"
                                                                                                      : "n") +
           ")";
}

bibliotheca::Noun::Noun(const std::string &_nomSing, const std::string &_genSing, bibliotheca::Gender _gender,
                        const bibliotheca::Translations &_english, int _declension) {
    spelling[0] = _nomSing;
    spelling[1] = _genSing;
    gender = _gender;
    english = _english;
    declension = _declension;
    stem = _genSing;
    stem.resize(stem.size() - endings[declension - 1][{Case::gen, Number::singular}].size());
}

bibliotheca::Verb::Verb(bibliotheca::PrincipalParts<4> principalParts, Translations _english) {
    deponent = false;
    english = _english;
    spelling = principalParts;
    char vowel = principalParts[1][principalParts[1].size() - 3];
    if (vowel == 'a') {
        conjugation = 1;
    }
    if (vowel == 'i') {
        conjugation = 4;
    }
    if (vowel == 'e') {
        if (principalParts[0][principalParts[0].size() - 2] == 'e') {
            conjugation = 2;
        }
        else {
            conjugation = 3;
        }
    }
}

std::string bibliotheca::Verb::getLatin() {
    return spelling[0] + ", " + spelling[1] + ", " + spelling[2] + ", " + spelling[3];
}

std::string bibliotheca::Verb::getEnglish() {
    std::string result;
    for (int i = 0; i < english.size() - 1; i++) {
        result += english[i];
        result += ", ";
    }
    return result + english[english.size() - 1];
}

bibliotheca::Verb::Verb(bibliotheca::PrincipalParts<3> principalParts, bibliotheca::Translations _english) {
    deponent = true;
    english = _english;
    spelling[0] = principalParts[0];
    spelling[1] = principalParts[1];
    spelling[2] = principalParts[2];
    spelling[3] = "";
    if (principalParts[1][principalParts[1].size() - 2] == 'r') {
        char vowel = principalParts[1][principalParts[1].size() - 3];
        switch (vowel) {
            case 'a':
                conjugation = 1;
                break;
            case 'e':
                conjugation = 2;
                break;
            case 'i':
                conjugation = 4;
                break;
        }
    }
    else {
        conjugation = 3;
    }
}

std::string
bibliotheca::Verb::participle(bibliotheca::Case participleCase, bibliotheca::Gender gender, bibliotheca::Number number,
                              bibliotheca::Mood mood, bibliotheca::Degree degree) {
    //TODO: Implement
    return "";
}

std::string
bibliotheca::Verb::verb(int person, bibliotheca::Number number, bibliotheca::Tense tense, bibliotheca::Mood mood,
                        bibliotheca::Voice voice) {
    if (deponent) {
        if (mood == Mood::indicative) {
            if (tense == Tense::pluperfect) {
                std::string stem = spelling[2];//TODO: Inflect for number and gender.
                stem.resize(stem.size() - 4);  //Remove " sum"
                if (number == Number::plural) {
                    stem.resize(stem.size() - 1);
                    stem[stem.size() - 1] = 'i';
                }
                return stem + " " + imperfectEsse(number, person);
            }
            else if (tense == Tense::perfect) {
                std::string stem = spelling[2];//TODO: Inflect for number and gender.
                stem.resize(stem.size() - 4);  //Remove " sum"
                if (number == Number::plural) {
                    stem.resize(stem.size() - 1);
                    stem[stem.size() - 1] = 'i';
                }
                return stem + " " + presentEsse(number, person);
            }
            else if (tense == Tense::imperfect) {
                std::string stem = spelling[1];
                if (conjugation == 3) {
                    stem[stem.size() - 1] = 'e';
                }
                else {
                    stem.resize(stem.size() - 2);
                }
                return stem + "ba" + passiveEndings(number, person);
            }
            else if (tense == Tense::present) {
                if (number == Number::singular && person == 1) {
                    return spelling[0];
                }
                else {
                    if (conjugation == 3) {
                        std::string stem = spelling[1];
                        stem.resize(stem.size() - 1);
                        if (number == Number::singular && person == 2) {
                            stem += "e";
                        }
                        else if (number == Number::plural && person == 3) {
                            stem += "u";
                        }
                        else {
                            stem += "i";
                        }
                        return stem + passiveEndings(number, person);
                    }
                    else {
                        std::string stem = spelling[1];
                        stem.resize(stem.size() - 2);
                        if (conjugation == 4 && person == 3 && number == Number::plural) {
                            stem = stem + "u";
                        }
                        return stem + passiveEndings(number, person);
                    }
                }
            }
            else if (tense == Tense::future) {
                if (conjugation < 3) {
                    std::string stem = spelling[1];
                    stem.resize(stem.size() - 2);
                    return stem + futurePassiveFirstSecondPresuffixes(number, person) + passiveEndings(number, person);
                }
                else {
                    std::string stem = spelling[1];
                    if (conjugation == 3) {
                        //stem.resize(stem.size() - 1);
                    }
                    else {
                        stem.resize(stem.size() - 2);
                    }
                    if (number == Number::singular && person == 1) {
                        stem += 'a';
                    }
                    else {
                        stem += 'e';
                    }
                    return stem + passiveEndings(number, person);
                }
            }
            else if (tense == Tense::futureperfect) {
                std::string stem = spelling[2];
                stem.resize(stem.size() - 4);
                if (number == Number::plural) {
                    stem.resize(stem.size() - 2);
                    stem += 'i';
                }
                return stem + " " + futureEsse(number, person);
            }
        }
        else if (mood == Mood::imperative) {
            if (conjugation == 3) {
                std::string result = spelling[1];
                result.resize(result.size() - 1);
                result += number == Number::singular ? "ere" : "imini";
                return result;
            }
            else {
                std::string result = spelling[1];
                result.resize(result.size() - 2);
                result += number == Number::singular ? "re" : "mini";
                return result;
            }
        }
        else if (mood == Mood::infinitive) {
            if (tense == Tense::present) {
                return spelling[1];
            }
            else if (tense == Tense::future) {
                std::string result = spelling[2];
                result.resize(result.size() - 5);
                result += "m iri";
                return result;
            }
            else if (tense == Tense::perfect) {
                std::string result = spelling[2];
                result.resize(result.size() - 3);
                result += "esse";
                return result;
            }
        }
        else if (mood == Mood::subjunctive) {
            if (tense == Tense::pluperfect) {
                std::string stem=spelling[2];
                stem.resize(stem.size()-4);
                if (number==Number::plural) {
                    stem.resize(stem.size()-2);
                    stem+="i";
                }
                return stem+" "+ imperfectSubjunctiveEsse(number,person);
            }
            else if (tense == Tense::perfect) {
                std::string stem=spelling[2];
                stem.resize(stem.size()-4);
                if (number==Number::plural) {
                    stem.resize(stem.size()-2);
                    stem+="i";
                }
                return stem+" "+ subjunctiveEsse(number,person);
            }
            else if (tense == Tense::imperfect) {
                std::string stem = spelling[1];
                if (conjugation==3) {
                    stem.resize(stem.size()-1);
                    stem+="ere";
                }
                else {
                    stem[stem.size()-1]='e';
                }
                return stem+ passiveEndings(number,person);
            }
            else if (tense == Tense::present) {
                std::string stem = spelling[1];
                if (conjugation==3) {
                    stem.resize(stem.size()-1);
                    stem+="ere";
                }
                else {
                    stem[stem.size()-1]='e';
                }
                if (conjugation==1) {
                    stem.resize(stem.size()-3);
                    stem+='e';
                }
                if (conjugation==2||conjugation==4) {
                    stem.resize(stem.size()-2);
                    stem+='a';
                }
                if (conjugation==3) {
                    stem.resize(stem.size()-3);
                    stem+='a';
                }
                return stem+ passiveEndings(number, person);
            }
        }
    }
    else {
        if (voice == Voice::active) {
            if (mood == Mood::indicative) {
                if (tense == Tense::pluperfect) {
                    std::string stem = spelling[2];
                    stem.resize(stem.size() - 1);
                    return stem + imperfectEsse(number, person);
                }
                else if (tense == Tense::perfect) {
                    std::string stem = spelling[2];
                    stem.resize(stem.size() - 1);
                    return stem + perfectEndings(number, person);
                }
                else if (tense == Tense::imperfect) {
                    std::string stem = spelling[1];
                    stem.resize(stem.size() - 2);
                    return stem + "ba" + standardVerbEndings(number, person, false);
                }
                else if (tense == Tense::present) {
                    if (number == Number::singular && person == 1) {
                        return spelling[0];
                    }
                    std::string stem = spelling[1];
                    stem.resize(stem.size() - 2);
                    if (conjugation == 3) {
                        stem.resize(stem.size() - 1);
                    }
                    if (conjugation == 3 && !(number == Number::plural && person == 3)) {
                        stem += "i";
                    }
                    if (conjugation == 4 && number == Number::plural && person == 3) {
                        stem = stem + "i";
                    }
                    return stem + standardVerbEndings(number, person, true);
                }
                else if (tense == Tense::future) {
                    std::string stem = spelling[1];
                    stem.resize(stem.size() - 2);
                    if (conjugation == 3) {
                        stem.resize(stem.size() - 1);
                    }
                    if (conjugation < 3) {
                        return stem + firstSecondFutureEndings(number, person);
                    }
                    else {
                        return stem + thirdFourthFutureEndings(number, person);
                    }
                }
                else if (tense == Tense::futureperfect) {
                    std::string stem = spelling[2];
                    stem.resize(stem.size() - 1);
                    return stem + futurePerfectEndings(number, person);
                }
            }
            else if (mood == Mood::imperative) {
                std::string result = spelling[1];
                result.resize(result.size() - 2);
                if (number == Number::plural) {
                    result = result + "te";
                    if (conjugation == 3) {
                        result[result.size() - 3] = 'i';
                    }
                }

                return result;
            }
            else if (mood == Mood::infinitive) {
                if (tense == Tense::present) {
                    return spelling[1];
                }
                else if (tense == Tense::future) {
                    std::string result = spelling[3];
                    result.resize(result.size() - 1);
                    result += "rus esse";
                    return result;
                }
                else if (tense == Tense::perfect) {
                    return spelling[2] + "sse";
                }
            }
            else if (mood == Mood::subjunctive) {
                if (tense == Tense::pluperfect) {
                    return spelling[2] + "sse" + standardVerbEndings(number, person, false);
                }
                else if (tense == Tense::perfect) {
                    std::string stem = spelling[2];
                    stem.resize(stem.size() - 1);
                    return stem + "eri" + standardVerbEndings(number, person, false);
                }
                else if (tense == Tense::imperfect) {
                    return spelling[1] + standardVerbEndings(number, person, false);
                }
                else if (tense == Tense::present) {
                    std::string stem = spelling[1];
                    if (conjugation==1) {
                        stem.resize(stem.size()-3);
                        stem+='e';
                    }
                    if (conjugation==2||conjugation==4) {
                        stem.resize(stem.size()-2);
                        stem+='a';
                    }
                    if (conjugation==3) {
                        stem.resize(stem.size()-3);
                        stem+='a';
                    }
                    return stem+ standardVerbEndings(number, person,false);
                }
            }
        }
        else if (voice == Voice::passive) {
            if (mood == Mood::indicative) {
                if (tense == Tense::pluperfect) {
                    std::string stem = spelling[3];//TODO: Inflect for number and gender.
                    if (number == Number::plural) {
                        stem.resize(stem.size() - 1);
                        stem[stem.size() - 1] = 'i';
                    }
                    return stem + " " + imperfectEsse(number, person);
                }
                else if (tense == Tense::perfect) {
                    std::string stem = spelling[3];//TODO: Inflect for number and gender.
                    if (number == Number::plural) {
                        stem.resize(stem.size() - 1);
                        stem[stem.size() - 1] = 'i';
                    }
                    return stem + " " + presentEsse(number, person);
                }
                else if (tense == Tense::imperfect) {
                    std::string stem = spelling[1];
                    stem.resize(stem.size() - 2);
                    return stem + "ba" + passiveEndings(number, person);
                }
                else if (tense == Tense::present) {
                    if (number == Number::singular && person == 1) {
                        return spelling[0] + "r";
                    }
                    else {
                        if (conjugation == 3) {
                            std::string stem = spelling[1];
                            stem.resize(stem.size() - 3);
                            if (number == Number::singular && person == 2) {
                                stem += "e";
                            }
                            else if (number == Number::plural && person == 3) {
                                stem += "u";
                            }
                            else {
                                stem += "i";
                            }
                            return stem + passiveEndings(number, person);
                        }
                        else {
                            std::string stem = spelling[1];
                            stem.resize(stem.size() - 2);
                            if (conjugation == 4 && person == 3 && number == Number::plural) {
                                stem = stem + "u";
                            }
                            return stem + passiveEndings(number, person);
                        }
                    }
                }
                else if (tense == Tense::future) {
                    if (conjugation < 3) {
                        std::string stem = spelling[1];
                        stem.resize(stem.size() - 2);
                        return stem + futurePassiveFirstSecondPresuffixes(number, person) + passiveEndings(number, person);
                    }
                    else {
                        std::string stem = spelling[1];
                        stem.resize(stem.size() - 2);
                        if (number == Number::singular && person == 1) {
                            if (conjugation==3) {
                                stem.resize(stem.size()-1);
                            }
                            stem += 'a';
                        }
                        else if (conjugation == 4) {
                            stem += 'e';
                        }
                        return stem + passiveEndings(number, person);
                    }
                }
                else if (tense == Tense::futureperfect) {
                    std::string stem = spelling[3];
                    if (number == Number::plural) {
                        stem.resize(stem.size() - 2);
                        stem += 'i';
                    }
                    return stem + " " + futureEsse(number, person);
                }
            }
            else if (mood == Mood::imperative) {
                if (number == Number::singular) {
                    return spelling[1];
                }
                else if (number == Number::plural) {
                    std::string result = spelling[1];
                    result.resize(result.size() - 2);
                    if (conjugation == 3) {
                        result[result.size() - 1] = 'i';
                    }
                    result += "mini";
                    return result;
                }
            }
            else if (mood == Mood::infinitive) {
                if (tense == Tense::present) {
                    if (conjugation == 3) {
                        std::string result = spelling[1];
                        result.resize(result.size() - 3);
                        result = result + 'i';
                        return result;
                    }
                    else {
                        std::string result = spelling[1];
                        result[result.size() - 1] = 'i';
                        return result;
                    }
                }
                else if (tense == Tense::future) {
                    std::string result = spelling[3];
                    result.resize(result.size() - 1);
                    result += "m iri";
                    return result;
                }
                else if (tense == Tense::perfect) {
                    return spelling[3] + " esse";
                }
            }
            else if (mood == Mood::subjunctive) {
                if (tense == Tense::pluperfect) {
                    std::string stem=spelling[3];
                    if (number==Number::plural) {
                        stem.resize(stem.size()-2);
                        stem+="i";
                    }
                    return stem+" "+ imperfectSubjunctiveEsse(number,person);
                }
                else if (tense == Tense::perfect) {
                    std::string stem=spelling[3];
                    if (number==Number::plural) {
                        stem.resize(stem.size()-2);
                        stem+="i";
                    }
                    return stem+" "+ subjunctiveEsse(number,person);
                }
                else if (tense == Tense::imperfect) {
                    return spelling[1]+ passiveEndings(number,person);
                }
                else if (tense == Tense::present) {
                    std::string stem = spelling[1];
                    if (conjugation==1) {
                        stem.resize(stem.size()-3);
                        stem+='e';
                    }
                    if (conjugation==2||conjugation==4) {
                        stem.resize(stem.size()-2);
                        stem+='a';
                    }
                    if (conjugation==3) {
                        stem.resize(stem.size()-3);
                        stem+='a';
                    }
                    return stem+ passiveEndings(number, person);
                }
            }
        }
    }
    return "";
}
