FuchsiaCity_House3_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House3_EventScript_MoveDeleter::
	lock
	faceplayer
	msgbox FuchsiaCity_House3_Text_WouldYouLikeToForgetMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter::
	msgbox FuchsiaCity_House3_Text_WhichMonShouldForgetMove
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, FuchsiaCity_House3_EventScript_CancelForgetMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_House3_EventScript_CantForgetMoveEgg
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_House3_EventScript_CantForgetOnlyMove
	msgbox FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ForgetMove
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ForgetMove::
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely
	release
	end

FuchsiaCity_House3_EventScript_CantForgetOnlyMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonOnlyKnowsOneMove
	release
	end

FuchsiaCity_House3_EventScript_CantForgetMoveEgg::
	msgbox FuchsiaCity_House3_Text_NoEggShouldKnowMoves
	release
	end

FuchsiaCity_House3_EventScript_CancelForgetMove::
	msgbox FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves
	release
	end

FuchsiaCity_House3_Text_WouldYouLikeToForgetMove::
	.string "Eh… Ah, hola.\n"
	.string "Soy el QUITA-MOVIMIENTOS.\p"
	.string "Puedo hacer que los POKéMON\n"
	.string "olviden sus movimientos.\p"
	.string "¿Quieres que me ocupe de los tuyos?$"

FuchsiaCity_House3_Text_WhichMonShouldForgetMove::
	.string "¿Qué POKéMON debería olvidar\n"
	.string "algún movimiento?$"

FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten::
	.string "¿Qué movimiento debería\n"
	.string "olvidar?$"

FuchsiaCity_House3_Text_MonOnlyKnowsOneMove::
	.string "{STR_VAR_1} parece conocer un\n"
	.string "solo movimiento…$"

FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten::
	.string "Ajá. ¿{STR_VAR_2} de {STR_VAR_1}?\n"
	.string "¿Ése quieres? ¿De verdad?$"

FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely::
	.string "¡Ha salido de perlas!\p"
	.string "{STR_VAR_1} ha olvidado\n"
	.string "completamente {STR_VAR_2}.$"

FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves::
	.string "Vuelve si hay otros movimientos\n"
	.string "que olvidar.$"

FuchsiaCity_House3_Text_NoEggShouldKnowMoves::
	.string "¿Cómo?\n"
	.string "Un HUEVO no puede saber\l"
	.string "ningún movimiento.$"

