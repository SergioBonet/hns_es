SaffronCity_Dojo_Frlg_MapScripts::
	.byte 0

SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleeBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONLEE, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONCHAN, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon::
	hidemonpic
	givemon VAR_TEMP_1, 25
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_EndGiveMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_EndGiveMon::
	release
	end

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Hitoshi::
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki::
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron::
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike::
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi::
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
	release
	end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	release
	end

SaffronCity_Dojo_Text_MasterKoichiIntro::
	.string "¡Grrrrr!\p"
	.string "¡Soy el MAESTRO KARATEKA!\n"
	.string "¡Y aquí yo soy el LÍDER!\p"
	.string "¿Quieres desafiarnos?\n"
	.string "¡No tendremos piedad!\p"
	.string "¡Fuaaa!$"

SaffronCity_Dojo_Text_MasterKoichiDefeat::
	.string "¡Fuaa!\n"
	.string "¡Arg! ¡Nos has vencido!$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
	.string "¡Pues sí, he perdido!\p"
	.string "¡Pero te suplico que no te lleves\n"
	.string "nuestro emblema como trofeo!\p"
	.string "¡A cambio te daré un valioso y\n"
	.string "fuerte POKéMON!\p"
	.string "¡Elige el que quieras!$"

SaffronCity_Dojo_Text_StayAndTrainWithUs::
	.string "¡Hola! ¡Quédate y practica karate\n"
	.string "con nosotros!$"

SaffronCity_Dojo_Text_MikeIntro::
	.string "¡Hoaargh!\n"
	.string "¡Quítate los zapatos!$"

SaffronCity_Dojo_Text_MikeDefeat::
	.string "¡Me rindo!$"

SaffronCity_Dojo_Text_MikePostBattle::
	.string "¡Espera a ver a nuestro MAESTRO!\p"
	.string "¡Yo soy una birria comparado\n"
	.string "con él!$"

SaffronCity_Dojo_Text_HidekiIntro::
	.string "¡Dicen que eres fuerte!\n"
	.string "¡Demuéstramelo!$"

SaffronCity_Dojo_Text_HidekiDefeat::
	.string "¡Juez!\n"
	.string "¡Un punto!$"

SaffronCity_Dojo_Text_HidekiPostBattle::
	.string "¡Nuestro MAESTRO es un karateka\n"
	.string "profesional!$"

SaffronCity_Dojo_Text_AaronIntro::
	.string "¡No me asustas nada!\n"
	.string "¡Rompo rocas para entrenarme!$"

SaffronCity_Dojo_Text_AaronDefeat::
	.string "¡Ay!\n"
	.string "¡Me he machacado los dedos!$"

SaffronCity_Dojo_Text_AaronPostBattle::
	.string "¡Sólo nos asustan los poderes\n"
	.string "psíquicos!$"

SaffronCity_Dojo_Text_HitoshiIntro::
	.string "¡Ehhh!\p"
	.string "¡No puedes entrar en nuestro DOJO-\n"
	.string "KARATE!$"

SaffronCity_Dojo_Text_HitoshiDefeat::
	.string "¡Uuuf!\n"
	.string "¡Me rindo!$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
	.string "Los mejores luchadores del país\n"
	.string "entrenan aquí.$"

SaffronCity_Dojo_Text_YouWantHitmonlee::
	.string "¿Quieres la dura patada de\n"
	.string "HITMONLEE?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
	.string "¡{PLAYER} obtuvo a {STR_VAR_1}\n"
	.string "de manos del MAESTRO de KARATE!$"

SaffronCity_Dojo_Text_YouWantHitmonchan::
	.string "¿Quieres el superpuñetazo de\n"
	.string "HITMONCHAN?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster2::
	.string "¡{PLAYER} recibió {STR_VAR_1}\n"
	.string "del MAESTRO KARATE!$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
	.string "Mejor no ser avaricioso…$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
	.string "¡Hay enemigos por todas partes!$"

SaffronCity_Dojo_Text_GoesAroundComesAround::
	.string "Lo que se siembra se recoge.$"

SaffronCity_Dojo_Text_FightingDojo::
	.string "DOJO-KARATE$"

