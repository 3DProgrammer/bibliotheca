//
// Created by miles on 11/6/22.
//

#include <bibliotheca.h>
#include <map>
#include "word.h"
std::map<std::pair<bibliotheca::Case,bibliotheca::Number>,std::string> endings[5]={{
    {{bibliotheca::Case::nom, bibliotheca::Number::singular},"us"},{{bibliotheca::Case::acc, bibliotheca::Number::singular},"um"},{{bibliotheca::Case::gen, bibliotheca::Number::singular},"i"},{{bibliotheca::Case::dat, bibliotheca::Number::singular},"o"},{{bibliotheca::Case::abl, bibliotheca::Number::singular},"o"},
    {{bibliotheca::Case::nom, bibliotheca::Number::plural},"i"},{{bibliotheca::Case::acc, bibliotheca::Number::plural},"os"},{{bibliotheca::Case::gen, bibliotheca::Number::plural},"orum"},{{bibliotheca::Case::dat, bibliotheca::Number::plural},"is"},{{bibliotheca::Case::abl, bibliotheca::Number::plural},"is"}
}};

std::string bibliotheca::Noun::noun(bibliotheca::Case nounCase, bibliotheca::Number number) {
    if (nounCase==Case::nom && number==Number::singular) {
        return spelling[0];
    }
    if (gender==Gender::n&&number==Number::plural&&(nounCase==Case::nom||nounCase==Case::acc||nounCase==Case::voc)) {
        return stem+"a";
    }
    if (nounCase==Case::voc) {
        return noun(Case::nom, number); //TODO: Fix vocative case.
    }
    return stem+endings[declension][{nounCase,number}];
}
