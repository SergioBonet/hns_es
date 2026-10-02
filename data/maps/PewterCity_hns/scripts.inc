PewterCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "Have you visited PEWTER GYM?\p"
	.string "The LEADER uses ROCK-type POKéMON.$"

PewterCity_Text_BugCatcher:
	.string "Por la noche, los CLEFAIRY salen a\n"
	.string "jugar al MT. MOON, pero no todas las\l"
	.string "noches.$"

PewterCity_Text_Gramps:
	.string "¡Vaya! ¿Vienes de JOHTO?\p"
	.string "Me trae muchos recuerdos. Cuando era\n"
	.string "joven, fui a JOHTO a entrenar.\p"
	.string "Te pareces mucho a mí cuando yo tenía\n"
	.string "tu edad.\p"
	.string "Me gustaría darte este objeto que\n"
	.string "encontré en JOHTO.$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "Visitar nuevos sitios y conocer gente\n"
	.string "nueva…\p"
	.string "Eso es lo bueno de viajar.$"

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "CIUDAD PLATEADA La ciudad de piedra\n"
	.string "grisácea$"

PewterCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD PLATEADA: BROCK\p"
	.string "El entrenador POKéMON más fuerte que\n"
	.string "la roca$"

PewterCity_Text_MuseumSign:
	.string "There's a notice here…\p"
	.string "PEWTER MUSEUM OF SCIENCE is closed for\n"
	.string "renovations…$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "Aquí hay una nota…\p"
	.string "¡TIENDA DE REGALOS MT. MOON abierta!$"

PewterCity_Text_WelcomeSign:
	.string "¡Bienvenidos a CIUDAD PLATEADA!$"

