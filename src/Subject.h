#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <iostream>
#include <vector>
#include <string>

class Subject
{
private:
	std::vector <class Observer*> views; // 3. Coupled only to "interface"
public:
	Subject();
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notify(std::string eventname);
};

#endif