EcruteakCity_House1_hns_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "Sucedió cuando era joven.\p"
	.string "El cielo se oscureció de repente.\p"
	.string "Un enorme POKéMON estaba tapando el\n"
	.string "sol.\p"
	.string "Me pregunto qué sería ese POKéMON,\n"
	.string "mezcla de pájaro y dragón.$"

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "¿Existe un POKéMON tan grande? Si\n"
	.string "existe, debe de ser muy fuerte.$"
