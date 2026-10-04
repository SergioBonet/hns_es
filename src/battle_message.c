#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_util.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_special.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "load_save.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "trainer_slide.h"
#include "trainer_tower.h"
#include "window.h"
#include "line_break.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    union {
        struct {
            DEPRECATED("Use color.background instead") u8 bgColor;
            DEPRECATED("Use color.foreground instead") u8 fgColor;
            DEPRECATED("Use color.shadow instead") u8 shadowColor;
            DEPRECATED("Use color.accent instead") u8 accentColor;
        };
        union TextColor color;
    };
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
};

#if TESTING
EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#else
static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#endif
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_EmptyString4[] = _("");

const u8 gText_PkmnShroudedInMist[] = _("¡{B_ATK_TEAM1} se ha cubierto de neblina!");
const u8 gText_PkmnGettingPumped[] = _("¡{B_DEF_NAME_WITH_PREFIX} se está animando!");
const u8 gText_PkmnsXPreventsSwitching[] = _("¡{B_BUFF1} impide el cambio con su habilidad {B_LAST_ABILITY}!\p");
const u8 gText_StatSharply[] = _(" mucho");
const u8 gText_StatRose[] = _("");
const u8 gText_StatFell[] = _("");
const u8 gText_DefendersStatRose[] = _("¡Subió{B_BUFF2} {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2}!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}¡Escapaste sin problemas!\p");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("¡Has vencido a {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("¡Has vencido a {B_LINK_OPPONENT1_NAME} y a {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("¡Has perdido contra {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostToTwo[] = _("¡Has perdido contra {B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("¡Has empatado con {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("¡Has empatado con {B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}¡{B_LINK_OPPONENT1_NAME} ha huido!"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}¡{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME} han huido!"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("¡Has vencido a {B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_OpponentMon1Appeared[] = _("¡Ha aparecido {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_WildPkmnAppeared[] = _("¡Te has encontrado con un {B_OPPONENT_MON1_NAME} salvaje!\p");
static const u8 sText_WildPkmnAppearedLR[] = _("¡Ha aparecido un {B_OPPONENT_MON1_NAME} salvaje!\n¿Huir? {L_BUTTON}+{R_BUTTON}+{A_BUTTON}\p");
static const u8 sText_WildPkmnAppearedB[] = _("¡Ha aparecido un {B_OPPONENT_MON1_NAME} salvaje!\n¿Huir? Pulsa {B_BUTTON}.\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("¡Te has encontrado con un {B_OPPONENT_MON1_NAME} salvaje!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("¡Te has encontrado con un {B_OPPONENT_MON1_NAME} salvaje!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("¡Oh! ¡Han aparecido un {B_OPPONENT_MON1_NAME} y un {B_OPPONENT_MON2_NAME} salvajes!\p");
static const u8 sText_GhostAppearedCantId[] = _("¡Ha aparecido el FANTASMA!\p¡Vaya!\n¡No se puede identificar al FANTASMA!\p");
static const u8 sText_TheGhostAppeared[] = _("¡Ha aparecido el FANTASMA!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} te desafía!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("¡{B_LINK_OPPONENT1_NAME} te desafía!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("¡{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME} te desafían!");
static const u8 sText_Trainer1SentOutPkmn[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} sacó a {B_OPPONENT_MON1_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} sacó a {B_OPPONENT_MON1_NAME} y a {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} sacó a {B_BUFF1}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} sacó a {B_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainer2SentOutPkmn2[] = _("¡{B_LINK_OPPONENT2_NAME} sacó a {B_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} sacó a {B_OPPONENT_MON1_NAME} y a {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} sacó a {B_LINK_OPPONENT_MON1_NAME}! ¡{B_LINK_OPPONENT2_NAME} sacó a {B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("¡{B_LINK_OPPONENT1_NAME} sacó a {B_BUFF1}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("¡{B_LINK_SCR_TRAINER_NAME} sacó a {B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("¡Adelante, {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("¡Adelante, {B_PLAYER_MON1_NAME} y {B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("¡Adelante, {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("¡Te toca, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("¡A por todas, {B_BUFF1}!");
static const u8 sText_JustALittleMorePkmn[] = _("¡Un poco más! ¡Aguanta, {B_BUFF1}!"); //currently unused, will require code changes
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("¡El rival está débil! ¡A por él, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmn1GoPkmn[] = _("¡{B_LINK_PARTNER_NAME} sacó a {B_LINK_PLAYER_MON1_NAME}! ¡Adelante, {B_LINK_PLAYER_MON2_NAME}!");
static const u8 sText_LinkPartnerSentOutPkmn2GoPkmn[] = _("¡{B_LINK_PARTNER_NAME} sacó a {B_LINK_PLAYER_MON2_NAME}! ¡Adelante, {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_LinkPartnerSentOutPkmn1[] = _("¡{B_LINK_PARTNER_NAME} sacó a {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_LinkPartnerSentOutPkmn2[] = _("¡{B_LINK_PARTNER_NAME} sacó a {B_LINK_PLAYER_MON2_NAME}!");
static const u8 sText_LinkPartnerWithdrewPkmn1[] = _("¡{B_LINK_PARTNER_NAME} retiró a {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_LinkPartnerWithdrewPkmn2[] = _("¡{B_LINK_PARTNER_NAME} retiró a {B_LINK_PLAYER_MON2_NAME}!");
static const u8 sText_PkmnSwitchOut[] = _("¡{B_BUFF1}, vuelve! ¡Regresa!"); //currently unused, I believe its used for when you switch on a pokemon in shift mode
static const u8 sText_PkmnThatsEnough[] = _("¡{B_BUFF1}, ya basta! ¡Vuelve!");
static const u8 sText_PkmnComeBack[] = _("¡{B_BUFF1}, vuelve!");
static const u8 sText_PkmnOkComeBack[] = _("¡Bien, {B_BUFF1}! ¡Vuelve!");
static const u8 sText_PkmnGoodComeBack[] = _("¡Buen trabajo, {B_BUFF1}! ¡Vuelve!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} retiró a {B_BUFF1}!");
static const u8 sText_Trainer2WithdrewPkmn[] = _("¡{B_TRAINER2_NAME_WITH_CLASS} retiró a {B_BUFF1}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} retiró a {B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("¡{B_LINK_OPPONENT2_NAME} retiró a {B_BUFF1}!");
// Traducción: en español el «salvaje»/«enemigo» va detrás del nombre («el PIDGEY salvaje»)
static const u8 sText_WildPkmnSuffix[] = _(" salvaje");
static const u8 sText_FoePkmnSuffix[] = _(" enemigo");
static const u8 sText_WildPkmnPrefix[] = _("El ");
static const u8 sText_FoePkmnPrefix[] = _("El ");
static const u8 sText_WildPkmnPrefixLower[] = _("el ");
static const u8 sText_FoePkmnPrefixLower[] = _("el ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("Enemigo");
static const u8 sText_AllyPkmnPrefix[] = _("Aliado");
static const u8 sText_FoePkmnPrefix3[] = _("Enemigo");
static const u8 sText_AllyPkmnPrefix2[] = _("Aliado");
static const u8 sText_FoePkmnPrefix4[] = _("Enemigo");
static const u8 sText_AllyPkmnPrefix3[] = _("Aliado");
static const u8 sText_AttackerUsedX[] = _("¡{B_ATK_NAME_WITH_PREFIX} usó {B_BUFF3}!");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP[] = _("los PS");
static const u8 sText_Attack[] = _("el ATAQUE");
static const u8 sText_Defense[] = _("la DEFENSA");
static const u8 sText_Speed[] = _("la VELOCIDAD");
static const u8 sText_SpAttack[] = _("el AT. ESP.");
static const u8 sText_SpDefense[] = _("la DEF. ESP.");
static const u8 sText_Accuracy[] = _("la precisión");
static const u8 sText_Evasiveness[] = _("la evasión");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP,
    [STAT_ATK]     = sText_Attack,
    [STAT_DEF]     = sText_Defense,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAttack,
    [STAT_SPDEF]   = sText_SpDefense,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};
const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = COMPOUND_STRING("estaba demasiado picante!"),
    [FLAVOR_DRY]    = COMPOUND_STRING("estaba demasiado seca!"),
    [FLAVOR_SWEET]  = COMPOUND_STRING("estaba demasiado dulce!"),
    [FLAVOR_BITTER] = COMPOUND_STRING("estaba demasiado amarga!"),
    [FLAVOR_SOUR]   = COMPOUND_STRING("estaba demasiado ácida!"),
};

static const u8 sText_Someones[] = _("alguien");
static const u8 sText_Lanettes[] = _("AREN"); //no decapitalize until it is everywhere
static const u8 sText_Bills[] = _("BILL");
static const u8 sText_EnigmaBerry[] = _("BAYA ENIGMA"); //no decapitalize until it is everywhere
static const u8 sText_BerrySuffix[] = _(" BAYA"); //no decapitalize until it is everywhere
const u8 gText_EmptyString3[] = _("");

static const u8 sText_TwoInGameTrainersDefeated[] = _("¡Has vencido a {B_TRAINER1_NAME_WITH_CLASS} y a {B_TRAINER2_NAME_WITH_CLASS}!\p");

// New battle strings.
const u8 gText_drastically[] = _(" muchísimo");
const u8 gText_severely[] = _(" muchísimo");
static const u8 sText_TerrainReturnedToNormal[] = _("¡El terreno ha vuelto a la normalidad!"); // Unused

const u8 *const gBattleStringsTable[STRINGID_COUNT] =
{
    [STRINGID_TRAINER1LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER1_LOSE_TEXT}"),
    [STRINGID_PKMNGAINEDEXP]                        = COMPOUND_STRING("¡{B_BUFF1} ha ganado {B_BUFF3} puntos de experiencia{B_BUFF2}!\p"),
    [STRINGID_PKMNGREWTOLV]                         = COMPOUND_STRING("¡{B_BUFF1} ha subido al nivel {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_PKMNLEARNEDMOVE]                      = COMPOUND_STRING("¡{B_BUFF1} ha aprendido {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_TRYTOLEARNMOVE1]                      = COMPOUND_STRING("{B_BUFF1} quiere aprender {B_BUFF2}.\p"),
    [STRINGID_TRYTOLEARNMOVE2]                      = COMPOUND_STRING("Pero {B_BUFF1} ya conoce cuatro movimientos.\p"),
    [STRINGID_TRYTOLEARNMOVE3]                      = COMPOUND_STRING("¿Quieres que olvide un movimiento y lo sustituya por {B_BUFF2}?"),
    [STRINGID_PKMNFORGOTMOVE]                       = COMPOUND_STRING("{B_BUFF1} ha olvidado {B_BUFF2}…\p"),
    [STRINGID_STOPLEARNINGMOVE]                     = COMPOUND_STRING("{PAUSE 32}¿Quieres que {B_BUFF1} deje de aprender {B_BUFF2}?"),
    [STRINGID_DIDNOTLEARNMOVE]                      = COMPOUND_STRING("{B_BUFF1} no ha aprendido {B_BUFF2}.\p"),
    [STRINGID_PKMNLEARNEDMOVE2]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha aprendido {B_BUFF1}!"),
    [STRINGID_ATTACKMISSED]                         = COMPOUND_STRING("¡El ataque de {B_ATK_NAME_WITH_PREFIX2} ha fallado!"),
    [STRINGID_PKMNPROTECTEDITSELF]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha protegido!"),
    [STRINGID_STATSWONTINCREASE2]                   = COMPOUND_STRING("¡Las características de {B_ATK_NAME_WITH_PREFIX2} no pueden subir más!"),
    [STRINGID_ITDOESNTAFFECT]                       = COMPOUND_STRING("No afecta a {B_DEF_NAME_WITH_PREFIX2}…"),
    [STRINGID_SCR_ITDOESNTAFFECT]                   = COMPOUND_STRING("No afecta a {B_SCR_NAME_WITH_PREFIX2}…"),
    [STRINGID_BATTLERFAINTED]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha debilitado!\p"),
    [STRINGID_PLAYERGOTMONEY]                       = COMPOUND_STRING("¡Has ganado ¥{B_BUFF1}!\p"),
    [STRINGID_PLAYERWHITEOUT]                       = COMPOUND_STRING("¡No te quedan Pokémon que puedan luchar!\p"),
    [STRINGID_PLAYERWHITEOUT2_WILD]                 = COMPOUND_STRING("Te has asustado y se te han caído ¥{B_BUFF1}…"),
    [STRINGID_PLAYERWHITEOUT2_TRAINER]              = COMPOUND_STRING("Has entregado ¥{B_BUFF1} al ganador…"),
    [STRINGID_PLAYERWHITEOUT3]                      = COMPOUND_STRING("¡La derrota te ha dejado en blanco!"),
    [STRINGID_PREVENTSESCAPE]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} impide la huida con {B_SCR_ABILITY}!\p"),
    [STRINGID_HITXTIMES]                            = COMPOUND_STRING("¡El Pokémon ha recibido {B_BUFF1} golpe(s)!"), //SV has dynamic plural here
    [STRINGID_PKMNFELLASLEEP]                       = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se ha dormido!"),
    [STRINGID_PKMNMADESLEEP]                        = COMPOUND_STRING("¡{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2} ha dormido a {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYASLEEP]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya está dormido!"),
    [STRINGID_PKMNALREADYASLEEP2]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya está dormido!"),
    [STRINGID_PKMNWASPOISONED]                      = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} ha sido envenenado!"),
    [STRINGID_PKMNPOISONEDBY]                       = COMPOUND_STRING("¡{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2} ha envenenado a {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYPOISON]                     = COMPOUND_STRING("¡El veneno resta PS a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNALREADYPOISONED]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya está envenenado!"),
    [STRINGID_PKMNBADLYPOISONED]                    = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} ha sido gravemente envenenado!"),
    [STRINGID_PKMNENERGYDRAINED]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha perdido energía!"),
    [STRINGID_PKMNWASBURNED]                        = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se ha quemado!"),
    [STRINGID_PKMNBURNEDBY]                         = COMPOUND_STRING("¡{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2} ha quemado a {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYBURN]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se resiente de la quemadura!"),
    [STRINGID_PKMNWASFROZEN]                        = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se ha congelado!"),
    [STRINGID_PKMNFROZENBY]                         = COMPOUND_STRING("¡{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2} ha congelado a {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISFROZEN]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está congelado!"),
    [STRINGID_PKMNWASDEFROSTED]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha descongelado!"),
    [STRINGID_PKMNWASDEFROSTEDBY]                   = COMPOUND_STRING("¡{B_CURRENT_MOVE} de {B_SCR_NAME_WITH_PREFIX2} ha derretido el hielo!"),
    [STRINGID_PKMNWASPARALYZED]                     = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} está paralizado! ¡Quizás no pueda moverse!"),
    [STRINGID_PKMNWASPARALYZEDBY]                   = COMPOUND_STRING("¡{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2} ha paralizado a {B_EFF_NAME_WITH_PREFIX2}! ¡Quizás no pueda moverse!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISPARALYZED]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está paralizado! ¡No se puede mover!"),
    [STRINGID_PKMNISALREADYPARALYZED]               = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya está paralizado!"),
    [STRINGID_PKMNHEALEDPARALYSIS]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no está paralizado!"),
    [STRINGID_STATSWONTINCREASE]                    = COMPOUND_STRING("¡No puede subir más {B_BUFF1} de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_STATSWONTDECREASE]                    = COMPOUND_STRING("¡No puede bajar más {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNISCONFUSED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está confuso!"),
    [STRINGID_PKMNHEALEDCONFUSION]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya no está confuso!"),
    [STRINGID_PKMNWASCONFUSED]                      = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se ha confundido!"),
    [STRINGID_PKMNALREADYCONFUSED]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya está confuso!"),
    [STRINGID_PKMNFELLINLOVE]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha enamorado!"),
    [STRINGID_PKMNINLOVE]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está enamorado de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNIMMOBILIZEDBYLOVE]                = COMPOUND_STRING("¡El amor impide que {B_ATK_NAME_WITH_PREFIX2} ataque!"),
    [STRINGID_PKMNCHANGEDTYPE]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha convertido en tipo {B_BUFF1}!"),
    [STRINGID_PKMNFLINCHED]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} retrocedió y no se pudo mover!"),
    [STRINGID_PKMNREGAINEDHEALTH]                   = COMPOUND_STRING("Los PS de {B_DEF_NAME_WITH_PREFIX2} se han restaurado."),
    [STRINGID_PKMNHPFULL]                           = COMPOUND_STRING("¡Los PS de {B_DEF_NAME_WITH_PREFIX2} están al máximo!"),
    [STRINGID_PKMNRAISEDSPDEF]                      = COMPOUND_STRING("¡Pantalla de Luz ha hecho a {B_ATK_TEAM2} más resistente a los ataques especiales!"),
    [STRINGID_PKMNRAISEDDEF]                        = COMPOUND_STRING("¡Reflejo ha hecho a {B_ATK_TEAM2} más resistente a los ataques físicos!"),
    [STRINGID_PKMNCOVEREDBYVEIL]                    = COMPOUND_STRING("¡{B_ATK_TEAM1} se ha envuelto en un velo místico!"),
    [STRINGID_PKMNUSEDSAFEGUARD]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} está protegido por Velo Sagrado!"),
    [STRINGID_PKMNSAFEGUARDEXPIRED]                 = COMPOUND_STRING("¡{B_ATK_TEAM1} ya no está protegido por Velo Sagrado!"),
    [STRINGID_PKMNWENTTOSLEEP]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha dormido!"), //not in gen 5+
    [STRINGID_PKMNSLEPTHEALTHY]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha dormido y ha recuperado PS!"),
    [STRINGID_PKMNWHIPPEDWHIRLWIND]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha levantado un remolino!"),
    [STRINGID_PKMNTOOKSUNLIGHT]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha absorbido luz!"),
    [STRINGID_PKMNLOWEREDHEAD]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha bajado la cabeza!"),
    [STRINGID_PKMNISGLOWING]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha envuelto en una luz intensa!"),
    [STRINGID_PKMNFLEWHIGH]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha volado muy alto!"),
    [STRINGID_PKMNDUGHOLE]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha escondido bajo tierra!"),
    [STRINGID_PKMNSQUEEZEDBYBIND]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha oprimido a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNTRAPPEDINVORTEX]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha quedado atrapado en el torbellino!"),
    [STRINGID_PKMNWRAPPEDBY]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha atrapado a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCLAMPED]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha atenazado a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBY]                           = COMPOUND_STRING("¡{B_BUFF1} hiere a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNFREEDFROM]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha liberado de {B_BUFF1}!"),
    [STRINGID_PKMNCRASHED]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha fallado y se ha estrellado!"),
    [STRINGID_PKMNSHROUDEDINMIST]                   = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST]                  = COMPOUND_STRING("¡La neblina protege a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNGETTINGPUMPED]                    = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha sufrido daño de retroceso!"),
    [STRINGID_PKMNPROTECTEDITSELF2]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha protegido!"),
    [STRINGID_PKMNBUFFETEDBYSANDSTORM]              = COMPOUND_STRING("¡La tormenta de arena zarandea a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNPELTEDBYHAIL]                     = COMPOUND_STRING("¡El granizo golpea a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSEEDED]                           = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha sido infectado!"),
    [STRINGID_PKMNEVADEDATTACK]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha esquivado el ataque!"),
    [STRINGID_PKMNSAPPEDBYLEECHSEED]                = COMPOUND_STRING("¡Drenadoras resta salud a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNFASTASLEEP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está dormido como un tronco."),
    [STRINGID_PKMNWOKEUP]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha despertado!"),
    [STRINGID_PKMNWOKEUPINUPROAR]                   = COMPOUND_STRING("¡El alboroto ha despertado a {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCAUSEDUPROAR]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha montado un alboroto!"),
    [STRINGID_PKMNMAKINGUPROAR]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está montando un alboroto!"),
    [STRINGID_PKMNCALMEDDOWN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se ha calmado."),
    [STRINGID_PKMNSTOCKPILED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha reservado energía {B_BUFF1} vez/veces!"),
    [STRINGID_PKMNCANTSLEEPINUPROAR2]               = COMPOUND_STRING("¡Pero {B_DEF_NAME_WITH_PREFIX2} no puede dormir con tanto alboroto!"),
    [STRINGID_UPROARKEPTPKMNAWAKE]                  = COMPOUND_STRING("¡Pero el alboroto mantiene despierto a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSTAYEDAWAKEUSING]                 = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} sigue despierto gracias a {B_DEF_ABILITY}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSTORINGENERGY]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está acumulando energía!"),
    [STRINGID_PKMNUNLEASHEDENERGY]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha liberado su energía!"),
    [STRINGID_PKMNFATIGUECONFUSION]                 = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha confundido por el cansancio!"),
    [STRINGID_PLAYERPICKEDUPMONEY]                  = COMPOUND_STRING("¡Has recogido ¥{B_BUFF1}!\p"),
    [STRINGID_PKMNUNAFFECTED]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} no se ha visto afectado!"),
    [STRINGID_PKMNTRANSFORMEDINTO]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha transformado en {B_BUFF1}!"),
    [STRINGID_PKMNMADESUBSTITUTE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha creado un sustituto!"),
    [STRINGID_PKMNHASSUBSTITUTE]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya tiene un sustituto!"),
    [STRINGID_SUBSTITUTEDAMAGED]                    = COMPOUND_STRING("¡El sustituto ha recibido el daño en lugar de {B_DEF_NAME_WITH_PREFIX2}!\p"),
    [STRINGID_PKMNSUBSTITUTEFADED]                  = COMPOUND_STRING("¡El sustituto de {B_DEF_NAME_WITH_PREFIX2} ha desaparecido!\p"),
    [STRINGID_PKMNMUSTRECHARGE]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} necesita recuperarse!"),
    [STRINGID_PKMNRAGEBUILDING]                     = COMPOUND_STRING("¡La furia de {B_DEF_NAME_WITH_PREFIX2} aumenta!"),
    [STRINGID_PKMNMOVEWASDISABLED]                  = COMPOUND_STRING("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2} ha sido anulado!"),
    [STRINGID_PKMNMOVEISDISABLED]                   = COMPOUND_STRING("¡{B_CURRENT_MOVE} de {B_ATK_NAME_WITH_PREFIX2} está anulado!\p"),
    [STRINGID_PKMNMOVEDISABLEDNOMORE]               = COMPOUND_STRING("¡El movimiento de {B_SCR_NAME_WITH_PREFIX2} ya no está anulado!"),
    [STRINGID_PKMNGOTENCORE]                        = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} tiene que repetir!"),
    [STRINGID_PKMNGOTENCOREDMOVE]                   = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} solo puede usar {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNENCOREENDED]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya no tiene que repetir!"),
    [STRINGID_PKMNTOOKAIM]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha apuntado a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSKETCHEDMOVE]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha copiado {B_BUFF1}!"),
    [STRINGID_PKMNTRYINGTOTAKEFOE]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} quiere llevarse a su rival por delante!"),
    [STRINGID_PKMNTOOKFOE]                          = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha llevado a su rival por delante!"),
    [STRINGID_PKMNREDUCEDPP]                        = COMPOUND_STRING("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2} ha perdido {B_BUFF2} PP!"),
    [STRINGID_PKMNSTOLEITEM]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha robado {B_LAST_ITEM} a {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_TARGETCANTESCAPENOW]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no puede escapar!"),
    [STRINGID_PKMNFELLINTONIGHTMARE]                = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha empezado a tener pesadillas!"),
    [STRINGID_PKMNLOCKEDINNIGHTMARE]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está atrapado en una pesadilla!"),
    [STRINGID_PKMNLAIDCURSE]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha sacrificado PS y ha maldecido a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNAFFLICTEDBYCURSE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} es víctima de una maldición!"),
    [STRINGID_SPIKESSCATTERED]                      = COMPOUND_STRING("¡{B_DEF_TEAM1} está rodeado de púas!"),
    [STRINGID_PKMNHURTBYSPIKES]                     = COMPOUND_STRING("¡Las púas han herido a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNIDENTIFIED]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha sido identificado!"),
    [STRINGID_PKMNPERISHCOUNTFELL]                  = COMPOUND_STRING("¡El contador de Canto Mortal de {B_ATK_NAME_WITH_PREFIX2} ha bajado a {B_BUFF1}!"),
    [STRINGID_PKMNBRACEDITSELF]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha preparado!"),
    [STRINGID_PKMNENDUREDHIT]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha aguantado el golpe!"),
    [STRINGID_MAGNITUDESTRENGTH]                    = COMPOUND_STRING("¡Magnitud {B_BUFF1}!"),
    [STRINGID_PKMNCUTHPMAXEDATTACK]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha sacrificado PS y ha maximizado su ATAQUE!"),
    [STRINGID_PKMNCOPIEDSTATCHANGES]                = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha copiado los cambios de características de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNGOTFREE]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha liberado de {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2}!"), //not in gen 5+, generic rapid spin?
    [STRINGID_PKMNSHEDLEECHSEED]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha librado de Drenadoras!"), //not in gen 5+, generic rapid spin?
    [STRINGID_PKMNBLEWAWAYSPIKES]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha librado de Púas!"), //not in gen 5+, generic rapid spin?
    [STRINGID_PKMNFLEDFROMBATTLE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha huido del combate!"),
    [STRINGID_PKMNFORESAWATTACK]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha previsto un ataque!"),
    [STRINGID_PKMNTOOKATTACK]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha recibido el ataque {B_BUFF1}!"),
    [STRINGID_PKMNATTACK]                           = COMPOUND_STRING("¡Ataque de {B_BUFF1}!"), //not in gen 5+
    [STRINGID_PKMNCENTERATTENTION]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha convertido en el centro de atención!"),
    [STRINGID_PKMNCHARGINGPOWER]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha empezado a cargar energía!"),
    [STRINGID_NATUREPOWERTURNEDINTO]                = COMPOUND_STRING("¡Adaptación se ha convertido en {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNSTATUSNORMAL]                     = COMPOUND_STRING("¡El estado de {B_ATK_NAME_WITH_PREFIX2} ha vuelto a la normalidad!"),
    [STRINGID_PKMNHASNOMOVESLEFT]                   = COMPOUND_STRING("¡A {B_ATK_NAME_WITH_PREFIX2} no le quedan movimientos que pueda usar!\p"),
    [STRINGID_PKMNSUBJECTEDTOTORMENT]               = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} sufre un tormento!"),
    [STRINGID_PKMNCANTUSEMOVETORMENT]               = COMPOUND_STRING("¡El tormento impide a {B_ATK_NAME_WITH_PREFIX2} usar el mismo movimiento dos veces seguidas!\p"),
    [STRINGID_PKMNTIGHTENINGFOCUS]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se está concentrando!"),
    [STRINGID_PKMNFELLFORTAUNT]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha dejado provocar!"),
    [STRINGID_PKMNCANTUSEMOVETAUNT]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar {B_CURRENT_MOVE} por la provocación!\p"),
    [STRINGID_PKMNREADYTOHELP]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se prepara para ayudar a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSWITCHEDITEMS]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha intercambiado objetos con su objetivo!"),
    [STRINGID_PKMNCOPIEDFOE]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha copiado la habilidad de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNWISHCAMETRUE]                     = COMPOUND_STRING("¡El deseo de {B_BUFF1} se ha hecho realidad!"),
    [STRINGID_PKMNPLANTEDROOTS]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha echado raíces!"),
    [STRINGID_PKMNABSORBEDNUTRIENTS]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha absorbido nutrientes con sus raíces!"),
    [STRINGID_PKMNANCHOREDITSELF]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha anclado con sus raíces!"),
    [STRINGID_PKMNWASMADEDROWSY]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} tiene sueño!"),
    [STRINGID_PKMNKNOCKEDOFF]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha tirado {B_LAST_ITEM} a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSWAPPEDABILITIES]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha intercambiado su habilidad con su objetivo!"),
    [STRINGID_PKMNSEALEDOPPONENTMOVE]               = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha sellado los movimientos que comparte con su objetivo!"),
    [STRINGID_PKMNCANTUSEMOVESEALED]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar {B_CURRENT_MOVE} porque está sellado!\p"),
    [STRINGID_PKMNWANTSGRUDGE]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} quiere que su objetivo le guarde rencor!"),
    [STRINGID_PKMNLOSTPPGRUDGE]                     = COMPOUND_STRING("¡{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX2} se ha quedado sin PP por el rencor!"),
    [STRINGID_PKMNSHROUDEDITSELF]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha cubierto con Capa Mágica!"),
    [STRINGID_PKMNMOVEBOUNCED]                      = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} ha devuelto {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNWAITSFORTARGET]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} espera a que su objetivo haga un movimiento!"),
    [STRINGID_PKMNSNATCHEDMOVE]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha robado el movimiento de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNMADEITRAIN]                       = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} ha hecho llover!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPROTECTEDBY]                      = COMPOUND_STRING("¡{B_DEF_ABILITY} ha protegido a {B_DEF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSUSAGE]                    = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} impide a {B_ATK_NAME_WITH_PREFIX2} usar {B_CURRENT_MOVE}!"), //I don't see this in SV text
    [STRINGID_PKMNRESTOREDHPUSING]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha recuperado PS con {B_SCR_ABILITY}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNCHANGEDTYPEWITH]                  = COMPOUND_STRING("¡{B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX2} lo ha convertido en tipo {B_BUFF1}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSROMANCEWITH]              = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} impide el enamoramiento!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSCONFUSIONWITH]            = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} impide la confusión!"), //not in gen 5+, ability popup
    [STRINGID_PKMNRAISEDFIREPOWERWITH]              = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} ha potenciado los movimientos de tipo Fuego!"), //not in gen 5+, ability popup
    [STRINGID_PKMNANCHORSITSELFWITH]                = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ancla al suelo con {B_DEF_ABILITY}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNCUTSATTACKWITH]                   = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} reduce el ATAQUE de {B_DEF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSSTATLOSSWITH]             = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} evita la bajada de características!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTSWITH]                        = COMPOUND_STRING("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2} ha herido a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNTRACED]                           = COMPOUND_STRING("¡Ha copiado {B_BUFF2} de {B_BUFF1}!"),
    [STRINGID_STATSHARPLY]                          = gText_StatSharply,
    [STRINGID_STATHARSHLY]                          = COMPOUND_STRING(" mucho"),
    [STRINGID_ATTACKERSSTATROSE]                    = COMPOUND_STRING("¡Subió{B_BUFF2} {B_BUFF1} de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_DEFENDERSSTATROSE]                    = gText_DefendersStatRose,
    [STRINGID_SCRIPTINGSTATROSE]                    = COMPOUND_STRING("¡Subió{B_BUFF2} {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_ATTACKERSSTATFELL]                    = COMPOUND_STRING("¡Bajó{B_BUFF2} {B_BUFF1} de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_DEFENDERSSTATFELL]                    = COMPOUND_STRING("¡Bajó{B_BUFF2} {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_CRITICALHIT]                          = COMPOUND_STRING("¡Un golpe crítico!"),
    [STRINGID_ONEHITKO]                             = COMPOUND_STRING("¡K.O. en un golpe!"),
    [STRINGID_123POOF]                              = COMPOUND_STRING("Uno…{PAUSE 10}dos…{PAUSE 10}y…{PAUSE 10}{PAUSE 20}{PLAY_SE SE_BALL_BOUNCE_1}¡tachán!\p"),
    [STRINGID_ANDELLIPSIS]                          = COMPOUND_STRING("Y…\p"),
    [STRINGID_NOTVERYEFFECTIVE]                     = COMPOUND_STRING("No es muy eficaz…"),
    [STRINGID_SUPEREFFECTIVE]                       = COMPOUND_STRING("¡Es muy eficaz!"),
    [STRINGID_GOTAWAYSAFELY]                        = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED]                         = COMPOUND_STRING("{PLAY_SE SE_FLEE}¡El {B_BUFF1} salvaje ha huido!"),
    [STRINGID_NORUNNINGFROMTRAINERS]                = COMPOUND_STRING("¡No! ¡No se puede huir de un combate contra un Entrenador!\p"),
    [STRINGID_CANTESCAPE]                           = COMPOUND_STRING("¡No puedes escapar!\p"),
    [STRINGID_DONTLEAVEBIRCH]                       = COMPOUND_STRING("PROF. ABEDUL: ¡No me dejes así!\p"), //no decapitalize until it is everywhere
    [STRINGID_BUTNOTHINGHAPPENED]                   = COMPOUND_STRING("¡Pero no ha pasado nada!"),
    [STRINGID_BUTITFAILED]                          = COMPOUND_STRING("¡Pero ha fallado!"),
    [STRINGID_ITHURTCONFUSION]                      = COMPOUND_STRING("¡Está tan confuso que se ha herido a sí mismo!"),
    [STRINGID_STARTEDTORAIN]                        = COMPOUND_STRING("¡Ha empezado a llover!"),
    [STRINGID_DOWNPOURSTARTED]                      = COMPOUND_STRING("¡Ha empezado a diluviar!"), // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
    [STRINGID_RAINCONTINUES]                        = COMPOUND_STRING("Sigue lloviendo."), //not in gen 5+
    [STRINGID_DOWNPOURCONTINUES]                    = COMPOUND_STRING("El chaparrón continúa…"), // unused
    [STRINGID_RAINSTOPPED]                          = COMPOUND_STRING("Ha dejado de llover."),
    [STRINGID_SANDSTORMBREWED]                      = COMPOUND_STRING("¡Se ha desatado una tormenta de arena!"),
    [STRINGID_SANDSTORMRAGES]                       = COMPOUND_STRING("La tormenta de arena arrecia."),
    [STRINGID_SANDSTORMSUBSIDED]                    = COMPOUND_STRING("La tormenta de arena ha amainado."),
    [STRINGID_SUNLIGHTGOTBRIGHT]                    = COMPOUND_STRING("¡El sol pega fuerte!"),
    [STRINGID_SUNLIGHTSTRONG]                       = COMPOUND_STRING("El sol pega fuerte."), //not in gen 5+
    [STRINGID_SUNLIGHTFADED]                        = COMPOUND_STRING("El sol ya no pega tan fuerte."),
    [STRINGID_STARTEDHAIL]                          = COMPOUND_STRING("¡Ha empezado a granizar!"),
    [STRINGID_HAILCONTINUES]                        = COMPOUND_STRING("Sigue granizando."),
    [STRINGID_HAILSTOPPED]                          = COMPOUND_STRING("Ha dejado de granizar."),
    [STRINGID_STATCHANGESGONE]                      = COMPOUND_STRING("¡Se han eliminado todos los cambios de características!"),
    [STRINGID_COINSSCATTERED]                       = COMPOUND_STRING("¡Hay monedas por todas partes!"),
    [STRINGID_TOOWEAKFORSUBSTITUTE]                 = COMPOUND_STRING("¡Pero no le quedan PS suficientes para crear un sustituto!"),
    [STRINGID_SHAREDPAIN]                           = COMPOUND_STRING("¡Los combatientes comparten el daño!"),
    [STRINGID_BELLCHIMED]                           = COMPOUND_STRING("¡Ha sonado una campana!"),
    [STRINGID_FAINTINTHREE]                         = COMPOUND_STRING("¡Los Pokémon que han oído la canción se debilitarán en tres turnos!"),
    [STRINGID_NOPPLEFT]                             = COMPOUND_STRING("¡No quedan PP para este movimiento!\p"), //not in gen 5+
    [STRINGID_BUTNOPPLEFT]                          = COMPOUND_STRING("¡Pero no quedaban PP para el movimiento!"),
    [STRINGID_PLAYERUSEDITEM]                       = COMPOUND_STRING("¡Has usado {B_LAST_ITEM}!"),
    [STRINGID_WALLYUSEDITEM]                        = COMPOUND_STRING("¡BLASCO ha usado {B_LAST_ITEM}!"), //no decapitalize until it is everywhere
    [STRINGID_TRAINERBLOCKEDBALL]                   = COMPOUND_STRING("¡El Entrenador ha bloqueado la Poké Ball!"),
    [STRINGID_DONTBEATHIEF]                         = COMPOUND_STRING("¡No seas ladrón!"),
    [STRINGID_ITDODGEDBALL]                         = COMPOUND_STRING("¡Ha esquivado la Poké Ball! ¡Este Pokémon no se puede atrapar!"),
    [STRINGID_PKMNBROKEFREE]                        = COMPOUND_STRING("¡Oh, no! ¡El Pokémon se ha escapado!"),
    [STRINGID_ITAPPEAREDCAUGHT]                     = COMPOUND_STRING("¡Vaya! ¡Parecía que ya estaba atrapado!"),
    [STRINGID_AARGHALMOSTHADIT]                     = COMPOUND_STRING("¡Argh! ¡Casi lo tenía!"),
    [STRINGID_SHOOTSOCLOSE]                         = COMPOUND_STRING("¡Jo! ¡Ha faltado muy poco!"),
#if IS_HNS
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER]               = COMPOUND_STRING("¡Ya está! ¡Has atrapado a {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM 659}\p"),
    [STRINGID_GOTCHAPKMNCAUGHTWALLY]                = COMPOUND_STRING("¡Ya está! ¡Has atrapado a {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM 659}{PAUSE 127}"),
#else
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER]               = COMPOUND_STRING("¡Ya está! ¡Has atrapado a {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"),
    [STRINGID_GOTCHAPKMNCAUGHTWALLY]                = COMPOUND_STRING("¡Ya está! ¡Has atrapado a {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}"),
