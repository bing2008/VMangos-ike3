#ifndef ROBOT_STRATEGIES_SCRIPT_PRIEST_H
#define ROBOT_STRATEGIES_SCRIPT_PRIEST_H

#ifndef PRIEST_RANGE_DISTANCE
# define PRIEST_RANGE_DISTANCE 30
#endif

#ifndef PRIEST_HEAL_DISTANCE
# define PRIEST_HEAL_DISTANCE 40
#endif

#include "Script_Base.h"

class Script_Priest :public Script_Base
{
public:
    Script_Priest(Player* pmMe);
    bool DPS(Unit* pmTarget, bool pmChase = true);
    bool Tank(Unit* pmTarget, bool pmChase, bool pmSingle = false);
    bool Heal(Unit* pmTarget, bool pmCure = true);
    bool SubHeal(Unit* pmTarget, bool pmCure = true);
    bool GroupHeal(float pmMaxHealthPercent = 60.0f);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure = true);

    bool DPS_Common(Unit* pmTarget, bool pmChase);
    bool Attack_Common(Unit* pmTarget);
    bool Heal_Holy(Unit* pmTarget, bool pmCure);
    bool GroupHeal_Holy(float pmMaxHealthPercent);
};
#endif
