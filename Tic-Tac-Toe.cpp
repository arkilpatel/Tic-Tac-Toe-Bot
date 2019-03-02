/*
TIC-TAC-TOE v2.0
Authors:
Naigam
Arkil
Malhar
Abhimanyu
*/

#include<bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int x_chk=1, o_chk=2;
int mv_c=0,game_type=0;
int spc_x,spc_y;
int flag_test=0;
int flag_game_type=0;
int test_recur=0;
int number=0;
int temp_mv=0;

int dup1[3][3]={{0}};
int dup2[3][3]={{0}};
int dup3[3][3]={{0}};
int dup4[3][3]={{0}};
int dup5[3][3]={{0}};
int pos[3][3]={{0}};
int r[2][3]={{0}},c[2][3]={{0}},dia[2][2]={{0}};

void print_row(int[][3],int);    //done
void print_board();             //done
bool has_won();                 //done
bool chk_col(int[][3]);          //done
bool chk_row(int[][3]);          //done
bool chk_dia(int[][3]);          //done
bool win_mv(int[][3],int, int);          //done
bool win_row(int[][3],int,int);     //done
bool win_col(int[][3],int,int);     //done
bool win_dia(int[][3],int,int);     //done
bool necessity_mv(int[][3]);         //done
void optimal_mv(int[][3],int,int);
bool is_marker(int,int);
bool is_adjacent(int,int);
void erasing_mv(int,int,int);
void find_spc();
void reinitialize();

