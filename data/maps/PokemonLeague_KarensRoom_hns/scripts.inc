PokemonLeague_KarensRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC

PokemonLeague_KarensRoom_EventScript_KarenRematchStandard::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_POSTOBC_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
	.string "KAREN: Ah, otra vez tú.\p"
	.string "Espero que no hayas olvidado lo que\n"
	.string "creo:\p"
	.string "la verdadera fuerza nace de la\n"
	.string "confianza en los POKéMON.\p"
	.string "Desde nuestro último encuentro, el\n"
	.string "vínculo con mis POKéMON se ha hecho\l"
	.string "aún más profundo.\p"
	.string "¿Estás listo para enfrentarte a un\n"
	.string "equipo unido por un vínculo\l"
	.string "inquebrantable?\p"
	.string "Muéstrame el poder del vínculo con\n"
	.string "tus POKéMON.$"

PokemonLeague_KarensRoom_Text_Before:
	.string "Soy KAREN, del ALTO MANDO.\p"
	.string "¿Eres {PLAYER}? ¡Qué gracia!\p"
	.string "Me gustan los POKéMON de tipo\n"
	.string "siniestro.\p"
	.string "Su naturaleza tan fuerte y salvaje me\n"
	.string "parece muy atractiva.\p"
	.string "¿Crees que podrás detenerlos? ¡A ver\n"
	.string "qué tal lo haces!\p"
	.string "¡Vamos allá!$"

PokemonLeague_KarensRoom_Text_Beaten:
	.string "Lo haces bien… Me gusta eso en los\n"
	.string "entrenadores.$"

PokemonLeague_KarensRoom_Text_Defeat:
	.string "POKéMON fuertes.\p"
	.string "POKéMON débiles.\p"
	.string "Ésa es la visión egoísta que tiene\n"
	.string "todo el mundo.\p"
	.string "Si un entrenador es bueno, debería\n"
	.string "ser capaz de ganar con sus favoritos.\p"
	.string "Me gusta tu estilo. Sabes lo que\n"
	.string "importa.\p"
	.string "Adelante. El CAMPEÓN te espera.$"

