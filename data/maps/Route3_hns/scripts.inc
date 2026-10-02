Route3_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS_HNS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN_HNS, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY_HNS, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT_HNS, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "¡Ah! Hace un tiempo estupendo.$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "Hace sol, pero estoy mojado…$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "Cuando llueve, es difícil encenderlo…$"

Route3_Text_YoungsterWarren_Seen:
	.string "¡Mmm…! No sé qué hacer…$"

Route3_Text_YoungsterWarren_Beaten:
	.string "Sabía que perdería…$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "Como parecías fuerte, me daba miedo\n"
	.string "desafiarte…$"

Route3_Text_YoungsterJimmy_Seen:
	.string "¡Puedo correr como el viento!$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "¡He perdido!$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "Siempre llevo pantalones cortos.\p"
	.string "Ésa es mi forma de vestir.$"

Route3_Text_FirebreatherBurt_Seen:
	.string "¡Sube y echa un vistazo!$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "¡Uh! ¡Eso quema!$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "Soy el mejor COMEFUEGO de Kanto… pero\n"
	.string "no el mejor ENTRENADOR.$"

Route3_Text_MtMoonSquareSign:
	.string "PLAZA MT. MOON\p"
	.string "Sube las escaleras$"

