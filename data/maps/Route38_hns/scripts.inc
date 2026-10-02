Route38_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY_HNS, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD_HNS, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten, Route38_EventScript_RegisterChad
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchChad
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHAD_HNS
	release
	end

Route38_EventScript_RematchChad::
	trainerbattle_rematch TRAINER_CHAD_HNS, Route38_Text_ChadRematchIntro, Route38_Text_ChadRematchDefeat
	msgbox Route38_Text_ChadPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA_HNS, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten, Route38_EventScript_RegisterDana
	goto_if_set FLAG_DANA_HAS_ITEM_HNS, Route38_EventScript_DanaGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchDana
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterDana::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_DanaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DANA_HNS
	release
	end

Route38_EventScript_RematchDana::
	trainerbattle_rematch TRAINER_DANA_HNS, Route38_Text_DanaRematchIntro, Route38_Text_DanaRematchDefeat
	msgbox Route38_Text_DanaPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaGiveItem::
	msgbox Route38_Text_DanaHasItem, MSGBOX_DEFAULT
	giveitem VAR_DANA_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route38_EventScript_DanaNoRoom
	clearflag FLAG_DANA_HAS_ITEM_HNS
	msgbox Route38_Text_DanaGaveItem, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaNoRoom::
	msgbox Route38_Text_DanaNoRoom, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_HNS, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY_HNS, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_HNS, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "¡Vuela alto hacia el cielo, querido\n"
	.string "pájaro POKéMON!$"

Route38_Text_BirdKeeperTobyBeaten:
	.string "¡Me apetece salir volando ahora!$"

Route38_Text_BirdKeeperTobyAfter:
	.string "Pienso entrenarme en CIUDAD ORQUÍDEA\p"
	.string "y enseñar a volar a mis POKéMON.$"

Route38_Text_SchoolboyChad1Seen:
	.string "Déjame probar algo que he aprendido\n"
	.string "hoy.$"

Route38_Text_SchoolboyChad1Beaten:
	.string "Creo que no estudié bastante.$"

Route38_Text_SchoolboyChadAfter:
	.string "Tengo que hacer muchos exámenes y no\n"
	.string "tengo tiempo para los POKéMON.\p"
	.string "Así que, cuando puedo jugar, me\n"
	.string "concentro mucho.$"

Route38_Text_ChadRegister:
	.string "Tengo que hacer muchos exámenes y no\n"
	.string "tengo tiempo para los POKéMON.\p"
	.string "Así que, cuando puedo jugar, me\n"
	.string "concentro mucho.$"

Route38_Text_ChadRematchIntro:
	.string "Déjame probar algo que he aprendido\n"
	.string "hoy.$"

Route38_Text_ChadRematchDefeat:
	.string "Creo que no estudié bastante.$"

Route38_Text_ChadPostRematch:
	.string "Tengo que hacer muchos exámenes y no\n"
	.string "tengo tiempo para los POKéMON.\p"
	.string "Así que, cuando puedo jugar, me\n"
	.string "concentro mucho.$"

Route38_Text_LassDana1Seen:
	.string "Parece que sabes de POKéMON.\p"
	.string "Si es así, ¿por qué no me das algún\n"
	.string "consejo?$"

Route38_Text_LassDana1Beaten:
	.string "Ya veo. De modo que luchas así.$"

Route38_Text_LassDanaAfter:
	.string "¡Tengo una buena noticia!\p"
	.string "La leche de la GRANJA MUU-MUU\p"
	.string "es famosa por su sabor.$"

Route38_Text_BeautyValerieSeen:
	.string "¡Hola! ¡Tienes buen aspecto!\p"
	.string "¿Me dejas ver a tus POKéMON?$"

Route38_Text_BeautyValerieBeaten:
	.string "Encantada de haber visto tu equipo\n"
	.string "POKéMON.$"

Route38_Text_BeautyValerieAfter:
	.string "Cuando veo POKéMON me tranquilizo.$"

Route38_Text_SailorHarrySeen:
	.string "He estado en el extranjero. ¡Así que\n"
	.string "conozco todo tipo de POKéMON!$"

Route38_Text_SailorHarryBeaten:
	.string "¡Tu destreza es de categoría mundial!$"

Route38_Text_SailorHarryAfter:
	.string "Gentes de todo el mundo viven felices\n"
	.string "con los POKéMON.$"

Route38_Text_BeautyOliviaSeen:
	.string "¿No te parece que mis POKéMON y yo\n"
	.string "somos preciosos?$"

Route38_Text_BeautyOliviaBeaten:
	.string "Bebemos LECHE MU-MU a diario.$"

Route38_Text_BeautyOliviaAfter:
	.string "La LECHE MU-MU es buena para la\n"
	.string "belleza y la salud,\p"
	.string "pero, por desgracia, solo venden una\n"
	.string "botella cada vez.$"

Route38_Text_Sign:
	.string "RUTA 38\p"
	.string "CIUDAD OLIVO - CIUDAD IRIS$"

Route38_Text_TrainerTips:
	.string "PISTAS para ENTRENADORES\p"
	.string "Si un POKéMON intenta evolucionar,\n"
	.string "puedes impedirlo.\p"
	.string "Pulsa el Botón B durante la evolución\n"
	.string "para cancelarla.\p"
	.string "Eso sobresalta al POKéMON y detiene\n"
	.string "su evolución.$"


Route38_Text_WaterSign:
	.string "PROHIBIDO NADAR Y PESCAR.\n"
	.string "AGUA SOLO PARA LA GRANJA.\p"
	.string "- AYUNTAMIENTO DE CIUDAD IRIS$"

Route38_Text_DanaRegister:
	.string "¡Tengo una buena noticia!\p"
	.string "La leche de la GRANJA MUU-MUU\p"
	.string "es famosa por su sabor.$"

Route38_Text_DanaRematchIntro:
	.string "Parece que sabes de POKéMON.\p"
	.string "Si es así, ¿por qué no me das algún\n"
	.string "consejo?$"

Route38_Text_DanaRematchDefeat:
	.string "Ya veo. De modo que luchas así.$"

Route38_Text_DanaPostRematch:
	.string "¡Tengo una buena noticia!\p"
	.string "La leche de la GRANJA MUU-MUU\p"
	.string "es famosa por su sabor.$"

Route38_Text_DanaHasItem:
	.string "¡Eh! ¡He encontrado algo interesante!\p"
	.string "¡Toma, para ti!$"

Route38_Text_DanaGaveItem:
	.string "¡Te avisaré si encuentro algo más!$"

Route38_Text_DanaNoRoom:
	.string "Mmm, tienes la MOCHILA llena.\p"
	.string "Vuelve cuando tengas sitio.$"
