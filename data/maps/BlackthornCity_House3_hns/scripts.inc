BlackthornCity_House3_hns_MapScripts::
	.byte 0

BlackthornCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, BlackthornCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox BlackthornCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

BlackthornCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "Eh… Ah, hola.\n"
	.string "Soy el QUITA-MOVIMIENTOS.\p"
	.string "Puedo hacer que los POKéMON\n"
	.string "olviden sus movimientos.\p"
	.string "¿Quieres que me ocupe de los tuyos?$"

BlackthornCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "¿Qué POKéMON debe olvidar\n"
	.string "movimientos?\p"
	.string "$"

BlackthornCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "¿Qué movimiento debe olvidar?$"

BlackthornCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "Parece que {STR_VAR_1} sólo sabe\n"
	.string "un movimiento…$"

BlackthornCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "Ajá. ¿{STR_VAR_2} de {STR_VAR_1}?\n"
	.string "¿Ése quieres? ¿De verdad?$"

BlackthornCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "¡Ha salido de perlas!\p"
	.string "{STR_VAR_1} ha olvidado\n"
	.string "completamente {STR_VAR_2}.$"

BlackthornCity_MoveDeletersHouse_Text_ComeAgain:
	.string "Vuelve por aquí si quieres que tus\n"
	.string "POKéMON olviden algún movimiento.$"

BlackthornCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "¿Cómo?\n"
	.string "Un HUEVO no puede saber\l"
	.string "ningún movimiento.$"

BlackthornCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "¡Ajá!\p"
	.string "Tu {STR_VAR_1} no tiene\n"
	.string "ganas de olvidar SURF.$"

BlackthornCity_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	faceplayer
	specialvar VAR_RESULT, IsRandomMovesActivated
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_Randomizer
	goto_if_set FLAG_TEMP_1, BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

BlackthornCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto BlackthornCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

BlackthornCity_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_EventScript_Randomizer::
	msgbox BlackthornCity_MoveRelearnersHouse_Text_SorryCantHelp, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BlackthornCity_MoveRelearnersHouse_Text_SorryCantHelp:
	.string "Lo siento, no puedo ayudarte.$"

BlackthornCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Soy el TUTOR de MOVIMIENTOS.\p"
	.string "Me sé todos los movimientos que\n"
	.string "aprenden los POKéMON. Todos, toditos,\l"
	.string "todos. Y además los puedo enseñar.\p"
	.string "Si quieres, puedo enseñar a uno\n"
	.string "de tus POKéMON un movimiento.\p"
	.string "Lo haré por una insignificante ESCAMA\n"
	.string "CORAZÓN. Es que las colecciono.$"

BlackthornCity_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "¡Sí! ¡Ésa es! ¡Una auténtica ESCAMA\n"
	.string "CORAZÓN! ¡Una de las de verdad!\p"
	.string "A ver que lo adivine, ¿quieres que\n"
	.string "enseñe un movimiento a tu POKéMON?$"

BlackthornCity_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "¿Qué POKéMON quieres que lo aprenda?\p"
	.string "$"

BlackthornCity_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "¿Qué movimiento quieres que aprenda?$"

BlackthornCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Perdona…\p"
	.string "Parece que no puedo enseñar ningún\n"
	.string "movimiento a ese POKéMON…$"

BlackthornCity_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} entregó una Escama Corazón a\n"
	.string "cambio.$"

BlackthornCity_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "Si tu POKéMON necesita aprender\n"
	.string "un movimiento, vuelve con una ESCAMA\l"
	.string "CORAZÓN.$"

BlackthornCity_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "¿Eh? No puedo enseñar absolutamente\n"
	.string "ningún movimiento a un HUEVO…$"



