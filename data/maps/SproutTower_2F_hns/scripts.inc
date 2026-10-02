SproutTower_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO_HNS, SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND_HNS, SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "Por mucho que luchemos, la TORRE\n"
	.string "seguirá en pie.$"

SproutTower_Text_SageNico_Beaten:
	.string "Luché con fuerza, pero estoy débil.$"

SproutTower_Text_SageNico_AfterBattle:
	.string "La columna flexible protege la TORRE\n"
	.string "hasta de los terremotos.$"

SproutTower_Text_SageEdmond_Seen:
	.string "… Cimbréate como las hojas al viento…$"

SproutTower_Text_SageEdmond_Beaten:
	.string "¡Oh, estoy débil!$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "Quería imitar los suaves movimientos\n"
	.string "de BELLSPROUT para pelear…\p"
	.string "Pero no me entrené lo suficiente.$"

SproutTower_Text_2F_Statue:
	.string "Estatua POKéMON…\p"
	.string "Parece muy ilustre.$"
