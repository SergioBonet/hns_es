MtEmber_Exterior_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtEmber_Exterior_OnLoad
	.byte 0

MtEmber_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_EMBER_EXTERIOR
	call_if_eq VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2, MtEmber_Exterior_EventScript_RocketsFaceDown
	end

MtEmber_Exterior_EventScript_RocketsFaceDown::
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT1, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT2, MOVEMENT_TYPE_FACE_DOWN
	return

MtEmber_Exterior_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_OpenCave
	end

MtEmber_Exterior_EventScript_OpenCave::
	setmetatile 42, 39, METATILE_MtEmber_CaveEntrance, 0
	return

MtEmber_Exterior_EventScript_Grunt1::
	lock
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_Grunt1Defeated
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt1
	msgbox MtEmber_Exterior_Text_WellTryDiggingHere
	release
	end

MtEmber_Exterior_EventScript_Grunt1Defeated::
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt1::
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt1Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_Text_Grunt1Defeat
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_DefeatedBothGrunts::
	msgbox MtEmber_Exterior_Text_WellRegroupDontStepInsideThere
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_EMBER_GRUNT1
	removeobject LOCALID_MT_EMBER_GRUNT2
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtEmber_Exterior_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedGrunt2
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt2
	msgbox MtEmber_Exterior_Text_YoureInTheWayGetLost
	closemessage
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MtEmber_Exterior_EventScript_DefeatedGrunt2::
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt2::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt2Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_Text_Grunt2Defeat
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_RocketPasswordScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtEmber_Exterior_Text_PunchedThroughAtLast
	message MtEmber_Exterior_Text_WhatsPasswordAgain
	waitmessage
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_QuestionMark
	waitmovement 0
	waitbuttonpress
	msgbox MtEmber_Exterior_Text_FirstPasswordGoldeen
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	call MtEmber_Exterior_EventScript_RocketsFaceDown
	msgbox MtEmber_Exterior_Text_SnoopsBeenListeningIn
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
	releaseall
	end

MtEmber_Exterior_EventScript_Logan::
	trainerbattle_single TRAINER_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganIntro, MtEmber_Exterior_Text_LoganDefeat
	msgbox MtEmber_Exterior_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Beth::
	trainerbattle_single TRAINER_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethIntro, MtEmber_Exterior_Text_BethDefeat
	msgbox MtEmber_Exterior_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Jocelyn::
	trainerbattle_single TRAINER_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynIntro, MtEmber_Exterior_Text_JocelynDefeat
	msgbox MtEmber_Exterior_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

Text_ExplosionTeach::
	.string "¿Te imaginas?\n"
	.string "¿Y si este volcán entrara en erupción?\p"
	.string "La explosión sería nuestro fin.\n"
	.string "¡Qué terror!\p"
	.string "Ya que estamos asustados,\n"
	.string "¿quieres que te enseñe EXPLOSIÓN?$"

Text_ExplosionDeclined::
	.string "Sí, tienes razón.\n"
	.string "Da demasiado miedo.$"

Text_ExplosionWhichMon::
	.string "¡Sí, señor!\p"
	.string "¿A qué POKéMON quieres que\n"
	.string "le enseñe EXPLOSIÓN?$"

Text_ExplosionTaught::
	.string "Imagínate lo que tiene que ser\n"
	.string "usar EXPLOSIÓN en este volcán...\p"
	.string "¡Lo pienso y no sé lo que me\n"
	.string "entra!$"

MtEmber_Exterior_Text_WellTryDiggingHere::
	.string "Aquí, aquí.\n"
	.string "Vamos a intentar cavar aquí.\p"
	.string "Yo creo que el tesoro del que\n"
	.string "hablaban los ADMINISTRADORES\l"
	.string "está aquí.$"

MtEmber_Exterior_Text_YoureInTheWayGetLost::
	.string "Pero...\n"
	.string "¿Te quieres quitar de aquí?$"

