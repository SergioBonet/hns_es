EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "¡Ah! ¿Vas de aventura con tus\n"
	.string "POKéMON?\p"
	.string "¿Y qué es una aventura sin un tesoro?\p"
	.string "¿Tengo razón o no?$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "¡Bien! Entiendes el verdadero\n"
	.string "espíritu de la aventura.\p"
	.string "¡Me gusta! Toma esto.$"

Ecruteak_Text_ItemfinderExplanation:
	.string "There are many items lying about\n"
	.string "that aren't obvious.\p"
	.string "Use DOWSING MACHINE to check if there\n"
	.string "is an item on the ground near you.\p"
	.string "It doesn't show the exact spot,\n"
	.string "so you'll have to look yourself.\p"
	.string "Oh yeah--I heard there are items\n"
	.string "in ECRUTEAK's BURNED TOWER.$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "¡Oh! A cada uno lo suyo, supongo…$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	checkitem ITEM_DOWSING_MACHINE
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_AlreadyGotItemfinder
	msgbox Ecruteak_Text_ItemfinderAdventure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_GiveItemFinder
	msgbox Ecruteak_Text_ItemfinderToEachHisOwn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_GiveItemFinder::
	msgbox Ecruteak_Text_ItemfinderTrueSpirit, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
EcruteakCity_House2_EventScript_AlreadyGotItemfinder::
	msgbox Ecruteak_Text_ItemfinderExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "ECRUTEAK is a very old city.\n"
	.string "Many generations passed down\l"
	.string "their history in books like these.$"

Ecruteak_Text_HistoryBook:
	.string "HISTORIA de CIUDAD IRIS\p"
	.string "¿Quieres leerla?$"

Ecruteak_Text_TwoTowers:
	.string "En CIUDAD IRIS había dos torres.\p"
	.string "Cada una acogía a un fuerte POKéMON\n"
	.string "volador.\p"
	.string "Pero una de ellas se quemó.\p"
	.string "Y desde entonces no se ha visto a\n"
	.string "ninguno de los dos POKéMON.\p"
	.string "¿Sigues leyendo?$"

Ecruteak_Text_ThreeMon:
	.string "En CIUDAD IRIS también vivían tres\n"
	.string "POKéMON que corrían por toda la\l"
	.string "ciudad.\p"
	.string "Dicen que habían nacido del agua, del\n"
	.string "fuego y del rayo.\p"
	.string "Pero como no podían contener su\n"
	.string "enorme fuerza…\p"
	.string "Huyeron hacia los pastos.$"
