#include <iostream>
#include <vector>     

/* Pattern observer, for example, allows to simplify model and view 
interactions sometimes. Let us have a canvas, that renders
the scene with some objects First of all, let us have our basic 
classes for observer pattern */

/* Determines observer classses that will observe some other classes
being updated */

class Observer
{
public:
    virtual void update() = 0;
};

/* Determines classes that will be observed by the observer. Notifies the
observer if some data was changed. */
class Observable
{
public:
   void addObserver(Observer *observer)
   {
      _observers.push_back(observer);
   }
   void notifyUpdate()
   {
      int size = _observers.size();
      for (int i = 0; i < size; i++)
      {
         _observers[i]->update();
      }
   }
private:
   std::vector<Observer*> _observers;
};

/* In model */

class Model : public Observable
{ 
private:
   Color color;
   Geometry geometry;
public:
   Geometry get3DGeometry()
   {
      return geometry;
   }
   Color getColor()
   {
      return currentColor;
   }
   void setColor(Color color)
   { 
      currentColor = color;
      notifyUpdate();
   }
};

/* In View */

class SomeViewWithCanvas: public Observer
{
private:
    Canvas canvas;
    GeometryObject *someObject;
//<...>
public:
//<...>
    SomeViewWithCanvas(GeometryObject *obj) 
    {
        someObject = obj;
        someObject->addObserver(this);
        //<...>
    }
    virtual void update()
    {
        //<...>
        canvas.renderObject(someObject->get3DGeometry(), someObject->get3DColor());
    }
};

/* Now if the color of the object is changed, the canvas (or canvases
if there are multiple of them) will be updated as well */
