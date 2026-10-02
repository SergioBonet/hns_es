SSAqua_RoomNW_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY_HNS, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD_HNS, SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY_HNS, SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
	.string "Sí, es verdad, soy un marinero.\p"
	.string "¡No hacía nada malo!\p"
	.string "Como el camarote estaba vacío, me\n"
	.string "eché un sueñecito.\p"
	.string "¡Ah! ¡Olvídalo! ¡Luchemos!$"

SSAqua_RoomNW_Text_SailorStanlyBeaten:
	.string "¡Lo siento! ¡Todo es culpa mía!$"

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
	.string "Los marineros hacemos mucho trabajo\n"
	.string "físico. ¡Es agotador!$"

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
	.string "¡Oh, no! He perdido algo muy\n"
	.string "importante.$"

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
	.string "No… No lo encuentro…$"

SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
	.string "Me rindo. No tienes por qué buscarlo.\n"
	.string "¡Olvídalo!$"

SSAqua_RoomNW_Text_BurglarCoreySeen:
	.string "¡Yujuu! ¡Qué suerte!$"

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
	.string "¡Qué mala suerte! ¡He perdido!$"

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
	.string "He encontrado una moneda muy bonita.\n"
	.string "Alguien debe de haberla perdido…$"
