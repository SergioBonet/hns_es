SilphCo_5F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad::
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_Text_RocketsInUproarAboutIntruder::
	.string "El TEAM ROCKET está buscando\n"
	.string "a un intruso.\p"
	.string "Te buscan a ti, ¿no?$"

SilphCo_5F_Text_YoureOurHeroThankYou::
	.string "¡El TEAM ROCKET se ha ido!\n"
	.string "¡Gracias! ¡Eres nuestra salvación!$"

SilphCo_5F_Text_Grunt1Intro::
	.string "Dicen que se ha colado alguien...$"

SilphCo_5F_Text_Grunt1Defeat::
	.string "¡Boooom!$"

SilphCo_5F_Text_Grunt1PostBattle::
	.string "¡No es que sea muy inteligente\n"
	.string "provocar al TEAM ROCKET!$"

SilphCo_5F_Text_BeauIntro::
	.string "¡En este piso estudiamos la\n"
	.string "tecnología de las POKé BALL!$"

SilphCo_5F_Text_BeauDefeat::
	.string "¡Caramba!\n"
	.string "¡Maldita sea!$"

SilphCo_5F_Text_BeauPostBattle::
	.string "¡Trabajamos en una nueva POKé\n"
	.string "BALL capaz de atraparlo todo!$"

SilphCo_5F_Text_DaltonIntro::
	.string "¿Qué?\p"
	.string "¡Aquí no debería haber niños!$"

SilphCo_5F_Text_DaltonDefeat::
	.string "¡Oh, cielos!$"

SilphCo_5F_Text_DaltonPostBattle::
	.string "¡Sólo has llegado al P4!\n"
	.string "¡Mi JEFE aún está muy lejos!$"

SilphCo_5F_Text_Grunt2Intro::
	.string "¡Respeta un poco al TEAM ROCKET!$"

SilphCo_5F_Text_Grunt2Defeat::
	.string "(Tos)...\n"
	.string "(Tos)...$"

SilphCo_5F_Text_Grunt2PostBattle::
	.string "Eso me recuerda que...\p"
	.string "¡KOFFING evoluciona y se\n"
	.string "transforma en WEEZING!$"

SilphCo_5F_Text_PorygonFirstVRMon::
	.string "¡Un INFORME sobre los POKéMON!\p"
	.string "PORYGON, el primer POKéMON\n"
	.string "virtual, se creó en el LABORATORIO\l"
	.string "POKéMON.$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
	.string "¡Un INFORME sobre los POKéMON!\p"
	.string "¡Confirmadas más de 350 técnicas\n"
	.string "POKéMON!$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
	.string "¡Un INFORME sobre los POKéMON!\p"
	.string "Se ha confirmado que algunos\n"
	.string "POKéMON evolucionan cuando\l"
	.string "se realiza un intercambio.$"

SilphCo_5F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P4$"

SilphCo_5F_Text_RocketBossLookingForStrongMons::
	.string "Los tipejos esos que se apoderaron\n"
	.string "de nuestro edificio...\p"
	.string "Su JEFE dijo que estaba buscando\n"
	.string "POKéMON fuertes.\p"
	.string "Espero que nuestro PRESIDENTE\n"
	.string "se haya ocupado del tema...$"
