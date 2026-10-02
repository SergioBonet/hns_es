CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "¿Quieres saber si vales o no con los\n"
	.string "POKéMON?\p"
	.string "Pues vete a los GIMNASIOS POKéMON\p"
	.string "de JOHTO y gana muchas MEDALLAS.$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "¡Cuando sea mayor, voy a ser un LÍDER\n"
	.string "de GIMNASIO!\p"
	.string "¡Hago luchar a mis POKéMON contra los\n"
	.string "de mi amigo para fortalecerlos!$"
