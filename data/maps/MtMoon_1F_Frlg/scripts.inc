MtMoon_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_1F_OnTransition
	.byte 0

MtMoon_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_1F
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MarcosIntro::
	.string "¡GUAU!\n"
	.string "¡Me has impresionado!\l"
	.string "¡Pero si eres muy joven!$"

MtMoon_1F_Text_MarcosDefeat::
	.string "¡Uau!\n"
	.string "¡Has vuelto a impresionarme!$"

MtMoon_1F_Text_MarcosPostBattle::
	.string "Los niños como tú no deberían\n"
	.string "andar por aquí en la oscuridad.$"

MtMoon_1F_Text_JoshIntro::
	.string "¿Estás aquí para explorar?$"

MtMoon_1F_Text_JoshDefeat::
	.string "¡Perder es lo peor!$"

MtMoon_1F_Text_JoshPostBattle::
	.string "¡Vine aquí para impresionar\n"
	.string "a las chicas!$"

MtMoon_1F_Text_MiriamIntro::
	.string "¡Uau! ¡Esto es mucho más grande\n"
	.string "de lo que creía!$"

MtMoon_1F_Text_MiriamDefeat::
	.string "¡Oh!\n"
	.string "¡He perdido!$"

MtMoon_1F_Text_MiriamPostBattle::
	.string "¿Cómo se sale de aquí?\n"
	.string "Es tan grande que me voy a perder.$"

MtMoon_1F_Text_JovanIntro::
	.string "¡Eh!\n"
	.string "¡No te pases conmigo!$"

MtMoon_1F_Text_JovanDefeat::
	.string "¡Mis POKéMON no lo han conseguido!$"

MtMoon_1F_Text_JovanPostBattle::
	.string "Tengo que encontrar POKéMON más\n"
	.string "fuertes. ¿Dónde estarán?$"

MtMoon_1F_Text_IrisIntro::
	.string "¿Qué?\n"
	.string "Estoy esperando aquí a mis amigos.$"

MtMoon_1F_Text_IrisDefeat::
	.string "¿He perdido?$"

MtMoon_1F_Text_IrisPostBattle::
	.string "Dicen que aquí hay unos fósiles\n"
	.string "muy raros.$"

MtMoon_1F_Text_KentIntro::
	.string "En la cueva hay unos hombres\n"
	.string "muy sospechosos. ¿Y tú, qué?$"

MtMoon_1F_Text_KentDefeat::
	.string "¡Me has parado los pies!$"

MtMoon_1F_Text_KentPostBattle::
	.string "¡Los he visto!\n"
	.string "¡Son del TEAM ROCKET! ¡Seguro!$"

MtMoon_1F_Text_RobbyIntro::
	.string "¡Cruza esta cueva y llegarás\n"
	.string "a CIUDAD CELESTE!$"

MtMoon_1F_Text_RobbyDefeat::
	.string "He perdido.$"

MtMoon_1F_Text_RobbyPostBattle::
	.string "¡ZUBAT es muy fuerte!\n"
	.string "¡Atrapar uno sería muy útil!$"

MtMoon_1F_Text_ZubatIsABloodsucker::
	.string "¡Cuidado!\n"
	.string "¡Los ZUBAT son unos chupasangre!$"

MtMoon_1F_Text_BrockHelpsExcavateFossils::
	.string "Estoy buscando fósiles en las\n"
	.string "entrañas del MT. MOON.\p"
	.string "A veces me ayuda BROCK,\n"
	.string "del GIMNASIO de PLATEADA.$"
