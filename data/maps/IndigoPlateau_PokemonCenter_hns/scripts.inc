IndigoPlateau_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_PokemonCenter_OnFrame 
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_Pokecenter_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 0, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 2, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 3, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 4, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 5, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 6, IndigoPlateau_PokemonCenter_Enter
	.2byte 0

IndigoPlateau_PokemonCenter_Enter::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setvar VAR_LEAGUE_STATE, 1
	end

IndigoPlateau_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU_HNS
	end


IndigoPlateau_EventScript_Cooltrainer::
	msgbox IndigoPlateau_Text_CooltrainerM, MSGBOX_NPC
	end

IndigoPlateau_EventScript_BlackBelt::
	msgbox IndigoPlateau_Text_Blackbelt, MSGBOX_NPC
	end

IndigoPlateau_EventScript_ShigyNinja::
	msgbox IndigoPlateau_Text_ShigyNinja, MSGBOX_NPC
	end

IndigoPlateau_Text_ShigyNinja:
	.string "¡Enhorabuena por llegar hasta aquí!\p"
	.string "He visto pasar a montones de\n"
	.string "ENTRENADORES a lo largo de los años, y\l"
	.string "todos son maravillosamente únicos.\p"
	.string "¡Deberías estar orgulloso de haber\n"
	.string "llegado tan lejos!\p"
	.string "¡Ahora, a por ellos!$"

IndigoPlateau_Text_Blackbelt:
	.string "La LIGA POKéMON no acepta nuevos\n"
	.string "aspirantes en este momento.\p"
	.string "Vuelve más tarde, por favor.$"

IndigoPlateau_Text_CooltrainerM:
	.string "En la LIGA POKéMON te pondrá a prueba\n"
	.string "el ALTO MANDO.\p"
	.string "Tienes que vencerlos a todos. ¡Si\n"
	.string "pierdes, tendrás que empezar desde el\l"
	.string "principio!$"

IndigoPlateau_EventScript_Silver::
	lock
	faceplayer 
	goto_if_set FLAG_DAILY_BEAT_SILVER, IndigoPlateau_EventScript_SilverBeat
	msgbox IndigoPlateau_Text_RivalEntrance1, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, IndigoPlateau_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, IndigoPlateau_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, IndigoPlateau_Silver_Battle_Chikorita
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BEAT_SILVER
	release
	end

IndigoPlateau_EventScript_SilverBeat::
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Text_RivalEntrance1:
	.string "Alto.\p"
	.string "¿Vas a enfrentarte ya al desafío de\n"
	.string "la LIGA POKéMON?\p"
	.string "Eso no va a pasar.\p"
	.string "Mis POKéMON, superbién entrenados,\n"
	.string "van a machacarte.\p"
	.string "¡{PLAYER}! ¡Te desafío!$"

IndigoPlateau_Text_RivalWin:
	.string "…\p"
	.string "Vale. He perdido.$"

IndigoPlateau_Text_RivalAfter:
	.string "¡Maldición…! Sigo sin ganar…\p"
	.string "Yo… Tengo que pensar más en mis\n"
	.string "POKéMON…\p"
	.string "¡Umm! ¡Procura no perder!$"

IndigoPlateau_EventScript_Psychic::
	lock
	faceplayer
	msgbox IndigoPlateau_Text_TeleportGuy1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_EventScript_PsychicTeleport
	msgbox IndigoPlateau_Text_TeleportGuyNo, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_EventScript_PsychicTeleport::
	msgbox IndigoPlateau_Text_TeleportGuyYes, MSGBOX_DEFAULT
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playbgm MUS_HG_NEW_BARK, FALSE
	delay 60
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	applymovement2 LOCALID_INDIGOPLATEAU_ABRA, IndigoPLateau_Movement_Abra
	waitmovement 0
	fadescreen FADE_TO_WHITE
	warpteleport MAP_NEW_BARK_TOWN_HNS, 20, 12
	waitstate
	release
	end
	
IndigoPLateau_Movement_Abra:
	jump_in_place_right
	jump_in_place_right
	step_end

IndigoPlateau_EventScript_Abra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	msgbox IndigoPlateau_Text_Abra, MSGBOX_DEFAULT
	waitmoncry
	release
	end

IndigoPlateau_Text_TeleportGuy1:
	.string "¿Qué? ¿Vas a desafiar al ALTO\p"
	.string "MANDO? ¿Seguro que quieres hacerlo?\p"
	.string "Si necesitas entrenarte más, mi\p"
	.string "ABRA te puede ayudar.\p"
	.string "ABRA te puede TELETRANSPORTAR.\p"
	.string "¿Te gustaría volver a casa?$"

IndigoPlateau_Text_TeleportGuyYes:
	.string "Vale. Concéntrate en la imagen de tu\n"
	.string "casa…$"

IndigoPlateau_Text_TeleportGuyNo:
	.string "Vale, vale. ¡Que tengas suerte!$"

IndigoPlateau_Text_Abra:
    .string "ABRA: Aabra…$"