void Test()
{
//  cout<<"Test Started"<<endl;
  flag_test=1;
  flag_game_type=1;
  test_recur++;
  for(int mark1=0; mark1<3; mark1++)
  {
    for(int mark2=0;mark2<3;mark2++)
    {
      if(pos[mark1][mark2]==0)
      {
  //      cout<<"test_recur is: "<<test_recur<<endl;
        mv_c=0;
        if(test_recur == 1)
        {
    //    cout<<"The duplicate is: ";
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            dup1[i1][j1]=pos[i1][j1];
            if(pos[i1][j1]==1)
              mv_c++;
      //      cout<<pos[i1][j1]<<" ";
          }
        }
        }
        if(test_recur == 2)
        {
  //      cout<<"The duplicate is: ";
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            dup2[i1][j1]=pos[i1][j1];
            if(pos[i1][j1]==2)
            {
            if((i1+j1)%2==0)
              game_type=2;
            else
              game_type=1;
            }
            if(pos[i1][j1]==1)
              mv_c++;
    //        cout<<pos[i1][j1]<<" ";
          }
        }
        }
        if(test_recur == 3)
        {
  //      cout<<"The duplicate is: ";
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            dup3[i1][j1]=pos[i1][j1];
            if(pos[i1][j1]==1)
              mv_c++;
    //        cout<<pos[i1][j1]<<" ";
          }
        }
        }
        if(test_recur == 4)
        {
    //    cout<<"The duplicate is: ";
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            dup4[i1][j1]=pos[i1][j1];
            if(pos[i1][j1]==1)
              mv_c++;
    //        cout<<pos[i1][j1]<<" ";
          }
        }
        }
        if(test_recur == 5)
        {
    //    cout<<"The duplicate is: ";
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            dup5[i1][j1]=pos[i1][j1];
            if(pos[i1][j1]==1)
              mv_c++;
      //      cout<<pos[i1][j1]<<" ";
          }
        }
        }
        cout<<endl;

        while(!(has_won()) && mv_c<=4 && mv_c>0){
            pos[mark1][mark2]=2;
            if(win_mv(pos,1,2)) {
             //  cout<<"Hello you are inside win move"<<endl;
                mv_c++;
                break;
            }
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){               //clearing to zero
                    r[i][j]=0;
                    c[i][j]=0;
                    if(j<2) dia[i][j]=0;
                }
            }
            if(necessity_mv(pos)){
        //        cout<<"Hello you are inside necessity move"<<endl;
                mv_c++;
                if(!has_won())
                Test();
        //        cout<<"mark1 & mark2 are: "<<mark1<<" "<<mark2<<endl;
                continue;
            }
        //    cout<<"No necessity"<<endl;
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){               //clearing to zero
                    r[i][j]=0;
                    c[i][j]=0;
                    if(j<2) dia[i][j]=0;
                }
            }
          //  cout<<"mv_c is: "<<mv_c<<endl;
  //          if(mv_c>0){
            //    cout<<"This is optimal move";
            temp_mv=mv_c;
            optimal_mv(pos,mark1,mark2);
            mv_c++;
            if(!has_won() && mv_c<=4)
            {
        //    cout<<"test_recur is: "<<test_recur<<endl;
            Test();
            }
        }
        int flg=0,i_j;
        if(mv_c==5 && !(has_won())){
      //    cout<<"Last rule"<<endl;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        i_j=i*j;
                        if(pos[i][j]==1 && is_adjacent(i,j) && i_j!=1){
                  //        cout<<"Erasing move will now run on "<<i<<" "<<j<<endl;
                            erasing_mv(i,j,1);
                            flg=1;
                        }
                        if(flg==1) break;
                    }
                    if(flg==1) break;
                }
                flg=0;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        i_j=i*j;
                    //    cout<<"i&j: "<<i<<j<<endl;
                        if(pos[i][j]==2 && is_adjacent(i,j) && i_j!=1){
                      //    cout<<"Erasing move will now run on "<<i<<" "<<j<<endl;
                            erasing_mv(i,j,2);
                            flg=1;
                        }
                        if(flg==1) break;
                    }
                    if(flg==1) break;
                }
          //      label:
            //    cin>>x>>y;
          //      if(is_marker(x,y) && is_adjacent(x,y)){
            //        erasing_mv(x,y,2);
                    /*
                    cout<<"-------------------Press ENTER key to continue....-------------------"<<endl;
                    cin.ignore();
                    cin.get();
                }

                else{
                    cout<<"Position invalid!!"<<endl;
                    cout<<"Enter once again: "<<endl;
                    goto label;
                }*/
                flg=0;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        i_j=i*j;
                        if(pos[i][j]==1 && is_adjacent(i,j) && i_j!=1){
                            erasing_mv(i,j,1);
                            flg=1;
                        }
                        if(flg==1) break;
                    }
                    if(flg==1) break;
                }
                number++;
                cout<<"possibility Number: "<<number<<endl;
                print_board();
                cout<<"COMPUTER has WON!!"<<endl;
        //        test_recur--;
                reinitialize();
                if(test_recur == 1)
                {
                for(int i1=0; i1<3; i1++)
                {
                  for(int j1=0; j1<3; j1++)
                  {
                    pos[i1][j1]=dup1[i1][j1];
                  }
                }
                }
                if(test_recur == 2)
                {
                for(int i1=0; i1<3; i1++)
                {
                  for(int j1=0; j1<3; j1++)
                  {
                    pos[i1][j1]=dup2[i1][j1];
                  }
                }
                }
                if(test_recur == 3)
                {
                for(int i1=0; i1<3; i1++)
                {
                  for(int j1=0; j1<3; j1++)
                  {
                    pos[i1][j1]=dup3[i1][j1];
                  }
                }
                }
                if(test_recur == 4)
                {
                for(int i1=0; i1<3; i1++)
                {
                  for(int j1=0; j1<3; j1++)
                  {
                    pos[i1][j1]=dup4[i1][j1];
                  }
                }
                }
                if(test_recur == 5)
                {
                for(int i1=0; i1<3; i1++)
                {
                  for(int j1=0; j1<3; j1++)
                  {
                    pos[i1][j1]=dup5[i1][j1];
                  }
                }
                }
          //      return 0;
            }
        else if (mv_c>0){
        number++;
        cout<<"possibility Number: "<<number<<endl;
        print_board();
        cout<<"COMPUTER has WON!!"<<endl;
  //      cout<<"test_recur is: "<<test_recur<<endl;
  //      test_recur--;
        reinitialize();
        if(test_recur == 1)
        {
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            pos[i1][j1]=dup1[i1][j1];
          }
        }
        }
        if(test_recur == 2)
        {
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            pos[i1][j1]=dup2[i1][j1];
          }
        }
        }
        if(test_recur == 3)
        {
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            pos[i1][j1]=dup3[i1][j1];
          }
        }
        }
        if(test_recur == 4)
        {
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            pos[i1][j1]=dup4[i1][j1];
          }
        }
        }
        if(test_recur == 5)
        {
        for(int i1=0; i1<3; i1++)
        {
          for(int j1=0; j1<3; j1++)
          {
            pos[i1][j1]=dup5[i1][j1];
          }
        }
        }
      //  return 0;
    } //end of else
  }//end of if(pos[mark1][mark2]==0)
    }
    }
  //}
  test_recur--;
