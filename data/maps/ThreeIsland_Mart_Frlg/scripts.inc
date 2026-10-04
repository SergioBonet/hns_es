ThreeIsland_Mart_Frlg_MapScripts::
	.byte 0

ThreeIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ThreeIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
ThreeIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

ThreeIsland_Mart_EventScript_Picnicker::
	msgbox ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_BugCatcher::
	msgbox ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_Youngster::
	msgbox ThreeIsland_Mart_Text_BikersWereAboutToTrashMart, MSGBOX_NPC
	end

ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger::
	.string "¿De verdad?\p"
	.string "¿Seguro que el CENTRO COMERCIAL\n"
	.string "de AZULONA es mucho mayor que\l"
	.string "esta tienda?$"

ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest::
	.string "A veces compro medicinas aquí.\p"
	.string "Pero hay mucha gente que cura a\n"
	.string "los POKéMON con BAYAS del BOSQUE\l"
	.string "BAYA.\p"
	.string "Hombre, yo lo entiendo; las BAYAS\n"
	.string "son gratis y nunca se acaban.$"

ThreeIsland_Mart_Text_BikersWereAboutToTrashMart::
	.string "Los MOTORISTAS han estado a punto\n"
	.string "de destrozar la TIENDA POKéMON.\p"
	.string "Menos mal que se han ido.$"

