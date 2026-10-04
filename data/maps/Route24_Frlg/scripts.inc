Route24_Frlg_MapScripts::
	.byte 0

Route24_EventScript_Rocket::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ROUTE24, 1, Route24_EventScript_RocketPostBattle
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	call Route24_EventScript_BattleRocket
	release
	end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom
	release
	end

Route24_EventScript_RocketPostBattle::
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	release
	end

Route24_EventScript_RocketTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketApproachPlayer
	call_if_eq VAR_TEMP_1, 1, Route24_EventScript_RocketMotionToPlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNuggetTrigger
	call Route24_EventScript_BattleRocket
	releaseall
	end

Route24_EventScript_BattleRocket::
	giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
	message Route24_Text_JoinTeamRocket
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_ROUTE24_ROCKET
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	setvar VAR_MAP_SCENE_ROUTE24, 1
	return

Route24_EventScript_RocketApproachPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketApproachPlayer
	waitmovement 0
	return

Route24_EventScript_RocketMotionToPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route24_EventScript_NoRoomForNuggetTrigger::
	msgbox Route24_Text_YouDontHaveAnyRoom
	closemessage
	applymovement LOCALID_PLAYER, Route24_Movement_WalkDown
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketWalkBackToPos
	release
	end

Route24_EventScript_RocketWalkBackToPos::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketWalkBackToPos
	waitmovement 0
	return

Route24_Movement_RocketApproachPlayer::
	walk_left
	step_end

Route24_Movement_RocketWalkBackToPos::
	walk_right
	walk_in_place_faster_left
	step_end

Route24_Movement_WalkDown::
	walk_down
	step_end

Route24_Text_JustEarnedFabulousPrize::
	.string "¡Enhorabuena! ¡Has ganado\n"
	.string "a nuestros 5 ENTRENADORES!\p"
	.string "¡Has ganado un premio fabuloso!$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
	.string "¡{PLAYER} obtuvo una PEPITA\n"
	.string "de manos del ENTRENADOR\l"
	.string "misterioso!$"

Route24_Text_YouDontHaveAnyRoom::
	.string "¡No te queda sitio!$"

Route24_Text_JoinTeamRocket::
	.string "¿Te gustaría unirte al TEAM\n"
	.string "ROCKET?\p"
	.string "¡Somos un grupo dedicado a hacer\n"
	.string "maldades con los POKéMON!\p"
	.string "¿Te interesa?\p"
	.string "¿Seguro?\p"
	.string "Únete a nosotros.\p"
	.string "¡Ya te he dicho que te unas\n"
	.string "a nosotros!\p"
	.string "Necesitas que te convenza.\p"
	.string "¡Te haré una oferta que no podrás\n"
	.string "rechazar!$"

Route24_Text_RocketDefeat::
	.string "¡Arrgh!\n"
	.string "¡Eres genial!$"

Route24_Text_YoudBecomeTopRocketLeader::
	.string "¡Con tu capacidad podrías ser\n"
	.string "líder del TEAM ROCKET!\p"
	.string "¡Piénsatelo, sería una buena\n"
	.string "oportunidad para ti!$"

Route24_Text_ShaneIntro::
	.string "¡Vi tu hazaña desde la hierba!$"

Route24_Text_ShaneDefeat::
	.string "¡Creía que no me ibas a ganar!$"

Route24_Text_ShanePostBattle::
	.string "¡Me oculté porque me asustaron\n"
	.string "los del puente!$"

Route24_Text_EthanIntro::
	.string "¡Yo soy el 5.º!\n"
	.string "¡Voy a acabar contigo!$"

Route24_Text_EthanDefeat::
	.string "¡Uauu!\n"
	.string "¡Ha sido mucha tela!$"

Route24_Text_EthanPostBattle::
	.string "¡He hecho lo que he podido!$"

Route24_Text_ReliIntro::
	.string "¡Soy el n.º 4!\n"
	.string "¿Te estás cansando?$"

Route24_Text_ReliDefeat::
	.string "¡También he perdido!$"

Route24_Text_ReliPostBattle::
	.string "¡He hecho lo que he podido!$"

Route24_Text_TimmyIntro::
	.string "¡Yo soy el 3.º!\n"
	.string "¡Te va a costar!$"

Route24_Text_TimmyDefeat::
	.string "¡Ay!\n"
	.string "¡Aplastado!$"

Route24_Text_TimmyPostBattle::
	.string "¡He hecho lo que he podido!$"

Route24_Text_AliIntro::
	.string "¡Soy el segundo!\n"
	.string "¡Ahora va en serio!$"

Route24_Text_AliDefeat::
	.string "¿Cómo he podido perder?$"

Route24_Text_AliPostBattle::
	.string "¡He hecho lo que he podido!$"

Route24_Text_CaleIntro::
	.string "¡Éste es el PUENTE PEPITA!\n"
	.string "¡Derrótanos a los 5 y gana un\l"
	.string "fabuloso premio!\p"
	.string "¿Crees que puedes hacerlo?$"

Route24_Text_CaleDefeat::
	.string "¡Uau!\n"
	.string "¡Buen trabajo!$"

Route24_Text_CalePostBattle::
	.string "¡He hecho lo que he podido!$"
