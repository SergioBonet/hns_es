RuinsOfAlph_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

RuinsOfAlph_Lab_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RuinsOfAlph_Lab_EventScript_Scientist1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Lab_Text_Scientist1, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_Lab_EventScript_Scientist2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Lab_Text_Scientist2, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph_Lab_EventScript_Fossils::
	lock
	msgbox RuinsOfAlph_Lab_Text_Fossils, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Lab_Text_Scientist1:
	.string "Las RUINAS datan de hace unos 1.500\n"
	.string "años.\p"
	.string "Pero ignoramos por qué o por quién\n"
	.string "fueron construidas.$"

RuinsOfAlph_Lab_Text_Scientist2:
	.string "En las paredes de las RUINAS hay unos\n"
	.string "dibujos extraños.\p"
	.string "Deben de ser la clave para desvelar el\n"
	.string "misterio de las RUINAS.$"

RuinsOfAlph_Lab_Text_Fossils:
	.string "Fósiles hallados en las RUINAS. Quizás\n"
	.string "haya más en algún sitio…$"


RuinsOfAlph_Lab_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RuinsOfAlph_Lab_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RuinsOfAlph_Lab_EventScript_StillRegenerating
	msgbox RuinsOfAlph_Lab_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeClawFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeHelixFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeDomeFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_NoticeOldAmber
	release
	end

@ This whole section has needless duplication and could be condensed considerably
RuinsOfAlph_Lab_EventScript_NoticeRootFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveRootFossil
	end

RuinsOfAlph_Lab_EventScript_GiveRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeClawFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveClawFossil
	end

RuinsOfAlph_Lab_EventScript_GiveClawFossil::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeHelixFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveHelixFossil
	end

RuinsOfAlph_Lab_EventScript_GiveHelixFossil::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_HELIX_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeDomeFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveDomeFossil
	end

RuinsOfAlph_Lab_EventScript_GiveDomeFossil::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_DOME_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
	release
	end

RuinsOfAlph_Lab_EventScript_NoticeOldAmber::
	closemessage
	playse SE_PIN
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_RUINS_FOSSIL_SCIENTIST
	applymovement LOCALID_RUINS_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ChooseFossil
	goto RuinsOfAlph_Lab_EventScript_GiveOldAmber
	end

RuinsOfAlph_Lab_EventScript_GiveOldAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	msgbox RuinsOfAlph_Lab_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_OLD_AMBER
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 5
	release
	end

RuinsOfAlph_Lab_EventScript_DeclineGiveFossil::
	msgbox RuinsOfAlph_Lab_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2::
	msgbox RuinsOfAlph_Lab_Text_OhIsThatSo2, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_StillRegenerating::
	msgbox RuinsOfAlph_Lab_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RuinsOfAlph_Lab_EventScript_LileepReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RuinsOfAlph_Lab_EventScript_AnorithReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 3, RuinsOfAlph_Lab_EventScript_OmanyteReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 4, RuinsOfAlph_Lab_EventScript_KabutoReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 5, RuinsOfAlph_Lab_EventScript_AeroReady
	end

RuinsOfAlph_Lab_EventScript_LileepReady::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveLileep
	end

RuinsOfAlph_Lab_EventScript_AnorithReady::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveAnorith
	end

RuinsOfAlph_Lab_EventScript_OmanyteReady::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveOmanyte
	end

RuinsOfAlph_Lab_EventScript_KabutoReady::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveKabuto
	end

RuinsOfAlph_Lab_EventScript_AeroReady::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RuinsOfAlph_Lab_EventScript_ReceiveAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileep::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveLileepParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveLileepParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveLileepPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveLileepPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferLileepToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferLileepToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingLileep
	end

RuinsOfAlph_Lab_EventScript_ReceivedLileepFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingLileep::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorith::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveAnorithParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorithParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	end

RuinsOfAlph_Lab_EventScript_ReceiveAnorithPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferAnorithToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAnorithToPC
	end

RuinsOfAlph_Lab_EventScript_TransferAnorithToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith
	end

RuinsOfAlph_Lab_EventScript_ReceivedAnorithFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingAnorith::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanyteParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC::
	call RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveOmanytePC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferOmanyteToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte
	end

