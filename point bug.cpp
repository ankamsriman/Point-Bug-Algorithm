//
//  main.cpp
//  Swarm
//
//  Created by ANKAM SRIMAN on 15/05/20.
//  Copyright © 2020 ANKAM SRIMAN. All rights reserved.
//




#define ll long long int
#include <iostream>
#include <utility>
#include<vector>
#include<cmath>

using namespace std;


//I wrote the code if we import the file which contain he below fuctions which do as mentttioned below


range_sensor();  //It returns the the distance of the obstacle from the bot for a specific direction

rot_sens();     //it rotates the sensor by certain degrees which is very small when eve it is called
                //other thing is that give value 1 makes it to rotate clock wise and -1 anti clockwise

rot_bot();      //rotates the bot by the given angle

move_bot();     //move the bot by given lenth






int main()
{
    
    
    
    ll dist;
    
    double del_d;     //it is the delta dist which can bebe considered as sudden point
    double angle=0;
    
    double orient;    //orientation of the bot
    long double prev_len,cur_len;
    double rot_sum;
    
    ll n;
    double A,x;
    pair<long double,long double>bot_pos={0,0}; //it is bot pos w.r.t initial pos
    
    cin>>dist;
    
    
    
    ll prev_sud,next_sud_dist;
    
    vector<long double>path_length,d_min;//storing the path travelled between each consequtive sudden points
 
    path_length.push_back(dist);
    
    while(d_min[n]==0)
    {
        
        if(angle<=360)  //robot is restricted to move <=360 as if it's not then it' waste as it's like searching the same region
        {
            prev_len= range_sensor();
            if(orient+atan((bot_pos.second-dist)/bot_pos.first<180))
            {
                rot_sum=rot_sum+rot_sens(1);
                orient=orient+rot_sens(1);
            }
            else
            {
                rot_sum=rot_sum+rot_sens(-1);
                orient=orient+rot_sens(-1);
            }
            
            cur_len=range_sensor();
            
            if(abs(cur_len-prev_len)>del_d)  //if the point is sudden point
            {
                
                if(angle==180)
                {
                    continue; //Ignoring the next sudden point if it is a previous sudden point
                }
                else
                {
                    n++;
                    bot_pos.first=cur_len*cos(orient);
                    bot_pos.second=cur_len*sin(orient);
                    
                    path_length.push_back(cur_len); //storing the path travelled between each consequtive sudden points
                    
    
                    next_sud_dist=cur_len;    //dist (current sudden,next suden)
                        
                     angle=rot_sum;   //its the angle which bot needed to rotate
                        
                    rot_bot(angle);       //making the bot to rotate
                        
                    move_bot(next_sud_dist) ;   //move the bot by a distance
                  
                    A=atan(1/(1/tan(angle)-(1/sin(angle))*(path_length[n-1]/path_length[n])));
                    
                  if(n==1)
                  {
                      A=angle;
                  }
                  else
                  {
                      if(A<=90)
                     {
                         A=180-x-angle;
                     }
                     else
                     {
                         A=x+angle;
                     }
                  }

                  d_min.push_back(pow(path_length[n-1],2) +pow(d_min[n-1],2)-2*path_length[n-1]*d_min[n-1]*cos(A));   //bsina=....,A=180-rot-adj    (angle of robot rot)
                        
                   angle=0;
                    
                    //****SECOND METHOD****
                    
                    // Replace 108 to 126 with the below code
                    
                    //d_min.push_back(pow((bot_pos.second-dist)*2+bot_first*2,0.5));
                    
                
                
                }
            }
        }
        else
        {
            cout<<"No way";
        }
    }
   if(d_min[n]==0)
   {
       cout<<"Target succesfully reached"<<endl;
   }
       ll sum=0;
    cout<<"path length covered in each partkelar orientation is ";
       for(ll i=0;i<=n;i++)
       {
           cout<<path_length[i]<<endl;
           sum=sum+path_length[i];
       }
       cout<<sum<<" is the total path length"<<endl;
    return 0;
}

