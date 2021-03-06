#include <bits/stdc++.h>
using namespace std;

string REGEX_ROUTE;
string INPUT;

vector<string> COLORS = {
    "#E74C3C",
    "#3498DB",
    "#D4AC0D",
    "#9B59B6",
    "#D35400",
    "#273746",
    "#D68910",
    "#1ABC9C",
    "#2ECC71",
    "#27AE60",
    "#C0392B",
    "#F39C12",
};

class RegularExpression{

    public:
        string regex;
        string type;
        string html_class;
        
        RegularExpression(string _regex, int _color_index){
            this->regex = _regex;
            this->html_class = "regex-" + to_string(_color_index); 
        }
    
        string getRegexLine(){
            return this->regex + " {fprintf(yyout, \"<span class=\'" + this->html_class + "\'>%s</span>\", yytext);}";
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
        if(line.size() > 0) {
            RegularExpression current_regex(line,color_index);
            output.push_back(current_regex); 
            color_index++;
        }
    
    }
    file.close();
    return output;
}

void buildHTML(){

    ofstream index("index.html");
    ifstream base_file("./core/base.html");
    ifstream inputHTML("./core/output.html");
    
    string input, line;
    getline(inputHTML, input);

    int line_num = 0;
    while(getline(base_file, line)){
        index << line << "\n";
        if(line.find("id=\"text-input\"") != string::npos){
            index << input << "\n"; 
        }
        line_num++;
    }

    index.close();
    base_file.close();
    inputHTML.close();

}

int main(int argc, char **argv){

    REGEX_ROUTE = argv[1];
    INPUT = argv[2];

    if(argc < 2){
        cout << "Provide 2 arguments (regex file followed by input file)" << endl;
        return 0;
    }
    
    vector<RegularExpression> regex_vector = getRegExpressions(REGEX_ROUTE);
    createLFile(regex_vector);
    system("flex core/lexic.l");
    system("gcc core/Scanner.c -o highlighter");
    system(string("highlighter " + INPUT).c_str());
    // Build index.html
    buildHTML();

    return 0;
}
