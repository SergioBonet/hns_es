MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hi, I'm the TRADER.\n"
	.string "Want to trade decorations with me?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "But we've traded decorations already,\n"
	.string "you and I.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "You don't want anything?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Uh… Wait a second. You don't have a\n"
	.string "single piece of decoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Okay, pick the decoration that you'll\n"
	.string "trade to me.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "You won't trade with me?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "You've got all the {STR_VAR_2}S that can\n"
	.string "be stored. You've no room for this.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "That piece of decoration is in use.\n"
	.string "You can't trade it.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Then we'll trade!\n"
	.string "I'll send my decoration to your PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oops! Sorry! That's a really rare\n"
	.string "piece of decoration.\l"
	.string "I can't trade that one away!\p"
	.string "Can I interest you in something else?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "I'm the STORYTELLER.\n"
	.string "I'll tell you tales of legendary\l"
	.string "TRAINERS.\p"
	.string "Will you hear my tale?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "I know of these legends.\n"
	.string "Which tale will you have me tell?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "But, I know of no legendary TRAINERS.\n"
	.string "Hence, I know no tales.\p"
	.string "Where does one find a TRAINER worthy\n"
	.string "of a legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "What's that?!\n"
	.string "You… You…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} time(s)?!\p"
	.string "That is indeed magnificent!\n"
	.string "It's the birth of a new legend!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "It gets me thinking, could there be\n"
	.string "other TRAINERS with more impressive\l"
	.string "legends awaiting discovery?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Are you a TRAINER?\p"
	.string "Then tell me, have you any tales that\n"
	.string "are even remotely legendary?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "I'm not satisfied…\p"
	.string "I wish you would bring me news worthy\n"
	.string "of being called a legend.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "I wish more people would be interested\n"
	.string "in hearing my epic tales of legendary\l"
	.string "TRAINERS.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "“El ENTRENADOR guardador”$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Guardaste la partida…$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR guardó la partida\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡No se encontrará un ENTRENADOR más\n"
	.string "precavido que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "“El ENTRENADOR molón”$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Creaste tendencias…$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR lanzó modas\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} marca tendencia en toda\n"
	.string "la región de HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "“El ENTRENADOR plantabayas”$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Plantaste BAYAS…$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR plantó BAYAS\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} es un amante legendario\n"
	.string "de las BAYAS!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "“El ENTRENADOR sobre ruedas”$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Cambiaste de BICI…$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR cambió de BICI\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de amar las BICIS\n"
	.string "con profunda pasión!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "“El ENTRENADOR estrella”$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Concediste entrevistas…$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR fue entrevistado\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de ser un ENTRENADOR\n"
	.string "que atrae mucha atención!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "“El ENTRENADOR peleón”$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Entablaste combate…$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR combatió {STR_VAR_1}\n"
	.string "veces.\p"
	.string "¡{STR_VAR_3} debe de ser un\n"
	.string "ENTRENADOR que nunca rechaza un\l"
	.string "combate!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "“El ENTRENADOR cazador”$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Atrapaste POKéMON…$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR capturó\n"
	.string "{STR_VAR_1} POKéMON.\p"
	.string "¡{STR_VAR_3} es un legendario cazador\n"
	.string "de POKéMON salvajes!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "“El ENTRENADOR pescador”$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Pescaste POKéMON con CAÑA…$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR capturó\n"
	.string "{STR_VAR_1} POKéMON pescando.\p"
	.string "¡{STR_VAR_3} es un legendario experto\n"
	.string "en pesca!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "“El ENTRENADOR empollón”$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Lograste incubar HUEVOS…$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR hizo nacer\n"
	.string "{STR_VAR_1} POKéMON de HUEVOS.\p"
	.string "¡{STR_VAR_3} es un legendario incubador\n"
	.string "de HUEVOS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "“El ENTRENADOR evolutivo”$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Hiciste evolucionar POKéMON…$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR hizo evolucionar\n"
	.string "a {STR_VAR_1} POKéMON.\p"
	.string "¡{STR_VAR_3} es el máximo evolucionador\n"
	.string "de POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "“El ENTRENADOR curandero”$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Usaste los CENTROS POKéMON…$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR curó a sus POKéMON\n"
	.string "{STR_VAR_1} veces en CENTROS POKéMON.\p"
	.string "¡No hay mayor amante de los\n"
	.string "CENTROS POKéMON que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "“El ENTRENADOR casero”$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Curaste POKéMON en casa…$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR curó a sus POKéMON\n"
	.string "{STR_VAR_1} veces en casa.\p"
	.string "¡No hay nadie más casero\n"
	.string "que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "“El ENTRENADOR aventurero”$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Entraste en la ZONA SAFARI…$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR entró en la ZONA\n"
	.string "SAFARI {STR_VAR_1} veces.\p"
	.string "¡Su lado salvaje debe de salir a la luz\n"
	.string "en la ZONA SAFARI, {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "“El ENTRENADOR leñador”$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Usaste CORTE…$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR usó CORTE\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡A {STR_VAR_3} le debe de encantar\n"
	.string "CORTAR!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "“El ENTRENADOR picapedrero”$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Usaste GOLPE ROCA…$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR usó GOLPE ROCA\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} no deja ni una piedra\n"
	.string "sin romper!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "“El ENTRENADOR nómada”$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Te mudaste de BASE SECRETA…$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR cambió de BASE\n"
	.string "SECRETA {STR_VAR_1} veces.\p"
	.string "¡A {STR_VAR_3} le encanta mudarse a\n"
	.string "menudo!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "“El ENTRENADOR salpicón”$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Usaste SALPICADURA…$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR usó SALPICADURA\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡A {STR_VAR_3} le debe de encantar\n"
	.string "chapotear!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "“El ENTRENADOR tenaz”$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Usaste COMBATE…$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR tuvo que recurrir a\n"
	.string "COMBATE {STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} es un ENTRENADOR tenaz\n"
	.string "que nunca cede ante la adversidad!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "“El rey de las TRAGAPERRAS”$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Ganaste el premio gordo…$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR ganó el premio gordo\n"
	.string "en las TRAGAPERRAS {STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} tiene suerte\n"
	.string "en las TRAGAPERRAS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "“El rey de las RULETAS”$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Ganaste en la RULETA…$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR ganó en la RULETA\n"
	.string "{STR_VAR_1} veces seguidas.\p"
	.string "¡{STR_VAR_3} tuvo suerte cuando la bola\n"
	.string "rebotó en la RULETA!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "“El paladín de la TORRE BATALLA”$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Luchaste en la TORRE BATALLA…$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR afrontó el desafío de\n"
	.string "la TORRE BATALLA {STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} aspira a la excelencia\n"
	.string "en la TORRE BATALLA!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "“El ENTRENADOR licuador”$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Hiciste {POKEBLOCK}S…$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR preparó {POKEBLOCK}S\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡Nadie maneja mejor una LICUABAYAS\n"
	.string "que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "“El ENTRENADOR concursante”$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Participaste en los CONCURSOS…$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR participó en\n"
	.string "CONCURSOS {STR_VAR_1} veces.\p"
	.string "¡A {STR_VAR_3} le debe de encantar\n"
	.string "lucir a sus POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "“El rey de los CONCURSOS”$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Ganaste en los CONCURSOS…$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR ganó CONCURSOS\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de ser un\n"
	.string "increíble maestro de CONCURSOS!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "“El ENTRENADOR consumista”$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Te fuiste de compras…$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR compró objetos en\n"
	.string "tiendas {STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de ser de esas\n"
	.string "personas que nacen para comprar!$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "“El ENTRENADOR detective”$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Usaste un BUSCAOBJETOS…$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR usó un ZAHORÍ\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡A {STR_VAR_3} le debe de encantar\n"
	.string "rastrear objetos ocultos!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "“El ENTRENADOR empapado”$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Te cayó un chaparrón…$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR se empapó con la lluvia\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡El carisma de {STR_VAR_3} atrae\n"
	.string "hasta la lluvia!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "“El lector de POKéDEX”$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Consultaste la POKéDEX…$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR consultó la POKéDEX\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡A {STR_VAR_3} le debe de encantar\n"
	.string "examinar POKéMON en la POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "“El coleccionista de CINTAS”$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Recibiste CINTAS…$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR recibió CINTAS\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de ser un ENTRENADOR\n"
	.string "que adora coleccionar CINTAS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "“El ENTRENADOR saltarín”$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Saltaste los desniveles…$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR saltó desniveles\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡Si hay un desnivel que saltar,\n"
	.string "{STR_VAR_3} no puede ignorarlo!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "“El ENTRENADOR teleadicto”$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Viste la tele…$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR vio la tele\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡A {STR_VAR_3} le debe de encantar\n"
	.string "ver la tele!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "“El ENTRENADOR relojero”$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Miraste la hora…$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR miró la hora\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de ser un ENTRENADOR\n"
	.string "puntual y pendiente del reloj!$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "“El rey de la LOTERÍA POKéMON”$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Ganaste a la LOTERÍA POKéMON…$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR ganó LOTERÍAS\n"
	.string "POKéMON {STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de tener muchos\n"
	.string "amigos con quienes intercambiar\l"
	.string "POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "“El ENTRENADOR impaciente”$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Dejaste POKéMON en la GUARDERÍA…$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR dejó POKéMON en la\n"
	.string "GUARDERÍA {STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} cría POKéMON\n"
	.string "con verdadero empeño!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "“El ENTRENADOR escalador”$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Te montaste en el TELEFÉRICO…$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR subió al TELEFÉRICO\n"
	.string "{STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de ser un ENTRENADOR\n"
	.string "ocupado, siempre arriba y abajo!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "“El ENTRENADOR bañista”$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Usaste los baños termales…$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Esta es la historia de un ENTRENADOR\n"
	.string "llamado {STR_VAR_3}.\p"
	.string "Este ENTRENADOR se bañó en aguas\n"
	.string "termales {STR_VAR_1} veces.\p"
	.string "¡{STR_VAR_3} debe de tener la piel\n"
	.string "suave como la de un bebé!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "I'm GIDDY!\n"
	.string "I have a scintillating story for you!\p"
	.string "Would you like to hear my story?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Also, I was thinking…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "That's about it, I think…\p"
	.string "We should chat again!\n"
	.string "Bye-bye!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hi, I'm the BARD.\n"
	.string "Would you like to hear my song?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, what a moving song…\n"
	.string "I wish I could play it for others…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "So?\n"
	.string "How do you like my song?\p"
	.string "But I'm none too happy about\n"
	.string "the lyrics.\p"
	.string "How would you like to write some\n"
	.string "new lyrics for me?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Thank you kindly!\n"
	.string "Let me sing it for you.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Was that how you wanted your song\n"
	.string "to go?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Okay! That's it, then.\n"
	.string "I'll sing this song for a while.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Hey, yo! They call me the HIPSTER.\n"
	.string "I'll teach you what's hip and happening.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "But, hey, I taught you what's hip and\n"
	.string "happening already.\p"
	.string "I'd like to spread the good word to\n"
	.string "other folks.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "But, hey, you already know a lot about\n"
	.string "what's hip and happening.\p"
	.string "I've got nothing new to teach you!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Hey, have you heard about\n"
	.string "“{STR_VAR_1}”?\p"
	.string "What's it mean? Well…\n"
	.string "Ask your daddy or mommy, okay?$"
