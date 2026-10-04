FiveIsland_MemorialPillar_Frlg_MapScripts::
	.byte 0

FiveIsland_MemorialPillar_EventScript_MemorialMan::
	lock
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_AlreadyGotTM42
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_ReturnedForTM42
	msgbox FiveIsland_MemorialPillar_Text_ScrubScrub
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_FacePlayer
	waitmovement 0
	delay 45
	msgbox FiveIsland_MemorialPillar_Text_YourMonsLookHealthy
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox FiveIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix
	release
	end

FiveIsland_MemorialPillar_EventScript_AlreadyGotTM42::
	msgbox FiveIsland_MemorialPillar_Text_ScrubScrubTectonix
	release
	end

FiveIsland_MemorialPillar_EventScript_ReturnedForTM42::
	msgbox FiveIsland_MemorialPillar_Text_StillHaveThingAsMyThanks
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_MemorialPillar_EventScript_NoRoomForTM42
	call FiveIsland_MemorialPillar_EventScript_ReceivedTM42
	release
	end

FiveIsland_MemorialPillar_EventScript_Memorial::
	lockall
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	msgbox FiveIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering
	checkitem ITEM_LEMONADE
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_MemorialPillar_EventScript_AskPlaceLemonade
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_AskPlaceLemonade::
	msgbox FiveIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FiveIsland_MemorialPillar_EventScript_PlaceLemonade
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_PlaceLemonade::
	removeitem ITEM_LEMONADE
	msgbox FiveIsland_MemorialPillar_Text_PlacedCanOfLemonade
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 45
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_MemorialPillar_Text_ThankYouPleaseTakeThis
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_MemorialPillar_EventScript_NoRoomForTM42
	call FiveIsland_MemorialPillar_EventScript_ReceivedTM42
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_ReceivedTM42::
	msgbox FiveIsland_MemorialPillar_Text_BeGoodToYourMonsToo
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_GOT_TM42_AT_MEMORIAL_PILLAR
	return

FiveIsland_MemorialPillar_EventScript_NoRoomForTM42::
	setflag FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR
	msgbox FiveIsland_MemorialPillar_Text_DontHaveRoomForIt
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced::
	msgbox FiveIsland_MemorialPillar_Text_HereLiesTectonix
	releaseall
	end

FiveIsland_MemorialPillar_Text_MiloIntro::
	.string "Soy el mayor de los HERMANOS\n"
	.string "PÁJARO.\p"
	.string "Lo mejor de las aves…\n"
	.string "Tiene que ser el pico.$"

FiveIsland_MemorialPillar_Text_MiloDefeat::
	.string "¡Estoy realmente en forma!$"

FiveIsland_MemorialPillar_Text_MiloPostBattle::
	.string "Desde aquí se puede ir volando\n"
	.string "a ISLA QUARTA.$"

FiveIsland_MemorialPillar_Text_ChazIntro::
	.string "Soy el mediano de los HERMANOS\n"
	.string "PÁJARO.\p"
	.string "Lo mejor que tienen los pájaros\n"
	.string "deben de ser las alas.$"

FiveIsland_MemorialPillar_Text_ChazDefeat::
	.string "¡Qué batida!$"

FiveIsland_MemorialPillar_Text_ChazPostBattle::
	.string "Había un tipo muy sombrío por\n"
	.string "allí.$"

FiveIsland_MemorialPillar_Text_HaroldIntro::
	.string "Soy el pequeño de los HERMANOS\n"
	.string "PÁJARO.\p"
	.string "Lo mejor que tienen los pájaros\n"
	.string "deben de ser las plumas.$"

FiveIsland_MemorialPillar_Text_HaroldDefeat::
	.string "El plumón es tan cómodo…\n"
	.string "Me da sueño…$"

FiveIsland_MemorialPillar_Text_HaroldPostBattle::
	.string "A mí me encanta ver pájaros\n"
	.string "POKéMON jugueteando tan contentos.$"

FiveIsland_MemorialPillar_Text_ScrubScrub::
	.string "Fro, fro…$"

FiveIsland_MemorialPillar_Text_YourMonsLookHealthy::
	.string "Mmm, así me gusta, que esté\n"
	.string "reluciente...$"

FiveIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix::
	.string "Aquí descansa mi ONIX...\n"
	.string "Se llamaba TECTONIX...$"

FiveIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering::
	.string "“Aquí yace TECTONIX”, pone\n"
	.string "en una piedra.\p"
	.string "Enfrente, hay una LIMONADA\n"
	.string "a modo de ofrenda.$"

FiveIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering::
	.string "¿Quieres dejar otra LIMONADA\n"
	.string "a modo de ofrenda?$"

FiveIsland_MemorialPillar_Text_PlacedCanOfLemonade::
	.string "{PLAYER} colocó una LIMONADA\n"
	.string "frente a la piedra.$"

FiveIsland_MemorialPillar_Text_ThankYouPleaseTakeThis::
	.string "G-gracias…\p"
	.string "Era la bebida favorita de mi\n"
	.string "TECTONIX…\p"
	.string "Ni siquiera te conozco, pero tu\n"
	.string "bondad…\p"
	.string "Me ha animado un poco.\p"
	.string "¿Puedes aceptar esto como\n"
	.string "agradecimiento?$"

FiveIsland_MemorialPillar_Text_BeGoodToYourMonsToo::
	.string "Tú también deberías comportarte \n"
	.string "con tus POKéMON.$"

FiveIsland_MemorialPillar_Text_DontHaveRoomForIt::
	.string "Si no te queda sitio, te la\n"
	.string "guardaré para cuando vuelvas.$"

FiveIsland_MemorialPillar_Text_StillHaveThingAsMyThanks::
	.string "Anda, si eres tú...\p"
	.string "Aquí tengo lo que quería darte\n"
	.string "como muestra de mi agradecimiento.$"

FiveIsland_MemorialPillar_Text_ScrubScrubTectonix::
	.string "Fro, fro…\p"
	.string "… … …\n"
	.string "TECTONIX…$"

FiveIsland_MemorialPillar_Text_HereLiesTectonix::
	.string "Cantos y rocas apilados de manera\n"
	.string "ordenada forman una especie\l"
	.string "de monumento.\p"
	.string "“Aquí yace TECTONIX”, pone\n"
	.string "en una piedra.$"

