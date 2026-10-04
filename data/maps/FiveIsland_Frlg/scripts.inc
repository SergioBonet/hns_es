FiveIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_OnTransition
	.byte 0

FiveIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND
	end

FiveIsland_EventScript_IslandSign::
	msgbox FiveIsland_Text_IslandSign, MSGBOX_SIGN
	end

FiveIsland_EventScript_BugCatcher::
	msgbox FiveIsland_Text_WeirdBuildingInMeadow, MSGBOX_NPC
	end

FiveIsland_EventScript_Fisher::
	msgbox FiveIsland_Text_BeenGettingBusierAroundHere, MSGBOX_NPC
	end

FiveIsland_Text_IslandSign::
	.string "ISLA INTA\n"
	.string "Isla que marca el paso del tiempo.$"

FiveIsland_Text_WeirdBuildingInMeadow::
	.string "Uf, qué rollo, yo quería jugar\n"
	.string "en el PRADO...\p"
	.string "Pero han puesto un raro edificio\n"
	.string "en medio y ya no hay dónde jugar.$"

FiveIsland_Text_BeenGettingBusierAroundHere::
	.string "Últimamente ha habido mucho\n"
	.string "movimiento por aquí...\p"
	.string "Y la pesca no ha sido buena...\n"
	.string "Mmmm...$"

