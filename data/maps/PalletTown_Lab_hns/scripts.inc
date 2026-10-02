PalletTown_Lab_hns_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_OakBadgeCheck
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_ROUTE28_SCIENTIST, 1
	setvar VAR_PALLETTOWN_LABSTATE, 2
	call_if_unset FLAG_IS_KANTO_CHAMPION, PalletTown_Lab_EventScript_OakKantoLeague
	release
	end

PalletTown_Lab_EventScript_OakKantoLeague::
	msgbox PalletTown_Lab_Text_OakOpenIndigoPlateau, MSGBOX_DEFAULT
	closemessage
	return

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "¿Qué tal va tu POKéDEX?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "OAK: ¡Ah, {PLAYER}! Me alegra que hayas\n"
	.string "venido hasta KANTO.\p"
	.string "¿Qué te parecen los ENTRENADORES de\n"
	.string "por aquí? Bastante duros, ¿eh?$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "Si pasas por aquí, espero que vengas a\n"
	.string "visitarme.$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "OAK: ¡Uau! ¡Excelente!\p"
	.string "¡Has conseguido las MEDALLAS de los\n"
	.string "GIMNASIOS de KANTO! ¡Bien hecho!\p"
	.string "No me equivocaba contigo.\p"
	.string "Te diré una cosa, {PLAYER}. Haré lo\n"
	.string "necesario para que puedas ir al MT.\l"
	.string "PLATEADO.\p"
	.string "El MT. PLATEADO es una gran montaña\n"
	.string "donde viven muchos POKéMON salvajes.\p"
	.string "Es demasiado peligroso para un\n"
	.string "ENTRENADOR normal, así que está\l"
	.string "prohibido el paso. Pero en tu caso\l"
	.string "podemos hacer una excepción,\l"
	.string "{PLAYER}.\p"
	.string "Sube a la MESETA AÑIL. Desde allí\n"
	.string "podrás llegar al MT. PLATEADO.$"

PalletTown_Lab_Text_OakOpenIndigoPlateau:
	.string "Ah, y hablando de la MESETA AÑIL:\n"
	.string "ahora que tienes 16 medallas, la LIGA\l"
	.string "de KANTO estará lista para aceptar de\l"
	.string "nuevo tu desafío.\p"
	.string "Pero te aviso: esta vez LANCE y su\n"
	.string "ALTO MANDO no te lo pondrán fácil.\p"
	.string "¡Buena suerte, {PLAYER}!$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "OAK: ¿Cómo? ¿No has conseguido las\n"
	.string "MEDALLAS DE KANTO?\p"
	.string "Los LÍDERES de los GIMNASIOS de\n"
	.string "KANTO\p"
	.string "son tan fuertes como los de JOHTO.\p"
	.string "Te aconsejo que te enfrentes a ellos.$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "OAK: Ah, estás reuniendo las MEDALLAS\n"
	.string "de los GIMNASIOS de KANTO.\p"
	.string "Me imagino que es difícil, pero la\n"
	.string "experiencia seguro que te será útil.\p"
	.string "Ven a verme cuando las tengas todas.\p"
	.string "Tendré un regalo para ti.\p"
	.string "¡Sigue esforzándote, {PLAYER}!$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "El programa de la HORA POKéMON\p"
	.string "del PROF. OAK no se emite aquí, en\n"
	.string "KANTO.\p"
	.string "¡Qué pena! ¡Me gustaría oírlo!$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "Gracias a tu POKéDEX, la investigación\n"
	.string "del profesor está avanzando.$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "No se lo digas a nadie, pero la\p"
	.string "HORA DE OAK no es en directo.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "Hay un correo electrónico en el PC.\p"
	.string "…\p"
	.string "PROF. OAK, ¿cómo va su investigación?\p"
	.string "Yo sigo con la mía.\p"
	.string "He oído rumores de que {PLAYER} se\n"
	.string "está haciendo una buena reputación.\p"
	.string "Me alegra mucho oírlo.\p"
	.string "ELM, de PUEBLO PRIMAVERA 8-)$"
