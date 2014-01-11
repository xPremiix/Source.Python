/**
* =============================================================================
* Source Python
* Copyright (C) 2012 Source Python Development Team.  All rights reserved.
* =============================================================================
*
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*
* As a special exception, the Source Python Team gives you permission
* to link the code of this program (as well as its derivative works) to
* "Half-Life 2," the "Source Engine," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, the Source.Python
* Development Team grants this exception to all derivative works.
*/

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "players_generator_wrap.h"
#include "modules/entities/entities_wrap.h"
#include "modules/export_main.h"

#include "public/game/server/iplayerinfo.h"
#include "inetchannelinfo.h"


// ----------------------------------------------------------------------------
// Namespaces to use.
// ----------------------------------------------------------------------------
using namespace boost::python;

// ----------------------------------------------------------------------------
// Exposer functions.
// ----------------------------------------------------------------------------
void export_playerinfo();
void export_netinfo();
void export_player_generator();

// ----------------------------------------------------------------------------
// Entity module definition.
// ----------------------------------------------------------------------------
DECLARE_SP_MODULE(player_c)
{
	export_playerinfo();
	export_netinfo();
	export_player_generator();
}

// ----------------------------------------------------------------------------
// Exports CBaseEntityHandle.
// ----------------------------------------------------------------------------
void export_playerinfo()
{
	// TODO: Expose as IPlayerInfo instead of CPlayerInfo?
	class_<IPlayerInfo, boost::noncopyable>("CPlayerInfo", no_init)
		.def("get_name",
			&IPlayerInfo::GetName,
			"Returns the player's name"
		)

		.def("get_userid",
			&IPlayerInfo::GetUserID,
			"Returns the player's userid."
		)

		.def("get_networkid_string",
			&IPlayerInfo::GetNetworkIDString,
			"Returns the player's SteamID."
		)

		.def("get_team_index",
			&IPlayerInfo::GetTeamIndex,
			"Returns the player's team number."
		)

		.def("change_team",
			&IPlayerInfo::ChangeTeam,
			"Moves the player to the given team.",
			args("team_number")
		)

		.def("get_frag_count",
			&IPlayerInfo::GetFragCount,
			"Returns the player's frag count."
		)
		
		.def("get_death_count",
			&IPlayerInfo::GetDeathCount,
			"Returns the player's death count."
		)

		.def("is_connected",
			&IPlayerInfo::IsConnected,
			"Returns whether the player is connected."
		)

		.def("get_armor_value",
			&IPlayerInfo::GetArmorValue,
			"Returns the player's armor value."
		)

		.def("is_hltv",
			&IPlayerInfo::IsHLTV,
			"Returns whether the player is HLTV."
		)

		.def("is_player",
			&IPlayerInfo::IsPlayer,
			"Returns whether the player is a client."
		)

		.def("is_fake_client",
			&IPlayerInfo::IsFakeClient,
			"Returns whether the player is a fake client."
		)

		.def("is_dead",
			&IPlayerInfo::IsDead,
			"Returns whether the player is dead."
		)

		.def("is_in_a_vehicle",
			&IPlayerInfo::IsInAVehicle,
			"Returns whether the player is in a vehicle."
		)

		.def("is_observer",
			&IPlayerInfo::IsObserver,
			"Returns whether the player is an observer."
		)

		.def("get_abs_origin",
			&IPlayerInfo::GetAbsOrigin,
			"Returns the player's origin Vector instance."
		)

		.def("get_abs_angles",
			&IPlayerInfo::GetAbsAngles,
			"Returns the player's angle QAngle instance."
		)

		.def("get_player_mins",
			&IPlayerInfo::GetPlayerMins,
			"Returns the player's min Vector instance."
		)

		.def("get_player_maxs",
			&IPlayerInfo::GetPlayerMaxs,
			"Returns the player's max Vector instance."
		)

		.def("get_weapon_name",
			&IPlayerInfo::GetWeaponName,
			"Returns the name of the weapon the player is carrying."
		)

		.def("get_model_name",
			&IPlayerInfo::GetModelName,
			"Returns the name of the player's model."
		)

		.def("get_health",
			&IPlayerInfo::GetHealth,
			"Returns the player's health."
		)

		.def("get_max_health",
			&IPlayerInfo::GetMaxHealth,
			"Returns the player's maximum health."
		)
	;
}

void export_netinfo()
{
	class_<INetChannelInfo, boost::noncopyable>("CNetChannelInfo", no_init)
		.def("get_address",
			&INetChannelInfo::GetAddress,
			"Returns the net address of the player."
		)

		.def("get_time_connected",
			&INetChannelInfo::GetTimeConnected,
			"Returns the amount of time the player has been connected."
		)
	;
}

void export_player_generator()
{
	BOOST_GENERATOR_CLASS(CPlayerGenerator)
	BOOST_END_CLASS()
}
