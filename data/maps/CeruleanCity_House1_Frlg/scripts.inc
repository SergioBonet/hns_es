CeruleanCity_House1_Frlg_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BadgeGuy::
	lock
	faceplayer
	msgbox CeruleanCity_House1_Text_BadgesHaveAmazingSecrets
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeAnotherBadge::
	message CeruleanCity_House1_Text_DescribeWhichBadge
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BADGES
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, CeruleanCity_House1_EventScript_DescribeBoulderBadge
	case 1, CeruleanCity_House1_EventScript_DescribeCascadeBadge
	case 2, CeruleanCity_House1_EventScript_DescribeThunderBadge
	case 3, CeruleanCity_House1_EventScript_DescribeRainbowBadge
	case 4, CeruleanCity_House1_EventScript_DescribeSoulBadge
	case 5, CeruleanCity_House1_EventScript_DescribeMarshBadge
	case 6, CeruleanCity_House1_EventScript_DescribeVolcanoBadge
	case 7, CeruleanCity_House1_EventScript_DescribeEarthBadge
	case 8, CeruleanCity_House1_EventScript_StopDescribingBadges
	case 127, CeruleanCity_House1_EventScript_StopDescribingBadges
	end

CeruleanCity_House1_EventScript_DescribeBoulderBadge::
	msgbox CeruleanCity_House1_Text_AttackStatFlash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeCascadeBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv30Cut
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeThunderBadge::
	msgbox CeruleanCity_House1_Text_SpeedStatFly
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeRainbowBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv50Strength
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeSoulBadge::
	msgbox CeruleanCity_House1_Text_DefenseStatSurf
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeMarshBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv70RockSmash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeVolcanoBadge::
	msgbox CeruleanCity_House1_Text_SpStatsWaterfall
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeEarthBadge::
	msgbox CeruleanCity_House1_Text_AllMonsWillObeyYou
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_StopDescribingBadges::
	msgbox CeruleanCity_House1_Text_ComeVisitAnytime
	release
	end

CeruleanCity_House1_Text_BadgesHaveAmazingSecrets::
	.string "Sólo tienen MEDALLAS los\n"
	.string "ENTRENADORES más hábiles.\p"
	.string "Ya veo que tienes una por lo\n"
	.string "menos.\p"
	.string "¡Esas MEDALLAS guardan secretos\n"
	.string "increíbles!$"

CeruleanCity_House1_Text_DescribeWhichBadge::
	.string "Dime...\p"
	.string "¿Cuál de las 8 MEDALLAS debería\n"
	.string "describirte?$"

CeruleanCity_House1_Text_ComeVisitAnytime::
	.string "Ven a verme cuando quieras.$"

CeruleanCity_House1_Text_AttackStatFlash::
	.string "Hace que aumente un poco\n"
	.string "el ATAQUE de los POKéMON.\p"
	.string "Y permite usar DESTELLO siempre\n"
	.string "que quieras.$"

CeruleanCity_House1_Text_ObeyLv30Cut::
	.string "Hace que te obedezcan los POKéMON\n"
	.string "de nivel inferior a 30.\p"
	.string "Y no sólo los tuyos, sino también\n"
	.string "los forasteros obtenidos\l"
	.string "por intercambio.\p"
	.string "¡Los de nivel superior, serán\n"
	.string "incontrolables!\p"
	.string "También permite usar CORTAR\n"
	.string "fuera del combate.$"

CeruleanCity_House1_Text_SpeedStatFly::
	.string "Hace que aumente un poco\n"
	.string "la VELOCIDAD de los POKéMON.\p"
	.string "Y permite usar VOLAR siempre\n"
	.string "que quieras.$"

CeruleanCity_House1_Text_ObeyLv50Strength::
	.string "Hace que te obedezcan los POKéMON\n"
	.string "de nivel inferior a 50.\p"
	.string "Y no sólo los tuyos, sino también\n"
	.string "los forasteros obtenidos\l"
	.string "por intercambio.\p"
	.string "¡Los de nivel superior, serán\n"
	.string "incontrolables!\p"
	.string "También permite usar FUERZA\n"
	.string "fuera del combate.$"

CeruleanCity_House1_Text_DefenseStatSurf::
	.string "Hace que aumente un poco\n"
	.string "la DEFENSA de los POKéMON.\p"
	.string "Y permite usar SURF siempre\n"
	.string "que quieras.$"

CeruleanCity_House1_Text_ObeyLv70RockSmash::
	.string "Hace que te obedezcan los POKéMON\n"
	.string "de nivel inferior a 70.\p"
	.string "Y no sólo los tuyos, sino también\n"
	.string "los forasteros obtenidos\l"
	.string "por intercambio.\p"
	.string "¡Los de nivel superior, serán\n"
	.string "incontrolables!\p"
	.string "También permite usar GOLPE\n"
	.string "ROCA fuera del combate.$"

CeruleanCity_House1_Text_SpStatsWaterfall::
	.string "Hace que aumenten un poco\n"
	.string "el AT. ESP. y la DEF. ESP.\l"
	.string "de los POKéMON.\p"
	.string "Y permite usar CASCADA siempre\n"
	.string "que quieras.$"

CeruleanCity_House1_Text_AllMonsWillObeyYou::
	.string "¡Todos los POKéMON te obedecerán!$"

