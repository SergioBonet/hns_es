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
	.string "My MILTANK ain't givin' me\n"
	.string "milk no more.\p"
	.string "This here FARM's got famous milk.\p"
	.string "Most everyone wants a drink.\p"
	.string "It'll give me lots o' milk if'n\n"
	.string "I feed it lots o' BERRIES,\l"
	.string "I reckon.$"

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
	.string "How bout another?$"

Route39_Text_GotMilk:
	.string "{PLAYER} got MOOMOO MILK.$"

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
	.string "That there's SNATCH.\p"
	.string "It's a tricky move that lets\n"
	.string "a POKéMON steal a foe's move\l"
	.string "right before it's used.\p"
	.string "If more than one POKéMON use\n"
	.string "SNATCH, only the slowest one\l"
	.string "will end up stealing the move.\p"
	.string "Use it smart, hon. Timing is\n"
	.string "everything.$"
