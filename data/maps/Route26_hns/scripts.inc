Route26_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE_HNS, Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN_HNS, Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten, Route26_EventScript_RegisterGaven
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchGaven
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterGaven::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_GavenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAVEN_HNS
	release
	end

Route26_EventScript_RematchGaven::
	trainerbattle_rematch TRAINER_GAVEN_HNS, Route26_Text_GavenRematchIntro, Route26_Text_GavenRematchDefeat
	msgbox Route26_Text_GavenPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE_HNS, Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_HNS, Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten, Route26_EventScript_RegisterBeth
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchBeth
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterBeth::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_BethRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BETH_HNS
	release
	end

Route26_EventScript_RematchBeth::
	trainerbattle_rematch TRAINER_BETH_HNS, Route26_Text_BethRematchIntro, Route26_Text_BethRematchDefeat
	msgbox Route26_Text_BethPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD_HNS, Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
	.string "Estoy haciendo los últimos\n"
	.string "preparativos para la LIGA POKéMON.$"

Route26_Text_CooltrainermJakeBeaten:
	.string "¡Caramba!$"

Route26_Text_CooltrainermJakeAfter:
	.string "Va a ser difícil ganar en la LIGA.\p"
	.string "Tengo que entrenarme mucho más.\p"
	.string "Dicen que el ALTO MANDO es más duro\n"
	.string "que los LÍDERES de GIMNASIO.$"

Route26_Text_CooltrainermGavenSeen:
	.string "Es en estos duros combates donde\n"
	.string "ganas más poder.$"

Route26_Text_CooltrainermGavenBeaten:
	.string "¡La vida es aún más dura!$"

Route26_Text_CooltrainermGavenAfter:
	.string "Para llegar a la LIGA POKéMON, hay que\n"
	.string "pasar por la CALLE VICTORIA.\p"
	.string "Pero la CALLE VICTORIA es dura.\p"
	.string "¡No va allí casi nadie!$"

Route26_Text_GavenRegister:
	.string "Para llegar a la LIGA POKéMON, hay que\n"
	.string "pasar por la CALLE VICTORIA.\p"
	.string "Pero la CALLE VICTORIA es dura.\p"
	.string "¡No va allí casi nadie!$"

Route26_Text_GavenRematchIntro:
	.string "Es en estos duros combates donde\n"
	.string "ganas más poder.$"

Route26_Text_GavenRematchDefeat:
	.string "¡La vida es aún más dura!$"

Route26_Text_GavenPostRematch:
	.string "Para llegar a la LIGA POKéMON, hay que\n"
	.string "pasar por la CALLE VICTORIA.\p"
	.string "Pero la CALLE VICTORIA es dura.\p"
	.string "¡No va allí casi nadie!$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "Since you've come this far,\n"
    .string "you must be good.\p"
    .string "I'm going to give this battle\n"
    .string "everything I've got!$"

Route26_Text_CooltrainerfJoyceBeaten:
	.string "¡No! ¡No puedo creerlo!$"

Route26_Text_CooltrainerfJoyceAfter:
	.string "Como había vencido a ocho LÍDERES de\p"
	.string "GIMNASIO, me confié demasiado.\p"
	.string "Tendré que esforzarme más.$"

Route26_Text_CooltrainerfBethSeen:
	.string "He perdido contra {RIVAL}.\p"
	.string "Era realmente fuerte, pero…\p"
	.string "Parecía como si tuviera que ganar a\n"
	.string "toda costa.\p"
	.string "Me dieron pena sus POKéMON.$"

Route26_Text_CooltrainerfBethBeaten:
	.string "Los POKéMON no son armas de guerra.$"

Route26_Text_CooltrainerfBethAfter:
    .string "POKéMON are in-valuable, lifelong\n"
    .string "partners.$"

Route26_Text_BethRegister:
	.string "Los POKéMON son valiosos amigos para\n"
	.string "toda la vida.$"

Route26_Text_BethRematchIntro:
    .string "I lost to a trainer named {RIVAL}.\p"
    .string "But I won't lose to you!$"

Route26_Text_BethRematchDefeat:
	.string "Los POKéMON no son armas de guerra.$"

Route26_Text_BethPostRematch:
	.string "Los POKéMON son valiosos amigos para\n"
	.string "toda la vida.$"

Route26_Text_PsychicRichardSeen:
	.string "¡Uau! ¡Cuántas MEDALLAS! Estoy\n"
	.string "impresionado.\p"
	.string "Pero no te basta sólo con\n"
	.string "coleccionarlas, ¿verdad?$"

Route26_Text_PsychicRichardBeaten:
    .string "Good battle!$"

Route26_Text_PsychicRichardAfter:
	.string "Las personas y los POKéMON se\n"
	.string "enriquecen con la experiencia.\p"
	.string "¡No seas tan conformista!$"

Route26_Text_Sign:
    .string "ROUTE 26\p"
    .string "POKéMON LEAGUE\n"
    .string "RECEPTION GATE$"

