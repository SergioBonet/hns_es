.set SPOKE_TO_WOMAN_LAST,   FLAG_TEMP_2
.set SPOKE_TO_FAT_MAN_LAST, FLAG_TEMP_3

VermilionCity_PokemonFanClub_Frlg_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BIKE_VOUCHER, VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory
	msgbox VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_PokemonFanClub_EventScript_ChairmanStory
	msgbox VermilionCity_PokemonFanClub_Text_ComeBackToHearStory
	release
	end

VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory::
	msgbox VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain
	release
	end

VermilionCity_PokemonFanClub_EventScript_ChairmanStory::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmansStory
	checkitemspace ITEM_BIKE_VOUCHER
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher
	setflag FLAG_GOT_BIKE_VOUCHER
	giveitem_msg VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman, ITEM_BIKE_VOUCHER, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher
	release
	end

VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher::
	msgbox VermilionCity_PokemonFanClub_Text_MakeRoomForThis
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear::
	famechecker FAMECHECKER_DAISY, 1
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons
	release
	end

VermilionCity_PokemonFanClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_set SPOKE_TO_FAT_MAN_LAST, VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan
	msgbox VermilionCity_PokemonFanClub_Text_AdoreMySeel
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan::
	msgbox VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set SPOKE_TO_WOMAN_LAST, VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman
	msgbox VermilionCity_PokemonFanClub_Text_AdmirePikachusTail
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman::
	msgbox VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Pikachu
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Seel
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign1::
	msgbox VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign2::
	msgbox VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_AdmirePikachusTail::
	.string "¿No te gusta la adorable cola\n"
	.string "de mi PIKACHU?$"

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
	.string "¡Mi PIKACHU es el doble\n"
	.string "de gracioso que ése!$"

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
	.string "¡Me encanta mi SEEL!\p"
	.string "¡Chilla cuando lo abrazo!$"

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
	.string "¡Por favor!\p"
	.string "¡Mi SEEL es mucho más atractivo!\n"
	.string "¡El doble de atractivo!$"

VermilionCity_PokemonFanClub_Text_Pikachu::
	.string "PIKACHU: ¡Chu! ¡Pika, pika!$"

VermilionCity_PokemonFanClub_Text_Seel::
	.string "SEEL: ¡Eeel!$"

VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
	.string "¡Yo presido el Club de Fans de los\n"
	.string "POKéMON!\p"
	.string "¡Tengo más de 100 POKéMON!\p"
	.string "¡Soy muy exigente en todo lo que\n"
	.string "se refiere a los POKéMON!\p"
	.string "Bueno...\p"
	.string "¿Has venido para saber más cosas\n"
	.string "de mis POKéMON?$"

VermilionCity_PokemonFanClub_Text_ChairmansStory::
	.string "¡Muy bien!\n"
	.string "¡Pues escucha!\p"
	.string "Mi preferido es RAPIDASH...\p"
	.string "Es... gracioso... cariñoso... veloz\n"
	.string "e increíble... ¿No crees?...\l"
	.string "Es sorprendente... simpático...\l"
	.string "¡Yo lo adoro!\p"
	.string "Si lo abrazas... cuando duerme...\n"
	.string "es tan cálido... y mimoso... es\l"
	.string "espectacular... encantador...\l"
	.string "¡Hala, mira qué hora es!\l"
	.string "¡Hablo demasiado!\p"
	.string "¡Gracias por escucharme!\n"
	.string "¡Toma esto!$"

VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
	.string "¡{PLAYER} recibió el BONO BICI\n"
	.string "de manos del PRESIDENTE!$"

VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
	.string "¡Cámbialo por una BICICLETA\n"
	.string "en la TIENDA de BICIS de CIUDAD\l"
	.string "CELESTE!\p"
	.string "¡Es gratis!\p"
	.string "¡No te apures por mí, mi FEAROW\n"
	.string "me lleva VOLANDO a donde sea!\p"
	.string "¡No necesito BICICLETA!\p"
	.string "¡Espero que te guste pedalear!$"

VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
	.string "¡Oh! ¡Pues vuelve cuando quieras\n"
	.string "oír mi historia!$"

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
	.string "¡Hola, {PLAYER}!\p"
	.string "¿Has vuelto para saber más cosas\n"
	.string "de mi POKéMON?\p"
	.string "¿No?\n"
	.string "¡Qué pena!$"

VermilionCity_PokemonFanClub_Text_MakeRoomForThis::
	.string "¡No tienes sitio para esto!$"

VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
	.string "El PRESIDENTE habla mucho\n"
	.string "de los POKéMON.$"

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
	.string "¡Escuchemos con atención a otros\n"
	.string "ENTRENADORES!$"

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
	.string "¡Si alguien presume, presume tú\n"
	.string "de vuelta!$"

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
	.string "A nuestro PRESIDENTE le encantan\n"
	.string "sus POKéMON.\p"
	.string "Pero los POKéMON a quien más\n"
	.string "quieren es a DALIA, creo.$"
