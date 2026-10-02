Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "ANA: ¡ANY y yo estamos en esto juntas!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "ANA-ANY: Nnn… Demasiado fuerte.$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "ANA: Sé lo que están pensando mi\n"
	.string "hermana y mis POKéMON.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "ANY: ¡ANA y yo estamos en esto juntas!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "ANA-ANY: Nnn… Demasiado fuerte.$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "ANY: Sentimos lo mismo que nuestros\n"
	.string "POKéMON.$"

Route37_Text_PsychicGreg_Seen:
	.string "Los POKéMON no pueden hacer nada\n"
	.string "dormidos.\p"
	.string "¡Yo te enseñaré el miedo que da eso!$"

Route37_Text_PsychicGreg_Beaten:
	.string "He perdido. ¡Qué pena…!$"

Route37_Text_PsychicGreg_After:
	.string "Dormir o paralizar a los POKéMON son\n"
	.string "buenas técnicas de lucha.$"

Route37_Text_Sunny_Meet:
	.string "SUNNY: Hi!\p"
	.string "I'm SUNNY of the WEEKDAY family!\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"

Route37_Text_Sunny_GiveGift1:
	.string "¡Me dijeron que te entregara esto si\n"
	.string "te veía!$"

Route37_Text_Sunny_GiveGift2:
	.string "¡Me dijeron que te entregara esto si\n"
	.string "te veía!$"

Route37_Text_Sunny_GaveGift:
	.string "DOMINGO: Eso…\p"
	.string "¡Um…!\p"
	.string "¿Qué era…?\p"
	.string "…\p"
	.string "¡Ah! ¡Ahora lo recuerdo!\p"
	.string "Debería llevarlo un POKéMON con\n"
	.string "habilidades eléctricas.\p"
	.string "¡Mi hermana LUNA dice que mejora las\n"
	.string "habilidades eléctricas!$"

Route37_Text_Sunny_Sunday:
	.string "DOMINGO: Mis hermanos son LUNA,\n"
	.string "MARTA, MIGUEL, JOSUÉ, VICKI y SABINO.\p"
	.string "¡Son todos mayores que yo!$"

Route37_Text_Sunny_NotSunday:
	.string "DOMINGO: ¿Hoy no es domingo? ¡Um…! ¡Lo\n"
	.string "olvidé!$"

Route37_Text_Sign:
	.string "ROUTE 37\n"
	.string "ECRUTEAK CITY AHEAD$"
