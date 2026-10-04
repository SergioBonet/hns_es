PewterCity_Museum_1F_Frlg_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_eq VAR_FACING, DIR_WEST, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_SOUTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_NORTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself
	release
	end

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
	msgbox PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter
	goto_if_eq VAR_RESULT, NO, PewterCity_Museum_1F_EventScript_ExplainAmber
	end

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
	msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter
	applymovement LOCALID_MUSEUM_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_ExplainAmber::
	msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap
	applymovement LOCALID_MUSEUM_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	showmoneybox 0, 0
	msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_TryPayForTicket
	msgbox PewterCity_Museum_1F_Text_ComeAgain
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NotEnoughMoney
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft
	call_if_eq VAR_TEMP_1, 1, PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid
	call_if_eq VAR_TEMP_1, 2, PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	waitse
	msgbox PewterCity_Museum_1F_Text_Right50YThankYou
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 1
	hidemoneybox
	releaseall
	end

PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
	msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Movement_ForcePlayerExit::
	walk_down
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
	msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined
	checkitemspace ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
	setflag FLAG_GOT_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	giveitem_msg PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan, ITEM_OLD_AMBER, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
	msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis
	release
	end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
	msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked
	release
	end

PewterCity_Museum_1F_EventScript_OldAmber::
	msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_AerodactylFossil::
	lockall
	setvar VAR_0x8004, SPECIES_AERODACTYL
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_AerodactylFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_EventScript_KabutopsFossil::
	lockall
	setvar VAR_0x8004, SPECIES_KABUTOPS
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_KabutopsFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_Text_Its50YForChildsTicket::
	.string "Los niños pagan 50¥.\p"
	.string "¿Te gustaría entrar?$"

PewterCity_Museum_1F_Text_ComeAgain::
	.string "¡Hasta pronto!$"

PewterCity_Museum_1F_Text_Right50YThankYou::
	.string "¡50¥! ¡Vale!\n"
	.string "¡Gracias!$"

PewterCity_Museum_1F_Text_DontHaveEnoughMoney::
	.string "No tienes suficiente dinero.$"

PewterCity_Museum_1F_Text_PleaseEnjoyYourself::
	.string "Disfruta de la visita.$"

PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs::
	.string "¡No puedes entrar por detrás!\p"
	.string "¡Bueno, da igual!\n"
	.string "¿Sabes qué es el ÁMBAR?$"

PewterCity_Museum_1F_Text_AmberContainsGeneticMatter::
	.string "¿Y sabías que el ÁMBAR contiene\n"
	.string "material genético de los POKéMON?\p"
	.string "Dicen que hay un LABORATORIO\n"
	.string "donde intentan revivir a viejos\l"
	.string "POKéMON a partir del ÁMBAR.$"

PewterCity_Museum_1F_Text_AmberIsFossilizedSap::
	.string "El ÁMBAR es en realidad savia, esa\n"
	.string "sustancia pegajosa que rezuma de\l"
	.string "los árboles.\p"
	.string "La savia antigua se fosilizó con el\n"
	.string "tiempo hasta convertirse en ÁMBAR\l"
	.string "duro como una roca.$"

@ Unused
PewterCity_Museum_1F_Text_PleaseGoAround::
	.string "Por favor, rodee por allí.$"

PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife::
	.string "¡Qué golpe de suerte!\p"
	.string "¡Nunca pensé que conseguiría\n"
	.string "ver huesos de dragón!$"

PewterCity_Museum_1F_Text_WantYouToGetAmberExamined::
	.string "¡Ssh! Voy a contarte un secreto.\p"
	.string "¡Creo que este trozo de ÁMBAR\n"
	.string "contiene ADN de POKéMON!\p"
	.string "¡Sería un descubrimiento científico\n"
	.string "increíble si se pudiera revivir a\l"
	.string "los POKéMON con esto!\p"
	.string "¡Pero mis colegas no me hacen\n"
	.string "ni caso! ¡Por eso te voy a pedir\l"
	.string "un favor!\p"
	.string "¡Lleva esto al LABORATORIO\n"
	.string "POKéMON para que lo analicen!$"

PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan::
	.string "¡{PLAYER} recibió el ÁMBAR VIEJO\n"
	.string "de manos del hombre!$"

PewterCity_Museum_1F_Text_GetOldAmberChecked::
	.string "¡Ssh!\n"
	.string "¡Haz que analicen el ÁMBAR VIEJO!$"

PewterCity_Museum_1F_Text_DontHaveSpaceForThis::
	.string "¡No tienes sitio para esto!$"

PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit::
	.string "¡Tenemos dos fósiles de unos\n"
	.string "POKéMON muy raros y prehistóricos!$"

PewterCity_Museum_1F_Text_BeautifulPieceOfAmber::
	.string "¡El ÁMBAR es transparente y de\n"
	.string "color oro!$"

PewterCity_Museum_1F_Text_AerodactylFossil::
	.string "Fósil AERODACTYL.\n"
	.string "Un primitivo y raro POKéMON.$"

PewterCity_Museum_1F_Text_KabutopsFossil::
	.string "Fósil KABUTOPS.\n"
	.string "Un primitivo y raro POKéMON.$"

