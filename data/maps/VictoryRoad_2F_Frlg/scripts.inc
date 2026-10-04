VictoryRoad_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	.byte 0

VictoryRoad_2F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_SetRockBarrier1
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_SetRockBarrier2
	end

VictoryRoad_2F_EventScript_SetRockBarrier1::
	setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_SetRockBarrier2::
	setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_FloorSwitch1::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
	setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_2F_BOULDER1
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
	setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_2F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_Dawson::
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Daisuke::
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
	msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Nelson::
	trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Gregory::
	trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
	msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Vincent::
	trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
	msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_DawsonIntro::
	.string "¡Si puedes pasar por aquí, podrás\n"
	.string "enfrentarte al ALTO MANDO!$"

VictoryRoad_2F_Text_DawsonDefeat::
	.string "¡No!\n"
	.string "¡Increíble!$"

VictoryRoad_2F_Text_DawsonPostBattle::
	.string "¡Puedo vencerte en cuanto a\n"
	.string "conocimientos sobre los POKéMON!$"

VictoryRoad_2F_Text_DaisukeIntro::
	.string "¡La CALLE VICTORIA es la prueba\n"
	.string "final de todo ENTRENADOR!$"

VictoryRoad_2F_Text_DaisukeDefeat::
	.string "¡Ayyyy!$"

VictoryRoad_2F_Text_DaisukePostBattle::
	.string "¡Prueba a mover las rocas\n"
	.string "si tienes el paso cortado!$"

VictoryRoad_2F_Text_NelsonIntro::
	.string "¡Ah!\n"
	.string "¿Quieres desafiar al ALTO MANDO?$"

VictoryRoad_2F_Text_NelsonDefeat::
	.string "¡Me has parado los pies!$"

VictoryRoad_2F_Text_NelsonPostBattle::
	.string "¡{RIVAL} también vino por aquí!$"

VictoryRoad_2F_Text_VincentIntro::
	.string "¡Adelante!\n"
	.string "¡Te daré una paliza!$"

VictoryRoad_2F_Text_VincentDefeat::
	.string "¡Me han zurrado!$"

VictoryRoad_2F_Text_VincentPostBattle::
	.string "¡Ahora puedes recorrer la CALLE\n"
	.string "VICTORIA!$"

VictoryRoad_2F_Text_GregoryIntro::
	.string "¿Es muy dura la CALLE VICTORIA?$"

VictoryRoad_2F_Text_GregoryDefeat::
	.string "¡Bien hecho!$"

VictoryRoad_2F_Text_GregoryPostBattle::
	.string "¡Muchos de los ENTRENADORES\n"
	.string "se rinden aquí!$"

@ Unused, old text for Moltres
VictoryRoad_2F_Text_Gyaoo::
	.string "¡Guiaaao!$"

