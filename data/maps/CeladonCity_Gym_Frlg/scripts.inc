CeladonCity_Gym_Frlg_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Erika::
	famechecker FAMECHECKER_ERIKA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaIntro, CeladonCity_Gym_Text_ErikaDefeat, CeladonCity_Gym_EventScript_DefeatedErika, NO_MUSIC
	goto_if_unset FLAG_GOT_TM19_FROM_ERIKA, CeladonCity_Gym_EventScript_GiveTM19
	famechecker FAMECHECKER_ERIKA, 4
	msgbox CeladonCity_Gym_Text_ErikaPostBattle
	release
	end

CeladonCity_Gym_EventScript_DefeatedErika::
	famechecker FAMECHECKER_ERIKA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	setflag FLAG_DEFEATED_ERIKA
	setflag FLAG_BADGE04_GET
	set_gym_trainers_frlg 4
	goto CeladonCity_Gym_EventScript_GiveTM19
	end

CeladonCity_Gym_EventScript_GiveTM19::
	msgbox CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis
	checkitemspace ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM19
	giveitem_msg CeladonCity_Gym_Text_ReceivedTM19FromErika, ITEM_TM19
	setflag FLAG_GOT_TM19_FROM_ERIKA
	msgbox CeladonCity_Gym_Text_ExplainTM19
	release
	end

CeladonCity_Gym_EventScript_NoRoomForTM19::
	msgbox CeladonCity_Gym_Text_ShouldMakeRoomForThis
	release
	end

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	famechecker FAMECHECKER_ERIKA, 2
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	famechecker FAMECHECKER_ERIKA, 3
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_ErikaIntro::
	.string "Hola…\n"
	.string "Qué día tan hermoso, ¿verdad?\l"
	.string "Es tan agradable…\p"
	.string "…Vaya, vaya…\n"
	.string "Me habré quedado dormida. Bienvenido.\p"
	.string "Me llamo ERIKA.\n"
	.string "Soy la LÍDER del GIMNASIO AZULONA.\p"
	.string "Soy alumna del arte de los\n"
	.string "arreglos florales.\p"
	.string "Mis POKéMON son únicamente de\n"
	.string "tipo PLANTA.\p"
	.string "…Oh, lo siento, no sabía que\n"
	.string "querías desafiarme.\p"
	.string "Muy bien, pero no perderé.{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeladonCity_Gym_Text_ErikaDefeat::
	.string "¡Reconozco mi derrota!\p"
	.string "Eres muy fuerte.\p"
	.string "Te voy a dar la MEDALLA ARCOIRIS.$"

CeladonCity_Gym_Text_ErikaPostBattle::
	.string "¿Estás estudiando a los POKéMON?\n"
	.string "Admito que me has impresionado.\p"
	.string "No coleccionaría POKéMON si\n"
	.string "fueran feos.$"

CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis::
	.string "La MEDALLA ARCOIRIS hará que los\n"
	.string "POKéMON de nivel inferior a 50 te\l"
	.string "obedezcan.\p"
	.string "Y permitirá que los POKéMON usen\n"
	.string "FUERZA siempre que quieras.\p"
	.string "¡Ah, llévate esto también!$"

CeladonCity_Gym_Text_ReceivedTM19FromErika::
	.string "¡{PLAYER} recibió la MT19\n"
	.string "de manos de ERIKA!$"

CeladonCity_Gym_Text_ExplainTM19::
	.string "La MT19 contiene GIGADRENADO.\p"
	.string "La mitad del daño que produce es\n"
	.string "usado para curar a tus POKéMON.\p"
	.string "No me digas que no es estupenda.$"

CeladonCity_Gym_Text_ShouldMakeRoomForThis::
	.string "Deberías hacerle sitio a esto.$"

CeladonCity_Gym_Text_KayIntro::
	.string "¿Sabes una cosa de este GIMNASIO?\p"
	.string "¡Es sólo para chicas!$"

CeladonCity_Gym_Text_KayDefeat::
	.string "¡Eres demasiado fuerte!$"

CeladonCity_Gym_Text_KayPostBattle::
	.string "¡Eeeh!\n"
	.string "¡Espero que ERIKA acabe contigo!$"

CeladonCity_Gym_Text_BridgetIntro::
	.string "Ah, hola.\n"
	.string "Estaba empezando a aburrirme.$"

CeladonCity_Gym_Text_BridgetDefeat::
	.string "¡Oh! ¡Mi maquillaje!$"

CeladonCity_Gym_Text_BridgetPostBattle::
	.string "¡Los POKéMON del tipo PLANTA\n"
	.string "son difíciles para los acuáticos!\p"
	.string "¡Y tienen ventaja sobre los del\n"
	.string "tipo ROCA y los del tipo TIERRA!$"

CeladonCity_Gym_Text_TinaIntro::
	.string "…¿No estuviste curioseando por\n"
	.string "aquí hace un rato?$"

CeladonCity_Gym_Text_TinaDefeat::
	.string "¡Me has abierto los ojos!$"

CeladonCity_Gym_Text_TinaPostBattle::
	.string "Ah, estabas buscando a ERIKA,\n"
	.string "no a mí.$"

CeladonCity_Gym_Text_TamiaIntro::
	.string "¡Mira mis POKéMON del tipo\n"
	.string "PLANTA!\p"
	.string "¡Son tan fáciles de entrenar!...$"

CeladonCity_Gym_Text_TamiaDefeat::
	.string "¡No!$"

CeladonCity_Gym_Text_TamiaPostBattle::
	.string "¡En nuestro GIMNASIO sólo luchamos\n"
	.string "con POKéMON del tipo PLANTA!\p"
	.string "¡Y también los usamos para hacer\n"
	.string "adornos florales!$"

CeladonCity_Gym_Text_LisaIntro::
	.string "¡Aquí no pueden entrar los POKéMON\n"
	.string "del tipo FUEGO o del tipo BICHO!$"

CeladonCity_Gym_Text_LisaDefeat::
	.string "¡Oh!\n"
	.string "¡Cómo eres!$"

CeladonCity_Gym_Text_LisaPostBattle::
	.string "¡ERIKA, nuestra LÍDER, puede\n"
	.string "parecer muy tranquila, pero es muy\l"
	.string "hábil!$"

CeladonCity_Gym_Text_LoriIntro::
	.string "Encantada de conocerte.\n"
	.string "Mi afición es entrenar POKéMON.$"

CeladonCity_Gym_Text_LoriDefeat::
	.string "¡Oh!\n"
	.string "¡Espléndido!$"

CeladonCity_Gym_Text_LoriPostBattle::
	.string "Voy a tener una cita a ciegas.\n"
	.string "¡Y debo aprender buenos modales!$"

CeladonCity_Gym_Text_MaryIntro::
	.string "¡Éste es el GIMNASIO de AZULONA!\p"
	.string "¡Las encantadoras chicas que hay\n"
	.string "aquí son muy fuertes!$"

CeladonCity_Gym_Text_MaryDefeat::
	.string "¡Me has ganado!$"

CeladonCity_Gym_Text_MaryPostBattle::
	.string "¡No he traído a mis mejores\n"
	.string "POKéMON! ¡Ya verás la próxima\l"
	.string "vez!$"

CeladonCity_Gym_Text_GymStatue::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de AZULONA: ERIKA\p"
	.string "ENTRENADOR GANADOR:\n"
	.string "{RIVAL}$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de AZULONA: ERIKA\p"
	.string "ENTRENADORES GANADORES:\n"
	.string "{RIVAL} y {PLAYER}$"

