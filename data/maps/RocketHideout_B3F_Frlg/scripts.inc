RocketHideout_B3F_Frlg_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
	.string "¡Deja de meterte en los asuntos\n"
	.string "del TEAM ROCKET!$"

RocketHideout_B3F_Text_Grunt1Defeat::
	.string "¡Uf!\n"
	.string "¡Derribado!$"

RocketHideout_B3F_Text_Grunt1PostBattle::
	.string "¿El SCOPE SILPH?\n"
	.string "Ah, la máquina que robó el JEFE.\p"
	.string "Debe de estar por aquí.$"

RocketHideout_B3F_Text_Grunt2Intro::
	.string "¡Nos dijeron desde arriba que\n"
	.string "venías!$"

RocketHideout_B3F_Text_Grunt2Defeat::
	.string "¿Qué?\n"
	.string "¿He perdido? ¡NO!$"

RocketHideout_B3F_Text_Grunt2PostBattle::
	.string "¡Venga, adelante!\p"
	.string "¡Pero necesitarás la LLAVE\n"
	.string "del ASCENSOR!$"

