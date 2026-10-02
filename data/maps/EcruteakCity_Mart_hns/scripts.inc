EcruteakCity_Mart_hns_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "Mi EEVEE evolucionó en ESPEON.\p"
	.string "Pero el EEVEE de mi amigo evolucionó\n"
	.string "en UMBREON.\p"
	.string "No sé por qué. Los dos educamos a\n"
	.string "nuestros EEVEE de la misma forma…$"

EcruteakMart_Text_Granny:
	.string "Si usas REVIVIR, el POKéMON\p"
	.string "debilitado se reanimará.$"
