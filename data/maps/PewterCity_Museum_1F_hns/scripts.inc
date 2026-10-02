PewterCity_Museum_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "¡Bienvenido!\p"
	.string "Para que lo sepas, todas las piezas\n"
	.string "grandes se han llevado a otros museos\l"
	.string "para exponerlas.\p"
	.string "Así que, de momento, ¡la entrada es\n"
	.string "gratuita!\p"
	.string "Adelante, por favor.$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "Debes de ser un ENTRENADOR fuerte.\p"
	.string "No le sacamos mucho partido a los\n"
	.string "fósiles del mostrador de allí.\p"
	.string "Un hombre extraño de pelo plateado\n"
	.string "nos dejó un montón.\p"
	.string "Si quieres, cógelos.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "Solemos compartir nuestras\n"
	.string "investigaciones con los\l"
	.string "investigadores de las RUINAS ALFA.\p"
	.string "¡Hasta compartimos fósiles con ellos a\n"
	.string "través del PC!$"

PewterCity_Museum_1F_Text_Oldman:
	.string "¡Qué golpe de suerte!\p"
	.string "¡Nunca pensé que conseguiría ver\n"
	.string "huesos de dragón!$"

PewterCity_Museum_1F_Text_Bones:
	.string "Huesos de un antiguo POKéMON dragón.$"
