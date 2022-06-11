#include <bibliotheca.h>
#include <iostream>
#include <map>



int main() {
    std::map<bibliotheca::Case, std::string> cases ={{bibliotheca::Case::nom, "nominative"}, {bibliotheca::Case::acc, "accusative"},
                                                     {bibliotheca::Case::gen, "genitive"}, {bibliotheca::Case::dat, "dative"},
                                                     {bibliotheca::Case::abl, "ablative"}, {bibliotheca::Case::voc, "vocative"}};
    std::map<bibliotheca::Number, std::string> numbers={{bibliotheca::Number::singular, "singular"},{bibliotheca::Number::plural, "plural"}};
    std::cout<<"Testing bibliotheca..."<<std::endl;
    std::vector<bibliotheca::Noun> nouns;
    nouns.push_back(bibliotheca::Noun("bibliotheca", "bibliothecae", bibliotheca::Gender::f, {"library"}, 1));
    nouns.push_back(bibliotheca::Noun("Quintus", "Quinti", bibliotheca::Gender::m, {"Quintus"}, 2));
    for (int i=0; i<100; i++) {
        auto casesIterator=cases.begin();
        std::advance(casesIterator, rand()%cases.size());
        bibliotheca::Case aCase = casesIterator->first;
        auto numberIterator=numbers.begin();
        std::advance(numberIterator, rand()%numbers.size());
        bibliotheca::Number aNumber = numberIterator->first;
        bibliotheca::Noun word=nouns[rand()%nouns.size()];
        std::cout<<word.getEnglish()<<" in the "<<cases[aCase]<<" "<<numbers[aNumber]<<": "<<word.noun(aCase, aNumber)<<std::endl;
    }
}