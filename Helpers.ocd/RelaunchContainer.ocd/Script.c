/**
 Relaunch container.
 @author Marky
 @credits Maikel
 @version 0.1.0
*/

#include RelaunchContainer

static const RELAUNCH_Default_Time = 360; // hold 10 seconds
static const RELAUNCH_Default_Hold = true;

protected func Initialize()
{
	time = RELAUNCH_Default_Time;
	hold = RELAUNCH_Default_Hold;
}

public func PrepareRelaunch(object clonk)
{
	if (!clonk) return false;
	if (crew)
	{
		if (clonk == crew) 
		{
			return true;
		}
		return false;
	}
	// save clonk for later use
	crew = clonk;
	clonk->Enter(this);
	return true;
}

public func StartRelaunch(object clonk)
{
	if (PrepareRelaunch(clonk))
	{
		ScheduleCall(this, "OpenWeaponMenu", 36, 0, clonk);
		AddEffect("IntTimeLimit", this, 100, 36, this);
		return true;
	}
	else
	{
		return false;
	}
}

public func InstantRelaunch()
{
	if (!crew)
	{
		FatalError("There was no object that can be relaunched. The function PrepareRelaunch() or StartRelaunch() should be called first.");
	}
	
	RelaunchClonk();
}