//  cout<<"test_recur is: "<<test_recur<<endl;
  if(test_recur == 1)
  {
  for(int i1=0; i1<3; i1++)
  {
    for(int j1=0; j1<3; j1++)
    {
      pos[i1][j1]=dup1[i1][j1];
    }
  }
  }
  if(test_recur == 2)
  {
  for(int i1=0; i1<3; i1++)
  {
    for(int j1=0; j1<3; j1++)
    {
      pos[i1][j1]=dup2[i1][j1];
    }
  }
  }
  if(test_recur == 3)
  {
  for(int i1=0; i1<3; i1++)
  {
    for(int j1=0; j1<3; j1++)
    {
      pos[i1][j1]=dup3[i1][j1];
    }
  }
  }
  if(test_recur == 4)
  {
  for(int i1=0; i1<3; i1++)
  {
    for(int j1=0; j1<3; j1++)
    {
      pos[i1][j1]=dup4[i1][j1];
    }
  }
  }
  if(test_recur == 5)
  {
  for(int i1=0; i1<3; i1++)
  {
    for(int j1=0; j1<3; j1++)
    {
      pos[i1][j1]=dup5[i1][j1];
    }
  }
  }
  /*
  cout<<"The pos is: ";
  for(int i1=0; i1<3; i1++)
  {
    for(int j1=0; j1<3; j1++)
    {
      cout<<pos[i1][j1]<<" ";
    }
  }
  cout<<endl;*/
}



