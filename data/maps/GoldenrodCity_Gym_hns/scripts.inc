GoldenrodCity_Gym_hns_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE_HNS, GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_HNS, GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA_HNS, GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA_HNS, GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1_HNS, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE CIUDAD TRIGAL$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD TRIGAL\p"
	.string "CERTIFICADOS POR BLANCA:\n"
	.string "{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
	.string "¡Hola! ¡Soy BLANCA!\p"
	.string "Todo el mundo estaba con los POKéMON,\n"
	.string "¡así que yo también me aficioné!\p"
	.string "¡Los POKéMON son supermonos!\p"
	.string "¿Quieres luchar? Te aviso: ¡soy buena!$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
	.string "¡Ayy…!\p"
	.string "¡Uaaaaaaa! ¡Qué mal!\p"
	.string "¡No deberías ser así! ¡Sí, tú! ¡Te lo\n"
	.string "digo a ti!$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
	.string "¡Uaaaaa!\p"
	.string "¡Uaaaaa!\p"
	.string "¡Buaa, buaa…! ¡Eres cruel!$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
	.string "¡Sniff…!\p"
	.string "¿Qué quieres? ¿Una MEDALLA?\p"
	.string "¡Ah, sí! Se me olvidaba. Toma la\n"
	.string "MEDALLA PLANICIE.$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
	.string "{PLAYER} recibió la MEDALLA PLANICIE.$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
	.string "La MEDALLA LLANURA permite a tus\n"
	.string "POKéMON usar FUERZA fuera de los\l"
	.string "combates.\p"
	.string "Además, aumenta la DEFENSA de tus\n"
	.string "POKéMON.\p"
	.string "¡Ah, y quédate también con esto!$"

GoldenrodCity_Gym_Text_WhitneyAttract:
	.string "¡Es ATRACCIÓN! Utiliza todo el\n"
	.string "encanto de un POKéMON.\p"
	.string "¿No es perfecto para una monada como\n"
	.string "yo?$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
	.string "¡Ah, qué bien me ha sentado llorar!$"

GoldenrodCity_Gym_Text_WhitneyRematch:
	.string "¡Hola! ¡Eres tú!\p"
	.string "¿Ahora eres el CAMPEÓN de JOHTO?\p"
	.string "¡Eres increíble!\p"
	.string "Quiero ver lo fuerte que eres.\p"
	.string "¿Quieres la revancha?$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
	.string "¡Uaaaaa!\p"
	.string "¡Uaaaaa!\p"
	.string "¡Buaa, buaa…! ¡Eres cruel!$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
	.string "No dejes que te impresione la belleza\n"
	.string "de mis POKéMON. ¡Son muy fuertes!$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
	.string "¡Vaya…! Pensaba que eras débil…$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
	.string "¿Creen mis POKéMON que soy guapa?$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
	.string "Prefiero un POKéMON mono a un POKéMON\n"
	.string "fuerte.\p"
	.string "¡Mis POKéMON son monos y fuertes!$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
	.string "¡Oh, no, no, no!$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
	.string "Intento vencer a BLANCA, pero… Es\n"
	.string "deprimente.\p"
	.string "¡De acuerdo! ¡Si pierdo, volveré a\n"
	.string "intentarlo otra vez!$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
	.string "¡Oh, no! Has hecho llorar a BLANCA.\p"
	.string "¡No te preocupes! Pronto dejará de\n"
	.string "llorar. Siempre llora si pierde.$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
	.string "¡Tienes gracia! ¡Me gustas!\p"
	.string "¡Pero no me rendiré!$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
	.string "Veamos… ¡Uups! ¿Ya está?$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
	.string "¡Uau! ¡Debes de valer mucho para\n"
	.string "haberme ganado! ¡Sigue así!$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
	.string "¡Hazlo lo mejor que puedas o acabaré\n"
	.string "contigo!$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
	.string "¡No! ¡Oh, MEOWTH, lo siento mucho!$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
	.string "Le había enseñado a MEOWTH todo tipo\n"
	.string "de ataques…$"

GoldenrodCity_Gym_Text_GymGuide:
	.string "¡Eh! ¡Futuro CAMPEÓN!\p"
	.string "Este GIMNASIO es el hogar de BLANCA,\n"
	.string "la maestra de los POKéMON de tipo\l"
	.string "NORMAL.\p"
	.string "Ten cuidado con su equipo tan mono.\p"
	.string "Algunos POKéMON de este gimnasio\n"
	.string "también tienen el recién descubierto\l"
	.string "tipo HADA.\p"
	.string "Mira en la RUTA 34 si necesitas un tipo\n"
	.string "LUCHA o VENENO.$"

GoldenrodCity_Gym_Text_GymGuideWin:
	.string "¿Has ganado? ¡Genial! Yo estaba\n"
	.string "ocupado mirando a las chicas.$"

