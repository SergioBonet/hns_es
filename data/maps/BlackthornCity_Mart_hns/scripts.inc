BlackthornCity_Mart_hns_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "El REVIVIR MÁXIMO no se puede\n"
	.string "comprar, pero restaura por completo a\l"
	.string "un POKéMON debilitado.\p"
	.string "Cuidado: no recupera los PP, los\n"
	.string "PUNTOS de PODER necesarios para los\l"
	.string "movimientos.$"

BlackthornMart_Text_BlackBelt:
	.string "REPELENTE MÁXIMO evita que se\n"
	.string "acerquen POKéMON débiles.\p"
	.string "Es el repelente más duradero de todos.$"
