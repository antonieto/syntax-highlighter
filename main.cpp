#include <bits/stdc++.h>
using namespace std;

vector<string> COLORS = {
    "red",
    "blue",
    "lightblue",
    "purple",
    "navy",
    "darkolivegreen",
    "orange",
    "green",
    "skyblue",
    "teal",
    "tomato",
    "violet"
};

void createLFile(vector<RegularExpression> reg_expressions){
    int lineNum = 0;
    
    ifstream baseFile("./core/base.l");
    ofstream targetFile("./core/lexic.l");
    string reading_file;
    while(getline(baseFile, reading_file)){
        
        if(lineNum <= 7){
            targetFile << line;
        } else {
            
            for(int i = 0; i < reg_expressions; i++){
                targetFile << regex_vector[i].getRegexLine() << "\n"; 
            }
            
        } 

    }
}

class RegularExpression{

    public:
        string regex;
        string type;
        string color;
        
        RegularExpression(string _regex, string _type){
            this->regex = _regex;
            this->type = _type; 
        }

        RegularExpression(string _regex, string _type, int _color_index){
            this->regex = _regex;
            this->type = _type;
            this->color = COLORS[_color_index]; 
        }

        string getRegexLine(){
            return this->regex + " {fprintf(yyout, \"<span style=\"color: " + this->color + ";\">%s</span>\", yytext)}";
        }


};
vector<RegularExpression> getRegExpressions(string source_path) {
    
    vector<RegularExpression> output; 
    
    ifstream file(source_path);
    string line, regex, type;
    int color_index = 0;
    while(getline(file, line)){
        stringstream ss(line);
        getline(ss, regex, ' ');
        getline(ss, type, ' ');
        cout<<regex<<" "<<type<<endl;
        RegularExpression current_regex(regex,type,color_index);
        output.push_back(current_regex); 
        color_index++;
    }
    file.close();
    return output;
}


int main(int argc, char **argv){

    // if(argc < 2){
    //     cout << "File names required" << endl;
    //     return 0;
    // }
    
    string regex_route = "regex.txt"; 
    
    vector<RegularExpression> regex_vector = getRegExpressions(regex_route);

    for(int i = 0; i < regex_vector.size() ; i++) {
        
        cout << regex_vector[i].getRegexLine() << endl;
    }


    return 0;
}
