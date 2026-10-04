SSAnne_CaptainsOffice_Frlg_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	lock
	goto_if_set FLAG_GOT_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
	msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	call EventScript_RestorePrevTextColor
	delay 50
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut
	giveitem_msg SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain, ITEM_HM01, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SSAnne_CaptainsOffice_Text_ExplainCut
	setflag FLAG_GOT_HM01
	setvar VAR_MAP_SCENE_VERMILION_CITY, 1
	release
	end

@ Unused
SSAnne_CaptainsOffice_EventScript_NoRoomForCut::
	msgbox SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis
	closemessage
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon
	release
	end

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
	.string "CAPITÁN: ¡Puajj!\n"
	.string "Me siento fatal.\l"
	.string "Me he mareado...$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
	.string "¡{PLAYER} le dio un masaje\n"
	.string "al CAPITÁN!\p"
	.string "(Scratch)...\n"
	.string "(Scratch)...$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
	.string "CAPITÁN: ¡Uff! ¡Gracias!\n"
	.string "Ya me siento mucho mejor...\p"
	.string "¿Quieres ver mi técnica de CORTAR?\p"
	.string "Te la mostraría si no estuviera\n"
	.string "tan mareado.\p"
	.string "¡Ya sé!\n"
	.string "¡Toma esto!\p"
	.string "¡Enséñasela a tu POKéMON\n"
	.string "y en breve estará CORTANDO!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
	.string "¡{PLAYER} obtuvo la MO01\n"
	.string "de manos del CAPITÁN!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
	.string "Al usar CORTE, se pueden talar\n"
	.string "árboles pequeños.\p"
	.string "A lo mejor deberías probarlo con\n"
	.string "los árboles de CIUDAD CARMÍN.$"

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
	.string "CAPITÁN: ¡Bien!\p"
	.string "¡Ahora que ya no estoy mareado,\n"
	.string "creo que deberíamos irnos!\p"
	.string "¡El S.S. ANNE zarpará pronto!\p"
	.string "¡Adiós, hasta que volvamos\n"
	.string "a CIUDAD CARMÍN!$"

SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis::
	.string "¡Oh, no!\n"
	.string "¡No tienes sitio para esto!$"

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
	.string "¡Puaj!\n"
	.string "¡No debería haber mirado!$"

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
	.string "Cómo combatir el mareo...\n"
	.string "¡El CAPITÁN está leyendo esto!$"

