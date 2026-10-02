SaffronCity_FightingDojoVIP_hns_MapScripts::
	.byte 0

SaffronCity_FightingDojoVIP_EventScript_Nurse::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSAquaRooms_EventScript_Bed_PokecenterChallenge
	msgbox SaffronCity_FightingDojoVIP_Text_Nurse1, MSGBOX_NPC
	waitmessage
	fadescreen 0x1
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen 0x0
	msgbox SaffronCity_FightingDojoVIP_Text_Nurse2, MSGBOX_NPC
	waitmessage
	release
	end

SaffronCity_FightingDojoVIP_Text_Nurse1:
	.string "¡Hola! ¡Bienvenido al DOJO de\n"
	.string "ENTRENAMIENTO! Voy a curar a tus\l"
	.string "POKéMON.$"

SaffronCity_FightingDojoVIP_Text_Nurse2:
	.string "¡Vuelve cuando quieras!$"


SaffronCity_FightingDojoVIP_EventScript_Declined::
	closemessage
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Falkner_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Falkner_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Falkner_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Falkner_Rematch::
	trainerbattle_no_intro TRAINER_FALKNER_2_HNS, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner_PostOBC::
	trainerbattle_no_intro TRAINER_FALKNER_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Bugsy_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Bugsy_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Bugsy_Rematch::
	trainerbattle_no_intro TRAINER_BUGSY_2_HNS, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy_PostOBC::
	trainerbattle_no_intro TRAINER_BUGSY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Whitney_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Whitney_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Whitney_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Whitney_Rematch::
	trainerbattle_no_intro TRAINER_WHITNEY_2_HNS, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney_PostOBC::
	trainerbattle_no_intro TRAINER_WHITNEY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Morty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Morty_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Morty_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Morty_Rematch::
	trainerbattle_no_intro TRAINER_MORTY_2_HNS, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty_PostOBC::
	trainerbattle_no_intro TRAINER_MORTY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Chuck_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Chuck_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Chuck_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Chuck_Rematch::
	trainerbattle_no_intro TRAINER_CHUCK_2_HNS, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck_PostOBC::
	trainerbattle_no_intro TRAINER_CHUCK_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Jasmine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Jasmine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Jasmine_Rematch::
	trainerbattle_no_intro TRAINER_JASMINE_2_HNS, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine_PostOBC::
	trainerbattle_no_intro TRAINER_JASMINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Pryce_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Pryce_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Pryce_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Pryce_Rematch::
	trainerbattle_no_intro TRAINER_PRYCE_2_HNS, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce_PostOBC::
	trainerbattle_no_intro TRAINER_PRYCE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Clair_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Clair_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Clair_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Clair_Rematch::
	trainerbattle_no_intro TRAINER_CLAIR_2_HNS, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair_PostOBC::
	trainerbattle_no_intro TRAINER_CLAIR_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Brock_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Brock_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Brock_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Brock_Rematch::
	trainerbattle_no_intro TRAINER_BROCK_HNS, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock_PostOBC::
	trainerbattle_no_intro TRAINER_BROCK_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Misty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Misty_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Misty_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Misty_Rematch::
	trainerbattle_no_intro TRAINER_MISTY_HNS, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty_PostOBC::
	trainerbattle_no_intro TRAINER_MISTY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Surge_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Surge_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Surge_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Surge_Rematch::
	trainerbattle_no_intro TRAINER_LTSURGE_HNS, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge_PostOBC::
	trainerbattle_no_intro TRAINER_LTSURGE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Erika_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Erika_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Erika_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Erika_Rematch::
	trainerbattle_no_intro TRAINER_ERIKA_HNS, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika_PostOBC::
	trainerbattle_no_intro TRAINER_ERIKA_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Janine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Janine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Janine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Janine_Rematch::
	trainerbattle_no_intro TRAINER_JANINE_HNS, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine_PostOBC::
	trainerbattle_no_intro TRAINER_JANINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Sabrina_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Sabrina_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Sabrina_Rematch::
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina_PostOBC::
	trainerbattle_no_intro TRAINER_SABRINA_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blaine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Blaine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Blaine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Blaine_Rematch::
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine_PostOBC::
	trainerbattle_no_intro TRAINER_BLAINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blue_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Blue_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Blue_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Blue_Rematch::
	trainerbattle_no_intro TRAINER_BLUE_HNS, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue_PostOBC::
	trainerbattle_no_intro TRAINER_BLUE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

