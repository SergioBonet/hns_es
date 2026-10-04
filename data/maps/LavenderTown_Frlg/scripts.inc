LavenderTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_DoYouBelieveInGhosts::
	.string "¿Crees en los fantasmas?$"

LavenderTown_Text_SoThereAreBelievers::
	.string "¿En serio?\n"
	.string "Así que hay creyentes…$"

LavenderTown_Text_JustImaginingWhiteHand::
	.string "Jajaja, supongo que no.\p"
	.string "Esa mano blanca en tu hombro…\n"
	.string "Solo me la estoy imaginando.$"

LavenderTown_Text_TownKnownAsMonGraveSite::
	.string "A este pueblo se lo conoce como\n"
	.string "el lugar de reposo de los POKéMON.\p"
	.string "Los homenajes se celebran en la\n"
	.string "TORRE POKéMON.$"

LavenderTown_Text_GhostsAppearedInTower::
	.string "Han aparecido fantasmas en la\n"
	.string "TORRE POKéMON.\p"
	.string "Creo que son los espíritus de los\n"
	.string "POKéMON que mataron los ROCKET.$"

LavenderTown_Text_TownSign::
	.string "PUEBLO LAVANDA\p"
	.string "El noble pueblo púrpura$"

LavenderTown_Text_SilphScopeNotice::
	.string "¡Nuevo SCOPE SILPH!\n"
	.string "¡Haz visible lo invisible!\p"
	.string "SILPH S.A.$"

LavenderTown_Text_VolunteerPokemonHouse::
	.string "CASA POKéMON de VOLUNTARIOS\n"
	.string "de PUEBLO LAVANDA$"

LavenderTown_Text_PokemonTowerSign::
	.string "TORRE POKéMON\n"
	.string "Calma el espíritu de los POKéMON$"

