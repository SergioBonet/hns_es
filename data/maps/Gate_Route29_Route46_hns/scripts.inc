Gate_Route29_Route46_hns_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "No puedes cruzar setos.\p"
	.string "Pero puedes saltar por encima de ellos\n"
	.string "para atajar.$"

Gate_Route29_Route46_Text_Youngster:
	.string "Más adelante aparecen muchos tipos\n"
	.string "de POKéMON.\p"
	.string "Si quieres hacerte con todos, tendrás\n"
	.string "que buscar por todas partes.$"
