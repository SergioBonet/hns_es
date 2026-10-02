PokemonLeague_BrunosRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_BrunosRoom_EventScript_BrunoRematchPostOBC

PokemonLeague_BrunosRoom_EventScript_BrunoRematchStandard::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_2_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematchPostOBC::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_POSTOBC_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
	.string "BRUNO: Bienvenido de nuevo, joven\n"
	.string "guerrero.\p"
	.string "Gracias a un entrenamiento riguroso,\n"
	.string "nos hemos hecho más fuertes.\p"
	.string "Mi voluntad de roca es aún más firme e\n"
	.string "inquebrantable.\p"
	.string "¿Estás preparado para un desafío aún\n"
	.string "mayor?\p"
	.string "Muéstrame los frutos de tu\n"
	.string "entrenamiento.\p"
	.string "¡Ju, ja!$"

PokemonLeague_BrunosRoom_Text_Before:
	.string "Soy BRUNO, del ALTO MANDO.\p"
	.string "Me entreno siempre al máximo porque\n"
	.string "confío en nuestro potencial.\p"
	.string "Por eso somos tan fuertes.\p"
	.string "¿Resistirás nuestro poder?\p"
	.string "¿Mmm? No veo que tengas miedo.\p"
	.string "Pareces audaz. ¡Perfecto!\p"
	.string "¿Vamos, {PLAYER}? ¡Te doblegarás ante\n"
	.string "nuestro inmenso poder!\p"
	.string "¡Ja, ja!$"

PokemonLeague_BrunosRoom_Text_Beaten:
	.string "¿Qué? ¿Cómo hemos podido perder?$"

PokemonLeague_BrunosRoom_Text_Defeat:
	.string "Como he perdido, no tengo derecho a\n"
	.string "decir nada…\p"
	.string "¡Enfréntate al siguiente desafío!$"
