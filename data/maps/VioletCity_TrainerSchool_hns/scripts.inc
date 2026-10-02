VioletCity_TrainerSchool_hns_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "I'm not a GBA kid, but I love\n"
	.string "playing POKéMON games!\p"
	.string "In the old games, you had to battle\n"
	.string "a lot of wild POKéMON to get enough\l"
	.string "EXP.\p"
	.string "But in newer games, the EXP. SHARE\n"
	.string "makes your POKéMON level up too fast.\p"
	.string "In this game, the EXP. SHARE is\n"
	.string "balanced to put your POKéMON at just\l"
	.string "the right level. Or slightly higher,\l"
	.string "depending on how many battles you do.\p"
	.string "If you want a traditional GEN 1-4\n"
	.string "experience, turn EXP. SHARE off.\l"
	.string "If you want a modern experience,\l"
	.string "turn EXP. SHARE ON.\p"
	.string "You choose how you want to play!$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "EARL, I am!\p"
	.string "Wonderful are POKéMON, yes!\p"
	.string "Teach you I will to be a better\n"
	.string "trainer!$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "Certain POKéMON start off weak and\n"
	.string "require much more EXP to become\l"
	.string "strong than others do.\p"
	.string "For example, LARVITAR is quite weak\n"
	.string "but will eventually become a\l"
	.string "mighty TYRANITAR, at the cost of\l"
	.string "much EXP.\p"
	.string "Only the most dedicated trainers\n"
	.string "should attempt to train such a\l"
	.string "POKéMON.$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "¡Bien! ¡A ti yo te enseñaré!\p"
	.string "¡En combate, los primeros POKéMON\n"
	.string "salen antes!\p"
	.string "¡Quizá sea más fácil si cambias el\n"
	.string "orden!\p"
	.string "¿Quieres que te cuente más cosas?$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "¿Quieres saber cómo educar bien a los\n"
	.string "POKéMON?$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "Fine! Teach you, I will!\p"
	.string "If POKéMON come out in battle\n"
	.string "even briefly, some EXP. Points\p"
	.string "it gets.\n"
	.string "At top of list put weak POKéMON\p"
	.string "Switch in battle quick!\n"
	.string "This way, weak POKéMON strong\p"
	.string "become!$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "Oh! Smart student you are!\n"
	.string "Nothing more do I teach!\p"
	.string "If you want more, talk to\n"
	.string "pupils!$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "POKéMON previously thought to\n"
	.string "only evolve through trade can\p"
	.string "evolve through leveling.\n"
	.string "MACHOKE and GRAVELER evolve\p"
	.string "at LVL 38, while KADABRA and\n"
	.string "HAUNTER evolve at LVL 42.\p"
	.string "Some items, like the METAL\n"
	.string "COAT, have also been found to\p"
	.string "evolve certain POKéMON\n"
	.string "while holding and leveling up.$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "Notable POKéMON available in an\n"
	.string "area can be seen in the overworld!\p"
	.string "But make sure to check routes\n"
	.string "at DAY and NIGHT!$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "BERRIES in the JOHTO region are\n"
	.string "good for healing and making BALLS.\p"
	.string "BERRIES in KANTO are good for\n"
	.string "reducing a POKéMON's stats.\p"
	.string "The DOJO in KANTO helps POKéMON\n"
	.string "perfect individual stats.$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "Be aware that your opponents\n"
	.string "now use teams with better type\l"
	.string "coverage, so expect a much\l"
	.string "more challenging journey ahead.$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "The blackboard describes\n"
	.string "POKéMON HM moves.\p"
	.string "HMs, once unlocked, don't need to\n"
	.string "be taught to be used.$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "Es el cuaderno de este niño…\p"
	.string "Captura POKéMON usando POKé BALL.\p"
	.string "Tu equipo puede tener hasta seis.\p"
	.string "¿Sigues leyendo?$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "Antes de lanzar la POKé BALL, debes\n"
	.string "debilitarlo.\p"
	.string "Atrapar un POKéMON quemado o\n"
	.string "envenenado es mucho más fácil.\p"
	.string "¿Sigues leyendo?$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "Algunos ataques causan confusión.\p"
	.string "Un POKéMON confuso puede atacarse a\n"
	.string "sí mismo.\p"
	.string "Retirarlo del combate, eliminará su\n"
	.string "confusión.\p"
	.string "¿Sigues leyendo?$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "Quienes atrapan POKéMON y los usan\n"
	.string "para luchar son entrenadores.\p"
	.string "Su misión es ir a los GIMNASIOS\p"
	.string "y vencer a otros entrenadores.\p"
	.string "La hoja siguiente está… ¡vacía!\p"
	.string "Niño: Eh, eh…\p"
	.string "No he escrito nada más…$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "¡Esta supermáquina imprime los datos\n"
	.string "como pegatinas!$"
