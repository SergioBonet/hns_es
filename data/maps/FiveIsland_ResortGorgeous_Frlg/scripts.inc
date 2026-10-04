FiveIsland_ResortGorgeous_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FiveIsland_ResortGorgeous_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_ResortGorgeous_OnFrame
	.byte 0

FiveIsland_ResortGorgeous_OnWarp::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

FiveIsland_ResortGorgeous_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
	closemessage
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 39, 8
	waitdooranim
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, FiveIsland_ResortGorgeous_Movement_SelphyEnterHome
	waitmovement 0
	closedoor 39, 8
	waitdooranim
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 2
	releaseall
	end

FiveIsland_ResortGorgeous_Movement_SelphyEnterHome::
	walk_up
	set_invisible
	step_end

FiveIsland_ResortGorgeous_EventScript_SelphysHouseSign::
	msgbox FiveIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
	end

FiveIsland_ResortGorgeous_Text_DaisyIntro::
	.string "¡Con mis manos, crearé mi propia\n"
	.string "victoria!$"

FiveIsland_ResortGorgeous_Text_DaisyDefeat::
	.string "Qué vergüenza...\n"
	.string "Estoy como un tomate...$"

FiveIsland_ResortGorgeous_Text_DaisyPostBattle::
	.string "¡Vaya, mis tubos de pintura se\n"
	.string "han esparcido por todas partes!$"

FiveIsland_ResortGorgeous_Text_CelinaIntro::
	.string "¡Disculpa!\n"
	.string "Estoy intentando pintar.\l"
	.string "¡Por favor, no te cruces en mi vista!$"

FiveIsland_ResortGorgeous_Text_CelinaDefeat::
	.string "Esta derrota…\n"
	.string "Siento que me quedo en blanco…$"

FiveIsland_ResortGorgeous_Text_CelinaPostBattle::
	.string "¿GILLIAN?\n"
	.string "Inclina un poco la cabeza…\l"
	.string "¡Ahí! ¡Ese es el gesto que quiero!$"

FiveIsland_ResortGorgeous_Text_RaynaIntro::
	.string "Mmm...\n"
	.string "Este ángulo no es el mejor...$"

FiveIsland_ResortGorgeous_Text_RaynaDefeat::
	.string "Oh…\n"
	.string "Mis sentimientos están tristes…$"

FiveIsland_ResortGorgeous_Text_RaynaPostBattle::
	.string "El mar y el cielo son tan...\n"
	.string "volubles.\l"
	.string "Es difícil plasmarlos en el lienzo.$"

FiveIsland_ResortGorgeous_Text_JackiIntro::
	.string "Estoy de visita en la zona de\n"
	.string "recreo, para tu información.$"

FiveIsland_ResortGorgeous_Text_JackiDefeat::
	.string "¡Qué fuerte eres!$"

FiveIsland_ResortGorgeous_Text_JackiPostBattle::
	.string "Es un auténtico placer combatir\n"
	.string "disfrutando de la brisa marina.$"

FiveIsland_ResortGorgeous_Text_GillianIntro::
	.string "Estoy pensando en construir una\n"
	.string "piscina para mis POKéMON.$"

FiveIsland_ResortGorgeous_Text_GillianDefeat::
	.string "¡Oh, cielos!$"

FiveIsland_ResortGorgeous_Text_GillianPostBattle::
	.string "Una piscina no estaría nada mal,\n"
	.string "pero un solárium sería fabuloso.$"

FiveIsland_ResortGorgeous_Text_DestinIntro::
	.string "No hay nadie que corra más rápido\n"
	.string "que yo.$"

FiveIsland_ResortGorgeous_Text_DestinDefeat::
	.string "¡Vaya!\n"
	.string "¡Me he precipitado!$"

FiveIsland_ResortGorgeous_Text_DestinPostBattle::
	.string "Cuando corro en el sentido del\n"
	.string "viento es como si volara.$"

FiveIsland_ResortGorgeous_Text_TobyIntro::
	.string "Debo decir que la vida marina de\n"
	.string "este complejo me sienta bien.$"

FiveIsland_ResortGorgeous_Text_TobyDefeat::
	.string "¡Qué impacto!\n"
	.string "Debes de estar bromeando.$"

FiveIsland_ResortGorgeous_Text_TobyPostBattle::
	.string "Me parece que te lo has tomado\n"
	.string "demasiado en serio.$"

FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
	.string "CONSU: Gracias.\p"
	.string "Ya te puedes ir.$"

FiveIsland_ResortGorgeous_Text_SelphysHouse::
	.string "CASA de CONSU$"

