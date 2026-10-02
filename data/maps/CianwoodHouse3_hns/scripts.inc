CianwoodHouse3_hns_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	goto_if_set FLAG_BADGE01_GET, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "¡Estoy alucinado!\p"
	.string "Vino un chico de tu edad, de pelo largo\n"
	.string "y mirada penetrante.\p"
	.string "¡Y me obligó a darle mis queridos\n"
	.string "POKéMON!\p"
	.string "Todavía me queda uno, ¿pero qué hago\n"
	.string "si vuelve?\p"
	.string "Pareces fuerte. ¿Podrías cuidar de mi\n"
	.string "POKéMON durante un rato?$"

CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "¡Oh, gracias!\p"
	.string "¡Cuídale bien, por favor!$"

CianwoodCity_Text_ManiacGotShuckle:
	.string "{PLAYER} recibió un POKéMON.$"

CianwoodCity_Text_ManiacPartyFull:
	.string "No puedes llevar más POKéMON.$"

CianwoodCity_Text_ManiacIfHeComesBack:
	.string "¡Oh, no…! ¿Y qué hago si vuelve?$"

CianwoodCity_Text_ManiacHowsdoing:
	.string "¡Hola! ¿Cómo está mi POKéMON?$"

CianwoodCity_Text_ManiacAskReturn:
	.string "¡Hola! ¿Cómo está mi POKéMON?\p"
	.string "Creo que ya pasó el peligro. ¿Me lo\n"
	.string "devuelves?$"

CianwoodCity_Text_ManiacThankYou:
	.string "¡Gracias!$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "¡Oye! ¡No llevas a mi POKéMON contigo!$"

CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "Mi POKéMON te ha tomado cariño.\p"
	.string "¡Vale! ¡Quédatelo, pero prométeme que\n"
	.string "serás amable con él!$"

CianwoodCity_Text_ManiacRobbed:
	.string "Huh, something's not right.$"

CianwoodCity_Text_ManiacRobbed2:
	.string "¡Oh, no, no…! Es como si me hubieran\n"
	.string "robado.$"

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "Para los POKéMON, la felicidad es\n"
	.string "estar con quien los quiere.$"

CianwoodCity_Text_ManiacLastMon:
	.string "Si me llevo a mi POKéMON, ¿cómo\n"
	.string "lucharás?$"


CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER} returned SHUCKIE.$"
