/*
 * TrackingController.cpp
 *
 *  Created on: 2022-07-18
 *      Author: devBoi76
 */

#include "TrackingController.h"

void CTrackingController::UpdatePosition(TCoordinate& newPos) {
	
	if (iTimesPosRecieved == 0)
		iPrevLastPosition = newPos;
	
	
	iLastPosition = newPos;
	
	iTimesPosRecieved += 1;
	
	// Distance calculation
	UpdateRouteDistance();
}

void CTrackingController::UpdateRouteDistance() {
	
	TReal32 dist;
	iPrevLastPosition.Distance(iLastPosition, dist);
	
	if(dist < iMinDistanceDiff)
		return;
	
	iPrevLastPosition = iLastPosition; // one "step"
	
	iThisRouteDistance += dist;
		
}

TInt CTrackingController::ThisRouteDistance(TReal32& aDistance)
	{
	aDistance = iThisRouteDistance;
	return KErrNone;
	}

CTrackingController* CTrackingController::NewL() 
	{
	DEBUG(_L("Got To NewL1 CTrackingController"));
	CTrackingController* self = CTrackingController::NewLC();
	CleanupStack::Pop(self);
	DEBUG(_L("Got To NewL2 CTrackingController"));
	return self;
	}

CTrackingController* CTrackingController::NewLC()
	{
	DEBUG(_L("Got To NewLC1 CTrackingController"));
	CTrackingController* self = new (ELeave) CTrackingController();
	CleanupStack::PushL(self);
	self->ConstructL();
	DEBUG(_L("Got To NewLC1 CTrackingController"));
	return self;
	}

void CTrackingController::ConstructL()
	{ 
	DEBUG(_L("Got To ConstructL1 CTrackingController"));
	iThisRouteDistance = 0;
	iMinDistanceDiff = 5; // In meters
	DEBUG(_L("Got To ConstructL2 CTrackingController"));
	DEBUG(_L("ConstructL2 CTrackingController members = %f %f"), iThisRouteDistance, iMinDistanceDiff);
	}

CTrackingController::CTrackingController()
	{
	}

CTrackingController::~CTrackingController()
	{
	}

