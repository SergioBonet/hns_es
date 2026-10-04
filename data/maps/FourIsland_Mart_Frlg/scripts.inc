FourIsland_Mart_Frlg_MapScripts::
	.byte 0

FourIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FourIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
FourIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FourIsland_Mart_EventScript_Camper::
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
	end

FourIsland_Mart_Text_LoreleiGrewUpOnThisIsland::
	.string "En esta isla creció un ENTRENADOR\n"
	.string "grande y poderoso.\p"
	.string "Apuesto a que hasta tú la conoces.\n"
	.string "¡Es LORELEI, del ALTO MANDO!\p"
	.string "Cuando LORELEI era pequeñaja,\n"
	.string "yo le enseñé sobre POKéMON.$"

FourIsland_Mart_Text_IcefallCaveIsFrigid::
	.string "Las ISLAS SEVII están en una\n"
	.string "región cálida en general.\p"
	.string "Pero hay una excepción que\n"
	.string "debes conocer.\p"
	.string "La CUEVA GLACIADA es gélida por\n"
	.string "los POKéMON que viven en ella.$"

