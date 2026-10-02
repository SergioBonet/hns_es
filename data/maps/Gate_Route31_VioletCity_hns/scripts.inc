Gate_Route31_VioletCity_hns_MapScripts::
	.byte 0

Gate_Route31_VioletCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_Text_Policeman:
	.string "¡Hola! ¿Has visitado la TORRE\n"
	.string "BELLSPROUT?$"

Gate_Route31_VioletCity_Text_CooltrainerF:
	.string "He visto ahí fuera el POKéMON más\n"
	.string "mono.\p"
	.string "¡Se parecía mucho a PIKACHU!$"
