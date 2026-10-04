.equ REQUIRED_CAUGHT_MONS, 50

Route15_WestEntrance_2F_Frlg_MapScripts::
	.byte 0

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
	lockall
	msgbox Route15_WestEntrance_2F_Text_LargeShiningBird
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ARTICUNO
	special SetSeenMon
	releaseall
	end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
	msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE, Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare
	msgbox Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route15_WestEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route15_WestEntrance_2F_Text_ReceivedItemFromAide, ITEM_EXP_SHARE
	setflag FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE
	msgbox Route15_WestEntrance_2F_Text_ExplainExpShare
	release
	end

Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare::
	msgbox Route15_WestEntrance_2F_Text_ExplainExpShare
	release
	end

Route15_WestEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_EXP_SHARE
	return

Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough::
	.string "¡Hola! ¿Te acuerdas de mí?\n"
	.string "Soy uno de los AYUDANTES del PROF. OAK.\p"
	.string "Si tu POKéDEX tiene datos completos\n"
	.string "de {STR_VAR_1} especies, debo darte\l"
	.string "un premio.\p"
	.string "El PROF. OAK me confió el objeto\n"
	.string "{STR_VAR_2} para ti.\p"
	.string "Así que, {PLAYER}, déjame preguntarte.\p"
	.string "¿Has reunido datos de al menos\n"
	.string "{STR_VAR_1} clases de POKéMON?$"

Route15_WestEntrance_2F_Text_GreatHereYouGo::
	.string "¡Bien! ¡Has logrado {STR_VAR_3} tipos\n"
	.string "de POKéMON!\p"
	.string "¡Enhorabuena!\n"
	.string "¡Aquí tienes!$"

Route15_WestEntrance_2F_Text_ReceivedItemFromAide::
	.string "¡{PLAYER} obtuvo {STR_VAR_2}\n"
	.string "de manos del AYUDANTE!$"

Route15_WestEntrance_2F_Text_ExplainExpShare::
	.string "REPARTIR EXP. es un objeto\n"
	.string "que puede llevar un POKéMON.\p"
	.string "Dará puntos de EXPERIENCIA\n"
	.string "al POKéMON que lo lleve, aunque\l"
	.string "no luche.$"

Route15_WestEntrance_2F_Text_LargeShiningBird::
	.string "Has usado los prismáticos...\p"
	.string "Un pájaro grande y brillante vuela\n"
	.string "hacia el mar.$"

Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
	.string "Has usado los prismáticos...\p"
	.string "¡Parece que hay una pequeña isla!$"

