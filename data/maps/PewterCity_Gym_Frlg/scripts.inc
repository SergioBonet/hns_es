PewterCity_Gym_Frlg_MapScripts::
	.byte 0

PewterCity_Gym_EventScript_Brock::
	famechecker FAMECHECKER_BROCK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrock, NO_MUSIC
	goto_if_unset FLAG_GOT_TM39_FROM_BROCK, PewterCity_Gym_EventScript_GiveTM39
	msgbox PewterCity_Gym_Text_BrockPostBattle
	release
	end

PewterCity_Gym_EventScript_DefeatedBrock::
	famechecker FAMECHECKER_BROCK, 1
	setflag FLAG_DEFEATED_BROCK
	setflag FLAG_BADGE01_GET
	setvar VAR_MAP_SCENE_PEWTER_CITY, 1
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	set_gym_trainers_frlg 1
	goto PewterCity_Gym_EventScript_GiveTM39
	end

PewterCity_Gym_EventScript_GiveTM39::
	msgbox PewterCity_Gym_Text_TakeThisWithYou
	checkitemspace ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM39
	giveitem_msg PewterCity_Gym_Text_ReceivedTM39FromBrock, ITEM_TM39
	setflag FLAG_GOT_TM39_FROM_BROCK
	msgbox PewterCity_Gym_Text_ExplainTM39
	release
	end

PewterCity_Gym_EventScript_NoRoomForTM39::
	msgbox PewterCity_Gym_Text_DontHaveRoomForThis
	release
	end

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BROCK, PewterCity_Gym_EventScript_GymGuyPostVictory
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial
	release
	end

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders
	release
	end

PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_BrockIntro::
	.string "Así que has venido. Soy BROCK.\n"
	.string "Soy el LÍDER del GIMNASIO de\l"
	.string "CIUDAD PLATEADA.\p"
	.string "Mi férrea voluntad se nota hasta\n"
	.string "en mis POKéMON.\p"
	.string "Mis POKéMON son duros como rocas\n"
	.string "y tienen una determinación a prueba\l"
	.string "de todo.\p"
	.string "¡Eso es! ¡Todos mis POKéMON son\n"
	.string "de tipo ROCA!\p"
	.string "¡Jajaja! ¿Vas a retarme sabiendo\n"
	.string "que vas a perder?\p"
	.string "Es el honor del ENTRENADOR lo que\n"
	.string "te obliga a desafiarme.\p"
	.string "¡Muy bien!\n"
	.string "¡Demuéstrame lo que vales!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PewterCity_Gym_Text_BrockDefeat::
	.string "Te subestimé y por eso he perdido.\p"
	.string "Como prueba de tu victoria, te\n"
	.string "concedo la MEDALLA ROCA oficial\l"
	.string "de la LIGA POKéMON.\p"
	.string "{FONT_NORMAL}¡{PLAYER} ha recibido la MEDALLA ROCA\n"
	.string "de BROCK!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
	.string "{FONT_MALE}Con la MEDALLA ROCA, tus POKéMON\n"
	.string "serán más poderosos.\p"
	.string "Además, podrás usar el movimiento\n"
	.string "DESTELLO fuera de combate.\p"
	.string "Claro que el POKéMON tiene que\n"
	.string "conocer DESTELLO para usarlo.$"

PewterCity_Gym_Text_TakeThisWithYou::
	.string "¡Espera!\n"
	.string "Llévate esto.$"

PewterCity_Gym_Text_ReceivedTM39FromBrock::
	.string "{PLAYER} received TM39\n"
	.string "from BROCK.$"

PewterCity_Gym_Text_ExplainTM39::
	.string "Una MT, o Máquina Técnica, contiene\n"
	.string "una técnica para POKéMON.\p"
	.string "Al usarla, el POKéMON aprende el\n"
	.string "movimiento que contiene.\p"
	.string "Una MT solo sirve para una vez.\p"
	.string "Así que cuando uses una, elige\n"
	.string "con cuidado al POKéMON.\p"
	.string "En fin…\n"
	.string "la MT39 contiene TUMBA ROCAS.\p"
	.string "Lanza rocas contra el rival y le\n"
	.string "reduce la VELOCIDAD.$"

PewterCity_Gym_Text_BrockPostBattle::
	.string "Hay todo tipo de ENTRENADORES en\n"
	.string "este enorme mundo.\p"
	.string "Pareces muy dotado como\n"
	.string "ENTRENADOR POKéMON.\p"
	.string "Así que te voy a hacer una\n"
	.string "sugerencia.\p"
	.string "Ve al GIMNASIO de CIUDAD CELESTE\n"
	.string "y pon a prueba tus habilidades.$"

PewterCity_Gym_Text_DontHaveRoomForThis::
	.string "No tienes espacio para esto.$"

PewterCity_Gym_Text_LiamIntro::
	.string "Stop right there, kid!\p"
	.string "You're ten thousand light-years \n"
	.string "from facing BROCK!$"

PewterCity_Gym_Text_LiamDefeat::
	.string "Darn!\p"
	.string "Light-years isn't time…\n"
	.string "It measures distance!$"

PewterCity_Gym_Text_LiamPostBattle::
	.string "You're pretty hot.\n"
	.string "…But not as hot as BROCK!$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
	.string "¡Hola!\n"
	.string "¿Quieres soñar a lo grande?\p"
	.string "¿Te atreves a soñar con ser el\n"
	.string "CAMPEÓN POKéMON?\p"
	.string "No soy ENTRENADOR, pero puedo\n"
	.string "aconsejarte cómo ganar.\p"
	.string "¡Deja que te lleve a lo más alto!$"

PewterCity_Gym_Text_LetsGetHappening::
	.string "All right!\n"
	.string "Let's get happening!$"

PewterCity_Gym_Text_TryDifferentPartyOrders::
	.string "El primer POKéMON en salir en un\n"
	.string "combate es el de la izquierda de\l"
	.string "la LISTA POKéMON.\p"
	.string "Cambiando el orden de los POKéMON\n"
	.string "puedes conseguir ventaja.\p"
	.string "Prueba con distintos órdenes según\n"
	.string "el equipo de tu rival.$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
	.string "It's a free service!\n"
	.string "Let's get happening!$"

PewterCity_Gym_Text_YoureChampMaterial::
	.string "Just as I thought!\n"
	.string "You're POKéMON champ material!$"

PewterCity_Gym_Text_GymStatue::
	.string "PEWTER POKéMON GYM\n"
	.string "LEADER: BROCK\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"

PewterCity_Gym_Text_GymStatuePlayerWon::
	.string "PEWTER POKéMON GYM\n"
	.string "LEADER: BROCK\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"

