#include <iostream>
#include <string>
using namespace std;

class Window
{
public:
   int leftTop[2];
   int rightBottom[2];
   unsigned int color = 0xffffff; // Default initialization
   Window()
   {
       leftTop[0] = 0;
       leftTop[1] = 0;
       rightBottom[0] = 100;
       rightBottom[1] = 100;
       color = 0xFFFFFF; // Explicit initialization in default constructor
   }
   Window(int x1, int y1, int x2, int y2) : color(0xFFFFFF) // Explicit initialization in parameterized constructor
   {
       leftTop[0] = x1;
       leftTop[1] = y1;
       rightBottom[0] = x2;
       rightBottom[1] = y2;
   }
   void setColor(unsigned int c)
   {
       color = c;
   }
   unsigned int getColor()
   {
       return color;
   }
   int getArea()
   {
       return (rightBottom[0] - leftTop[0]) * (rightBottom[1] - leftTop[1]);
   }
   void getCoordinates()
   {
       cout << "Coordinates: (" << leftTop[0] << ", " << leftTop[1] << ", "
           << rightBottom[0] << ", " << rightBottom[1] << ")\n";
   }
   ~Window() { cout << "Window destroyed\n"; }
};

class derivedWindow : public Window
{
private:
   string line;
public:
   derivedWindow() : Window()
   {
       line = "default";
   }
   derivedWindow(int x1, int y1, int x2, int y2) : Window(x1, y1, x2, y2)
   {
       line = "default";
   }
   void setLine(string l)
   {
       line = l;
   }
   string getLine()
   {
       return line;
   }
};

int main()
{
   Window window1(80, 80, 120, 120);
   window1.setColor(0xFFFFFF);
   window1.getCoordinates();
   cout << "Window area: " << window1.getArea() << endl;
   cout << "Window color: " << hex << window1.getColor() << endl;

   derivedWindow window2(100, 100, 200, 200); // Corrected coordinates
   window2.setColor(0xb6b6b6);
   window2.setLine("Window line");
   window2.getCoordinates();
   cout << "Derived window area: " << window2.getArea() << endl;
   cout << "Derived window color: " << hex << window2.getColor() << endl;
   cout << "Derived window line: " << window2.getLine() << endl;

   return 0;
}