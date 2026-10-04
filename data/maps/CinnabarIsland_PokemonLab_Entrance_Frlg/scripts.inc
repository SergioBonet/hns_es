CinnabarIsland_PokemonLab_Entrance_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonLab_Entrance_OnTransition
	.byte 0

CinnabarIsland_PokemonLab_Entrance_OnTransition::
	call_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil::
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2
	return

CinnabarIsland_PokemonLab_Entrance_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_DrFujiPhoto::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_MeetingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_RAndDRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TestingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji::
	.string "Una foto de BLAINE\n"
	.string "y el SR. FUJI...\p"
	.string "Aparecen juntos con una sonrisa\n"
	.string "de oreja a oreja.$"

CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively::
	.string "Aquí estudiamos a los POKéMON.\p"
	.string "La gente suele traernos POKéMON\n"
	.string "raros para analizarlos.$"

CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji::
	.string "¡Una foto del fundador del\n"
	.string "LABORATORIO, el DR. FUJI!$"

CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign::
	.string "LABORATORIO POKéMON\n"
	.string "Sala de reuniones$"

CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign::
	.string "LABORATORIO POKéMON\n"
	.string "Sala de I + D$"

CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign::
	.string "LABORATORIO POKéMON\n"
	.string "Sala de pruebas$"

