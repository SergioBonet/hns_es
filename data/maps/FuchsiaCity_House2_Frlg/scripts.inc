FuchsiaCity_House2_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

FuchsiaCity_House2_EventScript_GiveGoodRod::
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	giveitem_msg FuchsiaCity_House2_Text_ReceivedGoodRod, ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_GOT_GOOD_ROD
	release
	end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end

FuchsiaCity_House2_Text_DoYouLikeToFish::
	.string "¡Soy el hermano mayor del GURÚ\n"
	.string "PESCADOR!\p"
	.string "¡Me encanta pescar!\p"
	.string "¿Y a ti, te gusta pescar?$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
	.string "¡Fenomenal!\n"
	.string "¡Me gusta tu estilo!\p"
	.string "¡Toma esto y pesca, anda!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
	.string "¡{PLAYER} recibió una CAÑA BUENA\n"
	.string "de manos del hermano del GURÚ\l"
	.string "PESCADOR!$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
	.string "¡La pesca es una forma de vida!\n"
	.string "¡Es un arte!\p"
	.string "Con una CAÑA VIEJA de nada, lo\n"
	.string "máximo que se puede pescar es\l"
	.string "un MAGIKARP, ¿no?\p"
	.string "Pero con una CAÑA BUENA se pueden\n"
	.string "pescar POKéMON mucho mejores.$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
	.string "Oh...\n"
	.string "Estoy tan decepcionado...$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
	.string "¡Hola, {PLAYER}!\p"
	.string "¿Qué, pican los peces?$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
	.string "¡Oh, no!\p"
	.string "¡Tenía un regalo para ti, pero no\n"
	.string "tienes sitio!$"

