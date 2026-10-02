AzaleaTown_Mart_hns_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "¿Tú puedes comprar SUPER BALLS? Yo\n"
	.string "solo puedo comprar POKé BALLS.\p"
	.string "He oído que, cuando se consiguen\n"
	.string "MEDALLAS de GIMNASIO, se pueden\l"
	.string "comprar más cosas.\p"
	.string "¡Ojalá CÉSAR me hiciera unas de sus\n"
	.string "BALLS especiales!$"

AzaleaMart_Text_BugCatcher:
	.string "Mejor una SÚPER BALL para capturar\p"
	.string "POKéMON que una POKé BALL.\p"
	.string "Pero, a veces, las de CÉSAR son\n"
	.string "mejores.$"

