VermilionCity_House1_Frlg_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing
	release
	end

VermilionCity_House1_EventScript_AlreadyGotOldRod::
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_EventScript_GiveOldRod::
	checkitemspace ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish
	msgreceiveditem VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, ITEM_OLD_ROD
	setflag FLAG_GOT_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife
	release
	end

VermilionCity_House1_EventScript_NoRoomForOldRod::
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift
	release
	end

VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish::
	.string "¡Yo soy el GURÚ PESCADOR!\p"
	.string "¡Me encanta pescar!\n"
	.string "¡Es lo más!\p"
	.string "Y a ti, ¿te gusta pescar?$"

VermilionCity_House1_Text_TakeThisAndFish::
	.string "¡Fenomenal!\n"
	.string "¡Me gusta tu estilo!\p"
	.string "¡Toma esto y pesca, anda!$"

VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru::
	.string "¡{PLAYER} recibió una CAÑA VIEJA\n"
	.string "de manos del GURÚ PESCADOR!$"

VermilionCity_House1_Text_FishingIsAWayOfLife::
	.string "¡La pesca es una forma de vida!\n"
	.string "¡Es un arte!\p"
	.string "¡En el mar, en los ríos, da igual,\n"
	.string "hay que pescar el más grande!$"

VermilionCity_House1_Text_OhThatsSoDisappointing::
	.string "Oh...\n"
	.string "Estoy tan decepcionado...$"

VermilionCity_House1_Text_HowAreTheFishBiting::
	.string "¡Hola, {PLAYER}!\p"
	.string "¿Cómo va esa pesca?$"

VermilionCity_House1_Text_NoRoomForNiceGift::
	.string "¡Oh, no!\p"
	.string "¡Tenía un regalo para ti, pero no\n"
	.string "tienes sitio!$"

