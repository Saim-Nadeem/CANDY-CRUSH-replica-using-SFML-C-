#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
using namespace sf;
using namespace std;


//global variables
int camel=0,elephant=0,lion=0,goat=0,giraffe=0,dear=0,moves=40,ms=0,s=0,m=0;
float cbar=100,ebar=87.5,lbar=75,gbar=62.5,gfbar=55,dbar=42.5,mv=0.01,timebar=0.0022;
//function declaring
void time();
void swap(int x1,int x2, int y1,int y2);
void match();

struct tile
     {
        int x=0,y=0,diff=0;
        tile(){}
     }array_grid[8][8];


int main()
{
   int ts = 54,i=0,j=0,k=0,x1=0,y1=0,x2=0,y2=0,click=0; //tile size 
   Vector2i offset(48,24);
   srand(time(0));
   RenderWindow app(VideoMode(1920,1080),"Menagerie");
   Texture menu;
   menu.loadFromFile("menu.png");
   Sprite in(menu);
   in.scale(Vector2f(4,4.4));
   app.draw(in);
    app.display();
   
    for(i=0;i<8;i++){
       for(j=0;j<8;j++){
          array_grid[i][j].diff=rand()%6;
          array_grid[i][j].x=j*ts;
          array_grid[i][j].y=i*ts;
       }   
    } 
//Menu 
    Event e1;
    while (app.isOpen())
    {
    while(app.pollEvent(e1))
    {
    if (e1.type==Event::Closed)
    app.close();
    }
    
    // Normal Mode 
    if(Keyboard::isKeyPressed(Keyboard::Num1))
    {
    RenderWindow app(VideoMode(900,1000), "Normal Mode");
    app.setFramerateLimit(60);
    Texture t1,t2;
    t1.loadFromFile("background.png");
    t2.loadFromFile("gems.png");
    Sprite background(t1), gems(t2);
    Event e;
    while (app.isOpen()){
//-------------------------------------Calling match function---------------------------------------
    match();
    if(moves==40){
        camel=0;
          elephant=0;
          lion=0;
          goat=0;
          giraffe=0;
          dear=0;
          }
          
    while (app.pollEvent(e)){
    if ((e.type == Event::Closed)||(moves==0))
                app.close();
                if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left){
        //code of action to be performed on mouse click
                    click++;
                     
                    if(click==1){
                    x1=(Mouse::getPosition(app).x);
                    y1=(Mouse::getPosition(app).y);
                    
                    }
                    
                    if(click==2){
                    x2=(Mouse::getPosition(app).x);
                    y2=(Mouse::getPosition(app).y);
                   
                    click=0;
                    moves=moves-1;
                    mv=mv+0.01;
	                    
//--------------------------------------------Calling Swaping function---------------------------------
                    swap(x1,x2,y1,y2);
                    }                    
                }
             }
//game over screen loader  
if((moves==0)&&!((camel>=8000)&&(elephant>=7000)&&(lion>=6000)&&(goat>=5000)&&(giraffe>=4000)&&(dear>=3000)))
 {
   RenderWindow app(VideoMode(1366,768),"Game End");
   Texture menu;
   menu.loadFromFile("lost.png");
   Sprite in(menu);
   in.scale(Vector2f(4,4.4));
   app.draw(in);
   app.display();
   Event eo;
    while (app.isOpen())
    {
    while(app.pollEvent(eo))
    {
    if (eo.type==Event::Closed)
    app.close();
    }}
}
//Next level move
if((camel>=8000)&&(elephant>=7000)&&(lion>=6000)&&(goat>=5000)&&(giraffe>=4000)&&(dear>=3000)){
goto ab;
}
    
    
    app.draw(background);    
    for(i=0;i<8;i++){
       for(j=0;j<8;j++){
           tile t=array_grid[i][j];
           gems.setTextureRect(IntRect(t.diff*49,0,47,48));
           gems.setPosition(t.x,t.y);
           app.draw(gems);
       }
    }
//========================================================================================              
 //-----------------------------Bars ---------------------------------=--------------
//=======================================================================================
// ---------------------------Camel Bar---------------------------------------------------
//=======================================================================================
     Texture Bar1;
     Bar1.loadFromFile("bar.png");
     Sprite bar1(Bar1);
     bar1.setPosition(280 , 560);
     bar1.setScale(0.04*(cbar/800), 0.15);
       app.draw(bar1);
       
    app.display(); 
     if(camel<8000)
     {
    cbar=camel;
     }
     
    //=====================================Elephant============================================
     Texture Bar2;
     Bar2.loadFromFile("bar.png");
     Sprite bar2(Bar2);
     bar2.setPosition(280 , 625);
     bar2.setScale(0.04*(ebar/700), 0.15);
       app.draw(bar2);
    app.display();
    if(elephant<=7000)
    ebar=elephant;
    
    //=================================Lion===============================================
    //camel=0,elephant=0,lion=0,goat=0,giraffe=0,dear=0
     Texture Bar3;
     Bar3.loadFromFile("bar.png");
     Sprite bar3(Bar3);
     bar3.setPosition(280 , 690);
     bar3.setScale(0.04*(lbar/600), 0.15);
       app.draw(bar3);
    app.display();
   if(lion<=6000)
    lbar=lion;
    //=======================================goat==========================================
     Texture Bar4;
     Bar4.loadFromFile("bar.png");
     Sprite bar4(Bar4);
     bar4.setPosition(280 , 757);
     bar4.setScale(0.04*(gbar/500), 0.15);
       app.draw(bar4);
    app.display();
    if(goat<=5000)
    gbar=goat;
    //=====================================giraffe======================================
     Texture Bar5;
     Bar5.loadFromFile("bar.png");
     Sprite bar5(Bar5);
     bar5.setPosition(280 , 822);
     bar5.setScale(0.04*(gfbar/400), 0.15);
     app.draw(bar5);
    app.display();
    if(giraffe<=4000)
    gfbar=giraffe;
    //=========================================dear====================================
     Texture Bar6;
     Bar6.loadFromFile("bar.png");
     Sprite bar6(Bar6);
     bar6.setPosition(280 , 890);
     bar6.setScale(0.04*(dbar/300), 0.15);
       app.draw(bar6);
    app.display();
    if(dear<=3000)
    dbar=dear;
    
   // ======================================moves=======================================
        Texture Bar7;
     Bar7.loadFromFile("bar.png");
     Sprite bar7(Bar7);
     bar7.setPosition(280 ,967);
      
   
     bar7.setScale(mv, 0.15);
   
     
       app.draw(bar7);
    app.display();
  
    
    // ===================================== outline ==================================

    
     Font font;
  font.loadFromFile("fnt.ttf");
 
 Text text;
text.setFont(font); 


text.setString("\n\nCamel Score Bar : \n\nElephant Score Bar: \n\nCheetah Score Bar: \n\nSheep Score bar: \n\nGiraffe Score Bar: \n\nDeer Score bar: \n\nTotal Moves : ");
text.setCharacterSize(30);
text.setFillColor(Color::Blue);
 text.setPosition(10,480);
text.setStyle(Text::Underlined);
    
 app.draw(text);
    
    
    
    //======================================================================
    app.display();
    cout<<endl<<endl<<endl;
    cout<<"Camel = "<<camel<<endl;
    cout<<"Elephant = "<<elephant<<endl;
    cout<<"lion = "<<lion<<endl;
    cout<<"Goat = "<<goat<<endl;
    cout<<"Giraffe = "<<giraffe<<endl;
    cout<<"dear = "<<dear<<endl;
    cout<<"Moves = "<<moves<<endl;
    }
  }
//normal mode end  

	

//second mode
     else if(Keyboard::isKeyPressed(Keyboard::Num2))
      {   
          ab://goto
        int flag=1;
       camel=4000,elephant=3500,lion=3000,goat=2500,giraffe=2000,dear=1500;
        
          RenderWindow app(VideoMode(1000,1000), "Time trial Mode");
    app.setFramerateLimit(60);
    Texture t1,t2;
    t1.loadFromFile("background.png");
    t2.loadFromFile("gems.png");
    Sprite background(t1), gems(t2);
    Event e;
    while (app.isOpen()){
            
//-------------------------------------Calling match function---------------------------------------
    match();
    while (app.pollEvent(e)){
    if ((e.type == Event::Closed)||(m==3))
                app.close();
                if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left){
        
                    click++;flag++; 
                    if(click==1){
                    x1=(Mouse::getPosition(app).x);
                    y1=(Mouse::getPosition(app).y);
              
                    }
                    
                    if(click==2){
                    x2=(Mouse::getPosition(app).x);
                    y2=(Mouse::getPosition(app).y);
                  
                    click=0;
                    flag++;    
//--------------------------------------------Calling Swaping function---------------------------------
                    swap(x1,x2,y1,y2);
                    }     
                               
                }
                }
            
    if((camel>=8000)&&(elephant>=7000)&&(lion>=6000)&&(goat>=5000)&&(giraffe>=4000)&&(dear>=3000))
    {
    // ________________________________________ game won_______________________________________________________________
      RenderWindow app(VideoMode(1366,768),"Game won");
   Texture menu;
   menu.loadFromFile("win.png");
   Sprite in(menu);
   in.scale(Vector2f(4,4.4));
   app.draw(in);
   app.display();
   Event eo;
    while (app.isOpen())
    {
    while(app.pollEvent(eo))
    {
    if (eo.type==Event::Closed)
    app.close();
    }}
     
    }
    
    if(s>180)
    {
     RenderWindow app(VideoMode(1366,768),"Game End");
   Texture menu;
   menu.loadFromFile("lost.png");
   Sprite in(menu);
   in.scale(Vector2f(4,4.4));
   app.draw(in);
   app.display();
   Event eo;
    while (app.isOpen())
    {
    while(app.pollEvent(eo))
    {
    if (eo.type==Event::Closed)
    app.close();
    }}
    
    }
    app.draw(background);    
    for(i=0;i<8;i++){
       for(j=0;j<8;j++){
           tile t=array_grid[i][j];
           gems.setTextureRect(IntRect(t.diff*49,0,47,48));
           gems.setPosition(t.x,t.y);
           app.draw(gems);
       }
    }
    if(flag==1)
      camel=4000,elephant=3500,lion=3000,goat=2500,giraffe=2000,dear=1500;
//========================================================================================              
 //-----------------------------Bars ---------------------------------=--------------
//=======================================================================================
// ---------------------------Camel Bar---------------------------------------------------
//=======================================================================================
     Texture Bar1;
     Bar1.loadFromFile("bar.png");
     Sprite bar1(Bar1);
     bar1.setPosition(280 , 560);
     bar1.setScale(0.04*(cbar/800), 0.15);
       app.draw(bar1);
       
    app.display(); 
     if(camel<8000)
     {
    cbar=camel;
     }
     
    //=====================================Elephant============================================
     Texture Bar2;
     Bar2.loadFromFile("bar.png");
     Sprite bar2(Bar2);
     bar2.setPosition(280 , 625);
     bar2.setScale(0.04*(ebar/700), 0.15);
       app.draw(bar2);
    app.display();
    if(elephant<=7000)
    ebar=elephant;
    
    //=================================Lion===============================================
    
     Texture Bar3;
     Bar3.loadFromFile("bar.png");
     Sprite bar3(Bar3);
     bar3.setPosition(280 , 690);
     bar3.setScale(0.04*(lbar/600), 0.15);
       app.draw(bar3);
    app.display();
   if(lion<=6000)
    lbar=lion;
    //=======================================goat==========================================
     Texture Bar4;
     Bar4.loadFromFile("bar.png");
     Sprite bar4(Bar4);
     bar4.setPosition(280 , 757);
     bar4.setScale(0.04*(gbar/500), 0.15);
       app.draw(bar4);
    app.display();
    if(goat<=5000)
    gbar=goat;
    //=====================================giraffe======================================
     Texture Bar5;
     Bar5.loadFromFile("bar.png");
     Sprite bar5(Bar5);
     bar5.setPosition(280 , 822);
     bar5.setScale(0.04*(gfbar/400), 0.15);
     app.draw(bar5);
    app.display();
    if(giraffe<=4000)
    gfbar=giraffe;
    //=========================================dear====================================
     Texture Bar6;
     Bar6.loadFromFile("bar.png");
     Sprite bar6(Bar6);
     bar6.setPosition(280 , 890);
     bar6.setScale(0.04*(dbar/300), 0.15);
       app.draw(bar6);
    app.display();
    if(dear<=3000)
    dbar=dear;
    
   // ======================================time=======================================
        Texture Bar7;
     Bar7.loadFromFile("bar.png");
     Sprite bar7(Bar7);
     bar7.setPosition(280 ,957);
      
   
     bar7.setScale( timebar*1.0010, 0.15);
   
  
       app.draw(bar7);
    app.display();
  
    
    // ===================================== outline ==================================

    
     Font font;
  font.loadFromFile("fnt.ttf");
 
 Text text;
text.setFont(font); 


text.setString("\n\nCamel Score Bar : \n\nElephant Score Bar: \n\nCheetah Score Bar: \n\nSheep Score bar: \n\nGiraffe Score Bar: \n\nDeer Score bar: \n\nTotal Time : ");
text.setCharacterSize(30);
text.setFillColor(Color::Blue);
 text.setPosition(10,480);
text.setStyle(Text::Underlined);
    
 app.draw(text);
    
    
    //====================================================
    app.display();
     cout<<endl<<endl<<endl;
    cout<<"Camel = "<<camel<<endl;
    cout<<"Elephant = "<<elephant<<endl;
    cout<<"lion = "<<lion<<endl;
    cout<<"Goat = "<<goat<<endl;
    cout<<"Giraffe = "<<giraffe<<endl;
    cout<<"dear = "<<dear<<endl;
    cout<<"Moves = "<<moves<<endl;
    
    
//---------------------------------------time function calling------------------------------------------- 
    time();
    }
  }
