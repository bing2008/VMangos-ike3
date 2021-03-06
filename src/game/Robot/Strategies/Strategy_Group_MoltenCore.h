#ifndef ROBOT_STRATEGY_MOLTEN_CORE_H
#define ROBOT_STRATEGY_MOLTEN_CORE_H

#include "Strategy_Group.h"

enum GroupRole_MoltenCore :uint32
{
	GroupRole_MoltenCore_Tank1 = 0,
	GroupRole_MoltenCore_Tank2,
	GroupRole_MoltenCore_Healer,
	GroupRole_MoltenCore_DPS_Range,
	GroupRole_MoltenCore_DPS_Melee,
};

enum ActionType_MoltenCore :uint32
{
	ActionType_MoltenCore_None = 0,
	ActionType_MoltenCore_MarkMove,
};

class Strategy_Group_MoltenCore :public Strategy_Group
{
public:
	Strategy_Group_MoltenCore(Player* pmMe) :Strategy_Group(pmMe)
	{
		InitialStrategy();
	}

	void InitialStrategy();
	std::string GetGroupRoleName() override;
	void SetGroupRole(std::string pmRoleName) override;
	bool Stay(std::string pmTargetGroupRole) override;
	bool Hold(std::string pmTargetGroupRole) override;
	bool Engage(Unit* pmTarget) override;
	bool DPS() override;
	bool Tank() override;
	bool Tank(Unit* pmTarget) override;
	bool Heal() override;
	void Update(uint32 pmDiff) override;

	float engageAngle;
	float engageDistance;
	uint32 majordomoDPSDelay;
};
#endif
