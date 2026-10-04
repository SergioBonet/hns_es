ViridianCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

ViridianCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_SetOldManBlockingRoad
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_SetOldManStandingByRoad
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_SetOldManNormal
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
	end

ViridianCity_EventScript_SetOldManNormal::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	return

ViridianCity_EventScript_SetOldManStandingByRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return

ViridianCity_EventScript_SetOldManBlockingRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

ViridianCity_EventScript_TryUnlockGym::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_NopReturn
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	return

ViridianCity_EventScript_GymDoorLocked::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_JumpDownLedge::
	jump_2_down
	step_end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor::
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
	end

@ Other old man, not the tutorial old man
ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
	closemessage
	applymovement LOCALID_VIRIDIAN_OLD_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
	release
	end

ViridianCity_EventScript_TutorialOldMan::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_TutorialCompleted
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_TutorialStart
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_TutorialNotReady
	end

ViridianCity_EventScript_AskIfTeachyTVHelpful::
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
	release
	end

ViridianCity_EventScript_TeachyTVNotHelpful::
	msgbox ViridianCity_Text_TooBusyForTeachyTV
	release
	end

ViridianCity_EventScript_TutorialCompleted::
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
	release
	end

ViridianCity_EventScript_TutorialStart::
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

@ Unused
ViridianCity_EventScript_WatchToLearnBasics::
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	release
	end

@ Unused. Starts battle after the post battle text, which is odd.
ViridianCity_EventScript_TutorialUnused::
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	special StartOldManTutorialBattle
	waitstate
	release
	end

ViridianCity_EventScript_TutorialNotReady::
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	release
	end

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
	release
	end

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen
	release
	end

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_WomanRoadBlocked
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
	release
	end

ViridianCity_EventScript_WomanRoadBlocked::
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
	closemessage
	applymovement LOCALID_VIRIDIAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_DreamEaterTutor::
	goto EventScript_DreamEaterTutor
	end

ViridianCity_EventScript_RoadBlocked::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_WalkDown::
	walk_down
	step_end

ViridianCity_EventScript_TutorialTriggerLeft::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialTriggerRight::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_DoTutorialBattle::
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
	closemessage
	special StartOldManTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	giveitem ITEM_TEACHY_TV
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	return

ViridianCity_Text_CanCarryMonsAnywhere::
	.string "¿Llevas POKé BALLS?\n"
	.string "¡Entonces tú tienes POKéMON!\p"
	.string "¡Es genial poder llevar y usar los\n"
	.string "POKéMON en cualquier momento\l"
	.string "y lugar!$"

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
	.string "Este GIMNASIO POKéMON está\n"
	.string "siempre cerrado.\p"
	.string "Me pregunto quién será su LÍDER.$"

ViridianCity_Text_ViridiansGymLeaderReturned::
	.string "¡El LÍDER del GIMNASIO VERDE\n"
	.string "ha vuelto!$"

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
	.string "¿Quieres saber algo sobre los 2\n"
	.string "tipos de orugas POKéMON?$"

ViridianCity_Text_OhOkayThen::
	.string "Vale, pues nada.$"

ViridianCity_Text_ExplainCaterpieWeedle::
	.string "¡CATERPIE no tiene veneno; pero\n"
	.string "WEEDLE, sí!\p"
	.string "¡Cuidado con su PICOTAZO\n"
	.string "VENENOSO!$"

ViridianCity_Text_GrandpaHasntHadCoffeeYet::
	.string "¡Oh, abuelo!\n"
	.string "¡No seas tan malo!\p"
	.string "Lo siento, todavía no se ha tomado\n"
	.string "un café...$"

ViridianCity_Text_GoShoppingInPewterOccasionally::
	.string "¡Cuando voy de compras a\n"
	.string "CIUDAD PLATEADA, tomo el sinuoso\l"
	.string "camino del BOSQUE VERDE!$"