//second mode end
}

              
return 0;} 
  
     




//match fuction defining    
void match(){
int i,j,k,z1,z2,end=3;;
//check match
//horizontal
for(i=0;i<8;i++){
   for(j=0;j<8;j++){
        if((array_grid[i][j].diff==array_grid[i][j+1].diff)&&(array_grid[i][j].diff==array_grid[i][j+2].diff)){
              if(array_grid[i][j].diff==array_grid[i][j+3].diff){
               end++;             
                 if(array_grid[i][j].diff==array_grid[i][j+4].diff){
                  end++;
                  }
              }
               
             {
             if(array_grid[i][j].diff==0){camel=camel+(300*end);}        
             else if(array_grid[i][j].diff==1){elephant=elephant+(280*end);}
             else if(array_grid[i][j].diff==2){lion=lion+(260*end);}
             else if(array_grid[i][j].diff==3){goat=goat+(240*end);}
             else if(array_grid[i][j].diff==4){giraffe=giraffe+(220*end);}
             else if(array_grid[i][j].diff==5){dear=dear+(200*end);}
             }
             
           z1=i;
           while(z1!=0)
           {       array_grid[z1][j].diff= array_grid[z1-1][j].diff;
                   array_grid[z1][j+1].diff= array_grid[z1-1][j+1].diff;
                   array_grid[z1][j+2].diff= array_grid[z1-1][j+2].diff;
                   if(end==4){
                   array_grid[z1][j+3].diff= array_grid[z1-1][j+3].diff;
                   if(end==5){
                   array_grid[z1][j+4].diff= array_grid[z1-1][j+4].diff;
                   if(end==6){
                   array_grid[z1][j+5].diff= array_grid[z1-1][j+5].diff;
                   }
                   }
                   }
                   z1--;
           }
           if(z1==0) 
               {
                 for(k=0;k<end;k++){
                    array_grid[z1][j+k].diff=rand()%6;
                 } 
           }
       }
   }
}
//vertical
for(i=0;i<8;i++){
   for(j=0;j<8;j++){

//for 5 tiles match
if((array_grid[i][j].diff==array_grid[i+1][j].diff)&&(array_grid[i][j].diff==array_grid[i+2][j].diff)&&(array_grid[i][j].diff==array_grid[i+3][j].diff)&&(array_grid[i][j].diff==array_grid[i+4][j].diff))
    {
//count 5
               {
                 if(array_grid[i][j].diff==0){camel=camel+(300*5);}        
                 else if(array_grid[i][j].diff==1){elephant=elephant+(280*5);}
                 else if(array_grid[i][j].diff==2){lion=lion+(260*5);}
                 else if(array_grid[i][j].diff==3){goat=goat+(240*5);}
                 else if(array_grid[i][j].diff==4){giraffe=giraffe+(220*5);}
                 else if(array_grid[i][j].diff==5){dear=dear+(200*5);}
               }
        z2=i;
        
           
         if(z2>=0)
           {
               if(z2==0)
                {	
                    array_grid[z2][j].diff=rand()%6;
                    array_grid[z2+1][j].diff=rand()%6;
                    array_grid[z2+2][j].diff=rand()%6;
                    array_grid[z2+3][j].diff=rand()%6;
                    array_grid[z2+4][j].diff=rand()%6;
                }
               else if(z2==1)
               {
                    array_grid[z2][j].diff=rand()%6;
                    array_grid[z2+1][j].diff=rand()%6;
                    array_grid[z2+2][j].diff= rand()%6;
                    array_grid[z2+3][j].diff= rand()%6;
                    array_grid[z2+4][j].diff=array_grid[z2-1][j].diff;  
               }
                else if(z2==2)
               {
                    array_grid[z2][j].diff=rand()%6;
                    array_grid[z2+1][j].diff=rand()%6;
                    array_grid[z2+2][j].diff=rand()%6;
                    array_grid[z2+3][j].diff=array_grid[z2-2][j].diff;
                    array_grid[z2+4][j].diff= array_grid[z2-1][j].diff;                                  
               }
               
               else if(z2==3)
               {
                    array_grid[z2][j].diff=rand()%6;
                    array_grid[z2+1][j].diff=rand()%6;
                    array_grid[z2+2][j].diff=array_grid[z2-3][j].diff;
                    array_grid[z2+3][j].diff=array_grid[z2-2][j].diff;
                    array_grid[z2+4][j].diff= array_grid[z2-1][j].diff;           
               }
                
               
           for (k=z2;k>=0;k--)
               {               
               array_grid[k][j].diff=rand()%6;
               }   
               }
                                                           
}


// for 4 tiles match vertical
else if((array_grid[i][j].diff==array_grid[i+1][j].diff)&&(array_grid[i][j].diff==array_grid[i+2][j].diff)&&(array_grid[i][j].diff==array_grid[i+3][j].diff))
        {
//count 4
                 {
                    if(array_grid[i][j].diff==0){camel=camel+(300*4);}        
                    else if(array_grid[i][j].diff==1){elephant=elephant+(280*4);}
                    else if(array_grid[i][j].diff==2){lion=lion+(260*4);}
                    else if(array_grid[i][j].diff==3){goat=goat+(240*4);}
                    else if(array_grid[i][j].diff==4){giraffe=giraffe+(220*4);}
                    else if(array_grid[i][j].diff==5){dear=dear+(200*4);} 
                 }  
         z2=i;
        
         if(z2>=0)
           {
                if(z2==0)
                {
                     array_grid[z2][j].diff=rand()%6;
                     array_grid[z2+1][j].diff=rand()%6;
                     array_grid[z2+2][j].diff=rand()%6;
                     array_grid[z2+3][j].diff=rand()%6;  
                }
               else if(z2==1)
               {
                     array_grid[z2][j].diff=rand()%6;
                     array_grid[z2+1][j].diff=rand()%6;
                     array_grid[z2+2][j].diff= rand()%6;
                     array_grid[z2+3][j].diff=array_grid[z2-1][j].diff;                                
               }
                else if(z2==2)
               {
                     array_grid[z2][j].diff=rand()%6;
                     array_grid[z2+1][j].diff=rand()%6;
                     array_grid[z2+2][j].diff=array_grid[z2-2][j].diff;
                     array_grid[z2+3][j].diff= array_grid[z2-1][j].diff;
               }
             else if(z2==3)
               {
                     array_grid[z2][j].diff=rand()%6;
                     array_grid[z2+1][j].diff=array_grid[z2-3][j].diff;
                     array_grid[z2+2][j].diff=array_grid[z2-2][j].diff;
                     array_grid[z2+3][j].diff= array_grid[z2-1][j].diff;
               }                
              else if(z2==4)
               {
                     array_grid[z2][j].diff=array_grid[z2-4][j].diff;
                     array_grid[z2+1][j].diff=array_grid[z2-3][j].diff;
                     array_grid[z2+2][j].diff=array_grid[z2-2][j].diff;
                     array_grid[z2+3][j].diff= array_grid[z2-1][j].diff;                            
               }
               for (k=z2;k>=0;k--)
               {
               array_grid[k][j].diff=rand()%6;
               }
       }
    }

      
//3 tiles          
else if((array_grid[i][j].diff==array_grid[i+1][j].diff)&&(array_grid[i][j].diff==array_grid[i+2][j].diff)){
//count 3
           {
             if(array_grid[i][j].diff==0){camel=camel+(300*3);}        
             else if(array_grid[i][j].diff==1){elephant=elephant+(280*3);}
             else if(array_grid[i][j].diff==2){lion=lion+(260*3);}
             else if(array_grid[i][j].diff==3){goat=goat+(240*3);}
             else if(array_grid[i][j].diff==4){giraffe=giraffe+(220*3);}
             else if(array_grid[i][j].diff==5){dear=dear+(200*3);}
           }   

           z2=i;
           bool check=1;
         while(z2>=0)
           {
                if(z2==0)
                {
                    array_grid[z2][j].diff=rand()%6;
                    array_grid[z2+1][j].diff=rand()%6;
                    array_grid[z2+2][j].diff=rand()%6;
                    check=0;
                    break;
                }
                if(z2==1)
               {
                    array_grid[z2][j].diff=rand()%6;
                    array_grid[z2+1][j].diff=rand()%6;
                    array_grid[z2+2][j].diff= array_grid[z2-1][j].diff;
                    check=0;
                    break;
               }
                if(z2==2)
               {
                    array_grid[z2][j].diff=rand()%6;
                    array_grid[z2+1][j].diff=array_grid[z2-2][j].diff;
                    array_grid[z2+2][j].diff= array_grid[z2-1][j].diff;
                    check=0;
                    break;
               }
               array_grid[z2+2][j].diff= array_grid[z2-1][j].diff;
               z2--;
                                 
}
         if(check==1)
         {
           for(k=0;k<3;k++)
           {        
            array_grid[k][j].diff=rand()%6;
           }}      
     }}     
   }

}




