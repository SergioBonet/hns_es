VioletCity_House1_hns_MapScripts::
	.byte 0

VioletCity_House1_EventScript_Kyle::
	lock
	faceplayer
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House1_EventScript_Rudy::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, VioletCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_ONIX, VioletCity_House1_Text_YouWillTradeWontYou, VioletCity_House1_EventScript_DeclineTrade, VioletCity_House1_EventScript_NotRequestedMon, VioletCity_House1_Text_MonYouTakeCare
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	release
	end

VioletCity_House1_EventScript_DeclineTrade::
	msgbox VioletCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VioletCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_TradeCompleted::
	msgbox VioletCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_Text_YouWillTradeWontYou:
	.string "¡Colecciono POKéMON! ¿Tienes un\n"
	.string "{STR_VAR_1}?\p"
	.string "¿Quieres cambiármelo por mi\n"
	.string "{STR_VAR_2}?$"

VioletCity_House1_Text_MonYouTakeCare:
	.string "¡Bien! ¡He conseguido un {STR_VAR_1}!\p"
	.string "¡{STR_VAR_2}, cuídate!$"

VioletCity_House1_Text_ThisIsntAMon:
	.string "Vaya, pues va a ser que no.\n"
	.string "Eso no es un {STR_VAR_1}.$"

VioletCity_House1_Text_YouWontTradeMe:
	.string "¿No quieres cambiarlo? ¡Bah!$"

VioletCity_House1_Text_After:
	.string "Hola, ¿cómo está mi ONIX?$"

VioletCity_House1_Text_PokefanM:
	.string "Los POKéMON que se intercambian\n"
	.string "crecen rápido.\p"
	.string "Pero, si no tienes la MEDALLA\p"
	.string "adecuada, podrían desobedecerte.$"
