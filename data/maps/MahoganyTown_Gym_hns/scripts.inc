MahoganyTown_Gym_hns_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "Gimnasio POKéMON de PUEBLO CAOBA$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE PUEBLO CAOBA\p"
	.string "CERTIFICADOS POR FREDO:\n"
	.string "{PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD_HNS, MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD_HNS, MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_HNS, MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_HNS, MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_HNS, MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_SetupElmRocketCall::
    setvar VAR_TRIGGER_ELM_ROCKET_CALL, 1
    return

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
	.string "Los POKéMON viven todo tipo de\n"
	.string "experiencias.\p"
	.string "Yo también he visto y sufrido mucho en\n"
	.string "mi vida.\p"
	.string "Soy mayor, así que te enseñaré lo que\n"
	.string "quiero decir.\p"
	.string "He estado con los POKéMON desde\n"
	.string "antes de que tú nacieras.\p"
	.string "Y no pierdo fácilmente.\p"
	.string "¡Yo, FREDO, el entrenador del invierno,\n"
	.string "te mostraré mi poder!$"

MahoganyTown_Gym_Text_PryceImpressed:
	.string "¡Ah! Me impresiona tu valor.\p"
	.string "Con tu gran voluntad, sé que\n"
	.string "superarás todos los obstáculos.\p"
	.string "¡Te mereces esta MEDALLA!$"

MahoganyTown_Gym_Text_ReceivedBadge:
	.string "{PLAYER} recibió la MEDALLA GLACIAR.$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
	.string "Esa MEDALLA aumenta el ATAQUE\n"
	.string "ESPECIAL de los POKéMON.\p"
	.string "Además, permite a tus POKéMON usar\n"
	.string "TORBELLINO para cruzar los remolinos\l"
	.string "de verdad.\p"
	.string "Y esto… ¡Esto es un regalo de mi parte!$"

MahoganyTown_Gym_Text_HailSpeech:
	.string "Esa MT contiene GRANIZO.\p"
	.string "Causa daño cada turno durante 5\n"
	.string "turnos.\p"
	.string "Muestra la dureza del invierno.$"

MahoganyTown_Gym_Text_CherishPokemon:
	.string "La primavera llega cuando se derrite\n"
	.string "el hielo y la nieve.\p"
	.string "Tú y tus POKéMON pasaréis juntos\n"
	.string "muchos años.\p"
	.string "¡Pasadlo bien!$"

MahoganyTown_Gym_Text_PryceRematch:
	.string "¡Ah, el CAMPEÓN de JOHTO!\p"
	.string "Tus habilidades son realmente\n"
	.string "notables.\p"
	.string "Me has impresionado.\p"
	.string "Pero aún ahora tenemos mucho que\n"
	.string "aprender el uno del otro.\p"
	.string "Yo, FREDO, el ENTRENADOR del invierno,\n"
	.string "aún me guardo algún truco.\p"
	.string "¿Quieres la revancha?$"

MahoganyTown_Gym_Text_PryceRematchDefeat:
	.string "Ah, una vez más me impresiona tu\n"
	.string "destreza.\p"
	.string "Con tu fuerte voluntad, sé que\n"
	.string "superarás todos los obstáculos de la\l"
	.string "vida.$"

MahoganyTown_Gym_Text_Guide:
	.string "FREDO es un veterano que lleva unos\n"
	.string "50 años entrenando POKéMON.\p"
	.string "Tiene un equipo muy sólido para hacer\n"
	.string "frente a lo que le eches.\p"
	.string "El fuego es un buen punto de partida,\n"
	.string "¡pero ojo con la lluvia!$"

MahoganyTown_Gym_Text_GuideWin:
	.string "¡FREDO es bueno, pero tú eres aún\n"
	.string "mejor!\p"
	.string "¡Ha sido un gran combate que acortó\n"
	.string "distancias entre generaciones!$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
	.string "¡Congelaré a tus POKéMON! ¡No podrás\n"
	.string "hacer nada!$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
	.string "Maldición. No pude hacer nada.$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
	.string "Hay un movimiento que se puede usar\n"
	.string "cuando el POKéMON está congelado.$"

MahoganyTown_Gym_Text_BoarderBradSeen:
	.string "Este GIMNASIO tiene un suelo\n"
	.string "resbaladizo. ¿A que es divertido?\p"
	.string "¡Pero oye, aquí no estamos jugando!$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
	.string "¿Ves lo serios que somos?$"

MahoganyTown_Gym_Text_BoarderBradAfter:
	.string "Este GIMNASIO es genial. ¡Me encanta\n"
	.string "patinar con mis POKéMON!$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
	.string "Conozco el secreto de FREDO.$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
	.string "Te contaré el secreto de FREDO.$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
	.string "El secreto del poder de FREDO…\p"
	.string "Medita todos los días bajo una\n"
	.string "cascada para fortalecer el cuerpo y la\l"
	.string "mente.$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
	.string "Para vencer a FREDO, el LÍDER\p"
	.string "del GIMNASIO, piensa antes de patinar.$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
	.string "¡No perderé ante ti esquiando!$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
	.string "Si no patinas con precisión, te\n"
	.string "perderás toda la gracia de este\l"
	.string "Gimnasio.$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
	.string "¡Mira qué bien lo hago!$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
	.string "¡No! ¡He perdido!$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
	.string "No debería haber presumido sobre mi\n"
	.string "forma de esquiar.$"

