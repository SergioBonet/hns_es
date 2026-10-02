LavenderTown_Mart_hns_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_Pokefan::
	msgbox LavenderMart_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderMart_Text_Rocker, MSGBOX_NPC
	end

LavenderMart_Text_PokefanM:
	.string "Si vas a explorar una cueva, debes\n"
	.string "llevar siempre REPELENTE.\p"
	.string "Aunque me gusta la exploración, aún no\n"
	.string "he recorrido todas las cuevas.$"

LavenderMart_Text_Rocker:
	.string "He oído hablar de un artesano que\n"
	.string "fabrica POKé BALL a medida en PUEBLO\p"
	.string "AZALEA, en JOHTO. ¡Yo quiero una!$"
