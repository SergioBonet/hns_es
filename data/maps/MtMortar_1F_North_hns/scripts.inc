MtMortar_1F_North_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Protector::
    finditem ITEM_PROTECTOR
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER_HNS, MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS_HNS, MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "¡No perderé esta vez!$"

MountMortar2_Text_PokemaniacMillerBeaten:
	.string "¿He perdido…?$"

MountMortar2_Text_PokemaniacMillerAfter:
	.string "Hace un rato, este KARATEKA quería\n"
	.string "luchar.\p"
	.string "Era increíblemente bueno.\p"
	.string "Nos machacó.\p"
	.string "Nos dijo que sólo se estaba\n"
	.string "entrenando. ¿Cómo será?$"

MountMortar2_Text_SupernerdMarkusSeen:
	.string "¡Hey! ¡UFF!$"

MountMortar2_Text_SupernerdMarkusBeaten:
	.string "Te confundí con otra persona…$"

MountMortar2_Text_SupernerdMarkusAfter:
	.string "Vine a explorar el MT. MORTERO, pero me\n"
	.string "separé de mi compañero…\p"
	.string "¿Te has encontrado con un entrenador\n"
	.string "que usa a un SEADRA que conoce\l"
	.string "CASCADA?$"
