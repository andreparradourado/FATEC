#include <stdio.h>
#include <time.h>

int main(){
  struct tm *local;
  time_t t;
  char data[11],hora[9];

  t = time(NULL);
  local = localtime(&t);

  sprintf(data,"%d/%d/%d",local->tm_mday,local->tm_mon+1,local->tm_year+1900);
  sprintf(hora,"%d:%d:%d",local->tm_hour,local->tm_min,local->tm_sec);

  printf("\ndata: %s",data);
  printf("\nhora: %s",hora);

return 0;
}//Fim main()
