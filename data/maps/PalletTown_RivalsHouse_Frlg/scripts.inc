.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
	setvar RECEIVED_TOWN_MAP, TRUE
	return

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon::
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

PalletTown_RivalsHouse_EventScript_GiveTownMap::
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
	closemessage
	checkitemspace ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap::
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
	.string "DALIA: ¡Hola, {PLAYER}!\p"
	.string "¡{RIVAL} está en el laboratorio\n"
	.string "del abuelo!$"

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
	.string "DALIA: {PLAYER}, he oído que has\n"
	.string "luchado contra {RIVAL}.\p"
	.string "¡Me hubiera encantado estar ahí!$"

PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp::
	.string "¿Te encargó algo el abuelo?\p"
	.string "¡Toma esto!\n"
	.string "¡Te ayudará!$"

PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy::
	.string "¡{PLAYER} recibió el MAPA\n"
	.string "de manos de DALIA!$"

PalletTown_RivalsHouse_Text_DontHaveSpaceForThis::
	.string "Llevas demasiadas cosas\n"
	.string "en la MOCHILA.$"

PalletTown_RivalsHouse_Text_ExplainTownMap::
	.string "Usa el MAPA para saber dónde\n"
	.string "te encuentras.$"

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
	.string "DALIA: Los POKéMON son seres que\n"
	.string "sienten, igual que las personas.\p"
	.string "Cuando se cansen, deberás dejar\n"
	.string "que se recuperen.$"

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
	.string "¡Es un gran mapa de KANTO!\n"
	.string "¡Qué útil!$"

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
	.string "¡Está totalmente llena de libros\n"
	.string "sobre los POKéMON!$"

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
	.string "DALIA: ¡Hola, {PLAYER}!\n"
	.string "¡Llegas a tiempo!\p"
	.string "Iba a tomarme un té.\n"
	.string "¿Quieres uno?\p"
	.string "Tus POKéMON están un poco sucios.\n"
	.string "¿Quieres que limpie a alguno?$"

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
	.string "¿No quieres que limpie a ningún\n"
	.string "POKéMON?\l"
	.string "Bueno, vamos a tomarnos el té.$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
	.string "¿A qué POKéMON limpio?$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
	.string "DALIA: Vale, verás lo mono\n"
	.string "que se queda.$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
#ifdef BUGFIX @ The localizers missed what should be a textcolor change in the localizations.
	.string "{COLOR DARK_GRAY}{STR_VAR_1} parece soñadoramente\ncontento…\p"
	.string "{COLOR RED}DALIA: ¡Ya está! ¡Terminado!\n"
#else @ In the JP games, gender-based text used a different font instead of different colors.
	.string "{FONT_NORMAL}{STR_VAR_1} parece soñadoramente\ncontento…\p"
	.string "{FONT_FEMALE}DALIA: ¡Ya está! ¡Terminado!\n"
#endif
	.string "¿Ves? ¿A que queda bien?\p"
	.string "Ji, ji…\n"
	.string "Es un POKéMON tan mono.$"

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
	.string "Lo siento, yo no sé limpiar HUEVOS.$"

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
	.string "DALIA: Si crías a tus POKéMON\n"
	.string "con cariño, te querrán mucho.\p"
	.string "{PLAYER}, ¿me dejas ver a tu primer\n"
	.string "POKéMON?$"

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
	.string "Desde luego, no podría quererte\n"
	.string "más.\p"
	.string "¡No hay palabras para expresar\n"
	.string "lo mucho que se ve que te quiere!$"

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
	.string "Se le ve muy feliz.\p"
	.string "Ojalá {RIVAL} pudiera verlo y\n"
	.string "aprender cómo se hacen las cosas.$"

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
	.string "Se ve que se lleva muy bien\n"
	.string "contigo. ¡Que no decaiga!$"

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
	.string "Se ve que te está tomando\n"
	.string "cariño. Debes darle confianza.$"

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
	.string "Aún no te conoce bien.\p"
	.string "Todos los POKéMON son bastante\n"
	.string "recelosos al principio.$"

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
	.string "{PLAYER}, no me gusta cómo te mira.\p"
	.string "¿Podrías ser un poco más amable\n"
	.string "con él?$"

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
	.string "Eh... siento decírtelo, pero...\p"
	.string "¿Qué has hecho para que te tenga\n"
	.string "tanta tirria?$"

PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy::
	.string "El cariñoso y dulce\n"
	.string "CLEFAIRY.$"

