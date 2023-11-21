#include <iostream>
#include <string_view>
#include <string>
#include <regex>

using std::cout;
using std::endl;
using std::string_view;
using std::string;

using namespace std::string_literals;
using namespace std::string_view_literals;

//Utilisation de regex_match
bool isEmailValid(const std::string& email) {
    // Expression régulière pour vérifier une adresse e-mail
    const std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailRegex);
}

//Utilisation de regex_replace
void replaceText(string &chaine, const string &chaine_a_trouver, const string &remplacement){
    std::regex pattern{chaine_a_trouver};
    chaine = std::regex_replace(chaine, pattern, remplacement);
}

//Utilisation de regex_search
string findNumbers(string &chaine){

    //Expression régulière cherchant des caractères numériques
    std::regex pattern("\\d+");
    std::smatch match;
    if(std::regex_search(chaine, match, pattern)) {
        return match.str();
    } else {
        cout<<"Aucune correspondance trouvee"<<endl;
    }
    return "";
}


int main() {

    string s{"lucky.luke@daltons.org"};

    if(isEmailValid(s)){
        cout<<"Matched"<<endl;
    } else {
        cout<<"Not matched"<<endl;
    }

    replaceText(s, ".org", ".com");
    cout<<s<<endl;

    string phrase{"Mon numero de telephone est 0607080910. Je compte sur vous pour le garder."s};
    cout<<findNumbers(phrase)<<endl;

    return 0;
}
