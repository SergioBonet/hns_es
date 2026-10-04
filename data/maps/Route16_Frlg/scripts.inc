Route16_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route16_EventScript_RemoveSnorlax
	end

Route16_EventScript_RemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route16_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route16_OnTransitionCyclingRoad
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route16_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_16_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route16_EventScript_FoughtSnorlax
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_Text_LaoIntro::
	.string "¿Qué quieres?$"

Route16_Text_LaoDefeat::
	.string "¡No te atrevas a reírte!$"

Route16_Text_LaoPostBattle::
	.string "Nos gusta correr por aquí.\n"
	.string "¿Y a ti?$"

Route16_Text_KojiIntro::
	.string "¡Bonita BICI!\n"
	.string "¡Dámela!$"

Route16_Text_KojiDefeat::
	.string "¡Fuera de combate!$"

Route16_Text_KojiPostBattle::
	.string "¡Olvídalo, nadie necesita tu BICI!$"

Route16_Text_LukeIntro::
	.string "¡Sal a jugar, ratoncito!$"

Route16_Text_LukeDefeat::
	.string "¡Pequeña rata!$"

Route16_Text_LukePostBattle::
	.string "¡Odio perder!\n"
	.string "¡No te acerques a mí!$"

Route16_Text_HideoIntro::
	.string "¡Oye! ¡Me has dado!$"

Route16_Text_HideoDefeat::
	.string "¡Qué golpe!$"

Route16_Text_HideoPostBattle::
	.string "Te guste o no, de aquí no nos\n"
	.string "va a echar nadie.\p"
	.string "A FUCSIA puedes llegar también\n"
	.string "desde CARMÍN, por la costa.$"

Route16_Text_CamronIntro::
	.string "¡Tengo hambre y no estoy\n"
	.string "de humor!$"

Route16_Text_CamronDefeat::
	.string "¡Mal, mal, muy mal!$"

Route16_Text_CamronPostBattle::
	.string "¡Me gustan mis fuertes POKéMON!\n"
	.string "¡Son tremendos contra mis enemigos!$"

Route16_Text_RubenIntro::
	.string "¡Eh, vamos a echar el rato!$"

Route16_Text_RubenDefeat::
	.string "¡No me fastidies!$"

Route16_Text_RubenPostBattle::
	.string "Yo me parto tomándole el pelo\n"
	.string "a la gente con mis POKéMON.\p"
	.string "¡Son los mejores para asustar\n"
	.string "a la gente y, además, muerden!$"

Route16_Text_MonSprawledOutInSlumber::
	.string "Un POKéMON está tumbado en un\n"
	.string "sueño profundo y cómodo.$"

Route16_Text_CyclingRoadSign::
	.string "CAMINO DE BICIS\n"
	.string "¡Buen descenso!$"

Route16_Text_RouteSign::
	.string "RUTA 16:\n"
	.string "CIUDAD AZULONA - CIUDAD FUCSIA$"

Route16_Text_JedIntro::
	.string "JOEL: Nuestro amor no conoce límites.\n"
	.string "¡Estamos enamorados y lo demostramos!$"

Route16_Text_JedDefeat::
	.string "JOEL: ¡He perdido, pero no\n"
	.string "en el amor!$"

Route16_Text_JedPostBattle::
	.string "JOEL: ¡Oye, LIZ, no te quedes\n"
	.string "embobada conmigo!$"

Route16_Text_JedNotEnoughMons::
	.string "JOEL: ¿Sólo tienes un POKéMON?\n"
	.string "¿Y no te da pena?$"

Route16_Text_LeaIntro::
	.string "LIZ: ¡A veces, pienso en todo\n"
	.string "lo que nos queremos y se me pone\l"
	.string "la carne de gallina!$"

Route16_Text_LeaDefeat::
	.string "LIZ: ¡JOEL me gusta hasta cuando\n"
	.string "pierde!$"

Route16_Text_LeaPostBattle::
	.string "LIZ: Lo siento, pero no hay nadie\n"
	.string "como JOEL.$"

Route16_Text_LeaNotEnoughMons::
	.string "LIZ: ¿No tienes dos POKéMON?\p"
	.string "¿Y no os sentís solos?$"
