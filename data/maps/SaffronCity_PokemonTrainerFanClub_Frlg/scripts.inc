SaffronCity_PokemonTrainerFanClub_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonTrainerFanClub_OnTransition
	.byte 0

SaffronCity_PokemonTrainerFanClub_OnFrame::
	map_script_2 VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_Delay48
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HuhYou
	closemessage
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow
	setvar VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2
	releaseall
	end

SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer::
	delay_16
	delay_8
	walk_down
	delay_16
	walk_down
	delay_8
	walk_left
	step_end

SaffronCity_PokemonTrainerFanClub_OnTransition::
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2, SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
	special Script_TryLoseFansFromPlayTime
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, 5, 2
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_YOUNGSTER, 7, 4
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_YOUNGSTER, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_GENTLEMAN, 2, 2
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_GENTLEMAN, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, 3, 4
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, MOVEMENT_TYPE_FACE_RIGHT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_ROCKER, 4, 6
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_ROCKER, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_WOMAN, 10, 3
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_WOMAN, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BEAUTY, 7, 5
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BEAUTY, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BLACK_BELT, 9, 6
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BLACK_BELT, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting::
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Youngster::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Gentleman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Woman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Rocker::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBelt::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster
	release
	end

SaffronCity_PokemonTrainerFanClub_Text_HuhYou::
	.string "¿Mm?\n"
	.string "Tú...$"

SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow::
	.string "¿Serás acaso…?\n"
	.string "… …\p"
	.string "¡Lo eres!\n"
	.string "¡Eres {PLAYER}!\p"
	.string "¡Justo estábamos hablando de ti!\p"
	.string "Hablábamos de cómo había aparecido\n"
	.string "un ENTRENADOR increíblemente bueno.\p"
	.string "¡Y ese eres tú!\n"
	.string "¡Eres tan genial!\p"
	.string "Así que hemos decidido que\n"
	.string "seremos tu CLUB de FANS.\p"
	.string "Esperamos que sigas combatiendo y\n"
	.string "nos muestres lo genial que eres.\p"
	.string "Así, quizá otras personas se hagan\n"
	.string "fans como yo.$"

SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou::
	.string "¡Pienso animarte siempre!\p"
	.string "¡A la bim, a la bam, a la bim,\n"
	.string "bom, bam! ¡{PLAYER}, {PLAYER}, y\l"
	.string "nadie más! ¡A la bim, bom, bam!$"

SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou::
	.string "¡Pienso apoyarte siempre, {PLAYER}!\p"
	.string "¡Enséñale al mundo de lo que\n"
	.string "eres capaz cuando te lo propones!$"

SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore::
	.string "Lo siento.\n"
	.string "Yo era tu fan...\p"
	.string "Pero has perdido mucho tirón...\p"
	.string "Últimamente, quien parte la pana\n"
	.string "es {STR_VAR_1}, la verdad...$"

SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe::
	.string "¡Hola, {PLAYER}!\p"
	.string "¡Últimamente todo el mundo está\n"
	.string "revolucionado contigo!\p"
	.string "Y lo entiendo, eres muy fuerte...\p"
	.string "Pero ¿sabes qué pasa?\p"
	.string "Que me hice fan de {STR_VAR_1}\n"
	.string "y no es plan de echarme atrás\l"
	.string "ahora, ¿no?$"

SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling::
	.string "A mí me parece que no hay nada\n"
	.string "más guay que ver luchar a los\l"
	.string "ENTRENADORES.\p"
	.string "¿No te parece?$"

SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts::
	.string "¡Madre mía, pero si es {PLAYER}!\n"
	.string "¡Guau, qué pasada!\p"
	.string "¡Qué guay, qué guay!\n"
	.string "¡Qué emoción!\p"
	.string "¿Me firmas un autógrafo?\n"
	.string "¡Fírmame en los pantalones,\l"
	.string "no pasa nada!$"

SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou::
	.string "¡Yo siempre llevo pantalones\n"
	.string "cortos, como tú!\p"
	.string "¡Ya llueva, nieve, o ventee!\p"
	.string "¡Yo iré con pantalón corto,\n"
	.string "como tú!\p"
	.string "¡Venga, debes ir a por todas!\p"
	.string "¡Yo confío en ti y no me pienso\n"
	.string "quitar los pantalones cortos!\l"
	.string "¡Pantalones cortos al poder!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero::
	.string "¡BROCK es mi héroe!\n"
	.string "No hay otro como él.\p"
	.string "¡Lo admiro tanto que le he\n"
	.string "pedido a mi madre que me borde\l"
	.string "su nombre en los pantalones, je!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd::
	.string "…  …\p"
	.string "…  …\n"
	.string "¡Soy fan de BROCK!\p"
	.string "Aunque fuera su único fan,\n"
	.string "lo juro por mi voluntad de roca,\n"
	.string "y por mis calzoncillos.\p"
	.string "¡Seré su fan hasta el final!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool::
	.string "BROCK es la caña, punto.\p"
	.string "¡Ya me gustaría a mí ser como él!$"

SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle::
	.string "{PLAYER}, he tenido el placer\n"
	.string "de verte luchar.\p"
	.string "Y me he visto de joven. Ah, qué\n"
	.string "dulces y lejanos recuerdos...\p"
	.string "Sigue por el camino que llevas.\n"
	.string "Pienso seguirte siempre.$"

SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence::
	.string "He viajado por mil sitios y puedo\n"
	.string "decir que ningún ENTRENADOR\l"
	.string "te llega a la suela del zapato.\p"
	.string "¡Confía en tus posibilidades\n"
	.string "y sigue luchando!\p"
	.string "¡Di que vas a seguir luchando!\n"
	.string "¡Muy bien, joven!$"

SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre::
	.string "¿Mm?\n"
	.string "¿Y tú quién eres?\p"
	.string "¿Vienes a apuntarte al CLUB?$"

SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo::
	.string "Ah, así que tú eres el famoso\n"
	.string "{PLAYER}.\p"
	.string "Desde luego tienes pinta de\n"
	.string "ganador.\p"
	.string "Pero para aceptarte como un\n"
	.string "verdadero gran POKéMON…\p"
	.string "… …\n"
	.string "¡Aún te queda camino por recorrer!$"

SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning::
	.string "Todos los que estamos aquí somos\n"
	.string "fans de ENTRENADORES POKéMON.\p"
	.string "La imagen que dan cuando luchan...\n"
	.string "¡Son supercarismáticos!\p"
	.string "No sé, si ganas más combates,\n"
	.string "¡igual acabamos hablando todos\l"
	.string "de ti!$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay::
	.string "¡Eh, que es {PLAYER}!\n"
	.string "¡Es {PLAYER}!\p"
	.string "¡Yo quiero llegar a ser como\n"
	.string "{PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan::
	.string "Todo el mundo ha dejado de ser\n"
	.string "fan de {PLAYER}...\p"
	.string "¡Me da igual, así me tiene sólo\n"
	.string "a mí!\p"
	.string "¡{PLAYER}, {PLAYER}, {PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina::
	.string "¿Sabes qué?\n"
	.string "¡Me encantaría ser como SABRINA!\p"
	.string "¡Y dominar los poderes psíquicos,\n"
	.string "como ella!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan::
	.string "No pienso dejar nunca a SABRINA.\n"
	.string "¡Aunque sea su única fan!.\p"
	.string "Mi sueño es llegar a ser como\n"
	.string "ella; dulce, pero guay a la vez.\p"
	.string "¡Y dominar los poderes psíquicos,\n"
	.string "como ella!$"

SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay::
	.string "¿Llegaré a ser buena ENTRENADORA\n"
	.string "algún día?$"

SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool::
	.string "¡Qué pasada, qué pasada!\n"
	.string "¡Qué guay, qué guay!\p"
	.string "¿Mm?...\n"
	.string "No, no lo digo por ti.\p"
	.string "Lo digo por tu forma de luchar.\n"
	.string "Es guay.$"

SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans::
	.string "¡Eh, {PLAYER}!\p"
	.string "Creo que soy el único fan que\n"
	.string "tienes.\p"
	.string "Pero oye, tiene su lado positivo,\n"
	.string "te evitas mucho estrés.\p"
	.string "¡Sigue como hasta ahora!$"

SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks::
	.string "Qué guay es {STR_VAR_1}, ¿verdad?\n"
	.string "Me gusta hasta su forma de hablar.\p"
	.string "¡Me encantaría que viniera alguna\n"
	.string "vez por aquí!$"

SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan::
	.string "¿Será posible?\n"
	.string "¡Todo el mundo es fan tuyo!\p"
	.string "O sea, ¿que soy el único fan\n"
	.string "de {STR_VAR_1}?\p"
	.string "Bueno, en realidad, ¿qué más\n"
	.string "me da?$"

SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle::
	.string "¡No me lo puedo creer!\n"
	.string "¿Eres {PLAYER}, en serio?\p"
	.string "Tengo que decirte que me encanta\n"
	.string "la forma de luchar que tienes.\p"
	.string "Espero que no cambies nunca.\n"
	.string "¡Soy tu fan más fan!$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan::
	.string "¡No me lo puedo creer!\n"
	.string "¡Pero si es {PLAYER}!\p"
	.string "Quería decirte que estoy un poco\n"
	.string "chafada, porque soy tu única fan.\p"
	.string "Pero bueno, pienso animarte\n"
	.string "de todas formas.\p"
	.string "¡Viva {PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire::
	.string "Quien ha estado en boca de todos\n"
	.string "últimamente es {STR_VAR_1}.\p"
	.string "Lucha de una manera...\n"
	.string "Como a mí me gusta, vaya.$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou::
	.string "¡Oh, hola!\n"
	.string "¡Si es {PLAYER}!\p"
	.string "Últimamente todo el mundo habla\n"
	.string "solo de ti.\p"
	.string "Me siento solo porque prefiero\n"
	.string "a {STR_VAR_1}.$"

SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing::
	.string "¡Increíble! ¡{PLAYER}, eres increíble!\p"
	.string "En lugar de solo mirar, quizá debería\n"
	.string "hacerme ENTRENADOR yo también.$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan::
	.string "Soy tu única fan...\n"
	.string "Y... me encuentro tan sola...\p"
	.string "¿Por qué no te esfuerzas un poco\n"
	.string "para que se fijen en ti?$"

SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity::
	.string "El maestro {STR_VAR_1} es tan digno…\n"
	.string "Es totalmente mi tipo.\p"
	.string "¿Por qué los demás no ven la\n"
	.string "dignidad que rezuma?$"

SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart::
	.string "Creo en el maestro {STR_VAR_1}\n"
	.string "con todo mi corazón.\p"
	.string "Aunque sea la única que cree en él.\p"
	.string "Pero nunca me sentiré sola.\p"
	.string "Mientras siga pensando en el maestro\n"
	.string "{STR_VAR_1}.$"

SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational::
	.string "¡Guau!\p"
	.string "¡Tu forma de luchar es ejemplar!\p"
	.string "¡Espero que nunca dejes de tener\n"
	.string "éxito! ¡Ánimo!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan::
	.string "¡No te entretengas mirando cómo\n"
	.string "lucha el resto! ¡Lucha tú!\p"
	.string "Mi MAESTRO me echó del DOJO\n"
	.string "como el que no quiere la cosa...\p"
	.string "Pero, me da igual, yo voy a seguir\n"
	.string "siendo tu fan.\p"
	.string "¡No pienso dejar de serlo!$"

SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect::
	.string "¡Hiyah! Sólo tengo respeto por\n"
	.string "un ENTRENADOR.\p"
	.string "Por mi MAESTRO. No hay nadie\n"
	.string "como él sobre el DOJO.\p"
	.string "Deberías hacerte su fan, como yo.\n"
	.string "¡Hiyah!$"

SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster::
	.string "¡Hiyah! Tengo un respeto enorme\n"
	.string "por mi MAESTRO.\l"
	.string "Es el mejor sobre el DOJO.\p"
	.string "No pienso ser fan de nadie más.\p"
	.string "Voy a ir diciendo por ahí lo bueno\n"
	.string "que es.\p"
	.string "¡Hiyah!$"

