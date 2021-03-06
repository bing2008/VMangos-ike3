#include "Strategy_Group_DoctorWeavil.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "RobotConfig.h"
#include "RobotManager.h"
#include "Group.h"
#include "MotionMaster.h"
#include "TargetedMovementGenerator.h"
#include "GridNotifiers.h"
#include "Map.h"
#include "Pet.h"

bool Strategy_Group_DoctorWeavil::DPS()
{
	if (!me)
	{
		return false;
	}
	if (Group* myGroup = me->GetGroup())
	{
		if (combatTime > dpsDelay)
		{
			if (Unit* weavil = myGroup->GetGroupAttacker(CreatureEntry_RobotStrategy::CreatureEntry_Strategy_Doctor_Weavil))
			{
				if (sb->DPS(weavil, Chasing()))
				{
					return true;
				}
			}
		}
	}
	return Strategy_Group::DPS();
}

bool Strategy_Group_DoctorWeavil::Tank()
{
	if (!me)
	{
		return false;
	}
	if (Group* myGroup = me->GetGroup())
	{
		if (Unit* weavil = myGroup->GetGroupAttacker(CreatureEntry_RobotStrategy::CreatureEntry_Strategy_Doctor_Weavil))
		{
			if (sb->Tank(weavil, Chasing(), true))
			{
				return true;
			}
		}
	}

	return Strategy_Group::Tank();
}
