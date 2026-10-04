LavenderTown_Mart_Frlg_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_BaldingMan::
	msgbox LavenderTown_Mart_Text_SearchingForStatRaiseItems, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderTown_Mart_Text_DidYouBuyRevives, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Youngster::
	msgbox LavenderTown_Mart_Text_TrainerDuosCanChallengeYou, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavenderTown_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
LavenderTown_Mart_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

LavenderTown_Mart_Text_SearchingForStatRaiseItems::
	.string "Busco objetos que aumenten las\n"
	.string "estadísticas de los POKéMON.\p"
	.string "Son eficaces durante un solo\n"
	.string "combate.\p"
	.string "Busco ATAQUE X, DEFENSA X,\n"
	.string "VELOCIDAD X y ESPECIAL X.\p"
	.string "¿Sabes dónde puedo conseguirlos?$"

LavenderTown_Mart_Text_DidYouBuyRevives::
	.string "¿Compraste algunos REVIVIR?\n"
	.string "¡Reaniman a cualquier POKéMON\l"
	.string "debilitado!$"

LavenderTown_Mart_Text_TrainerDuosCanChallengeYou::
	.string "A veces, una pareja de ENTRENADORES\n"
	.string "te desafiará con dos POKéMON\l"
	.string "a la vez.\p"
	.string "Si eso pasa, tú también tienes que\n"
	.string "sacar dos POKéMON a combatir.$"

LavenderTown_Mart_Text_SoldNuggetFromMountainsFor5000::
	.string "El otro día encontré una PEPITA\n"
	.string "en lo profundo del monte.\p"
	.string "No me sirve de nada, pero\n"
	.string "¡me dieron 5000¥ por ella!$"
