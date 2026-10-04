SSAnne_1F_Room6_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHeal::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHealMale::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
	release
	end

SSAnne_1F_Room6_Text_TakeAShortRest::
	.string "Tienes cara de cansancio. ¿Quieres\n"
	.string "descansar un ratito?$"

SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed::
	.string "Me alegra ver que todos están\n"
	.string "descansados y de buen humor.$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother::
	.string "Perdona por darte la lata.\n"
	.string "Me recuerdas a mi hermano pequeño…$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMySister::
	.string "Perdona por darte la lata.\n"
	.string "Me recuerdas a mi hermana pequeña…$"

