CeruleanCity_House2_Frlg_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
	.string "¡Esos dichosos ROCKET!\p"
	.string "¡Mira lo que hicieron aquí!\p"
	.string "¡Robaron una MT para enseñar a\n"
	.string "los POKéMON cómo EXCAVAR hoyos!\p"
	.string "Yo que quería enseñárselo a\n"
	.string "MANKEY o a SANDSHREW... \p"
	.string "¡Menuda faena!$"

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
	.string "¡Lo perdido, perdido está!\p"
	.string "¡He decidido enseñar a DIGLETT\n"
	.string "cómo EXCAVAR sin tener una MT!$"

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
	.string "¡El TEAM ROCKET estará intentando\n"
	.string "EXCAVAR para hacer alguna de las\l"
	.string "suyas!$"

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
	.string "¡El TEAM ROCKET abrió una nueva\n"
	.string "salida!$"

