PewterCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY_HNS
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "¡Sí! Ya no hay GIMNASIO en la\p"
	.string "ISLA CANELA. Me quedé de piedra.\p"
	.string "¿Sí? Estoy al teléfono. ¡Fuera!$"

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "JIGGLYPUFF: Puff, puff.$"

PewterCity_PokemonCenter_EventScript_Mondo::
	lock
	faceplayer
	goto_if_set FLAG_PEWTER_NPC_TRADE_COMPLETED, PewterCity_PokemonCenter_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HAUNTER, PewterCity_PokemonCenter_Text_WantToTrade, PewterCity_PokemonCenter_EventScript_DeclineTrade, PewterCity_PokemonCenter_EventScript_NotRequestedMon, PewterCity_PokemonCenter_Text_TakeCare
	setflag FLAG_PEWTER_NPC_TRADE_COMPLETED
	release
	end

PewterCity_PokemonCenter_EventScript_DeclineTrade::
	msgbox PewterCity_PokemonCenter_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_PokemonCenter_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_EventScript_TradeCompleted::
	msgbox PewterCity_PokemonCenter_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_Text_WantToTrade:
	.string "He viajado por todas partes buscando\n"
	.string "un buen {STR_VAR_1}.\p"
	.string "¿Me cambiarías uno por mi\n"
	.string "{STR_VAR_2}?$"

PewterCity_PokemonCenter_Text_TakeCare:
	.string "¡Muchísimas gracias! ¡Cuida bien de mi\n"
	.string "{STR_VAR_1}!$"

PewterCity_PokemonCenter_Text_DeclineTrade:
	.string "¿No? Qué pena… Creo que te gustaría\n"
	.string "mi HAUNTER.$"

PewterCity_PokemonCenter_Text_NotRequestedMon:
	.string "Mmm, eso no es un {STR_VAR_1}. No es lo\n"
	.string "que busco.$"

PewterCity_PokemonCenter_Text_TradeCompleted:
	.string "¿Qué tal te trata ese HAUNTER? ¡Es un\n"
	.string "auténtico bromista!$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "Casi todos los POKéMON se duermen al\n"
	.string "oír cantar a JIGGLYPUFF.\p"
	.string "Cuando un POKéMON está dormido, se\n"
	.string "pueden usar ciertos movimientos.$"
