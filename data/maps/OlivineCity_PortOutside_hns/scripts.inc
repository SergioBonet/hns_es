OlivineCity_PortOutside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	.byte 0

OlivineCity_PortOutside_EventScript_Sabrina::
    lock
    faceplayer
    msgbox OlivineCity_PortOutside_Text_Sabrina, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_OLIVINE_SABRINA
    removeobject LOCALID_OLIVINE_SABRINA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SABRINA
    release
    end

OlivineCity_PortOutside_Text_Sabrina:
	.string "SABRINA: De repente, me han entrado\n"
	.string "ganas de ver el mar.\p"
	.string "Nos vemos en el DOJO KARATE.$"

OlivineCity_PortOutside_EventScript_Fisherman1::
	lock
	faceplayer
	msgbox OlivineCity_PortOutside_Text_PortFisherman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_PortOutside_EventScript_Fisherman2::
	lock
	faceplayer
	msgbox OlivineCity_PortOutside_Text_Fisherman2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_PortOutside_Text_PortFisherman1:
	.string "El FERRY S.S. AQUA antes zarpaba hacia\n"
	.string "KANTO los lunes y los viernes. ¡Pero\l"
	.string "ahora zarpa casi sin parar!$"

OlivineCity_PortOutside_Text_Fisherman2:
	.string "Pues sí, estoy pescando.$"
