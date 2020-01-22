#include <iostream>
using namespace std;

string createEncryption(string plainText, int key){
  for(int i = 0; i < plainText.size(); i++){
    if(plainText[i] == ' '){
      plainText[i] = plainText[i];
    }
    else if(plainText[i] + key > 'z'){
      plainText[i] = plainText[i] + key - 26;
    }
    else{
      plainText[i] = plainText[i] + key;
    }
  }
  return plainText;
}

string createDecryption(string cipherText, int key){
  for(int i = 0; i < cipherText.size(); i++){
    if(cipherText[i] == ' '){
      cipherText[i] = cipherText[i];
    }
    else if(cipherText[i] - key < 'a'){
      cipherText[i] = cipherText[i] - key + 26;
    }
    else{
      cipherText[i] = cipherText[i] - key;
    }
  }
  return cipherText;
}

int main(){
    while(true){
      cout<<"encrypt(e) or decrypt(d) or quit(q)? ";
      string choice; cin>>choice;
      if(choice == "q")
        return 0;
      if(choice != "e" && choice != "d"){
        bool correct = false;
        while(correct == false){
          cout<<"please enter either 'e' or 'd' or 'q': ";
          cin>>choice;
          if(choice == "q")
            return 0;
          if(choice == "d" || choice == "e"){
            correct = true;
          }
        }
      }

      if(choice == "e"){
        cout<<"enter string to encrypt: ";
        string encryption; getline(cin, encryption); getline(cin, encryption);
        cout<<"enter key: ";
        int key; cin>>key;
        string cipherText = createEncryption(encryption, key);
        cout<<cipherText<<endl;
      }

      if(choice == "d"){
        cout<<"enter string to decrypt: ";
        string cipherText; getline(cin, cipherText); getline(cin, cipherText);
        cout<<"enter key: ";
        int key; cin>>key;
        string plainText = createDecryption(cipherText, key);
        cout<<plainText<<endl;
      }
    }

    return 0;
}
