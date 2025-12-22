#include "School.h"
#include "UserInterface.h"
#include "FileWriter.h"
int main(){
  UserInterface run;
  User user;
  School school;
  FileWriter fileWriter;
  int input;
  bool endProgram = false;
  
  
  school.loadAll();
  school.initializeResources();
  
  //Returns user object affiliated with username to user
  user = school.login();

  if(user.isAdmin())
  do{
    run.printAdminMenu();
    input = run.getIntFromUser();
    
    if(input > 0 && input < 9){
      switch (input)
      {
      case 1:
        run.createReservationInteractive(user, school);
        break;
      case 2:
        run.cancelReservationInteractive(user, school);
        break;
      case 3:
        school.printAllReservations(user);
        run.waitForEnter();
        break;
      case 4:
        school.printResources();
        break;
      case 5:
        run.addResourceInteractive(school);
        break;
      case 6:
        run.removeResourceInteractive(school);
        break;
      case 7:
        school.editResource();
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
    input = run.getIntFromUser();
    
    if(input > 0 && input < 6){
      switch (input)
      {
      case 1:
        run.createReservationInteractive(user, school);
        break;
      case 2:
        run.cancelReservationInteractive(user, school);
        break;
      case 3:
        school.printAllReservations(user);
        run.waitForEnter();
        break;
      case 4:
        school.printResources();
        break;
      case 5:
        endProgram = true;
        break;
      }
    }
  }while (!endProgram);

  school.saveAll();
  
  return 0;
}

