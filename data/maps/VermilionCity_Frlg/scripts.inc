VermilionCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
	.2byte 0

VermilionCity_EventScript_ExitSSAnne::
	lockall
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
	waitmovement 0
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

VermilionCity_Movement_ExitSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
	end

VermilionCity_EventScript_HideOaksAide::
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_CheckHasMysticTicket::
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckHasAuroraTicket::
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckSeagallopPresent::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	release
	end

VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
	call VermilionCity_EventScript_CheckHasMysticTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	goto EventScript_SeviiDestinationsPage1
	end

VermilionCity_EventScript_HasMysticTicket::
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowMysticTicket::
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
	return

VermilionCity_EventScript_HasAuroraTicket::
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowAuroraTicket::
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
	return

VermilionCity_EventScript_HasMysticAndAuroraTickets::
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_SailToBirthIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

EventScript_SailToNavelRock::
	msgbox VermilionCity_Text_Seagallop10Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
	goto EventScript_SetSail
	end

EventScript_SailToBirthIsland::
	msgbox VermilionCity_Text_Seagallop12Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestTriPass::
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToOneIsland2
	case 1, EventScript_SailToTwoIsland2
	case 2, EventScript_SailToThreeIsland2
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

@ Unreachable
Vermilion_EventScript_Unused::
	release
	end

VermilionCity_EventScript_CheckTicketLeft::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_CheckTicketRight::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
	releaseall
	end

VermilionCity_EventScript_CheckTicket::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
	msgbox VermilionCity_Text_DoYouHaveATicket
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
	msgbox VermilionCity_Text_FlashedSSTicket
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
	releaseall
	end

VermilionCity_EventScript_DontHaveSSTicket::
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_CheckSeagallopPresentTrigger::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_EventScript_OaksAide::
	lock
	faceplayer
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
	release
	end

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat
	release
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_LTSURGE, 0
	msgbox VermilionCity_Text_GymSign
	releaseall
	end

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_Text_GrimerMultipliesInSludge::
	.string "Aquí cuidamos mucho la contaminación.\p"
	.string "Dicen que GRIMER se multiplica\n"
	.string "en el lodo tóxico.$"

VermilionCity_Text_DidYouSeeSSAnneInHarbor::
	.string "¿Has visto el S.S. LIN atracado\n"
	.string "en el puerto?$"

VermilionCity_Text_SSAnneHasDepartedForYear::
	.string "Así que el S.S. LIN ha zarpado.\p"
	.string "Volverá a CIUDAD CARMÍN por estas\n"
	.string "fechas el año que viene.$"

VermilionCity_Text_BuildingOnThisLand::
	.string "Estoy levantando un edificio en este\n"
	.string "solar. Todo es mío.\p"
	.string "Mi POKéMON está apisonando el\n"
	.string "terreno para los cimientos.$"

VermilionCity_Text_Machop::
	.string "MACHOP: ¡Guoh! ¡Gogogoh!$"

VermilionCity_Text_MachopStompingLandFlat::
	.string "Un MACHOP está aplanando el terreno.$"

VermilionCity_Text_SSAnneVisitsOnceAYear::
	.string "El S.S. LIN es un famoso crucero\n"
	.string "de lujo.\p"
	.string "Visita CIUDAD CARMÍN una vez al año.$"

VermilionCity_Text_CitySign::
	.string "CIUDAD CARMÍN\p"
	.string "El puerto de los ocasos exquisitos$"

VermilionCity_Text_SnorlaxBlockingRoute12::
	.string "¡AVISO!\p"
	.string "La RUTA 12 puede estar bloqueada\n"
	.string "por un POKéMON dormido.\p"
	.string "Rodea por el TÚNEL ROCA hasta\n"
	.string "PUEBLO LAVANDA.\p"
	.string "POLICÍA de CIUDAD CARMÍN$"

VermilionCity_Text_PokemonFanClubSign::
	.string "CLUB de FANS de POKéMON ¡Todos los\n"
	.string "fans de POKéMON son bienvenidos!$"

