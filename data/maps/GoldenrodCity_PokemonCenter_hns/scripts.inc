GoldenrodCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodCity_PokemonCenter_hns_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoldenrodCity_PokemonCenter_hns_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY_HNS
	end

GoldenrodCity_PokemonCenter_hns_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	.2byte 0

GoldenrodCity_PokemonCenter_hns_OnWarp_Nop::
	end

GoldenrodCity_PokemonCenter_hns_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	.2byte 0

GoldenrodCity_PokemonCenter_hns_ExitLinkRoom::
	lockall
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	erasebox 0, 0, 29, 19
	releaseall
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc::
	lock
	faceplayer
	copyvar VAR_0x8007, VAR_LAST_TALKED
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_LINK_SERVICES_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_ChooseTrade
	case 1, GoldenrodCity_PokemonCenter_EventScript_ChooseBattle
	case 2, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	end

GoldenrodCity_PokemonCenter_EventScript_ChooseTrade::
	helpwindow HELP_TRADE_WINDOW
	delay 30
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	message gText_PleaseWaitForLink
	waitmessage
	special TryTradeLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, GoldenrodCity_PokemonCenter_EventScript_EnterTradeRoom
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

GoldenrodCity_PokemonCenter_EventScript_EnterTradeRoom::
	setvar VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER
	closemessage
	release
	setdynamicwarp MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS, 255, 14, 6
	setwarp MAP_TRADE_CENTER_HNS, 5, 8
	special DoCableClubWarp
	waitstate
	end

GoldenrodCity_PokemonCenter_EventScript_ChooseBattle::
	helpwindow HELP_TRADE_WINDOW
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_BATTLE_MODE_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_SingleBattle
	case 1, GoldenrodCity_PokemonCenter_EventScript_DoubleBattle
	case 2, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	end

GoldenrodCity_PokemonCenter_EventScript_SingleBattle::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum
	end

GoldenrodCity_PokemonCenter_EventScript_DoubleBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, GoldenrodCity_PokemonCenter_EventScript_NeedTwoMons
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum
	end

GoldenrodCity_PokemonCenter_EventScript_NeedTwoMons::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_ChooseBattle
	end

GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	message gText_PleaseWaitForLink
	waitmessage
	special TryBattleLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, GoldenrodCity_PokemonCenter_EventScript_EnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

GoldenrodCity_PokemonCenter_EventScript_EnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	closemessage
	release
	setdynamicwarp MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS, 255, 14, 6
	setwarp MAP_BATTLE_COLOSSEUM_2P_HNS, 6, 8
	special DoCableClubWarp
	waitstate
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline::
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End::
	release
	end

GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro:
	.string "LINK CORNER\p"
	.string "SELECT LINK TYPE.$"

GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode:
	.string "SELECT BATTLE TYPE.$"

GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye:
	.string "GOODBYE.$"

GoldenrodCity_PokemonCenter_EventScript_LinkExplainerNpc::
	msgbox GoldenrodCity_PokemonCenter_Text_LinkExplainer, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_Text_LinkExplainer:
	.string "You can use this machine to trade\n"
	.string "or battle with other local players.\p"
	.string "Isn't technology wonderful?$"

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
    .string "I just love living in the big city!\n"
    .string "I moved here when I was a young\l"
    .string "trainer, like you!$"

GoldenrodCity_PokemonCenter_GameboyKidText1:
    .string "This is a special POKéMON CENTER.\n"
    .string "The roof is made of gold!$"

GoldenrodCity_PokemonCenter_GameboyKidText2:
    .string "I told my brother that the roof is\n"
    .string "made of real gold. He'll believe\l"
	.string "anything!$"

GoldenrodCity_PokemonCenter_LassText:
	.string "Un POKéMON de nivel superior no\n"
	.string "siempre gana.\p"
	.string "Aun así, su tipo puede tener alguna\n"
	.string "desventaja.\p"
	.string "No creo que haya un único POKéMON\p"
	.string "que sea el más fuerte.$"

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
	.string "{PLAYER}, ¿no?\p"
	.string "¡Felicidades!\p"
	.string "¡Estamos de promoción, hemos recibido\n"
	.string "una GS BALL para ti!\p"
	.string "¡Por favor, acéptala!$"

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
	.string "¡Vuelve cuando quieras!$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
	.string "¡Llevas mucho peso en la mochila!\p"
	.string "¡Oye! ¿No tendrás algo llamado CARTA\n"
	.string "EÓN?\p"
	.string "Mi hija está buscando una.\p"
	.string "Puedes darme una, ¿verdad?$"

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
	.string "¿Entregas una CARTA EÓN?$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
	.string "¡Oh, genial! ¡Gracias, cariño!\p"
	.string "¡Toma esto en agradecimiento!$"

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
	.string "¡A mi hija le encantará!$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
	.string "¿Oh? ¿No tienes? Qué lástima…$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
	.string "Oh… Bueno, en otra ocasión será.$"

GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
	.string "{PLAYER} entrega la CARTA EÓN.$"
