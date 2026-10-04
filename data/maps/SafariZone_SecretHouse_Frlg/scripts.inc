SafariZone_SecretHouse_Frlg_MapScripts::
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM03, SafariZone_SecretHouse_EventScript_ExplainSurf
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM03
	goto_if_eq VAR_RESULT, FALSE, SafariZone_SecretHouse_EventScript_NoRoomForHM03
	giveitem_msg SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant, ITEM_HM03
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_GOT_HM03
	release
	end

SafariZone_SecretHouse_EventScript_NoRoomForHM03::
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_EventScript_ExplainSurf::
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	release
	end

SafariZone_SecretHouse_Text_CongratsYouveWon::
	.string "¡Ah! ¡Por fin!\p"
	.string "¡Eres la primera persona que llega\n"
	.string "a la CASA SECRETA!\p"
	.string "He organizado un concurso con\n"
	.string "motivo de nuestra inauguración.\p"
	.string "Y estaba empezando a preocuparme\n"
	.string "que nadie ganara nuestro premio.\p"
	.string "¡Enhorabuena!\n"
	.string "¡Has ganado!$"

SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant::
	.string "¡{PLAYER} recibió una MO03\n"
	.string "del empleado!$"

SafariZone_SecretHouse_Text_ExplainSurf::
	.string "¡La MO03 es SURF!\p"
	.string "¡Un POKéMON podrá llevarte\n"
	.string "por el agua!\p"
	.string "¡Y esta MO puede ser utilizada\n"
	.string "una y otra vez!\p"
	.string "¡Tienes muchísima suerte!\n"
	.string "¡Te llevas un fabuloso premio!$"

SafariZone_SecretHouse_Text_DontHaveRoomForPrize::
	.string "¡No tienes sitio para este premio\n"
	.string "tan fabuloso!$"

