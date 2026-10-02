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
	.string "Gahahaha!\p"
	.string "The coins just keep coming in!\p"
	.string "Hm? What, kid? You want to play?\p"
	.string "I'll share my luck with you!$"

CeladonGameCorner_Text_Fisher2:
	.string "Gahahaha!\p"
	.string "It makes me feel good to do nice\n"
	.string "things for other people!$"

CeladonGameCorner_Text_GymGuide:
	.string "¿Tú también juegas a las tragaperras?\p"
	.string "Quiero conseguir bastantes fichas\n"
	.string "para cambiarlas por un POKéMON.\p"
	.string "Pero aún no tengo suficientes…$"

CeladonGameCorner_Text_PokefanF:
	.string "Roulette…\p"
	.string "I prefer it over the slots because\n"
	.string "it's easier to figure the odds.\p"
	.string "But the payout is much lower.$"

CeladonGameCorner_Text_Gramps:
	.string "Hmmm… The odds are surely\n"
	.string "better putting it all on blue,\l"
	.string "but… what to do?$"

CeladonGameCorner_Text_Woman:
	.string "I can't stop winning!$"
