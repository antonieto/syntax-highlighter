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
    "violet",
};

class RegularExpression{

    public:
        string regex;
        string type;
        string color;
        
        RegularExpression(string _regex, int _color_index){
            this->regex = _regex;
            this->color = COLORS[_color_index]; 
        }
    
        string getRegexLine(){
            return this->regex + " {fprintf(yyout, \"<span style=\'color: " + this->color + ";\'>%s</span>\", yytext);}";
        }
};

void createLFile(vector<RegularExpression> reg_expressions){
    int lineNum = 0;
    
    ifstream baseFile("./core/base.l");
    ofstream targetFile("./core/lexic.l");
    string reading_l;
    bool flag = false;
    while(getline(baseFile, reading_l)){
        
        targetFile << reading_l << "\n";

        if(lineNum == 7){
            cout << "in" <<endl;
            for(int i = 0; i < reg_expressions.size(); i++){
                targetFile << reg_expressions[i].getRegexLine() << "\n"; 
            } 
        }
        
        lineNum++;
    }
}

vector<RegularExpression> getRegExpressions(string source_path) {
    
    vector<RegularExpression> output; 
    
    ifstream file(source_path);
    string line, regex, type;
    int color_index = 0;
    while(getline(file, line)){
        // stringstream ss(line);
        // getline(ss, regex, ' ');
        // getline(ss, type, ' ');
        RegularExpression current_regex(line,color_index);
        output.push_back(current_regex); 
        color_index++;
    }
    file.close();
    return output;
}

    


int main(){

    // if(argc < 2){
    //     cout << "File names required" << endl;
    //     return 0;
    // }
    
    string regex_route = "regex.txt"; 
    
    vector<RegularExpression> regex_vector = getRegExpressions(regex_route);
    // cout << regex_vector.size()<< endl;
    createLFile(regex_vector);
    
    system("flex core/lexic.l");
    system("gcc core/Scanner.c -o highlighter");

    return 0;
}
