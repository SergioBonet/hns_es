Route19_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD_HNS, Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER_HNS, Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN_HNS, Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME_HNS, Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_EventScript_Item_Brine::
    finditem ITEM_TM_BRINE
    end

Route19_Text_SwimmermHaroldSeen:
	.string "¿Has nadado alguna vez en el mar por\n"
	.string "la noche?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "¡Glup…!$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "De noche, el mar se vuelve negro.\n"
	.string "Parece que te va a tragar.$"

Route19_Text_SwimmermTuckerSeen:
	.string "(Resoplido)… Un… poco más…\p"
	.string "y… llegaré… a CIUDAD FUCSIA…$"

Route19_Text_SwimmermTuckerBeaten:
	.string "¡Me ahogo!$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "Le… pedí a mi novia que nadara a\n"
	.string "CIUDAD FUCSIA…$"

Route19_Text_SwimmerfDawnSeen:
	.string "¡No me gustan los peques!$"

Route19_Text_SwimmerfDawnBeaten:
	.string "Podría ganarte nadando…$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "Si le pones ganas, podrías ir desde\n"
	.string "Ciudad Fucsia a las ISLAS ESPUMA… ¡y\l"
	.string "volver! ¿Qué? ¿No tienes agallas?$"

Route19_Text_SwimmermJeromeSeen:
	.string "Soy malísimo nadando.\p"
	.string "Sólo estoy chapoteando por estas\n"
	.string "aguas poco profundas.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "Creía que podía ganar.$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "Puede que no nade muy bien, pero me\n"
	.string "encanta el mar.$"

Route19_Text_Fisher1:
	.string "Lo siento. La carretera está cortada\n"
	.string "por obras.\p"
	.string "Si quieres llegar a ISLA CANELA, ve por\n"
	.string "el Sur, desde PUEBLO PALETA.$"

Route19_Text_Kingler:
	.string "KINGLER: KIIIIIIIIIII$"

Route19_Text_Fisher1_RocksCleared:
	.string "Estoy sudando. ¡Voy a bañarme!$"

Route19_Text_Fisher2:
	.string "Vaya, KINGLER está bloqueando la\n"
	.string "playa.$"

Route19_Text_FisherBefore:
	.string "No se puede pescar hasta que se vayan\n"
	.string "estos KINGLER.$"

Route19_Text_Fisher2_RocksCleared:
	.string "¡Por fin se han ido esos KINGLER!\p"
	.string "Ahora puedo volver a pescar.$"

Route19_Text_Sign:
	.string "RUTA 19\p"
	.string "CIUDAD FUCSIA - ISLAS ESPUMA$"

Route19_Text_CarefulSwimmingSign:
	.string "Por favor, ten cuidado si vas nadando\n"
	.string "hasta las ISLAS ESPUMA\p"
	.string "POLICÍA C. FUCSIA$"

