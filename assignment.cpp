# include "iGraphics.h"
# include "math.h"
# include "string.h"

int X=1000, Y=400;

int xo=400,yo=150,bxo=450,byo=100,dbx=260,dby=20;
int dx=60, dy=50, sp=20, th=5;
int h,mnt,s,i,d[6],e[6],mode=0,hour;

int cx=20, cy=300;
int y,m,day,n,year,month,len_yr,len_mn,j,k,hc, check=0, ec=60;
char yr[20],mn[2];
char ch[32][3]= {" 0"," 1"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10","11","12","13","14","15",
					"16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
char name[13][11]={"Invalid","  JANUARY,"," FEBRUARY,","    MARCH,","    APRIL,","      MAY,","     JUNE,",
					"     JULY,","   AUGUST,","SEPTEMBER,"," OCTOBER,"," NOVEMBER,"," DECEMBER,"};

//function iDraw() is called again and again by the system
void iDraw()
{
	/*
	void iText(GLdouble x, GLdouble y, char *str, void* font=GLUT_BITMAP_8_BY_13)
	Description: Displays a string on screen.
	Parameters: x, y- coordinates of the first character of the string,
				str- The string to show,
				font- (Optional)Specifies the font type.
	FONT values must be any one of the following-
	{GLUT_BITMAP_HELVETICA_10, GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_10,
	 GLUT_BITMAP_HELVETICA_12, GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_24,
	 GLUT_BITMAP_HELVETICA_18}
	*/
    //place your drawing codes here

	iClear();

	iSetColor(100, 100, 100);
	iFilledRectangle(bxo, byo, dbx, dby);

	iSetColor(255, 255, 255);
	iText(bxo+5,byo+7,"Click to change time format",GLUT_BITMAP_9_BY_15);

	iSetColor(0, 255, 255);
	
	iText(cx, cy, "Enter year:");
	iRectangle(cx, cy-30, 160, 20);
	iText(cx+5, cy-25, yr);
	
	if(check==1 || check==2) {
		iText(cx+200, cy, "Enter month:");
		iRectangle(cx+200, cy-30, 100, 20);
		iText(cx+205, cy-25, mn);
	}

	if(check==2 && (month<1 || month>12 || year<1)) {
		iText(cx+8, cy-50, "Invalid  input");
		iText(cx+8, cy-70, "press ''INSERT'' to try again");
	}

    if(check==2 && month>0 && month<13 && year>0) {
		iText(cx+80, cy-ec, name[month]);
		iText(cx+160, cy-ec, yr);
		iText(cx-5, cy-80, " SAT   SUN   MON   TUE   WED   THU   FRI");

		hc=cy-100;

		for(k=1,j=0;k<=n;k++,j++) {
    		iText(cx+5+48*(day+j), hc, ch[k]);
    		if(day+j==6) j-=7,hc-=20;
		}
		iText(cx+5, hc-20, "press ''INSERT'' to try again");
	}

	iSetColor(0, 255, 0);

	iPoint(xo+2*(dx+sp)+4*th, yo+th, th);
	iPoint(xo+2*(dx+sp)+4*th, yo+2*(dy+th), th);
	iPoint(xo+4*dx+5*sp+8*th, yo+th, th);
	iPoint(xo+4*dx+5*sp+8*th, yo+2*(dy+th), th);

	for(i=0;i<6;i++){
		if(d[i]==0 || d[i]==2 || d[i]==3 || d[i]==5 || d[i]==6 || d[i]==7 || d[i]==8 || d[i]==9)
			iFilledRectangle(e[i]+th,    yo+2*(dy+th), dx, th);
		
		if(d[i]==0 || d[i]==4 || d[i]==5 || d[i]==6 || d[i]==8 || d[i]==9)
			iFilledRectangle(e[i],       yo+dy+2*th,   th, dy);
		
		if(d[i]==0 || d[i]==1 || d[i]==2 || d[i]==3 || d[i]==4 || d[i]==7 || d[i]==8 || d[i]==9)
			iFilledRectangle(e[i]+dx+th, yo+dy+2*th,   th, dy);
		
		if(d[i]==2 || d[i]==3 || d[i]==4 || d[i]==5 || d[i]==6 || d[i]==8 || d[i]==9)
			iFilledRectangle(e[i]+th,    yo+dy+th,     dx, th);
		
		if(d[i]==0 || d[i]==2 || d[i]==6 || d[i]==8)
			iFilledRectangle(e[i],       yo+th,        th, dy);
		
		if(d[i]==0 || d[i]==1 || d[i]==3 || d[i]==4 || d[i]==5 || d[i]==6 || d[i]==7 || d[i]==8 ||d[i]==9)
			iFilledRectangle(e[i]+dx+th, yo+th,        th, dy);
		
		if(d[i]==0 || d[i]==2 || d[i]==3 || d[i]==5 || d[i]==6 || d[i]==8 || d[i]==9)
			iFilledRectangle(e[i]+th,    yo,           dx, th);
	}

	if(mode==1) {
		if(hour<12) {
			iText(xo, yo-30, "AM", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else {
			iText(xo, yo-30, "PM", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
    
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx >= bxo && mx <= (bxo+dbx) && my >= byo && my <= (byo+dby)) {
			if(mode==0)mode++;
			else mode--;
		}
		//printf("%d\n",h);
	}

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
    	//place your codes here

    }
    
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
    //if enter pressed, save the input string

    if(check==0)
    {
        if(key == '\r')
        {
            y=atoi(yr);
            //printf("%d\n",y);
            check++;
        }

        //if backspace pressed, delete last character
        else if(key=='\b')
        {
            if(len_yr>0)
            {
                len_yr--;
                yr[len_yr]=0;
            }
        }

        else
        {
            yr[len_yr] = key;
            len_yr++;
        }
    }

    else if(check==1)
    {
        if(key == '\r')
        {
            m=atoi(mn);
            check++;
            
			if(m==4 || m==6 || m==9 || m==11) n=30;
            else n=31;
            if(m==2){
                if((y%400==0)||(y%100!=0 && y%4==0)) n=29;
                else n=28;
            }
            
			year=y,month=m;
            
			if(m<=2) y--,m=m+12;
            
			day=1+floor(26*(m+1)/10)+y+floor(y/4)+6*floor(y/100)+floor(y/400);
            day%=7;

        }

        //if backspace pressed, delete last character
        else if(key=='\b')
        {
            if(len_mn>0)
            {
                len_mn--;
                mn[len_mn]=0;
            }
        }

        else
        {
            mn[len_mn] = key;
            len_mn++;
        }
    }

	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{
    
    if (key == GLUT_KEY_INSERT) {
    	check=0;
		for(k=0;k<20;k++) yr[k]=0;
		mn[0]=0,mn[1]=0;
		len_yr=0;
		len_mn=0;
    }
    //place your codes for other keys here    
}

void func(void) {
	//code of the task that will be repeated. 
	time_t now;
	struct tm *now_tm;

    now = time(NULL);
	now_tm = localtime(&now);
    hour = now_tm->tm_hour;
    mnt = now_tm->tm_min;
    s = now_tm->tm_sec;

	h=hour;

	if(mode==0) h=hour;
	else if(mode==1) {
		if(hour==0) h=12;
		else if(hour>12) h=hour-12;
	}

	d[0]=h/10,d[1]=h%10,d[2]=mnt/10,d[3]=mnt%10,d[4]=s/10,d[5]=s%10;
	
	e[0]=xo;
	e[1]=e[0]+dx+sp+2*th; e[2]=e[1]+dx+2*(sp+th);
	e[3]=e[2]+dx+sp+2*th; e[4]=e[3]+dx+2*(sp+th);
	e[5]=e[4]+dx+sp+2*th;	
}

int main()
{
    len_yr = 0;
    len_mn = 0;
    yr[0] = 0;
    mn[0] = 0;

	iSetTimer(100, func);

    iInitialize(X, Y, "Calendar & Digital Clock");
    
    return 0;
}
