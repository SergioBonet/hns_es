.equ REQUIRED_SEEN_MONS, 10

Route2_EastBuilding_Frlg_MapScripts::
	.byte 0

Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
	msgbox Route2_EastBuilding_Text_GiveHM05IfSeen10Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_SEEN_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route2_EastBuilding_Text_GreatHereYouGo
	checkitemspace ITEM_HM05
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route2_EastBuilding_Text_ReceivedHM05FromAide, ITEM_HM05
	setflag FLAG_GOT_HM05
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_AlreadyGotHM05::
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_HM05
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end

Route2_EastBuilding_Text_GiveHM05IfSeen10Mons::
	.string "¡Hola! ¿Te acuerdas de mí?\n"
	.string "Soy uno de los AYUDANTES del PROF. OAK.\p"
	.string "Si tu POKéDEX tiene datos completos\n"
	.string "de diez especies, debo darte\l"
	.string "un premio.\p"
	.string "El PROF. OAK me confió la\n"
	.string "MO05 para ti.\p"
	.string "Así que, {PLAYER}, déjame preguntarte.\p"
	.string "¿Has reunido datos de al menos\n"
	.string "diez clases de POKéMON?$"

Route2_EastBuilding_Text_GreatHereYouGo::
	.string "¡Bien! ¡Has logrado {STR_VAR_3} tipos\n"
	.string "de POKéMON!\p"
	.string "¡Enhorabuena!\n"
	.string "¡Aquí tienes!$"

Route2_EastBuilding_Text_ReceivedHM05FromAide::
	.string "{PLAYER} recibió la MO05\n"
	.string "del AYUDANTE.$"

Route2_EastBuilding_Text_ExplainHM05::
	.string "La MO05 contiene el movimiento\n"
	.string "oculto DESTELLO.\p"
	.string "DESTELLO ilumina hasta las cuevas\n"
	.string "y mazmorras más oscuras.$"

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
	.string "Cuando un POKéMON aprenda DESTELLO,\n"
	.string "podrás atravesar el TÚNEL ROCA.$"

