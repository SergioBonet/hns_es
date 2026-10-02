Route12_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN_HNS, Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN_HNS, Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_HNS, Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE_HNS, Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten, Route12_EventScript_RegisterKyle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_RematchKyle
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RegisterKyle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_KyleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLE_HNS
	release
	end

Route12_EventScript_RematchKyle::
	trainerbattle_rematch TRAINER_KYLE_HNS, Route12_Text_KyleRematchIntro, Route12_Text_KyleRematchDefeat
	msgbox Route12_Text_KylePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KYLE_2_HNS, Route12_EventScript_RematchKyleTryGiveItem
	end

Route12_EventScript_RematchKyleTryGiveItem::
	checkitem ITEM_BLUE_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_BLUE_SHARD
	closemessage
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Magikarp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route12_Text_Magikarp, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_Magikarp:
	.string "MAGIKARP: Kaaaarp.$"

Route12_Text_NewFisher:
	.string "Careful, something vicious lives in\n"
	.string "these waters.$"

Route12_Text_FisherMartinSeen:
	.string "La paciencia es la clave para pescar y\n"
	.string "criar POKéMON.$"

Route12_Text_FisherMartinBeaten:
	.string "¡Guaaa!$"

Route12_Text_FisherMartinAfterBattle:
	.string "No tengo paciencia para la pesca…$"

Route12_Text_FisherStephenSeen:
	.string "Me gusta pescar mientras escucho\n"
	.string "canciones por la radio.$"

Route12_Text_FisherStephenBeaten:
	.string "¡Mi estúpida radio me ha distraído!$"

Route12_Text_FisherStephenAfterBattle:
	.string "¿Conoces las emisoras de radio de\n"
	.string "KANTO? Tenemos muchas.$"

Route12_Text_FisherBarneySeen:
	.string "¿Qué es lo más importante en nuestras\n"
	.string "vidas?$"

Route12_Text_FisherBarneyBeaten:
	.string "¡La respuesta vendrá luego!$"

Route12_Text_FisherBarneyAfterBattle:
	.string "I think electricity is the most\n"
	.string "important thing in our daily\l"
	.string "lives.\p"
	.string "If it weren't, people wouldn't\n"
	.string "have made such a fuss when the\l"
	.string "POWER PLANT went out of\l"
	.string "commission.$"

Route12_Text_KyleRegister:
	.string "I'll remember this.\n"
	.string "Give me your number!$"

Route12_Text_KyleRematchIntro:
	.string "Did you forget?\n"
	.string "Let's see!$"

Route12_Text_KyleRematchDefeat:
	.string "You remembered.$"

Route12_Text_KylePostRematch:
	.string "The thrill of battle is almost\n"
	.string "as good as a big catch!$"

Route12_Text_FisherKyleSeen:
	.string "¿Te acuerdas?$"

Route12_Text_FisherKyleBeaten:
	.string "Te acuerdas, ¿no?$"

Route12_Text_FisherKyleAfterBattle:
	.string "The tug you feel on the ROD when\n"
	.string "you hook a POKéMON…\p"
	.string "That's the best feeling ever for\n"
	.string "an angler like me.$"

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "RUTA 12\p"
	.string "PUEBLO LAVANDA HACIA EL NORTE$"

Route12_Text_FishingSpotSign:
	.string "COTO DE PESCA$"

