SilphCo_6F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
	call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
	end

SilphCo_6F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts
	release
	end

SilphCo_6F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder
	release
	end

SilphCo_6F_EventScript_WorkerM3::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM3RocketsGone
	msgbox SilphCo_6F_Text_RocketsTookOverBuilding
	release
	end

SilphCo_6F_EventScript_WorkerM3RocketsGone::
	msgbox SilphCo_6F_Text_BetterGetBackToWork
	release
	end

SilphCo_6F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_6F_Text_HelpMePlease
	release
	end

SilphCo_6F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_6F_Text_WeGotEngaged
	release
	end

SilphCo_6F_EventScript_WorkerF1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF1RocketsGone
	msgbox SilphCo_6F_Text_ThatManIsSuchACoward
	release
	end

SilphCo_6F_EventScript_WorkerF1RocketsGone::
	msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim
	release
	end

SilphCo_6F_EventScript_WorkerF2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF2RocketsGone
	msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld
	release
	end

SilphCo_6F_EventScript_WorkerF2RocketsGone::
	msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou
	release
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
	msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
	msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_Text_RocketsTookOverBuilding::
	.string "¡Los ROCKET vinieron y se\n"
	.string "apoderaron de todo el edificio!$"

SilphCo_6F_Text_BetterGetBackToWork::
	.string "¡Más vale que vuelva al trabajo!$"

SilphCo_6F_Text_HelpMePlease::
	.string "¡Oh, por favor!\n"
	.string "¡Ayúdame!$"

SilphCo_6F_Text_WeGotEngaged::
	.string "Nos hemos prometido.\n"
	.string "¡Jeje!$"

SilphCo_6F_Text_ThatManIsSuchACoward::
	.string "Ese hombre que está a mi lado…\n"
	.string "¡Qué cobarde es!$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
	.string "¡Me daba tanta pena, que decidí\n"
	.string "ocuparme de él!$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
	.string "¡El TEAM ROCKET quiere conquistar\n"
	.string "el mundo con sus POKéMON!$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
	.string "¡El TEAM ROCKET se escapó\n"
	.string "por tu culpa!$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
	.string "Deben de haber elegido SILPH\n"
	.string "por nuestros productos POKéMON.$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
	.string "¡Ven a trabajar para SILPH cuando\n"
	.string "seas mayor!$"

SilphCo_6F_Text_Grunt1Intro::
	.string "¡Soy uno de los 4 HERMANOS\n"
	.string "ROCKET!$"

SilphCo_6F_Text_Grunt1Defeat::
	.string "¡Qué paliza!$"

SilphCo_6F_Text_Grunt1PostBattle::
	.string "¡No importa!\n"
	.string "¡Mis hermanos me vengarán!$"

SilphCo_6F_Text_TaylorIntro::
	.string "No puedo con el PRESIDENTE...\p"
	.string "¡No debía haberme enviado a la\n"
	.string "SUCURSAL TIKSI!\p"
	.string "¡Seguro que el TEAM ROCKET\n"
	.string "nos habría dejado en paz!$"

SilphCo_6F_Text_TaylorDefeat::
	.string "¡Ayah!$"

SilphCo_6F_Text_TaylorPostBattle::
	.string "¿La SUCURSAL TIKSI?\n"
	.string "¡Está en medio de la nada!$"

SilphCo_6F_Text_Grunt2Intro::
	.string "¿Te atreves a traicionar al TEAM\n"
	.string "ROCKET?$"

SilphCo_6F_Text_Grunt2Defeat::
	.string "¡Debería darte vergüenza!$"

SilphCo_6F_Text_Grunt2PostBattle::
	.string "¡Si defiendes la justicia,\n"
	.string "traicionas a los malos!$"

SilphCo_6F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P5$"

