#include "cipherSolver.h"
#include<iostream>
using namespace std;

int main(){
    string cipherText = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi\n"
        "bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx\n"
        "ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr\n"
        "yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk\n"
        "lmird jk xjubt trmui jx ibndt\n\n"
        "wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi\n"
        "iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m\n"
        "vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd\n"
        "wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr\n"
        "jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii\n"
        "ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh\n"
        "mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb\n"
        "bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd\n"
        "wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr\n"
        "riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb";

        cipherSolver solver(cipherText);
        solver.calcFreq();
        solver.printcomparisonTable();

        cout << "bpr -> the\n";
        solver.setSubs('b', 't');
        solver.setSubs('p', 'h');
        solver.setSubs('r', 'e');

        //hypothesis one
        // solver.setSubs('w', 'a'); w is alone a lot, a is a word of one letter FAILED
        solver.setSubs('i', 's'); //s is a common letter after a, wi are together, could be "as"
        //hypthesis worked so far
        //hypothesis two
        solver.setSubs('j', 'o'); //j is next to t a lot, common word is "to"
        //hypothesis worked so far
        //hypothesis three
        solver.setSubs('x', 'f'); //x is next to o a lot, common word is "of"
        //hypothesis worked so far
        //hypothesis four
        solver.setSubs('k', 'n'); //k is next to ot making me think of the word "not"
        // solver.setSubs('m', 'i'); if we assume k is n, since m is next to k, mk can be "in" FAILED
        // m is not i, there is no word that has 3 letters and the first two are in

        //hypothesis five: m is next to n in mkd, we know k is n, so mkd can be "one" meaning m is o, d is e
        // solver.setSubs('m', 'o'); FAILED!
        // solver.setSubs('d', 'e'); FAILED!
        // m can not be o because j is o , d is not e, r is e
        //hypothesis succesful, we have "one" in the text and more coherent clues of possible words
        //hypothesis six: y is next to t, possoble word "it", so y is i
        // solver.setSubs('y', 'i'); Failed
        //hypothersis seven: i have found the almsot decoded text "itsehf", if we are to 
        //assume all the letters previously decoded are correct, then h is l, so "itself" is the decoded text
        solver.setSubs('h', 'l');
        //w can not be a because it creates nonsense words like 'ats" and then words like "thmt" can not be 
        //"that" since w would be a, this means m is a
        solver.setSubs('m', 'a');
        //better coherent words discovered, "qata" could be "data" so q is d
        //solver.setSubs('q', 'd'); FAILED
        //"offeu" could be offer, so u is r
        solver.setSubs('u', 'r');
        //Failed! y is not i, it creates mixups, found "theorwes" which sounds like
        //"theories" so w is i
        solver.setSubs('w', 'i');
        // found a readable sentance: "i shall trt" which i assume is "i shall try" so t is y
        solver.setSubs('t', 'y');
        //found yy, it t is y, yt could be "my" so y is m
        solver.setSubs('y', 'm');
        //found "eavh" which could be "each" so v is c
        //found "stndy" which could be "study" so n is u
        //found "tasd" which means q is not d, so q is k
        solver.setSubs('v', 'c');
        solver.setSubs('n', 'u');
        solver.setSubs('q', 'k');
        //found "sionificance" which could be "significance" so o is g
        solver.setSubs('o', 'g');
        // "wkiswurd" is decoded to inssired which could be "inspired" so s is p
        solver.setSubs('s', 'p');
        //that lead to "rashmwk" being eaplain, which could be "explain" so a is x
        solver.setSubs('a', 'x');
        //i found "lut" and "lecause" which could be "but" and "because" so l is b
        solver.setSubs('l', 'b');
        //found moeement" twice so its "movement" so e is v
        //found "cith" and "cill" since our decoded letters are so far correct
        //i can assume "cith" is "with" and "cill" is "will" so c is w
        solver.setSubs('e', 'v');
        solver.setSubs('c', 'w');
        //found "fualified" which could be "qualified" so f is q
        solver.setSubs('f', 'q');


        solver.printdecodedText();
    return 0;
}