MtEmber_Exterior_Text_PunchedThroughAtLast::
	.string "¡Por fin lo hemos conseguido!\n"
	.string "¡A por el tesoro!$"

MtEmber_Exterior_Text_WhatsPasswordAgain::
	.string "Cosa que encontremos, cosa que\n"
	.string "llevamos al ALMACÉN, ¿eh?\p"
	.string "Eh... ¿y cuáles eran las\n"
	.string "contraseñas?\l"
	.string "Me refiero a las del ALMACÉN...$"

MtEmber_Exterior_Text_FirstPasswordGoldeen::
	.string "¿No te acuerdas de la contraseña?\n"
	.string "Bueno, en realidad son dos.\p"
	.string "La primera es “ARON ama\n"
	.string "a NORA”.\p"
	.string "Y la segunda...$"

MtEmber_Exterior_Text_SnoopsBeenListeningIn::
	.string "¡Eh, que por aquí se están\n"
	.string "quedando con la copla! ¡Cotilla!$"

MtEmber_Exterior_Text_Grunt1Intro::
	.string "Has estado espiándonos, ¿eh?$"

MtEmber_Exterior_Text_Grunt1Defeat::
	.string "¿Qué ha pasado?$"

MtEmber_Exterior_Text_Grunt1PostBattle::
	.string "¿Por qué me has ganado?$"

MtEmber_Exterior_Text_Grunt2Intro::
	.string "¿Te crees que vas a pillar cacho\n"
	.string "de nuestro tesoro? ¡Ni lo sueñes!$"

MtEmber_Exterior_Text_Grunt2Defeat::
	.string "¡Espera!\n"
	.string "¿Pero cómo?$"

MtEmber_Exterior_Text_Grunt2PostBattle::
	.string "Hazme un favorcito, olvídate de lo\n"
	.string "que has oído, anda.$"

MtEmber_Exterior_Text_WellRegroupDontStepInsideThere::
	.string "¡Menudo revés!...\n"
	.string "¡Vámonos con el resto!\p"
	.string "¡Tú, no te atrevas a entrar!\p"
	.string "¡Te lo digo por tu bien!\n"
	.string "¡Ni te lo plantees!$"

MtEmber_Exterior_Text_LoganIntro::
	.string "Se dice que un volcán está activo,\n"
	.string "cuando entra en erupción o está\l"
	.string "a punto.$"

MtEmber_Exterior_Text_LoganDefeat::
	.string "¡Uf… Qué calor!\n"
	.string "¡Me salta el sudor por todas partes!$"

MtEmber_Exterior_Text_LoganPostBattle::
	.string "Dicen que hay unos 1.500 volcanes\n"
	.string "activos en todo el mundo.\p"
	.string "Cada vez que lo pienso, ¡me entra\n"
	.string "una cosa!$"

MtEmber_Exterior_Text_BethIntro::
	.string "¿Sabes cómo se forman las cuevas\n"
	.string "en el interior de los volcanes?$"

MtEmber_Exterior_Text_BethDefeat::
	.string "¡Achís!\n"
	.string "¡Eres sorprendentemente bueno!$"

MtEmber_Exterior_Text_BethPostBattle::
	.string "Cuando la lava de la superficie se\n"
	.string "solidifica, aún puede quedar magma\l"
	.string "por salir.\p"
	.string "Y son los conductos que abre\n"
	.string "en su camino al exterior, los que\l"
	.string "pasan a ser las cuevas.$"

MtEmber_Exterior_Text_JocelynIntro::
	.string "He estado entrenando para curar mi\n"
	.string "corazón roto…\p"
	.string "¡Al menos me ha fortalecido\n"
	.string "físicamente! ¡Hi-yah!$"

MtEmber_Exterior_Text_JocelynDefeat::
	.string "Creo que he exagerado…$"

MtEmber_Exterior_Text_JocelynPostBattle::
	.string "Tu forma de combatir me recuerda\n"
	.string "al tipo que me dejó…$"

