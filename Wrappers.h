#pragma once

#include "LeakedObjectDetector.h"
#include "DailyActivities.h"
#include "Paint.h"

struct DailyActivitiesWrapper
{
    DailyActivitiesWrapper( DailyActivities* ptr );
    ~DailyActivitiesWrapper();

    DailyActivities* pointerToDailyActivities = nullptr; 
};

struct PaintWrapper
{
    PaintWrapper( Paint* ptr );
    ~PaintWrapper();

    Paint* pointerToPaint = nullptr; 
};

