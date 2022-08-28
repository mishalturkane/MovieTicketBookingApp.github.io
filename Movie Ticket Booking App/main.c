#include <stdio.h>
#include "conio2.h"
#include <stdlib.h>
#include <error.h>
#include <dir.h>
#include "mtb.h"

int main()
{
    int result;
    result=mkdir("C:\\Movie Ticket Booking");
    if(result!=0 && errno!=17)
    {
        printf("Sorry! Application cannot run\n");
        perror("Reason:");
          return 1;
    }
    set_master_admin();
    add_questions();

    create_user("admin");
  //  create_user("user");
    user *usr;
    int choice;
    while(1)
    {
        choice=enter_login_choice();
        if(choice==0)
            break;
        switch(choice)
        {
            case 1:
                usr=login("admin");
                if(usr==NULL){
                    break;
                    }
                while(1){
                    choice=enter_choice(usr);
                    printf("\nGot %d",choice);
                    getch();
                    if(choice==0)
                        break;
                            switch(choice)
                            {
                                case 1:
                                add_theater();
                                break;

                                case 2:
                                show_theater();
                                break;

                                case 3:
                                delete_theater();
                                break;

                                case 4:
                                add_movie();
                                break;

                                case 5:
                                show_movie();
                                break;

                                case 6:
                                  if(delete_movie() == 1)
                                {
                                    print_char(' ', 79, 25, BLACK);
                                    print_title_in_middle("Movie details deleted successfully", 25, LIGHTGREEN);
                                    getch();
                                }
                                break;

                                case 7:
                                    change_contact_details(usr);
                                break;

                                case 8:
                                    change_security_question(usr);
                                break;

                                case 9:
                                    change_password(usr);
                                break;

                                case 10:
                                  show_my_profile(usr);
                                break;
                                default:
                                print_char(' ',80,25,BLACK);
                                print_title_in_middle("Invalid Choice! Try Again",25,RED);
                                getch();
                        }
            }
            break;

            case 2:
                usr=login("user");
                if(usr==NULL){
                    break;
                    }
                while(1){
                    choice=enter_choice(usr);
                    printf("\nGot %d",choice);
                    getch();
                    if(choice==0)
                        break;

                            switch(choice)
                            {
                                case 1:
                                show_movie();
                                break;

                                case 2:
                                booking(usr);
                                break;

                                case 3:
                                 show_booking_of_user(usr);
                                break;

                                case 4:
                                 cancel_booking_of_user(usr);
                                break;

                                case 5:
                                  change_contact_details(usr);
                                break;

                                case 6:
                                  change_security_question(usr);
                                break;

                                case 7:
                                change_password(usr);
                                break;

                                case 8:
                                  show_my_profile(usr);
                                break;

                                case 9:
                                   choice=delete_my_account(usr);
                                break;


                                default:
                                print_char(' ',80,25,BLACK);
                                print_title_in_middle("Invalid Choice! Try Again",25,RED);
                                getch();
                        }
                    if (choice==0)
                        break;
                    }
            break;
            case 3:
                create_user("user");
                break;

            default:
                print_char(' ', 79, 25, BLACK);
                print_title_in_middle("Wrong Input! Please Try Again", 25, RED);
                getch();
        }
    }

    return 0;
}
