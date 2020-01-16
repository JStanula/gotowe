#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>


using namespace std;

int main(int argc, const char * argv[]) {
    fstream plik;
 //   int licznik = 0;
     string b;
    int win =0;
    int tounix = 0,towin =0;
   if(argc == 1){
        cout<<"usage: zad20 [-unix|-win] file"<<endl;
        return 0;
    }
   if(argc == 2){
        plik.open(argv[1], ios::out|ios::in);
    }
    if(argc == 3){
        plik.open(argv[1], ios::in|ios::out);
        if(strcmp(argv[2], "-unix") == 0){
           cout<<"to unix\n";
            tounix = 1;
        }
        if(strcmp(argv[2], "-win") == 0){
            towin = 1;
        }
    }
    if(plik.good() == true){
        char znak;
        cout<<"Uzyskano dostep"<<endl;
        while(plik>>noskipws>>znak){

         //  cout<<"in char checking";
           if(znak == '\r'){
                win = 1;
            }
            if(znak == '\n' && win ==1){
                win = 2;
            }
        }
       // plik<<"po edycji";
        plik.close();
    }
    else cout<<"Dostep zabroniony"<<endl;
    if(win == 2){
        cout<<"Windows file"<<endl;
        if(tounix == 1){
          //  cout<<"Converting to unix..."<<endl;
            plik.open(argv[1], ios::out|ios::in);
            if(plik.good()==true){
          /*  while(!plik.eof())
                             {
                                 getline(plik, b);
                                 cout << b << endl; //wyœwietlenie linii
                             }
                plik.close();
            }*/


                char znak;
                while(plik>>noskipws>>znak){

                        //  cout<<"in char checking";
                          if(znak != '\r'){
                              b += znak;
                           }
                       }
                plik.close();
            }
            plik.open(argv[1], ios::out|ios::trunc);
            if(plik.good()){
                plik<<b;
                plik.close();
            }
            cout<<"file: "<<argv[1]<<"succesfully converted to unix format";
        }
        if(towin == 1){
            cout<<"Sorry,you can't convert windows file to windows file"<<endl;
        }
    }
    else{
        cout<<"Unix file"<<endl;
        if(towin == 1){
          //  cout<<"Converting to windows..."<<endl;
                plik.open(argv[1], ios::out|ios::in);
                if(plik.good()==true){
                 char znak;
                 while(plik>>noskipws>>znak){

                         //  cout<<"in char checking";
                           if(znak == '\r' || znak == '\n'){
                             b += '\r';
                             b += '\n';

                            }
                           else b = b + znak;
                        }
                    plik.close();
                }
                plik.open(argv[1], ios::out|ios::trunc);
                if(plik.good()){

                    plik<<b;
                    plik.close();

                cout<<"file: "<<argv[1]<<"succesfully converted to windows format";
            }        }
    }
   // cout<<b;
    //cout<<"ilosc n ="<<win;
    return 0;
}



