//Save the Princess by Tristan S-M

int level = 1;
//int level = 2;
//int level = 3;



int Xmario = 0;
int Ymario = 0;


struct point
{
  int x;
  int y;
  int direction;
};


Point minion1 = {4,3};
Point minion2 = {7,1};
Point minion3 = {7,4};
Point teleport1 = {0,7};
Point teleport2 = {1,6};
Point teleport3 = {3,7};
Point teleport4 = {3,1};

boolean gameOver = false;

void setup() 
{
  
  minion1 direction = 0;
  minion2 direction = 0;
  minion3 direction = 0;
}

void loop() 
{ 
  if (gameOver == false)
  {
    if (level == 1)
    {
      Drawlevel1();
    }
    //if (level == 2)
    {
    //  DrawLevel2();
    }
    //if (level == 3)
    {
    //  DrawLevel3();
    }

    drawmario();
    drawMinion();
    drawtelportation();
    updateMario();
    updateminion1();
    updateminion2();
    updateminion3();
    purposeteleportation();

    //Checks to see if mario/player collides with minions
    if (collide())
    {
      Tone_Start(50000000,100);
      gameOver = true;
    }
  }

  else gameOverScreen();
}




void Drawlevel1()  //maze walls for the first level
{
  
  

  DrawPx(1,7,6); //maze walls of level 1
  DrawPx(1,0,6);
  DrawPx(1,1,6);

  DrawPx(2,6,6);
  DrawPx(2,5,6);
  DrawPx(2,2,6);
  DrawPx(2,3,6);
  DrawPx(2,4,6);
  DrawPx(2,1,6);

  DrawPx(3,4,5);  //Hiding Spot
  DrawPx(3,5,6);
  DrawPx(3,2,6);

  DrawPx(4,7,6);
  DrawPx(4,0,6);
  DrawPx(4,1,6);
  DrawPx(4,2,6);

  DrawPx(5,1,6);
  DrawPx(5,2,6);
  DrawPx(5,3,6);
  DrawPx(5,5,6);
  DrawPx(5,6,6);

  DrawPx(6,1,6)
  DrawPx(6,4,6);
  DrawPx(6,5,6);
  DrawPx(6,3,6);
  DrawPx(6,2,5);    //Hiding Spot


  DrawPx(7,7,7);  //dot that you eat to the next level

  DisplaySlate();

}

//void Drawlevel2() //draws the second level to the game slate


  
  //DrawPx(0,2,6); //maze walls for the first level
  //DrawPx(0,3,6);
  //DrawPx(0,4,6);

  //DrawPx(1,0,6);
  //DrawPx(1,2,6);
  //DrawPx(1,6,6);

  //DrawPx(2,2,6);
  //DrawPx(2,4,5);     //Hiding spot
  //DrawPx(2,5,6); 

  //DrawPx(3,1,6);
  //DrawPx(3,2,6);
  //DrawPx(3,4,6);
  //DrawPx(3,5,6);
  //DrawPx(3,7,6);
 
  //DrawPx(4,4,6);
  //DrawPx(4,5,5);     //Hiding spot
  //DrawPx(4,7,6); 

  //DrawPx(5,0,6);
  //DrawPx(5,1,6); 
  //DrawPx(5,3,6);
  //DrawPx(5,7,6);

  //DrawPx(6,3,6);
  //DrawPx(6,5,6);
  //DrawPx(6,6,6);
  //DrawPx(6,7,6); 
  
  //DrawPx(7,0,6);
  //DrawPx(7,1,6);
  //DrawPx(7,3,6);
  //DrawPx(7,7,7); //dot that you eat to go to next level

  //updateMinion2();  


  //DisplaySlate();
  


//void Drawlevel3() //draws the third level to the game slate


  //DrawPx(1,0,6);  //maze walls of level 3
  //DrawPx(0,5,6);
  //DrawPx(1,3,6);
  //DrawPx(1,6,6);

  //DrawPx(2,0,6);
  //DrawPx(2,2,6);
  //DrawPx(2,3,6);
  //DrawPx(2,4,6); 
  //DrawPx(2,5,6);

  //DrawPx(3,1,6);
  //DrawPx(3,2,6);
  //DrawPx(3,5,6);
  //DrawPx(3,6,6);
  //DrawPx(3,7,6);

  //DrawPx(4,3,6);
  //DrawPx(4,4,6); 
  //DrawPx(4,7,6);

  //DrawPx(5,0,6);
  //DrawPx(5,2,6);
  //DrawPx(5,3,5);
  //DrawPx(5,1,6);
  //DrawPx(5,4,6);
  //DrawPx(5,6,6);
  
  //DrawPx(6,5,6);
  //DrawPx(6,4,5);
  //DrawPx(7,1,6); 
  //DrawPx(7,7,6);

  //DrawPx(5,7,8);

  //DrawPx(1,1,4);
  //DrawPx(1,6,4);
  //DrawPx(2,6,4);
  //DrawPx(4,2,4);
  //DrawPx(5,5,4);
  

  //DisplaySlate();
  



