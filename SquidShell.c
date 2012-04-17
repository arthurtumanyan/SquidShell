#include "SquidShell.h"
#include "prototypes.h"


int main(int argc,char **argv){

  while((opt = getopt(argc,argv,"h:s:l:p:e:")) != -1){
    switch(opt){
      case 'h':
	strcpy(rh,optarg);
	printf("Host: %s\n",rh);
	break;
      case 's':
	strcpy(rp,optarg);
	printf("Port: %s ->%s\n",rp,optarg);
	break;
      case 'l':
	strcpy(ml,optarg);
	printf("Login: %s\n",ml);
	break;
      case 'p':
	strcpy(mp,optarg);
	printf("Password: %s\n",mp);
	break;
      case 'e':
	do_command(optarg);
	exit(EXIT_SUCCESS);
      default:
	break;
    }
    clf = 1;
  }
setbuf(stdout,NULL);
setbuf(stdin,NULL);
initHistory();
set_sig_handler();
    fprintf(stdout,"%s\n\n",welcome_str);
    do{

	fprintf(stdout,"%s","SquidShell>");
	 fgets(inputline, sizeof(inputline), stdin);
	 low_string(inputline);
    if(inputline[0] == '\0'||inputline[0] == '\n')continue;
    if(0 == do_command(inputline)){

        fprintf(stdout,"%s:\t%s\n","No such command","type 'help' for available commands list");
    }

    }while(doneProg == 0);

    return 0;
}

