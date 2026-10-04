CeruleanCity_House5_Frlg_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BerryPowderMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POWDER_JAR, CeruleanCity_House5_EventScript_AskToExchangePowder
	msgbox CeruleanCity_House1_Text_AnyInterestInBerries, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_NoInterestInBerries
	goto_if_unset FLAG_SYS_GOT_BERRY_POUCH, CeruleanCity_House5_EventScript_NoBerries
	msgbox CeruleanCity_House1_Text_HaveJustTheThing
	setflag FLAG_GOT_POWDER_JAR
	giveitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner
	release
	end

CeruleanCity_House5_EventScript_NoBerries::
	msgbox CeruleanCity_House1_Text_WhyMustYouLieNoBerries
	release
	end

CeruleanCity_House5_EventScript_NoInterestInBerries::
	msgbox CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings
	release
	end

CeruleanCity_House5_EventScript_AskToExchangePowder::
	special DisplayBerryPowderVendorMenu
	msgbox CeruleanCity_House1_Text_HaveYouBroughtBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_ChooseExchangeItem::
	message CeruleanCity_House5_Text_ExchangeWithWhat
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, CeruleanCity_House5_EventScript_EnergyPowder
	case 1, CeruleanCity_House5_EventScript_EnergyRoot
	case 2, CeruleanCity_House5_EventScript_HealPowder
	case 3, CeruleanCity_House5_EventScript_RevivalHerb
	case 4, CeruleanCity_House5_EventScript_Protein
	case 5, CeruleanCity_House5_EventScript_Iron
	case 6, CeruleanCity_House5_EventScript_Carbos
	case 7, CeruleanCity_House5_EventScript_Calcium
	case 8, CeruleanCity_House5_EventScript_Zinc
	case 9, CeruleanCity_House5_EventScript_HPUp
	case 10, CeruleanCity_House5_EventScript_PPUp
	case 11, CeruleanCity_House5_EventScript_ExitMenu
	case 127, CeruleanCity_House5_EventScript_ExitMenu
	end

CeruleanCity_House5_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_ExitMenu::
	msgbox CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_ExchangePowderForItem::
	msgbox CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_ChooseExchangeItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_BagIsFull
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox CeruleanCity_House1_Text_TradeMoreBerryPowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeruleanCity_House5_EventScript_ChooseExchangeItem
	msgbox CeruleanCity_House1_Text_HopeToSeeYouAgain
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_BagIsFull::
	msgbox gText_TheBagIsFull
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_NotEnoughBerryPowder::
	msgbox CeruleanCity_House1_Text_DontHaveEnoughBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_BerryCrushRankings::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

CeruleanCity_House1_Text_AnyInterestInBerries::
	.string "Yo hago una especie de medicina\n"
	.string "a partir del POLVO de BAYA.\p"
	.string "Y si el POLVO de BAYA es bueno,\n"
	.string "hago unos mejunjes espectaculares.\p"
	.string "Bueno, a todo esto, ¿te gustan\n"
	.string "las BAYAS?$"

CeruleanCity_House1_Text_HaveJustTheThing::
	.string "Ah, estupendo, pues voy a darte\n"
	.string "una cosita.$"

CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner::
	.string "Hay algo nuevo en el primer piso\n"
	.string "de los CENTROS POKéMON, en la\l"
	.string "ZONA DIRECTA.\p"
	.string "Se ha instalado una máquina para\n"
	.string "Conectores inalámbricos de GBA,\l"
	.string "que permite MACHACAR BAYAS.\p"
	.string "¿Que para qué te cuento esto?\p"
	.string "Pues porque tengo que pedirte\n"
	.string "un favor. Sólo tú puedes ayudarme.\p"
	.string "¿Podrías hacer POLVO de BAYA\n"
	.string "usando esa máquina?\p"
	.string "Recuerda, la máquina está en la\n"
	.string "ZONA DIRECTA de los CENTROS\l"
	.string "POKéMON.\p"
	.string "Si me traes el POLVO de BAYA,\n"
	.string "elaboraré una medicina para ti.\p"
	.string "¡Hala, MACHACA algunas BAYAS\n"
	.string "y tráeme el POLVO de BAYAS!$"

CeruleanCity_House1_Text_WhyMustYouLieNoBerries::
	.string "¿Por qué me mientes?\p"
	.string "¿Cuántas BAYAS tienes?\n"
	.string "¡Ni una!$"

CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings::
	.string "¡A ti las BAYAS te importan\n"
	.string "un pimiento!\p"
	.string "Pues debes saber que hay que\n"
	.string "tener interés por todas las cosas.$"

CeruleanCity_House1_Text_HaveYouBroughtBerryPowder::
	.string "¡Eh! ¿Me has traído POLVO\n"
	.string "de BAYA?$"

CeruleanCity_House5_Text_ExchangeWithWhat::
	.string "¿Por qué quieres que te lo cambie?$"

CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem::
	.string "Vale, te cambio el POLVO de BAYA\n"
	.string "por una unidad de {STR_VAR_1}.$"

CeruleanCity_House1_Text_DontHaveEnoughBerryPowder::
	.string "¿Mm? No tienes suficiente POLVO\n"
	.string "de BAYA.$"

CeruleanCity_House1_Text_TradeMoreBerryPowder::
	.string "Este POLVO de BAYA es excelente.\n"
	.string "Va a salir una medicina buenísima.\p"
	.string "¿Quieres cambiar más POLVO\n"
	.string "de BAYA por otra cosa más?$"

CeruleanCity_House1_Text_HopeToSeeYouAgain::
	.string "Muy bien, muy bien.\n"
	.string "Hasta la próxima.$"

CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder::
	.string "Ven a verme cuando quieras cambiar\n"
	.string "POLVO de BAYA por otra cosa.$"

