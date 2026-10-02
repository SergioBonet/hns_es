CeruleanCity_Mart_hns_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "Encontrarás muchos entrenadores de\n"
	.string "camino hacia CABO CELESTE.\p"
	.string "Quieren saber cómo son en comparación\n"
	.string "con otros entrenadores.$"

CeruleanMart_Text_CooltrainerF:
	.string "MISTY es casi la única persona de la\n"
	.string "ciudad capaz de vencer a los\p"
	.string "ENTRENADORES de CABO CELESTE.$"
