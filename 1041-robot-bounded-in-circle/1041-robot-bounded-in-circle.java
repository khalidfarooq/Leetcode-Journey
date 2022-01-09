class Solution {
    public boolean isRobotBounded(String str) 
    {
        
        /*        
           N
           |
        W<-O->E
           |
           S
        */
        
        
        int x=0;
        int y=0;
        
        int north = 0;
        int east = 1;
        int south = 2;
        int west = 3;
        
        int direction = north; //north;
        
        for(char ch:str.toCharArray())
        {
            if(ch=='G')
            {
                if(direction==north)
                y++;
                else if(direction==south)
                y--;
                else if(direction==east)
                x++;
                else
                x--;
            }
            else if(ch=='L')
            {
                if(direction==north)
                direction=west;
                else if(direction==east)
                direction=north;
                else if(direction==south)
                direction=east;
                else
                direction=south;
            }
            else
            {
                if(direction==north)
                direction=east;
                else if(direction==east)
                direction=south;
                else if(direction==south)
                direction=west;
                else
                direction=north;
            }
        }
        
        if(x==0 && y==0)
        return true;
        
        if(direction==north)
        return false;
        
        return true;
       
        
    }
}