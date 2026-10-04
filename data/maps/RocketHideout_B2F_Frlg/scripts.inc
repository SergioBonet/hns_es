RocketHideout_B2F_Frlg_MapScripts::
	.byte 0

RocketHideout_B2F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_13, RocketHideout_B2F_Text_GruntIntro, RocketHideout_B2F_Text_GruntDefeat
	msgbox RocketHideout_B2F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntIntro::
	.string "¡El JEFE dijo que se pueden ver\n"
	.string "fantasmas con el SCOPE SILPH!$"

RocketHideout_B2F_Text_GruntDefeat::
	.string "¡Esto no estaba previsto!$"

RocketHideout_B2F_Text_GruntPostBattle::
	.string "El CUARTEL del TEAM ROCKET tiene\n"
	.string "cuatro sótanos.\p"
	.string "¿Crees que podrás llegar al JEFE?$"

