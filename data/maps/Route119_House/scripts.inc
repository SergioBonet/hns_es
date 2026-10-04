Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "He oído hablar de una cueva llamada\n"
	.string "CUEVA ANCESTRAL.\p"
	.string "Dicen que allí reviven los espíritus\n"
	.string "de los POKéMON. ¿Podría ocurrir\l"
	.string "eso de verdad?$"

Route119_House_Text_Wingull:
	.string "WINGULL: ¡Winguuu!$"

