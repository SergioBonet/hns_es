SproutTower_1F_hns_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW_HNS, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "Montamos guardia en esta torre.\p"
	.string "Así expresamos nuestra gratitud a\n"
	.string "todos los POKéMON.$"

SproutTower_Text_SageChow_Beaten:
	.string "Gra… ¡Gracias!$"

SproutTower_Text_SageChow_AfterBattle:
	.string "Todos los seres vivos cooperan para\n"
	.string "sobrevivir.\p"
	.string "Deberíamos estar agradecidos.$"

SproutTower_Text_1F_Sage1:
	.string "Sólo obtendrás una MO si llegas arriba.$"

SproutTower_Text_1F_Sage2:
	.string "La TORRE BELLSPROUT fue construida\n"
	.string "para entrenar POKéMON.$"

SproutTower_Text_1F_Granny:
	.string "A BELLSPROUT over 100 feet\n"
	.string "tall…\p"
	.string "People say that it became the\n"
	.string "center pillar here.$"

SproutTower_Text_1F_Teacher:
	.string "¿Ves cómo se mueve la columna?\p"
	.string "Arriba hay gente entrenándose.$"

SproutTower_Text_1F_Statue:
	.string "Estatua POKéMON…\p"
	.string "Parece muy ilustre.$"
