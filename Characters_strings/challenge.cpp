#include <iostream>
#include <string>
/*
Substitution Cipher

Ask the user to enter a secret message

Encrypt the message using substitution cipher
display the encrypted message



*/

using namespace std;

int main()
{
  string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

  string secret;
  cout << "Enter your secrete message: ";
  getline(cin, secret);

  cout << "Encrypting message..." << endl;
  string encrypt;
  for (auto letter : secret)
  {
    size_t position = alphabet.find(letter);
    if (position != string::npos)
    {
      string substitute = key.substr(position, 1);
      encrypt += substitute;
    }
    else
    {
      encrypt += letter;
    }
  }
  cout << "Encrypted message: " << encrypt << endl;

  cout << "Decrypting message ..." << endl;

  string decrypt;
  for (auto letter : encrypt)
  {
    size_t position = key.find(letter);
    if (position != string::npos)
    {
      string substitute = alphabet.substr(position, 1);
      decrypt += substitute;
    }
    else
    {
      decrypt += letter;
      ;
    }
  }
  cout << "Decrypted message: " << decrypt << endl;
  cout << endl;
  return 0;
}