SilphCo_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
	.string "¡Socorro!\n"
	.string "¡Soy un empleado de SILPH S.A.!$"

SilphCo_2F_Text_ConnorDefeat::
	.string "¿Cómo sabías que yo era un\n"
	.string "ROCKET?$"

SilphCo_2F_Text_ConnorPostBattle::
	.string "¡Trabajo para SILPH S.A. y para\n"
	.string "el TEAM ROCKET!$"

SilphCo_2F_Text_JerryIntro::
	.string "¡Estás en zona prohibida!\n"
	.string "¡Vuelve a casa!$"

SilphCo_2F_Text_JerryDefeat::
	.string "¡Eres genial!$"

SilphCo_2F_Text_JerryPostBattle::
	.string "¿Puedes resolver este laberinto?$"

SilphCo_2F_Text_Grunt1Intro::
	.string "¡Aquí no pueden entrar los niños!$"

SilphCo_2F_Text_Grunt1Defeat::
	.string "¡Muy fuerte!$"

SilphCo_2F_Text_Grunt1PostBattle::
	.string "¡Las baldosas con forma\n"
	.string "de diamante son puntos\l"
	.string "de teletransporte!\p"
	.string "¡Son medios de transporte\n"
	.string "de alta tecnología!$"

SilphCo_2F_Text_Grunt2Intro::
	.string "¡Oye, tú!\n"
	.string "¿Qué haces aquí?$"

SilphCo_2F_Text_Grunt2Defeat::
	.string "¡He metido la pata!$"

SilphCo_2F_Text_Grunt2PostBattle::
	.string "¡SILPH S.A. va a fusionarse\n"
	.string "con el TEAM ROCKET!$"

Text_ThunderWaveTeach::
	.string "¡Aaah!\n"
	.string "¡No! ¡Alto! ¡Socorro!\p"
	.string "Oh, no eres del TEAM ROCKET.\n"
	.string "Lo siento, pensé que…\p"
	.string "¿Me perdonarás si te enseño la\n"
	.string "técnica ONDA TRUENO?$"

Text_ThunderWaveDeclined::
	.string "Eh...\n"
	.string "ONDA TRUENO es muy útil...$"

Text_ThunderWaveWhichMon::
	.string "¿A qué POKéMON quieres que\n"
	.string "le enseñe ONDA TRUENO?$"

Text_ThunderWaveTaught::
	.string "ONDA TRUENO puede paralizar\n"
	.string "al POKéMON que sufre el ataque.\p"
	.string "Y cuando un POKéMON está\n"
	.string "paralizado en combate es posible\l"
	.string "que no se mueva.\p"
	.string "Es un ataque del tipo ELÉCTRICO,\n"
	.string "así que no funcionará contra\l"
	.string "algunos POKéMON.$"

SilphCo_2F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P1$"

