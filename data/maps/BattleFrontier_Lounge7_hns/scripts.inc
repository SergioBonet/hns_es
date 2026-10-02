BattleFrontier_Lounge7_hns_MapScripts::
	.byte 0

@special ChooseMonForMoveTutor
BattleFrontier_Lounge7_EventScript_LeftMoveTutor_hns::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor_hns
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro_hns, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor_hns::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove_hns::
	message BattleFrontier_Lounge7_Text_TeachWhichMove_hns
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled_hns
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss_hns
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater_hns
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch_hns
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick_hns
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam_hns
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide_hns
	case 7, BattleFrontier_Lounge7_EventScript_Counter_hns
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave_hns
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance_hns
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove_hns::
	message BattleFrontier_Lounge7_Text_TeachWhichMove_hns
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled_hns
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss_hns
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater_hns
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch_hns
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick_hns
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam_hns
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide_hns
	case 7, BattleFrontier_Lounge7_EventScript_Counter_hns
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave_hns
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance_hns
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	end

BattleFrontier_Lounge7_EventScript_Softboiled_hns::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_SeismicToss_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_DreamEater_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_MegaPunch_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_MegaKick_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_BodySlam_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_RockSlide_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_Counter_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_COUNTER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_ThunderWave_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_SwordsDance_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor_hns::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor_hns
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro_hns, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor_hns::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove_hns::
	message BattleFrontier_Lounge7_Text_TeachWhichMove_hns
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl_hns
	case 1, BattleFrontier_Lounge7_EventScript_Snore_hns
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap_hns
	case 3, BattleFrontier_Lounge7_EventScript_Swift_hns
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind_hns
	case 5, BattleFrontier_Lounge7_EventScript_Endure_hns
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp_hns
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch_hns
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch_hns
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch_hns
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove_hns::
	message BattleFrontier_Lounge7_Text_TeachWhichMove_hns
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl_hns
	case 1, BattleFrontier_Lounge7_EventScript_Snore_hns
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap_hns
	case 3, BattleFrontier_Lounge7_EventScript_Swift_hns
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind_hns
	case 5, BattleFrontier_Lounge7_EventScript_Endure_hns
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp_hns
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch_hns
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch_hns
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch_hns
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl_hns::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_Snore_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SNORE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_MudSlap_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MUD_SLAP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_Swift_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SWIFT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_IcyWind_hns::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_Endure_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ENDURE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_PsychUp_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_PSYCH_UP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_IcePunch_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_FirePunch_hns::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns_hns::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon_hns_hns::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo_hns, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove_hns
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove_hns
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove_hns
	end


BattleFrontier_Lounge7_EventScript_TeachTutorMove_hns::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon_hns_hns
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints_hns, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove_hns::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove_hns
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, BattleFrontier_Lounge7_EventScript_ChooseNewElementalTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove_hns
	end

BattleFrontier_Lounge7_EventScript_Sailor_hns::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetElementalTutor
	msgbox BattleFrontier_Lounge7_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetElementalTutor::
	msgbox BattleFrontier_Lounge7_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_FrenzyPlant
	case 1, BattleFrontier_Lounge7_EventScript_BlastBurn
	case 2, BattleFrontier_Lounge7_EventScript_HydroCannon
	case 3, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns
	end

BattleFrontier_Lounge7_EventScript_ChooseNewElementalTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_FrenzyPlant
	case 1, BattleFrontier_Lounge7_EventScript_BlastBurn
	case 2, BattleFrontier_Lounge7_EventScript_HydroCannon
	case 3, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns
	end

BattleFrontier_Lounge7_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	setvar VAR_0x8005, MOVE_FRENZY_PLANT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	setvar VAR_0x8005, MOVE_BLAST_BURN
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	setvar VAR_0x8005, MOVE_HYDRO_CANNON
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection_hns
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect_hns::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon_hns::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end


