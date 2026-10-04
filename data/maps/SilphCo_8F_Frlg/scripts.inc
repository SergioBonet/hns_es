SilphCo_8F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_8F_OnLoad
	.byte 0

SilphCo_8F_OnLoad::
	call_if_unset FLAG_SILPH_8F_DOOR, EventScript_Close8FDoor
	end

SilphCo_8F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_8F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_8F_Text_WonderIfSilphIsFinished
	release
	end

SilphCo_8F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_8F_Text_ThanksForSavingUs
	release
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat
	msgbox SilphCo_8F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat
	msgbox SilphCo_8F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_Text_WonderIfSilphIsFinished::
	.string "Me pregunto si SILPH estará\n"
	.string "acabada.$"

SilphCo_8F_Text_ThanksForSavingUs::
	.string "¡Gracias por salvarnos!$"

SilphCo_8F_Text_Grunt1Intro::
	.string "¡No podrás ir más lejos!$"

SilphCo_8F_Text_Grunt1Defeat::
	.string "¡No tienes bastante agallas!$"

SilphCo_8F_Text_Grunt1PostBattle::
	.string "Si no das marcha atrás…\n"
	.string "¡Pediré refuerzos!$"

SilphCo_8F_Text_ParkerIntro::
	.string "¡Nos estás dando muchos problemas!$"

SilphCo_8F_Text_ParkerDefeat::
	.string "¿Qué?\n"
	.string "¿He perdido?$"

SilphCo_8F_Text_ParkerPostBattle::
	.string "¿Qué opinas del laberinto del\n"
	.string "EDIFICIO SILPH?$"

SilphCo_8F_Text_Grunt2Intro::
	.string "¡Soy uno de los 4\n"
	.string "HERMANOS ROCKET!$"

SilphCo_8F_Text_Grunt2Defeat::
	.string "¡Ahhhg!\n"
	.string "¡Hermanos! ¡Tenéis que vengarme!$"

SilphCo_8F_Text_Grunt2PostBattle::
	.string "¡Mis hermanos se encargarán de ti!$"

SilphCo_8F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P7$"

SilphCo_8F_Text_ToRocketBossMonsAreTools::
	.string "¡El JEFE del TEAM ROCKET es muy\n"
	.string "cruel!\p"
	.string "Sólo quiere a los POKéMON para\n"
	.string "luchar.\p"
	.string "No quiero ni pensar lo que podría\n"
	.string "ocurrir si se hiciera con el mando\l"
	.string "de la compañía...$"
