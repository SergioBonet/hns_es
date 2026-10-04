.equ CHECKED_MUSHROOMS,  FLAG_TEMP_1
.equ HAS_BIG_MUSHROOM,   FLAG_TEMP_2
.equ HAS_TINY_MUSHROOMS, FLAG_TEMP_3
.equ HAS_BOTH_MUSHROOMS, FLAG_TEMP_4

TwoIsland_House_Frlg_MapScripts::
	.byte 0

TwoIsland_House_EventScript_MoveManiac::
	lock
	faceplayer
	clearflag HAS_BIG_MUSHROOM
	clearflag HAS_TINY_MUSHROOMS
	clearflag HAS_BOTH_MUSHROOMS
	goto_if_set CHECKED_MUSHROOMS, TwoIsland_House_EventScript_CheckPlayerHasMushrooms
	msgbox TwoIsland_House_Text_TeachMonMoveForMushroom
	setflag CHECKED_MUSHROOMS
	goto TwoIsland_House_EventScript_CheckPlayerHasMushrooms
	end

TwoIsland_House_EventScript_CheckPlayerHasMushrooms::
	checkitem ITEM_BIG_MUSHROOM
	call_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_SetHasBigMushroom
	checkitem ITEM_TINY_MUSHROOM, 2
	call_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_SetHasTinyMushrooms
	goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms
	goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_CheckAlsoHasBigMushroom
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms::
	call_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_SetHasBothMushrooms
	goto TwoIsland_House_EventScript_AskTutorMon
	end

TwoIsland_House_EventScript_CheckAlsoHasBigMushroom::
	call_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_SetHasBothMushrooms
	goto TwoIsland_House_EventScript_AskTutorMon
	end

TwoIsland_House_EventScript_AskTutorMon::
	msgbox TwoIsland_House_Text_WantMeToTeachMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TwoIsland_House_EventScript_EndTutorMove
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_ChooseMonToTutor::
	msgbox TwoIsland_House_Text_TutorWhichMon
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, TwoIsland_House_EventScript_EndTutorMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_CantTutorEgg
	goto_if_eq VAR_0x8005, 0, TwoIsland_House_EventScript_NoMoveToTutorMon
	goto TwoIsland_House_EventScript_ChooseMoveToTeach
	end

TwoIsland_House_EventScript_ChooseMoveToTeach::
	msgbox TwoIsland_House_Text_TeachWhichMove
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, TwoIsland_House_EventScript_ChooseMonToTutor
	goto_if_set HAS_BOTH_MUSHROOMS, TwoIsland_House_EventScript_ChooseMushroom
	goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_GiveBigMushroom
	goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_GiveTinyMushrooms
	end

TwoIsland_House_EventScript_GiveBigMushroom::
	removeitem ITEM_BIG_MUSHROOM
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox TwoIsland_House_Text_HandedOverOneBigMushroom
	call EventScript_RestorePrevTextColor
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_GiveTinyMushrooms::
	removeitem ITEM_TINY_MUSHROOM, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox TwoIsland_House_Text_HandedOverTwoTinyMushrooms
	call EventScript_RestorePrevTextColor
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_ChooseMushroom::
	message TwoIsland_House_Text_IllNeedMushroomOrTwo
	waitmessage
	multichoice 0, 0, MULTI_MUSHROOMS, TRUE
	switch VAR_RESULT
	case 0, TwoIsland_House_EventScript_GiveTinyMushrooms
	case 1, TwoIsland_House_EventScript_GiveBigMushroom
	end

TwoIsland_House_EventScript_NoMoveToTutorMon::
	msgbox TwoIsland_House_Text_NoMoveICanTeachThatMon
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_CantTutorEgg::
	msgbox TwoIsland_House_Text_CantTeachAnEgg
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_EndTutorMove::
	msgbox TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove
	release
	end

TwoIsland_House_EventScript_SetHasBigMushroom::
	setflag HAS_BIG_MUSHROOM
	return

TwoIsland_House_EventScript_SetHasTinyMushrooms::
	setflag HAS_TINY_MUSHROOMS
	return

TwoIsland_House_EventScript_SetHasBothMushrooms::
	setflag HAS_BOTH_MUSHROOMS
	return

TwoIsland_House_Text_TeachMonMoveForMushroom::
	.string "Soy el TUTOR de MOVIMIENTOS.\p"
	.string "Me sé todos los movimientos que\n"
	.string "aprenden los POKéMON. Todos,\l"
	.string "toditos, todos. Y puedo enseñar.\p"
	.string "También soy EXPERTO en SETAS.\p"
	.string "Si me traes dos MINI SETAS o una\n"
	.string "SETA GRANDE, le enseñaré un\l"
	.string "movimiento a uno de tus POKéMON.$"

TwoIsland_House_Text_WantMeToTeachMove::
	.string "Sniff, sniff...\n"
	.string "¡Mmm! ¡Hueles a SETA!\p"
	.string "¿Quieres que le enseñe un\n"
	.string "movimiento a uno de tus POKéMON?$"

TwoIsland_House_Text_TutorWhichMon::
	.string "¿Qué POKéMON quieres que lo aprenda?$"

TwoIsland_House_Text_TeachWhichMove::
	.string "¿Qué movimiento quieres que aprenda?$"

TwoIsland_House_Text_NoMoveICanTeachThatMon::
	.string "Perdona...\p"
	.string "Parece que no puedo enseñar ningún\n"
	.string "movimiento a ese POKéMON...$"

TwoIsland_House_Text_IllNeedMushroomOrTwo::
	.string "Pues tendrás que darme una SETA\n"
	.string "o un par de ellas.\l"
	.string "¿Qué me das?$"

TwoIsland_House_Text_HandedOverTwoTinyMushrooms::
	.string "{PLAYER} entregó dos MINI SETAS\n"
	.string "a cambio de la lección.$"

TwoIsland_House_Text_HandedOverOneBigMushroom::
	.string "{PLAYER} entregó una SETA GRANDE\n"
	.string "a cambio de la lección.$"

TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove::
	.string "Si quieres que le enseñe un\n"
	.string "movimiento a algún POKéMON,\l"
	.string "tráeme una SETA o dos.$"

TwoIsland_House_Text_CantTeachAnEgg::
	.string "¿Eh? No puedo enseñar absolutamente\n"
	.string "ningún movimiento a un HUEVO…$"