BattleFrontier_Lounge7_Text_LeftTutorIntro_hns:
	.string "¡Ji, ji, ji, ji!\p"
	.string "Quizás ahora no lo parezca, pero yo\n"
	.string "en su día fui una gran ENTRENADORA.\p"
	.string "¡Decían que yo era la BELLA y la bestia!\n"
	.string "¡Las dos juntas!\p"
	.string "¿Mmm?\p"
	.string "¿Qué?…\n"
	.string "Ah, ¿que no me crees?\p"
	.string "¡Pues no te pienses que sólo\n"
	.string "soy una pobre viejecita!\l"
	.string "¡Como ésa de ahí enfrente!\p"
	.string "Te lo voy a demostrar.\n"
	.string "Les puedo enseñar a tus POKéMON\l"
	.string "movimientos especiales.\p"
	.string "Pero las lecciones no son gratis, claro.\n"
	.string "Yo cobro en PUNTOS de BATALLA.$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack_hns:
	.string "¡Ji, ji, ji, ji!\p"
	.string "¿Has vuelto para aprender movimientos \n"
	.string "especiales para tus POKéMON?$"

BattleFrontier_Lounge7_Text_TeachWhichMove_hns:
	.string "Bien, bien.\n"
	.string "¿Qué quieres que te enseñe?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints_hns:
	.string "Conque el movimiento {STR_VAR_1}…\n"
	.string "Te costará {STR_VAR_2} PUNTOS de BATALLA, ¿sí?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon_hns:
	.string "¿A qué POKéMON quieres que se lo\n"
	.string "enseñe?\p"
	.string "$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints_hns:
	.string "¿Pero cómo…? ¿No ves que no tienes\n"
	.string "suficientes PUNTOS de BATALLA?$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints_hns:
	.string "¿A que ahora no parezco tan viejecita?\n"
	.string "¡Vengan acá esos PUNTOS de BATALLA!$"

BattleFrontier_Lounge7_Text_YouDontWantTo_hns:
	.string "¡Cómo!\n"
	.string "¿Ya no quieres…?\p"
	.string "En fin, si quieres aprender algo bueno,\n"
	.string "¡ven a verme cuando quieras!$"

BattleFrontier_Lounge7_Text_RightTutorIntro_hns:
	.string "¡Je, je, je, je!\p"
	.string "Sé que resulta difícil de creer, pero yo\n"
	.string "antes era una ENTRENADORA fantástica.\p"
	.string "¡Tenía fama de ser una NADADORA\n"
	.string "poco menos que invencible! ¡En serio!\p"
	.string "¿Mmm?\p"
	.string "¿Qué pasa?\n"
	.string "¿No me crees?\p"
	.string "A diferencia de esa abuelita de ahí,\n"
	.string "yo aún tengo mucho que enseñar.\p"
	.string "Y puedo demostrártelo.\n"
	.string "Puedo enseñarte movimientos POKéMON\l"
	.string "“alucinantes”, como decís los jóvenes.\p"
	.string "Aunque, claro, aprender un movimiento\n"
	.string "te costará PUNTOS de BATALLA.$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack_hns:
	.string "¡Je, je, je, je!\p"
	.string "¿Has venido a aprender movimientos \n"
	.string "especiales para tus POKéMON?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong_hns:
	.string "Seguro que al ver a esas viejecitas\n"
	.string "ponerse verdes, pensarás que no pueden\l"
	.string "ni verse, ¿verdad?\p"
	.string "Pero yo creo que, si se llevasen tan mal,\n"
	.string "no estarían todo el rato juntas, ¿no?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful_hns:
	.string "Cuando yo era un apuesto JOVEN, esas\n"
	.string "ancianas de ahí eran las ENTRENADORAS\l"
	.string "más guapas y más fuertes que había.\p"
	.string "Eran la envidia de todas las demás.\p"
	.string "Ni siquiera la edad ha echado a perder\n"
	.string "sus encantos, ni sus habilidades.\p"
	.string "De hecho, juraría que sus movimientos\n"
	.string "POKéMON son ahora más perfectos.\p"
	.string "De todos modos, siento\n"
	.string "no sé qué al verlas…\p"
	.string "Ay, el tiempo es tan cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc_hns::
	.string "Restaura hasta\n"
	.string "la mitad de tus\n"
	.string "PS máximos.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc_hns::
	.string "Resta los mismos\n"
	.string "PS que nivel\n"
	.string "tenga el agresor.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc_hns::
	.string "Roba la mitad del\n"
	.string "daño causado\n"
	.string "a un rival dormido.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc_hns::
	.string "Un fuerte puñetazo\n"
	.string "lanzado con una\n"
	.string "fuerza increíble.$"

