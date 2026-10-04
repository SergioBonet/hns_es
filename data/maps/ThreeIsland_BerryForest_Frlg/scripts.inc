ThreeIsland_BerryForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
	.byte 0

ThreeIsland_BerryForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 12, 6
	end

ThreeIsland_BerryForest_EventScript_Lostelle::
	lock
	faceplayer
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
	playse SE_PIN
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
	waitse
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HYPNO, 30
	dowildbattle
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
	giveitem ITEM_IAPAPA_BERRY
	call_if_eq VAR_RESULT, FALSE, ThreeIsland_BerryForest_EventScript_NoRoomForBerry
	special GetPlayerBigGuyGirlString
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
	closemessage
	setflag FLAG_RESCUED_LOSTELLE
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 6, 6
	waitstate
	release
	end

ThreeIsland_BerryForest_EventScript_NoRoomForBerry::
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
	return

ThreeIsland_BerryForest_Movement_LostelleLookAround::
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	step_end

ThreeIsland_BerryForest_EventScript_WelcomeSign::
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_BewareSign::
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_Text_HelpScaryPokemon::
	.string "PEDRITA: Buuuua... ¡BUAAAA!...\n"
	.string "¡Ayúdame, ayúdame!\p"
	.string "POKéMON ho-horrible...\n"
	.string "Mmme he sustado ucho...\p"
	.string "Buaaaaa... Sustado a PEDRITA...\p"
	.string "Teno miedo...\n"
	.string "Quiedo id a casa...$"

ThreeIsland_BerryForest_Text_HereItComesAgain::
	.string "¡Oh! ¡Ya viene otra vez!\n"
	.string "¡No! ¡Vete! ¡Me da miedo!\p"
	.string "¡Buaaaaaah!\n"
	.string "¡Quiero a mi papá!$"

ThreeIsland_BerryForest_Text_ThankYouHaveThis::
	.string "¡Uuuh! ¡Qué miedo!\n"
	.string "¡Gracias!\p"
	.string "PEDRITA vino a recoger\n"
	.string "unas BAYAS.\p"
	.string "¡Puedes quedarte con esto!$"

ThreeIsland_BerryForest_Text_LetsGoHome::
	.string "¿Quién ede?\p"
	.string "PEDRITA sustada, lleva a casa\n"
	.string "con papi a PEDRITA.\p"
	.string "¡A casa con papi!\n"
	.string "¡Con papi!$"

ThreeIsland_BerryForest_Text_BerryPouchIsFull::
	.string "El SACO de las BAYAS está lleno.$"

ThreeIsland_BerryForest_Text_WelcomeToBerryForest::
	.string "Éste es el BOSQUE BAYA.\p"
	.string "¡Hay que compartir BAYAS\n"
	.string "con la gente y los POKéMON!$"

ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons::
	.string "Atención:\n"
	.string "Presencia de POKéMON salvajes\l"
	.string "devoradores de BAYAS.$"

