Gate_Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Gate_Route43_Rocket_OnFrame
	.byte 0

Gate_Route43_Rocket_OnFrame::
	map_script_2 VAR_TEMP_0, 0, Gate_Route43_RocketChecker
	.2byte 0

Gate_Route43_RocketChecker::
	setvar VAR_TEMP_0, 1
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 1, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 2, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 4, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 5, Gate_Route43_Rocket_EventScript_Shakedown
	end

Gate_Route43_Rocket_EventScript_Shakedown::
	lock
	showmoneybox 0, 0
	msgbox Gate_Route43_Rocket_Text_TollFee, MSGBOX_DEFAULT
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_ShakedownBroke
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_ShakedownBroke::
	checkmoney 1
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_KickOut
	msgbox Gate_Route43_Rocket_Text_AllYouGot, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_KickOut::
	msgbox Gate_Route43_Rocket_Text_KickOut, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_Policeman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_FROM_MAHOGANY_COP, Gate_Route43_Rocket_EventScript_PolicemanAfter
	msgbox Route43Gate_Text_OfficerFoundTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	setflag FLAG_GOT_TM_FROM_MAHOGANY_COP
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_PolicemanAfter::
	msgbox Gate_Route43_Text_OfficerAvoidGrass, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_Rockets::
	msgbox Gate_Route43_Rocket_Text_MakingABundle, MSGBOX_NPC
	end

Gate_Route43_Rocket_Text_TollFee:
	.string "¡Alto ahí, chaval!\p"
	.string "El peaje para pasar es de ¥500.$"

Gate_Route43_Rocket_Text_ThankYou:
	.string "¡Gracias, joven!$"

Gate_Route43_Rocket_Text_AllYouGot:
	.string "Entonces paga lo que tengas.$"

Gate_Route43_Rocket_Text_KickOut:
	.string "¡Vaya!\p"
	.string "¡No tienes ni un céntimo!\p"
	.string "Casi me das pena.\p"
	.string "Vale, puedes pasar…\p"
	.string "Pero no se lo digas al otro guardia,\n"
	.string "¿vale?$"

Gate_Route43_Rocket_Text_MakingABundle:
	.string "¡Je, je! Nos estamos forrando.\p"
	.string "Todo el mundo quiere ver lo que ocurre\n"
	.string "en el LAGO DE LA FURIA.$"

Route43Gate_Text_OfficerFoundTM:
	.string "Esos gamberros de negro me echaron de\n"
	.string "mi puesto.\p"
	.string "Se dejaron esto. Me molesta.\p"
	.string "¿Podrías llevártelo?$"

Gate_Route43_Text_ReceivedTM30:
	.string "¡{PLAYER} ha recibido la MT36!$"

Gate_Route43_Text_OfficerAvoidGrass:
	.string "Usa esta puerta para no andar por la\n"
	.string "hierba.$"