@===============MONS===============================================================================================================

SaffronCity_FightingDojoVIP_EventScript_Scizor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SCIZOR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Scizor, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Scizor:
	.string "SCIZOR: ¡Scii-zor!$"

SaffronCity_FightingDojoVIP_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Miltank:
	.string "MILTANK: ¡MuuUUU!$"

SaffronCity_FightingDojoVIP_EventScript_Poliwhirl::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Poliwhirl, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Poliwhirl:
	.string "POLIWHIRL: ¡Whirl-whirl!$"

SaffronCity_FightingDojoVIP_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Dewgong:
	.string "DEWGONG: ¡Goooooong!$"

SaffronCity_FightingDojoVIP_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Steelix:
	.string "STEELIX: ¡GraaAAANk!$"

SaffronCity_FightingDojoVIP_EventScript_Kingdra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kingdra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kingdra:
	.string "KINGDRA: Draaa…$"

SaffronCity_FightingDojoVIP_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Onix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Onix:
	.string "ONIX: ¡Oooonix!$"

SaffronCity_FightingDojoVIP_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Starmie, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Starmie:
	.string "STARMIE: ¡Hyaaa!$"

SaffronCity_FightingDojoVIP_EventScript_Victreebel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTREEBEL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Victreebel, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Victreebel:
	.string "VICTREEBEL: ¡Vreeee!$"

SaffronCity_FightingDojoVIP_EventScript_Muk::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Muk, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Muk:
	.string "MUK: Muuuk…$"

SaffronCity_FightingDojoVIP_EventScript_Kadabra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KADABRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kadabra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kadabra:
	.string "KADABRA: ¡Kadabra!$"

SaffronCity_FightingDojoVIP_EventScript_Magmar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Magmar, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Magmar:
	.string "MAGMAR: ¡Magmaaaar!$"

SaffronCity_FightingDojoVIP_EventScript_Raichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Raichu, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Raichu:
	.string "RAICHU: ¡Rai-CHU!$"

SaffronCity_FightingDojoVIP_EventScript_Machamp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Machamp, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Machamp:
	.string "MACHAMP: ¡Maa-champ!$"

SaffronCity_FightingDojo_EventScript_Chased::
	msgbox SaffronCity_FightingDojoVIP_Text_Chased, MSGBOX_NPC
	end

SaffronCity_FightingDojoVIP_Text_Chased:
	.string "¡Socorro!$"

SaffronCity_FightingDojoVIP_EvetScript_Statue::
	msgbox SaffronCity_FightingDojoVIP_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_FightingDojoVIP_Text_Statue:
	.string "SALA VIP DEL DOJO KARATE$"

SaffronCity_FightingDojoVIP_Text_Falkner_Rematch:
	.string "¡Enhorabuena por vencer al ALTO\n"
	.string "MANDO!\p"
	.string "He entrenado a mis POKéMON de tipo\n"
	.string "VOLADOR aún más duro.\p"
	.string "¿Crees que podrás volver a con el\n"
	.string "poder de los cielos?$"

SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat:
	.string "Uau… Me has vuelto a ganar.\p"
	.string "Voy a entrenar más para convertirme\n"
	.string "en el mejor maestro de los pájaros.$"

SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch:
	.string "¡Vaya, ahora eres el CAMPEÓN de JOHTO!\p"
	.string "¡Tus habilidades son impresionantes!\p"
	.string "He estado muy ocupado con mis\n"
	.string "investigaciones.\p"
	.string "Ya estoy listo para enseñarte mis\n"
	.string "nuevos descubrimientos.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat:
	.string "Vaya, debes de ser un ENTRENADOR\n"
	.string "experto.\p"
	.string "Mis investigaciones aún no están\n"
	.string "completas…$"

SaffronCity_FightingDojoVIP_Text_Whitney_Rematch:
	.string "¡Hola! ¡Eres tú!\p"
	.string "¿Ahora eres el CAMPEÓN de JOHTO?\p"
	.string "¡Eres increíble!\p"
	.string "Quiero ver lo fuerte que eres.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat:
	.string "¡Uaaaaa!\p"
	.string "¡Uaaaaa!\p"
	.string "¡Buaa, buaa…! ¡Eres cruel!$"

SaffronCity_FightingDojoVIP_Text_Morty_Rematch:
	.string "¡Ah, el CAMPEÓN de JOHTO! Me alegra\n"
	.string "que hayas venido.\p"
	.string "Has demostrado fuerza y habilidad,\n"
	.string "pero ¿has mejorado desde nuestro\l"
	.string "último combate?\p"
	.string "He estado entrenando con mis POKéMON\n"
	.string "de tipo FANTASMA.\p"
	.string "Veamos si puedes volver a superar las\n"
	.string "sombras.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat:
	.string "Aún no soy lo bastante bueno…\p"
	.string "Has visto mucho más que yo.\p"
	.string "Te envidio por ello…$"

SaffronCity_FightingDojoVIP_Text_Chuck_Rematch:
	.string "¡JAJAJÁ! ¡CAMPEÓN de JOHTO!\p"
	.string "¡Has vuelto a por más!\p"
	.string "¡Veo que has mejorado!\p"
	.string "¿Listo para ver quién es más fuerte?$"

SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat:
	.string "¿Qué? ¿Eh? ¿He perdido? ¿Otra vez?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch:
	.string "… Enhorabuena, CAMPEÓN de JOHTO.\p"
	.string "Te has vuelto muy fuerte…\p"
	.string "Me pregunto si yo habré mejorado.\p"
	.string "¿Quieres comprobarlo?\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat:
	.string "… Eres mejor ENTRENADOR que yo,\p"
	.string "tanto en habilidad como en bondad.$"

SaffronCity_FightingDojoVIP_Text_Pryce_Rematch:
	.string "¡Ah, CAMPEÓN de JOHTO!\p"
	.string "Tus habilidades son realmente\n"
	.string "notables.\p"
	.string "Me has impresionado.\p"
	.string "Pero aún ahora tenemos mucho que\n"
	.string "aprender el uno del otro.\p"
	.string "Yo, FREDO, el ENTRENADOR del invierno,\p"
	.string "aún me guardo algún truco.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat:
	.string "Ah, una vez más me impresiona tu\n"
	.string "destreza.\p"
	.string "Con tu fuerte voluntad, sé que\n"
	.string "superarás todos los obstáculos de la\l"
	.string "vida.$"

SaffronCity_FightingDojoVIP_Text_Clair_Rematch:
	.string "Lo has conseguido, ¿eh?\p"
	.string "Ahora eres el CAMPEÓN de JOHTO.\p"
	.string "Has demostrado tu fuerza, pero\n"
	.string "¿podrás conmigo otra vez?\p"
	.string "Como Maestra Dragón, no me contendré.\p"
	.string "Esta vez no.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat:
	.string "¿He perdido?\p"
	.string "¿Otra vez?\p"
	.string "No me lo creo. Tiene que haber algún\n"
	.string "error…$"