int main(){
    int option1;
    fast();
    cout<<"......Welcome to TIC-TAC-TOE v2.0......"<<endl<<endl;
    cout<<"Select an option: "<<endl;
    cout<<"1. Test (Exhaustive List of final outputs using all possible input combinations)....press 1"<<endl;
    cout<<"2. Play Game....press 2"<<endl;
    cin>>option1;
    if(option1 == 1)
    {
    pos[1][1]=1;
    mv_c++;
    Test(); //remember: flag_game_type has to be 0 for normal game
    cout<<endl;
    cout<<"Total possible number of final outputs: "<<number<<endl;
    cout<<"-------------------Press ENTER key to continue....-------------------"<<endl;
    cin.ignore();
    cin.get();
    }
    else
    {
      flag_game_type=0;
      int consent=1;
      int mv_c=0;

    while(true){
        reinitialize();
        mv_c=0;
        cout<<"Your marker is 'O'."<<endl;
        cout<<"Opponets marker is 'X'."<<endl;
        cout<<"First move is of Computer(X)."<<endl<<endl;
  //      while(consent){
        print_board();
        cout<<"-------------------Press ENTER key to continue....-------------------"<<endl;
        cin.ignore();
        //cin.get();
        while(!(has_won()) && mv_c<=4){
            //print_board();
            if(mv_c==0){
                cout<<"Computer(X) has taken its first move."<<endl;
                pos[1][1]=1;
                print_board();
                //cout<<"Press ENTER key to continue...."<<endl;
                //cin.get();
                mv_c++;
            }
      //      cout<<"Here";
            cout<<"Enter your(O) CHOICE (x y), x-row, y-column: "<<endl;
            int x,y;
            cin>>x>>y;
            if(pos[x][y]==1 || pos[x][y]==2){
                cout<<"Sorry that place is already filled, please enter another choice!!"<<endl<<endl;
                continue;
            }
            pos[x][y]=2;
            cout<<"-----FOR A BETTER GAMING EXPERIENCE, ALWAYS SEE BELOW THIS LEVEL-----"<<endl<<endl;
            cout<<"After your(O) "<<mv_c<<"th move: "<<endl;
            print_board();
            cin.ignore();
            cout<<"-------------------Press ENTER key to continue....-------------------"<<endl;
            cin.get();
            if(win_mv(pos,1,2)) {
                //cout<<"Hello you are inside win move"<<endl;
                mv_c++;
                cout<<endl;
                cout<<"-----FOR A BETTER GAMING EXPERIENCE, ALWAYS SEE BELOW THIS LEVEL-----"<<endl<<endl;
                cout<<"After computer's "<<mv_c<<"th move: "<<endl;
                print_board();
                break;
            }
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){               //clearing to zero
                    r[i][j]=0;
                    c[i][j]=0;
                    if(j<2) dia[i][j]=0;
                }
            }
            if(necessity_mv(pos)){
                //cout<<"Hello you are inside necessity move"<<endl;
                mv_c++;
                cout<<"After computer's "<<mv_c<<"th move: "<<endl;
                print_board();
                //cout<<"Press ENTER key to continue...."<<endl;
                //cin.get();
                continue;
            }
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){               //clearing to zero
                    r[i][j]=0;
                    c[i][j]=0;
                    if(j<2) dia[i][j]=0;
                }
            }

            if(mv_c>0){
    //            cout<<"You are going into optimal move"<<endl;
      //          cout<<"mv_c is: "<<mv_c<<endl;
                temp_mv=mv_c;
    //            cout<<"temp_mv is: "<<mv_c<<endl;
                optimal_mv(pos,x,y);
    //            cout<<"You are out of optimal move"<<endl;
                cout<<"After computer's "<<mv_c+1<<"th move: "<<endl;
                print_board();
                //cout<<"Press ENTER key to continue...."<<endl;
                //cin.get();
            }
            mv_c++;

        }
        //print_board();
        int flg=0,i_j;
        if(mv_c==5 && !(has_won())){
            cout<<"-------------------Press ENTER key to continue....-------------------"<<endl;
            cin.get();
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        i_j=i*j;
                        if(pos[i][j]==1 && is_adjacent(i,j) && i_j!=1){
                            erasing_mv(i,j,1);
                            flg=1;
                        }
                        if(flg==1) break;
                    }
                    if(flg==1) break;
                }
                cout<<"Enter position to be ERASED: "<<endl;
                int x,y;
                label:
                cin>>x>>y;
                if(is_marker(x,y) && is_adjacent(x,y)){
                    erasing_mv(x,y,2);
                    cout<<"-------------------Press ENTER key to continue....-------------------"<<endl;
                    cin.ignore();
                    cin.get();
                }
                else{
                    cout<<"Position invalid!!"<<endl;
                    cout<<"Enter once again: "<<endl;
                    goto label;
                }
                flg=0;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        i_j=i*j;
                        if(pos[i][j]==1 && is_adjacent(i,j) && i_j!=1){
                            erasing_mv(i,j,1);
                            flg=1;
                        }
                        if(flg==1) break;
                    }
                    if(flg==1) break;
                }
                cout<<"COMPUTER has WON!!"<<endl;
            }
        else cout<<"COMPUTER has WON!!"<<endl;

        cout<<"If you want to play another game kindly press '1' else press '0': "<<endl;
        int consent;
        cin>>consent;
    //    cout << "\033[2J\033[1;1H";
    //    cout << "\x1B[2J\x1B[H";
        if(consent==0){
            cout<<"Thank You for playing! Have a nice Day!!"<<endl;
            cout<<"A Project by Naigam, Arkil, Malhar & Abhimanyu!!"<<endl;
            break;
        }
  //      cout << "\033[2J\033[1;1H";
  //      cout << "\x1B[2J\x1B[H";
