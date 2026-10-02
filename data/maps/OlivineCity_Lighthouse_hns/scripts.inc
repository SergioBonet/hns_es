OlivineCity_Lighthouse_hns_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMSwagger::
    finditem ITEM_TM_SWAGGER
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "La gente entrena en este FARO.\p"
	.string "No es fácil subir con todos los\n"
	.string "ENTRENADORES que esperan dentro.$"

OlivineLighthouse_Text_1FPokefanF:
	.string "Antiguamente, los POKéMON iluminaban\n"
	.string "de noche el mar que rodea CIUDAD\l"
	.string "OLIVO.\p"
	.string "El FARO se construyó en honor a esos\n"
	.string "nobles POKéMON.$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY_HNS, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten, OlivineLighthouse_EventScript_RegisterHuey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OlivineLighthouse_EventScript_RematchHuey
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_RegisterHuey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox OlivineLighthouse_Text_HueyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HUEY_HNS
	release
	end

OlivineLighthouse_EventScript_RematchHuey::
	trainerbattle_rematch TRAINER_HUEY_HNS, OlivineLighthouse_Text_HueyRematchIntro, OlivineLighthouse_Text_HueyRematchDefeat
	msgbox OlivineLighthouse_Text_HueyPostRematch, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED_HNS, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "¡Los hombres de mar siempre quieren\n"
	.string "luchar!$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "¡Urf! ¡He perdido!$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "¡Qué poderío! ¿Te gustaría navegar\n"
	.string "conmigo por estos mares?$"

OlivineLighthouse_Text_HueyRegister:
	.string "¡Qué poderío! ¿Te gustaría navegar\n"
	.string "conmigo por estos mares?$"

OlivineLighthouse_Text_HueyRematchIntro:
	.string "¡Los hombres de mar siempre quieren\n"
	.string "luchar!$"

OlivineLighthouse_Text_HueyRematchDefeat:
	.string "¡Urf! ¡He perdido!$"

OlivineLighthouse_Text_HueyPostRematch:
	.string "¡Qué poderío! ¿Te gustaría navegar\n"
	.string "conmigo por estos mares?$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "¿Qué? Aquí no se juega.$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "¡Ah! Ya veo que vas en serio.$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "Arriba hay un POKéMON que mantiene\n"
	.string "encendido el FARO.\p"
	.string "Pero he oído que ahora está enfermo y\n"
	.string "que no se puede curar de la forma\l"
	.string "normal.$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO_HNS, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL_HNS, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON_HNS, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "¿Qué haces aquí? ¿Solo has venido a\n"
	.string "mirar? ¡Te sugiero que te vayas!$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "De verdad te preocupa el POKéMON\n"
	.string "enfermo…$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "¿Cómo demonios se sube?\p"
	.string "Quiero visitar al POKéMON enfermo,\n"
	.string "pero no consigo subir…$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Los marineros somos fuertes y\n"
	.string "simpáticos. ¿Y tú?$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "Eres fuerte y amable…$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "Cada vez que vuelvo a CIUDAD OLIVO,\n"
	.string "visito el GIMNASIO.\p"
	.string "El tipo de los POKéMON de la LÍDER del\n"
	.string "GIMNASIO cambió sin que me diera\l"
	.string "cuenta.$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "Viajo por el mundo para entrenar a mis\n"
	.string "POKéMON. Quiero luchar contigo.$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "Ufffff… Debo entrenar más.$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "YASMINA usaba POKéMON de tipo ROCA,\n"
	.string "como ONIX.$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT_HNS, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE_HNS, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "YASMINA debe de estar preocupada por\n"
	.string "ese POKéMON.\p"
	.string "Ni siquiera sonríe.$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "Yo tampoco puedo sonreír…$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "Hablando de enfermedades, hay una\n"
	.string "FARMACIA en CIUDAD ORQUÍDEA.$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "YASMINA es LÍDER del GIMNASIO.\p"
	.string "Quiero que vuelva conmigo.\p"
	.string "¡No he encontrado a nadie mejor!$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "¡Ay! ¡Mi POKéMON!$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "Cualquiera estaría preocupado si sus\p"
	.string "POKéMON estuvieran enfermos.\p"
	.string "Rezaré por ese POKéMON, para que\p"
	.string "YASMINA regrese al GIMNASIO.$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST_HNS, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS_HNS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "Quería luchar con YASMINA, pero no\n"
	.string "está disponible. ¿Y tú, qué…?$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "¡Uauu! ¡Eres increíble!$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "Ser LÍDER de GIMNASIO no es sólo\n"
	.string "cuestión de fuerza. Todo\p"
	.string "LÍDER también debe ser compasivo.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "Estamos a gran altura aquí. Mis\p"
	.string "POKéMON pájaro están en forma.$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "¡Uf…! ¡Todo lo que sube baja!$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "Mi POKéMON aprendió VUELO en CIUDAD\n"
	.string "ORQUÍDEA.\p"
	.string "Y como soy un perdedor, cruzaré el mar\n"
	.string "VOLANDO…$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "YASMINA: Este pequeñín siempre\n"
	.string "iluminaba el mar por la noche.\p"
	.string "Pero de pronto enfermó… Le cuesta\n"
	.string "respirar.\p"
	.string "Dicen que hay una farmacia estupenda\n"
	.string "en CIUDAD ORQUÍDEA…\p"
	.string "pero está al otro lado del mar… y no\n"
	.string "puedo dejar solo a Amphy…\p"
	.string "Quisiera pedirte un favor. ¿Podrías ir\n"
	.string "a buscar la medicina por mí?\p"
	.string "Dejaré esta entrada abierta…\p"
	.string "$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "¿Podrías traerme su medicina? ¿Por\n"
	.string "favor?$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "En CIUDAD ORQUÍDEA hay una FARMACIA\n"
	.string "maravillosa…\p"
	.string "Pero está al otro lado del mar… Y no\n"
	.string "puedo dejar solo a AMPHY…\p"
	.string "… ¿Puedo pedirte que me traigas una\n"
	.string "medicina? ¿Por favor?$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "YASMINA: ¿Le hará la medicina algo a\n"
	.string "AMPHY?$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playfanfare MUS_HEAL
	waitfanfare
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER} le ha dado la POCIÓN SECRETA\n"
	.string "a YASMINA.$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "YASMINA: ¡Mmm! Por favor, no te\n"
	.string "ofendas…\p"
	.string "AMPHY no aceptaría nada de nadie.\n"
	.string "Sólo confía en mí.$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "YASMINA: …\p"
	.string "Amphy, ¿cómo te sientes?\p"
	.string "$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "YASMINA: … Oh, qué alivio…\p"
	.string "Es maravilloso…\p"
	.string "Muchísimas, muchísimas gracias.\p"
	.string "… Volveré al GIMNASIO…\p"
	.string "También te aviso: el tipo ACERO es muy\n"
	.string "poderoso.$"

OlivineLighthouse_Text_JasmineISee:
	.string "YASMINA: … Ya veo… … ¡AMPHY, aguanta!$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "AMPHY: ¡Am… Am… phyphy…!$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Apenas puede respirar…$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "AMPHY: ¡Amphy! ¡Amphy!$"


