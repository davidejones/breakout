#include "Subject.h"

using namespace std;

Subject::Subject()
{

}

void Subject::addObserver(Observer* observer) {
	views.push_back(observer);
}

void Subject::removeObserver(Observer* observer) {
	//views.erase(1);
	//views.erase(std::remove(views.begin(), views.end(), observer), views.end()); 
}

void Subject::notify(string eventname) {
	// 5. Publisher broadcasts
	for (int i = 0; i < views.size(); i++)
		views[i]->onNotify(eventname);
}