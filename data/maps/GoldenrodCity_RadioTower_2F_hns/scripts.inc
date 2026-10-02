GoldenrodCity_RadioTower_2F_hns_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26_HNS, GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_set FLAG_DAILY_BUENAS_PASSWORD_GUESSED, GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed
	goto_if_unset FLAG_DAILY_BUENAS_PASSWORD, GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword, MSGBOX_DEFAULT
	special Special_BuenaPasswordShowMultichoice
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled
	special Special_BuenaCheckAnswer
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaWrong, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect::
	special Special_BuenaRollReward
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull
	giveitem VAR_0x8004, 1
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaCorrect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaComeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "BUENA: ¿Eh? ¿El código de hoy?\p"
	.string "¡AYUDA, por supuesto!$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "Puedes oír la radio donde sea.\n"
	.string "¡Sintonízala!$"

GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "Restricted access beyond this\n"
	.string "point.$"

GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "Las nanas de la radio duermen a los\n"
	.string "POKéMON.$"

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "¿Por qué querrían apoderarse de la\n"
	.string "TORRE RADIO?$"

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "JIGGLYPUFF: Jiggly…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "¡Aviso! Prohibido entrar sin\n"
	.string "autorización.\p"
	.string "Antes no era así.\p"
	.string "Debe de haber algún problema con el\n"
	.string "DIRECTOR…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "Puedes mirar por todas partes.\p"
	.string "El DIRECTOR ya no está enfadado.$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "Hace tres años, el TEAM ROCKET tuvo\n"
	.string "que separarse.\p"
	.string "¡Pero nos estamos volviendo a reunir\n"
	.string "aquí!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "¡Bah! ¡No vayas de perdonavidas!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "¡No permitiremos que arruines\n"
	.string "nuestros planes!$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "¡Somos el TEAM ROCKET, explotadores\n"
	.string "de los POKéMON!\p"
	.string "¡Nos gusta ser malos! ¿Damos miedo?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "¿Te crees invencible?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "No siempre somos malos. Hacemos lo que\n"
	.string "queremos.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "¡Oye! ¡Fuera de nuestro camino!$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "¡Arggh! Me rindo.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "Nuestros EJECUTIVOS quieren hacerse\n"
	.string "con este lugar.\p"
	.string "Tienen grandes planes. ¿Cuáles serán?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "¡Ja, ja, ja!\p"
	.string "¡Qué aburrimiento! ¡Fue tan sencillo\n"
	.string "apoderarse de este lugar!\p"
	.string "¡Venga, entretenme!$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "¿Quién eres tú?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "¡Me venciste y no pienso olvidarlo!$"

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "BUENA: Tune in to my PASSWORD\n"
	.string "SHOW!\p"
	.string "Listen to find out today's\n"
	.string "password!$"

GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword:
	.string "BUENA: Hi there!\p"
	.string "So, do you know today's\n"
	.string "password?\p"
	.string "OK! Which one is it?$"

GoldenrodCity_RadioTower_2F_Text_BuenaCorrect:
	.string "BUENA: You got it!\p"
	.string "Here, take this {STR_VAR_1}\n"
	.string "as your prize!$"

GoldenrodCity_RadioTower_2F_Text_BuenaWrong:
	.string "BUENA: Bzzt! Too bad!\p"
	.string "Try again tomorrow!$"

GoldenrodCity_RadioTower_2F_Text_BuenaComeBack:
	.string "BUENA: No guess?\n"
	.string "Come back when you're ready!$"

GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed:
	.string "BUENA: You already guessed\n"
	.string "today's password!\p"
	.string "Tune in again tomorrow!$"

GoldenrodCity_RadioTower_2F_Text_BuenaBagFull:
	.string "BUENA: You got it right, but\n"
	.string "your BAG is full!\p"
	.string "Make some room and come\n"
	.string "talk to me again!$"

GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "P1 VENTAS$"

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "La HORA POKéMON del PROF. OAK.\p"
	.string "¡El mejor programa de la radio!$"

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "Anywhere, Anytime POKéMON Radio$"