#endif
    [STRINGID_GIVENICKNAMECAPTURED]                 = COMPOUND_STRING("¿Quieres ponerle un mote a {B_DEF_NAME}?"),
    [STRINGID_PKMNDATAADDEDTODEX]                   = COMPOUND_STRING("¡Los datos de {B_DEF_NAME} se han añadido a la Pokédex!\p"),
    [STRINGID_ITISRAINING]                          = COMPOUND_STRING("¡Está lloviendo!"),
    [STRINGID_SANDSTORMISRAGING]                    = COMPOUND_STRING("¡Arrecia la tormenta de arena!"),
    [STRINGID_CANTESCAPE2]                          = COMPOUND_STRING("¡No has podido escapar!\p"),
    [STRINGID_PKMNIGNORESASLEEP]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no obedece y sigue durmiendo!"),
    [STRINGID_PKMNIGNOREDORDERS]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no obedece!"),
    [STRINGID_PKMNBEGANTONAP]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha echado una siesta!"),
    [STRINGID_PKMNLOAFING]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está holgazaneando!"),
    [STRINGID_PKMNWONTOBEY]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no quiere obedecer!"),
    [STRINGID_PKMNTURNEDAWAY]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha mirado hacia otro lado!"),
    [STRINGID_PKMNPRETENDNOTNOTICE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} hace como si no se hubiera enterado!"),
    [STRINGID_ENEMYABOUTTOSWITCHPKMN]               = COMPOUND_STRING("{B_TRAINER1_NAME_WITH_CLASS} va a sacar a {B_BUFF2}.\p¿Quieres cambiar de Pokémon?"),
    [STRINGID_CREPTCLOSER]                          = COMPOUND_STRING("¡{B_PLAYER_NAME} se ha acercado a {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_CANTGETCLOSER]                        = COMPOUND_STRING("¡{B_PLAYER_NAME} no puede acercarse más!"), //safari
    [STRINGID_PKMNWATCHINGCAREFULLY]                = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} vigila con atención!"), //safari
    [STRINGID_PKMNCURIOUSABOUTX]                    = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} siente curiosidad por {B_BUFF1}!"), //safari
    [STRINGID_PKMNENTHRALLEDBYX]                    = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} está encantado con {B_BUFF1}!"), //safari
    [STRINGID_PKMNIGNOREDX]                         = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} ha ignorado por completo {B_BUFF1}!"), //safari
    [STRINGID_THREWPOKEBLOCKATPKMN]                 = COMPOUND_STRING("¡{B_PLAYER_NAME} ha lanzado un {POKEBLOCK} a {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_OUTOFSAFARIBALLS]                     = COMPOUND_STRING("{PLAY_SE SE_DING_DONG}LOCUTOR: ¡Te has quedado sin Safari Balls! ¡Se acabó!\p"), //safari
    [STRINGID_PKMNSITEMCUREDPARALYSIS]              = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} le ha curado la parálisis!"),
    [STRINGID_PKMNSITEMCUREDPOISON]                 = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} le ha curado el envenenamiento!"),
    [STRINGID_PKMNSITEMHEALEDBURN]                  = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} le ha curado la quemadura!"),
    [STRINGID_PKMNSITEMDEFROSTEDIT]                 = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} lo ha descongelado!"),
    [STRINGID_PKMNSITEMWOKEIT]                      = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} lo ha despertado!"),
    [STRINGID_PKMNSITEMSNAPPEDOUT]                  = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} le ha quitado la confusión!"),
    [STRINGID_PKMNSITEMCUREDPROBLEM]                = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} le ha curado el problema de {B_BUFF1}!"),
    [STRINGID_PKMNSITEMRESTOREDHEALTH]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha recuperado salud con {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDPP]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha recuperado los PP de {B_BUFF1} con {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDSTATUS]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha restablecido sus características con {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE]           = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha recuperado algunos PS con {B_LAST_ITEM}!"),
    [STRINGID_ITEMALLOWSONLYYMOVE]                  = COMPOUND_STRING("¡{B_LAST_ITEM} solo permite usar {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNHUNGONWITHX]                      = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha aguantado gracias a {B_LAST_ITEM}!"),
    [STRINGID_EMPTYSTRING3]                         = gText_EmptyString3,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2]             = COMPOUND_STRING("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX2} le ha restaurado algunos PS!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM]             = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} ha levantado una tormenta de arena!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXPREVENTSYLOSS]                  = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} evita que baje {B_BUFF1}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXINFATUATEDY]                    = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} ha enamorado a {B_ATK_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXMADEYINEFFECTIVE]               = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} ha anulado {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXCUREDYPROBLEM]                  = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} le ha curado el problema de {B_BUFF1}!"), //not in gen 5+, ability popup
    [STRINGID_ITSUCKEDLIQUIDOOZE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha absorbido el lodo líquido!"),
    [STRINGID_PKMNTRANSFORMED]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha transformado!"),
    [STRINGID_ELECTRICITYWEAKENED]                  = COMPOUND_STRING("¡Se ha debilitado el poder de la electricidad!"),
    [STRINGID_FIREWEAKENED]                         = COMPOUND_STRING("¡Se ha debilitado el poder del fuego!"),
    [STRINGID_PKMNHIDUNDERWATER]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha ocultado bajo el agua!"),
    [STRINGID_PKMNSPRANGUP]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha saltado muy alto!"),
    [STRINGID_HMMOVESCANTBEFORGOTTEN]               = COMPOUND_STRING("Los movimientos de MO no se pueden olvidar ahora.\p"),
    [STRINGID_XFOUNDONEY]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha encontrado {B_LAST_ITEM}!"),
    [STRINGID_PLAYERDEFEATEDTRAINER1]               = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA]                        = COMPOUND_STRING("¡Un aroma tranquilizador inunda la zona!"),
    [STRINGID_ITEMSCANTBEUSEDNOW]                   = COMPOUND_STRING("Ahora no se pueden usar objetos.{PAUSE 64}"), //not in gen 5+, i think
    [STRINGID_USINGITEMSTATOFPKMNROSE]              = COMPOUND_STRING("¡Con {B_LAST_ITEM}, subió{B_BUFF2} {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2}!"), //todo: update this, will require code changes
    [STRINGID_USINGITEMSTATOFPKMNFELL]              = COMPOUND_STRING("¡Con {B_LAST_ITEM}, bajó{B_BUFF2} {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNUSEDXTOGETPUMPED]                 = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha usado {B_LAST_ITEM} para venirse arriba!"),
    [STRINGID_PKMNSXMADEYUSELESS]                   = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} ha inutilizado {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNTRAPPEDBYSANDTOMB]                = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha quedado atrapado en arenas movedizas!"),
    [STRINGID_EMPTYSTRING4]                         = COMPOUND_STRING(""),
    [STRINGID_ABOOSTED]                             = COMPOUND_STRING(" extra"),
    [STRINGID_PKMNSXINTENSIFIEDSUN]                 = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} ha intensificado los rayos del sol!"), //not in gen 5+, ability popup
    [STRINGID_YOUTHROWABALLNOWRIGHT]                = COMPOUND_STRING("Ahora lanzo una Ball, ¿no? ¡Ha… haré lo que pueda!"),
    [STRINGID_PKMNSXTOOKATTACK]                     = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} ha recibido el ataque!"), //In gen 5+ but without naming the ability
    [STRINGID_PKMNCHOSEXASDESTINY]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha elegido Deseo Oculto como destino!"),
    [STRINGID_PKMNLOSTFOCUS]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha perdido la concentración y no se ha podido mover!"),
    [STRINGID_USENEXTPKMN]                          = COMPOUND_STRING("¿Usar el siguiente Pokémon?"),
    [STRINGID_PKMNFLEDUSINGITS]                     = COMPOUND_STRING("{PLAY_SE SE_FLEE}¡{B_ATK_NAME_WITH_PREFIX} ha huido gracias a {B_LAST_ITEM}!\p"),
    [STRINGID_PKMNFLEDUSING]                        = COMPOUND_STRING("{PLAY_SE SE_FLEE}¡{B_ATK_NAME_WITH_PREFIX} ha huido gracias a {B_ATK_ABILITY}!\p"), //not in gen 5+
    [STRINGID_PKMNWASDRAGGEDOUT]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha sido arrastrado al combate!\p"),
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS]            = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} ha normalizado su estado!"),
    [STRINGID_TRAINER1USEDITEM]                     = COMPOUND_STRING("¡{B_ATK_TRAINER_NAME_WITH_CLASS} ha usado {B_LAST_ITEM}!"),
    [STRINGID_BOXISFULL]                            = COMPOUND_STRING("¡La caja está llena! ¡No puedes atrapar más Pokémon!\p"),
    [STRINGID_PKMNAVOIDEDATTACK]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha esquivado el ataque!"),
    [STRINGID_PKMNSXMADEITINEFFECTIVE]              = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} lo ha vuelto ineficaz!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXPREVENTSFLINCHING]              = COMPOUND_STRING("¡{B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX2} impide el retroceso!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYHASBURN]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya está quemado!"),
    [STRINGID_STATSWONTDECREASE2]                   = COMPOUND_STRING("¡Las características de {B_DEF_NAME_WITH_PREFIX2} no pueden bajar más!"),
    [STRINGID_PKMNSXBLOCKSY]                        = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} bloquea {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXWOREOFF]                        = COMPOUND_STRING("¡{B_BUFF1} de {B_ATK_TEAM2} ha dejado de hacer efecto!"),
    [STRINGID_THEWALLSHATTERED]                     = COMPOUND_STRING("¡La barrera se ha roto!"), //not in gen5+, uses "your teams light screen wore off!" etc instead
    [STRINGID_PKMNSXCUREDITSYPROBLEM]               = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} le ha curado el problema de {B_BUFF1}!"), //not in gen 5+, ability popup
    [STRINGID_ATTACKERCANTESCAPE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede escapar!"),
    [STRINGID_PKMNOBTAINEDX]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ha obtenido {B_BUFF1}."),
    [STRINGID_PKMNOBTAINEDX2]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ha obtenido {B_BUFF2}."),
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ha obtenido {B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} ha obtenido {B_BUFF2}."),
    [STRINGID_BUTNOEFFECT]                          = COMPOUND_STRING("¡Pero no ha tenido ningún efecto!"),
    [STRINGID_TWOENEMIESDEFEATED]                   = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER2_LOSE_TEXT}"),
    [STRINGID_PKMNINCAPABLEOFPOWER]                 = COMPOUND_STRING("¡Parece que {B_ATK_NAME_WITH_PREFIX2} no puede usar su poder!"),
    [STRINGID_GLINTAPPEARSINEYE]                    = COMPOUND_STRING("¡Un destello brilla en los ojos de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNGETTINGINTOPOSITION]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se está colocando en posición!"),
    [STRINGID_PKMNBEGANGROWLINGDEEPLY]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha empezado a gruñir!"),
    [STRINGID_PKMNEAGERFORMORE]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} quiere más!"),
    [STRINGID_DEFEATEDOPPONENTBYREFEREE]            = COMPOUND_STRING("¡{B_PLAYER_MON1_NAME} ha vencido a {B_OPPONENT_MON1_NAME} por decisión del ÁRBITRO!"),
    [STRINGID_LOSTTOOPPONENTBYREFEREE]              = COMPOUND_STRING("¡{B_PLAYER_MON1_NAME} ha perdido contra {B_OPPONENT_MON1_NAME} por decisión del ÁRBITRO!"),
    [STRINGID_TIEDOPPONENTBYREFEREE]                = COMPOUND_STRING("¡{B_PLAYER_MON1_NAME} ha empatado con {B_OPPONENT_MON1_NAME} por decisión del ÁRBITRO!"),
    [STRINGID_QUESTIONFORFEITMATCH]                 = COMPOUND_STRING("¿Quieres rendirte y abandonar el combate?"),
    [STRINGID_FORFEITEDMATCH]                       = COMPOUND_STRING("Te has rendido."),
    [STRINGID_PKMNTRANSFERREDSOMEONESPC]            = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC]            = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL]                = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL]                = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT]                      = COMPOUND_STRING("{B_TRAINER1_WIN_TEXT}"),
    [STRINGID_TRAINER2WINTEXT]                      = COMPOUND_STRING("{B_TRAINER2_WIN_TEXT}"),
    [STRINGID_ENDUREDSTURDY]                        = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha aguantado el golpe gracias a {B_DEF_ABILITY}!"),
    [STRINGID_POWERHERB]                            = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha cargado por completo gracias a {B_LAST_ITEM}!"),
    [STRINGID_HURTBYITEM]                           = COMPOUND_STRING("¡{B_LAST_ITEM} ha herido a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_GRAVITYINTENSIFIED]                   = COMPOUND_STRING("¡La gravedad se ha intensificado!"),
    [STRINGID_TARGETWOKEUP]                         = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha despertado!"),
    [STRINGID_TAILWINDBLEW]                         = COMPOUND_STRING("¡Sopla un viento afín a favor de {B_ATK_TEAM2}!"),
    [STRINGID_PKMNWENTBACK]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha vuelto con {B_ATK_TRAINER_NAME}!"),
    [STRINGID_PKMNCANTUSEITEMSANYMORE]              = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no puede usar objetos!"),
    [STRINGID_PKMNFLUNG]                            = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha lanzado {B_LAST_ITEM}!"),
    [STRINGID_PKMNPREVENTEDFROMHEALING]             = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} no puede curarse!"),
    [STRINGID_PKMNSWITCHEDATKANDDEF]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha intercambiado su ATAQUE y su DEFENSA!"),
    [STRINGID_PKMNSABILITYSUPPRESSED]               = COMPOUND_STRING("¡Se ha anulado la habilidad de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_SHIELDEDFROMCRITICALHITS]             = COMPOUND_STRING("¡Conjuro protege a {B_ATK_TEAM2} de los golpes críticos!"),
    [STRINGID_PKMNACQUIREDABILITY]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha adquirido {B_DEF_ABILITY}!"),
    [STRINGID_POISONSPIKESSCATTERED]                = COMPOUND_STRING("¡{B_DEF_TEAM1} está rodeado de púas tóxicas!"),
    [STRINGID_PKMNSWITCHEDSTATCHANGES]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha intercambiado los cambios de características con su objetivo!"),
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER]        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha rodeado de un velo de agua!"),
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM]      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} levita gracias al electromagnetismo!"),
    [STRINGID_PKMNTWISTEDDIMENSIONS]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha distorsionado las dimensiones!"),
    [STRINGID_POINTEDSTONESFLOAT]                   = COMPOUND_STRING("¡Hay piedras puntiagudas flotando alrededor de {B_DEF_TEAM2}!"),
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA]               = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha quedado atrapado en un remolino de magma!"),
    [STRINGID_VANISHEDINSTANTLY]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha desaparecido al instante!"),
    [STRINGID_PROTECTEDTEAM]                        = COMPOUND_STRING("¡{B_CURRENT_MOVE} ha protegido a {B_ATK_TEAM2}!"),
    [STRINGID_SHAREDITSGUARD]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha compartido su defensa con el objetivo!"),
    [STRINGID_SHAREDITSPOWER]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha compartido su poder con el objetivo!"),
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON]         = COMPOUND_STRING("¡Se ha creado un espacio extraño en el que se intercambian la DEFENSA y la DEF. ESP.!"),
    [STRINGID_BECAMENIMBLE]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha vuelto más ágil!"),
    [STRINGID_HURLEDINTOTHEAIR]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha salido despedido por los aires!"),
    [STRINGID_HELDITEMSLOSEEFFECTS]                 = COMPOUND_STRING("¡Se ha creado un espacio extraño en el que los objetos pierden su efecto!"),
    [STRINGID_FELLSTRAIGHTDOWN]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha caído en picado!"),
    [STRINGID_TARGETCHANGEDTYPE]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha convertido en tipo {B_BUFF1}!"),
    [STRINGID_KINDOFFER]                            = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha aceptado la amable oferta!"),
    [STRINGID_RESETSTARGETSSTATLEVELS]              = COMPOUND_STRING("¡Se han eliminado los cambios de características de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ALLYSWITCHPOSITION]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} y {B_SCR_NAME_WITH_PREFIX2} han cambiado de sitio!"),
    [STRINGID_REFLECTTARGETSTYPE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ahora es del mismo tipo que {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_EMBARGOENDS]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya puede volver a usar objetos!"),
    [STRINGID_ELECTROMAGNETISM]                     = COMPOUND_STRING("electromagnetismo"),
    [STRINGID_BUFFERENDS]                           = COMPOUND_STRING("¡{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2} ha dejado de hacer efecto!"),
    [STRINGID_TELEKINESISENDS]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha librado de la telequinesis!"),
    [STRINGID_TAILWINDENDS]                         = COMPOUND_STRING("¡El Viento Afín de {B_ATK_TEAM2} ha amainado!"),
    [STRINGID_LUCKYCHANTENDS]                       = COMPOUND_STRING("¡El Conjuro de {B_ATK_TEAM2} ha dejado de hacer efecto!"),
    [STRINGID_TRICKROOMENDS]                        = COMPOUND_STRING("¡Las dimensiones han vuelto a la normalidad!"),
    [STRINGID_WONDERROOMENDS]                       = COMPOUND_STRING("¡Zona Extraña ha terminado y la DEFENSA y la DEF. ESP. han vuelto a la normalidad!"),
    [STRINGID_MAGICROOMENDS]                        = COMPOUND_STRING("¡Zona Mágica ha terminado y los objetos vuelven a tener efecto!"),
    [STRINGID_MUDSPORTENDS]                         = COMPOUND_STRING("Chapoteolodo ha dejado de hacer efecto."),
    [STRINGID_WATERSPORTENDS]                       = COMPOUND_STRING("Hidrochorro ha dejado de hacer efecto."),
    [STRINGID_GRAVITYENDS]                          = COMPOUND_STRING("¡La gravedad ha vuelto a la normalidad!"),
    [STRINGID_AQUARINGHEAL]                         = COMPOUND_STRING("¡Un velo de agua ha restaurado los PS de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ELECTRICTERRAINENDS]                  = COMPOUND_STRING("La electricidad ha desaparecido del terreno de combate."),
    [STRINGID_MISTYTERRAINENDS]                     = COMPOUND_STRING("La niebla ha desaparecido del terreno de combate."),
    [STRINGID_PSYCHICTERRAINENDS]                   = COMPOUND_STRING("¡El terreno de combate ha dejado de ser extraño!"),
    [STRINGID_GRASSYTERRAINENDS]                    = COMPOUND_STRING("La hierba ha desaparecido del terreno de combate."),
    [STRINGID_TARGETABILITYSTATRAISE]               = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} ha subido{B_BUFF2} {B_BUFF1}!"),
    [STRINGID_TARGETSSTATWASMAXEDOUT]               = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} ha maximizado {B_BUFF1}!"),
    [STRINGID_ATTACKERABILITYSTATRAISE]             = COMPOUND_STRING("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX2} ha subido{B_BUFF2} {B_BUFF1}!"),
    [STRINGID_POISONHEALHPUP]                       = COMPOUND_STRING("¡El envenenamiento ha curado un poco a {B_ATK_NAME_WITH_PREFIX2}!"), //don't think this message is displayed anymore
    [STRINGID_BADDREAMSDMG]                         = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} sufre un tormento!"),
    [STRINGID_MOLDBREAKERENTERS]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} rompe moldes!"),
    [STRINGID_TERAVOLTENTERS]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} desprende un aura chisporroteante!"),
    [STRINGID_TURBOBLAZEENTERS]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} desprende un aura llameante!"),
    [STRINGID_SLOWSTARTENTERS]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} tarda en arrancar!"),
    [STRINGID_SLOWSTARTEND]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} por fin se ha puesto en marcha!"),
    [STRINGID_SOLARPOWERHPDROP]                     = COMPOUND_STRING("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX2} le pasa factura!"), //don't think this message is displayed anymore
    [STRINGID_AFTERMATHDMG]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha resultado herido!"),
    [STRINGID_ANTICIPATIONACTIVATES]                = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha estremecido!"),
    [STRINGID_FOREWARNACTIVATES]                    = COMPOUND_STRING("¡{B_SCR_ABILITY} ha alertado a {B_SCR_NAME_WITH_PREFIX2} de {B_BUFF1} de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ICEBODYHPGAIN]                        = COMPOUND_STRING("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX2} le ha curado un poco!"), //don't think this message is displayed anymore
    [STRINGID_SNOWWARNINGHAIL]                      = COMPOUND_STRING("¡Ha empezado a granizar!"),
    [STRINGID_FRISKACTIVATES]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha cacheado a {B_DEF_NAME_WITH_PREFIX2} y ha encontrado {B_LAST_ITEM}!"),
    [STRINGID_UNNERVEENTERS]                        = COMPOUND_STRING("¡{B_EFF_TEAM1} está demasiado nervioso para comer Bayas!"),
    [STRINGID_HARVESTBERRY]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha recolectado {B_LAST_ITEM}!"),
    [STRINGID_PROTEANTYPECHANGE]                    = COMPOUND_STRING("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX2} lo ha convertido en tipo {B_BUFF1}!"),
    [STRINGID_SYMBIOSISITEMPASS]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha pasado {B_LAST_ITEM} a {B_EFF_NAME_WITH_PREFIX2} gracias a {B_LAST_ABILITY}!"),
    [STRINGID_STEALTHROCKDMG]                       = COMPOUND_STRING("¡Las piedras puntiagudas han herido a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_TOXICSPIKESABSORBED]                  = COMPOUND_STRING("¡Las púas tóxicas han desaparecido del suelo alrededor de {B_EFF_TEAM2}!"),
    [STRINGID_TOXICSPIKESPOISONED]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha sido envenenado!"),
    [STRINGID_TOXICSPIKESBADLYPOISONED]             = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha sido gravemente envenenado!"),
    [STRINGID_STICKYWEBSWITCHIN]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha quedado atrapado en una red pegajosa!"),
    [STRINGID_HEALINGWISHCAMETRUE]                  = COMPOUND_STRING("¡El Deseo Cura de {B_SCR_NAME_WITH_PREFIX2} se ha hecho realidad!"),
    [STRINGID_HEALINGWISHHEALED]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha recuperado la salud!"),
    [STRINGID_LUNARDANCECAMETRUE]                   = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha envuelto en una mística luz de luna!"),
    [STRINGID_CURSEDBODYDISABLED]                   = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} ha anulado {B_BUFF1} de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ATTACKERACQUIREDABILITY]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha adquirido {B_ATK_ABILITY}!"),
    [STRINGID_TARGETABILITYSTATLOWER]               = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} ha bajado{B_BUFF2} {B_BUFF1}!"),
    [STRINGID_TARGETSTATWONTGOHIGHER]               = COMPOUND_STRING("¡No puede subir más {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNMOVEBOUNCEDABILITY]               = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} ha devuelto {B_CURRENT_MOVE} de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_IMPOSTERTRANSFORM]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha transformado en {B_DEF_NAME_WITH_PREFIX2} gracias a {B_LAST_ABILITY}!"),
    [STRINGID_ASSAULTVESTDOESNTALLOW]               = COMPOUND_STRING("¡Los efectos de {B_LAST_ITEM} impiden usar movimientos de estado!\p"),
    [STRINGID_GRAVITYPREVENTSUSAGE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar {B_CURRENT_MOVE} por la gravedad!\p"),
    [STRINGID_HEALBLOCKPREVENTSUSAGE]               = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede curarse!\p"),
    [STRINGID_NOTDONEYET]                           = COMPOUND_STRING("¡El efecto de este movimiento aún no está programado!\p"),
    [STRINGID_STICKYWEBUSED]                        = COMPOUND_STRING("¡Se ha extendido una red pegajosa por el suelo alrededor de {B_DEF_TEAM2}!"),
    [STRINGID_QUASHSUCCESS]                         = COMPOUND_STRING("¡Se ha aplazado el movimiento de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha librado de Púas Tóxicas!"),
    [STRINGID_PKMNBLEWAWAYSTICKYWEB]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha librado de Red Viscosa!"),
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha librado de Trampa Rocas!"),
    [STRINGID_IONDELUGEON]                          = COMPOUND_STRING("¡Una lluvia de iones cae sobre el terreno de combate!"),
    [STRINGID_TOPSYTURVYSWITCHEDSTATS]              = COMPOUND_STRING("¡Se han invertido los cambios de características de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_TERRAINBECOMESMISTY]                  = COMPOUND_STRING("¡La niebla envuelve el terreno de combate!"),
    [STRINGID_TERRAINBECOMESGRASSY]                 = COMPOUND_STRING("¡La hierba ha cubierto el terreno de combate!"),
    [STRINGID_TERRAINBECOMESELECTRIC]               = COMPOUND_STRING("¡Una corriente eléctrica recorre el terreno de combate!"),
    [STRINGID_TERRAINBECOMESPSYCHIC]                = COMPOUND_STRING("¡El terreno de combate se ha vuelto extraño!"),
    [STRINGID_TARGETELECTRIFIED]                    = COMPOUND_STRING("¡Los movimientos de {B_DEF_NAME_WITH_PREFIX2} se han electrificado!"),
    [STRINGID_MEGAEVOREACTING]                      = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX2} reacciona al Megaaro de {B_ATK_TRAINER_NAME}!"), //actually displays the type of mega ring in inventory, but we didnt implement them :(
    [STRINGID_MEGAEVOEVOLVED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha megaevolucionado en Mega-{B_BUFF1}!"),
    [STRINGID_DRASTICALLY]                          = gText_drastically,
    [STRINGID_SEVERELY]                             = gText_severely,
    [STRINGID_INFESTATION]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha infestado a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_NOEFFECTONTARGET]                     = COMPOUND_STRING("¡No tendrá ningún efecto en {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BURSTINGFLAMESHIT]                    = COMPOUND_STRING("¡Las llamas han alcanzado a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_BESTOWITEMGIVING]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha recibido {B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THIRDTYPEADDED]                       = COMPOUND_STRING("¡Se ha añadido el tipo {B_BUFF1} a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_FELLFORFEINT]                         = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha caído en el engaño!"),
    [STRINGID_POKEMONCANNOTUSEMOVE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar {B_CURRENT_MOVE}!"),
    [STRINGID_COVEREDINPOWDER]                      = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} está cubierto de polvo!"),
    [STRINGID_POWDEREXPLODES]                       = COMPOUND_STRING("¡Al tocar la llama el polvo del Pokémon, se ha producido una explosión!"),
    [STRINGID_BELCHCANTSELECT]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no se ha comido ninguna Baya, así que no puede eructar!\p"),
    [STRINGID_SPECTRALTHIEFSTEAL]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha robado las mejoras de características del objetivo!"),
    [STRINGID_GRAVITYGROUNDING]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha caído al suelo por la gravedad!"),
    [STRINGID_MISTYTERRAINPREVENTS]                 = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se envuelve en una niebla protectora!"),
    [STRINGID_GRASSYTERRAINHEALS]                   = COMPOUND_STRING("¡El campo de hierba cura a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ELECTRICTERRAINPREVENTS]              = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se rodea de un campo electrificado!"),
    [STRINGID_PSYCHICTERRAINPREVENTS]               = COMPOUND_STRING("¡El campo psíquico protege a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_SAFETYGOGGLESPROTECTED]               = COMPOUND_STRING("¡{B_LAST_ITEM} protege a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_FLOWERVEILPROTECTED]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha rodeado de un velo de pétalos!"),
    [STRINGID_AROMAVEILPROTECTED]                   = COMPOUND_STRING("¡Un velo aromático protege a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_CELEBRATEMESSAGE]                     = COMPOUND_STRING("¡Felicidades, {B_PLAYER_NAME}!"),
    [STRINGID_USEDINSTRUCTEDMOVE]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha seguido las instrucciones de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THROATCHOPENDS]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} vuelve a poder usar movimientos de sonido!"),
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP]            = COMPOUND_STRING("¡Los efectos de Golpe Mordaza impiden a {B_ATK_NAME_WITH_PREFIX2} usar ciertos movimientos!\p"),
    [STRINGID_LASERFOCUS]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha concentrado al máximo!"),
    [STRINGID_GEMACTIVATES]                         = COMPOUND_STRING("¡{B_LAST_ITEM} ha potenciado el ataque de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_BERRYDMGREDUCES]                      = COMPOUND_STRING("¡{B_LAST_ITEM} ha reducido el daño a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRBALLOONFLOAT]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} flota en el aire con su Globo Helio!"),
    [STRINGID_AIRBALLOONPOP]                        = COMPOUND_STRING("¡El Globo Helio de {B_DEF_NAME_WITH_PREFIX2} ha explotado!"),
    [STRINGID_INCINERATEBURN]                       = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX2} se ha quemado!"),
    [STRINGID_BUGBITE]                              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha robado y se ha comido {B_LAST_ITEM} del objetivo!"),
    [STRINGID_ILLUSIONWOREOFF]                      = COMPOUND_STRING("¡La ilusión de {B_SCR_NAME_WITH_PREFIX2} se ha desvanecido!"),
    [STRINGID_ATTACKERCUREDTARGETSTATUS]            = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha curado el problema de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ATTACKERLOSTFIRETYPE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha consumido por completo!"),
    [STRINGID_HEALERCURE]                           = COMPOUND_STRING("¡{B_LAST_ABILITY} de {B_ATK_NAME_WITH_PREFIX2} ha curado el problema de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_SCRIPTINGABILITYSTATRAISE]            = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} ha subido{B_BUFF2} {B_BUFF1}!"),
    [STRINGID_RECEIVERABILITYTAKEOVER]              = COMPOUND_STRING("¡Se ha adoptado {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKNMABSORBINGPOWER]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está absorbiendo energía!"),
    [STRINGID_NOONEWILLBEABLETORUNAWAY]             = COMPOUND_STRING("¡Nadie podrá huir durante el próximo turno!"),
    [STRINGID_DESTINYKNOTACTIVATES]                 = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha enamorado por {B_LAST_ITEM}!"),
    [STRINGID_CLOAKEDINAFREEZINGLIGHT]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha envuelto en una luz gélida!"),
    [STRINGID_CLEARAMULETWONTLOWERSTATS]            = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} impide que bajen sus características!"),
    [STRINGID_FERVENTWISHREACHED]                   = COMPOUND_STRING("¡El ferviente deseo de {B_ATK_TRAINER_NAME} ha llegado hasta {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRLOCKACTIVATES]                     = COMPOUND_STRING("Los efectos del tiempo atmosférico han desaparecido."),
    [STRINGID_PRESSUREENTERS]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ejerce presión!"),
    [STRINGID_DARKAURAENTERS]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} desprende un aura oscura!"),
    [STRINGID_FAIRYAURAENTERS]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} desprende un aura feérica!"),
    [STRINGID_AURABREAKENTERS]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha invertido las auras de los demás Pokémon!"),
    [STRINGID_COMATOSEENTERS]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} está adormilado!"),
    [STRINGID_SCREENCLEANERENTERS]                  = COMPOUND_STRING("¡Se han eliminado todas las barreras del terreno de combate!"),
    [STRINGID_FETCHEDPOKEBALL]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha encontrado una {B_LAST_ITEM}!"),
    [STRINGID_ASANDSTORMKICKEDUP]                   = COMPOUND_STRING("¡Se ha desatado una tormenta de arena!"),
    [STRINGID_PKMNSWILLPERISHIN3TURNS]              = COMPOUND_STRING("¡Ambos Pokémon se debilitarán en tres turnos!"),  //don't think this message is displayed anymore
    [STRINGID_AURAFLAREDTOLIFE]                     = COMPOUND_STRING("¡El aura de {B_DEF_NAME_WITH_PREFIX2} se ha avivado!"),
    [STRINGID_ASONEENTERS]                          = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} tiene dos habilidades!"),
    [STRINGID_CURIOUSMEDICINEENTERS]                = COMPOUND_STRING("¡Se han eliminado los cambios de características de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_CANACTFASTERTHANKSTO]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} puede actuar más rápido gracias a {B_BUFF1}!"),
    [STRINGID_MICLEBERRYACTIVATES]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha aumentado la precisión de su próximo movimiento con {B_LAST_ITEM}!"),
    [STRINGID_PKMNSHOOKOFFTHETAUNT]                 = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha librado de la provocación!"),
    [STRINGID_PKMNGOTOVERITSINFATUATION]            = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya no está enamorado!"),
    [STRINGID_ITEMCANNOTBEREMOVED]                  = COMPOUND_STRING("¡El objeto de {B_ATK_NAME_WITH_PREFIX2} no se puede quitar!"),
    [STRINGID_STICKYBARBTRANSFER]                   = COMPOUND_STRING("¡{B_LAST_ITEM} se ha pegado a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBURNHEALED]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no está quemado!"),
    [STRINGID_REDCARDACTIVATE]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha sacado la Tarjeta Roja a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_EJECTBUTTONACTIVATE]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se ha retirado gracias a {B_LAST_ITEM}!"),
    [STRINGID_ATKGOTOVERINFATUATION]                = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya no está enamorado!"),
    [STRINGID_TORMENTEDNOMORE]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya no sufre ningún tormento!"),
    [STRINGID_HEALBLOCKEDNOMORE]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya puede volver a curarse!"),
    [STRINGID_ATTACKERBECAMEFULLYCHARGED]           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está totalmente cargado por el vínculo con su Entrenador!\p"),
    [STRINGID_ATTACKERBECAMEASHSPECIES]             = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha convertido en Greninja-Ash!\p"),
    [STRINGID_EXTREMELYHARSHSUNLIGHT]               = COMPOUND_STRING("¡El sol pega muy fuerte!"),
    [STRINGID_EXTREMESUNLIGHTFADED]                 = COMPOUND_STRING("¡El sol ya no pega con tanta fuerza!"),
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT]     = COMPOUND_STRING("¡El ataque de tipo Agua se ha evaporado por el sol abrasador!"),
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED] = COMPOUND_STRING("¡El sol abrasador no ha perdido nada de fuerza!"),
    [STRINGID_HEAVYRAIN]                            = COMPOUND_STRING("¡Ha empezado a diluviar!"),
    [STRINGID_HEAVYRAINLIFTED]                      = COMPOUND_STRING("¡Ha dejado de diluviar!"),
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN]         = COMPOUND_STRING("¡El ataque de tipo Fuego se ha apagado por el diluvio!"),
    [STRINGID_NORELIEFROMHEAVYRAIN]                 = COMPOUND_STRING("¡El diluvio no da tregua!"),
    [STRINGID_MYSTERIOUSAIRCURRENT]                 = COMPOUND_STRING("¡Unas misteriosas turbulencias protegen a los Pokémon de tipo Volador!"),
    [STRINGID_STRONGWINDSDISSIPATED]                = COMPOUND_STRING("¡Las misteriosas turbulencias se han disipado!"),
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON]          = COMPOUND_STRING("¡Las misteriosas turbulencias siguen soplando!"),
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS]           = COMPOUND_STRING("¡Las misteriosas turbulencias han debilitado el ataque!"),
    [STRINGID_STUFFCHEEKSCANTSELECT]                = COMPOUND_STRING("¡No puede usar el movimiento porque no tiene ninguna Baya!\p"),
    [STRINGID_PKMNREVERTEDTOPRIMAL]                 = COMPOUND_STRING("¡Regresión Primigenia de {B_SCR_NAME_WITH_PREFIX2}! ¡Ha vuelto a su estado primigenio!"),
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE]             = COMPOUND_STRING("¡Pero {B_ATK_NAME_WITH_PREFIX2} no puede usar el movimiento!"),
    [STRINGID_BUTHOOPACANTUSEIT]                    = COMPOUND_STRING("¡Pero {B_ATK_NAME_WITH_PREFIX2} no puede usarlo tal y como está ahora!"),
    [STRINGID_BROKETHROUGHPROTECTION]               = COMPOUND_STRING("¡Ha atravesado la protección de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ABILITYALLOWSONLYMOVE]                = COMPOUND_STRING("¡{B_ATK_ABILITY} solo permite usar {B_CURRENT_MOVE}!\p"),
    [STRINGID_SWAPPEDABILITIES]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha intercambiado su habilidad con su objetivo!"),
    [STRINGID_PASTELVEILENTERS]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no está envenenado!"),
    [STRINGID_BATTLERTYPECHANGEDTO]                 = COMPOUND_STRING("¡El tipo de {B_SCR_NAME_WITH_PREFIX2} ha cambiado a {B_BUFF1}!"),
    [STRINGID_BOTHCANNOLONGERESCAPE]                = COMPOUND_STRING("¡Ninguno de los dos Pokémon puede huir!"),
    [STRINGID_CANTESCAPEDUETOUSEDMOVE]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya no puede escapar por haber usado Bastión Final!"),
    [STRINGID_PKMNBECAMEWEAKERTOFIRE]               = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha vuelto más débil al fuego!"),
    [STRINGID_ABOUTTOUSEPOLTERGEIST]                = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} va a ser atacado por su {B_BUFF1}!"),
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE]       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no puede escapar por Octopresa!"),
    [STRINGID_NEUTRALIZINGGASENTERS]                = COMPOUND_STRING("¡Un gas reactivo inunda la zona!"),
    [STRINGID_NEUTRALIZINGGASOVER]                  = COMPOUND_STRING("¡Los efectos del gas reactivo han desaparecido!"),
    [STRINGID_TARGETTOOHEAVY]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} pesa demasiado para levantarlo!"),
    [STRINGID_PKMNTOOKTARGETHIGH]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha llevado a {B_DEF_NAME_WITH_PREFIX2} por los aires!"),
    [STRINGID_PKMNINSNAPTRAP]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha caído en un cepo!"),
    [STRINGID_METEORBEAMCHARGING]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} rebosa energía cósmica!"),
    [STRINGID_HEATUPBEAK]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha empezado a calentar el pico!"),
    [STRINGID_COURTCHANGE]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha intercambiado los efectos de ambos lados del terreno!"),
    [STRINGID_ZPOWERSURROUNDS]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha rodeado de su poder Z!"),
    [STRINGID_ZMOVEUNLEASHED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} desata su movimiento Z con todas sus fuerzas!"),
    [STRINGID_ZMOVERESETSSTATS]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha restablecido sus características con su poder Z!"),
    [STRINGID_ZMOVEALLSTATSUP]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha aumentado sus características con su poder Z!"),
    [STRINGID_ZMOVEZBOOSTCRIT]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha aumentado su índice de golpe crítico con su poder Z!"),
    [STRINGID_ZMOVERESTOREHP]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha recuperado PS con su poder Z!"),
    [STRINGID_ZMOVESTATUP]                          = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha aumentado sus características con su poder Z!"),
    [STRINGID_ZMOVEHPTRAP]                          = COMPOUND_STRING("¡El poder Z ha restaurado los PS de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_ATTACKEREXPELLEDTHEPOISON]            = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha expulsado el veneno para que no te preocupes!"),
    [STRINGID_ATTACKERSHOOKITSELFAWAKE]             = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha despertado solo para que no te preocupes!"),
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS]        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha reunido fuerzas para superar la parálisis y que no te preocupes!"),
    [STRINGID_ATTACKERHEALEDITSBURN]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha curado la quemadura a fuerza de voluntad para que no te preocupes!"),
    [STRINGID_ATTACKERMELTEDTHEICE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha derretido el hielo con su ardiente determinación para que no te preocupes!"),
    [STRINGID_TARGETTOUGHEDITOUT]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha aguantado para que no te pongas triste!"),
    [STRINGID_ATTACKERLOSTELECTRICTYPE]             = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha gastado toda su electricidad!"),
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET]       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha intercambiado {B_BUFF1} con su objetivo!"),
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER]         = COMPOUND_STRING("¡Recibir {B_CURRENT_MOVE} ha cargado de energía a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_SUNLIGHTACTIVATEDABILITY]             = COMPOUND_STRING("¡El sol abrasador ha activado Paleosíntesis de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_STATWASHEIGHTENED]                    = COMPOUND_STRING("¡Ha aumentado {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY]      = COMPOUND_STRING("¡El campo eléctrico ha activado Carga Cuark de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_ABILITYWEAKENEDSURROUNDINGMONSSTAT]   = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} ha debilitado {B_BUFF1} de todos los Pokémon de alrededor!\p"),
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN]  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha recibido la fuerza de los caídos!"),
    [STRINGID_PKMNSABILITYPREVENTSABILITY]          = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX2} impide que funcione {B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PREPARESHELLTRAP]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha colocado una coraza trampa!"),
    [STRINGID_SHELLTRAPDIDNTWORK]                   = COMPOUND_STRING("¡La coraza trampa de {B_ATK_NAME_WITH_PREFIX2} no ha funcionado!"),
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM]            = COMPOUND_STRING("¡Las púas han desaparecido del suelo alrededor de {B_ATK_TEAM2}!"),
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("¡Las púas tóxicas han desaparecido del suelo alrededor de {B_ATK_TEAM2}!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM]         = COMPOUND_STRING("¡La red pegajosa ha desaparecido del suelo alrededor de {B_ATK_TEAM2}!"),
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("¡Las piedras puntiagudas han desaparecido de alrededor de {B_ATK_TEAM2}!"),
    [STRINGID_COULDNTFULLYPROTECT]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} no ha podido protegerse del todo y ha resultado herido!"),
    [STRINGID_STOCKPILEDEFFECTWOREOFF]              = COMPOUND_STRING("¡El efecto de Reserva de {B_ATK_NAME_WITH_PREFIX2} ha desaparecido!"),
    [STRINGID_PKMNREVIVEDREADYTOFIGHT]              = COMPOUND_STRING("¡{B_BUFF1} ha revivido y está listo para volver a luchar!"),
    [STRINGID_ITEMRESTOREDSPECIESHEALTH]            = COMPOUND_STRING("{B_BUFF1} ha recuperado sus PS."),
    [STRINGID_ITEMCUREDSPECIESSTATUS]               = COMPOUND_STRING("¡{B_BUFF1} se ha curado de su problema de estado!"),
    [STRINGID_ITEMRESTOREDSPECIESPP]                = COMPOUND_STRING("¡{B_BUFF1} ha recuperado sus PP!"),
    [STRINGID_THUNDERCAGETRAPPED]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha atrapado a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBYFROSTBITE]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se resiente del congelamiento!"),
    [STRINGID_PKMNGOTFROSTBITE]                     = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} ha sufrido congelamiento!"),
    [STRINGID_PKMNSITEMHEALEDFROSTBITE]             = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX2} le ha curado el congelamiento!"),
    [STRINGID_ATTACKERHEALEDITSFROSTBITE]           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha curado el congelamiento a fuerza de voluntad para que no te preocupes!"),
    [STRINGID_PKMNFROSTBITEHEALED]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya no sufre congelamiento!"),
    [STRINGID_PKMNFROSTBITEHEALEDBY]                = COMPOUND_STRING("¡{B_CURRENT_MOVE} de {B_SCR_NAME_WITH_PREFIX2} le ha curado el congelamiento!"),
    [STRINGID_MIRRORHERBCOPIED]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha usado su Hierba Copia para imitar los cambios de características del rival!"),
    [STRINGID_STARTEDSNOW]                          = COMPOUND_STRING("¡Ha empezado a nevar!"),
    [STRINGID_SNOWCONTINUES]                        = COMPOUND_STRING("Sigue nevando."), //not in gen 5+ (lol)
    [STRINGID_SNOWSTOPPED]                          = COMPOUND_STRING("Ha dejado de nevar."),
    [STRINGID_SNOWWARNINGSNOW]                      = COMPOUND_STRING("¡Ha empezado a nevar!"),
    [STRINGID_PKMNITEMMELTED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha corroído {B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ULTRABURSTREACTING]                   = COMPOUND_STRING("¡Una luz intensa está a punto de brotar de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ULTRABURSTCOMPLETED]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha recuperado su verdadero poder gracias al Ultraestallido!"),
    [STRINGID_TEAMGAINEDEXP]                        = COMPOUND_STRING("¡El resto de tu equipo ha ganado puntos de experiencia gracias al Repartir Exp.!\p"),
    [STRINGID_CURRENTMOVECANTSELECT]                = COMPOUND_STRING("¡No se puede usar {B_BUFF1}!\p"),
    [STRINGID_TARGETISBEINGSALTCURED]               = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} está sufriendo los efectos de Salazón!"),
    [STRINGID_TARGETISHURTBYSALTCURE]               = COMPOUND_STRING("¡{B_BUFF1} hiere a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP]      = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se ha cubierto de un almíbar pegajoso!"),
    [STRINGID_SHARPSTEELFLOATS]                     = COMPOUND_STRING("¡Unas afiladas piezas de acero flotan alrededor de los Pokémon de {B_DEF_TEAM2}!"),
    [STRINGID_SHARPSTEELDMG]                        = COMPOUND_STRING("¡El acero afilado ha herido a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL]               = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha librado del acero afilado!"),
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM]        = COMPOUND_STRING("¡Las piezas de acero que rodeaban a los Pokémon de {B_ATK_TEAM2} han desaparecido!"),
    [STRINGID_TEAMTRAPPEDWITHVINES]                 = COMPOUND_STRING("¡Los Pokémon de {B_DEF_TEAM2} han quedado atrapados entre lianas!"),
    [STRINGID_PKMNHURTBYVINES]                      = COMPOUND_STRING("¡Los latigazos de Gigalianas golpean a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_TEAMCAUGHTINVORTEX]                   = COMPOUND_STRING("¡Los Pokémon de {B_DEF_TEAM2} han quedado atrapados en un remolino!"),
    [STRINGID_PKMNHURTBYVORTEX]                     = COMPOUND_STRING("¡El remolino de Gigacañonazo hiere a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_TEAMSURROUNDEDBYFIRE]                 = COMPOUND_STRING("¡Los Pokémon de {B_DEF_TEAM2} han quedado rodeados de fuego!"),
    [STRINGID_PKMNBURNINGUP]                        = COMPOUND_STRING("¡Las llamas de Gigallamarada abrasan a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_TEAMSURROUNDEDBYROCKS]                = COMPOUND_STRING("¡Los Pokémon de {B_DEF_TEAM2} han quedado rodeados de rocas!"),
    [STRINGID_PKMNHURTBYROCKSTHROWN]                = COMPOUND_STRING("¡Las rocas de Gigavulcano hieren a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_MOVEBLOCKEDBYDYNAMAX]                 = COMPOUND_STRING("¡El poder del Dinamax ha bloqueado el movimiento!"),
    [STRINGID_ZEROTOHEROTRANSFORMATION]             = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha experimentado una transformación heroica!"),
    [STRINGID_THETWOMOVESBECOMEONE]                 = COMPOUND_STRING("¡Los dos movimientos se han unido! ¡Es un movimiento combinado!{PAUSE 16}"),
    [STRINGID_ARAINBOWAPPEAREDONSIDE]               = COMPOUND_STRING("¡Ha aparecido un arcoíris en el cielo del lado de {B_ATK_TEAM2}!"),
    [STRINGID_THERAINBOWDISAPPEARED]                = COMPOUND_STRING("¡El arcoíris del lado de {B_ATK_TEAM2} ha desaparecido!"),
    [STRINGID_WAITINGFORPARTNERSMOVE]               = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está esperando el movimiento de {B_ATK_PARTNER_NAME}…!{PAUSE 16}"),
    [STRINGID_SEAOFFIREENVELOPEDSIDE]               = COMPOUND_STRING("¡Un mar de llamas ha envuelto a {B_DEF_TEAM2}!"),
    [STRINGID_HURTBYTHESEAOFFIRE]                   = COMPOUND_STRING("¡El mar de llamas ha herido a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THESEAOFFIREDISAPPEARED]              = COMPOUND_STRING("¡El mar de llamas alrededor de {B_ATK_TEAM2} ha desaparecido!"),
    [STRINGID_SWAMPENVELOPEDSIDE]                   = COMPOUND_STRING("¡Un pantano ha envuelto a {B_DEF_TEAM2}!"),
    [STRINGID_THESWAMPDISAPPEARED]                  = COMPOUND_STRING("¡El pantano alrededor de {B_ATK_TEAM2} ha desaparecido!"),
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE]        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se prepara para contar un chiste malísimo!"),
    [STRINGID_HOSPITALITYRESTORATION]               = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se ha bebido todo el matcha que ha preparado {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_ELECTROSHOTCHARGING]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha absorbido electricidad!"),
    [STRINGID_ITEMWASUSEDUP]                        = COMPOUND_STRING("Se ha gastado {B_LAST_ITEM}…"),
    [STRINGID_ATTACKERLOSTITSTYPE]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha perdido el tipo {B_BUFF1}!"),
    [STRINGID_SHEDITSTAIL]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha desprendido de la cola para crear un señuelo!"),
    [STRINGID_CLOAKEDINAHARSHLIGHT]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha envuelto en una luz intensa!"),
    [STRINGID_SUPERSWEETAROMAWAFTS]                 = COMPOUND_STRING("¡Un aroma dulcísimo emana del almíbar que cubre a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_DIMENSIONSWERETWISTED]                = COMPOUND_STRING("¡Las dimensiones se han distorsionado!"),
    [STRINGID_BIZARREARENACREATED]                  = COMPOUND_STRING("¡Se ha creado un espacio extraño en el que los objetos pierden su efecto!"),
    [STRINGID_BIZARREAREACREATED]                   = COMPOUND_STRING("¡Se ha creado un espacio extraño en el que se intercambian la DEFENSA y la DEF. ESP.!"),
    [STRINGID_TIDYINGUPCOMPLETE]                    = COMPOUND_STRING("¡Limpieza completada!"),
    [STRINGID_PKMNTERASTALLIZEDINTO]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha teracristalizado en tipo {B_BUFF1}!"),
    [STRINGID_BOOSTERENERGYACTIVATES]               = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ha usado {B_LAST_ITEM} para activar {B_SCR_ABILITY}!"),
    [STRINGID_FOGCREPTUP]                           = COMPOUND_STRING("¡Ha aparecido una niebla muy espesa!"),
    [STRINGID_FOGISDEEP]                            = COMPOUND_STRING("La niebla es muy densa…"),
    [STRINGID_FOGLIFTED]                            = COMPOUND_STRING("La niebla se ha disipado."),
    [STRINGID_PKMNMADESHELLGLEAM]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ha hecho brillar su caparazón! ¡Distorsiona la eficacia de los tipos!"),
    [STRINGID_FICKLEBEAMDOUBLED]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} lo da todo en este ataque!"),
    [STRINGID_COMMANDERACTIVATES]                   = COMPOUND_STRING("¡Dondozo se ha tragado a {B_SCR_NAME_WITH_PREFIX2} y ahora es su comandante!"),
    [STRINGID_POKEFLUTECATCHY]                      = COMPOUND_STRING("{B_PLAYER_NAME} ha tocado {B_LAST_ITEM}.\p¡Qué melodía tan pegadiza!"),
    [STRINGID_POKEFLUTE]                            = COMPOUND_STRING("{B_PLAYER_NAME} ha tocado {B_LAST_ITEM}."),
    [STRINGID_MONHEARINGFLUTEAWOKE]                 = COMPOUND_STRING("¡Los Pokémon que han oído la flauta se han despertado!"),
    [STRINGID_SUNLIGHTISHARSH]                      = COMPOUND_STRING("¡El sol pega fuerte!"),
    [STRINGID_ITISHAILING]                          = COMPOUND_STRING("¡Está granizando!"),
    [STRINGID_ITISSNOWING]                          = COMPOUND_STRING("¡Está nevando!"),
    [STRINGID_ISCOVEREDWITHGRASS]                   = COMPOUND_STRING("¡El terreno de combate está cubierto de hierba!"),
    [STRINGID_MISTSWIRLSAROUND]                     = COMPOUND_STRING("¡La niebla envuelve el terreno de combate!"),
    [STRINGID_ELECTRICCURRENTISRUNNING]             = COMPOUND_STRING("¡Una corriente eléctrica recorre el terreno de combate!"),
    [STRINGID_SEEMSWEIRD]                           = COMPOUND_STRING("¡El terreno de combate parece extraño!"),
    [STRINGID_WAGGLINGAFINGER]                      = COMPOUND_STRING("¡Moviendo un dedo ha usado {B_CURRENT_MOVE}!"),
    [STRINGID_BLOCKEDBYSLEEPCLAUSE]                 = COMPOUND_STRING("¡La cláusula de sueño ha mantenido despierto a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_SUPEREFFECTIVETWOFOES]                = COMPOUND_STRING("¡Es muy eficaz contra {B_DEF_NAME_WITH_PREFIX2} y {B_DEF_PARTNER_NAME}!"),
    [STRINGID_NOTVERYEFFECTIVETWOFOES]              = COMPOUND_STRING("¡No es muy eficaz contra {B_DEF_NAME_WITH_PREFIX2} y {B_DEF_PARTNER_NAME}!"),
    [STRINGID_ITDOESNTAFFECTTWOFOES]                = COMPOUND_STRING("No afecta a {B_DEF_NAME_WITH_PREFIX2} ni a {B_DEF_PARTNER_NAME}…"),
    [STRINGID_SENDCAUGHTMONPARTYORBOX]              = COMPOUND_STRING("¿Quieres añadir a {B_DEF_NAME} a tu equipo?"),
    [STRINGID_PKMNSENTTOPCAFTERCATCH]               = gText_PkmnSentToPCAfterCatch,
    [STRINGID_PKMNDYNAMAXED]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha hecho enorme con el Dinamax!"),
    [STRINGID_PKMNGIGANTAMAXED]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha hecho enorme con el Gigamax!"),
    [STRINGID_TIMETODYNAMAX]                        = COMPOUND_STRING("¡Hora del Dinamax!"),
    [STRINGID_TIMETOGIGANTAMAX]                     = COMPOUND_STRING("¡Hora del Gigamax!"),
    [STRINGID_QUESTIONFORFEITBATTLE]                = COMPOUND_STRING("¿Quieres rendirte? Abandonar el combate equivale a perderlo."),
    [STRINGID_POWERCONSTRUCTPRESENCEOFMANY]         = COMPOUND_STRING("¡Percibes la presencia de muchos!"),
    [STRINGID_POWERCONSTRUCTTRANSFORM]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se ha transformado en su Forma Completa!"),
    [STRINGID_ABILITYSHIELDPROTECTS]                = COMPOUND_STRING("¡Los efectos de {B_LAST_ITEM} protegen la habilidad de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_MONTOOSCAREDTOMOVE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está demasiado asustado para moverse!"),
    [STRINGID_GHOSTGETOUTGETOUT]                    = COMPOUND_STRING("FANTASMA: Vete…… Vete……"),
    [STRINGID_SILPHSCOPEUNVEILED]                   = COMPOUND_STRING("¡El SILPH SCOPE ha revelado la\nidentidad del FANTASMA!"),
    [STRINGID_GHOSTWASMAROWAK]                      = COMPOUND_STRING("¡El FANTASMA era MAROWAK!\p\n"),
    [STRINGID_TRAINER1MON1COMEBACK]                 = COMPOUND_STRING("{B_TRAINER1_NAME}: ¡{B_OPPONENT_MON1_NAME}, vuelve!"),
    [STRINGID_THREWROCK]                            = COMPOUND_STRING("¡{B_PLAYER_NAME} ha lanzado una ROCA\na {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_THREWBAIT]                            = COMPOUND_STRING("¡{B_PLAYER_NAME} ha lanzado CEBO\na {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_PKMNANGRY]                            = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} está enfadado!"),
    [STRINGID_PKMNEATING]                           = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} está comiendo!"),
    [STRINGID_PKMNDISGUISEWASBUSTED]                = COMPOUND_STRING("¡El disfraz de {B_SCR_NAME_WITH_PREFIX2} se ha roto!"),
    [STRINGID_ZENMODETRIGGERED]                     = COMPOUND_STRING("¡Se ha activado {B_SCR_ABILITY}!"),
    [STRINGID_ZENMODEENDED]                         = COMPOUND_STRING("¡{B_SCR_ABILITY} ha terminado!"),
    [STRINGID_WILDPKMNDROPPEDITEM]                  = COMPOUND_STRING("¡El Pokémon salvaje ha soltado\n{B_LAST_ITEM}!\p"),
    [STRINGID_DROPPEDITEMBAGFULL]                   = COMPOUND_STRING("El Pokémon salvaje ha soltado un objeto,\npero tu Mochila está llena.\p"),
};

const u16 gTrainerUsedItemStringIds[] =
{
    STRINGID_PLAYERUSEDITEM, STRINGID_TRAINER1USEDITEM
};

const u16 gZEffectStringIds[] =
{
    [B_MSG_Z_RESET_STATS] = STRINGID_ZMOVERESETSSTATS,
    [B_MSG_Z_ALL_STATS_UP]= STRINGID_ZMOVEALLSTATSUP,
    [B_MSG_Z_BOOST_CRITS] = STRINGID_ZMOVEZBOOSTCRIT,
    [B_MSG_Z_FOLLOW_ME]   = STRINGID_PKMNCENTERATTENTION,
    [B_MSG_Z_RECOVER_HP]  = STRINGID_ZMOVERESTOREHP,
    [B_MSG_Z_STAT_UP]     = STRINGID_ZMOVESTATUP,
    [B_MSG_Z_HP_TRAP]     = STRINGID_ZMOVEHPTRAP,
};

const u16 gMentalHerbCureStringIds[] =
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_BUFFERENDS,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
};

const u16 gStartingStatusStringIds[B_MSG_STARTING_STATUS_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_SET_TRICK_ROOM]       = STRINGID_DIMENSIONSWERETWISTED,
    [B_MSG_SET_MAGIC_ROOM]       = STRINGID_BIZARREARENACREATED,
    [B_MSG_SET_WONDER_ROOM]      = STRINGID_BIZARREAREACREATED,
    [B_MSG_SET_TAILWIND]         = STRINGID_TAILWINDBLEW,
    [B_MSG_SET_RAINBOW]          = STRINGID_ARAINBOWAPPEAREDONSIDE,
    [B_MSG_SET_SEA_OF_FIRE]      = STRINGID_SEAOFFIREENVELOPEDSIDE,
    [B_MSG_SET_SWAMP]            = STRINGID_SWAMPENVELOPEDSIDE,
    [B_MSG_SET_SPIKES]           = STRINGID_SPIKESSCATTERED,
    [B_MSG_SET_POISON_SPIKES]    = STRINGID_POISONSPIKESSCATTERED,
    [B_MSG_SET_STICKY_WEB]       = STRINGID_STICKYWEBUSED,
    [B_MSG_SET_STEALTH_ROCK]     = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SET_SHARP_STEEL]      = STRINGID_SHARPSTEELFLOATS,
};