RuinsOfAlph_Lab_EventScript_ReceivedOmanyteFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingOmanyte::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	call_if_unset FLAG_BADGE04_GET, RuinsOfAlph_Lab_EventScript_GiveEarlyKabuto
	call_if_set FLAG_BADGE04_GET, RuinsOfAlph_Lab_EventScript_GiveLateKabuto
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_GiveEarlyKabuto::
	givemon SPECIES_KABUTO, 5
	return

RuinsOfAlph_Lab_EventScript_GiveLateKabuto::
	givemon SPECIES_KABUTO, 20
	return

RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveKabutoPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferKabutoToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferKabutoToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto
	end

RuinsOfAlph_Lab_EventScript_ReceivedKabutoFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingKabuto::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RuinsOfAlph_Lab_EventScript_ReceiveAero::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	givemon SPECIES_AERODACTYL, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RuinsOfAlph_Lab_EventScript_ReceiveAeroParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RuinsOfAlph_Lab_EventScript_ReceiveAeroPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroParty::
	call RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveAeroParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroPC::
	call RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_ReceiveAeroPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	end

RuinsOfAlph_Lab_EventScript_ReceiveAeroPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto RuinsOfAlph_Lab_EventScript_TransferAeroToPC
	end
	
RuinsOfAlph_Lab_EventScript_TransferAeroToPC::
	call Common_EventScript_TransferredToPC
	goto RuinsOfAlph_Lab_EventScript_FinishReceivingAero
	end

RuinsOfAlph_Lab_EventScript_ReceivedAeroFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	return

RuinsOfAlph_Lab_EventScript_FinishReceivingAero::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end


RuinsOfAlph_Lab_EventScript_ChooseFossil::
	message RuinsOfAlph_Lab_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL_HNS, FALSE
	switch VAR_RESULT
	case 0, RuinsOfAlph_Lab_EventScript_ChooseClawFossil
	case 1, RuinsOfAlph_Lab_EventScript_ChooseRootFossil
	case 2, RuinsOfAlph_Lab_EventScript_ChooseHelixFossil
	case 3, RuinsOfAlph_Lab_EventScript_ChooseDomeFossil
	case 4, RuinsOfAlph_Lab_EventScript_ChooseOldAmber
	case 5, RuinsOfAlph_Lab_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RuinsOfAlph_Lab_EventScript_CancelFossilSelect
	end

RuinsOfAlph_Lab_EventScript_ChooseClawFossil::
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveClawFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseRootFossil::
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveRootFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseHelixFossil::
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveHelixFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseDomeFossil::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveDomeFossil
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_ChooseOldAmber::
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Lab_EventScript_GiveOldAmber
	goto_if_eq VAR_RESULT, FALSE, RuinsOfAlph_Lab_EventScript_DeclineGiveFossil2
	end

RuinsOfAlph_Lab_EventScript_CancelFossilSelect::
	release
	end

RuinsOfAlph_Lab_EventScript_WorkOnNext::
	msgbox RuinsOfAlph_Lab_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_Lab_Text_DeviceForTalkingToPokemon:
	.string "Estamos desarrollando un dispositivo\n"
	.string "para hablar con los POKéMON.\p"
	.string "Bueno, la verdad es que todavía no\n"
	.string "hemos conseguido gran cosa…$"

RuinsOfAlph_Lab_Text_DevelopingNewBalls:
	.string "Estoy desarrollando nuevos tipos\n"
	.string "de POKé BALLS…\p"
	.string "En fin, lo cierto es que aún no he\n"
	.string "descubierto nada que funcione…$"

RuinsOfAlph_Lab_Text_WeFinallyMadeNewBalls:
	.string "¡Por fin hemos creado nuevos tipos\n"
	.string "de POKé BALLS!\p"
	.string "Con la ACOPIO BALL es más fácil cazar\n"
	.string "aquellos tipos de POKéMON que ya has\l"
	.string "atrapado al menos una vez antes.\p"
	.string "Con la TURNO BALL resulta más fácil\n"
	.string "atrapar POKéMON a medida que va\l"
	.string "avanzando el combate.\p"
	.string "Ambas son patentes exclusivas\n"
	.string "de DEVON S.A. ¡Pruébalas!$"

RuinsOfAlph_Lab_Text_IMadePokenav:
	.string "¡Soy el creador del POKéNAV!\p"
	.string "¡Como ingeniero, es un gran orgullo\n"
	.string "ser el autor de esta maravilla!$"

