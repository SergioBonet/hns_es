LavenderTown_SoulHouse_hns_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "SR. FUJI: Bienvenido.\p"
	.string "Mmm… Parece que crías a tus POKéMON\n"
	.string "con amabilidad y cariño.\p"
	.string "Los amantes de los POKéMON vienen\n"
	.string "aquí a presentar sus respetos a los\l"
	.string "POKéMON fallecidos.\p"
	.string "Por favor, reza por las almas de los\n"
	.string "POKéMON que ya no están.\p"
	.string "Seguro que eso los hará felices.$"

SoulHouse_Text_Teacher:
	.string "Creo que aquí hay más tumbas de\n"
	.string "POKéMON.\p"
	.string "Hay muchas salas en las que solo\n"
	.string "puede entrar el SR. FUJI.$"

SoulHouse_Text_Lass:
	.string "He venido con mi madre a visitar las\n"
	.string "tumbas de los POKéMON…$"

SoulHouse_Text_Granny:
	.string "A los POKéMON que vivían conmigo…\p"
	.string "los quería como a mis nietos…$"
