VictoryRoad_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER1
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_3F, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Text_DoubleEdgeTeach::
	.string "Has conseguido abrirte paso por\n"
	.string "la CALLE VICTORIA con mucho\l"
	.string "valor; es para alegrarse.\p"
	.string "Como reconocimiento a tu hazaña,\n"
	.string "te enseñaré DOBLE FILO.\p"
	.string "¿Quieres?$"

Text_DoubleEdgeDeclined::
	.string "Te enseñaré la técnica cuando\n"
	.string "quieras.$"

Text_DoubleEdgeWhichMon::
	.string "¿A qué POKéMON quieres que\n"
	.string "le enseñe DOBLE FILO?$"

Text_DoubleEdgeTaught::
	.string "¡No bajes la guardia para la LIGA\n"
	.string "POKéMON!\p"
	.string "¡A por ella, acaba con todos!$"

VictoryRoad_3F_Text_GeorgeIntro::
	.string "¡Los rumores hablan de un\n"
	.string "ENTRENADOR espectacular!$"

VictoryRoad_3F_Text_GeorgeDefeat::
	.string "¡Los rumores eran ciertos!$"

VictoryRoad_3F_Text_GeorgePostBattle::
	.string "¿Derrotaste a GIOVANNI\n"
	.string "del TEAM ROCKET?$"

VictoryRoad_3F_Text_AlexaIntro::
	.string "¡Los ENTRENADORES sólo viven para\n"
	.string "buscar enemigos más fuertes!$"

VictoryRoad_3F_Text_AlexaDefeat::
	.string "¡Oooooh!\n"
	.string "¡Eres tan fuerte!$"

VictoryRoad_3F_Text_AlexaPostBattle::
	.string "¡Librar duros combates te hará\n"
	.string "más fuerte!$"

VictoryRoad_3F_Text_CarolineIntro::
	.string "¡Te demostraré lo fuerte que eres\n"
	.string "de verdad!$"

VictoryRoad_3F_Text_CarolineDefeat::
	.string "¡Argh! ¡Eres increíble!$"

VictoryRoad_3F_Text_CarolinePostBattle::
	.string "¡Yo soy la que ha aprendido\n"
	.string "la lección!$"

VictoryRoad_3F_Text_ColbyIntro::
	.string "¡Aquí sólo pueden pasar\n"
	.string "los elegidos!$"

VictoryRoad_3F_Text_ColbyDefeat::
	.string "¡No me lo puedo creer!$"

VictoryRoad_3F_Text_ColbyPostBattle::
	.string "¡Todos estos ENTRENADORES van a\n"
	.string "participar en la LIGA POKéMON!\p"
	.string "¡Ten cuidado!$"

VictoryRoad_3F_Text_RayIntro::
	.string "DESI: ¡Juntos lucharemos contra\n"
	.string "quien sea!$"

VictoryRoad_3F_Text_RayDefeat::
	.string "DESI: ¡No me lo puedo creer!$"

VictoryRoad_3F_Text_RayPostBattle::
	.string "DESI: Nos has vencido.\n"
	.string "La grandeza sigue siendo esquiva…$"

VictoryRoad_3F_Text_RayNotEnoughMons::
	.string "DESI: Acabaríamos contigo\n"
	.string "en un abrir y cerrar de ojos.\p"
	.string "Para luchar con nosotros, hay\n"
	.string "que tener dos POKéMON.$"

VictoryRoad_3F_Text_TyraIntro::
	.string "TULA: ¡Tenemos intención de\n"
	.string "convertirnos en campeones!$"

VictoryRoad_3F_Text_TyraDefeat::
	.string "TULA: Oh, pero…$"

VictoryRoad_3F_Text_TyraPostBattle::
	.string "TULA: De ti he aprendido la\n"
	.string "verdadera dimensión de la fuerza.$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
	.string "TULA: No podrás con nosotros\n"
	.string "si no tienes dos POKéMON.$"

