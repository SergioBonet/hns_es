Route11_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN_HNS, Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON_HNS, Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN_HNS, Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL_HNS, Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_EventScript_Item_Grass_Knot::
    finditem ITEM_TM_GRASS_KNOT
    end

Route11_Text_Engineer:
	.string "I saw a strange POKéMON climbing\n"
	.string "in the trees, but it didn't\l"
	.string "look like MANKEY...$"

Route11_Text_YoungsterOwenSeen:
	.string "There's no cheating in POKéMON.\p"
	.string "Let's keep it fair and square!$"

Route11_Text_YoungsterOwenBeaten:
	.string "¿Qué? ¿Cómo ha podido ocurrir?$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "He luchado con honor.\p"
	.string "No me avergüenzo.$"

Route11_Text_YoungsterJasonSeen:
	.string "Cuando llevo pantalones cortos por la\n"
	.string "hierba, me pican las piernas.$"

Route11_Text_YoungsterJasonBeaten:
	.string "¡Ayyyy! ¡Me han pisado!$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "Voy a capturar más POKéMON en la\n"
	.string "hierba.$"

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "…\p"
	.string "Perdí cuando tenía los ojos cerrados.$"

Route11_Text_PsychicFidelSeen:
	.string "Ya veo…\p"
	.string "Todo lo que hay que ver de ti…$"

Route11_Text_PsychicFidelBeaten:
	.string "No me imaginaba tu poder…$"

Route11_Text_PsychicFidelAfterBattle:
	.string "Fuerza de convicción…\p"
	.string "Eres fuerte porque confías en tus\n"
	.string "POKéMON.$"

Route11_Text_Sign:
	.string "RUTA 11$"

