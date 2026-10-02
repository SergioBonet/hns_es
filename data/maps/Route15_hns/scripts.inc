Route15_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE_HNS, Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY_HNS, Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten, Route15_EventScript_RegisterHillary
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchHillary
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterHillary::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_HillaryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HILLARY_HNS
	release
	end

Route15_EventScript_RematchHillary::
	trainerbattle_rematch TRAINER_HILLARY_HNS, Route15_Text_HillaryRematchIntro, Route15_Text_HillaryRematchDefeat
	msgbox Route15_Text_HillaryPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_HILLARY_2_HNS, Route15_EventScript_RematchHillaryTryGiveItem
	end

Route15_EventScript_RematchHillaryTryGiveItem::
	checkitem ITEM_TM_ENERGY_BALL
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_ENERGY_BALL
	closemessage
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP_HNS, Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY_HNS, Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY_HNS, Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY_HNS, Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten, Route15_EventScript_RegisterBilly
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchBilly
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterBilly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BillyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY_HNS
	release
	end

Route15_EventScript_RematchBilly::
	trainerbattle_rematch TRAINER_BILLY_HNS, Route15_Text_BillyRematchIntro, Route15_Text_BillyRematchDefeat
	msgbox Route15_Text_BillyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_BILLY_2_HNS, Route15_EventScript_RematchBillyTryGiveItem
	end

Route15_EventScript_RematchBillyTryGiveItem::
	checkitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_FACADE
	closemessage
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "¿Has olvidado algo?$"

Route15_Text_TeacherColetteBeaten:
	.string "¡Kiaaa!$"

Route15_Text_TeacherColetteAfterBattle:
	.string "Antes de ser maestra, solía olvidarme\n"
	.string "de muchas cosas.$"

Route15_Text_TeacherHillarySeen:
	.string "Creo que si hace sol, los niños\n"
	.string "deberían estar jugando en el patio en\l"
	.string "lugar de estar en clase.$"

Route15_Text_TeacherHillaryBeaten:
	.string "No quería perder…$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "Es importante estudiar, pero hacer\n"
	.string "deporte también.$"

Route15_Text_HillaryRegister:
	.string "You've taught me a lesson!\n"
	.string "May I have your number?$"

Route15_Text_HillaryRematchIntro:
	.string "I'll school you this time!$"

Route15_Text_HillaryRematchDefeat:
	.string "Back to the drawing board…$"

Route15_Text_HillaryPostRematch:
	.string "Teaching POKéMON is just like\n"
	.string "teaching children. Patience!$"

Route15_Text_SchoolboyKippSeen:
	.string "Espera. Tengo que llamar a mamá.$"

Route15_Text_SchoolboyKippBeaten:
	.string "¡Lo siento, mamá! ¡Me han vencido!$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "Mi madre se preocupa mucho por mí,\n"
	.string "tengo que llamarla siempre.$"

Route15_Text_SchoolboyTommySeen:
	.string "Luchemos. ¡No perderé!$"

Route15_Text_SchoolboyTommyBeaten:
	.string "¡Me olvidé de hacer los deberes!$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "Sayonara! I just learned that in\n"
	.string "my Japanese class.$"

Route15_Text_SchoolboyJohnnySeen:
	.string "Vamos a la TORRE RADIO de LAVANDA\p"
	.string "para realizar unos estudios sociales.$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "¡Eres demasiado fuerte!$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "Estoy cansado de caminar. Necesito un\n"
	.string "descanso.$"

Route15_Text_SchoolboyBillySeen:
	.string "¡Mi asignatura favorita es la\n"
	.string "gimnasia!$"

Route15_Text_SchoolboyBillyBeaten:
	.string "¡Oh, no! ¿Cómo he podido perder?$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "¡Si los POKéMON fueran una asignatura,\n"
	.string "yo sería el mejor de la clase!$"

Route15_Text_BillyRegister:
	.string "I should've paid more attention in class.\n"
	.string "Can I have your number?$"

Route15_Text_BillyRematchIntro:
	.string "I've been studying hard!\n"
	.string "Let me show you what I learned!$"

Route15_Text_BillyRematchDefeat:
	.string "I need to study more…$"

Route15_Text_BillyPostRematch:
	.string "Book smarts aren't everything.\n"
	.string "I need battle experience too!$"

Route15_Text_Sign:
	.string "RUTA 15\p"
	.string "CIUDAD FUCSIA - PUEBLO LAVANDA$"

