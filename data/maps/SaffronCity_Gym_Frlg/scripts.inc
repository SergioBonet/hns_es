SaffronCity_Gym_Frlg_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE06_GET
	set_gym_trainers_frlg 6
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	checkitemspace ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM04
	giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
	setflag FLAG_GOT_TM04_FROM_SABRINA
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle
	release
	end

SaffronCity_Gym_EventScript_NoRoomForTM04::
	msgbox SaffronCity_Gym_Text_BagFullOfOtherItems
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro::
	.string "Tuve una visión de tu llegada.\p"
	.string "Tengo poderes psíquicos desde que\n"
	.string "era niña.\p"
	.string "Empezó cuando una cuchara que lancé\n"
	.string "sin querer se dobló.\p"
	.string "No me gusta combatir, ¡pero si quieres,\n"
	.string "te mostraré mis poderes!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

SaffronCity_Gym_Text_SabrinaDefeat::
	.string "¡Estoy impresionada!\n"
	.string "Acepto mi derrota.\p"
	.string "¡Admito que no he sido lo bastante\n"
	.string "fuerte y por eso he perdido!\p"
	.string "¡Has ganado la MEDALLA PANTANO!$"

SaffronCity_Gym_Text_SabrinaPostBattle::
	.string "Todo el mundo tiene poderes\n"
	.string "mentales, pero la gente no lo\l"
	.string "sabe.\p"
	.string "La mente es muy poderosa, pero\n"
	.string "no todo el mundo la aprovecha.$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
	.string "¡Con la MEDALLA PANTANO, todo\n"
	.string "POKéMON con nivel inferior a 70 te\l"
	.string "obedecerá!\p"
	.string "¡Los POKéMON más fuertes\n"
	.string "suelen desobedecer las órdenes\l"
	.string "en combate!\p"
	.string "¡No entrenes demasiado a tus\n"
	.string "POKéMON para evitar este\l"
	.string "problema!\p"
	.string "¡Espera, llévate esta MT!$"

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
	.string "¡{PLAYER} obtuvo la MT04\n"
	.string "de manos de SABRINA!$"

SaffronCity_Gym_Text_ExplainTM04::
	.string "¡La MT04 contiene PAZ MENTAL!\p"
	.string "Hace concentrarse a los POKéMON\n"
	.string "para que aumente su AT. ESP. \l"
	.string "y su DEF. ESP.$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
	.string "Tu MOCHILA está llena de objetos.$"

SaffronCity_Gym_Text_AmandaIntro::
	.string "¡SABRINA es más joven que yo,\n"
	.string "pero la respeto!$"

SaffronCity_Gym_Text_AmandaDefeat::
	.string "¡Vaya fallo!$"

SaffronCity_Gym_Text_AmandaPostBattle::
	.string "¡En una pelea de iguales, ganará\n"
	.string "quien tenga más voluntad!\p"
	.string "¡Si quieres ganar a SABRINA,\n"
	.string "piensa sólo en ganar!$"

SaffronCity_Gym_Text_JohanIntro::
	.string "¿Te asusta nuestro poder oculto?$"

SaffronCity_Gym_Text_JohanDefeat::
	.string "¡Jamás lo hubiera pensado!$"

SaffronCity_Gym_Text_JohanPostBattle::
	.string "¡Los POKéMON psíquicos temen sólo\n"
	.string "a los bichos y a los fantasmas!$"

SaffronCity_Gym_Text_StacyIntro::
	.string "Los POKéMON acaban pareciéndose\n"
	.string "a sus ENTRENADORES.\p"
	.string "¡Pues tus POKéMON parecen fuertes!$"

SaffronCity_Gym_Text_StacyDefeat::
	.string "¡Lo sabía!$"

SaffronCity_Gym_Text_StacyPostBattle::
	.string "¡Debo enseñarles mejores técnicas\n"
	.string "a mis POKéMON!\p"
	.string "¡Sobre todo del tipo PSÍQUICO!$"

SaffronCity_Gym_Text_TyronIntro::
	.string "Sabes que tu fuerza no bastará\n"
	.string "para ganar en el mundo de los\l"
	.string "POKéMON, ¿no?$"

SaffronCity_Gym_Text_TyronDefeat::
	.string "¡No me lo puedo creer!$"

SaffronCity_Gym_Text_TyronPostBattle::
	.string "¡SABRINA ganó al MAESTRO de\n"
	.string "KARATE de la puerta de al lado!$"

SaffronCity_Gym_Text_TashaIntro::
	.string "¡Tú y yo!\n"
	.string "Nuestros POKéMON deben luchar.$"

SaffronCity_Gym_Text_TashaDefeat::
	.string "¡He perdido al final!$"

SaffronCity_Gym_Text_TashaPostBattle::
	.string "Sabía que esto iba a pasar.$"

SaffronCity_Gym_Text_CameronIntro::
	.string "¡SABRINA es joven, pero es nuestra\n"
	.string "LÍDER!\p"
	.string "¡No llegarás a ella fácilmente!$"

SaffronCity_Gym_Text_CameronDefeat::
	.string "¡Ooooh! ¡Me has noqueado!$"

SaffronCity_Gym_Text_CameronPostBattle::
	.string "En AZAFRÁN había dos\n"
	.string "GIMNASIOS POKéMON.\p"
	.string "¡El DOJO-KARATE de aquí al lado\n"
	.string "perdió su condición de GIMNASIO\l"
	.string "cuando los machacamos!$"

SaffronCity_Gym_Text_PrestonIntro::
	.string "¡El GIMNASIO POKéMON de AZAFRÁN\n"
	.string "es famoso por sus médiums!\p"
	.string "¡Quieres ver a SABRINA!\n"
	.string "¡Lo sé!$"

SaffronCity_Gym_Text_PrestonDefeat::
	.string "¡Arrrgg!$"

SaffronCity_Gym_Text_PrestonPostBattle::
	.string "¡Tienes razón! ¡Usé la telepatía\n"
	.string "para leer tu mente!$"

SaffronCity_Gym_Text_GymGuyAdvice::
	.string "¡Hola, aspirante al título!\p"
	.string "¡Los POKéMON de SABRINA usan el\n"
	.string "poder de la mente, no la fuerza!\p"
	.string "¡Los POKéMON del tipo LUCHA\n"
	.string "son débiles contra los de tipo\l"
	.string "PSÍQUICO!\p"
	.string "¡Se debilitan casi antes de poder\n"
	.string "prepararse!$"

SaffronCity_Gym_Text_GymGuyPostVictory::
	.string "¿Poder mental?\p"
	.string "¡Si yo lo tuviera me haría rico en\n"
	.string "las tragaperras!$"

SaffronCity_Gym_Text_GymStatue::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de AZAFRÁN: SABRINA\p"
	.string "ENTRENADOR GANADOR:\n"
	.string "{RIVAL}$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de AZAFRÁN: SABRINA\p"
	.string "ENTRENADORES GANADORES:\n"
	.string "{RIVAL} y {PLAYER}$"

