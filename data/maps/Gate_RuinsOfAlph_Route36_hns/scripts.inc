Gate_RuinsOfAlph_Route36_hns_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "RUINAS ALFA\p"
	.string "Lugar turístico para observar y\n"
	.string "tocar.\p"
	.string "¡Intenta mover los paneles de piedra!$"

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "¿Estás estudiando las RUINAS?\p"
	.string "Podrías dedicarte a la ciencia.$"

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "Hay dibujos en los paneles de piedra.\p"
	.string "Intenté moverlos. Me pregunto qué\n"
	.string "serán.$"
