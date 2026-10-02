Route46_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY_HNS, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED_HNS, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN_HNS, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten, Route46_EventScript_RegisterErin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route46_EventScript_RematchErin
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_RegisterErin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_ErinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ERIN_HNS
	release
	end

Route46_EventScript_RematchErin::
	trainerbattle_rematch TRAINER_ERIN_HNS, Route46_Text_ErinRematchIntro, Route46_Text_ErinRematchDefeat
	msgbox Route46_Text_ErinPostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "De acuerdo. ¡Te enseñaré el poder de\n"
	.string "los POKéMON de montaña!$"

Route46_Text_HikerBaileyBeaten:
	.string "¡Me has demostrado tu poder!$"

Route46_Text_HikerBaileyAfterBattle:
	.string "Se acabó, pero no me importa.\p"
	.string "Los MONTAÑEROS somos así.$"

Route46_Text_CamperTedSeen:
	.string "¡Yo también entreno POKéMON!\p"
	.string "¿Quieres luchar contra mí?$"

Route46_Text_CamperTedBeaten:
	.string "¿Qué…?$"

Route46_Text_CamperTedAfterBattle:
	.string "Hice lo que pude pero no sirvió.\p"
	.string "No hay excusa que valga. He perdido.$"

Route46_Text_PicnickerErinSeen:
	.string "¡Yo también entreno POKéMON!\p"
	.string "¿Quieres luchar contra mí?$"

Route46_Text_PicnickerErinBeaten:
	.string "¡Oh, narices!$"

Route46_Text_PicnickerErinAfterBattle:
	.string "He estado en muchos GIMNASIOS, pero\n"
	.string "el de TRIGAL es mi favorito.\p"
	.string "¡Está lleno de flores preciosas!$"

Route46_Text_ErinRegister:
	.string "He estado en muchos GIMNASIOS, pero\n"
	.string "el de TRIGAL es mi favorito.\p"
	.string "¡Está lleno de flores preciosas!$"

Route46_Text_ErinRematchIntro:
	.string "¡Yo también entreno POKéMON!\p"
	.string "¿Quieres luchar contra mí?$"

Route46_Text_ErinRematchDefeat:
	.string "¡Oh, narices!$"

Route46_Text_ErinPostRematch:
	.string "He estado en muchos GIMNASIOS, pero\n"
	.string "el de TRIGAL es mi favorito.\p"
	.string "¡Está lleno de flores preciosas!$"

Route46_Text_PicnickerErin2Beaten:
	.string "Auuuu… ¡Pierdo siempre! ¡Sólo tengo\n"
	.string "que seguir intentándolo!\p"
	.string "Bueno, gracias por luchar conmigo una\n"
	.string "y otra vez. Toma este regalo de la\l"
	.string "última vez.$"

Route46_Text_Sign:
	.string "RUTA 46 CAMINO MONTAÑA$"
