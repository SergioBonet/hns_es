.set FOUND_FIRST_SWITCH, FLAG_TEMP_1
.set SWITCH1_ID,         VAR_0x8004
.set SWITCH2_ID,         VAR_0x8005
.set TRASH_CAN_ID,       VAR_0x8008

.set CHECK_VISITOR_STATE, 6
.set TYPE, VAR_0x8003
.set ARGUMENT, VAR_0x8004

VermilionCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_Return::
	end

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_EventScript_Gregory::
	trainerbattle_single TRAINER_GREGORY_HNS, VermilionGym_Text_GentlemanGregorySeen, VermilionGym_Text_GentlemanGregoryBeaten
	msgbox VermilionGym_Text_GentlemanGregoryAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT_HNS, VermilionGym_Text_GuitaristVincentSeen, VermilionGym_Text_GuitaristVincentBeaten
	msgbox VermilionGym_Text_GuitaristVincentAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Horton::
	trainerbattle_single TRAINER_HORTON_HNS, VermilionGym_Text_JugglerHortonSeen, VermilionGym_Text_JugglerHortonBeaten
	msgbox VermilionGym_Text_JugglerHortonAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_Surge_Defeated
	msgbox VermilionGym_Text_LtSurgeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LTSURGE_HNS, VermilionGym_Text_LtSurgeWinLoss
	message VermilionGym_Text_ReceivedThunderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VermilionGym_Text_ThunderBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE11_GET
	setflag FLAG_DEFEATED_VERMILION_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers_hns
	checkitem ITEM_TM_SHOCK_WAVE
	call_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_GiveThunderstone
	call_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_GiveTM
	clearflag FLAG_HIDE_PLANT_SURGE
	closemessage
	release
	end

VermilionCity_Gym_EventScript_GiveThunderstone::
	msgbox VermilionGym_Text_LtSurgeThunderstone, MSGBOX_DEFAULT
	giveitem ITEM_THUNDER_STONE
	return

VermilionCity_Gym_EventScript_GiveTM::
	msgbox VermilionGym_Text_LtSurge_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SHOCK_WAVE
	msgbox VermilionGym_Text_LtSurge_ExplainTM, MSGBOX_DEFAULT
	return

VermilionCity_Gym_EventScript_Surge_Defeated::
	msgbox VermilionGym_Text_LtSurgePostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionGym_Text_LtSurgeIntro:
	.string "SURGE: ¡Eh, tú, joven!\p"
	.string "Tengo que reconocerlo. No es que sea\n"
	.string "inteligente desafiarme, ¡pero requiere\l"
	.string "agallas!\p"
	.string "Cuando se trata de POKéMON\p"
	.string "eléctricos, ¡soy el número uno!\p"
	.string "Nunca he perdido en la batalla.\p"
	.string "¡Te electrocutaré como hice con el\n"
	.string "enemigo en la guerra!$"

VermilionGym_Text_LtSurgeWinLoss:
	.string "SURGE: ¡Arrrgh! ¡Eres fuerte!\p"
	.string "Vale, joven. ¡Toma la MEDALLA TRUENO!$"

VermilionGym_Text_ReceivedThunderBadge:
	.string "¡{PLAYER} ha recibido la MEDALLA\n"
	.string "TRUENO!$"

VermilionGym_Text_ThunderBadgeInfo:
	.string "SURGE: La MEDALLA TRUENO aumenta la\p"
	.string "VELOCIDAD de los POKéMON.\p"
	.string "Te la mereces por haberme vencido.\p"
	.string "Llévala con orgullo, ¿me oyes?$"

VermilionGym_Text_LtSurge_GiveTM:
	.string "Y llévate esta MT. ¡Me fue muy útil en\n"
	.string "la guerra!$"

VermilionGym_Text_LtSurge_ExplainTM:
	.string "Es ONDA VOLTIO.\p"
	.string "¡Un movimiento increíblemente preciso\n"
	.string "que acierta siempre!$"

VermilionGym_Text_LtSurgeThunderstone:
	.string "Y llévate esta piedra. ¡Tiene\n"
	.string "auténtico poder del trueno!$"