const u16 gTerrainStringIds[B_MSG_TERRAIN_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY] = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC] = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY] = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_TERRAIN_END_MISTY] = STRINGID_MISTYTERRAINENDS,
    [B_MSG_TERRAIN_END_ELECTRIC] = STRINGID_ELECTRICTERRAINENDS,
    [B_MSG_TERRAIN_END_PSYCHIC] = STRINGID_PSYCHICTERRAINENDS,
    [B_MSG_TERRAIN_END_GRASSY] = STRINGID_GRASSYTERRAINENDS,
};

const u16 gTerrainPreventsStringIds[] =
{
    [B_MSG_TERRAINPREVENTS_MISTY]    = STRINGID_MISTYTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_ELECTRIC] = STRINGID_ELECTRICTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_PSYCHIC]  = STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE,
    STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    [B_MSG_PKMNHURTBYSPIKES]   = STRINGID_PKMNHURTBYSPIKES,
    [B_MSG_STEALTHROCKDMG]     = STRINGID_STEALTHROCKDMG,
    [B_MSG_SHARPSTEELDMG]      = STRINGID_SHARPSTEELDMG,
    [B_MSG_POINTEDSTONESFLOAT] = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SPIKESSCATTERED]    = STRINGID_SPIKESSCATTERED,
    [B_MSG_SHARPSTEELFLOATS]   = STRINGID_SHARPSTEELFLOATS,
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_PASTEL_VEIL] = STRINGID_PASTELVEILENTERS,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW]      = STRINGID_STARTEDSNOW,
    [B_MSG_STARTED_FOG]       = STRINGID_FOGCREPTUP, // Unused, can use for custom moves that set fog
};

