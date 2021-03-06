#include "secretary.hpp"

void Secretary::attach(StockObserver observer)
{
  _observers.push_back(observer);
}

void Secretary::notify()
{
  std::cout <<"start notifying, stock observer number = " <<_observers.size() <<std::endl;

  for (std::list<StockObserver>::iterator iter = _observers.begin();
    iter != _observers.end();
    ++iter)
  {
    iter->update();
  }
}
