#include "Person.hpp"
#include "Librarian.hpp"
#include "User.hpp"
#include <iostream>
#include <fstream>
class person_factory{

public:
Person* begin(fstream& f, const string& filename){
  Person* me = nullptr;
  bool admin = false;
  string name, ans, pass;
  int tries = 3;
  pass = " ";
  cout << "Welcome to our Library System!" << endl;
  cout << "Are you a new user? (Y/N)" << endl;
  cin >> ans;
  cin.ignore();

  if(ans == "Y" ||  ans == "y" || ans == "YES" || ans == "Yes"){

    cout << "Enter your full name with first and last seperated by a space: ";
    getline(cin, name);
    cout << "Enter a password: ";
    getline(cin, pass);
    f << "#" << name << "|" << pass << endl;

  }

  else{

    string corrPass = "";
    cout << "Enter your name: " << endl;
    getline(cin, name, '\n');

    while(!corr_name(f, filename, name, corrPass, admin) && tries > 0){

      --tries;
      cout << "No users found! " << tries << " attempts remaining!" << endl;

      if(tries == 0){

        cout << "Too many attempts! Exiting..." << endl;
        exit(1);

      }

      cout << "Enter your name: " << endl;

      getline(cin, name, '\n');
      
     
    }

    tries = 3;

    cout << "Enter your password: " << endl;

    getline(cin, pass, '\n');

    while(tries > 0 && corrPass != pass){

      --tries;
      cout << "Incorrect Password! " << tries << " attempts remaining!" << endl;

      if(tries == 0){

        cout << "Too many attempts! Exiting..." << endl;
        exit(1);

      }

      cout << "Enter your password: " << endl;
      getline(cin, pass, '\n');

    }

  }

  f.close();
 if(admin){
	me = new Librarian(name,pass);
	return me;
	
}
me = new User(name, pass);
return me;
 

}

bool corr_name(fstream& f, const string& filename, const string& name, string& corrPass,bool& admin){
  f.clear();
  f.seekg(0);
  string user;
  string realName;
  while(getline(f, user)){
    
    if(name == user.substr(1,user.find('|')-1)){
      //cout << user.substr(1,user.find('|'));
      if(user.at(0) == '@') admin = true;
      corrPass = user.substr(user.find('|')+1, user.size()-user.find('|'));
      return true;

    }
}

return false;

}

};
