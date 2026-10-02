CeladonCity_GameCorner_hns_MapScripts::
	.byte 0

CeladonGameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanM, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Teacher::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Teacher, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_FishingGuru::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_FishingGuru, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_Fisher1::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher1, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Fisher2::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher2, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_GymGuide::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_GymGuide, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Gramps::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Gramps, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonGameCorner_Text_PokefanM:
	.string "Todas las tragaperras son de última\n"
	.string "generación.$"

CeladonGameCorner_Text_Teacher:
	.string "Quiero jugar en esta máquina.\p"
	.string "Ayer me desplumó, así que hoy soltará\n"
	.string "las fichas.$"

CeladonGameCorner_Text_FishingGuru:
	.string "Creo que esta máquina está repleta de\n"
	.string "fichas…\p"
	.string "Las posibilidades de ganar varían\n"
	.string "según la máquina.$"

CeladonGameCorner_Text_Fisher1:
	.string "¡Jajajajá!\p"
	.string "¡No paran de salir fichas!\p"
	.string "¿Mmm? ¿Qué pasa, chaval? ¿Quieres\n"
	.string "jugar?\p"
	.string "¡Te pasaré un poco de mi suerte!$"

CeladonGameCorner_Text_Fisher2:
	.string "¡Jajajajá!\p"
	.string "¡Hacer cosas buenas por los demás me\n"
	.string "hace sentir bien!$"

CeladonGameCorner_Text_GymGuide:
	.string "¿Tú también juegas a las tragaperras?\p"
	.string "Quiero conseguir bastantes fichas\n"
	.string "para cambiarlas por un POKéMON.\p"
	.string "Pero aún no tengo suficientes…$"

CeladonGameCorner_Text_PokefanF:
	.string "La ruleta…\p"
	.string "La prefiero a las tragaperras porque\n"
	.string "es más fácil calcular las\l"
	.string "probabilidades.\p"
	.string "Pero se gana mucho menos.$"

CeladonGameCorner_Text_Gramps:
	.string "Mmm… Seguro que es más probable\n"
	.string "apostarlo todo al azul, pero… ¿qué\l"
	.string "hago?$"

CeladonGameCorner_Text_Woman:
	.string "¡No paro de ganar!$"
