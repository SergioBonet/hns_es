Route45_hns_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK_HNS, Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL_HNS, Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY_HNS, Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten, Route45_EventScript_RegisterParry
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchParry
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterParry::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_ParryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PARRY_HNS
	release
	end

Route45_EventScript_RematchParry::
	trainerbattle_rematch TRAINER_PARRY_HNS, Route45_Text_ParryRematchIntro, Route45_Text_ParryRematchDefeat
	msgbox Route45_Text_ParryPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_HNS, Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI_HNS, Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten, Route45_EventScript_RegisterKenji
	goto_if_set FLAG_KENJI_HAS_ITEM_HNS, Route45_EventScript_KenjiGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchKenji
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterKenji::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_KenjiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENJI_HNS
	release
	end

Route45_EventScript_RematchKenji::
	trainerbattle_rematch TRAINER_KENJI_HNS, Route45_Text_KenjiRematchIntro, Route45_Text_KenjiRematchDefeat
	msgbox Route45_Text_KenjiPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiGiveItem::
	msgbox Route45_Text_KenjiHasItem, MSGBOX_DEFAULT
	giveitem VAR_KENJI_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route45_EventScript_KenjiNoRoom
	clearflag FLAG_KENJI_HAS_ITEM_HNS
	msgbox Route45_Text_KenjiGaveItem, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiNoRoom::
	msgbox Route45_Text_KenjiNoRoom, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN_HNS, Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY_HNS, Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN_HNS, Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
	.string "¡Prepárate para cualquier cosa!\p"
	.string "¡Déjame ver si has entrenado bien a\n"
	.string "tus POKéMON!$"

Route45_Text_HikerErikBeaten:
	.string "¡Oh, he perdido!$"

Route45_Text_HikerErikAfter:
	.string "Volveré a la RUTA HELADA de Ciudad\n"
	.string "Endrino y seguiré entrenándome.$"

Route45_Text_HikerMichaelSeen:
	.string "¡Eres valiente! Pero…\p"
	.string "¿Sabes qué? Para valiente, ¡yo!$"

Route45_Text_HikerMichaelBeaten:
	.string "¡A mis POKéMON les faltaron agallas!$"

Route45_Text_HikerMichaelAfter:
	.string "¡Cómo me gusta MÁS PS! ¡Mmmm!\p"
	.string "¡Me bebo la de mis POKéMON!\p"
	.string "No puedo evitarlo.$"

Route45_Text_HikerParrySeen:
	.string "¡Mis POKéMON son muy poderosos!$"

Route45_Text_HikerParryBeaten:
	.string "¡Buaaaaa! ¡Soy un perdedor!$"

Route45_Text_HikerParryAfter:
	.string "No se me da muy bien pensar.\p"
	.string "¡Así que utilizo sólo la fuerza!$"

Route45_Text_ParryRegister:
	.string "No se me da muy bien pensar.\p"
	.string "¡Así que utilizo sólo la fuerza!$"

Route45_Text_ParryRematchIntro:
	.string "¡Mis POKéMON son muy poderosos!$"

Route45_Text_ParryRematchDefeat:
	.string "¡Buaaaaa! ¡Soy un perdedor!$"

Route45_Text_ParryPostRematch:
	.string "No se me da muy bien pensar.\p"
	.string "¡Así que utilizo sólo la fuerza!$"

Route45_Text_HikerTimothySeen:
	.string "¿Que por qué escalo montañas?\p"
	.string "Porque están ahí.\p"
	.string "¿Que por qué entreno POKéMON?\p"
	.string "¡Porque están ahí!$"

Route45_Text_HikerTimothyBeaten:
	.string "Las derrotas… ¡son inevitables!$"

Route45_Text_HikerTimothyAfter:
    .string "The best thing to ever happen to\n"
    .string "me was discovering POKéMON.$"

Route45_Text_HikerParryGivesIron:
    .string "I just can't find a way to win!\p"
    .string "Keep it up!\p"
    .string "Oh, and take this -- it's the\n"
    .string "gift you couldn't take when we\n"
    .string "last met.$"

Route45_Text_BlackbeltKenjiSeen:
	.string "Estaba entrenando aquí solo.\p"
	.string "¡Observa el fruto de mi trabajo!$"

Route45_Text_BlackbeltKenjiBeaten:
	.string "¡Waaaargh!$"

Route45_Text_BlackbeltKenjiAfter:
	.string "Esto requiere medidas extremas.\p"
	.string "Debo ir a los montes y entrenarme allí,\n"
	.string "en soledad.$"

Route45_Text_KenjiRegister:
	.string "Esto requiere medidas extremas.\p"
	.string "Debo ir a los montes y entrenarme allí,\n"
	.string "en soledad.$"

Route45_Text_KenjiRematchIntro:
	.string "Estaba entrenando aquí solo.\p"
	.string "¡Observa el fruto de mi trabajo!$"

Route45_Text_KenjiRematchDefeat:
	.string "¡Waaaargh!$"

Route45_Text_KenjiPostRematch:
	.string "Esto requiere medidas extremas.\p"
	.string "Debo ir a los montes y entrenarme allí,\n"
	.string "en soledad.$"

Route45_Text_KenjiHasItem:
    .string "Hey! I'm taking a break from\n"
    .string "training.\p"
    .string "I found something good while I\n"
    .string "was out. Here, take it!$"

Route45_Text_KenjiGaveItem:
    .string "Use it well!\p"
    .string "I need to get back to my\n"
    .string "training. Oooooaaarrrgh!$"

Route45_Text_KenjiNoRoom:
    .string "Hmm, your BAG is full.\p"
    .string "Come back when you have room.$"

Route45_Text_BlackbeltKenjiMorning:
    .string "I'm going to train a bit more\n"
    .string "before I break for lunch.$"

Route45_Text_BlackbeltKenjiNight:
    .string "We had plenty of rest at lunch, so\p"
    .string "now we're all ready to go again!\p"
    .string "We're going to train again!$"

Route45_Text_CooltrainermRyanSeen:
	.string "¿Qué piensas sobre la educación de\n"
	.string "los POKéMON?$"

Route45_Text_CooltrainermRyanBeaten:
	.string "Te has ganado mi respeto.$"

Route45_Text_CooltrainermRyanAfter:
	.string "Veo que entrenas tus POKéMON con\n"
	.string "cariño.\p"
	.string "El vínculo que os une os salvará en\n"
	.string "las situaciones difíciles.$"

Route45_Text_CooltrainerfKellySeen:
	.string "¿Cuál es tu estrategia?\p"
	.string "Es de tontos usar movimientos\n"
	.string "fuertes de forma indiscriminada.$"

Route45_Text_CooltrainerfKellyBeaten:
	.string "Vale. He perdido.$"

Route45_Text_CooltrainerfKellyAfter:
    .string "I'm not in favor of overly\n"
    .string "powerful moves.\p"
    .string "I want to win, but I also don't\n"
    .string "want to harm POKéMON.$"

Route45_Text_CamperQuentinSeen:
	.string "¡Soy muy, muy fuerte!$"

Route45_Text_CamperQuentinBeaten:
    .string "I was tough at the TRAINER HILL…$"

Route45_Text_CamperQuentinAfter:
    .string "Have you been to the TRAINER HILL?\p"
    .string "I never, ever lose there, but…$"

Route45_Text_Sign:
	.string "RUTA 45 CAMINO MONTAÑA$"
