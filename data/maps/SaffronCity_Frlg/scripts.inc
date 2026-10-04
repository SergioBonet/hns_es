SaffronCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	end

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
	return

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SaffronCity_Text_ImASecurityGuard
	release
	end

SaffronCity_EventScript_DoorGuardAsleep::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_SABRINA, 0
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_WhatDoYouWantGetLost::
	.string "¿Qué quieres?\n"
	.string "¡Lárgate!$"

SaffronCity_Text_BossTakeTownForTeamRocket::
	.string "¡El JEFE dijo que tomará esta\n"
	.string "ciudad en nombre del TEAM ROCKET!$"

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
	.string "¡No te pongas farruco!\n"
	.string "¡O tendré que hacerte daño!$"

SaffronCity_Text_SaffronBelongsToTeamRocket::
	.string "¡AZAFRÁN pertenece al TEAM ROCKET!$"

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
	.string "¡Mi vida criminal me hace sentir\n"
	.string "tan vivo!$"

SaffronCity_Text_WatchWhereYoureWalking::
	.string "¡Ay!\n"
	.string "¡Mira por dónde andas!$"

SaffronCity_Text_WeCanExploitMonsAroundWorld::
	.string "Con SILPH bajo control, ¡podremos\n"
	.string "explotar a los POKéMON de todo el\l"
	.string "mundo!\p"
	.string "¡Nos haremos asquerosamente ricos,\n"
	.string "jajá!$"

SaffronCity_Text_YouBeatTeamRocket::
	.string "¿Has vencido tú solo al TEAM ROCKET?\n"
	.string "¡Es increíble!$"

SaffronCity_Text_SafeToGoOutAgain::
	.string "¡Sí! ¡El TEAM ROCKET se ha ido!\n"
	.string "¡Ya se puede salir otra vez!$"

SaffronCity_Text_PeopleComingBackToSaffron::
	.string "La gente huyó en masa de aquí\n"
	.string "cuando llegaron esos ROCKET.\p"
	.string "Ahora deberían volver en tropel\n"
	.string "a AZAFRÁN.$"

SaffronCity_Text_FlewHereOnPidgeot::
	.string "Vine volando en mi PIDGEOT cuando\n"
	.string "leí lo de SILPH.\p"
	.string "¿Ya ha terminado?\n"
	.string "Me he perdido la acción mediática…$"

SaffronCity_Text_Pidgeot::
	.string "PIDGEOT: ¡Bi bibii!$"

SaffronCity_Text_SawRocketBossEscaping::
	.string "Vi al JEFE ROCKET escapar del\n"
	.string "edificio de SILPH.$"

SaffronCity_Text_ImASecurityGuard::
	.string "Soy guardia de seguridad.\p"
	.string "A los niños sospechosos no los dejo\n"
	.string "pasar.$"

SaffronCity_Text_HesTakingASnooze::
	.string "…\n"
	.string "Zzz…\p"
	.string "¡Ja! ¡Se ha quedado dormido!$"

SaffronCity_Text_CitySign::
	.string "CIUDAD AZAFRÁN\p"
	.string "La brillante y dorada tierra del\n"
	.string "comercio$"

SaffronCity_Text_FightingDojo::
	.string "DOJO DE LUCHA$"

SaffronCity_Text_GymSign::
	.string "GIMNASIO POKéMON de CIUDAD AZAFRÁN\n"
	.string "LÍDER: SABRINA\l"
	.string "¡La Maestra de los POKéMON PSÍQUICOS!$"

SaffronCity_Text_FullHealCuresStatus::
	.string "PISTAS ENTRENADOR\p"
	.string "CURA TOTAL cura todos los males,\n"
	.string "como quemaduras, parálisis,\l"
	.string "envenenamiento, congelación y sueño.\p"
	.string "Cuesta un poco más, pero es más\n"
	.string "cómodo que comprar otros objetos.$"

SaffronCity_Text_GreatBallImprovedCatchRate::
	.string "PISTAS ENTRENADOR\p"
	.string "La nueva SUPER BALL ofrece mejores\n"
	.string "probabilidades de captura.\p"
	.string "¡Pruébala con esos POKéMON\n"
	.string "tan difíciles de atrapar!$"

SaffronCity_Text_SilphCoSign::
	.string "EDIFICIO de SILPH S.A.$"

SaffronCity_Text_MrPsychicsHouse::
	.string "CASA del SR. PSÍQUICO$"

SaffronCity_Text_SilphsLatestProduct::
	.string "¡El último producto de SILPH!\n"
	.string "Fecha de lanzamiento por determinar…$"

SaffronCity_Text_TrainerFanClubSign::
	.string "CLUB de FANS de ENTRENADORES POKéMON\p"
	.string "Muchos ENTRENADORES han garabateado\n"
	.string "su nombre en este cartel.$"

SaffronCity_Text_HowCanClubNotRecognizeLance::
	.string "Este CLUB de FANS…\n"
	.string "¡Aquí nadie tiene ni idea!\p"
	.string "¿Cómo no van a reconocer el\n"
	.string "talento de LANCE?\p"
	.string "¡Defiende la justicia!\n"
	.string "¡Es genial y apasionado a la vez!\l"
	.string "¡Es el mejor, LANCE!$"

