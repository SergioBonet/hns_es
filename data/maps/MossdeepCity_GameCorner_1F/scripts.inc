MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Cuando era un yogurín, viajé por todo\n"
	.string "el mundo como ENTRENADOR POKéMON.\p"
	.string "Ahora que soy un vejestorio, me basta\n"
	.string "con ver los combates de los demás.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "Parece que la puerta está atrancada.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Un ENTRENADOR que se llama {STR_VAR_1}\n"
	.string "ha venido de visita.\p"
	.string "¿Quieres desafiar a {STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "¿No quieres luchar?\n"
	.string "Me decepcionas…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "¡Muy bien, muy bien!\p"
	.string "Pero mi casa no es demasiado sólida.\p"
	.string "¿Podrías dejarlo en un combate\n"
	.string "de tres asaltos?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Antes de luchar, deberíais guardar\n"
	.string "la partida.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "¡Espero disfrutar de un buen combate!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "¡Al final habéis empatado!\p"
	.string "Fue un gran combate en el que\n"
	.string "nadie dio su brazo a torcer.$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "¡Ha sido grandioso!\p"
	.string "Me ha hecho recordar mis tiempos\n"
	.string "como ENTRENADOR.$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "¡Mala suerte!\p"
	.string "Pero no ha estado tan mal. Espero\n"
	.string "que la próxima vez puedas ganar.$"
