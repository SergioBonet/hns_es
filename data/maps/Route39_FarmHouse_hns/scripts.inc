Route39_FarmHouse_hns_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "Mi MILTANK ya no me da leche.\p"
	.string "La leche de esta GRANJA es famosa.\p"
	.string "Casi todo el mundo quiere probarla.\p"
	.string "Si le doy muchas BAYAS, supongo que me\n"
	.string "dará mucha leche.$"

Route39_Text_FarmerMBuyMilk:
	.string "¿Te gusta mi LECHE MU-MU?\p"
	.string "Es mi orgullo y mi alegría.\p"
	.string "¡Dásela a los POKéMON para restaurar\n"
	.string "sus PS!\p"
	.string "Tuya es por sólo 500¥.$"

Route39_Text_FarmerMGotMilk:
	.string "¡Toma! ¡Bébetela y disfruta!$"

Route39_Text_FarmerMNoMoney:
	.string "Lo siento. ¡Si no hay dinero, no hay\n"
	.string "trato!$"

Route39_Text_FarmerMNoRoom:
	.string "Vaya, tu MOCHILA está llena.$"

Route39_Text_FarmerMNoSale:
	.string "¿No la quieres? Vuelve otro día.$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "¿Qué tal otra?$"

Route39_Text_GotMilk:
	.string "¡{PLAYER} ha conseguido LECHE MU-MU!$"

Route39_Text_FarmerMMilking:
	.string "Mejor que me vaya a ordeñar.$"

Route39_Text_FarmerFInTrouble:
	.string "Nuestra leche llega hasta KANTO.\p"
	.string "Así que si nuestra MUU-MUU no nos da\n"
	.string "leche, tendremos problemas.$"

Route39_Text_FarmerFHealedMiltank:
	.string "Has curado a nuestra MUU-MUU.\p"
	.string "Ya vuelve a dar LECHE MU-MU.\p"
	.string "Aquí tienes algo que te ayudará.$"

Route39_Text_FarmerFSnatchSpeech:
	.string "Esto es ROBO.\p"
	.string "Es un movimiento muy astuto que\n"
	.string "permite a un POKéMON robar el\l"
	.string "movimiento del rival justo antes de\l"
	.string "que lo use.\p"
	.string "Si más de un POKéMON usa ROBO, solo el\n"
	.string "más lento acabará robando el\l"
	.string "movimiento.\p"
	.string "Úsalo con cabeza, cielo. Todo es\n"
	.string "cuestión de saber elegir el momento.$"
