#include "Wrappers.h"
#include <iostream>

DailyActivitiesWrapper::DailyActivitiesWrapper( DailyActivities* ptr ): pointerToDailyActivities( ptr ) {}

DailyActivitiesWrapper::~DailyActivitiesWrapper()
{
    delete pointerToDailyActivities;
}

PaintWrapper::PaintWrapper( Paint* ptr ) : pointerToPaint( ptr ) {}

PaintWrapper::~PaintWrapper()
{
    delete pointerToPaint;
}
