BlackthornCity_Mart_hns_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "You can't buy MAX REVIVE, but it\n"
	.string "fully restores a fainted POKéMON.\p"
	.string "Beware--it won't restore PP, the\n"
	.string "POWER POINTS needed for moves.$"

BlackthornMart_Text_BlackBelt:
	.string "REPELENTE MÁXIMO evita que se\n"
	.string "acerquen POKéMON débiles.\p"
	.string "Es el repelente más duradero de todos.$"
