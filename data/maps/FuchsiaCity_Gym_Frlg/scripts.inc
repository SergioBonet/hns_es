FuchsiaCity_Gym_Frlg_MapScripts::
	.byte 0

FuchsiaCity_Gym_EventScript_Koga::
	famechecker FAMECHECKER_KOGA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_KogaIntro, FuchsiaCity_Gym_Text_KogaDefeat, FuchsiaCity_Gym_EventScript_DefeatedKoga, NO_MUSIC
	goto_if_unset FLAG_GOT_TM06_FROM_KOGA, FuchsiaCity_Gym_EventScript_GiveTM06
	msgbox FuchsiaCity_Gym_Text_KogaPostBattle
	release
	end

FuchsiaCity_Gym_EventScript_DefeatedKoga::
	famechecker FAMECHECKER_KOGA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL
	setflag FLAG_DEFEATED_KOGA
	setflag FLAG_BADGE05_GET
	set_gym_trainers_frlg 5
	goto FuchsiaCity_Gym_EventScript_GiveTM06
	end

FuchsiaCity_Gym_EventScript_GiveTM06::
	msgbox FuchsiaCity_Gym_Text_KogaExplainSoulBadge
	checkitemspace ITEM_TM06
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_NoRoomForTM06
	giveitem_msg FuchsiaCity_Gym_Text_ReceivedTM06FromKoga, ITEM_TM06
	setflag FLAG_GOT_TM06_FROM_KOGA
	msgbox FuchsiaCity_Gym_Text_KogaExplainTM06
	release
	end

FuchsiaCity_Gym_EventScript_NoRoomForTM06::
	msgbox FuchsiaCity_Gym_Text_MakeSpaceForThis
	release
	end

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	famechecker FAMECHECKER_KOGA, 2
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KOGA, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_KogaIntro::
	.string "KOGA: ¡Fuajajaja!\p"
	.string "¿Un simple niño como tú se atreve a\n"
	.string "desafiarme?\p"
	.string "¡Solo la idea me hace temblar de risa!\p"
	.string "Muy bien, te mostraré el verdadero\n"
	.string "terror de un maestro ninja.\p"
	.string "El veneno trae una perdición\n"
	.string "constante. El sueño deja indefensos a\l"
	.string "los rivales.\p"
	.string "¡Desespera ante el horror rastrero de\n"
	.string "los POKéMON de tipo\l"
	.string "VENENO!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

FuchsiaCity_Gym_Text_KogaDefeat::
	.string "¡Ejem!\n"
	.string "¡Has demostrado tu valor!\p"
	.string "¡Aquí tienes la MEDALLA ALMA!$"

FuchsiaCity_Gym_Text_KogaPostBattle::
	.string "Cuando un POKéMON sufre TÓXICO,\n"
	.string "sufre cada vez más.\p"
	.string "¡El daño empeora a medida que\n"
	.string "transcurre el combate!\p"
	.string "¡Seguro que aterroriza a los rivales!$"

FuchsiaCity_Gym_Text_KogaExplainSoulBadge::
	.string "Ahora que tienes la MEDALLA ALMA,\n"
	.string "la DEFENSA de tus POKéMON aumentará.\p"
	.string "¡Y podrás hacer SURF siempre\n"
	.string "que quieras!\p"
	.string "¡Ah!\n"
	.string "¡Llévate esto también!$"

FuchsiaCity_Gym_Text_ReceivedTM06FromKoga::
	.string "¡{PLAYER} recibió la MT06\n"
	.string "de KOGA!$"

FuchsiaCity_Gym_Text_KogaExplainTM06::
	.string "¡La MT06 contiene TÓXICO!\p"
	.string "¡Es una técnica secreta de hace\n"
	.string "más de 400 años!$"

FuchsiaCity_Gym_Text_MakeSpaceForThis::
	.string "¡Haz sitio para esto, chico!$"

