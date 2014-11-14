#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer
{
	public:
		virtual ~Observer() {}
		//virtual void onNotify(const Entity& entity, Event event) = 0;
		virtual void onNotify(std::string eventname) = 0;
};

#endif