#include <bibliotheca.h>
#include <iostream>
#include <map>

void displayVerb(bibliotheca::Mood mood, bibliotheca::Voice voice, bibliotheca::Tense tense, const std::string &starter, const std::string &indent, bibliotheca::Verb &verb) {
    std::cout << starter << "Singular:" << std::endl;
    std::cout << starter << indent << "1st: " << verb.verb(1, bibliotheca::Number::singular, tense, mood, voice)<<std::endl;
    std::cout << starter << indent << "2nd: " << verb.verb(2, bibliotheca::Number::singular, tense, mood, voice)<<std::endl;
    std::cout << starter << indent << "3rd: " << verb.verb(3, bibliotheca::Number::singular, tense, mood, voice)<<std::endl;
    std::cout << starter << "Plural:" << std::endl;
    std::cout << starter << indent << "1st: " << verb.verb(1, bibliotheca::Number::plural, tense, mood, voice)<<std::endl;
    std::cout << starter << indent << "2nd: " << verb.verb(2, bibliotheca::Number::plural, tense, mood, voice)<<std::endl;
    std::cout << starter << indent << "3rd: " << verb.verb(3, bibliotheca::Number::plural, tense, mood, voice)<<std::endl;
}
int main() {
    std::map<bibliotheca::Case, std::string> cases = {{bibliotheca::Case::nom, "nominative"},
                                                      {bibliotheca::Case::acc, "accusative"},
                                                      {bibliotheca::Case::gen, "genitive"},
                                                      {bibliotheca::Case::dat, "dative"},
                                                      {bibliotheca::Case::abl, "ablative"},
                                                      {bibliotheca::Case::voc, "vocative"}};
    std::map<bibliotheca::Number, std::string> numbers = {{bibliotheca::Number::singular, "singular"},
                                                          {bibliotheca::Number::plural, "plural"}};
    std::cout << "Testing bibliotheca..." << std::endl;
    //    std::vector<bibliotheca::Noun> nouns;
    //    nouns.push_back(bibliotheca::Noun("bibliotheca", "bibliothecae", bibliotheca::Gender::f, {"library"}, 1));
    //    nouns.push_back(bibliotheca::Noun("Quintus", "Quinti", bibliotheca::Gender::m, {"Quintus"}, 2));
    //    nouns.push_back(bibliotheca::Noun("Caecilius", "Caecili", bibliotheca::Gender::m, {"Caecilius"}, 2));
    //    nouns.push_back(bibliotheca::Noun("templum", "templi", bibliotheca::Gender::n, {"temple"}, 2));
    //    nouns.push_back(
    //            bibliotheca::Noun("imperator", "imperatoris", bibliotheca::Gender::m, {"emperor", "general", "commander"},
    //                              3));
    //    nouns.push_back(bibliotheca::Noun("corpus", "corporis", bibliotheca::Gender::n, {"body", "corpse"}, 3));
    //    nouns.push_back(bibliotheca::Noun("manus", "manus", bibliotheca::Gender::f, {"hand"}, 4));
    //    nouns.push_back(bibliotheca::Noun("dies", "diei", bibliotheca::Gender::m, {"day"}, 5));
    //
    //    for (int i = 0; i < 250; i++) {
    //        auto casesIterator = cases.begin();
    //        std::advance(casesIterator, rand() % cases.size());
    //        bibliotheca::Case aCase = casesIterator->first;
    //        auto numberIterator = numbers.begin();
    //        std::advance(numberIterator, rand() % numbers.size());
    //        bibliotheca::Number aNumber = numberIterator->first;
    //        bibliotheca::Noun word = nouns[rand() % nouns.size()];
    //        std::cout << word.getEnglish() << " in the " << cases[aCase] << " " << numbers[aNumber] << ": "
    //                  << word.noun(aCase, aNumber) << std::endl;
    //    }
    std::vector<bibliotheca::Verb> verbs;
    verbs.push_back(bibliotheca::Verb({"ambulo", "ambulare", "ambulavi", "ambulatus"}, {"walk"}));
    verbs.push_back(bibliotheca::Verb({"habeo", "habere", "habui", "habitum"}, {"have", "own"}));
    verbs.push_back(bibliotheca::Verb({"cognosco", "cognoscere", "cognovi", "cognitus"}, {"know", "understand"}));
    verbs.push_back(bibliotheca::Verb({"audio", "audire", "audivi", "auditus"}, {"hear"}));
    verbs.push_back(bibliotheca::Verb(std::array<std::string, 3>({"ingredior", "ingredi", "ingressus sum"}), {"enter"}));
    verbs.push_back(bibliotheca::Verb(std::array<std::string, 3>({"miror", "mirari", "miratus sum"}), {"admire"}));
    verbs.push_back(bibliotheca::Verb(std::array<std::string, 3>({"vereor", "vereri", "veritus sum"}), {"fear"}));
    verbs.push_back(bibliotheca::Verb(std::array<std::string, 3>({"partior", "partiri", "partitus sum"}), {"share"}));
    for (auto verb: verbs) {
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << verb.getLatin() << " is conjugation " << verb.conjugation << std::endl;
        std::cout << "Imperative:" << std::endl;
        std::cout << " Active:" << std::endl;
        std::cout << "  Singular: " << verb.verb(1, bibliotheca::Number::singular, bibliotheca::Tense::present, bibliotheca::Mood::imperative, bibliotheca::Voice::active) << std::endl;
        std::cout << "  Plural: " << verb.verb(1, bibliotheca::Number::plural, bibliotheca::Tense::present, bibliotheca::Mood::imperative, bibliotheca::Voice::active) << std::endl;
        std::cout << " Passive:" << std::endl;
        std::cout << "  Singular: " << verb.verb(1, bibliotheca::Number::singular, bibliotheca::Tense::present, bibliotheca::Mood::imperative, bibliotheca::Voice::passive) << std::endl;
        std::cout << "  Plural: " << verb.verb(1, bibliotheca::Number::plural, bibliotheca::Tense::present, bibliotheca::Mood::imperative, bibliotheca::Voice::passive) << std::endl;
        std::cout << "Infinitive:" << std::endl;
        std::cout << " Active:" << std::endl;
        std::cout << "  Present: " << verb.verb(1, bibliotheca::Number::singular, bibliotheca::Tense::present, bibliotheca::Mood::infinitive, bibliotheca::Voice::active) << std::endl;
        std::cout << "  Future: " << verb.verb(1, bibliotheca::Number::singular, bibliotheca::Tense::future, bibliotheca::Mood::infinitive, bibliotheca::Voice::active) << std::endl;
        std::cout << "  Perfect: " << verb.verb(1, bibliotheca::Number::singular, bibliotheca::Tense::perfect, bibliotheca::Mood::infinitive, bibliotheca::Voice::active) << std::endl;
        std::cout << " Passive:" << std::endl;
        std::cout << "  Present: " << verb.verb(1, bibliotheca::Number::singular, bibliotheca::Tense::present, bibliotheca::Mood::infinitive, bibliotheca::Voice::passive) << std::endl;
        std::cout << "  Future: " << verb.verb(1, bibliotheca::Number::singular, bibliotheca::Tense::future, bibliotheca::Mood::infinitive, bibliotheca::Voice::passive) << std::endl;
        std::cout << "  Perfect: " << verb.verb(1, bibliotheca::Number::singular, bibliotheca::Tense::perfect, bibliotheca::Mood::infinitive, bibliotheca::Voice::passive) << std::endl;
        std::cout << "Indicative:" << std::endl;
        std::cout << " Active:" << std::endl;
        std::cout << "  Pluperfect:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::active, bibliotheca::Tense::pluperfect, "   ", " ", verb);
        std::cout << "  Perfect:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::active, bibliotheca::Tense::perfect, "   ", " ", verb);
        std::cout << "  Imperfect:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::active, bibliotheca::Tense::imperfect, "   ", " ", verb);
        std::cout << "  Present:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::active, bibliotheca::Tense::present, "   ", " ", verb);
        std::cout << "  Future:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::active, bibliotheca::Tense::future, "   ", " ", verb);
        std::cout << "  Future perfect:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::active, bibliotheca::Tense::futureperfect, "   ", " ", verb);
        std::cout << " Passive:" << std::endl;
        std::cout << "  Pluperfect:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::passive, bibliotheca::Tense::pluperfect, "   ", " ", verb);
        std::cout << "  Perfect:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::passive, bibliotheca::Tense::perfect, "   ", " ", verb);
        std::cout << "  Imperfect:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::passive, bibliotheca::Tense::imperfect, "   ", " ", verb);
        std::cout << "  Present:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::passive, bibliotheca::Tense::present, "   ", " ", verb);
        std::cout << "  Future:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::passive, bibliotheca::Tense::future, "   ", " ", verb);
        std::cout << "  Future perfect:" << std::endl;
        displayVerb(bibliotheca::Mood::indicative, bibliotheca::Voice::passive, bibliotheca::Tense::futureperfect, "   ", " ", verb);
        std::cout << "Subjunctive:" << std::endl;
        std::cout << " Active:" << std::endl;
        std::cout << "  Pluperfect:" << std::endl;
        displayVerb(bibliotheca::Mood::subjunctive, bibliotheca::Voice::active, bibliotheca::Tense::pluperfect, "   ", " ", verb);
        std::cout << "  Perfect:" << std::endl;
        displayVerb(bibliotheca::Mood::subjunctive, bibliotheca::Voice::active, bibliotheca::Tense::perfect, "   ", " ", verb);
        std::cout << "  Imperfect:" << std::endl;
        displayVerb(bibliotheca::Mood::subjunctive, bibliotheca::Voice::active, bibliotheca::Tense::imperfect, "   ", " ", verb);
        std::cout << "  Present:" << std::endl;
        displayVerb(bibliotheca::Mood::subjunctive, bibliotheca::Voice::active, bibliotheca::Tense::present, "   ", " ", verb);
        std::cout << " Passive:" << std::endl;
        std::cout << "  Pluperfect:" << std::endl;
        displayVerb(bibliotheca::Mood::subjunctive, bibliotheca::Voice::passive, bibliotheca::Tense::pluperfect, "   ", " ", verb);
        std::cout << "  Perfect:" << std::endl;
        displayVerb(bibliotheca::Mood::subjunctive, bibliotheca::Voice::passive, bibliotheca::Tense::perfect, "   ", " ", verb);
        std::cout << "  Imperfect:" << std::endl;
        displayVerb(bibliotheca::Mood::subjunctive, bibliotheca::Voice::passive, bibliotheca::Tense::imperfect, "   ", " ", verb);
        std::cout << "  Present:" << std::endl;
        displayVerb(bibliotheca::Mood::subjunctive, bibliotheca::Voice::passive, bibliotheca::Tense::present, "   ", " ", verb);
    }
}