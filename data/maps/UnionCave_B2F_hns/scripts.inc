UnionCave_B2F_hns_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_NICK_HNS, UnionCave_B2F_Text_CooltrainermNickSeen, UnionCave_B2F_Text_CooltrainermNickBeaten
	msgbox UnionCave_B2F_Text_CooltrainermNickAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfGwen::
	trainerbattle_single TRAINER_GWEN_HNS, UnionCave_B2F_Text_CooltrainerfGwenSeen, UnionCave_B2F_Text_CooltrainerfGwenBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfGwenAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfEmma::
	trainerbattle_single TRAINER_EMMA_HNS, UnionCave_B2F_Text_CooltrainerfEmmaSeen, UnionCave_B2F_Text_CooltrainerfEmmaBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfEmmaAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 20
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnionCave_B2F_EventScript_LaprasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_UNION_CAVE_LAPRAS
	setflag FLAG_HIDE_UNION_CAVE_LAPRAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

UnionCave_B2F_EventScript_LaprasRan::
	release
	end


UnionCave_B2F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

UnionCave_B2F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

UnionCave_B2F_EventScript_Item_MaxRevive::
	finditem ITEM_MAX_REVIVE
	end

UnionCave_B2F_Text_CooltrainermNickSeen:
	.string "Hay dos tipos de personas.\p"
	.string "Las que tienen estilo y las que no lo\n"
	.string "tienen.\p"
	.string "¿A qué tipo perteneces tú?$"

UnionCave_B2F_Text_CooltrainermNickBeaten:
	.string "¡Tu estilo es deslumbrante!$"

UnionCave_B2F_Text_CooltrainermNickAfter:
	.string "Lo admito: tu estilo con los POKéMON\n"
	.string "es deslumbrante y colorido.\p"
	.string "¡No harás más que mejorar!$"

UnionCave_B2F_Text_CooltrainerfGwenSeen:
	.string "Estoy entrenando. ¿Quieres luchar?$"

UnionCave_B2F_Text_CooltrainerfGwenBeaten:
	.string "No, eres demasiado para mí.$"

UnionCave_B2F_Text_CooltrainerfGwenAfter:
	.string "Seguiré entrenándome hasta que\n"
	.string "mejore.$"

UnionCave_B2F_Text_CooltrainerfEmmaSeen:
	.string "Si los POKéMON que me gustan\n"
	.string "estuvieran ahí, iría sin pensarlo.\p"
	.string "Eso haría un buen entrenador.$"

UnionCave_B2F_Text_CooltrainerfEmmaBeaten:
	.string "¡Preferiría cuidar de mis niños!$"

UnionCave_B2F_Text_CooltrainerfEmmaAfter:
	.string "Cada semana viene un POKéMON hasta la\n"
	.string "orilla.\p"
	.string "Quería ver a ese POKéMON…$"
