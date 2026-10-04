SixIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OnTransition
	.byte 0

SixIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND
	end

SixIsland_EventScript_Hiker::
	msgbox SixIsland_Text_ThatWayToWaterPathRuinValley, MSGBOX_NPC
	end

SixIsland_EventScript_Boy::
	msgbox SixIsland_Text_SkyAtNightIsFantastic, MSGBOX_NPC
	end

SixIsland_EventScript_IslandSign::
	msgbox SixIsland_Text_IslandSign, MSGBOX_SIGN
	end

SixIsland_Text_IslandSign::
	.string "ISLA EXTA\n"
	.string "Isla de la fortuna y el saber.$"

SixIsland_Text_ThatWayToWaterPathRuinValley::
	.string "Si sigues por aquí, llegarás a la\n"
	.string "VÍA ACUÁTICA.\p"
	.string "Cuando alcances la VÍA,\n"
	.string "ve hacia el sur si quieres ir\l"
	.string "al VALLE de las RUINAS.$"

SixIsland_Text_SkyAtNightIsFantastic::
	.string "Al estar tan lejos de las ciudades,\n"
	.string "por la noche el cielo se ve muy\l"
	.string "despejado.$"

