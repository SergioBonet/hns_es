PalletTown_PlayersHouse_1F_Frlg_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	release
	end

@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
	.string "MAMÁ: En fin...\n"
	.string "Todos los niños se van de casa\l"
	.string "algún día. ¡Así es la vida!\p"
	.string "Ah, nuestro vecino, el PROF. OAK,\n"
	.string "quería verte.$"

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
	.string "MAMÁ: En fin...\n"
	.string "Todos los niños se van de casa\l"
	.string "algún día. ¡Así es la vida!\p"
	.string "Ah, nuestro vecino, el PROF. OAK,\n"
	.string "quería verte.$"

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
	.string "MAMÁ: ¡{PLAYER}!\n"
	.string "Deberías tomarte un descanso.$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
	.string "MAMÁ: ¡Muy bien! ¡Tú y tus\n"
	.string "POKéMON estáis en plena forma!\l"
	.string "¡Cuídate!$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
	.string "Están poniendo una peli...\n"
	.string "Salen cuatro niños caminando\l"
	.string "por las vías del tren...\p"
	.string "Bueno, voy a ponerme en marcha.$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
	.string "Están poniendo una peli...\n"
	.string "Sale una chica con coletas andando\l"
	.string "por una calle empedrada...\p"
	.string "Bueno, voy a ponerme en marcha.$"

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
	.string "Vaya, lado equivocado…$"