VermilionGym_Text_LtSurgePostBattle:
	.string "SURGE: ¡Eh, tú! ¿Todavía estás\n"
	.string "molestando por aquí?\p"
	.string "¡Mis POKéMON y yo seguimos en ello!$"

VermilionGym_Text_SurgeRematch:
	.string "SURGE: ¡Así que ahora eres el CAMPEÓN\n"
	.string "de KANTO!\p"
	.string "¡Buen trabajo, chaval! ¡Pero no creas\n"
	.string "que he terminado!\p"
	.string "¿Qué tal si lo intentamos otra vez?$"

VermilionGym_Text_SurgeRematchDefeat:
	.string "SURGE: ¡Aaargh! ¡Sigues siendo igual\n"
	.string "de fuerte!$"

VermilionGym_Text_GentlemanGregorySeen:
	.string "¿Has venido a vencer al LT. SURGE?\p"
	.string "¡No si yo puedo evitarlo!$"

VermilionGym_Text_GentlemanGregoryBeaten:
	.string "¡Cuánto siento haberle fallado, LT.\n"
	.string "SURGE!$"

VermilionGym_Text_GentlemanGregoryAfter:
	.string "Cuando aún estaba en el ejército, el\n"
	.string "LT. SURGE me salvó la vida.$"

VermilionGym_Text_GuitaristVincentSeen:
	.string "El LT. SURGE reconoció mi potencial\n"
	.string "con los POKéMON eléctricos.\p"
	.string "¿Crees que puedes vencerme?$"

VermilionGym_Text_GuitaristVincentBeaten:
	.string "¡Ooh! ¡Increíble!$"

VermilionGym_Text_GuitaristVincentAfter:
	.string "Mi madre me dijo que no dejara mi\n"
	.string "trabajo, pero ¿qué hago si tampoco\l"
	.string "tengo éxito ahí?$"

VermilionGym_Text_JugglerHortonSeen:
	.string "¡Voy a acabar contigo! ¡Vas a echar\n"
	.string "chispas!$"

VermilionGym_Text_JugglerHortonBeaten:
	.string "¡Vaya! Me has vencido…$"

VermilionGym_Text_JugglerHortonAfter:
	.string "No te relajes por haberme vencido…\p"
	.string "LT. SURGE es muy fuerte.$"

VermilionCity_Gym_Text_GymGuyAdvice::
	.string "¡Eh! ¡Futuro CAMPEÓN!\p"
	.string "El LT. SURGE tiene un apodo.\p"
	.string "La gente le llama ¡el Rayo americano!\p"
	.string "Es un experto en POKéMON eléctricos.\p"
	.string "Los POKéMON de tipo VOLADOR y AGUA se\n"
	.string "llevan mal con el tipo ELÉCTRICO.\p"
	.string "Ten cuidado también con la parálisis.\p"
	.string "El LT. SURGE es muy precavido.\p"
	.string "Se ha encerrado, así que no será fácil\n"
	.string "llegar hasta él.$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "¡Vaya combate más electrizante!\p"
	.string "¡Me has puesto muy nervioso!$"

VermilionCity_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON DE CIUDAD CARMÍN\n"
	.string "LÍDER: LT. SURGE\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO$"


VermilionCity_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE CIUDAD CARMÍN\n"
	.string "LÍDER: LT. SURGE\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
	.string "¡Nada! Aquí solo hay basura.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
	.string "¡Eh! ¡Hay un interruptor bajo la\n"
	.string "basura! ¡Actívalo!\p"
	.string "¡Se ha abierto la primera cerradura\n"
	.string "eléctrica!$"

VermilionCity_Gym_Text_SecondLockOpened::
	.string "¡Se ha abierto la segunda cerradura\n"
	.string "eléctrica! ¡Se ha abierto la puerta\l"
	.string "motorizada!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
	.string "¡Nada! Aquí solo hay basura.\p"
	.string "¡Eh! ¡Las cerraduras eléctricas se han\n"
	.string "reiniciado!$"

