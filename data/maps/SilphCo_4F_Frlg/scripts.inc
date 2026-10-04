SilphCo_4F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_4F_OnLoad
	.byte 0

SilphCo_4F_OnLoad::
	call_if_unset FLAG_SILPH_4F_DOOR_1, EventScript_Close4FDoor1
	call_if_unset FLAG_SILPH_4F_DOOR_2, EventScript_Close4FDoor2
	end

SilphCo_4F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_4F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_4F_Text_CantYouSeeImHiding
	release
	end

SilphCo_4F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_4F_Text_TeamRocketIsGone
	release
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat
	msgbox SilphCo_4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat
	msgbox SilphCo_4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_Text_CantYouSeeImHiding::
	.string "¡Sssh! ¿Acaso no ves que me estoy\n"
	.string "escondiendo?$"

SilphCo_4F_Text_TeamRocketIsGone::
	.string "¿Eh?\n"
	.string "¿Que el TEAM ROCKET se ha ido?$"

SilphCo_4F_Text_Grunt1Intro::
	.string "¡El TEAM ROCKET se ha apoderado\n"
	.string "de SILPH S.A.!$"

SilphCo_4F_Text_Grunt1Defeat::
	.string "¡Arrgh!$"

SilphCo_4F_Text_Grunt1PostBattle::
	.string "¡Ja, ja, ja!\n"
	.string "¡Mi JEFE buscaba este lugar!$"

SilphCo_4F_Text_RodneyIntro::
	.string "Mi POKéMON es mi fiel sirviente.$"

SilphCo_4F_Text_RodneyDefeat::
	.string "¡Maldición!\n"
	.string "¡Qué POKéMON tan débiles!$"

SilphCo_4F_Text_RodneyPostBattle::
	.string "¡Las puertas están cerradas\n"
	.string "electrónicamente!\p"
	.string "¡Las abre una LLAVE MAGNÉTICA!$"

SilphCo_4F_Text_Grunt2Intro::
	.string "¡Nos invaden!$"

SilphCo_4F_Text_Grunt2Defeat::
	.string "¿Quién eres tú?$"

SilphCo_4F_Text_Grunt2PostBattle::
	.string "¡Será mejor que se lo diga\n"
	.string "al JEFE del décimo piso!$"

SilphCo_4F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P3$"

