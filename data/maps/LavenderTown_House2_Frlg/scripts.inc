LavenderTown_House2_Frlg_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseMon
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	waitstate
	goto_if_lt VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_CheckCanRateMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	msgbox LavenderTown_House2_Text_ISeeComeVisitAgain
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseNewNickname
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_Text_WantMeToRateNicknames::
	.string "¡Hola, hola!\n"
	.string "¡Soy el INSPECTOR de MOTES oficial!\p"
	.string "¿Quieres que valore los motes de\n"
	.string "tus POKéMON?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
	.string "¿Qué nombre de POKéMON\n"
	.string "quieres que adivine y evalúe?$"

LavenderTown_House2_Text_GiveItANicerName::
	.string "¿Será posible?\n"
	.string "¡Todo el mundo es fan tuyo!\p"
	.string "O sea, ¿que soy el único fan\n"
	.string "de {STR_VAR_1}?\p"
	.string "Bueno, en realidad, ¿qué más\n"
	.string "me da?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
	.string "Así me gusta. A ver…\n"
	.string "¿Cuál será el nuevo nombre?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
	.string "¡Ya está! ¡A partir de ahora, el nombre\n"
	.string "de este POKéMON será {STR_VAR_1}!\p"
	.string "Es un nombre mucho mejor que\n"
	.string "el anterior, ¡qué suerte tienes!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
	.string "Entiendo…\n"
	.string "Entonces vuelve cuando quieras.$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
	.string "¡Ya está! ¡A partir de ahora, el nombre\n"
	.string "de este POKéMON será {STR_VAR_1}!\p"
	.string "No parece muy diferente del anterior\n"
	.string "y, sin embargo, es muchísimo mejor.\l"
	.string "¡Qué suerte tienes!$"

LavenderTown_House2_Text_TrulyImpeccableName::
	.string "¿{STR_VAR_1}, dices?\n"
	.string "¡Es un nombre realmente impecable!\p"
	.string "¡Cuida bien de {STR_VAR_1}!$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
	.string "Pero vamos a ver…\n"
	.string "¡Esto es sólo un HUEVO!$"

