Route33_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY_HNS, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten, Route33_EventScript_RegisterAnthony
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route33_EventScript_RematchAnthony
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_RegisterAnthony::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route33_Text_AnthonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANTHONY_HNS
	release
	end

Route33_EventScript_RematchAnthony::
	trainerbattle_rematch TRAINER_ANTHONY_HNS, Route33_Text_AnthonyRematchIntro, Route33_Text_AnthonyRematchDefeat
	msgbox Route33_Text_AnthonyPostRematch, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "He cruzado el túnel, pero todavía me\n"
	.string "quedan muchas energías.$"

Route33_Text_HikerAnthony2Beaten:
	.string "¡Guau! ¡Tienes más fuerza que yo!$"

Route33_Text_HikerAnthony2After:
	.string "Los Montañeros somos felices en las\n"
	.string "montañas.$"

Route33_Text_AnthonyRegister:
	.string "Los Montañeros somos felices en las\n"
	.string "montañas.$"

Route33_Text_AnthonyRematchIntro:
	.string "He cruzado el túnel, pero todavía me\n"
	.string "quedan muchas energías.$"

Route33_Text_AnthonyRematchDefeat:
	.string "¡Guau! ¡Tienes más fuerza que yo!$"

Route33_Text_AnthonyPostRematch:
	.string "Los Montañeros somos felices en las\n"
	.string "montañas.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "¿Conseguiste un DUNSPARCE?\p"
	.string "Yo también.\p"
	.string "Míralo a la luz. ¡Pone una cara muy\n"
	.string "divertida!$"

Route33_Text_Lass:
	.string "Uf, uf…\p"
	.string "Esa cueva era más grande de lo que\n"
	.string "pensaba.\p"
	.string "Me he cansado mucho buscando MARILL,\n"
	.string "así que he salido.$"
