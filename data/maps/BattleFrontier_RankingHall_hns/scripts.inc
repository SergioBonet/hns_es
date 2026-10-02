BattleFrontier_RankingHall_hns_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_DomeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PikeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ShowRecords_hns::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant_hns::
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign_hns::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn_hns::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hns::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns::
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy_hns::
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall_hns:
	.string "Éste es el archiconocido\n"
	.string "HALL de las CLASIFICACIONES.\p"
	.string "Aquí es donde inmortalizamos a los\n"
	.string "ENTRENADORES que dejan récords\l"
	.string "inolvidables en el FRENTE de BATALLA.$"

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns:
	.string "Récords de la CÚPULA BATALLA, la\n"
	.string "SIERPE BATALLA y la FÁBRICA BATALLA.$"

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns:
	.string "Récords del PALACIO BATALLA,\n"
	.string "el DOJO BATALLA y la PIRÁMIDE BATALLA.$"

BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns:
	.string "Oye, ¿estás tú en esta lista?$"

BattleFrontier_RankingHall_Text_WowThatsSuper_hns:
	.string "¡Guau! ¡Impresionante!\n"
	.string "¡Tendré que tomármelo más en serio!$"

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns:
	.string "Pues ya somos dos.\p"
	.string "¡Seguro que lucharías con más ganas si\n"
	.string "vieras aquí el nombre de un amigo tuyo!$"

BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns:
	.string "Mmm…\n"
	.string "Aquí no está mi nombre…\p"
	.string "Pero, vamos, es normal porque aún no he\n"
	.string "participado en ningún combate, je, je.$"

