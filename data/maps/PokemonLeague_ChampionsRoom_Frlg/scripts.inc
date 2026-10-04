PokemonLeague_ChampionsRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander
	end

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle::
	goto_if_defeated TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur::
	goto_if_defeated TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander::
	goto_if_defeated TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_ChampionsRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_ChampionsRoom_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	setflag FLAG_TEMP_2
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
	waitmovement 0
	delay 20
	call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_Intro
	call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_VICTORY_GYM_LEADER
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_Battle
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_Rematch
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_DEFEATED_CHAMP
	setflag FLAG_TEMP_4
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle
	playbgm MUS_RG_SLOW_PALLET, 0
	addobject LOCALID_CHAMPIONS_ROOM_PROF_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayer
	closemessage
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter
	applymovement LOCALID_KANTO_CHAMPIONS_ROOM_RIVAL, PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	waitmovement 0
	delay 25
	specialvar VAR_RESULT, GetStarterPokemon
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_KANTO_CHAMPIONS_ROOM_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe
	closemessage
	delay 13
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakExit
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 5, 12
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_QuestLogEnd::
	call PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_Battle::
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_BattleCharmander
	return

PokemonLeague_ChampionsRoom_EventScript_Rematch::
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_RematchCharmander
	return

PokemonLeague_ChampionsRoom_EventScript_Intro::
	msgbox PokemonLeague_ChampionsRoom_Text_Intro
	return

PokemonLeague_ChampionsRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchIntro
	return

PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleCharmander::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchCharmander::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_Movement_PlayerEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerExit::
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter::
	delay_8
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter::
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_in_place_faster_down
	delay_16
	step_end

PokemonLeague_ChampionsRoom_Movement_OakExit::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Text_Intro::
	.string "{RIVAL}: ¡Eh, {PLAYER}!\p"
	.string "Tenía ganas de verte, {PLAYER}.\p"
	.string "Mi rival debe ser fuerte para\n"
	.string "mantenerme en forma.\p"
	.string "Mientras completaba mi POKéDEX, busqué\n"
	.string "POKéMON por todas partes.\p"
	.string "Además, formé equipos que vencerían\n"
	.string "a cualquier tipo de POKéMON.\p"
	.string "Y ahora…\p"
	.string "¡Soy el CAMPEÓN de la LIGA POKéMON!\p"
	.string "¡{PLAYER}!\n"
	.string "¿Sabes lo que eso significa?\p"
	.string "Te lo diré.\p"
	.string "¡Soy el ENTRENADOR más poderoso\n"
	.string "del mundo!$"

PokemonLeague_ChampionsRoom_Text_RematchIntro::
	.string "{RIVAL}: ¡Eh, {PLAYER}!\p"
	.string "¡Has vuelto, {PLAYER}!\n"
	.string "Jaja, ¡qué bien!\p"
	.string "Mi rival debe ser fuerte para\n"
	.string "mantenerme en forma.\p"
	.string "Mientras completaba mi POKéDEX, busqué\n"
	.string "POKéMON por todas partes.\p"
	.string "Además, formé equipos que vencerían\n"
	.string "a cualquier tipo de POKéMON.\p"
	.string "Y ahora…\p"
	.string "¡Soy el CAMPEÓN de la LIGA POKéMON!\p"
	.string "¡{PLAYER}!\n"
	.string "¿Sabes lo que eso significa?\p"
	.string "Te lo diré.\p"
	.string "¡Soy el ENTRENADOR más poderoso\n"
	.string "del mundo!$"

PokemonLeague_ChampionsRoom_Text_Defeat::
	.string "¡NO!\n"
	.string "¡Eso no puede ser!\l"
	.string "¡Me has vencido en mi mejor momento!\p"
	.string "¿Después de tanto trabajo para ser\n"
	.string "el CAMPEÓN de la LIGA?\p"
	.string "¿Mi reinado ya ha terminado?\n"
	.string "¡No es justo!$"

PokemonLeague_ChampionsRoom_Text_Victory::
	.string "¡Jajá!\n"
	.string "¡He ganado! ¡He ganado! ¡He ganado!\p"
	.string "¡No soy de los que pierden contra\n"
	.string "{PLAYER}!\p"
	.string "Bueno, ¡te has esforzado mucho\n"
	.string "contra mí, {RIVAL}, el genio de los\l"
	.string "POKéMON!\p"
	.string "¡Te elogio por ello!\n"
	.string "¡Jajajajá!$"

PokemonLeague_ChampionsRoom_Text_PostBattle::
	.string "¿Por qué?\n"
	.string "¿Por qué he perdido?\p"
	.string "Nunca cometí errores criando\n"
	.string "a mis POKéMON…\p"
	.string "¡Maldición! ¡Eres el nuevo CAMPEÓN\n"
	.string "de la LIGA POKéMON!\p"
	.string "Aunque no me guste admitirlo…$"

PokemonLeague_ChampionsRoom_Text_OakPlayer::
	.string "OAK: ¡{PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations::
	.string "OAK: ¡Así que has ganado!\n"
	.string "¡Mi más sincera enhorabuena!\p"
	.string "¡Eres el nuevo CAMPEÓN de la\n"
	.string "LIGA POKéMON!\p"
	.string "Has crecido mucho desde que te\n"
	.string "fuiste con {STR_VAR_1} a trabajar\l"
	.string "en la POKéDEX.\p"
	.string "¡{PLAYER}, te has hecho mayor!$"

PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival::
	.string "OAK: {RIVAL}…\n"
	.string "Estoy decepcionado contigo.\p"
	.string "Vine al oír que habías vencido\n"
	.string "al ALTO MANDO.\p"
	.string "¡Pero, cuando llegué, ya habías\n"
	.string "perdido!\p"
	.string "{RIVAL}, ¿entiendes por qué\n"
	.string "perdiste?\p"
	.string "Has olvidado tratar a tus\n"
	.string "POKéMON con amor y confianza.\p"
	.string "¡Sin ellos, jamás volverás a ser\n"
	.string "CAMPEÓN!$"

PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe::
	.string "OAK: {PLAYER}.\p"
	.string "Entiendes que tu victoria no fue\n"
	.string "solo mérito tuyo.\p"
	.string "El vínculo que compartes con tus\n"
	.string "POKéMON es maravilloso.\p"
	.string "¡{PLAYER}!\n"
	.string "¡Ven conmigo!$"

