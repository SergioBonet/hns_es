TrainerHill_Roof_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Roof_hns_OnLoad
	.byte 0

TrainerHill_Roof_hns_OnLoad::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

TrainerHill_Roof_hns_EventScript_Owner::
	trainerhill_settrainerflags
	lock
	faceplayer
	trainerhill_getownerstate
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_Arrived
	case 1, TrainerHill_Roof_hns_EventScript_GivePrize
	case 2, TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize
TrainerHill_Roof_hns_EventScript_Arrived::
	msgbox TrainerHill_Roof_hns_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerHill_Roof_hns_EventScript_GivePrize::
	trainerhill_giveprize
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_ReceivePrize
	case 1, TrainerHill_Roof_hns_EventScript_NoRoomForPrize
	case 2, TrainerHill_Roof_hns_EventScript_CheckFinalTime
TrainerHill_Roof_hns_EventScript_ReceivePrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_NoRoomForPrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_CheckFinalTime::
	trainerhill_finaltime
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_NewRecord
	case 1, TrainerHill_Roof_hns_EventScript_NoNewRecord
	case 2, TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
TrainerHill_Roof_hns_EventScript_NewRecord::
	msgbox TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_NoNewRecord::
	msgbox TrainerHill_Roof_hns_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_EndSpeakToOwner::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_Text_YouFinallyCameBravo:
	.string "¡Mmm!\p"
	.string "¡Por fin has llegado!\n"
	.string "¡Ya estás aquí!\p"
	.string "¡Espera! ¡No me lo digas!\n"
	.string "¡Ya sé por qué has subido\l"
	.string "corriendo hasta aquí!\p"
	.string "Querías verme a mí, al propietario\n"
	.string "de la COLINA DESAFÍO, porque…\p"
	.string "¡Quieres luchar a mi lado!\n"
	.string "¡¿A que sí?!\p"
	.string "¿Mmm?\n"
	.string "¿Cómo? ¿Que no ha sido por eso?\p"
	.string "Bueno, da igual, he visto cómo subías.\n"
	.string "¡Bien luchado! ¡Bravo! ¡Bravo!$"

TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift:
	.string "¡Para alguien tan maravilloso como tú,\n"
	.string "tengo el regalo más maravilloso, y\l"
	.string "además algo de dinero por tu\l"
	.string "esfuerzo!$"

TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis:
	.string "Oh, no, ¡no tienes sitio para nada!\n"
	.string "¡Vuelve cuando lo tengas!$"

TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly:
	.string "¡Oh, espera un momento! ¿De verdad\n"
	.string "has conseguido llegar aquí tan rápido?\p"
	.string "¡Espléndido! ¡Pero no tenías que\n"
	.string "correr tanto para venir a verme!\p"
	.string "Aunque es un detalle, claro.\n"
	.string "¡Le pediré a la chica de recepción\l"
	.string "que actualice el PANEL de TIEMPOS!$"

TrainerHill_Roof_hns_Text_YouWerentVeryQuick:
	.string "Pero bueno…\n"
	.string "No parece que hayas corrido mucho…$"

TrainerHill_Roof_hns_Text_ArriveZippierNextTime:
	.string "¿Sabes? Creo que me alegraría más\n"
	.string "si llegases más rápido la próxima vez.\p"
	.string "¡Seguro que hasta me animaba\n"
	.string "a formar un equipo contigo!\p"
	.string "¡Hasta entonces!$"
