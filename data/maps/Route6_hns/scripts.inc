Route6_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route6_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route6_EventScript_Rex::
	trainerbattle_single TRAINER_REX_HNS, PokefanM_Text_RexSeen, PokefanM_Text_RexBeaten
	msgbox PokefanM_Text_RexAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Allan::
	trainerbattle_single TRAINER_ALLAN_HNS, PokefanM_Text_AllanSeen, PokefanM_Text_AllanBeaten
	msgbox PokefanM_Text_AllanAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Pokefan::
	msgbox Route6_Text_PokefanM, MSGBOX_NPC
	end

Route6_EventScript_Sign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_EventScript_Item_Silver_Wind::
    finditem ITEM_TM_SILVER_WIND
    end

Route6_Text_PokefanM:
	.string "La carretera está cortada hasta que\n"
	.string "arreglen la CENTRAL ENERGÍA.$"

Route6_Text_UndergroundPathSign:
	.string "VÍA SUBTERRÁNEA\p"
	.string "CIUDAD CELESTE - CIUDAD CARMÍN$"

PokefanM_Text_RexSeen:
	.string "Mi STANTLER es el más mono del mundo.$"

PokefanM_Text_RexBeaten:
	.string "¡Mi STANTLER!$"

PokefanM_Text_RexAfter:
	.string "¡Mira qué adorable es mi STANTLER!\p"
	.string "¿A que es tan mono que te derrite el\n"
	.string "corazón?$"

PokefanM_Text_AllanSeen:
	.string "Mi GRANBULL es el más mono del mundo.$"

PokefanM_Text_AllanBeaten:
	.string "¡Mi GRANBULL!$"

PokefanM_Text_AllanAfter:
	.string "¡Mira qué adorable es mi GRANBULL!\p"
	.string "¿A que es tan mono que te derrite el\n"
	.string "corazón?$"