FuchsiaCity_Gym_Text_KaydenIntro::
	.string "La fuerza no es la clave con los\n"
	.string "POKéMON. ¿Lo entiendes?\p"
	.string "¡Lo importante es la estrategia!\p"
	.string "¡Te mostraré cómo la estrategia puede\n"
	.string "vencer a la fuerza bruta!$"

FuchsiaCity_Gym_Text_KaydenDefeat::
	.string "¿Qué?\n"
	.string "¡Extraordinario!$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
	.string "Así que combinas fuerza e\n"
	.string "inteligencia. ¡Buena estrategia!\p"
	.string "¡Es notable para un ENTRENADOR\n"
	.string "tan joven!$"

FuchsiaCity_Gym_Text_KirkIntro::
	.string "Fui mago hace tiempo.\p"
	.string "Pero soñaba con ser ninja, así que\n"
	.string "me uní a este GIMNASIO.$"

FuchsiaCity_Gym_Text_KirkDefeat::
	.string "¡Estoy acabado!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
	.string "Aunque he perdido, seguiré\n"
	.string "entrenando según las enseñanzas\l"
	.string "de KOGA, mi maestro ninja.$"

FuchsiaCity_Gym_Text_NateIntro::
	.string "¡A ver si puedes con mis\n"
	.string "técnicas especiales!$"

FuchsiaCity_Gym_Text_NateDefeat::
	.string "¡Me has engañado!$"

FuchsiaCity_Gym_Text_NatePostBattle::
	.string "Me gustan las técnicas de veneno\n"
	.string "y sueño, ¡porque duran después\l"
	.string "de los combates!$"

FuchsiaCity_Gym_Text_PhilIntro::
	.string "¡Alto ahí!\p"
	.string "¿Te frustran las famosas paredes\n"
	.string "invisibles del GIMNASIO FUCSIA?$"

FuchsiaCity_Gym_Text_PhilDefeat::
	.string "¡Vaya!\n"
	.string "¡Lo has conseguido!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
	.string "¡Me has impresionado!\n"
	.string "¡Aquí va una pista!\p"
	.string "¡Busca con atención huecos en las\n"
	.string "paredes invisibles!$"

FuchsiaCity_Gym_Text_EdgarIntro::
	.string "¡Yo también estudio el camino del\n"
	.string "ninja con el maestro KOGA!\p"
	.string "¡Los ninjas llevan mucho tiempo\n"
	.string "usando animales!$"

FuchsiaCity_Gym_Text_EdgarDefeat::
	.string "¡Auuu!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
	.string "Aún me queda mucho por aprender.$"

FuchsiaCity_Gym_Text_ShawnIntro::
	.string "El maestro KOGA proviene de una\n"
	.string "larga estirpe de ninjas.\p"
	.string "¿De quién desciendes tú?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
	.string "¡Eres más hábil de lo que\n"
	.string "pensaba!$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
	.string "¡Donde hay luz, hay sombra!\p"
	.string "¡Luz y sombra!\n"
	.string "¿Cuál eliges?$"

FuchsiaCity_Gym_Text_GymGuyAdvice::
	.string "¡Eh! ¡Futuro CAMPEÓN!\p"
	.string "El GIMNASIO de CIUDAD FUCSIA está\n"
	.string "lleno de trampas. ¡Está plagado de\l"
	.string "paredes invisibles!\p"
	.string "KOGA parece estar cerca, pero hay una\n"
	.string "pared que lo separa de ti.\p"
	.string "Tienes que encontrar los huecos entre\n"
	.string "las paredes para llegar hasta él.$"

FuchsiaCity_Gym_Text_GymGuyPostVictory::
	.string "¡Es increíble lo mucho que sigue\n"
	.string "asustando el ninja, incluso ahora!$"

FuchsiaCity_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON de FUCSIA\n"
	.string "LÍDER: KOGA\p"
	.string "ENTRENADORES VENCEDORES:\n"
	.string "{RIVAL}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON de FUCSIA\n"
	.string "LÍDER: KOGA\p"
	.string "ENTRENADORES VENCEDORES:\n"
	.string "{RIVAL}, {PLAYER}$"