//swap fuction defining 
void swap(int x1,int x2, int y1,int y2){
//r1,r2,c1,c3 column and row finder
//exchange used for swaping
//max_x and max_y used to ristrict swap around limited area
int r1=0,r2=0,c1=0,c2=0,exchange=0,max_x=0,max_y=0,i=0,j=0;
r1=(x1/54);
r2=(x2/54);
c1=(y1/54);
c2=(y2/54);
max_x=r1-r2;
max_y=c1-c2;
//ristrict movement
if(((max_x==1)&&(max_y==0))||((max_x==0)&&(max_y==1))||((max_x==-1)&&(max_y==0))||((max_x==0)&&(max_y==-1))){
       exchange=array_grid[c1][r1].diff;
       array_grid[c1][r1].diff=array_grid[c2][r2].diff;
       array_grid[c2][r2].diff=exchange;
//swap back if no min 3 match found
   if((((array_grid[c2][r2].diff==array_grid[c2-1][r2].diff)&&(array_grid[c2][r2].diff==array_grid[c2-2][r2].diff))||((array_grid[c2]  [r2].diff==array_grid[c2+1][r2].diff)&&(array_grid[c2][r2].diff==array_grid[c2+2][r2].diff))||((array_grid[c2][r2].diff==array_grid[c2][r2-1].diff)&&(array_grid[c2][r2].diff==array_grid[c2][r2-2].diff))||((array_grid[c2][r2].diff==array_grid[c2][r2+1].diff)&&(array_grid[c2][r2].diff==array_grid[c2][r2+2].diff))||((array_grid[c2][r2].diff==array_grid[c2][r2-1].diff)&&(array_grid[c2][r2].diff==array_grid[c2][r2+1].diff))||((array_grid[c2][r2].diff==array_grid[c2-1][r2].diff)&&(array_grid[c2][r2].diff==array_grid[c2+1][r2].diff))))
     {
     
     }
     else
     {
     exchange=array_grid[c2][r2].diff;
     array_grid[c2][r2].diff=array_grid[c1][r1].diff;
     array_grid[c1][r1].diff=exchange;
     } 
}
}




void time(){
//---------------------------------------time calcilation-------------------------------------------            
    ms++;
    if(ms==6){
    s++;
    timebar=timebar+0.0022;
    ms=0;
  
    }
}