BattleFrontier_Lounge7_Text_MegaKickDesc_hns::
	.string "Una patada muy\n"
	.string "potente lanzada\n"
	.string "con gran fuerza.$"

BattleFrontier_Lounge7_Text_BodySlamDesc_hns::
	.string "Un placaje con\n"
	.string "todo el cuerpo que\n"
	.string "puede paralizar.$"

BattleFrontier_Lounge7_Text_RockSlideDesc_hns::
	.string "Lanza grandes\n"
	.string "rocas. Puede hacer\n"
	.string "retroceder.$"

BattleFrontier_Lounge7_Text_CounterDesc_hns::
	.string "Devuelve el doble\n"
	.string "de daño de los\n"
	.string "golpes físicos.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc_hns::
	.string "Una débil descarga\n"
	.string "eléctrica que\n"
	.string "paraliza al rival.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc_hns::
	.string "Una danza de\n"
	.string "combate que sube\n"
	.string "mucho el ATAQUE.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc_hns::
	.string "Oculta su punto\n"
	.string "débil al rizarse.\n"
	.string "Sube la DEFENSA.$"

BattleFrontier_Lounge7_Text_SnoreDesc_hns::
	.string "Fuerte ronquido\n"
	.string "que puede usarse\n"
	.string "estando dormido.$"

BattleFrontier_Lounge7_Text_MudSlapDesc_hns::
	.string "Echa lodo en la\n"
	.string "cara para bajar\n"
	.string "la PRECISIÓN.$"

BattleFrontier_Lounge7_Text_SwiftDesc_hns::
	.string "Lanza rayos en\n"
	.string "forma de estrella\n"
	.string "que no fallan.$"

BattleFrontier_Lounge7_Text_IcyWindDesc_hns::
	.string "Un ataque gélido\n"
	.string "que baja la\n"
	.string "VELOCIDAD rival.$"

BattleFrontier_Lounge7_Text_EndureDesc_hns::
	.string "Aguanta cualquier\n"
	.string "ataque 1 turno y\n"
	.string "queda con 1 PS.$"

BattleFrontier_Lounge7_Text_PsychUpDesc_hns::
	.string "Copia los efectos\n"
	.string "del rival y se los\n"
	.string "pasa al usuario.$"

BattleFrontier_Lounge7_Text_IcePunchDesc_hns::
	.string "Un puñetazo\n"
	.string "helado que puede\n"
	.string "congelar al rival.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc_hns::
	.string "Un puñetazo\n"
	.string "eléctrico que puede\n"
	.string "paralizar al rival.$"

BattleFrontier_Lounge7_Text_FirePunchDesc_hns::
	.string "Un puñetazo\n"
	.string "ardiente que puede\n"
	.string "quemar al rival.$"


BattleFrontier_Lounge7_Text_ElementalTutorIntro::
	.string "Zzzzzz…\p"
	.string "¿Qué, cómo, qué?\p"
	.string "Ay, perdona, me había quedado\n"
	.string "traspuesto.\p"
	.string "Soy el TUTOR ELEMENTAL.\p"
	.string "Tengo el poder de enseñar los\n"
	.string "movimientos más poderosos a los\l"
	.string "POKéMON de tipo PLANTA, FUEGO y AGUA.\p"
	.string "¿Has venido a aprender un poder tan\n"
	.string "grande?$"

BattleFrontier_Lounge7_Text_ElementalTutorWelcomeBack:
	.string "Zzzzzz…\p"
	.string "¿Qué, cómo, qué, quién?\p"
	.string "Ah, ¿has venido a aprender el poder de\n"
	.string "mis movimientos más fuertes?$"

BattleFrontier_Lounge7_Text_TeachWhichMoveElemental::
	.string "¿Qué movimiento crees que le irá bien\n"
	.string "a tu POKéMON?$"

BattleFrontier_Lounge7_Text_StrongElementalMoveDesc::
	.string "Muy potente, pero\n"
	.string "el usuario queda\n"
	.string "inmóvil un turno.$"