const u16 gAbilityWeatherChangeStringId[] =
{
    [B_MSG_STARTED_DRIZZLE]        = STRINGID_PKMNMADEITRAIN,
    [B_MSG_STARTED_SAND_STREAM]    = STRINGID_PKMNSXWHIPPEDUPSANDSTORM,
    [B_MSG_STARTED_DROUGHT]        = STRINGID_PKMNSXINTENSIFIEDSUN,
    [B_MSG_STARTED_HAIL_WARNING]   = STRINGID_SNOWWARNINGHAIL,
    [B_MSG_STARTED_SNOW_WARNING]   = STRINGID_SNOWWARNINGSNOW,
    [B_MSG_STARTED_DESOLATE_LAND]  = STRINGID_EXTREMELYHARSHSUNLIGHT,
    [B_MSG_STARTED_PRIMORDIAL_SEA] = STRINGID_HEAVYRAIN,
    [B_MSG_STARTED_STRONG_WINDS]   = STRINGID_MYSTERIOUSAIRCURRENT,
};

const u16 gWeatherEndsStringIds[B_MSG_WEATHER_END_COUNT] =
{
    [B_MSG_WEATHER_END_RAIN]         = STRINGID_RAINSTOPPED,
    [B_MSG_WEATHER_END_SUN]          = STRINGID_SUNLIGHTFADED,
    [B_MSG_WEATHER_END_SANDSTORM]    = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_WEATHER_END_HAIL]         = STRINGID_HAILSTOPPED,
    [B_MSG_WEATHER_END_SNOW]         = STRINGID_SNOWSTOPPED,
    [B_MSG_WEATHER_END_FOG]          = STRINGID_FOGLIFTED,
    [B_MSG_WEATHER_END_STRONG_WINDS] = STRINGID_STRONGWINDSDISSIPATED,
};

