ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VIRIDIAN_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GiovanniIntro::
	.string "¡Fuajajaja! ¡Bienvenido a mi guarida!\p"
	.string "Así será hasta que pueda devolver al\n"
	.string "TEAM ROCKET su antigua gloria.\p"
	.string "Pero me has encontrado otra vez. Que\n"
	.string "así sea. Esta vez no me contendré.\p"
	.string "¡Una vez más te enfrentarás a\n"
	.string "GIOVANNI, el mejor\l"
	.string "ENTRENADOR!{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

ViridianCity_Gym_Text_GiovanniDefeat::
	.string "¡Ja! Qué combate tan intenso. ¡Has\n"
	.string "ganado!\p"
	.string "¡Como prueba, aquí tienes la MEDALLA\n"
	.string "TIERRA! {PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}$"

ViridianCity_Gym_Text_GiovanniPostBattle::
	.string "¡He perdido, ya no soy digno\n"
	.string "de dirigir a mis secuaces!\p"
	.string "¡Se acabó el TEAM ROCKET!\p"
	.string "¡Dedicaré mi vida al estudio\n"
	.string "de los POKéMON!\p"
	.string "¡Espero que nos volvamos a ver!\n"
	.string "¡Adiós!$"

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
	.string "La MEDALLA TIERRA hace que los POKéMON\n"
	.string "de cualquier nivel obedezcan sin\l"
	.string "rechistar.\p"
	.string "Es prueba de tu dominio como\n"
	.string "ENTRENADOR POKéMON.\p"
	.string "Con ella, puedes desafiar a la\n"
	.string "LIGA POKéMON.\p"
	.string "Además, toma esta MT.\p"
	.string "Considérala un regalo para tu\n"
	.string "desafío a la LIGA POKéMON.$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
	.string "¡{PLAYER} obtuvo la MT26\n"
	.string "de manos de GIOVANNI!$"

ViridianCity_Gym_Text_ExplainTM26::
	.string "¡La MT26 es TERREMOTO!\p"
	.string "¡Es muy potente, causa un\n"
	.string "temblor devastador!\p"
	.string "La inventé cuando dirigía este\n"
	.string "GIMNASIO, hace ya mucho tiempo...$"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
	.string "¡Llevas muchas cosas!$"

ViridianCity_Gym_Text_YujiIntro::
	.string "¡Je!\n"
	.string "¡Ya debes de estar sin fuerzas!$"

ViridianCity_Gym_Text_YujiDefeat::
	.string "¡Me he quedado sin fuerza!$"

ViridianCity_Gym_Text_YujiPostBattle::
	.string "¡Necesitas potencia para luchar\n"
	.string "contra el LÍDER del GIMNASIO!$"

ViridianCity_Gym_Text_AtsushiIntro::
	.string "¡Grrrr!\n"
	.string "¡Me estoy poniendo furioso!$"

ViridianCity_Gym_Text_AtsushiDefeat::
	.string "¡Rargh!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
	.string "¡Aún no soy digno!$"

ViridianCity_Gym_Text_JasonIntro::
	.string "¡Mis POKéMON y yo hacemos\n"
	.string "muy buena música!$"

ViridianCity_Gym_Text_JasonDefeat::
	.string "¡Estás en perfecta armonía!$"

ViridianCity_Gym_Text_JasonPostBattle::
	.string "¿Sabes quién es el LÍDER de\n"
	.string "nuestro GIMNASIO?$"

ViridianCity_Gym_Text_KiyoIntro::
	.string "¡El karate es lo máximo en artes\n"
	.string "marciales!$"

ViridianCity_Gym_Text_KiyoDefeat::
	.string "¡Ayyyy!$"

ViridianCity_Gym_Text_KiyoPostBattle::
	.string "¡Si mis POKéMON fueran tan buenos\n"
	.string "en kárate como yo…!$"

ViridianCity_Gym_Text_WarrenIntro::
	.string "¡Los más hábiles ganan con estilo!$"

ViridianCity_Gym_Text_WarrenDefeat::
	.string "¡He perdido el control!$"

ViridianCity_Gym_Text_WarrenPostBattle::
	.string "El LÍDER me regañará por\n"
	.string "perder de esta manera…$"

ViridianCity_Gym_Text_TakashiIntro::
	.string "¡Soy el REY del KARATE!\n"
	.string "¡Te tengo en mis manos!$"

ViridianCity_Gym_Text_TakashiDefeat::
	.string "¡Aaah!$"

ViridianCity_Gym_Text_TakashiPostBattle::
	.string "¿La LIGA POKéMON? ¿Tú?\n"
	.string "¿Pero quién te crees que eres?$"

ViridianCity_Gym_Text_ColeIntro::
	.string "¡Tus POKéMON se acobardarán ante\n"
	.string "el chasquido de mi látigo!$"

ViridianCity_Gym_Text_ColeDefeat::
	.string "¡Ay!\n"
	.string "¡Latigazo!$"

ViridianCity_Gym_Text_ColePostBattle::
	.string "¡Espera!\n"
	.string "¡No he tenido ningún cuidado!$"

ViridianCity_Gym_Text_SamuelIntro::
	.string "¡El GIMNASIO de VERDE estuvo\n"
	.string "cerrado mucho tiempo, pero nuestro\l"
	.string "LÍDER ha vuelto!$"

ViridianCity_Gym_Text_SamuelDefeat::
	.string "¿Me has ganado?$"

ViridianCity_Gym_Text_SamuelPostBattle::
	.string "¡Accederás a la LIGA POKéMON\n"
	.string "si ganas a nuestro LÍDER!$"

ViridianCity_Gym_Text_GymGuyAdvice::
	.string "¡Hola, aspirante al título!\p"
	.string "¡Ni yo conozco la identidad del\n"
	.string "LÍDER de VERDE!\p"
	.string "¡Debe de ser el más duro de todos\n"
	.string "los LÍDERES de GIMNASIO!\p"
	.string "¡Dicen que estos ENTRENADORES usan\n"
	.string "los POKéMON del tipo TIERRA!$"

ViridianCity_Gym_Text_GymGuyPostVictory::
	.string "¿Qué dices? ¿Que GIOVANNI era\n"
	.string "el LÍDER del GIMNASIO?$"

ViridianCity_Gym_Text_GymStatue::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de CIUDAD VERDE: (?)\p"
	.string "ENTRENADOR GANADOR:\n"
	.string "{RIVAL}$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de CIUDAD VERDE: GIOVANNI\p"
	.string "ENTRENADORES GANADORES:\n"
	.string "{RIVAL} y {PLAYER}$"