void updateMario()
{
  DrawPx(Xmario,Ymario,Red);
  //check to see if a button was pressed
   CheckButtonsDown();
    //If the righ arrow was pressed, add one to x.
    if (Button_Right && ReadPx(x + 1, y) == 5 || ReadPx(x + 1, y) == 7 || ReadPx(x + 1, y) == 8 || ReadPx(x + 1, y) == 2 || ReadPx(x + 1, y) == 4)
        {
          x= x + 1;
        }
    //If the left arrow was pressed, take one away from x.
    if (Button_Left && ReadPx(x - 1, y) == 5 || ReadPx(x - 1, y) == 7 || ReadPx(x - 1, y) == 8 || ReadPx(x - 1, y) == 2 || ReadPx(x - 1, y) == 4)
        {
          x= x - 1;
        }
     //If the up arrow was pressed, add one to y.
     if (Button_Up && ReadPx(y + 1, x) == 5 || ReadPx(y + 1, x) == 7 || ReadPx(y + 1, x) == 8 || ReadPx(y + 1, x) == 2 || ReadPx(y + 1, x) == 4)
        {
          y= y + 1;
        }
      //If the down arrow was pressed, take one away from y.
      if (Button_Down && ReadPx(y - 1, x) == 5 || ReadPx(y - 1, x) == 7 || ReadPx(y - 1, x) == 8 || ReadPx(y - 1, x) == 2 || ReadPx(y - 1, x) == 4)
        {
          y= y - 1;
        }

      if (y > 7)
        y = 7;
      if (y < 0)
        y = 0;
      if (x < 0)
        x = 0;
      if (x > 7)
        x = 7;

}

void drawtelportation()

{
  DrawPx(teleport1.x,teleport1.y,Green);
  DrawPx(teleport2.x,teleport2.y,Green);
  DrawPx(teleport3.x,teleport3.y,Green);
  DrawPx(teleport4.x,teleport4.y,Green);
  
}

void purposeteleportation()

{
  if (Xmario.x == teleport1.x && Ymario.y == teleport1.y)
   {
     Xmario = 2;
     Ymario = 0; 
   }
  if (Xmario.x == teleport2.x && Ymario.y == teleport2.y)
   {
     Xmario = 3;
     Ymario = 3;
   }
  if (Xmario.x == teleport3.x && Ymario.y == teleport3.y)
   {
     Xmario = 5;
     Ymario = 0;
   }
  if (Xmario.x == teleport4.x && Ymario.y == teleport4.y)
   {
     Xmario = 0;
     Ymario = 3;
   }
}

void drawMinion()
{
  DrawPx(minion1.x,minion1.y,DimOrange);
  DrawPx(minion2.x,minion2.y,DimOrange);
  DrawPx(minion3.x,minion3.y,DimOrange);
}

void updateminion1()
{
  if (minion1.direction == 0)
  {
    minion1.y = minion1.y + 1;
  }
  if (minion1.direction == 180)
  {
    minion1.y = minion1.y - 1;
  }
  if ((minion1.x = 4) && (minion1.y = 3))
  {
    direction = 0;
  }
  if ((minion1.x = 4) && (minion1.y = 5))
  {
    direction = 180;
  }
  
}

void updateminion2()
{
  if (minion2.direction == 0)
  {
    minion2.y = minion2.y + 1;
  }
  if (minion2.direction == 180)
  {
    minion2.y = minion2.y - 1;
  }
  if ((minion2.x = 7) && (minion2.y = 1))
  {
    direction = 0;
  }
  if ((minion2.x = 7) && (minion.y = 3))
  {
    direction = 180;
  }
}

void updateminion3()
{
  if (minion3.direction == 0)
  {
    minion3.y = minion3.y + 1;
  }
  if (minion3.direction == 180)
  {
    minion3.y = minion3.y - 1;
  }
  if ((minion3.x = 7) && (minion3.y = 4))
  {
    direction = 0;
  }
  if ((minion3.x = 7) && (minion3.y = 6))
  {
    direction = 180;
  }
}

//void updateMinion2()

{
  
}

boolean collide()

{
  if (Xmario.x == minion1.x && Ymario.y == minion1.y)
  {
    return true;
  }
  else
  {
    return false;     //If no collision, return false.
  }
  if (Xmario.x == minion2.x && Ymario.y == minion2.y)
  {
    return true;
  }
  else
  {
    return false;     //If no collision, return false.
  }
  if (Xmario.x == minion3.x && Ymario.y == minion2.y)
  {
    return true;
  }
  else
  {
    return false;     //If no collision, return false.
  }
}



void drawmario()
{
  DrawPx(Xmario,Ymario,Red);
}
void gameOverScreen()         //GameOver sign

{
  DrawPx(0,0,4White);
  DrawPx(1,1,White);
  DrawPx(2,2,White);
  DrawPx(3,3,White);
  DrawPx(4,4,White);
  DrawPx(5,5,White);
  DrawPx(6,6,White);
  DrawPx(7,7,White);
  DrawPx(0,7,White);
  DrawPx(1,6,White);
  DrawPx(2,5,White);
  DrawPx(3,4,White);
  DrawPx(4,3,White);
  DrawPx(5,2,White);
  DrawPx(6,1,White);
  DrawPx(7,0,White);
  DisplaySlate();
}

