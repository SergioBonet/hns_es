GoldenrodCity_House1_hns_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_ToggleShinies::
	lock
	msgbox GoldenrodCity_NameRatersHouse_Text_AskToggleShinies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused
	@special ToggleShinyColors
	msgbox GoldenrodCity_NameRatersHouse_Text_ToggleShinies, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused::
	release
	end

GoldenrodCity_NameRatersHouse_Text_AskToggleShinies:
	.string "¿Quieres activar o desactivar los\n"
	.string "colores variocolor únicos?$"

GoldenrodCity_NameRatersHouse_Text_ToggleShinies:
	.string "¡Ajuste de colores variocolor\n"
	.string "cambiado!\p"
	.string "Puedes verlo en el VISOR DE DESAFÍOS\n"
	.string "de cualquier PC.$"

GoldenrodCity_NameRatersHouse_EventScript_RenameRival::
	msgbox GoldenrodCity_NameRatersHouse_Text_RenameRival, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	end

GoldenrodCity_NameRatersHouse_Text_RenameRival:
	.string "Son las noticias…\p"
	.string "¡La POLICÍA busca a este CHICO\n"
	.string "PELIRROJO!\p"
	.string "¿Sabes TÚ cómo se llama?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "¡Je, je! ¡Hola! ¡Soy el INSPECTOR\n"
	.string "de los MOTES! ¡El adivinador de nombres!\p"
	.string "Estaré encantado de evaluar\n"
	.string "el nombre de tu POKéMON, je, je.$"

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "¿Qué mote de POKéMON quieres que\n"
	.string "evalúe?$"

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Mmmmm… {STR_VAR_1}, ¿a que sí?\n"
	.string "No está mal, no está mal…\p"
	.string "Pero ¿no crees que podríamos\n"
	.string "encontrar un nombre aún mejor?$"

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Así me gusta. A ver…\n"
	.string "¿Cuál será el nuevo nombre?$"

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "¡Ya está! ¡A partir de ahora, el nombre\n"
	.string "de este POKéMON será {STR_VAR_1}!\p"
	.string "Es un nombre mucho mejor que\n"
	.string "el anterior, ¡qué suerte tienes!$"

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Entiendo…\n"
	.string "Entonces vuelve cuando quieras.$"

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "¡Ya está! ¡A partir de ahora, el nombre\n"
	.string "de este POKéMON será {STR_VAR_1}!\p"
	.string "No parece muy diferente del anterior\n"
	.string "y, sin embargo, es muchísimo mejor.\l"
	.string "¡Qué suerte tienes!$"

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "Mmmm… ¡Será {STR_VAR_1}!\p"
	.string "¡He aquí un mote magnífico!\n"
	.string "¡Absolutamente irreprochable!\p"
	.string "Harás bien en querer mucho\n"
	.string "a tu {STR_VAR_1} de ahora en adelante.$"

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Pero vamos a ver… ¡Esto es solo un\n"
	.string "Huevo!$"


