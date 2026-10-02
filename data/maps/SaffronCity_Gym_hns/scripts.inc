SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA_HNS, SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_HNS, SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS_HNS, SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_HNS, SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	msgbox SaffronCity_Gym_Text_Sabrina_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SKILL_SWAP
	msgbox SaffronCity_Gym_Text_Sabrina_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "SABRINA: Sabía que vendrías…\p"
	.string "Hace tres años tuve una visión de tu\n"
	.string "llegada.\p"
	.string "Tú lo que quieres es mi MEDALLA.\p"
	.string "No me gusta luchar, pero mi deber como\n"
	.string "LÍDER es conceder\p"
	.string "MEDALLAS a todo aquel que se las\n"
	.string "merezca.\p"
	.string "Como eso es lo que quieres, mira mis\n"
	.string "poderes psíquicos.$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "SABRINA: Tu poder… supera con creces\n"
	.string "lo que esperaba…\p"
	.string "Quizá no se pueda predecir del todo lo\n"
	.string "que nos espera en el futuro…\p"
	.string "Vale, tú ganas. Te has ganado la\n"
	.string "MEDALLA PANTANO.$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} recibió MEDALLA PANTANO.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "SABRINA: La MEDALLA PANTANO\p"
	.string "muestra tus poderes ocultos.\p"
	.string "Aunque no supe predecir tu poder con\n"
	.string "exactitud, sabía que valías mucho.\p"
	.string "¡Llegarás a ser lo que te propongas!$"

SaffronCity_Gym_Text_Sabrina_GiveTM:
	.string "Toma, quédate también esto.$"

SaffronCity_Gym_Text_Sabrina_ExplainTM:
	.string "Contiene INTERCAMBIO.\p"
	.string "Puede quitarles las habilidades a tus\n"
	.string "rivales y darles las tuyas.\p"
	.string "Úsalo con sabiduría…$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "SABRINA: Tu amor por tus POKéMON\p"
	.string "supera mi poder psíquico…\p"
	.string "Creo que el poder del amor es un tipo\n"
	.string "de poder psíquico…$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "SABRINA: Ah, el CAMPEÓN de KANTO.\p"
	.string "Presentía tu regreso.\p"
	.string "Tu poder ha crecido enormemente.\p"
	.string "Incluso ahora siento tu aura.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "SABRINA: Tu amor por tus POKéMON ha\n"
	.string "vuelto a superar mi poder psíquico…$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "¡El poder de todos a los que venciste\n"
	.string "está en mí!$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "Fuerte… Muy fuerte…$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "¿De dónde proviene tu poder?$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "El poder psíquico es el poder de tu\n"
	.string "alma.$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "¡Tu alma tiene más poder que la mía!$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "No solo has fortalecido tus\n"
	.string "habilidades, también tu alma.$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "¡Fufufufu…! Lo veo claramente.\p"
	.string "¡Puedo ver lo que encierra tu alma!$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "A pesar de leerte el pensamiento, he\n"
	.string "perdido…$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "¡Maldición! Olvidé que predije mi\n"
	.string "derrota contra ti.$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "El DOJO-KARATE era el GIMNASIO de\n"
	.string "esta ciudad.$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "¡No he estado a tu altura…!$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "El REY del KARATE, el maestro del\p"
	.string "DOJO-KARATE, acaba de ser machacado\n"
	.string "por SABRINA.$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "¡Oye, realmente prometes!\p"
	.string "Alguien tan hábil como tú, no necesita\n"
	.string "que le digan cómo luchar contra\l"
	.string "POKéMON psíquicos, ¿no?\p"
	.string "¡Espero mucho de ti!\p"
	.string "¡Buena suerte!$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "¡Otro combate fantástico!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON DE CIUDAD AZAFRÁN\n"
	.string "LÍDER: SABRINA\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE CIUDAD AZAFRÁN\n"
	.string "LÍDER: SABRINA\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"
