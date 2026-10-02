CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "No recuerdo la última vez que alguien\n"
	.string "vino a visitarme.\p"
	.string "De joven, yo también fui ENTRENADOR\n"
	.string "POKéMON. Intenté llegar a la torre y\l"
	.string "sumergirme en el océano.\p"
	.string "Me esforcé mucho en muchas cosas.\p"
	.string "Bueno, ahora me lo tomo con calma,\n"
	.string "escuchando las olas y el viento en\l"
	.string "esta playa.$"

CianwoodCity_Text_BellTowerStory:
	.string "¿Has oído hablar de la TORRE CAMPANA\n"
	.string "de CIUDAD IRIS?\p"
	.string "En lo alto de la torre hay unos\n"
	.string "cascabeles llamados Cascabeles\l"
	.string "Claros.\p"
	.string "No hacen ni un ruido aunque sople un\n"
	.string "viento fuerte.\p"
	.string "Solo hay una forma de hacerlos sonar.\p"
	.string "Conseguir otro CASCABEL CLARO igual\n"
	.string "que los de lo alto de la torre.\p"
	.string "Yo lo intenté de joven. Pero nunca\n"
	.string "conseguí uno…$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "¿Has oído hablar de las ISLAS\n"
	.string "REMOLINO?\p"
	.string "En la poza de su cascada hay unos\n"
	.string "cascabeles llamados Cascabeles\l"
	.string "Oleaje.\p"
	.string "No hacen ni un ruido aunque rompan las\n"
	.string "olas.\p"
	.string "Solo hay una forma de hacerlos sonar.\p"
	.string "Conseguir otro CASCABEL OLEAJE igual\n"
	.string "que los de la poza de la cascada.\p"
	.string "Yo lo intenté de joven. Pero nunca\n"
	.string "conseguí uno…$"

CianwoodCity_Text_ClearBellReaction:
	.string "¡Oh! ¿Has conseguido un CASCABEL\n"
	.string "CLARO?\p"
	.string "Mi viejo sueño… Ya veo…\p"
	.string "Lo has conseguido… … ¡Lo oigo!\p"
	.string "El tintineo de los cascabeles en el\n"
	.string "viento que viene de la TORRE CAMPANA…$"

CianwoodCity_Text_TidalBellReaction:
	.string "¡Oh! ¿Has conseguido un CASCABEL\n"
	.string "OLEAJE?\p"
	.string "Mi viejo sueño… Ya veo…\p"
	.string "Lo has conseguido… … ¡Lo oigo!\p"
	.string "El tintineo de los cascabeles en la\n"
	.string "brisa marina que viene de las ISLAS\l"
	.string "REMOLINO…$"