const u16 gWeatherTurnStringIds[] =
{
    [B_MSG_WEATHER_TURN_RAIN]         = STRINGID_RAINCONTINUES,
    [B_MSG_WEATHER_TURN_DOWNPOUR]     = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_WEATHER_TURN_SUN]          = STRINGID_SUNLIGHTSTRONG,
    [B_MSG_WEATHER_TURN_SANDSTORM]    = STRINGID_SANDSTORMRAGES,
    [B_MSG_WEATHER_TURN_HAIL]         = STRINGID_HAILCONTINUES,
    [B_MSG_WEATHER_TURN_SNOW]         = STRINGID_SNOWCONTINUES,
    [B_MSG_WEATHER_TURN_FOG]          = STRINGID_FOGISDEEP,
    [B_MSG_WEATHER_TURN_STRONG_WINDS] = STRINGID_MYSTERIOUSAIRCURRENTBLOWSON,
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_CHANGED] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_CHANGED] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_CHANGE]      = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_CHANGE_EMPTY]     = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]         = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_CHANGED] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_CHANGED] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_CHANGE]      = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_CHANGE_EMPTY]     = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]     = STRINGID_USINGITEMSTATOFPKMNFELL,
};

// Index copied from move's index in sTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,     // MOVE_BIND
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,          // MOVE_WRAP
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_FIRE_SPIN
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,            // MOVE_CLAMP
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_WHIRLPOOL
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,  // MOVE_SAND_TOMB
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA, // MOVE_MAGMA_STORM
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,            // MOVE_INFESTATION
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,         // MOVE_SNAP_TRAP
    [B_MSG_WRAPPED_THUNDER_CAGE]= STRINGID_THUNDERCAGETRAPPED,     // MOVE_THUNDER_CAGE
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrostbiteStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNGOTFROSTBITE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNGOTFROSTBITE,
};

