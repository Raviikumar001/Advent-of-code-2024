#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
#include <iostream>
using namespace std;

  int main ()
  {
      string s;
      char c;
      while(scanf("%c", &c) !=EOF){
          s +=c;
      }
      s += "##################";
      int n = (int) s.length();
      auto getNumber = [&] (int& i) {
          int x =0;
          while (x<100 && isdigit(s[i])) {

              x = 10 * x + (s[i] - '0');
              i++;
          }
          if (1 <=x && x <= 999){
              return x;
          }
          return  -1;
      };

      int answer = 0;
      for (int i=0; i<n; i++)
      {
          if(s[i] == 'm')
          {
              if (s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(') {
                  i += 4;
                  int x = getNumber(i);
                  if (s[i] == ','){
                      i+=1;
                      int y = getNumber(i);
                      if (s[i] == ')'){
                          if(x != -1 && y!= -1)
                          {

                          answer += x * y;
                          }
                      }
                  }
              }
          }
      }

      cout << " "<< answer;
  }
