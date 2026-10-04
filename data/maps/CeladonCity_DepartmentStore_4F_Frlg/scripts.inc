CeladonCity_DepartmentStore_4F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_4F_EventScript_Man::
	msgbox CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items::
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent::
	.string "Estoy comprando un regalo para mi\n"
	.string "novia.\p"
	.string "Creo que será un POKé MUÑECO.\n"
	.string "Es lo que se lleva.$"

CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll::
	.string "He oído algo útil.\p"
	.string "Si aparece un POKéMON salvaje,\n"
	.string "puedes distraerlo con un POKé MUÑECO.\p"
	.string "Puedes huir mientras el POKéMON\n"
	.string "salvaje está distraído.$"

CeladonCity_DepartmentStore_4F_Text_FloorSign::
	.string "¡Exprésate con regalos!\n"
	.string "P3: REGALOS del SABIO\p"
	.string "¡Especial evolución!\n"
	.string "¡PIEDRAS elementales en oferta!$"