//}
}
cout<<"-------------------Press ENTER key to continue....-------------------"<<endl;
cin.ignore();
cin.get();
}
return 0;
}

void erasing_mv(int x,int y,int a){
        find_spc();
  //      cout<<"empty is: "<<spc_x<<" "<<spc_y<<endl;
        pos[spc_x][spc_y]=a;
        pos[x][y]=0;
        //cout<<"3.) "<<endl;
        if(flag_test==0 && flag_game_type==0)
        print_board();
}

void find_spc(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(pos[i][j]==0){
                spc_x=i;
                spc_y=j;
            }
        }
    }
}

bool is_marker(int x,int y){
    if(pos[x][y]==2) return true;
    else return false;
}

bool is_adjacent(int x,int y){
    //int spc_x,spc_y;
    find_spc();
    if((((x==spc_x-1) || (x==spc_x+1)) && y==spc_y) || (((y==spc_y-1) || (y==spc_y+1)) && x==spc_x)) return true;
    else return false;
}

void print_row(int pos[][3],int i){
    cout<<"   _____ _____ _____"<<endl;
    cout<<"  |     |     |     |"<<endl;
    cout<<i<<" ";
    for(int j=0;j<3;j++){
        if(pos[i][j]==0) cout<<"|     ";
        else if(pos[i][j]==1) cout<<"|  X  ";
        else cout<<"|  O  ";
    }
    cout<<"| "<<endl;
    cout<<"  |     |     |     |"<<endl;
}

void print_board(){
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"     0     1     2  "<<endl;
    print_row(pos,0);
    print_row(pos,1);
    print_row(pos,2);
    cout<<"   _____ _____ _____"<<endl;
    cout<<"\n"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;

}

bool has_won(){
    if(chk_col(pos) || chk_row(pos) || chk_dia(pos)) return true;
    return false;
}

bool chk_row(int pos[][3]){
    for(int i=0;i<3;i++){
        if(pos[i][0]==1 && pos[i][1]==1 && pos[i][2]==1) return true;
    }
    return false;
}

bool chk_col(int pos[][3]){
    for(int i=0;i<3;i++){
        if(pos[0][i]==1 && pos[1][i]==1 && pos[2][i]==1) return true;
    }
    return false;
}

bool chk_dia(int pos[][3]){
    if(pos[0][0]==1 && pos[1][1]==1 && pos[2][2]==1) return true;
    else if(pos[0][2]==1 && pos[1][1]==1 && pos[2][0]==1) return true;
    return false;
}

bool win_mv(int pos[][3],int des, int undes){
    int ran = rand()%6;
    if(ran==0){
        if(win_row(pos,des,undes)) return true;
        else if(win_col(pos,des,undes)) return true;
        else if(win_dia(pos,des,undes)) return true;
        else return false;
    }
    else if(ran==1){
        if(win_col(pos,des,undes)) return true;
        else if(win_row(pos,des,undes)) return true;
        else if(win_dia(pos,des,undes)) return true;
        else return false;
    }
    else if(ran==2){
        if(win_dia(pos,des,undes)) return true;
        else if(win_col(pos,des,undes)) return true;
        else if(win_row(pos,des,undes)) return true;
        else return false;
    }
    else if(ran==3){
        if(win_dia(pos,des,undes)) return true;
        else if(win_row(pos,des,undes)) return true;
        else if(win_col(pos,des,undes)) return true;
        else return false;
    }
    else if(ran==4){
        if(win_col(pos,des,undes)) return true;
        else if(win_dia(pos,des,undes)) return true;
        else if(win_row(pos,des,undes)) return true;
        else return false;
    }
    else if(ran==5){
        if(win_row(pos,des,undes)) return true;
        else if(win_dia(pos,des,undes)) return true;
        else if(win_col(pos,des,undes)) return true;
        else return false;
    }
}

