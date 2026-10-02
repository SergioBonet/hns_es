CeladonCity_House1_hns_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "¡Hola!\p"
	.string "Estamos celebrando un concurso de\n"
	.string "tragones.\p"
	.string "Perdona. Ahora no podemos atenderte.$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "¡Ñam, ñam!$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "¡No me hables!\p"
	.string "¡Me vas a desconcentrar!$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "… Glup… Ñam…$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "¡Prefiero cantidad antes que calidad!\p"
	.string "¡Soy feliz cuando estoy lleno!$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "¡Ñam, ñam!$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "La comida de aquí es buena, pero en\p"
	.string "CIUDAD TRIGAL es aún mejor.$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "¡Ñam, ñam!$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "Aquí nadie te va a dar un MONEDERO.\p"
	.string "Mejor que lo busques en JOHTO.$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "¡Ñam, ñam…!\p"
	.string "Todavía puedo comer más…\p"
	.string "¡Otro plato, camarero!\p"
	.string "$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "¡Concurso de tragones! ¡Sin tiempo!\n"
	.string "¡Una lucha sin fin! ¡El mayor tragón\l"
	.string "podrá comer gratis!$"