const u16 gFrostbiteHealedStringIds[] =
{
    [B_MSG_FROSTBITE_HEALED]         = STRINGID_PKMNFROSTBITEHEALED,
    [B_MSG_FROSTBITE_HEALED_BY_MOVE] = STRINGID_PKMNFROSTBITEHEALEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = (B_OVERWORLD_SNOW >= GEN_9 ? STRINGID_ITISSNOWING : STRINGID_ITISHAILING),
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_FOGISDEEP,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_FOGISDEEP,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTISHARSH,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gTerrainStartsStringIds[] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_MISTSWIRLSAROUND,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_ELECTRICCURRENTISRUNNING,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_SEEMSWEIRD,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_ISCOVEREDWITHGRASS,
};

const u16 gPrimalWeatherBlocksStringIds[] =
{
    [B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN]      = STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN,
    [B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN]    = STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT,
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariReactionStringIds[NUM_SAFARI_REACTIONS] =
{
    [B_MSG_MON_WATCHING] = STRINGID_PKMNWATCHINGCAREFULLY,
    [B_MSG_MON_ANGRY]    = STRINGID_PKMNANGRY,
    [B_MSG_MON_EATING]   = STRINGID_PKMNEATING
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 CureStatusBerryEffectStringID[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_PKMNSITEMCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_PKMNSITEMHEALEDBURN,
    [B_MSG_CURED_FREEEZE] = STRINGID_PKMNSITEMDEFROSTEDIT,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PKMNSITEMHEALEDFROSTBITE,
    [B_MSG_CURED_SLEEP] = STRINGID_PKMNSITEMWOKEIT,
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]   = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]   = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL]  = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL]  = STRINGID_PKMNBOXLANETTESPCFULL,
    [B_MSG_SWAPPED_INTO_PARTY] = STRINGID_PKMNSENTTOPCAFTERCATCH,
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP, STRINGID_PKMNGOTFROSTBITE
};