bool win_row(int pos[][3],int des,int undes ){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        if(pos[i][j]==undes) continue;
        else r[des-1][i]+=pos[i][j];
        }
        if(r[des-1][i]==2*des){
            for(int k=0;k<3;k++){
                if(pos[i][k]==0) {
                    pos[i][k]=1;
                    //cout<<i<<"----------"<<k<<endl<<endl<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool win_col(int pos[][3],int des, int undes){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        if(pos[j][i]==undes) continue;
        else c[des-1][i]+=pos[j][i];
        }
        if(c[des-1][i]==2*des){
            for(int k=0;k<3;k++){
                //if(pos[k][i]==0) pos[k][i]==1;
                if(pos[k][i]==0) {
                    pos[k][i]=1;
                    //cout<<i<<"----------"<<k<<endl<<endl<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool win_dia(int pos[][3],int des,int undes){
    for(int i=0;i<3;i++){
        if(pos[i][i]!=undes) dia[des-1][0]+=pos[i][i];
        if(pos[i][2-i]!=undes) dia[des-1][1]+= pos[i][2-i];
    }
    if(dia[des-1][0]==2*des){
        for(int k=0;k<3;k++){
            //if(pos[k][k]==0) pos[k][k]=1;
            if(pos[k][k]==0) {
                pos[k][k]=1;
                //cout<<k<<"----------"<<k<<endl<<endl<<endl;
                return true;
            }
        }
    }
    if(dia[des-1][1]==2*des){
        for(int k=0;k<3;k++){
            //if(pos[k][2-k]==0) pos[k][2-k]=1;
            if(pos[k][2-k]==0) {
                pos[k][2-k]=1;
                //cout<<k<<"----------"<<2-k<<endl<<endl<<endl;
                return true;
            }
        }
    }
    return false;
}

bool necessity_mv(int pos[][3]){
    return win_mv(pos,2,1);
}

void optimal_mv(int pos[][3],int x,int y){
    mv_c=temp_mv;
//    cout<<"mv_c is: "<<mv_c<<endl;
    if(mv_c==1){
        if((x+y)%2) game_type=1; //edge_centre
        else game_type=2;//corner
    }
//    cout<<"game_type is: "<<game_type<<endl;
    if(mv_c==1 && game_type==1) pos[0][0]=1;
    if(mv_c==2 && game_type==1){
        if(pos[1][0]==2) pos[0][2]=1;
        else if(pos[0][1]==2) pos[2][0]=1;
    }
    if(mv_c==1 && game_type==2){
        if(pos[0][0]==2) pos[0][2]=1;
        if(pos[0][2]==2) pos[0][0]=1;
        if(pos[2][0]==2) pos[2][2]=1;
        if(pos[2][2]==2) pos[2][0]=1;
    }
    if(mv_c==3 && game_type==2){
        if(pos[0][0]==1 || pos[0][2]==1) pos[2][1]=1;
        if(pos[2][0]==1 || pos[2][2]==1) pos[0][1]=1;
    }
}

void reinitialize(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            pos[i][j]=0;
            if(i<2){
              r[i][j]=0;
              c[i][j]=0;
              if(j<2) dia[i][j]=0;
            }
        }
    }
    flag_test=0;

    x_chk=1;
    o_chk=2;
  //  if(!flag_game_type)
      mv_c=0;
      if(!flag_game_type)
    game_type=0;

}