SaffronCity_FightingDojoVIP_Text_Brock_Rematch:
	.string "BROCK: ¡Eh, hola, {PLAYER}!\p"
	.string "He oído que ahora eres el CAMPEÓN de\n"
	.string "KANTO.\p"
	.string "¡Es increíble!\p"
	.string "Ahora debes de ser aún más fuerte.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat:
	.string "BROCK: Tus POKéMON han vuelto a\n"
	.string "superar mi defensa de roca…$"

SaffronCity_FightingDojoVIP_Text_Misty_Rematch:
	.string "MISTY: ¡Vaya, ahora eres el CAMPEÓN de\n"
	.string "KANTO!\p"
	.string "¡Es increíble! Has llegado muy lejos,\n"
	.string "{PLAYER}.\p"
	.string "Pero no pienso echarme atrás.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat:
	.string "MISTY: Eres muy bueno…$"

SaffronCity_FightingDojoVIP_Text_Surge_Rematch:
	.string "SURGE: ¡Así que ahora eres el CAMPEÓN\n"
	.string "de KANTO!\p"
	.string "¡Buen trabajo, chaval! ¡Pero no creas\n"
	.string "que he terminado!\p"
	.string "¿Qué tal si lo intentamos otra vez?$"

SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat:
	.string "SURGE: ¡Aaargh! ¡Sigues siendo igual\n"
	.string "de fuerte!$"

SaffronCity_FightingDojoVIP_Text_Erika_Rematch:
	.string "ERIKA: Oh, hola.\p"
	.string "¡Qué sorpresa, CAMPEÓN!\p"
	.string "Me alegra mucho volver a verte.\p"
	.string "Tu viaje debe de haber sido muy\n"
	.string "emocionante.\p"
	.string "Hasta los campeones disfrutan de un\n"
	.string "buen desafío.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat:
	.string "ERIKA: Perder aún me deja un regusto\n"
	.string "amargo…\p"
	.string "Pero saber que hay ENTRENADORES\n"
	.string "fuertes me anima a mejorar…$"

SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch:
	.string "SABRINA: Ah, el CAMPEÓN.\p"
	.string "Presentía tu regreso.\p"
	.string "Tu poder ha crecido enormemente.\p"
	.string "Incluso ahora siento tu aura.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat:
	.string "SABRINA: Tu amor por tus POKéMON ha\n"
	.string "vuelto a superar mi poder psíquico…$"

SaffronCity_FightingDojoVIP_Text_Janine_Rematch:
	.string "Jujujuju…\p"
	.string "¡Uau, lo has conseguido!\p"
	.string "¡Ahora eres el CAMPEÓN!\p"
	.string "¡Estoy muy orgullosa de ti! Pero no\n"
	.string "creas que te lo pondré fácil.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat:
	.string "SACHIKO: ¡Sigues siendo igual de duro!\p"
	.string "Has ganado, sin duda…$"

SaffronCity_FightingDojoVIP_Text_Blaine_Rematch:
	.string "BLAINE: ¡Caramba!\p"
	.string "¡Veo que te has convertido en el\n"
	.string "CAMPEÓN de KANTO!\p"
	.string "¡Eso es abrasador!\p"
	.string "Tus habilidades son de primera.\p"
	.string "Yo siempre estoy dispuesto a luchar.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat:
	.string "BLAINE: ¡Tus habilidades son\n"
	.string "realmente ardientes!\p"
	.string "¡Has atravesado mis defensas a fuego!$"

SaffronCity_FightingDojoVIP_Text_Blue_Rematch:
	.string "AZUL: Vaya, vaya. ¡El CAMPEÓN!\p"
	.string "Parece que has llegado muy lejos.\p"
	.string "Yo también tuve ese título, ¿sabes?\n"
	.string "Pero no te lo pondré fácil.\p"
	.string "A ver si puedes mantenerlo.\p"
	.string "¿Quieres la revancha?$"

SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat:
	.string "AZUL: ¿Qué?\p"
	.string "¿Cómo demonios he vuelto a perder?$"

