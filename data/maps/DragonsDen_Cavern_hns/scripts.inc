DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
	.string "{PLAYER}… Así que estás aquí.\p"
	.string "Si crees que puedes seguirme el ritmo,\n"
	.string "ven al DOJO KARATE de CIUDAD AZAFRÁN.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
	.string "DÉBORA: ¡ESPERA!\p"
	.string "Siento todo esto. Toma, acepta esto\n"
	.string "como disculpa.$"

DragonsDen_Cavern_Text_Clair_ExplainTM:
	.string "PULSO DRAGÓN es una especie de… ¡bah,\n"
	.string "da igual!\p"
	.string "Es una energía enorme de algún tipo.\p"
	.string "Si no lo quieres, no tienes por qué\n"
	.string "cogerlo.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
	.string "¿Qué pasa? ¿No vas a la LIGA POKéMON?\p"
	.string "Cuando seas CAMPEÓN, podrás volver a\n"
	.string "luchar con el LÍDER de GIMNASIO que\l"
	.string "quieras.\p"
	.string "Ve a la LIGA POKéMON.\p"
	.string "¿Sabes cómo llegar?\p"
	.string "Desde aquí, ve a PUEBLO PRIMAVERA.\p"
	.string "Y luego, usa SURF hacia el este hasta\n"
	.string "la LIGA POKéMON.\p"
	.string "El camino es muy duro.\p"
	.string "¡Ni se te ocurra perder en la LIGA\n"
	.string "POKéMON!\p"
	.string "Si lo haces, ¡me sentiré aún peor por\n"
	.string "haber perdido contra ti!\p"
	.string "Dalo todo.$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
	.string "SANTUARIO DRAGÓN\p"
	.string "Erigido en honor de los POKéMON\p"
	.string "dragón de la GUARIDA DRAGÓN$"

DragonsDen_Cavern_Text_SilverTraining1:
	.string "… ¿Qué? ¿{PLAYER}?\p"
	.string "No, no lucharé contra ti…\p"
	.string "Mis POKéMON no pueden ganarte.\p"
	.string "Y ahora no puedo presionarles.\p"
	.string "La disciplina es clave para ser el\n"
	.string "mejor entrenador POKéMON.$"

DragonsDen_Cavern_Text_SilverTraining2:
	.string "…\p"
	.string "¡Vaya…!\p"
	.string "Aprende a no cruzarte en mi camino.$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
	.string "¡Tú! ¿Cómo te atreves a entrar sin que\n"
	.string "te hayan invitado?\p"
	.string "$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
	.string "¡Qué fuerte!$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
	.string "El SANTUARIO de ahí delante es el\n"
	.string "hogar del MAESTRO del clan de los\l"
	.string "dragones.\p"
	.string "¡No te está permitido pasar!$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
	.string "¡No deberías estar aquí!$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
	.string "¡Oh, maldición! ¡Perdí!$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
	.string "Pronto me darán permiso nuestro\n"
	.string "MAESTRO para usar dragones.\p"
	.string "Cuando lo consiga, me convertiré en un\n"
	.string "admirable domador de dragones y me\l"
	.string "ganaré la aprobación de nuestro\l"
	.string "MAESTRO.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
	.string "Es alguien que no conocemos.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
	.string "Ayyyy…$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
	.string "Fue como tener que luchar con LANCE.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
	.string "¿Quién eres tú?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
	.string "Qué cutre.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
	.string "Te lo avisamos.\p"
	.string "El MAESTRO se enfadará contigo.$"
