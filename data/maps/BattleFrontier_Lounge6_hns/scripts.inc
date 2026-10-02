BattleFrontier_Lounge6_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader_hns::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted_hns
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns, BattleFrontier_Lounge6_EventScript_DeclineTrade_hns, BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade_hns::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted_hns::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns:
	.string "Mi POKéMON es un {STR_VAR_2}.\n"
	.string "¿Lo conoces?\l"
	.string "¿A que es una monada?\p"
	.string "Si quieres, te lo cambio por uno tuyo.\p"
	.string "¿Qué tal cambiar tu {STR_VAR_1}\n"
	.string "por mi {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns:
	.string "¡Oh, es adorable!\n"
	.string "¡Gracias!\l"
	.string "¡Te prometo que me portaré bien con él!\p"
	.string "¡Y espero que tú también\n"
	.string "te portes bien con mi {STR_VAR_2}!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns:
	.string "¡Oh, lo siento!\n"
	.string "Sólo lo cambio por un {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo_hns:
	.string "Ah, ¿que no?\n"
	.string "Bueno, a mí, plin.\l"
	.string "En fin, ya sabes dónde me tienes.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns:
	.string "¡Ji, ji, ji!\n"
	.string "SKITTY es mucho más mono de lo\l"
	.string "que pensaba. ¡Estoy encantadísima!$"
