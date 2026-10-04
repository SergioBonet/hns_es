Route18_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route18_OnTransitionCyclingRoad
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_Text_WiltonIntro::
	.string "Compruebo siempre las zonas de\n"
	.string "hierba en busca de nuevos POKéMON.$"

Route18_Text_WiltonDefeat::
	.string "¡Tch!$"

Route18_Text_WiltonPostBattle::
	.string "¡Ojalá tuviera una BICICLETA!$"

Route18_Text_RamiroIntro::
	.string "¡Kurukkoo!\n"
	.string "¿Te gusta mi reclamo de pájaro?$"

Route18_Text_RamiroDefeat::
	.string "¡Tenía que molestarte!$"

Route18_Text_RamiroPostBattle::
	.string "¡También recojo POKéMON del mar\n"
	.string "los fines de semana!$"

Route18_Text_JacobIntro::
	.string "¡Es mi césped!\n"
	.string "¡Fuera de aquí!$"

Route18_Text_JacobDefeat::
	.string "¡Grr!$"

Route18_Text_JacobPostBattle::
	.string "¡Es mi zona preferida para atrapar\n"
	.string "POKéMON!$"

Route18_Text_RouteSign::
	.string "RUTA 18:\n"
	.string "CIUDAD AZULONA - CIUDAD FUCSIA$"

Route18_Text_CyclingRoadSign::
	.string "CAMINO DE BICIS\n"
	.string "¡Prohibido el paso a los peatones!$"

