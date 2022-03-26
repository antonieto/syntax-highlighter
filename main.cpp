#include <bits/stdc++.h>
using namespace std;

void create_l_file(vector<string> reg_expressions) {
    return;
}

class RegularExpression{

    public:
        string regex;
        string type;
        int color;
        
        RegularExpression(string _regex, string _type){
            this->regex = _regex;
            this->type = _type; 
        }

        RegularExpression(string _regex, string _type, int _color_index){
            this->regex = _regex;
            this->type = _type;
            this->color = _color_index; 
        }

        // Constructor from line
        // RegularExpression(string line, int _vector_index){
        //     // Split line in segments
        //     vector<string> segments;

        //     string current_string = "";
        //     for(int i = 0; i < line.size(); i++) {

        //         if(line[i] == ' ' && current_string.size() > 0 ){
                
        //             segments.push_back(current_string);
        //             current_string = "";

        //         } else {
        //             current_string = current_string + line[i];
        //         }
        //     }

        //     segments.push_back(current_string);

        //     // Segments vector has been constructed 
        //     if(segments.size() != 2){
        //         cout << segments.size() << endl;
        //         throw invalid_argument("Line must contain two strings");
        //         return;
        //     }
        //     // cout << "segment 0 " << segments[0] << " "  << " segment 1 " << segments[1] << endl;
        //     this->regex = segments[0];
        //     this->type = segments[1];


        // }

        string getRegexLine(){
            
            string output("", 50);

            output = this->regex;
            output = output + " {fprintf(yyout, <span class='";
            output = output + this->type;
            output = output + "mamda";
            

            // output = format("{} {fprintf(yyou, <span class=\"{}\">%s</span>)}"), this->regex, this->type)

            return output;
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
