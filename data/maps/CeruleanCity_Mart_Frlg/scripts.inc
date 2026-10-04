CeruleanCity_Mart_Frlg_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeruleanCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeruleanCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

CeruleanCity_Mart_Text_RepelWorksOnWeakMons::
	.string "REPELENTE no solo ahuyenta a los\n"
	.string "bichos, también a los POKéMON débiles.\p"
	.string "Pon a tu POKéMON más fuerte a la\n"
	.string "izquierda de la LISTA POKéMON.\p"
	.string "Si tu primer POKéMON es fuerte,\n"
	.string "el efecto del REPELENTE aumenta.$"

CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy::
	.string "¿Conoces el CARAMELO RARO?\n"
	.string "No lo venden en las tiendas.\p"
	.string "Creo que hace que los POKéMON\n"
	.string "crezcan muy rápido de golpe.$"

