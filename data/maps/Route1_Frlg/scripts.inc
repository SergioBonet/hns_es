Route1_Frlg_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Route1_Text_PutPotionAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_WorkAtPokeMartTakeSample::
	.string "¡Hola!\n"
	.string "Trabajo en una TIENDA POKéMON.\p"
	.string "Tenemos muchas cosas. Visítanos\n"
	.string "en CIUDAD VERDE.\p"
	.string "¡Mira, te daré una muestra!\n"
	.string "¡Aquí tienes!$"

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
	.string "¡También tenemos POKé BALLS\n"
	.string "para capturar los POKéMON!$"

Route1_Text_PutPotionAway::
	.string "{PLAYER} puso la POCIÓN\n"
	.string "en el BOLSILLO de OBJETOS\l"
	.string "de la MOCHILA.$"

Route1_Text_CanJumpFromLedges::
	.string "¿Ves esos bordes del camino?\p"
	.string "Dan miedo, pero puedes saltar\n"
	.string "por encima de ellos.\p"
	.string "¡De esa forma podrás volver más\n"
	.string "rápidamente a PUEBLO PALETA!$"

Route1_Text_RouteSign::
	.string "RUTA 1:\n"
	.string "PUEBLO PALETA - CIUDAD VERDE$"