const u16 gDamageNonTypesStartStringIds[] =
{
    [B_MSG_TRAPPED_WITH_VINES]  = STRINGID_TEAMTRAPPEDWITHVINES,
    [B_MSG_CAUGHT_IN_VORTEX]    = STRINGID_TEAMCAUGHTINVORTEX,
    [B_MSG_SURROUNDED_BY_FIRE]  = STRINGID_TEAMSURROUNDEDBYFIRE,
    [B_MSG_SURROUNDED_BY_ROCKS] = STRINGID_TEAMSURROUNDEDBYROCKS,
};

const u16 gDamageNonTypesDmgStringIds[] =
{
    [B_MSG_HURT_BY_VINES]        = STRINGID_PKMNHURTBYVINES,
    [B_MSG_HURT_BY_VORTEX]       = STRINGID_PKMNHURTBYVORTEX,
    [B_MSG_BURNING_UP]           = STRINGID_PKMNBURNINGUP,
    [B_MSG_HURT_BY_ROCKS_THROWN] = STRINGID_PKMNHURTBYROCKSTHROWN,
};

const u16 gDefogHazardsStringIds[] =
{
    [HAZARDS_SPIKES] = STRINGID_SPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STICKY_WEB] = STRINGID_STICKYWEBDISAPPEAREDFROMTEAM,
    [HAZARDS_TOXIC_SPIKES] = STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STEALTH_ROCK] = STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM,
    [HAZARDS_STEELSURGE] = STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM,
};

const u16 gSpinHazardsStringIds[] =
{
    [HAZARDS_SPIKES] = STRINGID_PKMNBLEWAWAYSPIKES,
    [HAZARDS_STICKY_WEB] = STRINGID_PKMNBLEWAWAYSTICKYWEB,
    [HAZARDS_TOXIC_SPIKES] = STRINGID_PKMNBLEWAWAYTOXICSPIKES,
    [HAZARDS_STEALTH_ROCK] = STRINGID_PKMNBLEWAWAYSTEALTHROCK,
    [HAZARDS_STEELSURGE] = STRINGID_PKMNBLEWAWAYSHARPSTEEL,
};

const u16 gZenModeStringIds[] =
{
    [B_MSG_ZEN_MODE_TRIGGERED] = STRINGID_ZENMODETRIGGERED,
    [B_MSG_ZEN_MODE_ENDED] = STRINGID_ZENMODEENDED
};

