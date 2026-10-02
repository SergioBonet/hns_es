BlackthornCity_House2_hns_MapScripts::
	.byte 0

BlackthornCity_House2_EventScript_Emy::
	lock
	faceplayer
	goto_if_set FLAG_BLACKTHORN_NPC_TRADE_COMPLETED, BlackthornCity_House2_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MR_MIME, BlackthornCity_House2_Text_YouWillTradeWontYou, BlackthornCity_House2_EventScript_DeclineTrade, BlackthornCity_House2_EventScript_NotRequestedMon, BlackthornCity_House2_Text_MonYouTakeCare
	setflag FLAG_BLACKTHORN_NPC_TRADE_COMPLETED
	release
	end

BlackthornCity_House2_EventScript_DeclineTrade::
	msgbox BlackthornCity_House2_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BlackthornCity_House2_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_TradeCompleted::
	msgbox BlackthornCity_House2_Text_After, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_Text_YouWillTradeWontYou:
	.string "¡Colecciono POKéMON! ¿Tienes un\n"
	.string "{STR_VAR_1}?\p"
	.string "¿Quieres cambiármelo por mi\n"
	.string "{STR_VAR_2}?$"

BlackthornCity_House2_Text_MonYouTakeCare:
	.string "¡Bien! ¡He conseguido un {STR_VAR_1}!\p"
	.string "¡{STR_VAR_2}, cuídate!$"

BlackthornCity_House2_Text_ThisIsntAMon:
	.string "Vaya, pues va a ser que no.\n"
	.string "Eso no es un {STR_VAR_1}.$"

BlackthornCity_House2_Text_YouWontTradeMe:
	.string "¿No quieres cambiarlo? ¡Bah!$"

BlackthornCity_House2_Text_After:
	.string "Hola, ¿qué tal está mi viejo MR. MIME?$"
