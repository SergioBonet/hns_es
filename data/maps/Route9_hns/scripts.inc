Route9_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN_HNS, Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI_HNS, Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA_HNS, Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID_HNS, Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM_HNS, Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY_HNS, Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_EventScript_Item_Flash_Cannon::
    finditem ITEM_TM_FLASH_CANNON
    end

Route9_Text_CamperDeanSeen:
	.string "He venido a explorar el TÚNEL ROCA.$"

Route9_Text_CamperDeanBeaten:
	.string "¡Uau! Peligro.$"

Route9_Text_CamperDeanAfter:
	.string "Hirieron mis POKéMON antes de entrar\n"
	.string "en el TÚNEL ROCA. ¡Será mejor que los\l"
	.string "lleve ahora mismo a un CENTRO\l"
	.string "POKéMON!$"

Route9_Text_PicnickerHeidiSeen:
	.string "¿Has ido alguna vez de picnic? ¡Es muy\n"
	.string "divertido!$"

Route9_Text_PicnickerHeidiBeaten:
	.string "¡Ohhhh!$"

Route9_Text_PicnickerHeidiAfter:
	.string "Horneamos un montón de dulces y los\n"
	.string "repartimos por ahí.\p"
	.string "¡Están riquísimos!$"

Route9_Text_CamperSidSeen:
	.string "¡Eh, tú! ¡No tires basura!$"

Route9_Text_CamperSidBeaten:
	.string "Sólo estaba diciendo que…$"

Route9_Text_CamperSidAfter:
	.string "Perdón. No estabas tirando basura. Me\n"
	.string "he equivocado.$"

Route9_Text_PicnickerEdnaSeen:
	.string "La gente no debería dejar la basura\n"
	.string "por ahí.$"

Route9_Text_PicnickerEdnaBeaten:
	.string "¡Ohh…! Perdí…$"

Route9_Text_PicnickerEdnaAfter:
	.string "Ahorrar energía es importante, pero el\n"
	.string "entorno aún lo es más.$"

Route9_Text_HikerTimSeen:
	.string "Cuando venga, lo hará por MT.\n"
	.string "PLATEADO…\p"
	.string "MT. PLATEADO está en JOHTO, ¿verdad?$"

Route9_Text_HikerTimBeaten:
	.string "Estaba ocupado cantando…$"

Route9_Text_HikerTimAfter:
	.string "Los combates son cuestión de\n"
	.string "concentración.$"

Route9_Text_HikerSidneySeen:
	.string "Te contaré un secreto.\p"
	.string "Pero primero, ¡luchemos!$"

Route9_Text_HikerSidneyBeaten:
	.string "¡Caray! He perdido…$"

Route9_Text_HikerSidneyAfter:
	.string "La CENTRAL ENERGÍA está al otro lado\n"
	.string "de un riachuelo.$"

Route9_Text_Sign:
	.string "RUTA 9\p"
	.string "CIUDAD CELESTE - TÚNEL ROCA$"