const u8 gText_PkmnIsEvolving[] = _("¿Eh?\n¡{STR_VAR_1} está evolucionando!");
const u8 gText_CongratsPkmnEvolved[] = _("¡Enhorabuena! ¡Tu {STR_VAR_1}\nha evolucionado en {STR_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("¿Eh? ¡{STR_VAR_1}\nha dejado de evolucionar!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("¿Qué hará\n{B_BUFF1}?");
const u8 gText_WhatWillPkmnDo2[] = _("¿Qué hará\n{B_PLAYER_NAME}?");
const u8 gText_WhatWillWallyDo[] = _("¿Qué hará\nBLASCO?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Esperando conexión…");
const u8 gText_BattleMenu[] = _("LUCHAR{CLEAR_TO 56}{FONT_NARROW}MOCHILA{FONT_NORMAL}\nPOKéMON{CLEAR_TO 56}HUIR");
const u8 gText_SafariZoneMenu[] = _("BALL{CLEAR_TO 56}{POKEBLOCK}\nACERCARSE{CLEAR_TO 56}HUIR");
const u8 gText_SafariZoneMenuFrlg[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}BALL{CLEAR_TO 56}CEBO\nROCA{CLEAR_TO 56}HUIR");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TIPO/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}PP\nTIPO/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}¿Qué movimiento\ndebe olvidar?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}Sí\nNo");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}¿Cambiar\npor cuál?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");
const u8 gText_SafariBalls[] = _("SAFARI BALLS");
const u8 gText_SafariBallLeft[] = _("Quedan: $");
const u8 gText_Sleep[] = _("sueño");
const u8 gText_Poison[] = _("veneno");
const u8 gText_Burn[] = _("quemadura");
const u8 gText_Paralysis[] = _("parálisis");
const u8 gText_Ice[] = _("congelación");
const u8 gText_Confusion[] = _("confusión");
const u8 gText_Love[] = _("amor");
const u8 gText_SpaceAndSpace[] = _(" y ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("no pueden");
const u8 gText_Are2[] = _("no pueden");
const u8 gText_BadEgg[] = _("Huevo Malo");
const u8 gText_BattleWallyName[] = _("BLASCO");
const u8 gText_Win[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Victoria");
const u8 gText_Loss[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Derrota");
const u8 gText_Draw[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Empate");
static const u8 sText_SpaceIs[] = _(" is");
static const u8 sText_ApostropheS[] = _("'s");
const u8 gText_BattleTourney[] = _("TORNEO DE COMBATE");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = COMPOUND_STRING("Ronda 1"),
    [DOME_ROUND2]    = COMPOUND_STRING("Ronda 2"),
    [DOME_SEMIFINAL] = COMPOUND_STRING("Semifinal"),
    [DOME_FINAL]     = COMPOUND_STRING("Final"),
};

const u8 gText_TheGreatNewHope[] = _("¡La nueva gran esperanza!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("¿¡Hará realidad su sueño de ser campeón!?\p");
const u8 gText_AFormerChampion[] = _("¡Un antiguo campeón!\p");
const u8 gText_ThePreviousChampion[] = _("¡El anterior campeón!\p");
const u8 gText_TheUnbeatenChampion[] = _("¡El campeón invicto!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mente");
const u8 gText_Skill[] = _("Técnica");
const u8 gText_Body[] = _("Cuerpo");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Veredicto{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} sacó a {B_OPPONENT_MON1_NAME}!\p¡{B_TRAINER2_NAME_WITH_CLASS} sacó a {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("¡{B_TRAINER2_NAME_WITH_CLASS} sacó a {B_BUFF1}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} y {B_TRAINER2_NAME_WITH_CLASS} te desafían!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("¡{B_PARTNER_NAME_WITH_CLASS} sacó a {B_PLAYER_MON2_NAME}! ¡Adelante, {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerSentOutNGoZ[] = _("¡{B_PARTNER_NAME_WITH_CLASS} sacó a {B_PLAYER_MON1_NAME}! ¡Adelante, {B_PLAYER_MON2_NAME}!");
static const u8 sText_InGamePartnerSentOutPkmn1[] = _("¡{B_PARTNER_NAME_WITH_CLASS} sacó a {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerSentOutPkmn2[] = _("¡{B_PARTNER_NAME_WITH_CLASS} sacó a {B_PLAYER_MON2_NAME}!");
static const u8 sText_InGamePartnerWithdrewPkmn1[] = _("¡{B_PARTNER_NAME_WITH_CLASS} retiró a {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerWithdrewPkmn2[] = _("¡{B_PARTNER_NAME_WITH_CLASS} retiró a {B_PLAYER_MON2_NAME}!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = COMPOUND_STRING("ÁRBITRO: ¡Si no hay un resultado en 3 turnos, pasaremos a la valoración!"),
    [B_MSG_REF_THATS_IT]           = COMPOUND_STRING("ÁRBITRO: ¡Se acabó! ¡Pasamos a la valoración para decidir el ganador!"),
    [B_MSG_REF_JUDGE_MIND]         = COMPOUND_STRING("ÁRBITRO: ¡Categoría 1, Mente! ¡El POKéMON que muestre más agallas!\p"),
    [B_MSG_REF_JUDGE_SKILL]        = COMPOUND_STRING("ÁRBITRO: ¡Categoría 2, Técnica! ¡El POKéMON que mejor use sus movimientos!\p"),
    [B_MSG_REF_JUDGE_BODY]         = COMPOUND_STRING("ÁRBITRO: ¡Categoría 3, Cuerpo! ¡El POKéMON con más vitalidad!\p"),
    [B_MSG_REF_PLAYER_WON]         = COMPOUND_STRING("ÁRBITRO: ¡Veredicto: {B_BUFF1} a {B_BUFF2}! ¡Gana {B_PLAYER_MON1_NAME} de {B_PLAYER_NAME}!\p"),
    [B_MSG_REF_OPPONENT_WON]       = COMPOUND_STRING("ÁRBITRO: ¡Veredicto: {B_BUFF1} a {B_BUFF2}! ¡Gana {B_OPPONENT_MON1_NAME} de {B_TRAINER1_NAME}!\p"),
    [B_MSG_REF_DRAW]               = COMPOUND_STRING("ÁRBITRO: ¡Veredicto: 3 a 3! ¡Es un empate!\p"),
    [B_MSG_REF_COMMENCE_BATTLE]    = COMPOUND_STRING("ÁRBITRO: ¡{B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}! ¡Que empiece el combate!"),
};

static const u8 sText_Trainer1Fled[] = _( "{PLAY_SE SE_FLEE}¡{B_TRAINER1_NAME_WITH_CLASS} ha huido!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("¡Has perdido contra {B_TRAINER1_NAME_WITH_CLASS}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("¡Has empatado con {B_TRAINER1_NAME_WITH_CLASS}!");
const u8 gText_RecordBattleToPass[] = _("¿Quieres guardar el combate\nen tu Pase Frente?");
const u8 gText_BattleRecordedOnPass[] = _("El resultado del combate de {B_PLAYER_NAME}\nse ha guardado en el Pase Frente.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("¡{B_LINK_OPPONENT1_NAME} te desafía!\p");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("¡{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME} te desafían!\p");
static const u8 sText_Your1[] = _("Tu equipo");
static const u8 sText_Opposing1[] = _("El equipo enemigo");
static const u8 sText_Your2[] = _("tu equipo");
static const u8 sText_Opposing2[] = _("el equipo enemigo");
static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_KantoTutorial[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_OAK_OLD_MAN] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena,
    [B_WIN_TYPE_KANTO_TUTORIAL] = sTextOnWindowsInfo_KantoTutorial,
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(enum StringID stringID, enum BattlerId battler)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleResources->bufferA[battler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->scriptPartyIdx = gBattleMsgDataPtr->bakScriptPartyIdx;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    {
                        if (TESTING && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        {
                            if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
                                stringPtr = sText_Trainer1WantsToBattle;
                            else
                                stringPtr = sText_TwoTrainersWantToBattle;
                        }
                        else if (TESTING && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                        {
                            stringPtr = sText_TwoTrainersWantToBattle;
                        }
                        else if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
                        {
                            stringPtr = sText_LinkTrainerWantsToBattlePause;
                        }
                        else
                        {
                            stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                        }
                    }
                    else
                    {
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                    }
                }
                else
                {
                    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1WantsToBattle;
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_GHOST && IsGhostBattleWithoutScope())
                stringPtr = sText_GhostAppearedCantId;
            else if (gBattleTypeFlags & BATTLE_TYPE_GHOST)
                stringPtr = sText_TheGhostAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))))
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_CATCH_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else if (!gSaveblock3.challengeSettings.lrToRun && gSaveblock3.challengeSettings.runType == 1)
                stringPtr = sText_WildPkmnAppearedLR;
            else if (!gSaveblock3.challengeSettings.lrToRun && gSaveblock3.challengeSettings.runType == 3)
                stringPtr = sText_WildPkmnAppearedB;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))
         || BattlerIsWally(battler) || BattlerIsWally(BATTLE_PARTNER(battler)))
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(BATTLE_PARTNER(battler))))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                {
                    if (BattlerIsPlayer(battler)) // Player is battler 0
                        stringPtr = sText_InGamePartnerSentOutZGoN;
                    else // Player is battler 2
                        stringPtr = sText_InGamePartnerSentOutNGoZ;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    stringPtr = sText_GoTwoPkmn;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (BattlerIsPlayer(battler)) // Player is battler 0
                        stringPtr = sText_LinkPartnerSentOutPkmn2GoPkmn;
                    else // Player is battler 2
                        stringPtr = sText_LinkPartnerSentOutPkmn1GoPkmn;
                }
                else
                {
                    stringPtr = sText_GoTwoPkmn;
                }
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(BATTLE_PARTNER(battler))))
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (BattlerIsLink(battler) || (BattlerIsRecorded(battler) && BattlerIsOpponent(battler))) // Link Opponent 1 and test opponent
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(BattlerIsLink(battler) || (BattlerIsRecorded(battler) && BattlerIsOpponent(battler))))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if ((GetBattlerPosition(battler) & BIT_FLANK) == B_FLANK_LEFT) // battler 0 and 1
        {
            if (BattlerIsPlayer(battler) || BattlerIsWally(battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_PkmnThatsEnough;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_PkmnComeBack;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_PkmnOkComeBack;
                else
                    stringPtr = sText_PkmnGoodComeBack;
            }
            else if (BattlerIsPartner(battler))
            {
                if (BattlerIsLink(battler)) // Link Partner
                {
                    stringPtr = sText_LinkPartnerWithdrewPkmn1;
                }
                else // In-game Partner
                {
                    stringPtr = sText_InGamePartnerWithdrewPkmn1;
                }
            }
            else if (BattlerIsLink(battler) || TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
            || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent 1 and test opponent
            {
                stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        else // battler 2 and 3
        {
            if (BattlerIsPlayer(battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_PkmnComeBack;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_PkmnOkComeBack;
                else
                    stringPtr = sText_PkmnGoodComeBack;
            }
            else if (BattlerIsPartner(battler))
            {
                if (BattlerIsLink(battler)) // Link Partner
                {
                    stringPtr = sText_LinkPartnerWithdrewPkmn2;
                }
                else // In-game Partner
                {
                    stringPtr = sText_InGamePartnerWithdrewPkmn2;
                }
            }
            else if (BattlerIsLink(battler) || TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
            || TRAINER_BATTLE_PARAM.opponentB == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent B and test opponent
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) // Opponent B
            {
                stringPtr = sText_Trainer2WithdrewPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if ((GetBattlerPosition(gBattleScripting.battler) & BIT_FLANK) == B_FLANK_LEFT) // battler 0 and 1
        {
            if (BattlerIsPlayer(gBattleScripting.battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_GoPkmn2;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_DoItPkmn;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_GoForItPkmn;
                else
                    stringPtr = sText_YourFoesWeakGetEmPkmn;
            }
            else if (BattlerIsPartner(gBattleScripting.battler))
            {
                if (BattlerIsLink(gBattleScripting.battler)) // Link Partner
                {
                    stringPtr = sText_LinkPartnerSentOutPkmn1;
                }
                else // In-game Partner
                {
                    stringPtr = sText_InGamePartnerSentOutPkmn1;
                }
            }
            else if (BattlerIsLink(gBattleScripting.battler) || TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
            || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent 1 and test opponent
            {
                // Must use the {B_BUFF1} variant, like the battler 2/3 case below does.
                // {B_OPPONENT_MON1_NAME} is resolved from this console's own
                // gBattlerPartyIndexes at print time, but over a link the authoritative
                // index does not arrive until switchinanim, which runs after this
                // printstring -- so it named the opponent's previous mon. gBattleTextBuff1
                // was just filled with the right nickname by Cmd_switchindataupdate and
                // travels with the message.
                stringPtr = sText_LinkTrainerSentOutPkmn2;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1SentOutPkmn;
            }
        }
        else // battler 2 and 3
        {
            if (BattlerIsPlayer(gBattleScripting.battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_GoPkmn2;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_DoItPkmn;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_GoForItPkmn;
                else
                    stringPtr = sText_YourFoesWeakGetEmPkmn;
            }
            else if (BattlerIsPartner(gBattleScripting.battler))
            {
                if (BattlerIsLink(gBattleScripting.battler)) // Link Partner
                {
                    stringPtr = sText_LinkPartnerSentOutPkmn2;
                }
                else // In-game Partner
                {
                    stringPtr = sText_InGamePartnerSentOutPkmn2;
                }
            }
            else if (BattlerIsLink(gBattleScripting.battler) || TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
            || TRAINER_BATTLE_PARAM.opponentB == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent B and test opponent
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_LinkTrainer2SentOutPkmn2;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn2;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) // Opponent B
            {
                stringPtr = sText_Trainer2SentOutPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1SentOutPkmn2;
            }
        }
        /*if (IsOnPlayerSide(gBattleScripting.battler))
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && (BattlerIsPartner(gBattleScripting.battler)))
                stringPtr = sText_InGamePartnerSentOutPkmn2;
            else if (*(&gBattleStruct->hpScale) == 0 || IsDoubleBattle())
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (TESTING && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    {
                        if (gBattleScripting.battler == 1)
                        {
                            stringPtr = sText_Trainer1SentOutPkmn;
                        }
                        else
                        {
                            if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                                stringPtr = sText_Trainer2SentOutPkmn;
                            else
                                stringPtr = sText_Trainer1SentOutPkmn2;
                        }
                    }
                    else if (TESTING && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    {
                        if (gBattleScripting.battler == 1)
                            stringPtr = sText_Trainer1SentOutPkmn;
                        else
                            stringPtr = sText_Trainer2SentOutPkmn;
                    }
                    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    {
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    }
                    else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    {
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    }
                    else
                    {
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                    }
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }*/
        break;
    case STRINGID_USEDMOVE: // Pokémon used a move msg
        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
         && !IsZMove(gBattleMsgDataPtr->currentMove)
         && !IsMaxMove(gBattleMsgDataPtr->currentMove))
            StringCopy(gBattleTextBuff3, gTypesInfo[*(&gBattleStruct->stringMoveType)].generic);
        else
            StringCopy(gBattleTextBuff3, GetMoveName(gBattleMsgDataPtr->currentMove));
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (!(BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (!(BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= STRINGID_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
#ifndef NDEBUG
    u32 j, strWidth;
    u32 dstID = BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
    for (j = 1;; j++)
    {
        strWidth = GetStringLineWidth(0, gDisplayedStringBattle, 0, j, sizeof(gDisplayedStringBattle));
        if (strWidth == 0)
            break;
    }
    return dstID;
#else
    return BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
#endif
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

static void GetBattlerNick(enum BattlerId battler, u8 *dst)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    struct Pokemon *mon = GetBattlerMon(battler);

    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

// Traducción: añade « salvaje» o « enemigo» detrás del mote de un Pokémon rival.
static void AppendFoeSuffix(enum BattlerId battler, u8 *nick)
{
    if (!IsOnPlayerSide(battler))
        StringAppend(nick, (gBattleTypeFlags & BATTLE_TYPE_TRAINER) ? sText_FoePkmnSuffix : sText_WildPkmnSuffix);
}

// Traducción: contracciones del español que aparecen al sustituir las variables:
// «de el» -> «del» y «a el» -> «al». Devuelve cuántos bytes se han quitado.
static u32 ContractSpanishArticles(u8 *str)
{
    u32 i, j, removed = 0;

    for (i = 0, j = 0; str[i] != EOS; i++)
    {
        bool32 wordStart = (j == 0 || str[j - 1] == CHAR_SPACE || str[j - 1] == CHAR_NEWLINE);
        // «de el » / «a el »: se quita el espacio y la «e» de «el»
        if (wordStart && str[i] == CHAR_d && str[i + 1] == CHAR_e && str[i + 2] == CHAR_SPACE
         && str[i + 3] == CHAR_e && str[i + 4] == CHAR_l && str[i + 5] == CHAR_SPACE)
        {
            str[j++] = CHAR_d;
            str[j++] = CHAR_e;
            str[j++] = CHAR_l;
            i += 4;
            removed += 2;
        }
        else if (wordStart && str[i] == CHAR_a && str[i + 1] == CHAR_SPACE
         && str[i + 2] == CHAR_e && str[i + 3] == CHAR_l && str[i + 4] == CHAR_SPACE)
        {
            str[j++] = CHAR_a;
            str[j++] = CHAR_l;
            i += 3;
            removed += 2;
        }
        else
        {
            str[j++] = str[i];
        }
    }
    str[j] = EOS;
    return removed;
}

#define HANDLE_NICKNAME_STRING_CASE(battler)                            \
    if (!IsOnPlayerSide(battler))                                       \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battler, text);                                      \
    AppendFoeSuffix(battler, text);                                     \
    toCpy = text;

#define HANDLE_NICKNAME_STRING_LOWERCASE(battler)                       \
    if (!IsOnPlayerSide(battler))                       \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefixLower;                           \
        else                                                            \
            toCpy = sText_WildPkmnPrefixLower;                          \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battler, text);                                      \
    AppendFoeSuffix(battler, text);                                     \
    toCpy = text;

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
    {
        GetTrainerTowerOpponentName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        enum TrainerClassID trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);

        if (trainerClass == TRAINER_CLASS_RIVAL_EARLY_FRLG || trainerClass == TRAINER_CLASS_RIVAL_LATE_FRLG || trainerClass == TRAINER_CLASS_CHAMPION_FRLG)
            toCpy = GetExpandedPlaceholder(PLACEHOLDER_ID_RIVAL);
        else
        {
            toCpy = GetTrainerNameFromId(trainerId);
            if (toCpy[0] == B_BUFF_PLACEHOLDER_BEGIN && toCpy[1] == B_TXT_RIVAL_NAME)
                toCpy = GetExpandedPlaceholder(PLACEHOLDER_ID_RIVAL);
        }
    }

    assertf(DoesStringProperlyTerminate(toCpy, TRAINER_NAME_LENGTH + 1),"Opponent needs a valid name")
    {
        return gText_Blank;
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, battler);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    default:
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (((gBattleTypeFlags & BATTLE_TYPE_RECORDED) && !(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)))
            || gTestRunnerEnabled)
        {
            toCpy = gLinkPlayers[0].name;
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    default:
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    if (IsOnPlayerSide(battler))
        return BattleStringGetPlayerName(text, battler);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClasses[GetSecretBaseTrainerClass()].name;
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClasses[GetUnionRoomTrainerClass()].name;
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClasses[GetFrontierBrainTrainerClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClasses[GetFrontierOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
        toCpy = gTrainerClasses[GetTrainerTowerOpponentClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClasses[GetTrainerHillOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClasses[GetEreaderTrainerClassId()].name;
    else if (trainerId == TRAINER_LINK_OPPONENT)
        toCpy = gTrainerClasses[TRAINER_NONE].name;
    else
        toCpy = gTrainerClasses[GetTrainerClassFromId(trainerId)].name;

    return toCpy;
}

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 *textStart = &text[0];
    u8 multiplayerId;
    u8 fontId = FONT_NORMAL;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    // Clear destination first
    while (dstID < dstSize)
    {
        dst[dstID] = EOS;
        dstID++;
    }

    dstID = 0;
    while (*src != EOS)
    {
        toCpy = NULL;

        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            u32 classLength = 0;
            u32 nameLength = 0;
            const u8 *classString;
            const u8 *nameString;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                {
                    toCpy = gBattleTextBuff2;
                }
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                {
                    toCpy = gBattleTextBuff3;
                }
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 1, text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 2, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 3, text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(BATTLE_PARTNER(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_DEF_PARTNER_NAME: // partner target name
                GetBattlerNick(BATTLE_PARTNER(gBattlerTarget), text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->currentMove);
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->originallyUsedMove);
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY_E_READER)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilitiesInfo[gLastUsedAbility].name;
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerAttacker]].name;
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerTarget]].name;
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattleScripting.battler]].name;
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gEffectBattler]].name;
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_TRAINER1_NAME_WITH_CLASS: // trainer1 name with trainer class
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentLoseText(gStringVar4, 0);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentWinText(gStringVar4, 0);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerWonSpeech();
                }
                break;
            case B_TXT_26: // ?
                if (!IsOnPlayerSide(gBattleScripting.battler))
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                }
                GetMonData(&GetBattlerParty(gBattleScripting.battler)[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                AppendFoeSuffix(gBattleScripting.battler, text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = (IS_FRLG || IS_HNS) ? sText_Bills : sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentLoseText(gStringVar4, 1);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentWinText(gStringVar4, 1);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_RIVAL_NAME:
                toCpy = gSaveBlock2Ptr->rivalName;
                break;
            case B_TXT_PARTNER_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetPlayerName(textStart, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                default:
                    break;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME_WITH_CLASS:
                toCpy = textStart;
                if (GetBattlerPosition(gBattlerAttacker) == B_POSITION_PLAYER_LEFT)
                {
                    textStart = StringCopy(textStart, BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker));
                }
                else
                {
                    classString = NULL;
                    switch (GetBattlerPosition(gBattlerAttacker))
                    {
                    case B_POSITION_PLAYER_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                            classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                        break;
                    case B_POSITION_OPPONENT_LEFT:
                        classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    case B_POSITION_OPPONENT_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                        else
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    default:
                        break;
                    }
                    classLength = 0;
                    nameLength = 0;
                    while (classString[classLength] != EOS)
                    {
                        textStart[classLength] = classString[classLength];
                        classLength++;
                    }
                    textStart[classLength] = CHAR_SPACE;
                    textStart += 1 + classLength;
                    nameString = BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker);
                    if (nameString != textStart)
                    {
                        while (nameString[nameLength] != EOS)
                        {
                            textStart[nameLength] = nameString[nameLength];
                            nameLength++;
                        }
                        textStart[nameLength] = EOS;
                    }
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_EFF_TEAM1:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_EFF_TEAM2:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerTarget)
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattleScripting.battler)
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    if (*toCpy == CHAR_SPACE)
                        dst[dstID] = CHAR_NBSP;
                    else
                        dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    dstID -= ContractSpanishArticles(dst);
    BreakStringAutomatic(dst, BATTLE_MSG_MAX_WIDTH, BATTLE_MSG_MAX_LINES, fontId, SHOW_SCROLL_PROMPT);

    return dstID;
}

static void IllusionNickHack(enum BattlerId battler, u32 partyId, u8 *dst)
{
    u32 id = PARTY_SIZE;
    // we know it's gEnemyParty
    struct Pokemon *mon = &gEnemyParty[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(battler)))
            partnerMon = GetBattlerMon(BATTLE_PARTNER(battler));
        else
            partnerMon = mon;

        id = GetIllusionMonPartyId(gEnemyParty, mon, partnerMon, battler);
    }

    if (id != PARTY_SIZE)
        GetMonData(&gEnemyParty[id], MON_DATA_NICKNAME, dst);
    else
        GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1 + 8]; // Traducción: +8 para « enemigo»/« salvaje»
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, GetMoveName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypesInfo[src[srcID + 1]].name);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
        case B_BUFF_MON_NICK_WITH_PREFIX_LOWER: // poke nick with lowercase prefix
            if (!IsOnPlayerSide(src[srcID + 1]))
            {
                if (src[srcID] == B_BUFF_MON_NICK_WITH_PREFIX_LOWER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, sText_FoePkmnPrefixLower);
                    else
                        StringAppend(dst, sText_WildPkmnPrefixLower);
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, sText_FoePkmnPrefix);
                    else
                        StringAppend(dst, sText_WildPkmnPrefix);
                }
            }
            GetMonData(&GetBattlerParty(src[srcID + 1])[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            StringGet_Nickname(nickname);
            AppendFoeSuffix(src[srcID + 1], nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                if (IsOnPlayerSide(src[srcID + 1]))
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilitiesInfo[T1_READ_16(&src[srcID + 1])].name);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY_E_READER)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.type = WINDOW_TEXT_PRINTER;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.color = textInfo[windowId].color;

    if (B_WIN_MOVE_NAME_1 <= windowId && windowId <= B_WIN_MOVE_NAME_4)
    {
        // We cannot check the actual width of the window because
        // B_WIN_MOVE_NAME_1 and B_WIN_MOVE_NAME_3 are 16 wide for
        // Z-move details.
        if (gBattleStruct->zmove.viewing && windowId == B_WIN_MOVE_NAME_1)
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 16 * TILE_WIDTH);
        else
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 8 * TILE_WIDTH);
    }

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT || windowId == B_WIN_OAK_OLD_MAN)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if ((gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)) || gTestRunnerEnabled || ((gBattleTypeFlags & BATTLE_TYPE_POKEDUDE) && windowId != B_WIN_OAK_OLD_MAN))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT || windowId == B_WIN_OAK_OLD_MAN)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(enum BattlerId battler)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var;

    if (!gBattleStruct->zmove.viewing)
        var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[battler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[battler]]);
    else
        var = 3;

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}
