CeladonCity_Gym_hns_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA_HNS, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_Erika_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	msgbox CeladonCity_Gym_Text_Erika_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "ERIKA: Hola… Bonito día, ¿verdad? Se\n"
	.string "está tan bien…\p"
	.string "Podría hasta dormirme…\p"
	.string "Me llamo ERIKA. Soy la LÍDER\p"
	.string "del GIMNASIO de CIUDAD AZULONA.\p"
	.string "¿Cómo? ¿Vienes de JOHTO? ¡Qué bien…!\p"
	.string "¡Oh! Lo siento, no me di cuenta de que\n"
	.string "querías desafiarme.\p"
	.string "Muy bien, pero no perderé.$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "ERIKA: ¡Oh! Admito que he perdido…\p"
	.string "Eres realmente fuerte…\p"
	.string "Te daré la MEDALLA ARCOIRIS…$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER} recibió MEDALLA ARCOIRIS.$"

CeladonCity_Gym_Text_Erika_GiveTM:
	.string "ERIKA: Ha sido un combate encantador.\p"
	.string "Me has inspirado. Por favor, acepta\n"
	.string "esta MT.$"

CeladonCity_Gym_Text_Erika_ExplainTM:
	.string "Es GIGADRENADO.\p"
	.string "Es un movimiento maravilloso que\n"
	.string "absorbe la mitad del daño causado\l"
	.string "para curar a tu POKéMON.\p"
	.string "Úsalo si te place…$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "ERIKA: La derrota deja mal sabor de\n"
	.string "boca…\p"
	.string "Pero saber que hay entrenadores más\n"
	.string "fuertes me anima a mejorar…$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "ERIKA: Oh, hola.\p"
	.string "¡Qué sorpresa, CAMPEÓN de KANTO!\p"
	.string "Me alegra mucho volver a verte.\p"
	.string "Tu viaje debe de haber sido muy\n"
	.string "emocionante.\p"
	.string "Hasta los campeones disfrutan de un\n"
	.string "buen desafío.\p"
	.string "¿Quieres la revancha?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "ERIKA: Perder aún me deja un regusto\n"
	.string "amargo…\p"
	.string "Pero saber que hay ENTRENADORES\n"
	.string "fuertes me anima a mejorar…$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE_HNS, CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "¿Te parece raro un GIMNASIO exclusivo\n"
	.string "para chicas?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "¡Oh, maldición!$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "Tenía que haber estado más atenta.$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA_HNS, CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "¡Oh! ¿Un combate? Me da un poco de\n"
	.string "miedo, pero bueno.$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "¿Ah, ya está?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "¡Uauu! ¡Tienes muchas MEDALLAS!\p"
	.string "¡No me extraña haber perdido!$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA_HNS, CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "¿Estabas mirando estas flores o a mí?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "¡Qué rabia!$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "¿Cómo podré llegar a ser tan elegante\n"
	.string "como ERIKA?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "¡Te enseñaremos los movimientos\p"
	.string "POKéMON que nos enseñó ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "Hemos perdido…$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "¡ERIKA nos vengará!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "¡Vamos a proteger a ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "No podíamos ganar…$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "¡ERIKA es mucho, mucho más fuerte!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON DE CIUDAD AZULONA\n"
	.string "LÍDER: ERIKA\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE CIUDAD AZULONA\n"
	.string "LÍDER: ERIKA\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"