VermilionCity_Text_GymSign::
	.string "GIMNASIO POKéMON de CIUDAD CARMÍN\n"
	.string "LÍDER: LT. SURGE\l"
	.string "¡El Americano Relámpago!$"

VermilionCity_Text_VermilionHarbor::
	.string "PUERTO de CIUDAD CARMÍN$"

VermilionCity_Text_WelcomeToTheSSAnne::
	.string "¡Bienvenido al S.S. LIN!$"

VermilionCity_Text_DoYouHaveATicket::
	.string "¡Bienvenido al S.S. LIN!\p"
	.string "Disculpa, ¿tienes un billete?$"

VermilionCity_Text_FlashedSSTicket::
	.string "{FONT_NORMAL}¡{PLAYER} mostró el BILLETE S.S.!\p"
	.string "{FONT_MALE}¡Estupendo!\n"
	.string "¡Bienvenido al S.S. LIN!$"

VermilionCity_Text_DontHaveNeededSSTicket::
	.string "{FONT_NORMAL}{PLAYER} no tiene el BILLETE S.S.\n"
	.string "necesario.\p"
	.string "{FONT_MALE}¡Lo siento!\p"
	.string "Necesitas un billete para subir a bordo.$"

VermilionCity_Text_TheShipSetSail::
	.string "El barco ha zarpado.$"

VermilionCity_Text_BoardSeagallopTriPass::
	.string "Ah, tienes un TRI-PASE.\p"
	.string "¿Quieres subir a un ferry\n"
	.string "SEAGALLOP?$"

VermilionCity_Text_Seagallop7Departing::
	.string "Muy bien, todo en orden.\p"
	.string "El SEAGALLOP RÁPIDO 7 zarpará\n"
	.string "de inmediato.$"

VermilionCity_Text_BoardSeagallopRainbowPass::
	.string "Ah, tienes un PASE ARCOÍRIS.\p"
	.string "¿Quieres subir a un ferry\n"
	.string "SEAGALLOP?$"

VermilionCity_Text_OhMysticTicketTakeYouToNavelRock::
	.string "¡Oh! ¡Eso es un TICKET MÍSTICO!\n"
	.string "Qué raro.\p"
	.string "Estaremos encantados de llevarte a\n"
	.string "ROCA OMBLIGO cuando quieras.$"

VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland::
	.string "¡Oh! ¡Eso es un TICKET AURORA!\n"
	.string "Qué raro.\p"
	.string "Estaremos encantados de llevarte a\n"
	.string "ISLA NACIMIENTO cuando quieras.$"

VermilionCity_Text_BoardSeagallopFerry::
	.string "¿Quieres subir a un ferry\n"
	.string "SEAGALLOP?$"

VermilionCity_Text_Seagallop10Departing::
	.string "Muy bien, todo en orden para que\n"
	.string "subas a un ferry especial.\p"
	.string "El SEAGALLOP RÁPIDO 10 zarpará\n"
	.string "de inmediato.$"

VermilionCity_Text_Seagallop12Departing::
	.string "Muy bien, todo en orden para que\n"
	.string "subas a un ferry especial.\p"
	.string "El SEAGALLOP RÁPIDO 12 zarpará\n"
	.string "de inmediato.$"

VermilionCity_Text_Route2AideHasPackageForYou::
	.string "¡Oh, hola, {PLAYER}!\n"
	.string "¿Cómo estás?\p"
	.string "Soy uno de los AYUDANTES del\n"
	.string "PROF. OAK.\p"
	.string "¿Conociste al otro AYUDANTE?\p"
	.string "Tenía un paquete del PROF. OAK\n"
	.string "para ti, {PLAYER}.\p"
	.string "Dijo que te buscaría por la\n"
	.string "RUTA 2, {PLAYER}.\p"
	.string "Si andas por la zona de la RUTA 2,\n"
	.string "búscalo, por favor.$"