RuinsOfAlph_Lab_Text_WowThatsAPokenav:
	.string "¡Guau!\n"
	.string "¡Tienes un POKéNAV!\p"
	.string "¿Sabes que se creó porque nuestro\n"
	.string "PRESIDENTE quería saber más sobre\l"
	.string "los sentimientos de los POKéMON?\p"
	.string "¿Quieres que te explique con detalle\n"
	.string "todas sus características?\p"
	.string "No, mejor las vas descubriendo tú\n"
	.string "a base de usarlo. No es tan difícil.$"

RuinsOfAlph_Lab_Text_DeviceToVisualizePokemonDreams:
	.string "Estoy intentando desarrollar un\n"
	.string "dispositivo que reproduzca una imagen\l"
	.string "de los sueños de los POKéMON.\p"
	.string "Por ahora no he avanzado mucho…$"

RuinsOfAlph_Lab_Text_DevelopDeviceToResurrectFossils:
	.string "Llevo siglos intentando crear\n"
	.string "un dispositivo para reanimar POKéMON\l"
	.string "a partir de sus fósiles…\p"
	.string "¡Y por fin lo he conseguido!$"

RuinsOfAlph_Lab_Text_WantToBringFossilBackToLife:
	.string "Un momento. Eso que tienes ahí…\n"
	.string "¿no es un fósil de un POKéMON?\p"
	.string "¿Querrías reanimarlo?\p"
	.string "Pues yo puedo hacerlo con mi\n"
	.string "REGENERADOR de FÓSILES.$"

RuinsOfAlph_Lab_Text_OhIsThatSo:
	.string "Ah, ¿sí?\p"
	.string "Te aseguro que mis conocimientos\n"
	.string "tecnológicos son excepcionales.$"

RuinsOfAlph_Lab_Text_OhIsThatSo2:
	.string "Vaya, no tienes este fósil. Vuelve si\n"
	.string "consigues encontrarlo.$"

RuinsOfAlph_Lab_Text_TwoFossilsPickOne:
	.string "¡Vaya, qué sorpresa! ¿Tienes más de un\n"
	.string "fósil?\p"
	.string "Por desgracia, mi máquina solo puede\n"
	.string "regenerar un POKéMON cada vez.\p"
	.string "¿Qué fósil quieres regenerar?$"

RuinsOfAlph_Lab_Text_HandedFossilToResearcher:
	.string "¡Excelente! Pongámonos a ello ahora\n"
	.string "mismo.\p"
	.string "{PLAYER} ha entregado el {STR_VAR_1}\n"
	.string "al INVESTIGADOR de las RUINAS.$"

RuinsOfAlph_Lab_Text_FossilRegeneratorTakesTime:
	.string "El REGENERADOR de FÓSILES\n"
	.string "que he ideado es algo impresionante.\p"
	.string "Pero tiene un problemilla… Tarda\n"
	.string "un montón en funcionar…\p"
	.string "Así que, ejem, ¿por qué no vas a darte\n"
	.string "una vueltecita mientras tanto?$"

RuinsOfAlph_Lab_Text_FossilizedMonBroughtBackToLife:
	.string "¡Gracias por tu paciencia!\p"
	.string "Tu POKéMON fosilizado ya vuelve\n"
	.string "a estar vivito y coleando.\p"
	.string "Este fósil era un antiguo {STR_VAR_2}\n"
	.string "POKéMON, sí, señor.$"

RuinsOfAlph_Lab_Text_ReceivedMonFromResearcher:
	.string "¡{PLAYER} ha recibido a {STR_VAR_2} del\n"
	.string "INVESTIGADOR!$"

@ Unused
RuinsOfAlph_Lab_Text_TooManyPokemon:
	.string "Vaya, tienes demasiados POKéMON. No\n"
	.string "tienes sitio para este.$"

RuinsOfAlph_Lab_Text_DevelopNewPokenavFeature:
	.string "Estoy intentando crear una nueva\n"
	.string "función para el POKéNAV…\p"
	.string "Pero no me sale, no me sale…$"

RuinsOfAlph_Lab_Text_WhatToWorkOnNext:
	.string "Bueno, bueno, ¿qué podría\n"
	.string "ponerme a investigar ahora?\p"
	.string "¿Sabes? Esta empresa nos permite\n"
	.string "hacer realidad nuestros sueños.\p"
	.string "No existe mejor lugar para un\n"
	.string "ingeniero con visión de futuro.$"


