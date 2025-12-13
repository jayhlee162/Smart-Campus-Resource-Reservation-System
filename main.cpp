#include "UserInterface.h"
#include "School.h"
int main(){
  UserInterface run;
  User u1;
  School s1;
  int input;
  bool endProgram = false;
  //code to handle login

  if(u1.isAdmin())
  do{
    run.printAdminMenu();
    std::cin >> input;
    
    switch (input)
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
  }while (!endProgram);

  else
  do{
    run.printStudentMenu();
    std::cin >> input;
    switch (input)
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
  }while (!endProgram);
  return 0;
}
