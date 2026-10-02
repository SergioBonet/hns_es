CianwoodPokecenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	@callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "En cuanto a POKéMON de agua,\n"
	.string "¡TENTACOOL es el mejor con diferencia!$"

CianwoodPokemoncenter_Text_Fisher2:
	.string "Parece que te hace falta un POKéMON\n"
	.string "de agua.\p"
	.string "Toma, quédate este, tengo muchos.$"

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "¿Conoces al POKéMANÍACO?\p"
	.string "Siempre está presumiendo de sus raros\n"
	.string "POKéMON.$"


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "Los entrenadores del GIMNASIO\p"
	.string "POKéMON de aquí son muy agresivos.\p"
	.string "Si me ven, seguro que vienen a por mí.\p"
	.string "Escucha este consejo: el LÍDER\p"
	.string "del GIMNASIO usa POKéMON del tipo\n"
	.string "lucha.\p"
	.string "Así que deberías retarle con\p"
	.string "POKéMON de tipo psíquico.\p"
	.string "Elimina sus POKé- MON antes de que\n"
	.string "puedan usar su fuerza física.\p"
	.string "¿Y esas rocas en mitad del GIMNASIO?\p"
	.string "Si no las mueves adecuadamente, no\n"
	.string "llegarás hasta el LÍDER del GIMNASIO.\p"
	.string "Si te atascas, salte.$"

CianwoodCity_Text_GymGuideWin:
	.string "¡{PLAYER}! ¡Has ganado! ¡Con sólo\n"
	.string "mirarte, lo sé!$"

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "Me encanta fardar de los POKéMON\p"
	.string "que he mejorado. ¿A ti no?\p"
	.string "¡Voy a enfrentarme a otros\n"
	.string "entrenadores para mostrar mis\l"
	.string "POKéMON!$"
