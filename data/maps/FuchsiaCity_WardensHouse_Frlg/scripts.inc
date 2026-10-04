FuchsiaCity_WardensHouse_Frlg_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	call EventScript_RestorePrevTextColor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksMale
	call_if_eq VAR_RESULT, FEMALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale
	giveitem_msg FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden, ITEM_HM04
	setflag FLAG_GOT_HM04
	removeitem ITEM_GOLD_TEETH
	release
	end

FuchsiaCity_WardensHouse_EventScript_WardenThanksMale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
	.string "GUARDA: ¡Fii, fuff, fefifu!\p"
	.string "A fof, a fif ee afahi fo.\n"
	.string "¡Eeff fi fui!$"

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
	.string "¡Ah fafee, oo foo!\n"
	.string "¡Eef ee afafi fo!$"

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
	.string "¿Ah?\n"
	.string "¡Fe ofay fe fa foo ii fafef!$"

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
	.string "¡{PLAYER} le dio los DIENTES\n"
	.string "de ORO al GUARDA!$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
	.string "¡El GUARDA se puso los dientes!$"

FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething::
	.string "GUARDA: ¡Gracias, majo!\n"
	.string "¡Menos mal!\p"
	.string "No había quien me entendiera,\n"
	.string "vamos, ¡no me entendía ni yo!\p"
	.string "¡Me daba vergüenza hasta ir\n"
	.string "a trabajar!\p"
	.string "¡Te daré algo por las molestias!$"

FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething::
	.string "GUARDA: ¡Gracias, maja!\n"
	.string "¡Menos mal!\p"
	.string "No había quien me entendiera,\n"
	.string "vamos, ¡no me entendía ni yo!\p"
	.string "¡Me daba vergüenza hasta ir\n"
	.string "a trabajar!\p"
	.string "¡Te daré algo por las molestias!$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
	.string "¡{PLAYER} recibió la MO04\n"
	.string "de manos del GUARDA!$"

FuchsiaCity_WardensHouse_Text_ExplainStrength::
	.string "GUARDA: ¡La MO04 enseña FUERZA!\p"
	.string "Tus POKéMON podrán mover rocas\n"
	.string "siempre que quieras.\p"
	.string "¿Encontraste la CASA SECRETA\n"
	.string "en la ZONA del SAFARI?$"

@ Unused
FuchsiaCity_WardensHouse_Text_YouHaveTooMuchStuff::
	.string "¡Vaya, llevas el\n"
	.string "equipaje lleno!$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
	.string "Hay fotos y fósiles de POKéMON\n"
	.string "en exposición.$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
	.string "Hay mercancía POKéMON antigua\n"
	.string "en exposición.$"

