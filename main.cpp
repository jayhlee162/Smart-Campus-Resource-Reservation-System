#include "School.h"
#include "UserInterface.h"
#include "FileWriter.h"
int main(){
  UserInterface run;
  User u1;
  School s1;
  FileWriter f1;
  std::string input;
  bool endProgram = false;
  
  
  s1.loadAll();
  s1.initializeResources();
  
  //Returns user object affiliated with username to u1
  u1 = s1.login();

  if(u1.isAdmin())
  do{
    run.printAdminMenu();
    std::getline(std::cin, input);
    
    if(stoi(input) > 0 && stoi(input) < 9){
      switch (stoi(input))
      {
      case 1:
        s1.createReservation(u1);
        break;
      case 2:
        s1.cancelReservation(u1);
        break;
      case 3:
        s1.printReservation(u1);
        break;
      case 4:
        s1.printResources();
        break;
      case 5:
        s1.addResource();
        break;
      case 6:
        s1.removeResource();
        break;
      case 7:
        s1.editResource();
        break;
      case 8:
        endProgram = true;
        break;
      default:
        break;
      }
    }
  }while (!endProgram);

  else
  do{
    run.printStudentMenu();
    std::getline(std::cin, input);
    
    if(stoi(input) > 0 && stoi(input) < 6){
      switch (stoi(input))
      {
      case 1:
        s1.createReservation(u1);
        break;
      case 2:
        s1.cancelReservation(u1);
        break;
      case 3:
        s1.printReservation(u1);
        break;
      case 4:
        s1.printResources();
        break;
      case 5:
        endProgram = true;
        break;
      }
    }
  }while (!endProgram);

  s1.saveAll();
  
  return 0;
}

