VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "¡Soy PEGASO, el LÍDER del GIMNASIO\n"
	.string "POKéMON de CIUDAD MALVA!\p"
	.string "La gente dice que se pueden cortar\n"
	.string "las alas a los POKéMON de tipo VOLADOR\p"
	.string "con una descarga eléctrica… ¡No\n"
	.string "permitiré semejantes insultos a los\l"
	.string "POKéMON pájaro!\p"
	.string "¡Te mostraré el verdadero poder de los\n"
	.string "magníficos POKéMON pájaro!$"

VioletGym_Text_Falkner_WinLoss:
	.string "… ¡Maldita sea! Los queridos POKéMON\n"
	.string "pájaro de mi padre…\p"
	.string "Está bien. Toma esto.\p"
	.string "Es la MEDALLA CÉFIRO oficial de la\n"
	.string "LIGA POKéMON.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} recibió la MEDALLA CÉFIRO.$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "La MEDALLA CÉFIRO aumenta el ATAQUE\n"
	.string "de los POKéMON.\p"
	.string "Además, permite a los POKéMON que\n"
	.string "puedan aprenderlo usar DESTELLO en\l"
	.string "cualquier momento.\p"
	.string "Toma, llévate también esto.$"

VioletGym_Text_Falkner_TMExplain:
	.string "Al usar una MT, un POKéMON aprende al\n"
	.string "instante un movimiento nuevo.\p"
	.string "Esa MT contiene RESPIRO.\p"
	.string "Restaura hasta la mitad de los PS\n"
	.string "máximos de tu POKéMON.\p"
	.string "Es decir, cura a tu POKéMON.$"

VioletGym_Text_Falkner_AfterFight:
	.string "Encontrarás GIMNASIOS POKéMON\p"
	.string "en las ciudades y en los pueblos.\p"
	.string "Deberías probar tus habilidades en\n"
	.string "estos GIMNASIOS.\p"
	.string "¡Yo seguiré entrenándome para ser el\n"
	.string "maestro de los pájaros!$"

VioletGym_Text_Falkner_Rematch:
	.string "¡Enhorabuena por vencer al ALTO\n"
	.string "MANDO!\p"
	.string "He entrenado a mis POKéMON de tipo\n"
	.string "VOLADOR aún más duro.\p"
	.string "¿Crees que podrás volver a con el\n"
	.string "poder de los cielos?$"

VioletGym_Text_Falkner_RematchLoss:
	.string "Uau… Me has vuelto a ganar.\p"
	.string "Voy a entrenar más para convertirme\n"
	.string "en el mejor maestro de los pájaros.$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "¡La clave está en tener valor!\p"
	.string "Éstos se entrenan noche y día para\n"
	.string "convertirse en maestros POKéMON.\p"
	.string "¡Adelante!$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "¡Aaah!$"

VioletGym_Text_BirdKeeperRod_After:
	.string "¡La destreza de PEGASO es real!\p"
	.string "¡No te confíes por haberme vencido!$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "¡Demuéstrame que vales lo suficiente\n"
	.string "para luchar contra PEGASO!$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "¡No puede ser cierto!$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "Qué patético resulta perder contra\n"
	.string "entrenadores novatos…$"

VioletGym_Text_GymGuide_Intro:
	.string "¡Eh! ¿Qué tal? No soy ENTRENADOR,\n"
	.string "¡pero puedo darte algún consejo!\p"
	.string "¡Créeme! Si crees en ti, el sueño de ser\n"
	.string "campeón puede hacerse realidad.\p"
	.string "¿Crees en ti? Entonces escucha.\p"
	.string "El as de PEGASO es un búho corpulento\n"
	.string "al que le encanta comer BAYAS.\p"
	.string "No es el más fuerte, pero aguanta\n"
	.string "muchos golpes.\p"
	.string "Puedes hacerle daño con movimientos\n"
	.string "de tipo ELÉCTRICO y ROCA, ¡pero\l"
	.string "cuidado con BOFETÓN LODO!\p"
	.string "Si quieres más ayuda, visita la\n"
	.string "ACADEMIA POKéMON.\p"
	.string "¡Los alumnos de allí saben un montón!$"

VioletGym_Text_GymGuide_Win:
	.string "¡Bonita batalla! ¡Sigue así y podrás\n"
	.string "conseguir lo que quieras!$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "Gimnasio POKéMON de CIUDAD MALVA$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD MALVA\p"
	.string "CERTIFICADOS POR PEGASO:\n"
	.string "{PLAYER}$"
