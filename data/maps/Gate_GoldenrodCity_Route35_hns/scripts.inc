Gate_GoldenrodCity_Route35_hns_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "¡Perdona, joven! ¿Puedes hacerme un\n"
	.string "favor?\p"
	.string "¿Puedes darle este POKéMON con CARTA\n"
	.string "a mi amigo?\p"
	.string "Está en la RUTA 31.$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "¿Lo harás? Genial. ¡Gracias, joven!\p"
	.string "Mi amigo es un chico gordinflón que\n"
	.string "siempre está durmiendo.\p"
	.string "¡Le reconocerás enseguida!$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER} recibió POKéMON con CARTA.$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "¡Ponlo el primero de tu equipo cuando\n"
	.string "encuentres a mi amigo!\p"
	.string "¡RUTA 31!\p"
	.string "Ah, sí. Había un árbol muy raro\n"
	.string "cortando el camino.\p"
	.string "¿Lo habrán quitado ya?$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "No puedes llevar otro POKéMON…$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "¡Oh…! Entonces, no importa…$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "¡Gracias, joven! ¡Muchas gracias por\n"
	.string "habérselo llevado!\p"
	.string "¡Toma esto por las molestias!$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "¿A que mi amigo estaba durmiendo? Te\n"
	.string "lo dije.$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "Un extraño árbol bloquea el camino.\p"
	.string "Si le hablas, se mueve.\p"
	.string "Dicen que se volvió loco cuando\n"
	.string "alguien lo mojó con una REGADERA.$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "Me gusta la Nana POKéMON que ponen en\n"
	.string "la radio.$"

Route35GoldenrodGate_Text_Fisher:
	.string "Me pregunto cuántas clases de\n"
	.string "POKéMON habrá en el mundo.\p"
	.string "Hace tres años, el PROF. OAK dijo que\n"
	.string "había 150.\p"
	.string "¡Pero hace poco oí que hay más de 400!$"
