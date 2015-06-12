#include <iostream>
#include <fstream>
using namespace std;
int main(){
    //variables for input entries and ranking
    string year;
    string name;
    char gender;
    string ranking="";
    //prompting for variable values
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the Gender: ";
    cin >> gender;
    cout << "Enter the name: ";
    cin >> name;
    //creating the file name chosen
    string filename= "Babynameranking" + year+ ".txt";
    //checking for connection
    ifstream fin(filename, ios::in);
    if (fin.fail()){
        cout << "file does not exist." << endl;
        return 0;
    }
    //string to copy file lines
    string line;
    //bool for whether a name is found
    bool noname=1;
    //while loop to find line with name
    while (getline(fin,line)){
        if (line.find(name)!=std::string::npos){
            fin.seekg(0, ios::cur);
            //attempting to cycle through line string to copy over ranking
            int i=0;
            while (line[i]!=' '){//i is going up past 4000?
                ranking[i]+=line[i];//get bad access here
                i++;}
            noname=0;
        }
    }
           if (noname==1)
               cout<< "The name "<<name<< " is not found in the year " << year<< endl;
        
    
        
    
    
    cout << name << " is ranked #" << ranking << "in the year " << year <<endl;
    
    fin.close();
    
    return 0;
    
}