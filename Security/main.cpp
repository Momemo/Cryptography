//  < Cryptography Security >

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>


using namespace std;

void validate();  // validates input and call corresponding function according to user choice
void encrypting(int,string); // encrypts the user message according to the key
void decryption(int,string); // decrypts the user message according to the key
int main()
{
    cout<<"Welcome to Cryptography"<<endl << endl;
    validate(); //Function call for validation
    return 0;
}
//*********************************************************************************************
// This function validates user input and calls corresponding function according to user choice
//
//This function doesn't return anything but calls functions.
//*********************************************************************************************
void validate(){
    int key;
    string userChoice;
    string userMessage;
    while (userChoice != "exit"){
        cout << "What would you like to do to a message? (encrypt, decrypt, exit)" << endl;
        cout << "Enter your choice: ";
        cin>>userChoice;
        
        while(userChoice != "encrypt" && userChoice != "decrypt" && userChoice != "exit"){
            cout<<"Invalid message"<< endl << endl;
            cout<<"What would you like to do to a message? (encrypt, decrypt, exit) "<<endl;
            cout<<"Enter your choice: ";
            cin>>userChoice;
        }
        
        if (userChoice == "exit"){ //Action to take if user chooses to exit
            cout << endl;
            cout << "Mohammad Security Systems"<<endl;
            exit(0);
        }
        cin.ignore();
        
        cout << "Enter your Message: "<<endl;//Asking for input for the message
        getline(cin,userMessage);
        cout<<"Enter the key number (1-35)\n";//Asking for key value
        cin>>key;
        
        while (key <= 0 || key > 35){//Checks if the input for the key is correct
            cout << endl << "Invalid Key number" << endl << endl;
            cout << "What would you like to do to a message? (encrypt, decrypt, exit) \n"
            << "Enter your choice: ";
            cin >> userChoice;
            
            if (userChoice == "exit"){//Action to be taken if user chooses to exit
                cout << endl;
                cout << "Mohammad  Security Systems"<<endl;
                cout <<"2-25-2019"<<endl;
                exit(0);
            }
            cin.ignore ();
            
            cout << "Enter your Message: "<<endl;//Asking for user message
            getline(cin,userMessage);
            cout<<"Enter the key number (1-35)\n ";//Asking for key value
            cin>>key;
        }
        
        if(userChoice == "encrypt"){//Calls encrypting function if user chooses to encrypt
            encrypting(key,userMessage);//Function call for encrypting and sending two parameters
        }
        
        else if(userChoice == "decrypt"){//Calls decryption function if user chooses to decrypt
            decryption(key,userMessage);//Function call for decryption and sending two parameters
        }
    }
}
//*********************************************************************************************
// This function encrypts the user message according to the key
//
// param-1- int key, the value the user wants to encrypt their message by
// param-2- string userMessage, the message the user wants to encrypt
//*********************************************************************************************
void encrypting(int key, string userMessage){
    int count = 0;//Integer variable for count which will be used as a iterator
    
    vector <char> alphaNum;// Creating a vector
    for (int i =0; i < 26; i++) {
        alphaNum.push_back('A' +i);//Filling the vector with the alphabet
    }
    
    for  (int j=0; j<10; j++){
        alphaNum.push_back('0' +j);//Filling the rest of the vector with numbers
    }
    
    vector<vector<char> > shiftedAlphaNum(2,alphaNum);
    
    for (int i = 0; i < userMessage.size(); i++){//Turns user input to upper case letters
        userMessage[i] = toupper(userMessage[i]);
    }
    
    for (int i = 1; i <= 1; i++){
        for (int j = 0; j < 36-key; j++){
            shiftedAlphaNum[i][j] = shiftedAlphaNum[i][j+key];
            count++;
            
            if (shiftedAlphaNum[i][j] > '9' && shiftedAlphaNum[i][j] < 'A')
                shiftedAlphaNum[i][j] +=7;
            
            else if(shiftedAlphaNum[i][j] > 'Z')
                shiftedAlphaNum[i][j] = shiftedAlphaNum[i][j] -43;
            
            if (count == 36-key){
                int keyToEnd=0;//Counts from key to end of the vector
                while (keyToEnd<key)
                    for (int k=36-key; k < 36; k++){
                        shiftedAlphaNum[i][k] = 'A'+keyToEnd;
                        keyToEnd++;
                        
                        if (shiftedAlphaNum[i][k] > '9' && shiftedAlphaNum[i][k] < 'A')
                            shiftedAlphaNum[i][k] +=7;
                        
                        else if(shiftedAlphaNum[i][k] > 'Z')
                            shiftedAlphaNum[i][k] = shiftedAlphaNum[i][k] -43;
                        
              }
            }
        }
    }
    
    cout << "Your translated text is:" << endl;
    
    
    for(int i = 0; i < userMessage.size(); i++){
        for(int j=0; j < alphaNum.size(); j++){
            
            if(userMessage[i] == alphaNum[j])
                cout << shiftedAlphaNum[1][j];
            }
        if (userMessage[i] == ' '){
            cout << " ";
        }
        
    }
    cout << endl << endl;
}
//*********************************************************************************************
// This function decrypts the user message according to the key
//
// param-1- int key, the value the user wants to decrypt their message by
// param-2- string userMessage, the message the user wants to decrypt
//*********************************************************************************************
void decryption(int key, string userMessage){
    int count = 0;//Integer variable for count which will be used as a iterator
    
    vector <char> alphaNum;// Creating a vector
    for (int i =0; i < 26; i++) {
        alphaNum.push_back('A' +i);//Filling the vector with the alphabet
    }
    
    for  (int j=0; j<10; j++){
        alphaNum.push_back('0' +j);//Filling the rest of the vector with numbers
    }
    
    vector<vector<char> > shiftedAlphaNum(2,alphaNum);
    
    for (int i = 0; i < userMessage.size(); i++){
        userMessage[i] = toupper(userMessage[i]);
    }
    
    for (int i = 1; i <= 1; i++){
        
        for (int j = 0; j < 36-key; j++){
            shiftedAlphaNum[i][j] = shiftedAlphaNum[i][j+key];
            count++;
            
            if (shiftedAlphaNum[i][j] > '9' && shiftedAlphaNum[i][j] < 'A')
                shiftedAlphaNum[i][j] +=7;
            
            else if(shiftedAlphaNum[i][j] > 'Z')
                shiftedAlphaNum[i][j] = shiftedAlphaNum[i][j] -43;
            if (count == 36-key){
                int keyToEnd=0;//Counts from key to end of the vector
                while (keyToEnd<key)
                    for (int k=36-key; k < 36; k++){
                        shiftedAlphaNum[i][k] = 'A'+keyToEnd;
                        keyToEnd++;
                        if (shiftedAlphaNum[i][k] > '9' && shiftedAlphaNum[i][k] < 'A')
                            shiftedAlphaNum[i][k] +=7;
                        
                        else if(shiftedAlphaNum[i][k] > 'Z')
                            shiftedAlphaNum[i][k] = shiftedAlphaNum[i][k] -43;
                        
                    }
            }
        }
    }
    
    cout << "Your translated text is:" << endl;
    
    for(int i = 0; i < userMessage.size(); i++){//Prints the encrypted text out to screen
        for(int j=0; j < alphaNum.size(); j++){
            
            if(userMessage[i] == shiftedAlphaNum[1][j])
                cout << shiftedAlphaNum[0][j];
        }
        if (userMessage[i] == ' '){
            cout << " ";
        }
        
    }
    cout << endl;
    
}

