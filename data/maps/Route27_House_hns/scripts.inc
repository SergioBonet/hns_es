Route27_House_hns_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
	.string "¿Adónde vas con los POKéMON?\p"
	.string "¿A la LIGA POKéMON?\p"
	.string "¿Son tus POKéMON lo bastante fieles\n"
	.string "como para permitirte ganar?\p"
	.string "Déjame ver…$"

SandstormHouse_Text_LoyalMon:
	.string "¡Ah! Tus POKéMON confían mucho en ti.\p"
	.string "Da gusto ver a alguien tan bueno.\p"
	.string "Toma. Un regalo para el viaje.$"

SandstormHouse_Text_TM37Description:
	.string "MT37 contiene TORMENTA ARENA.\p"
	.string "Este movimiento daña a ambos\n"
	.string "combatientes.\p"
	.string "Es para entrenadores avanzados.\p"
	.string "Úsala si te atreves. ¡Suerte!$"

SandstormHouse_Text_DisloyalMon:
	.string "Si no confían más en ti, tendras\n"
	.string "problemas para ganar.\p"
	.string "La confianza es el vínculo entre los\p"
	.string "POKéMON y sus entrenadores.$"


