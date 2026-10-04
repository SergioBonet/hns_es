MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Gracias por usar el sistema de\n"
	.string "REGALO MISTERIOSO.\p"
	.string "Tú debes de ser {PLAYER}.\n"
	.string "Hay un billete aquí para ti.$"

sText_MysticTicketUseAtPort:
	.string "Parece que puedes usarlo en el\n"
	.string "PUERTO de CIUDAD CALAGUA.\p"
	.string "¿Por qué no curioseas un poco\n"
	.string "para ver de qué se trata?$"

sText_MysticTicketThankYou:
	.string "Gracias por usar el sistema de\n"
	.string "REGALO MISTERIOSO.$"

sText_MysticTicketBagFull:
	.string "Oh, lo siento, {PLAYER}.\n"
	.string "El bolsillo OBJ. CLAVE de tu MOCHILA\l"
	.string "está lleno.\p"
	.string "Guarda algo en tu PC y vuelve\n"
	.string "a por esto.$"
