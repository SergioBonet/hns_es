Route44_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_HNS, Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten, Route44_EventScript_RegisterWilton
	goto_if_set FLAG_WILTON_HAS_ITEM_HNS, Route44_EventScript_WiltonGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchWilton
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_HNS
	release
	end

Route44_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_HNS, Route44_Text_WiltonRematchIntro, Route44_Text_WiltonRematchDefeat
	msgbox Route44_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonGiveItem::
	msgbox Route44_Text_WiltonHasItem, MSGBOX_DEFAULT
	giveitem VAR_WILTON_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route44_EventScript_WiltonNoRoom
	clearflag FLAG_WILTON_HAS_ITEM_HNS
	msgbox Route44_Text_WiltonGaveItem, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonNoRoom::
	msgbox Route44_Text_WiltonNoRoom, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR_HNS, Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE_HNS, Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten, Route44_EventScript_RegisterVance
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchVance
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterVance::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_VanceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VANCE_HNS
	release
	end

Route44_EventScript_RematchVance::
	trainerbattle_rematch TRAINER_VANCE_HNS, Route44_Text_VanceRematchIntro, Route44_Text_VanceRematchDefeat
	msgbox Route44_Text_VancePostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL_HNS, Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_HNS, Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN_HNS, Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL_HNS, Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
	.string "¡Me has hecho perder a POLIWAG!\p"
	.string "¿Qué vas a hacer para remediarlo?$"

Route44_Text_FisherWilton1Beaten:
	.string "Simplemente olvídalo.$"

Route44_Text_FisherWiltonHugePoliwag:
	.string "Ese POLIWAG que escapó… Era enorme.\p"
	.string "¡Juraría que medía unos 5 metros!$"

Route44_Text_WiltonRegister:
	.string "Ese POLIWAG que escapó… Era enorme.\p"
	.string "¡Juraría que medía unos 5 metros!$"

Route44_Text_WiltonRematchIntro:
	.string "¡Me has hecho perder a POLIWAG!\p"
	.string "¿Qué vas a hacer para remediarlo?$"

Route44_Text_WiltonRematchDefeat:
	.string "Simplemente olvídalo.$"

Route44_Text_WiltonPostRematch:
	.string "Ese POLIWAG que escapó… Era enorme.\p"
	.string "¡Juraría que medía unos 5 metros!$"

Route44_Text_WiltonHasItem:
	.string "¡Eh! ¡He pescado algo que no es un\n"
	.string "POKéMON!\p"
	.string "¡Toma, para ti!$"

Route44_Text_WiltonGaveItem:
	.string "¡Te avisaré si pesco algo más!$"

Route44_Text_WiltonNoRoom:
	.string "Mmm, tienes la MOCHILA llena.\p"
	.string "Vuelve cuando tengas sitio.$"

Route44_Text_FisherEdgarSeen:
	.string "Pesco hasta que no puedo más, y lucho\n"
	.string "hasta desfallecer.\p"
	.string "Ésta es la relación que tengo con mis\n"
	.string "POKéMON.$"

Route44_Text_FisherEdgarBeaten:
	.string "¡Mmmmm…! Eso no está bien.$"

Route44_Text_FisherEdgarAfter:
	.string "Son 100 victorias y 101 derrotas. No\n"
	.string "lucharé en un rato.$"

Route44_Text_BirdKeeperVance1Seen:
	.string "¿Sabes algo sobre el POKéMON pájaro\n"
	.string "legendario?$"

Route44_Text_BirdKeeperVance1Beaten:
	.string "¡Uauu! Eres el no va más.$"

Route44_Text_BirdKeeperVanceBirds:
	.string "ARTICUNO, ZAPDOS y MOLTRES son los\n"
	.string "tres POKéMON pájaro legendarios.\p"
	.string "Pero he oído que hay otros pájaros\n"
	.string "legendarios.$"

Route44_Text_VanceRegister:
	.string "ARTICUNO, ZAPDOS y MOLTRES son los\n"
	.string "tres POKéMON pájaro legendarios.\p"
	.string "Pero he oído que hay otros pájaros\n"
	.string "legendarios.$"

Route44_Text_VanceRematchIntro:
	.string "¿Sabes algo sobre el POKéMON pájaro\n"
	.string "legendario?$"

Route44_Text_VanceRematchDefeat:
	.string "¡Uauu! Eres el no va más.$"

Route44_Text_VancePostRematch:
	.string "ARTICUNO, ZAPDOS y MOLTRES son los\n"
	.string "tres POKéMON pájaro legendarios.\p"
	.string "Pero he oído que hay otros pájaros\n"
	.string "legendarios.$"

Route44_Text_PsychicPhilSeen:
	.string "¡Voy a ganar! ¡Seguro!$"

Route44_Text_PsychicPhilBeaten:
	.string "¡Arrgh…! No esperaba perder.$"

Route44_Text_PsychicPhilAfter:
	.string "¡Es importante tener confianza en uno\n"
	.string "mismo!$"

Route44_Text_PokemaniacZachSeen:
	.string "¡Haré lo que sea para conseguir\n"
	.string "POKéMON raros!$"

Route44_Text_PokemaniacZachBeaten:
	.string "Oooh, tus POKéMON son muy bonitos.$"

Route44_Text_PokemaniacZachAfter:
	.string "Los POKéMON de colores poco\n"
	.string "habituales tienen más valor.\p"
	.string "¿Qué? ¿Insinúas que no es cierto?$"

Route44_Text_CooltrainermAllenSeen:
	.string "Con sólo mirarte sé cuál es tu nivel.\p"
	.string "Yo soy bueno con los POKéMON y veo\n"
	.string "que tú también.$"

Route44_Text_CooltrainermAllenBeaten:
	.string "¡Vaya! Ha sido una auténtica derrota.$"

Route44_Text_CooltrainermAllenAfter:
	.string "¡Uauu! Tienes muchas MEDALLAS.\p"
	.string "No me extraña que seas tan fuerte.\p"
	.string "Me pregunto si MORTI, de GIMNASIO\p"
	.string "IRIS, estará aún entrenándose.\p"
	.string "Él sí que me dio una paliza.$"

Route44_Text_CooltrainerfCybilSeen:
	.string "Pareces fuerte.\p"
	.string "Los buenos entrenadores siempre\n"
	.string "buscan buenos rivales.$"

Route44_Text_CooltrainerfCybilBeaten:
	.string "¡No! Esto no servirá para nada.$"

Route44_Text_CooltrainerfCybilAfter:
	.string "Todos mejoramos luchando muchas\n"
	.string "veces.\p"
	.string "He luchado mucho para llegar a ser lo\n"
	.string "que soy hoy: una campeona.$"

Route44_Text_Sign1:
	.string "RUTA 44 HACIA RUTA HELADA$"

Route44_Text_Sign2:
	.string "RUTA 44\p"
	.string "PUEBLO CAOBA - CIUDAD ENDRINO$"

