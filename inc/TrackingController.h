/*
 * TrackingController.h
 *
 *  Created on: 2022-07-18
 *      Author: devBoi76
 */

// Includes

#include <e32base.h>
#include <e32def.h>
#include "Map.h"
#include "Logger.h"

#ifndef TRACKINGCONTROLLER_H_
#define TRACKINGCONTROLLER_H_

//class TCoordinateEx; // forward declare

class CTrackingController : CBase
	{
public:
	// Constructor
	CTrackingController();
	
	static CTrackingController* NewL();
	static CTrackingController* NewLC();
	void ConstructL();
	
	// Destructor
	virtual ~CTrackingController();
	
private:
	TReal32 iThisRouteDistance; // In meters
	TReal32 iMinDistanceDiff; // In meters
	TCoordinate iPrevLastPosition;
	TCoordinate iLastPosition;
	TInt iTimesPosRecieved;
	
	void UpdateRouteDistance();
	
public:
	void UpdatePosition(TCoordinate& newPos);
	TInt ThisRouteDistance(TReal32& aDistance);
	
	};
#endif /* TRACKINGCONTROLLER_H_ */
