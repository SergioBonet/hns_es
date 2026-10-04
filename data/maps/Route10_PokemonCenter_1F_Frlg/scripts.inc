.equ REQUIRED_OWNED_MONS, 20

Route10_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE10
	end

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Aide::
	lock
	faceplayer
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE, Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone
	msgbox Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_OWNED_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route10_PokemonCenter_1F_Text_GreatHereYouGo
	checkitemspace ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide, ITEM_EVERSTONE
	setflag FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone::
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_OWNED_MONS
	bufferitemname STR_VAR_2, ITEM_EVERSTONE
	return

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
	.string "¡Los POKéMON de ciertos elementos\n"
	.string "son más o menos fuertes que otros!$"

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
	.string "¡Vendí una inútil PEPITA\n"
	.string "por 5.000¥!$"

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
	.string "¡Dicen que hay fantasmas en\n"
	.string "PUEBLO LAVANDA!$"

Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons::
	.string "Oh… ¡{PLAYER}!\n"
	.string "¡Te estaba buscando!\p"
	.string "Soy uno de los siempre presentes\n"
	.string "AYUDANTES del PROF. OAK.\p"
	.string "Si tu POKéDEX tiene datos completos\n"
	.string "de veinte especies, debo darte\l"
	.string "un premio del PROF. OAK.\p"
	.string "Me confió esta\n"
	.string "PIEDRA ETERNA.\p"
	.string "Así que, {PLAYER}, déjame preguntarte.\p"
	.string "¿Has reunido datos de al menos\n"
	.string "veinte clases de POKéMON?$"

Route10_PokemonCenter_1F_Text_GreatHereYouGo::
	.string "¡Bien! ¡Has logrado {STR_VAR_3} tipos\n"
	.string "de POKéMON!\p"
	.string "¡Enhorabuena!\n"
	.string "¡Aquí tienes!$"

Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide::
	.string "¡{PLAYER} obtuvo la\n"
	.string "PIEDRAETERNA de manos\l"
	.string "del AYUDANTE!$"

Route10_PokemonCenter_1F_Text_ExplainEverstone::
	.string "Si dejas evolucionar a los\n"
	.string "POKéMON, tu POKéDEX\l"
	.string "se verá beneficiada.\p"
	.string "Aunque habrá algún caso en el\n"
	.string "que no quieras que evolucionen.\p"
	.string "Para evitarlo, dale al POKéMON\n"
	.string "que quieras una PIEDRAETERNA.\p"
	.string "Según dice el PROFESOR,\n"
	.string "el POKéMON que la lleve,\l"
	.string "no evolucionará.$"

