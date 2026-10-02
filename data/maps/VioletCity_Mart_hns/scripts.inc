VioletCity_Mart_hns_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "Cuando atrapas un POKéMON, puede\n"
	.string "estar débil.\p"
	.string "Pero éste crecerá y se hará más\n"
	.string "fuerte.\p"
	.string "Es importante tratar a todos los\p"
	.string "POKéMON con mucho cariño.$"

VioletCity_Mart_Text_CooltrainerM:
	.string "Los POKéMON pueden llevar objetos\n"
	.string "como POCIONES y ANTÍDOTOS.\p"
	.string "Pero parece que no saben usar objetos\n"
	.string "hechos por el hombre.$"
