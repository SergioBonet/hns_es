Route17_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY_HNS, Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten, Route17_EventScript_RegisterRiley
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchRiley
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterRiley::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_RileyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RILEY_HNS
	release
	end

Route17_EventScript_RematchRiley::
	trainerbattle_rematch TRAINER_RILEY_HNS, Route17_Text_RileyRematchIntro, Route17_Text_RileyRematchDefeat
	msgbox Route17_Text_RileyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_RILEY_2_HNS, Route17_EventScript_RematchRileyTryGiveItem
	end

Route17_EventScript_RematchRileyTryGiveItem::
	checkitem ITEM_TM_TOXIC
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_TOXIC
	closemessage
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL_HNS, Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten, Route17_EventScript_RegisterJoel
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchJoel
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterJoel::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_JoelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEL_HNS
	release
	end

Route17_EventScript_RematchJoel::
	trainerbattle_rematch TRAINER_JOEL_HNS, Route17_Text_JoelRematchIntro, Route17_Text_JoelRematchDefeat
	msgbox Route17_Text_JoelPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_JOEL_2_HNS, Route17_EventScript_RematchJoelTryGiveItem
	end

Route17_EventScript_RematchJoelTryGiveItem::
	checkitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BRICK_BREAK
	closemessage
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN_HNS, Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES_HNS, Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten, Route17_EventScript_RegisterCharles
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchCharles
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterCharles::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_CharlesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHARLES_HNS
	release
	end

Route17_EventScript_RematchCharles::
	trainerbattle_rematch TRAINER_CHARLES_HNS, Route17_Text_CharlesRematchIntro, Route17_Text_CharlesRematchDefeat
	msgbox Route17_Text_CharlesPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CHARLES_2_HNS, Route17_EventScript_RematchCharlesTryGiveItem
	end

Route17_EventScript_RematchCharlesTryGiveItem::
	checkitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BULK_UP
	closemessage
	end

Route17_Text_BikerRileySeen:
	.string "¡Eh, tú! Eres de JOHTO, ¿verdad?$"

Route17_Text_BikerRileyBeaten:
	.string "¡Venga, golpea!$"

Route17_Text_BikerRileyAfterBattle:
	.string "¡No te pases, que esto no es JOHTO!$"

Route17_Text_BikerJoelSeen:
	.string "¡Uau! ¡Qué BICI más guay!$"

Route17_Text_BikerJoelBeaten:
	.string "Pero tú no pareces guay…$"

Route17_Text_BikerJoelAfterBattle:
	.string "Soy guay, pero estoy débil. Por eso no\n"
	.string "lo parezco.\p"
	.string "Debería entrenar mucho más…$"

Route17_Text_BikerGlennSeen:
	.string "¡Eh! ¿Un combate rapidito?$"

Route17_Text_BikerGlennBeaten:
	.string "¡Vaya! ¡Qué vitalidad!$"

Route17_Text_BikerGlennAfterBattle:
	.string "Montar sin manos en el CAMINO de\n"
	.string "BICIS es muy guay.$"

Route17_Text_BikerCharlesSeen:
	.string "¡Somos estrellas de la carretera!\p"
	.string "$"

Route17_Text_BikerCharlesBeaten:
	.string "¡Arrrg! ¡Chocar y arder!$"

Route17_Text_BikerCharlesAfterBattle:
	.string "¡Conducir de forma imprudente causa\n"
	.string "accidentes! ¡Ten cuidado!$"

Route17_Text_RileyRegister:
	.string "Not bad for a JOHTO kid!$"

Route17_Text_RileyRematchIntro:
	.string "JOHTO punks can only win once!$"

Route17_Text_RileyRematchDefeat:
	.string "I got kicked...$"

Route17_Text_RileyPostRematch:
	.string "Maybe I should train in JOHTO\n"
	.string "after all.$"

Route17_Text_JoelRegister:
	.string "You're pretty cool after all!\n"
	.string "Let's trade numbers!$"

Route17_Text_JoelRematchIntro:
	.string "Let's see who's cooler now!$"

Route17_Text_JoelRematchDefeat:
	.string "Still not cool enough…$"

Route17_Text_JoelPostRematch:
	.string "I'll keep training to be as cool\n"
	.string "as you, kid!$"

Route17_Text_CharlesRegister:
	.string "You're a heartbreaker like me, kid!\n"
	.string "Give me your number!$"

Route17_Text_CharlesRematchIntro:
	.string "I'm not just a highway star,\n"
	.string "I'm a heartbreaker!$"

Route17_Text_CharlesRematchDefeat:
	.string "Crashed and burned again!$"

Route17_Text_CharlesPostRematch:
	.string "I met a trainer like you in UNOVA.\n"
	.string "Don't crash out!$"