ViridianCity_Text_ThisIsPrivateProperty::
	.string "¡Te prohíbo terminantemente\n"
	.string "pasar por aquí!\p"
	.string "¡Esto es propiedad privada!$"

ViridianCity_Text_ShowYouHowToCatchMons::
	.string "Lo bien que me sienta tomarme\n"
	.string "un cafelito... ¡me pone las pilas!\p"
	.string "¿Y esa caja roja que llevas ahí?\p"
	.string "Ah, así que estás trabajando\n"
	.string "en tu POKéDEX...\p"
	.string "Pues deja que te diga algo.\p"
	.string "Cuando atrapes un POKéMON,\n"
	.string "la POKéDEX actualizará sus datos\l"
	.string "de forma automática.\p"
	.string "¿Cómo? ¿Que no sabes atrapar\n"
	.string "POKéMON?\p"
	.string "¡Pues haber empezado por ahí!$"

ViridianCity_Text_ThatWasEducationalTakeThis::
	.string "¡Ya está! Ahora dime, ¿no ha sido\n"
	.string "educativo?\p"
	.string "Y toma, llévate esto también.$"

ViridianCity_Text_WatchThatToLearnBasics::
	.string "Si hay algo que no entiendas, mira eso.\p"
	.string "Te enseñará lo básico de ser\n"
	.string "ENTRENADOR POKéMON.$"

ViridianCity_Text_WeakenMonsFirstToCatch::
	.string "Lo bien que me sienta tomarme\n"
	.string "un cafelito... ¡me pone las pilas!\p"
	.string "Aunque..., creo que estaba muy\n"
	.string "cargado... Me duele la cabeza.\p"
	.string "A todo esto, ¿estás completando\n"
	.string "la POKéDEX?\p"
	.string "No olvides que conviene agotar\n"
	.string "todo lo posible a los POKéMON\l"
	.string "antes de intentar atraparlos.$"

ViridianCity_Text_HowsTeachyTVHelping::
	.string "Lo bien que me sienta tomarme\n"
	.string "un cafelito... ¡me pone las pilas!\p"
	.string "Aunque..., creo que estaba muy\n"
	.string "cargado... Me duele la cabeza.\p"
	.string "A todo esto, ¿te está sirviendo\n"
	.string "mi vieja POKé TELE?$"

ViridianCity_Text_MyGrandsonOnTheShow::
	.string "¡No me extraña, el chico es\n"
	.string "mi nieto!\p"
	.string "¡Con él aprende hasta el menos\n"
	.string "espabilado, je!$"

ViridianCity_Text_TooBusyForTeachyTV::
	.string "Hm… Estás tan ocupado que ni tienes\n"
	.string "tiempo para la TELE DIDÁCTICA…\p"
	.string "El tiempo es oro, y ninguno debe\n"
	.string "gastarse mal…$"

ViridianCity_Text_CitySign::
	.string "CIUDAD VERDE\n"
	.string "El paraíso del eterno verdor.$"

ViridianCity_Text_CatchMonsForEasierBattles::
	.string "PISTAS ENTRENADOR\p"
	.string "¡Atrapa los POKéMON y amplía\n"
	.string "tu colección!\p"
	.string "¡Cuantos más tengas, más fácil\n"
	.string "te será luchar!$"

ViridianCity_Text_MovesLimitedByPP::
	.string "PISTAS ENTRENADOR\p"
	.string "Los ataques de los POKéMON\n"
	.string "dependen de sus PUNTOS de PODER\l"
	.string "o PP.\p"
	.string "¡Para rellenar tus PP, deja que\n"
	.string "tus cansados POKéMON descansen\l"
	.string "en un CENTRO POKéMON!$"

ViridianCity_Text_GymSign::
	.string "GIMNASIO POKéMON DE CIUDAD VERDE$"

ViridianCity_Text_GymDoorsAreLocked::
	.string "Las puertas del GIMNASIO están\n"
	.string "cerradas...$"

