Route2_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_Carbos::
    finditem ITEM_CARBOS
    end

Route2_EventScript_Nugget::
    finditem ITEM_NUGGET
    end

Route2_Text_RobRegister:
	.string "Let me get your number!$"

Route2_Text_RobRematchIntro:
	.string "I've caught even more bugs!\n"
	.string "Check them out!$"

Route2_Text_RobRematchDefeat:
	.string "I need better bugs!$"

Route2_Text_RobPostRematch:
	.string "I caught every bug in VIRIDIAN.\n"
	.string "Is there a better FOREST somewhere?$"

Route2_Text_BugCatcherRob_Seen:
	.string "Mis POKéMON bicho son muy fuertes.\p"
	.string "¡Prepárate para perder!$"

Route2_Text_BugCatcherRob_Beaten:
	.string "Me vencieron…$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "Voy a buscar POKéMON bicho más\n"
	.string "fuertes.$"

Route2_Text_BugCatcherEd_Seen:
	.string "Si caminas por la hierba alta con\n"
	.string "pantalones cortos, ¿no te arañas?\p"
	.string "$"

Route2_Text_BugCatcherEd_Beaten:
	.string "¡Au, au, au!$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "Seguro que te pican si te bañas.$"

Route2_Text_BugCatcherDoug_Seen:
	.string "¿Por qué a las chicas no les gustan\n"
	.string "los POKéMON bicho?$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "¡Muy mal!$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "Los POKéMON bicho parecen muñecos de\n"
	.string "goma cuando les aprietas la tripa.\p"
	.string "¡Me encanta tocarlos!$"

Route2_Text_Sign:
	.string "ROUTE 2\p"
	.string "VIRIDIAN CITY - PEWTER CITY$"

Route2_Text_DiglettsCaveSign:
	.string "CUEVA DIGLETT$"

