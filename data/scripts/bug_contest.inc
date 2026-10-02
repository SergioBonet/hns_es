BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3

	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 5
	waitstate
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	clearflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSportBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK_HNS, 7, 2
	waitstate
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK_HNS, 35, 7
	waitstate
	releaseall
	end

BugContest_Text_Judging0::
	.string "El concurso ha terminado.\p"
	.string "Elige el POKéMON que quieras quedarte\n"
	.string "y que se va a evaluar.$"

BugContest_Text_Judging1::
	.string "Ahora vamos a evaluar los POKéMON que\n"
	.string "habéis atrapado.\p"
	.string "……\p"
	.string "¡Ya tenemos a los ganadores! ¿Estáis\n"
	.string "preparados?$"

BugContest_Text_WrongChoiceMon:
	.string "Elige el POKéMON que quieras quedarte\n"
	.string "y que se va a evaluar.$"

BugContest_Text_DidntCatch:
	.string "¡Oh, no! No has atrapado ningún\n"
	.string "POKéMON. Quedas descalificado.\p"
	.string "Ahora te devolveremos tu equipo.$"

BugContest_Text_TimesUp:
	.string "¡Tilín, tilín! ¡Se acabó el tiempo!$"

BugContest_Text_WhiteOut:
	.string "{PLAYER} no tiene POKéMON en\n"
	.string "condiciones. {PLAYER} se ha retirado\l"
	.string "del concurso.$"

BugContest_Text_First1:
	.string "¡En tercer lugar queda la ENTRE. GUAY\n"
	.string "BELINDA, que atrapó un BUTTERFREE\l"
	.string "muy inquieto!$"
BugContest_Text_First2:
	.string "¡En segundo lugar queda el CAZABICHOS\n"
	.string "SHAUN, que atrapó un PINSIR muy\l"
	.string "revoltoso!$"
BugContest_Text_First3:
	.string "Y, finalmente, el primer puesto de este\n"
	.string "Concurso de Captura de Bichos es…\p"
	.string "¡para el {STR_VAR_1} que ha atrapado\n"
	.string "{PLAYER}!\p"
	.string "$"

BugContest_Text_Second1:
	.string "¡En tercer lugar queda la ENTRE. GUAY\n"
	.string "BELINDA, que atrapó un BUTTERFREE\l"
	.string "muy inquieto!$"
BugContest_Text_Second2:
	.string "¡En segundo lugar queda {PLAYER}, que\n"
	.string "atrapó un {STR_VAR_1} muy revoltoso!$"
BugContest_Text_Second3:
	.string "El ganador de este Concurso de\n"
	.string "Captura de Bichos es…\p"
	.string "¡el CAZABICHOS SHAUN, que atrapó un\n"
	.string "PINSIR enorme!$"

BugContest_Text_Third1:
	.string "¡En tercer lugar queda {PLAYER}, que\n"
	.string "atrapó un {STR_VAR_1} muy inquieto!$"
BugContest_Text_Third2:
	.string "¡En segundo lugar queda la ENTRE. GUAY\n"
	.string "BELINDA, que atrapó un BUTTERFREE\l"
	.string "muy revoltoso!$"
BugContest_Text_Third3:
	.string "El ganador de este Concurso de\n"
	.string "Captura de Bichos es…\p"
	.string "¡el CAZABICHOS SHAUN, que atrapó un\n"
	.string "PINSIR enorme!$"

BugContest_Text_TakePartInFuture:
	.string "¡Gracias por participar! Esperamos\n"
	.string "que vuelvas a participar en el futuro.$"

BugContest_Text_TransferAndReturn:
	.string "El POKéMON de tipo BICHO que has\n"
	.string "elegido se enviará ahora al PC, y te\l"
	.string "devolveremos tu equipo.$"
