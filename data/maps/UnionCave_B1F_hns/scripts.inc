UnionCave_B1F_hns_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP_HNS, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD_HNS, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW_HNS, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN_HNS, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "Hace mucho tiempo que no veo a nadie.\p"
	.string "Acércate. ¡Luchemos!$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "¡Uurggh…!$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "Llevo perdido mucho tiempo…\p"
	.string "No es que me importe, ¡pero estoy\n"
	.string "hambriento!$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "¡Qué sabes tú! ¡Un visitante!$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "¡Jajaja! Te gusta pelear, ¿verdad?$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "Yo vivo aquí abajo.\p"
	.string "Tú también puedes, si quieres.\p"
	.string "Hay sitio de sobra, ¿ves?$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "¿Quién anda ahí?\p"
	.string "¡Déjame en paz, a mí y a mis POKéMON!$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "¡Fuera…! ¡Lárgate!$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "Solo mis POKéMON y yo. Estoy loco de\n"
	.string "alegría.$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "He venido hasta aquí para estudiar a\n"
	.string "los POKéMON.\p"
	.string "¡Te demostraré mis hallazgos en un\n"
	.string "combate real!$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "¡Lo has demostrado conmigo!$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "Debería reunir y publicar mis\n"
	.string "hallazgos.\p"
	.string "Podría hacerme tan famoso como el\n"
	.string "PROF. ELM.$"
