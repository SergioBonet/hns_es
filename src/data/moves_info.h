#include "battle_dynamax.h"
#include "battle_anim_scripts.h"
#include "constants/battle.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/contest.h"

// The Gen. 4+ contest data comes from urpg's contest movedex.

#if B_BINDING_TURNS >= GEN_5
#define BINDING_TURNS "4 or 5"
#else
#define BINDING_TURNS "2 to 5"
#endif

// Shared Move Description entries

const u8 gNotDoneYetDescription[] = _(
    "Este movimiento no se puede\n"
    "usar. Su efecto está en desarrollo.");

static const u8 sNullDescription[] = _("");

static const u8 sMegaDrainDescription[] = _(
    "Absorbe la mitad del daño\n"
    "causado.");

#if B_SKIP_RECHARGE != GEN_1
static const u8 sHyperBeamDescription[] = _(
    "Es eficaz, pero deja inmóvil\n"
    "al atacante 1 turno.");
#else
static const u8 sHyperBeamDescription[] = _(
    "Deja inmóvil al usuario\n"
    "si el objetivo no cae.");
#endif

static const u8 sRevengeDescription[] = _(
    "Ataca último y gana potencia\n"
    "si le golpean.");

static const u8 sPluckDescription[] = _(
    "Se come la Baya del rival y\n"
    "obtiene su efecto.");

static const u8 sHealingWishDescription[] = _(
    "Se debilita para curar al que\n"
    "entra.");

static const u8 sWringOutDescription[] = _(
    "Cuantos más PS tenga el\n"
    "rival, más daño.");

static const u8 sUTurnDescription[] = _(
    "Ataca y luego cambia al\n"
    "usuario.");

static const u8 sStormThrowDescription[] = _(
    "Este ataque siempre es un\n"
    "golpe crítico.");

static const u8 sCircleThrowDescription[] = _(
    "Expulsa al rival o acaba el\n"
    "combate salvaje.");

static const u8 sChipAwayDescription[] = _(
    "Ignora los cambios de caract.\n"
    "del rival.");

static const u8 sHeavySlamDescription[] = _(
    "Más daño cuanto más pese que\n"
    "el rival.");

static const u8 sPsyshockDescription[] = _(
    "Onda psíquica que causa daño\n"
    "físico.");

static const u8 sLavaPlumeDescription[] = _(
    "Llamas escarlata que lo\n"
    "queman todo alrededor.");

static const u8 sShadowForceDescription[] = _(
    "Desaparece el 1.{SUPER_ER} turno y\n"
    "ataca el siguiente.");

static const u8 sFalseSwipeDescription[] = _(
    "Ataque que deja al rival con\n"
    "al menos 1 PS.");

static const u8 sDrainingKissDescription[] = _(
    "Absorbe más de la mitad del\n"
    "daño causado.");

static const u8 sCloseCombatDescription[] = _(
    "Ataque fuerte, pero baja sus\n"
    "defensas.");

static const u8 sHyperspaceHoleDescription[] = _(
    "Ataca desde un agujero\n"
    "dimensional. No falla.");

static const u8 sSuckerPunchDescription[] = _(
    "Golpea primero si el rival\n"
    "prepara un ataque.");

static const u8 sFeintDescription[] = _(
    "Golpea a quien use\n"
    "movimientos como Protección.");

static const u8 sProtectDescription[] = _(
    "Frena ataques, pero puede\n"
    "fallar si se usa sin cesar.");

static const u8 sGMaxOneBlowDescription[] = _(
    "Gigamax de Urshifu. Ignora\n"
    "Maxibarrera.");

const struct MoveInfo gMovesInfo[MOVES_COUNT_ALL] =
{
    [MOVE_NONE] =
    {
        .name = COMPOUND_STRING("-"),
        .description = COMPOUND_STRING(""),
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 0,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .sketchBanned = TRUE,
        .assistBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_None,
    },

    [MOVE_POUND] =
    {
        .name = COMPOUND_STRING("DESTRUCTOR"),
        .description = COMPOUND_STRING(
            "Golpea con las patas o la\n"
            "cola."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS == GEN_4,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_POUND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pound,
    },

    [MOVE_KARATE_CHOP] =
    {
        .name = COMPOUND_STRING("GOLPE KÁRATE"),
        .description = COMPOUND_STRING(
            "Da un golpe cortante. Suele\n"
            "ser crítico."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_FIGHTING : TYPE_NORMAL,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_KarateChop,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_SLAP] =
    {
        .name = COMPOUND_STRING("DOBLE BOFETÓN"),
        .description = COMPOUND_STRING(
            "Abofetea de 2 a 5 veces\n"
            "seguidas."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_DoubleSlap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COMET_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO COMETA"),
        .description = COMPOUND_STRING(
            "Pega de 2 a 5 veces seguidas."),
        .effect = EFFECT_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CometPunch,
    },

    [MOVE_MEGA_PUNCH] =
    {
        .name = COMPOUND_STRING("MEGAPUÑO"),
        .description = COMPOUND_STRING(
            "Un puñetazo de gran\n"
            "potencia."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_MegaPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PAY_DAY] =
    {
        .name = COMPOUND_STRING("DÍA DE PAGO"),
        .description = COMPOUND_STRING(
            "Arroja monedas que luego\n"
            "recupera."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PAYDAY,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PayDay,
    },

    [MOVE_FIRE_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO FUEGO"),
        .description = COMPOUND_STRING(
            "Puñetazo ardiente. Puede\n"
            "quemar."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_FIRE_PUNCH,
        .contestComboMoves = {COMBO_STARTER_ICE_PUNCH, COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_THUNDER_PUNCH},
        .battleAnimScript = gBattleAnimMove_FirePunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO HIELO"),
        .description = COMPOUND_STRING("Puñetazo helado. Puede\n" "congelar."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_ICE_PUNCH,
        .contestComboMoves = {COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_THUNDER_PUNCH},
        .battleAnimScript = gBattleAnimMove_IcePunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO TRUENO"),
        .description = COMPOUND_STRING(
            "Puñetazo eléctrico. Puede\n"
            "paralizar."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_THUNDER_PUNCH,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_ICE_PUNCH},
        .battleAnimScript = gBattleAnimMove_ThunderPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCRATCH] =
    {
        .name = COMPOUND_STRING("ARAÑAZO"),
        .description = COMPOUND_STRING(
            "Araña con afiladas garras."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCRATCH,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Scratch,
    },

    [MOVE_VISE_GRIP] =
    {
        .name = COMPOUND_STRING("AGARRE"),
        .description = COMPOUND_STRING(
            "Atrapa con potentes pinzas."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_VICE_GRIP,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ViseGrip,
    },

    [MOVE_GUILLOTINE] =
    {
        .name = COMPOUND_STRING("GUILLOTINA"),
        .description = COMPOUND_STRING(
            "Pinza poderosa que debilita\n"
            "si acierta."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_VICE_GRIP},
        .battleAnimScript = gBattleAnimMove_Guillotine,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAZOR_WIND] =
    {
        .name = COMPOUND_STRING("VIENTO CORTANTE"),
        #if B_UPDATED_MOVE_DATA == GEN_3 || B_UPDATED_MOVE_DATA == GEN_1
            .description = COMPOUND_STRING(
                "Movimiento de 2 turnos que\n"
                "golpea al rival en el 2.º."),
        #else
            .description = COMPOUND_STRING(
                "Ataque en 2 turnos. Suele ser\n"
                "crítico."),
        #endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 100 : 75,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .criticalHitStage = 1,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .criticalHitStage = 2,
        #else
            .criticalHitStage = 0,
        #endif
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNWHIPPEDWHIRLWIND },
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RazorWind,
    },

    [MOVE_SWORDS_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA ESPADA"),
        .description = COMPOUND_STRING(
            "Baile que mejora el Ataque."),
        .effect = EFFECT_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SWORDS_DANCE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SwordsDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CUT] =
    {
        .name = COMPOUND_STRING("CORTE"),
        .description = COMPOUND_STRING(
            "Corta con garras, guadañas,\n"
            "etc."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Cut,
    },

    [MOVE_GUST] =
    {
        .name = COMPOUND_STRING("TORNADO"),
        .description = COMPOUND_STRING(
            "Crea un tornado con las alas."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_FLYING : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_4) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .damagesAirborneDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .windMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Gust,
    },

    [MOVE_WING_ATTACK] =
    {
        .name = COMPOUND_STRING("ATAQUE ALA"),
        .description = COMPOUND_STRING(
            "Golpea al objetivo con las\n"
            "alas."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 60 : 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WingAttack,
    },

    [MOVE_WHIRLWIND] =
    {
        .name = COMPOUND_STRING("REMOLINO"),
        .description = COMPOUND_STRING(
            "Saca al rival del combate o\n"
            "acaba uno salvaje."),
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 0,
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .accuracy = 100,
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .accuracy = 100,
            .priority = -1,
        #else
            .accuracy = 85,
            .priority = 0,
        #endif
        .pp = 20,
        .target = TARGET_SELECTED,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .windMove = TRUE,
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Whirlwind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLY] =
    {
        .name = COMPOUND_STRING("VUELO"),
        .description = COMPOUND_STRING(
            "1.{SUPER_ER} turno: vuela. 2.º: ataca."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNFLEWHIGH, .status = STATE_ON_AIR },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Fly,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BIND] =
    {
        .name = COMPOUND_STRING("ATADURA"),
        .description = COMPOUND_STRING(
            "Ata y oprime al rival durante\n"
            "4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_BIND,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_VICE_GRIP},
        .battleAnimScript = gBattleAnimMove_Bind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLAM] =
    {
        .name = COMPOUND_STRING("ATIZAR"),
        .description = COMPOUND_STRING(
            "Golpea con las extremidades."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_Slam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VINE_WHIP] =
    {
        .name = COMPOUND_STRING("LÁTIGO CEPA"),
        .description = COMPOUND_STRING(
            "Azota al enemigo con ramas\n"
            "finas."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 25,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 15,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 45 : 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_VineWhip,
    },

    [MOVE_STOMP] =
    {
        .name = COMPOUND_STRING("PISOTÓN"),
        .description = COMPOUND_STRING(
            "Tremendo pisotón que puede\n"
            "causar retroceso."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Stomp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_KICK] =
    {
        .name = COMPOUND_STRING("DOBLE PATADA"),
        .description = COMPOUND_STRING(
            "Una patada doble. Golpea 2\n"
            "veces."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEGA_KICK] =
    {
        .name = COMPOUND_STRING("MEGAPATADA"),
        .description = COMPOUND_STRING(
            "Patada de extrema fuerza."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_MegaKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_JUMP_KICK] =
    {
        .name = COMPOUND_STRING("PATADA SALTO"),
        .description = COMPOUND_STRING(
            "Si falla, dañará a quien lo\n"
            "usa."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 85,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_JumpKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLLING_KICK] =
    {
        .name = COMPOUND_STRING("PATADA GIRO"),
        .description = COMPOUND_STRING(
            "Patada rápida con giro. Puede\n"
            "hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RollingKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAND_ATTACK] =
    {
        .name = COMPOUND_STRING("ATAQUE ARENA"),
        .description = COMPOUND_STRING(
            "Arroja arena a la cara y baja\n"
            "la Precisión."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_GROUND : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SAND_ATTACK,
        .contestComboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_SandAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEADBUTT] =
    {
        .name = COMPOUND_STRING("GOLPE CABEZA"),
        .description = COMPOUND_STRING(
            "Cabezazo que puede hacer\n"
            "retroceder al rival."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_Headbutt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HORN_ATTACK] =
    {
        .name = COMPOUND_STRING("CORNADA"),
        .description = COMPOUND_STRING(
            "Ataca al enemigo con afilados\n"
            "cuernos."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_HORN_ATTACK,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_HornAttack,
    },

    [MOVE_FURY_ATTACK] =
    {
        .name = COMPOUND_STRING("ATAQUE FURIA"),
        .description = COMPOUND_STRING(
            "Cornea al enemigo de 2 a 5\n"
            "veces."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HORN_ATTACK, COMBO_STARTER_PECK},
        .battleAnimScript = gBattleAnimMove_FuryAttack,
    },

    [MOVE_HORN_DRILL] =
    {
        .name = COMPOUND_STRING("PERFORADOR"),
        .description = COMPOUND_STRING(
            "Ataque taladro. Fulmina en 1\n"
            "golpe."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HORN_ATTACK},
        .battleAnimScript = gBattleAnimMove_HornDrill,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TACKLE] =
    {
        .name = COMPOUND_STRING("PLACAJE"),
        .description = COMPOUND_STRING(
            "Embiste con todo el cuerpo."),
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 40,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 50,
        #else
            .power = 35,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 95,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN, COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Tackle,
    },

    [MOVE_BODY_SLAM] =
    {
        .name = COMPOUND_STRING("GOLPE CUERPO"),
        .description = COMPOUND_STRING(
            "Ataque corporal que puede\n"
            "paralizar."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BodySlam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WRAP] =
    {
        .name = COMPOUND_STRING("CONSTRICCIÓN"),
        .description = COMPOUND_STRING(
            "Oprime al rival 4 o 5 turnos\n"
            "con lianas, etc."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Wrap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAKE_DOWN] =
    {
        .name = COMPOUND_STRING("DERRIBO"),
        .description = COMPOUND_STRING(
            "Carga desmedida que también\n"
            "hiere al agresor."),
        .effect = EFFECT_RECOIL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_TakeDown,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THRASH] =
    {
        .name = COMPOUND_STRING("SAÑA"),
        .description = COMPOUND_STRING(
            "Dura de 2 a 3 turnos y acaba\n"
            "confundiéndote."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 120 : 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAGE},
        .battleAnimScript = gBattleAnimMove_Thrash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_EDGE] =
    {
        .name = COMPOUND_STRING("DOBLE FILO"),
        .description = COMPOUND_STRING(
            "Ataque arriesgado que\n"
            "también hiere al agresor."),
        .effect = EFFECT_RECOIL,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 120 : 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = B_UPDATED_MOVE_DATA >= GEN_3 ? 33 : 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_DoubleEdge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAIL_WHIP] =
    {
        .name = COMPOUND_STRING("AGITACOLA"),
        .description = COMPOUND_STRING(
            "Agita la cola para bajar la\n"
            "Defensa del otro."),
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_TailWhip,
    },

    [MOVE_POISON_STING] =
    {
        .name = COMPOUND_STRING("PICOTAZO VENENO"),
        .description = COMPOUND_STRING(
            "Puede envenenar al enemigo\n"
            "con púas, etc."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 20,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonSting,
    },

    [MOVE_TWINEEDLE] =
    {
        .name = COMPOUND_STRING("DOBLE ATAQUE"),
        .description = COMPOUND_STRING(
            "Pincha dos veces con\n"
            "aguijones. Puede envenenar."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .strikeCount = 2,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Twineedle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PIN_MISSILE] =
    {
        .name = COMPOUND_STRING("PIN MISIL"),
        .description = COMPOUND_STRING(
            "Lanza finas púas que hieren\n"
            "de 2 a 5 veces."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 14,
        .type = TYPE_BUG,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PinMissile,
    },

    [MOVE_LEER] =
    {
        .name = COMPOUND_STRING("MALICIOSO"),
        .description = COMPOUND_STRING(
            "Asusta con la mirada y baja la\n"
            "Defensa rival."),
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_LEER,
        .contestComboMoves = {COMBO_STARTER_RAGE, COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Leer,
    },

    [MOVE_BITE] =
    {
        .name = COMPOUND_STRING("MORDISCO"),
        .description = COMPOUND_STRING(
            "Un voraz bocado que puede\n"
            "causar retroceso."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_DARK : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Bite,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GROWL] =
    {
        .name = COMPOUND_STRING("GRUÑIDO"),
        .description = COMPOUND_STRING(
            "Dulce gruñido que reduce el\n"
            "Ataque del otro."),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Growl,
    },

    [MOVE_ROAR] =
    {
        .name = COMPOUND_STRING("RUGIDO"),
        .description = COMPOUND_STRING(
            "Cambia al rival o acaba un\n"
            "combate salvaje."),
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        #if B_UPDATED_MOVE_DATA >= GEN_3
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .priority = -1,
        #else
            .priority = 0,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .soundMove = TRUE,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Roar,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SING] =
    {
        .name = COMPOUND_STRING("CANTO"),
        .description = COMPOUND_STRING(
            "Cancioncilla que puede dormir\n"
            "al enemigo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SING,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sing,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPERSONIC] =
    {
        .name = COMPOUND_STRING("SUPERSÓNICO"),
        .description = COMPOUND_STRING(
            "Raras ondas sónicas que\n"
            "pueden confundir."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Supersonic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SONIC_BOOM] =
    {
        .name = COMPOUND_STRING("BOMBA SÓNICA"),
        .description = COMPOUND_STRING(
            "Lanza ondas de choque que\n"
            "restan 20 PS."),
        .effect = EFFECT_FIXED_HP_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .fixedDamage = 20 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SonicBoom,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DISABLE] =
    {
        .name = COMPOUND_STRING("ANULACIÓN"),
        .description = COMPOUND_STRING(
            "Impide al rival usar su último\n"
            "ataque 4 turnos."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 80,
        #else
            .accuracy = 55,
        #endif
        .effect = EFFECT_DISABLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Disable,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ACID] =
    {
        .name = COMPOUND_STRING("ÁCIDO"),
        .description = COMPOUND_STRING(
            "Ácido corrosivo. Puede bajar\n"
            "la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
            .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = B_UPDATED_MOVE_DATA >= GEN_4 ? MOVE_EFFECT_SP_DEF_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acid,
    },

    [MOVE_EMBER] =
    {
        .name = COMPOUND_STRING("ASCUAS"),
        .description = COMPOUND_STRING(
            "Ligero ataque que puede\n"
            "causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Ember,
    },

    [MOVE_FLAMETHROWER] =
    {
        .name = COMPOUND_STRING("LANZALLAMAS"),
        .description = COMPOUND_STRING(
            "Fuerte ataque que puede\n"
            "causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Flamethrower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIST] =
    {
        .name = COMPOUND_STRING("NEBLINA"),
        .description = COMPOUND_STRING(
            "Crea una niebla que evita\n"
            "bajadas de caract."),
        .effect = EFFECT_MIST,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Mist,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_GUN] =
    {
        .name = COMPOUND_STRING("PISTOLA AGUA"),
        .description = COMPOUND_STRING(
            "Rocía agua para atacar."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_WaterGun,
    },

    [MOVE_HYDRO_PUMP] =
    {
        .name = COMPOUND_STRING("HIDROBOMBA"),
        .description = COMPOUND_STRING(
            "Lanza agua a chorros para\n"
            "atacar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_HydroPump,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SURF] =
    {
        .name = COMPOUND_STRING("SURF"),
        .description = COMPOUND_STRING(
            "Crea una gran ola que rompe\n"
            "sobre el campo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = B_UPDATED_MOVE_DATA >= GEN_4 ? TARGET_FOES_AND_ALLY : TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesUnderwater = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SURF,
        .contestComboMoves = {COMBO_STARTER_DIVE, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Surf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_BEAM] =
    {
        .name = COMPOUND_STRING("RAYO HIELO"),
        .description = COMPOUND_STRING("Rayo de hielo que puede\n" "llegar a congelar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            // The following effect is also relevant in battle_Pike.c
            // If you cherry-pick this to use something other than the config, make sure to update it there too
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IceBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLIZZARD] =
    {
        .name = COMPOUND_STRING("VENTISCA"),
        .description = COMPOUND_STRING(
            "Tormenta helada contra los\n"
            "rivales. Puede congelar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_ICE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_2 ? 70 : 90,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInHailSnow = B_BLIZZARD_HAIL >= GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_POWDER_SNOW},
        .battleAnimScript = gBattleAnimMove_Blizzard,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYBEAM] =
    {
        .name = COMPOUND_STRING("PSICORRAYO"),
        .description = COMPOUND_STRING(
            "Extraño rayo que puede\n"
            "causar confusión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Psybeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BUBBLE_BEAM] =
    {
        .name = COMPOUND_STRING("RAYO BURBUJA"),
        .description = COMPOUND_STRING(
            "Diluvio de burbujas que puede\n"
            "bajar la Velocidad."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_BubbleBeam,
    },

    [MOVE_AURORA_BEAM] =
    {
        .name = COMPOUND_STRING("RAYO AURORA"),
        .description = COMPOUND_STRING(
            "Rayo multicolor que puede\n"
            "reducir el Ataque."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_AuroraBeam,
    },

    [MOVE_HYPER_BEAM] =
    {
        .name = COMPOUND_STRING("HIPERRAYO"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PECK] =
    {
        .name = COMPOUND_STRING("PICOTAZO"),
        .description = COMPOUND_STRING(
            "Ataca con un punzante pico."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_PECK,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Peck,
    },

    [MOVE_DRILL_PECK] =
    {
        .name = COMPOUND_STRING("PICO TALADRO"),
        .description = COMPOUND_STRING(
            "Picotazo giratorio y\n"
            "perforador muy potente."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PECK},
        .battleAnimScript = gBattleAnimMove_DrillPeck,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUBMISSION] =
    {
        .name = COMPOUND_STRING("SUMISIÓN"),
        .description = COMPOUND_STRING(
            "Golpe desmedido que también\n"
            "hiere al agresor."),
        .effect = EFFECT_RECOIL,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .argument = { .recoilPercentage = 25 },
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_Submission,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LOW_KICK] =
    {
        .name = COMPOUND_STRING("PATADA BAJA"),
        #if B_UPDATED_MOVE_DATA >= GEN_3
            .description = COMPOUND_STRING(
                "Cuanto más pesa el enemigo,\n"
                "más daño causa."),
            .effect = EFFECT_LOW_KICK,
        #else
            .description = COMPOUND_STRING(
                "Patada baja que hace\n"
                "tropezar. Puede amedrentar."),
            .effect = EFFECT_HIT,
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 30,
            }),
        #endif
        .power = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 50,
        .type = TYPE_FIGHTING,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 100 : 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_LATER : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LowKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COUNTER] =
    {
        .name = COMPOUND_STRING("CONTRAATAQUE"),
        .description = COMPOUND_STRING(
            "Devuelve un golpe físico por\n"
            "duplicado."),
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = -5,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .argument = {
            .reflectDamage.damagePercent = 200,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT, COMBO_STARTER_ENCORE, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Counter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SEISMIC_TOSS] =
    {
        .name = COMPOUND_STRING("SÍSMICO"),
        .description = COMPOUND_STRING(
            "Resta los mismos PS que nivel\n"
            "tenga el agresor."),
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SeismicToss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRENGTH] =
    {
        .name = COMPOUND_STRING("FUERZA"),
        .description = COMPOUND_STRING(
            "Potente ataque físico."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Strength,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ABSORB] =
    {
        .name = COMPOUND_STRING("ABSORBER"),
        .description = COMPOUND_STRING(
            "Absorbe la mitad del daño\n"
            "causado."),
        .effect = EFFECT_ABSORB,
        .power = 20,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 25 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_Absorb,
    },

    [MOVE_MEGA_DRAIN] =
    {
        .name = COMPOUND_STRING("MEGAAGOTAR"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .zMove = { .powerOverride = 120 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_MegaDrain,
    },

    [MOVE_LEECH_SEED] =
    {
        .name = COMPOUND_STRING("DRENADORAS"),
        .description = COMPOUND_STRING(
            "Planta tres semillas que\n"
            "quitan PS en cada turno."),
        .effect = EFFECT_LEECH_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_LEECH_SEED,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_WORRY_SEED, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_LeechSeed,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GROWTH] =
    {
        .name = COMPOUND_STRING("DESARROLLO"),
        .description = COMPOUND_STRING(
            "Hace crecer el cuerpo: sube\n"
            "Ataque y At. Esp."),
        .effect = B_GROWTH_STAT_RAISE >= GEN_5 ? EFFECT_GROWTH : EFFECT_SPECIAL_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_GROWTH,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Growth,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAZOR_LEAF] =
    {
        .name = COMPOUND_STRING("HOJA AFILADA"),
        .description = COMPOUND_STRING(
            "Corta con hojas. Suele ser\n"
            "crítico."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_RazorLeaf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SOLAR_BEAM] =
    {
        .name = COMPOUND_STRING("RAYO SOLAR"),
        .description = COMPOUND_STRING(
            "1.{SUPER_ER} turno: absorbe luz. 2.º:\n"
            "ataca."),
        .effect = EFFECT_SOLAR_BEAM,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNTOOKSUNLIGHT, .weather = B_WEATHER_SUN },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SolarBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_POWDER] =
    {
        .name = COMPOUND_STRING("POLVO VENENO"),
        .description = COMPOUND_STRING(
            "Polvo tóxico que puede\n"
            "envenenar al enemigo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 75,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_POISON },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_POISON_POWDER,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_PoisonPowder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STUN_SPORE] =
    {
        .name = COMPOUND_STRING("PARALIZADOR"),
        .description = COMPOUND_STRING(
            "Esparce polvo que puede\n"
            "paralizar al enemigo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_StunSpore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLEEP_POWDER] =
    {
        .name = COMPOUND_STRING("SOMNÍFERO"),
        .description = COMPOUND_STRING(
            "Esparce polvo que puede\n"
            "dormir al enemigo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SLEEP_POWDER,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_SleepPowder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PETAL_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA PÉTALO"),
        .description = COMPOUND_STRING(
            "Dura de 2 a 3 turnos y acaba\n"
            "confundiéndote."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 90,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .danceMove = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_PetalDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRING_SHOT] =
    {
        .name = COMPOUND_STRING("DISPARO DEMORA"),
        .description = COMPOUND_STRING(
            "Baja la Velocidad del enemigo."),
        .effect = B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_SPEED_DOWN_2 : EFFECT_SPEED_DOWN,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 40,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_STRING_SHOT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StringShot,
    },

    [MOVE_DRAGON_RAGE] =
    {
        .name = COMPOUND_STRING("FURIA DRAGÓN"),
        .description = COMPOUND_STRING(
            "Cadena de ondas de choque\n"
            "que quitan 40 PS."),
        .effect = EFFECT_FIXED_HP_DAMAGE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_4) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .argument = { .fixedDamage = 40 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_RAGE,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonRage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FIRE_SPIN] =
    {
        .name = COMPOUND_STRING("GIRO FUEGO"),
        .description = COMPOUND_STRING(
            "Atrapa al rival en un anillo de\n"
            "fuego 4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_FIRE_SPIN,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireSpin,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_SHOCK] =
    {
        .name = COMPOUND_STRING("IMPACTRUENO"),
        .description = COMPOUND_STRING(
            "Ataque eléctrico que puede\n"
            "paralizar al enemigo."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ThunderShock,
    },

    [MOVE_THUNDERBOLT] =
    {
        .name = COMPOUND_STRING("RAYO"),
        .description = COMPOUND_STRING(
            "Duro ataque eléctrico que\n"
            "puede paralizar al enemigo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Thunderbolt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_WAVE] =
    {
        .name = COMPOUND_STRING("ONDA TRUENO"),
        .description = COMPOUND_STRING(
            "Una descarga que puede\n"
            "paralizar al enemigo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 90 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_THUNDER_WAVE,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ThunderWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER] =
    {
        .name = COMPOUND_STRING("TRUENO"),
        .description = COMPOUND_STRING(
            "Un estruendo que puede\n"
            "paralizar al enemigo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 70,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesAirborne = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .alwaysHitsInRain = TRUE,
        .accuracy50InSun = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Thunder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_THROW] =
    {
        .name = COMPOUND_STRING("LANZARROCAS"),
        .description = COMPOUND_STRING(
            "Tira pequeñas rocas al\n"
            "enemigo."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_2 ? 90 : 65,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROCK_THROW,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockThrow,
    },

    [MOVE_EARTHQUAKE] =
    {
        .name = COMPOUND_STRING("TERREMOTO"),
        .description = COMPOUND_STRING(
            "Terremoto que golpea a todos\n"
            "los demás Pokémon."),
        .effect = EFFECT_EARTHQUAKE,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesUnderground = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_EARTHQUAKE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Earthquake,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FISSURE] =
    {
        .name = COMPOUND_STRING("FISURA"),
        .description = COMPOUND_STRING(
            "Ataque de tierra. Fulmina en 1\n"
            "golpe."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_EARTHQUAKE},
        .battleAnimScript = gBattleAnimMove_Fissure,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DIG] =
    {
        .name = COMPOUND_STRING("EXCAVAR"),
        .description = COMPOUND_STRING(
            "1.{SUPER_ER} turno: cava. 2.º: ataca."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 80,
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .power = 60,
        #else
            .power = 100,
        #endif
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNDUGHOLE, .status = STATE_UNDERGROUND },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Dig,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TOXIC] =
    {
        .name = COMPOUND_STRING("TÓXICO"),
        .description = COMPOUND_STRING(
            "Envenena al rival de forma\n"
            "progresiva."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_TOXIC },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .alwaysHitsOnSameType = B_TOXIC_NEVER_MISS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TOXIC,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Toxic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONFUSION] =
    {
        .name = COMPOUND_STRING("CONFUSIÓN"),
        .description = COMPOUND_STRING(
            "Ataque psíquico que puede\n"
            "causar confusión."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CONFUSION,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Confusion,
    },

    [MOVE_PSYCHIC] =
    {
        .name = COMPOUND_STRING("PSÍQUICO"),
        .description = COMPOUND_STRING(
            "Fuerte ataque psíquico que\n"
            "puede bajar la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PSYCHIC,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS},
        .battleAnimScript = gBattleAnimMove_Psychic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPNOSIS] =
    {
        .name = COMPOUND_STRING("HIPNOSIS"),
        .description = COMPOUND_STRING(
            "Ataque hipnótico que puede\n"
            "dormir al enemigo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 60,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HYPNOSIS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Hypnosis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEDITATE] =
    {
        .name = COMPOUND_STRING("MEDITACIÓN"),
        .description = COMPOUND_STRING(
            "Reposa y medita para\n"
            "aumentar el Ataque."),
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Meditate,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AGILITY] =
    {
        .name = COMPOUND_STRING("AGILIDAD"),
        .description = COMPOUND_STRING(
            "Relaja el cuerpo para ganar\n"
            "Velocidad."),
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_AGILITY,
        .contestComboMoves = {COMBO_STARTER_DOUBLE_TEAM},
        .battleAnimScript = gBattleAnimMove_Agility,
        .validApprenticeMove = TRUE,
    },

    [MOVE_QUICK_ATTACK] =
    {
        .name = COMPOUND_STRING("ATAQUE RÁPIDO"),
        .description = COMPOUND_STRING(
            "Ataque rápido que permite\n"
            "golpear en 1.{SUPER_ER} lugar."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DOUBLE_TEAM},
        .battleAnimScript = gBattleAnimMove_QuickAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAGE] =
    {
        .name = COMPOUND_STRING("FURIA"),
        .description = COMPOUND_STRING(
            "Mejora tu Ataque cada vez\n"
            "que te golpean."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAGE,
        }),
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_RAGE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Rage,
    },

    [MOVE_TELEPORT] =
    {
        .name = COMPOUND_STRING("TELETRANSPORTE"),
        #if B_TELEPORT_BEHAVIOR >= GEN_8
        .description = COMPOUND_STRING(
            "El usuario cambia al final. Si\n"
            "es salvaje, huye."),
        #else
        .description = COMPOUND_STRING(
            "Movimiento psíquico para\n"
            "huir del combate al instante."),
        #endif
        .effect = EFFECT_TELEPORT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_8 ? -6 : 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_DOUBLE_TEAM, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Teleport,
    },

    [MOVE_NIGHT_SHADE] =
    {
        .name = COMPOUND_STRING("TINIEBLAS"),
        .description = COMPOUND_STRING(
            "Resta los mismos PS que nivel\n"
            "tenga el agresor."),
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NightShade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIMIC] =
    {
        .name = COMPOUND_STRING("MIMÉTICO"),
        .description = COMPOUND_STRING(
            "Copia el último ataque rival\n"
            "durante el combate."),
        .effect = EFFECT_MIMIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 0 : 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresSubstitute = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Mimic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCREECH] =
    {
        .name = COMPOUND_STRING("CHIRRIDO"),
        .description = COMPOUND_STRING(
            "Ruido agudo que baja mucho la\n"
            "Defensa del rival."),
        .effect = EFFECT_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Screech,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_TEAM] =
    {
        .name = COMPOUND_STRING("DOBLE EQUIPO"),
        .description = COMPOUND_STRING(
            "Crea espejismos para mejorar\n"
            "la Evasión."),
        .effect = EFFECT_EVASION_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DOUBLE_TEAM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleTeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RECOVER] =
    {
        .name = COMPOUND_STRING("RECUPERACIÓN"),
        .description = COMPOUND_STRING(
            "Restaura hasta la mitad de\n"
            "los PS máximos."),
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Recover,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HARDEN] =
    {
        .name = COMPOUND_STRING("FORTALEZA"),
        .description = COMPOUND_STRING(
            "Tensa la musculatura para\n"
            "aumentar la Defensa."),
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_HARDEN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Harden,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MINIMIZE] =
    {
        .name = COMPOUND_STRING("REDUCCIÓN"),
        .description = COMPOUND_STRING(
            "Encoge al usuario para subir\n"
            "mucho la Evasión."),
        .effect = EFFECT_MINIMIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Minimize,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMOKESCREEN] =
    {
        .name = COMPOUND_STRING("PANTALLA DE HUMO"),
        .description = COMPOUND_STRING(
            "Baja la Precisión del enemigo\n"
            "con humo, etc."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SMOG},
        .battleAnimScript = gBattleAnimMove_Smokescreen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONFUSE_RAY] =
    {
        .name = COMPOUND_STRING("RAYO CONFUSO"),
        .description = COMPOUND_STRING(
            "Rayo siniestro que confunde\n"
            "al enemigo."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ConfuseRay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WITHDRAW] =
    {
        .name = COMPOUND_STRING("REFUGIO"),
        .description = COMPOUND_STRING(
            "El agresor se protege en su\n"
            "coraza y sube la Defensa."),
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Withdraw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DEFENSE_CURL] =
    {
        .name = COMPOUND_STRING("RIZO DEFENSA"),
        .description = COMPOUND_STRING(
            "Oculta su punto débil al\n"
            "rizarse. Sube la Defensa."),
        .effect = EFFECT_DEFENSE_CURL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_DEFENSE_CURL,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DefenseCurl,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BARRIER] =
    {
        .name = COMPOUND_STRING("BARRERA"),
        .description = COMPOUND_STRING(
            "Crea una barrera para subir\n"
            "mucho la Defensa."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Barrier,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LIGHT_SCREEN] =
    {
        .name = COMPOUND_STRING("PANTALLA DE LUZ"),
        .description = COMPOUND_STRING(
            "Barrera de luz: menos daño\n"
            "especial 5 turnos."),
        .effect = EFFECT_LIGHT_SCREEN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_LightScreen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HAZE] =
    {
        .name = COMPOUND_STRING("NIEBLA"),
        .description = COMPOUND_STRING(
            "Nube negra que elimina los\n"
            "cambios de caracterís."),
        .effect = EFFECT_HAZE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_Haze,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REFLECT] =
    {
        .name = COMPOUND_STRING("REFLEJO"),
        .description = COMPOUND_STRING(
            "Barrera de luz: menos daño\n"
            "físico 5 turnos."),
        .effect = EFFECT_REFLECT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Reflect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOCUS_ENERGY] =
    {
        .name = COMPOUND_STRING("FOCO ENERGÍA"),
        .description = COMPOUND_STRING(
            "Concentra energía para\n"
            "asegurar un golpe crítico."),
        .effect = EFFECT_FOCUS_ENERGY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .argument = { .status = VOLATILE_FOCUS_ENERGY },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_FOCUS_ENERGY,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FocusEnergy,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BIDE] =
    {
        .name = COMPOUND_STRING("VENGANZA"),
        .description = COMPOUND_STRING(
            "Espera 2 turnos para atacar\n"
            "con doble potencia."),
        .effect = EFFECT_BIDE,
        .power = 1,
        .type = TYPE_NORMAL,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .priority = 1,
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .accuracy = 100,
            .priority = 0,
        #else
            .accuracy = 0,
            .priority = 0,
        #endif
        .pp = 10,
        .target = TARGET_USER,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bide,
    },

    [MOVE_METRONOME] =
    {
        .name = COMPOUND_STRING("METRÓNOMO"),
        .description = COMPOUND_STRING(
            "Usa al azar un ataque\n"
            "Pokémon."),
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_3,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Metronome,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIRROR_MOVE] =
    {
        .name = COMPOUND_STRING("ESPEJO"),
        .description = COMPOUND_STRING(
            "Contraataca con el mismo\n"
            "movimiento."),
        .effect = EFFECT_MIRROR_MOVE,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_3,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MirrorMove,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SELF_DESTRUCT] =
    {
        .name = COMPOUND_STRING("AUTODESTRUCCIÓN"),
        .description = COMPOUND_STRING(
            "Potente, pero hace que te\n"
            "debilites."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 200 : 130,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .explosion = TRUE,
        .parentalBondBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_SelfDestruct,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EGG_BOMB] =
    {
        .name = COMPOUND_STRING("BOMBA HUEVO"),
        .description = COMPOUND_STRING(
            "Arroja un huevo al enemigo."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SOFT_BOILED},
        .battleAnimScript = gBattleAnimMove_EggBomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LICK] =
    {
        .name = COMPOUND_STRING("LENGÜETAZO"),
        .description = COMPOUND_STRING(
            "Usa la lengua para atacar.\n"
            "Puede causar parálisis."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Lick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMOG] =
    {
        .name = COMPOUND_STRING("POLUCIÓN"),
        .description = COMPOUND_STRING(
            "Gases de escape que pueden\n"
            "llegar a envenenar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20,
        .type = TYPE_POISON,
        .accuracy = 70,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 40,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SMOG,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Smog,
    },

    [MOVE_SLUDGE] =
    {
        .name = COMPOUND_STRING("RESIDUOS"),
        .description = COMPOUND_STRING(
            "Arroja residuos al rival.\n"
            "Puede llegar a envenenar."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 40,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SLUDGE,
        .contestComboMoves = {COMBO_STARTER_SLUDGE_BOMB},
        .battleAnimScript = gBattleAnimMove_Sludge,
    },

    [MOVE_BONE_CLUB] =
    {
        .name = COMPOUND_STRING("HUESO PALO"),
        .description = COMPOUND_STRING(
            "Aporrea con un hueso. Puede\n"
            "causar retroceso."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONE_CLUB,
        .contestComboMoves = {COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_BoneClub,
    },

    [MOVE_FIRE_BLAST] =
    {
        .name = COMPOUND_STRING("LLAMARADA"),
        .description = COMPOUND_STRING(
            "Llama que lo chamusca todo y\n"
            "suele causar quemadura."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireBlast,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATERFALL] =
    {
        .name = COMPOUND_STRING("CASCADA"),
        .description = COMPOUND_STRING(
            "Embiste a gran velocidad.\n"
            "Puede hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Waterfall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CLAMP] =
    {
        .name = COMPOUND_STRING("TENAZA"),
        .description = COMPOUND_STRING(
            "Atrapa y oprime al rival\n"
            "durante 4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 15 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_CLAMP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Clamp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWIFT] =
    {
        .name = COMPOUND_STRING("METEOROS"),
        .description = COMPOUND_STRING(
            "Lanza rayos en forma de\n"
            "estrella que no fallan."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Swift,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKULL_BASH] =
    {
        .name = COMPOUND_STRING("CABEZAZO"),
        .description = COMPOUND_STRING(
            "1.{SUPER_ER} turno: se prepara. 2.º: da\n"
            "el cabezazo."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNLOWEREDHEAD },
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
                .self = TRUE,
                .onChargeTurnOnly = TRUE,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkullBash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIKE_CANNON] =
    {
        .name = COMPOUND_STRING("CLAVO CAÑÓN"),
        .description = COMPOUND_STRING(
            "Lanza finas púas que hieren\n"
            "de 2 a 5 veces."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpikeCannon,
    },

    [MOVE_CONSTRICT] =
    {
        .name = COMPOUND_STRING("RESTRICCIÓN"),
        .description = COMPOUND_STRING(
            "Constriñe para herir y puede\n"
            "bajar la Velocidad."),
        .effect = EFFECT_HIT,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Constrict,
    },

    [MOVE_AMNESIA] =
    {
        .name = COMPOUND_STRING("AMNESIA"),
        .description = COMPOUND_STRING(
            "Olvida algo y aumenta mucho\n"
            "la Defensa Esp."),
        .effect = EFFECT_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_AMNESIA,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Amnesia,
        .validApprenticeMove = TRUE,
    },

    [MOVE_KINESIS] =
    {
        .name = COMPOUND_STRING("KINÉTICO"),
        .description = COMPOUND_STRING(
            "Distrae al rival y baja su\n"
            "nivel de Precisión."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_KINESIS,
        .contestComboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Kinesis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SOFT_BOILED] =
    {
        .name = COMPOUND_STRING("OVOCURACIÓN"),
        .description = COMPOUND_STRING(
            "Restaura hasta la mitad de\n"
            "los PS máximos."),
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_FIRST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SOFT_BOILED,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SoftBoiled,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HIGH_JUMP_KICK] =
    {
        .name = COMPOUND_STRING("PAT. SALTO ALTA"),
        .description = COMPOUND_STRING(
            "Si fallas esta patada, puedes\n"
            "autolesionarte."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 130,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 100,
        #else
            .power = 85,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_HighJumpKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GLARE] =
    {
        .name = COMPOUND_STRING("DESLUMBRAR"),
        .description = COMPOUND_STRING(
            "Intimida y asusta al rival\n"
            "hasta dejarlo paralizado."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 90,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_GLARE,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Glare,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DREAM_EATER] =
    {
        .name = COMPOUND_STRING("COMESUEÑOS"),
        .description = COMPOUND_STRING(
            "Roba la mitad del daño\n"
            "causado a un rival dormido."),
        .effect = EFFECT_DREAM_EATER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_DreamEater,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_GAS] =
    {
        .name = COMPOUND_STRING("GAS VENENOSO"),
        .description = COMPOUND_STRING(
            "Gas tóxico contra los\n"
            "rivales. Puede envenenar."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 90,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 80,
        #else
            .accuracy = 55,
        #endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_5 ? TARGET_BOTH : TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_POISON },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_POISON_GAS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonGas,
    },

    [MOVE_BARRAGE] =
    {
        .name = COMPOUND_STRING("BOMBARDEO"),
        .description = COMPOUND_STRING(
            "Arroja esferas al rival de 2 a\n"
            "5 veces."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Barrage,
    },

    [MOVE_LEECH_LIFE] =
    {
        .name = COMPOUND_STRING("CHUPAVIDAS"),
        .description = COMPOUND_STRING(
            "Roba la mitad del daño\n"
            "causado."),
        .effect = EFFECT_ABSORB,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeechLife,
    },

    [MOVE_LOVELY_KISS] =
    {
        .name = COMPOUND_STRING("BESO AMOROSO"),
        .description = COMPOUND_STRING(
            "Pide un beso con una cara que\n"
            "asusta y adormece."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_LOVELY_KISS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LovelyKiss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKY_ATTACK] =
    {
        .name = COMPOUND_STRING("ATAQUE AÉREO"),
        .description = COMPOUND_STRING(
            "En 2 turnos. Suele ser\n"
            "crítico y hacer retroceder."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = B_UPDATED_MOVE_DATA >= GEN_4 ? STRINGID_CLOAKEDINAHARSHLIGHT : STRINGID_PKMNISGLOWING },
    #if B_UPDATED_MOVE_DATA >= GEN_3
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
    #endif
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkyAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRANSFORM] =
    {
        .name = COMPOUND_STRING("TRANSFORMACIÓN"),
        .description = COMPOUND_STRING(
            "Modifica las células del rival\n"
            "y lo clona."),
        .effect = EFFECT_TRANSFORM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_5,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Transform,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BUBBLE] =
    {
        .name = COMPOUND_STRING("BURBUJA"),
        .description = COMPOUND_STRING(
            "Ataque con burbujas. Puede\n"
            "bajar la Velocidad."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 40 : 20,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Bubble,
    },

    [MOVE_DIZZY_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO MAREO"),
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .description = COMPOUND_STRING(
                "Puñetazo rítmico. Puede\n"
                "confundir al objetivo."),
        #else
            .description = COMPOUND_STRING(
                "Golpea al objetivo con\n"
                "puñetazos rítmicos."),
        #endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_CONFUSION,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DizzyPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPORE] =
    {
        .name = COMPOUND_STRING("ESPORA"),
        .description = COMPOUND_STRING(
            "Esparce esporas que inducen\n"
            "al sueño."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SPORE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLASH] =
    {
        .name = COMPOUND_STRING("DESTELLO"),
        .description = COMPOUND_STRING(
            "Ciega con un fogonazo de luz\n"
            "y baja la Precisión."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 70,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Flash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYWAVE] =
    {
        .name = COMPOUND_STRING("PSICOONDA"),
        .description = COMPOUND_STRING(
            "Ataque con onda psíquica de\n"
            "intensidad variable."),
        .effect = EFFECT_PSYWAVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Psywave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPLASH] =
    {
        .name = COMPOUND_STRING("SALPICADURA"),
        .description = COMPOUND_STRING(
            "No tiene ningún efecto. Sólo\n"
            "salpica."),
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_3 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Splash,
    },

    [MOVE_ACID_ARMOR] =
    {
        .name = COMPOUND_STRING("ARMADURA ÁCIDA"),
        .description = COMPOUND_STRING(
            "Te hace líquido y aumenta\n"
            "bastante tu Defensa."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AcidArmor,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CRABHAMMER] =
    {
        .name = COMPOUND_STRING("MARTILLAZO"),
        .description = COMPOUND_STRING(
            "Pinza con fuerza y suele dar\n"
            "un golpe crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Crabhammer,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXPLOSION] =
    {
        .name = COMPOUND_STRING("EXPLOSIÓN"),
        .description = COMPOUND_STRING(
            "Potente, pero hace que te\n"
            "debilites."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 250 : 170,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .explosion = TRUE,
        .parentalBondBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_Explosion,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FURY_SWIPES] =
    {
        .name = COMPOUND_STRING("GOLPES FURIA"),
        .description = COMPOUND_STRING(
            "Araña rápidamente de 2 a 5\n"
            "veces."),
        .effect = EFFECT_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCRATCH},
        .battleAnimScript = gBattleAnimMove_FurySwipes,
    },

    [MOVE_BONEMERANG] =
    {
        .name = COMPOUND_STRING("HUESOMERANG"),
        .description = COMPOUND_STRING(
            "Lanza un hueso a modo de\n"
            "bumerán, que da 2 veces."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .strikeCount = 2,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONEMERANG,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_Bonemerang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REST] =
    {
        .name = COMPOUND_STRING("DESCANSO"),
        .description = COMPOUND_STRING(
            "Te duerme durante 2 turnos\n"
            "para curarte totalmente."),
        .effect = EFFECT_REST,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_REST,
        .contestComboMoves = {COMBO_STARTER_BELLY_DRUM, COMBO_STARTER_CHARM, COMBO_STARTER_YAWN},
        .battleAnimScript = gBattleAnimMove_Rest,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_SLIDE] =
    {
        .name = COMPOUND_STRING("AVALANCHA"),
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .description = COMPOUND_STRING(
                "Lanza grandes pedruscos.\n"
                "Puede causar retroceso."),
        #else
            .description = COMPOUND_STRING(
                "Golpea al rival con una\n"
                "avalancha de rocas."),
        #endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 30,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROCK_THROW},
        .battleAnimScript = gBattleAnimMove_RockSlide,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPER_FANG] =
    {
        .name = COMPOUND_STRING("HIPERCOLMILLO"),
        .description = COMPOUND_STRING(
            "Ataque con finos colmillos.\n"
            "Puede causar retroceso."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperFang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHARPEN] =
    {
        .name = COMPOUND_STRING("AFILAR"),
        .description = COMPOUND_STRING(
            "Mejora el Ataque de quien lo\n"
            "usa."),
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sharpen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONVERSION] =
    {
        .name = COMPOUND_STRING("CONVERSIÓN"),
        .description = COMPOUND_STRING(
            "Cambia su tipo al de su primer\n"
            "movimiento."),
        .effect = EFFECT_CONVERSION,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Conversion,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRI_ATTACK] =
    {
        .name = COMPOUND_STRING("TRIATAQUE"),
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .description = COMPOUND_STRING(
                "Tres rayos. Puede quemar,\n"
                "paralizar o congelar."),
        #else
            .description = COMPOUND_STRING(
                "Se crea y lanza un campo\n"
                "triangular de energía."),
        #endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_TRI_ATTACK,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON},
        .battleAnimScript = gBattleAnimMove_TriAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPER_FANG] =
    {
        .name = COMPOUND_STRING("SUPERDIENTE"),
        .description = COMPOUND_STRING(
            "Finos colmillos que bajan a la\n"
            "mitad los PS del rival."),
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .damagePercentage = 50 },
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_SuperFang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLASH] =
    {
        .name = COMPOUND_STRING("CUCHILLADA"),
        .description = COMPOUND_STRING(
            "Acuchilla con pinzas, etc.\n"
            "Suele dar un golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCRATCH, COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Slash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUBSTITUTE] =
    {
        .name = COMPOUND_STRING("SUSTITUTO"),
        .description = COMPOUND_STRING(
            "Crea un señuelo con 1/4 de\n"
            "tus PS máximos."),
        .effect = EFFECT_SUBSTITUTE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Substitute,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRUGGLE] =
    {
        .name = COMPOUND_STRING("FORCEJEO"),
        .description = COMPOUND_STRING(
            "Sólo se usa al acabarse los\n"
            "PP. Te hiere un poco."),
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_STRUGGLE,
            .accuracy = 0,
            .pp = 1,
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_RECOIL_HP_25,
                .self = TRUE,
            }),
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .effect = EFFECT_RECOIL,
            .accuracy = 100,
            .pp = 1,
            .argument = { .recoilPercentage = 25 },
        #else
            .effect = EFFECT_RECOIL,
            .accuracy = 100,
            .pp = 10,
            .argument = { .recoilPercentage = 50 },
        #endif
        .power = 50,
        .type = TYPE_NORMAL,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .battleAnimScript = gBattleAnimMove_Struggle,
        .validApprenticeMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_TOUGH,
    },

    [MOVE_SKETCH] =
    {
        .name = COMPOUND_STRING("ESQUEMA"),
        .description = COMPOUND_STRING(
            "Copia siempre el último\n"
            "ataque del rival."),
        .effect = EFFECT_SKETCH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sketch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRIPLE_KICK] =
    {
        .name = COMPOUND_STRING("TRIPLE PATADA"),
        .description = COMPOUND_STRING(
            "Patea 3 veces seguidas y\n"
            "cada vez más fuerte."),
        .effect = EFFECT_TRIPLE_KICK,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_TripleKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THIEF] =
    {
        .name = COMPOUND_STRING("LADRÓN"),
        .description = COMPOUND_STRING(
            "Puede quitarle al rival el\n"
            "objeto que lleve."),
        .effect = EFFECT_STEAL_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Thief,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIDER_WEB] =
    {
        .name = COMPOUND_STRING("TELARAÑA"),
        .description = COMPOUND_STRING(
            "Enreda al rival para evitar\n"
            "que huya o pida el relevo."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_3,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_SpiderWeb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIND_READER] =
    {
        .name = COMPOUND_STRING("TELÉPATA"),
        .description = COMPOUND_STRING(
            "Adivina el ataque del otro y\n"
            "actúa en consecuencia."),
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_EARLIER : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_MIND_READER,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MindReader,
        .validApprenticeMove = TRUE,
    },

    [MOVE_NIGHTMARE] =
    {
        .name = COMPOUND_STRING("PESADILLA"),
        .description = COMPOUND_STRING(
            "El rival dormido pierde 1/4 de\n"
            "PS por turno."),
        .effect = EFFECT_NIGHTMARE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_3,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_Nightmare,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLAME_WHEEL] =
    {
        .name = COMPOUND_STRING("RUEDA FUEGO"),
        .description = COMPOUND_STRING(
            "Ataque de fuego que puede\n"
            "causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FlameWheel,
    },

    [MOVE_SNORE] =
    {
        .name = COMPOUND_STRING("RONQUIDO"),
        .description = COMPOUND_STRING(
            "Solo dormido. Ruido que puede\n"
            "hacer retroceder."),
        .effect = EFFECT_SNORE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_REST},
        .battleAnimScript = gBattleAnimMove_Snore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CURSE] =
    {
        .name = COMPOUND_STRING("MALDICIÓN"),
        .description = COMPOUND_STRING(
            "En el tipo Fantasma tiene un\n"
            "efecto distinto."),
        .effect = EFFECT_CURSE,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_5 ? TYPE_GHOST : TYPE_MYSTERY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_CURSE },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_CURSE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Curse,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLAIL] =
    {
        .name = COMPOUND_STRING("AZOTE"),
        .description = COMPOUND_STRING(
            "Causa un daño mayor si tienes\n"
            "pocos PS."),
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Flail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONVERSION_2] =
    {
        .name = COMPOUND_STRING("CONVERSIÓN 2"),
        .description = COMPOUND_STRING(
            "Tu tipo se hace resistente al\n"
            "último tipo de ataque."),
        .effect = EFFECT_CONVERSION_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = B_UPDATED_MOVE_DATA >= GEN_5 ? TARGET_SELECTED : TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Conversion2,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AEROBLAST] =
    {
        .name = COMPOUND_STRING("AEROCHORRO"),
        .description = COMPOUND_STRING(
            "Lanza un chorro de aire que\n"
            "suele dar un golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST :
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Aeroblast,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COTTON_SPORE] =
    {
        .name = COMPOUND_STRING("ESPORAGODÓN"),
        .description = COMPOUND_STRING(
            "Esporas que bajan mucho la\n"
            "Velocidad rival."),
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 85,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_6 ? TARGET_BOTH : TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CottonSpore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REVERSAL] =
    {
        .name = COMPOUND_STRING("INVERSIÓN"),
        .description = COMPOUND_STRING(
            "Causa un daño mayor si tienes\n"
            "pocos PS."),
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_LATER : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Reversal,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPITE] =
    {
        .name = COMPOUND_STRING("RENCOR"),
        .description = COMPOUND_STRING(
            "Quita 4 PP al último ataque\n"
            "del rival."),
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Spite,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POWDER_SNOW] =
    {
        .name = COMPOUND_STRING("NIEVE POLVO"),
        .description = COMPOUND_STRING(
            "Ráfaga de nieve contra los\n"
            "rivales. Puede congelar."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_POWDER_SNOW,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_PowderSnow,
    },

    [MOVE_PROTECT] =
    {
        .name = COMPOUND_STRING("PROTECCIÓN"),
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NORMAL },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_Protect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MACH_PUNCH] =
    {
        .name = COMPOUND_STRING("ULTRAPUÑO"),
        .description = COMPOUND_STRING(
            "Puñetazo que se da rápido\n"
            "para golpear primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MachPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCARY_FACE] =
    {
        .name = COMPOUND_STRING("CARA SUSTO"),
        .description = COMPOUND_STRING(
            "Asusta al enemigo para\n"
            "bajarle Velocidad."),
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCARY_FACE,
        .contestComboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_RAGE},
        .battleAnimScript = gBattleAnimMove_ScaryFace,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FEINT_ATTACK] =
    {
        .name = COMPOUND_STRING("FINTA"),
        .description = COMPOUND_STRING(
            "Acerca al enemigo para que el\n"
            "golpe no falle."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_LEER, COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_FeintAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWEET_KISS] =
    {
        .name = COMPOUND_STRING("BESO DULCE"),
        .description = COMPOUND_STRING(
            "Pide un beso con dulzura y\n"
            "suele causar confusión."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_SweetKiss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BELLY_DRUM] =
    {
        .name = COMPOUND_STRING("TAMBOR"),
        .description = COMPOUND_STRING(
            "Maximiza el Ataque a costa de\n"
            "la mitad de PS."),
        .effect = EFFECT_BELLY_DRUM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BELLY_DRUM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BellyDrum,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLUDGE_BOMB] =
    {
        .name = COMPOUND_STRING("BOMBA LODO"),
        .description = COMPOUND_STRING(
            "Arroja residuos al rival.\n"
            "Puede llegar a envenenar."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SLUDGE_BOMB,
        .contestComboMoves = {COMBO_STARTER_SLUDGE},
        .battleAnimScript = gBattleAnimMove_SludgeBomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SLAP] =
    {
        .name = COMPOUND_STRING("BOFETÓN LODO"),
        .description = COMPOUND_STRING(
            "Echa lodo en la cara para\n"
            "bajar la Precisión."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MUD_SLAP,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_SAND_ATTACK, COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_MudSlap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OCTAZOOKA] =
    {
        .name = COMPOUND_STRING("PULPOCAÑÓN"),
        .description = COMPOUND_STRING(
            "Dispara tinta para atacar y\n"
            "bajar la Precisión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Octazooka,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIKES] =
    {
        .name = COMPOUND_STRING("PÚAS"),
        .description = COMPOUND_STRING(
            "Riega púas que hieren si el\n"
            "rival pide el relevo."),
        .effect = EFFECT_SPIKES,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .forcePressure = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SPIKES,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spikes,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ZAP_CANNON] =
    {
        .name = COMPOUND_STRING("ELECTROCAÑÓN"),
        .description = COMPOUND_STRING(
            "No es certero, pero causa\n"
            "parálisis si atina."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON},
        .battleAnimScript = gBattleAnimMove_ZapCannon,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FORESIGHT] =
    {
        .name = COMPOUND_STRING("PROFECÍA"),
        .description = COMPOUND_STRING(
            "Anula los intentos del rival\n"
            "de aumentar la Evasión."),
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 0 : 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Foresight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DESTINY_BOND] =
    {
        .name = COMPOUND_STRING("MISMO DESTINO"),
        .description = COMPOUND_STRING(
            "Si te debilitas, el enemigo se\n"
            "debilita contigo."),
        .effect = EFFECT_DESTINY_BOND,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_FOLLOW_ME },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENDURE, COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_DestinyBond,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PERISH_SONG] =
    {
        .name = COMPOUND_STRING("CANTO MORTAL"),
        .description = COMPOUND_STRING(
            "A los 3 turnos del canto, caen\n"
            "rival y atacante."),
        .effect = EFFECT_PERISH_SONG,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_SING, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_PerishSong,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICY_WIND] =
    {
        .name = COMPOUND_STRING("VIENTO HIELO"),
        .description = COMPOUND_STRING(
            "Ataque helado que baja la\n"
            "Velocidad."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IcyWind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DETECT] =
    {
        .name = COMPOUND_STRING("DETECCIÓN"),
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NORMAL },
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT},
        .battleAnimScript = gBattleAnimMove_Detect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BONE_RUSH] =
    {
        .name = COMPOUND_STRING("ATAQUE ÓSEO"),
        .description = COMPOUND_STRING(
            "Hueso en ristre, aporrea al\n"
            "enemigo de 2 a 5 veces."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_GROUND,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONE_RUSH,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_BoneRush,
    },

    [MOVE_LOCK_ON] =
    {
        .name = COMPOUND_STRING("FIJAR BLANCO"),
        .description = COMPOUND_STRING(
            "Fija el blanco para que el\n"
            "siguiente ataque no falle."),
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_EARLIER : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_LOCK_ON,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LockOn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OUTRAGE] =
    {
        .name = COMPOUND_STRING("ENFADO"),
        .description = COMPOUND_STRING(
            "Dura de 2 a 3 turnos y acaba\n"
            "confundiéndote."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 15,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Outrage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SANDSTORM] =
    {
        .name = COMPOUND_STRING("TORMENTA ARENA"),
        .description = COMPOUND_STRING(
            "Tormenta de arena que dura\n"
            "varios turnos."),
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .windMove = TRUE,
        .argument = { .weatherType = BATTLE_WEATHER_SANDSTORM },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SANDSTORM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sandstorm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GIGA_DRAIN] =
    {
        .name = COMPOUND_STRING("GIGADRENADO"),
        .description = COMPOUND_STRING(
            "Roba la mitad del daño\n"
            "causado."),
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_GigaDrain,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENDURE] =
    {
        .name = COMPOUND_STRING("AGUANTE"),
        .description = COMPOUND_STRING(
            "Resiste el ataque de 1 turno\n"
            "y deja al menos 1 PS."),
        .effect = EFFECT_ENDURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NONE },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ENDURE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Endure,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CHARM] =
    {
        .name = COMPOUND_STRING("ENCANTO"),
        .description = COMPOUND_STRING(
            "Engatusa al rival y reduce\n"
            "bastante su Ataque."),
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_CHARM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Charm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLLOUT] =
    {
        .name = COMPOUND_STRING("RODAR"),
        .description = COMPOUND_STRING(
            "Ataque de 5 turnos cada vez\n"
            "más fuerte."),
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_Rollout,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FALSE_SWIPE] =
    {
        .name = COMPOUND_STRING("FALSO TORTAZO"),
        .description = sFalseSwipeDescription,
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_FalseSwipe,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWAGGER] =
    {
        .name = COMPOUND_STRING("FANFARRONEAR"),
        .description = COMPOUND_STRING(
            "Confunde al rival, pero sube\n"
            "mucho su Ataque."),
        .effect = EFFECT_SWAGGER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 85 : 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        //.ignoresSubstitute = TRUE, In Gen4+, the attack raise will no longer bypass Substitute. However, this is tricky to code
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Swagger,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MILK_DRINK] =
    {
        .name = COMPOUND_STRING("BATIDO"),
        .description = COMPOUND_STRING(
            "Restaura hasta la mitad de\n"
            "los PS máximos."),
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_FIRST : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MilkDrink,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPARK] =
    {
        .name = COMPOUND_STRING("CHISPA"),
        .description = COMPOUND_STRING(
            "Ataque eléctrico que puede\n"
            "llegar a paralizar."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Spark,
    },

    [MOVE_FURY_CUTTER] =
    {
        .name = COMPOUND_STRING("CORTE FURIA"),
        .description = COMPOUND_STRING(
            "Cada golpe seguido es más\n"
            "fuerte."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 20,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_FURY_CUTTER,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_FuryCutter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STEEL_WING] =
    {
        .name = COMPOUND_STRING("ALA DE ACERO"),
        .description = COMPOUND_STRING(
            "Alas rígidas que golpean al\n"
            "rival."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelWing,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEAN_LOOK] =
    {
        .name = COMPOUND_STRING("MAL DE OJO"),
        .description = COMPOUND_STRING(
            "Mal de ojo que impide al rival\n"
            "huir o pedir el relevo."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = (B_UPDATED_MOVE_FLAGS >= GEN_6) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_MEAN_LOOK,
        .contestComboMoves = {COMBO_STARTER_CURSE},
        .battleAnimScript = gBattleAnimMove_MeanLook,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ATTRACT] =
    {
        .name = COMPOUND_STRING("ATRACCIÓN"),
        .description = COMPOUND_STRING(
            "Reduce la posibilidad de que\n"
            "el enemigo ataque."),
        .effect = EFFECT_ATTRACT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Attract,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLEEP_TALK] =
    {
        .name = COMPOUND_STRING("SONÁMBULO"),
        .description = COMPOUND_STRING(
            "Mientras duerme, usa un\n"
            "ataque elegido al azar."),
        .effect = EFFECT_SLEEP_TALK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mimicBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_REST},
        .battleAnimScript = gBattleAnimMove_SleepTalk,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEAL_BELL] =
    {
        .name = COMPOUND_STRING("CASCABEL CURA"),
        .description = COMPOUND_STRING(
            "Repicar que cura los\n"
            "problemas de estado."),
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_HEAL_BELL,
        .contestComboMoves = {COMBO_STARTER_LUCKY_CHANT},
        .battleAnimScript = gBattleAnimMove_HealBell,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RETURN] =
    {
        .name = COMPOUND_STRING("RETRIBUCIÓN"),
        .description = COMPOUND_STRING(
            "Más potencia cuanto mayor\n"
            "sea la amistad."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Return,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PRESENT] =
    {
        .name = COMPOUND_STRING("PRESENTE"),
        .description = COMPOUND_STRING(
            "Regalo con forma de bomba.\n"
            "Puede que restaure los PS."),
        .effect = EFFECT_PRESENT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Present,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FRUSTRATION] =
    {
        .name = COMPOUND_STRING("FRUSTRACIÓN"),
        .description = COMPOUND_STRING(
            "Más fuerte cuanto menos\n"
            "aprecie al Entrenador."),
        .effect = EFFECT_FRUSTRATION,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Frustration,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAFEGUARD] =
    {
        .name = COMPOUND_STRING("VELO SAGRADO"),
        .description = COMPOUND_STRING(
            "Protege al equipo de estados\n"
            "durante 5 turnos."),
        .effect = EFFECT_SAFEGUARD,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 25,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Safeguard,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PAIN_SPLIT] =
    {
        .name = COMPOUND_STRING("DIVIDE DOLOR"),
        .description = COMPOUND_STRING(
            "Une tus PS a los del rival y\n"
            "los reparte por igual."),
        .effect = EFFECT_PAIN_SPLIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_PainSplit,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SACRED_FIRE] =
    {
        .name = COMPOUND_STRING("FUEGO SAGRADO"),
        .description = COMPOUND_STRING(
            "Fuego místico que puede\n"
            "causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SacredFire,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGNITUDE] =
    {
        .name = COMPOUND_STRING("MAGNITUD"),
        .description = COMPOUND_STRING(
            "Sacudida sísmica de\n"
            "intensidad variable."),
        .effect = EFFECT_MAGNITUDE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Magnitude,
    },

    [MOVE_DYNAMIC_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO DINÁMICO"),
        .description = COMPOUND_STRING(
            "No es certero, pero causa\n"
            "confusión si atina."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_DynamicPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEGAHORN] =
    {
        .name = COMPOUND_STRING("MEGACUERNO"),
        .description = COMPOUND_STRING(
            "Violenta embestida con\n"
            "retorcidos cuernos."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_BUG,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Megahorn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_BREATH] =
    {
        .name = COMPOUND_STRING("DRAGOALIENTO"),
        .description = COMPOUND_STRING(
            "Aliento que golpea al rival.\n"
            "Puede paralizar."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_BREATH,
        .contestComboMoves = {COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonBreath,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BATON_PASS] =
    {
        .name = COMPOUND_STRING("RELEVO"),
        .description = COMPOUND_STRING(
            "Cambia de compañero y\n"
            "mantiene los estados."),
        .effect = EFFECT_BATON_PASS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AGILITY, COMBO_STARTER_AMNESIA, COMBO_STARTER_HONE_CLAWS, COMBO_STARTER_CALM_MIND, COMBO_STARTER_NASTY_PLOT, COMBO_STARTER_ROCK_POLISH},
        .battleAnimScript = gBattleAnimMove_BatonPass,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENCORE] =
    {
        .name = COMPOUND_STRING("OTRA VEZ"),
        .description = COMPOUND_STRING(
            "Obliga al rival a repetir su\n"
            "último ataque 3 turnos."),
        .effect = EFFECT_ENCORE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .encoreBanned = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_ENCORE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Encore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PURSUIT] =
    {
        .name = COMPOUND_STRING("PERSECUCIÓN"),
        .description = COMPOUND_STRING(
            "Hace mucho daño al rival que\n"
            "pide el relevo."),
        .effect = EFFECT_PURSUIT,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pursuit,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAPID_SPIN] =
    {
        .name = COMPOUND_STRING("GIRO RÁPIDO"),
        .description = COMPOUND_STRING(
            "Gira y elimina efectos. Sube\n"
            "la Velocidad."),
        .effect = EFFECT_RAPID_SPIN,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 50 : 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RapidSpin,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWEET_SCENT] =
    {
        .name = COMPOUND_STRING("DULCE AROMA"),
        .description = COMPOUND_STRING(
            "Atrae a los rivales y baja\n"
            "mucho su Evasión."),
        .effect = B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_EVASION_DOWN_2 : EFFECT_EVASION_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SWEET_SCENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SweetScent,
        .validApprenticeMove = TRUE,
    },

    [MOVE_IRON_TAIL] =
    {
        .name = COMPOUND_STRING("COLA FÉRREA"),
        .description = COMPOUND_STRING(
            "Ataca con una cola férrea y\n"
            "puede bajar la Defensa."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronTail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METAL_CLAW] =
    {
        .name = COMPOUND_STRING("GARRA METAL"),
        .description = COMPOUND_STRING(
            "Ataque con garra que puede\n"
            "aumentar tu Ataque."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_METAL_SOUND},
        .battleAnimScript = gBattleAnimMove_MetalClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VITAL_THROW] =
    {
        .name = COMPOUND_STRING("LLAVE VITAL"),
        .description = COMPOUND_STRING(
            "Lleva su tiempo, pero no\n"
            "falla."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_VitalThrow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MORNING_SUN] =
    {
        .name = COMPOUND_STRING("SOL MATINAL"),
        .description = COMPOUND_STRING(
            "Restaura PS. La cantidad\n"
            "varía según el clima."),
        .effect = EFFECT_MORNING_SUN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_MorningSun,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SYNTHESIS] =
    {
        .name = COMPOUND_STRING("FOTOSÍNTESIS"),
        .description = COMPOUND_STRING(
            "Restaura PS. La cantidad\n"
            "varía según el clima."),
        .effect = EFFECT_SYNTHESIS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Synthesis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MOONLIGHT] =
    {
        .name = COMPOUND_STRING("LUZ LUNAR"),
        .description = COMPOUND_STRING(
            "Restaura PS. La cantidad\n"
            "varía según el clima."),
        .effect = EFFECT_MOONLIGHT,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Moonlight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HIDDEN_POWER] =
    {
        .name = COMPOUND_STRING("PODER OCULTO"),
        .description = COMPOUND_STRING(
            "El tipo varía según el\n"
            "usuario."),
        .power = B_HIDDEN_POWER_DMG >= GEN_6 ? 60 : 1,
        .effect = EFFECT_HIDDEN_POWER,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HiddenPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CROSS_CHOP] =
    {
        .name = COMPOUND_STRING("TAJO CRUZADO"),
        .description = COMPOUND_STRING(
            "Corte doble que suele\n"
            "propinar un golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_CrossChop,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TWISTER] =
    {
        .name = COMPOUND_STRING("CICLÓN"),
        .description = COMPOUND_STRING(
            "Crea un tornado feroz. Puede\n"
            "hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesAirborneDoubleDamage = TRUE,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Twister,
    },

    [MOVE_RAIN_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA LLUVIA"),
        .description = COMPOUND_STRING(
            "Refuerza los ataques de tipo\n"
            "Agua durante 5 turnos."),
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType =  BATTLE_WEATHER_RAIN },
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_RAIN_DANCE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RainDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUNNY_DAY] =
    {
        .name = COMPOUND_STRING("DÍA SOLEADO"),
        .description = COMPOUND_STRING(
            "Sube los ataques de tipo\n"
            "Fuego durante 5 turnos."),
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType = BATTLE_WEATHER_SUN },
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SUNNY_DAY,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SunnyDay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CRUNCH] =
    {
        .name = COMPOUND_STRING("TRITURAR"),
        .description = COMPOUND_STRING(
            "Muerde con colmillos. Puede\n"
            "bajar la Defensa."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
            .additionalEffects = ADDITIONAL_EFFECTS({
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
        #else
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        #endif
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Crunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIRROR_COAT] =
    {
        .name = COMPOUND_STRING("MANTO ESPEJO"),
        .description = COMPOUND_STRING(
            "Responde a un Ataque\n"
            "Especial con doble fuerza."),
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = -5,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = {
            .reflectDamage.damagePercent = 200,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = B_UPDATED_MOVE_FLAGS <= GEN_8,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT, COMBO_STARTER_ENCORE, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_MirrorCoat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYCH_UP] =
    {
        .name = COMPOUND_STRING("AUTOSUGESTIÓN"),
        .description = COMPOUND_STRING(
            "Copia los cambios de caract.\n"
            "del rival."),
        .effect = EFFECT_PSYCH_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS < GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXTREME_SPEED] =
    {
        .name = COMPOUND_STRING("VELOC. EXTREMA"),
        .description = COMPOUND_STRING(
            "Ataque extremadamente\n"
            "rápido y demoledor."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 2 : 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ExtremeSpeed,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ANCIENT_POWER] =
    {
        .name = COMPOUND_STRING("PODER PASADO"),
        .description = COMPOUND_STRING(
            "Ataque que puede subir todas\n"
            "las caract."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = B_UPDATED_MOVE_DATA < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AncientPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHADOW_BALL] =
    {
        .name = COMPOUND_STRING("BOLA SOMBRA"),
        .description = COMPOUND_STRING(
            "Lanza una bola negra que\n"
            "puede bajar la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FUTURE_SIGHT] =
    {
        .name = COMPOUND_STRING("PREMONICIÓN"),
        .description = COMPOUND_STRING(
            "Aumenta la energía interior\n"
            "para golpear a los 2 turnos."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 100,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 90,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_FutureSight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_SMASH] =
    {
        .name = COMPOUND_STRING("GOLPE ROCA"),
        .description = COMPOUND_STRING(
            "Ataque de fuerza brutal que\n"
            "puede bajar la Defensa."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 40 : 20,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockSmash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WHIRLPOOL] =
    {
        .name = COMPOUND_STRING("TORBELLINO"),
        .description = COMPOUND_STRING(
            "Atrapa y daña al rival en un\n"
            "remolino 4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesUnderwater = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_WHIRLPOOL,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Whirlpool,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BEAT_UP] =
    {
        .name = COMPOUND_STRING("PALIZA"),
        .description = COMPOUND_STRING(
            "Ataque de todo el equipo\n"
            "Pokémon."),
        .effect = EFFECT_BEAT_UP,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 1 : 10,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BEAT_UP_MESSAGE,
            .preAttackEffect = TRUE,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BeatUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FAKE_OUT] =
    {
        .name = COMPOUND_STRING("SORPRESA"),
        .description = COMPOUND_STRING(
            "Solo en su 1.{SUPER_ER} turno: ataca\n"
            "antes y hace retroceder."),
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 3 : 1,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .effect = EFFECT_FIRST_TURN_ONLY,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_FAKE_OUT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FakeOut,
        .validApprenticeMove = TRUE,
    },

    [MOVE_UPROAR] =
    {
        .name = COMPOUND_STRING("ALBOROTO"),
        .description = COMPOUND_STRING(
            "Alboroto de 3 turnos que\n"
            "impide dormir."),
        .effect = EFFECT_UPROAR,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_UPROAR,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Uproar,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STOCKPILE] =
    {
        .name = COMPOUND_STRING("RESERVA"),
        .description = COMPOUND_STRING(
            "Recarga energía hasta 3\n"
            "veces."),
        .effect = EFFECT_STOCKPILE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 20 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_STOCKPILE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Stockpile,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIT_UP] =
    {
        .name = COMPOUND_STRING("ESCUPIR"),
        .description = COMPOUND_STRING(
            "Libera energía acumulada.\n"
            "Cuanta más, mejor."),
        .effect = EFFECT_SPIT_UP,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STOCKPILE},
        .battleAnimScript = gBattleAnimMove_SpitUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWALLOW] =
    {
        .name = COMPOUND_STRING("TRAGAR"),
        .description = COMPOUND_STRING(
            "Absorbe energía acumulada y\n"
            "restaura PS."),
        .effect = EFFECT_SWALLOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STOCKPILE},
        .battleAnimScript = gBattleAnimMove_Swallow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEAT_WAVE] =
    {
        .name = COMPOUND_STRING("ONDA ÍGNEA"),
        .description = COMPOUND_STRING(
            "Aliento cálido contra los\n"
            "rivales. Puede quemar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 100,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_HeatWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HAIL] =
    {
        .name = COMPOUND_STRING("GRANIZO"),
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
            .description = COMPOUND_STRING(
                "Invoca una nevada que dura\n"
                "cinco turnos."),
        #else
            .description = COMPOUND_STRING(
                "Tormenta de granizo que\n"
                "golpea en cada turno."),
        #endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW) ? BATTLE_WEATHER_SNOW : BATTLE_WEATHER_HAIL },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_HAIL,
        .contestComboMoves = {0},
        .battleAnimScript = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW) ? gBattleAnimMove_Snowscape : gBattleAnimMove_Hail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TORMENT] =
    {
        .name = COMPOUND_STRING("TORMENTO"),
        .description = COMPOUND_STRING(
            "Agobia e impide el uso\n"
            "reiterado de un ataque."),
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_TORMENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Torment,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLATTER] =
    {
        .name = COMPOUND_STRING("CAMELO"),
        .description = COMPOUND_STRING(
            "Confunde al rival, pero sube\n"
            "su At. Esp."),
        .effect = EFFECT_FLATTER,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Flatter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WILL_O_WISP] =
    {
        .name = COMPOUND_STRING("FUEGO FATUO"),
        .description = COMPOUND_STRING(
            "Fuego muy intenso que\n"
            "produce quemaduras."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_BURN },
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_WILL_O_WISP,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_WillOWisp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEMENTO] =
    {
        .name = COMPOUND_STRING("LEGADO"),
        .description = COMPOUND_STRING(
            "Se debilita y baja mucho\n"
            "Ataque y At. Esp. rivales."),
        .effect = EFFECT_MEMENTO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESTORE_REPLACEMENT_HP },
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_Memento,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FACADE] =
    {
        .name = COMPOUND_STRING("FACHADA"),
        .description = COMPOUND_STRING(
            "Más fuerte si está quemado,\n"
            "paralizado o envenenado."),
        .effect = EFFECT_FACADE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Facade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOCUS_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO CERTERO"),
        .description = COMPOUND_STRING(
            "Potente; ataca último. Falla\n"
            "si le golpean antes."),
        .effect = EFFECT_FOCUS_PUNCH,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = -3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = TRUE,
        .punchingMove = TRUE,
        .meFirstBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_FocusPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMELLING_SALTS] =
    {
        .name = COMPOUND_STRING("ESTÍMULO"),
        .description = COMPOUND_STRING(
            "Afecta a rivales paralizados,\n"
            "pero también los cura."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 70 : 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_PARALYSIS },
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FORCE_PALM, COMBO_STARTER_THUNDER_WAVE, COMBO_STARTER_GLARE},
        .battleAnimScript = gBattleAnimMove_SmellingSalts,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOLLOW_ME] =
    {
        .name = COMPOUND_STRING("SEÑUELO"),
        .description = COMPOUND_STRING(
            "Llama la atención para\n"
            "concentrar los ataques."),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FollowMe,
        .validApprenticeMove = TRUE,
    },

    [MOVE_NATURE_POWER] =
    {
        .name = COMPOUND_STRING("ADAPTACIÓN"),
        .description = COMPOUND_STRING(
            "El tipo de ataque varía según\n"
            "el sitio."),
        .effect = EFFECT_NATURE_POWER,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = B_UPDATED_MOVE_FLAGS >= GEN_6 ? TARGET_SELECTED : TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturePower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CHARGE] =
    {
        .name = COMPOUND_STRING("CARGA"),
        .description = COMPOUND_STRING(
            "Recarga energía y sube el\n"
            "ataque eléctrico posterior."),
        .effect = EFFECT_CHARGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CHARGE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Charge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAUNT] =
    {
        .name = COMPOUND_STRING("MOFA"),
        .description = COMPOUND_STRING(
            "Hace que el rival sólo use\n"
            "ataques."),
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_4,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TAUNT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Taunt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HELPING_HAND] =
    {
        .name = COMPOUND_STRING("REFUERZO"),
        .description = COMPOUND_STRING(
            "Potencia los ataques del\n"
            "aliado."),
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = B_UPDATED_MOVE_DATA >= GEN_4 ? TARGET_ALLY : TARGET_USER,
        .priority = 5,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HelpingHand,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRICK] =
    {
        .name = COMPOUND_STRING("TRUCO"),
        .description = COMPOUND_STRING(
            "Engaña al rival y provoca un\n"
            "cambio de objeto."),
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Trick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLE_PLAY] =
    {
        .name = COMPOUND_STRING("IMITACIÓN"),
        .description = COMPOUND_STRING(
            "Imita al objetivo y copia su\n"
            "habilidad."),
        .effect = EFFECT_ROLE_PLAY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RolePlay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WISH] =
    {
        .name = COMPOUND_STRING("DESEO"),
        .description = COMPOUND_STRING(
            "Lleva tiempo, pero cumple el\n"
            "deseo de restaurar PS."),
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .healingMove = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_WISH,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Wish,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ASSIST] =
    {
        .name = COMPOUND_STRING("AYUDA"),
        .description = COMPOUND_STRING(
            "Ataque elegido al azar de un\n"
            "miembro del equipo."),
        .effect = EFFECT_ASSIST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Assist,
        .validApprenticeMove = TRUE,
    },

    [MOVE_INGRAIN] =
    {
        .name = COMPOUND_STRING("ARRAIGO"),
        .description = COMPOUND_STRING(
            "Echa raíces para recuperar\n"
            "PS, pero impide el relevo."),
        .effect = EFFECT_INGRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Ingrain,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPERPOWER] =
    {
        .name = COMPOUND_STRING("FUERZA BRUTA"),
        .description = COMPOUND_STRING(
            "Aumenta mucho la fuerza,\n"
            "pero las habilidades bajan."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_DEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_Superpower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGIC_COAT] =
    {
        .name = COMPOUND_STRING("CAPA MÁGICA"),
        .description = COMPOUND_STRING(
            "El agresor recibe el reflejo\n"
            "de los efectos especiales."),
        .effect = EFFECT_MAGIC_COAT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_DEPENDS,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicCoat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RECYCLE] =
    {
        .name = COMPOUND_STRING("RECICLAJE"),
        .description = COMPOUND_STRING(
            "Recicla un objeto usado para\n"
            "utilizarlo de nuevo."),
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Recycle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REVENGE] =
    {
        .name = COMPOUND_STRING("DESQUITE"),
        .description = sRevengeDescription,
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -4,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_REVENGE,
        .contestComboMoves = {COMBO_STARTER_PAYBACK},
        .battleAnimScript = gBattleAnimMove_Revenge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BRICK_BREAK] =
    {
        .name = COMPOUND_STRING("DEMOLICIÓN"),
        .description = COMPOUND_STRING(
            "Destruye barreras como\n"
            "Reflejo y causa daño."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_BrickBreak,
        .validApprenticeMove = TRUE,
    },

    [MOVE_YAWN] =
    {
        .name = COMPOUND_STRING("BOSTEZO"),
        .description = COMPOUND_STRING(
            "Provoca el bostezo y después\n"
            "el sueño."),
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_YAWN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Yawn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_KNOCK_OFF] =
    {
        .name = COMPOUND_STRING("DESARME"),
        .description = COMPOUND_STRING(
            "Deja al rival desprovisto del\n"
            "objeto que lleva."),
        .effect = EFFECT_KNOCK_OFF,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT},
        .battleAnimScript = gBattleAnimMove_KnockOff,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENDEAVOR] =
    {
        .name = COMPOUND_STRING("ESFUERZO"),
        .description = COMPOUND_STRING(
            "Iguala los PS del rival a los\n"
            "del usuario."),
        .effect = EFFECT_ENDEAVOR,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Endeavor,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ERUPTION] =
    {
        .name = COMPOUND_STRING("ESTALLIDO"),
        .description = COMPOUND_STRING(
            "Cuanto mayor sea el número\n"
            "de tus PS, más daño harás."),
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_EARTHQUAKE, COMBO_STARTER_ENDURE, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Eruption,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKILL_SWAP] =
    {
        .name = COMPOUND_STRING("INTERCAMBIO"),
        .description = COMPOUND_STRING(
            "Intercambia la habilidad\n"
            "especial con otro Pokémon."),
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkillSwap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_IMPRISON] =
    {
        .name = COMPOUND_STRING("SELLAR"),
        .description = COMPOUND_STRING(
            "Impide al rival usar ataques\n"
            "que tú conoces."),
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .forcePressure = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_DONT_EXCITE_AUDIENCE : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Imprison,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REFRESH] =
    {
        .name = COMPOUND_STRING("ALIVIO"),
        .description = COMPOUND_STRING(
            "Cura envenenamientos,\n"
            "parálisis y quemaduras."),
        .effect = EFFECT_REFRESH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SING, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_Refresh,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GRUDGE] =
    {
        .name = COMPOUND_STRING("RABIA"),
        .description = COMPOUND_STRING(
            "Si te debilitas, borra los PP\n"
            "del último ataque del rival."),
        .effect = EFFECT_GRUDGE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_FOLLOW_ME },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Grudge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SNATCH] =
    {
        .name = COMPOUND_STRING("ROBO"),
        .description = COMPOUND_STRING(
            "Roba el efecto del ataque\n"
            "que el objetivo use después."),
        .effect = EFFECT_SNATCH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .ignoresSubstitute = TRUE,
        .forcePressure = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Snatch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SECRET_POWER] =
    {
        .name = COMPOUND_STRING("DAÑO SECRETO"),
        .description = COMPOUND_STRING(
            "Efecto variable según el\n"
            "lugar."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SECRET_POWER,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SecretPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DIVE] =
    {
        .name = COMPOUND_STRING("BUCEO"),
        .description = COMPOUND_STRING(
            "1.{SUPER_ER} turno: bucea. 2.º: golpea."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 80 : 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNHIDUNDERWATER, .status = STATE_UNDERWATER },
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_DIVE,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SURF},
        .battleAnimScript = gBattleAnimMove_Dive,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ARM_THRUST] =
    {
        .name = COMPOUND_STRING("EMPUJÓN"),
        .description = COMPOUND_STRING(
            "Se dan puñetazos directos de\n"
            "2 a 5 veces."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_ArmThrust,
    },

    [MOVE_CAMOUFLAGE] =
    {
        .name = COMPOUND_STRING("CAMUFLAJE"),
        .description = COMPOUND_STRING(
            "Modifica el tipo del Pokémon\n"
            "según la zona donde esté."),
        .effect = EFFECT_CAMOUFLAGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Camouflage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAIL_GLOW] =
    {
        .name = COMPOUND_STRING("LUMINICOLA"),
        .description = COMPOUND_STRING(
            "Destello que sube muchísimo\n"
            "el At. Esp."),
        .effect = B_UPDATED_MOVE_DATA >= GEN_5 ? EFFECT_SPECIAL_ATTACK_UP_3 : EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TailGlow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LUSTER_PURGE] =
    {
        .name = COMPOUND_STRING("RESPLANDOR"),
        .description = COMPOUND_STRING(
            "Fogonazo de luz que puede\n"
            "bajar la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = (B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_LusterPurge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIST_BALL] =
    {
        .name = COMPOUND_STRING("BOLA NEBLINA"),
        .description = COMPOUND_STRING(
            "Banco de niebla que puede\n"
            "bajar el At. Esp."),
        .effect = EFFECT_HIT,
        .power = (B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_MistBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FEATHER_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA PLUMA"),
        .description = COMPOUND_STRING(
            "Envuelve al rival con plumón\n"
            "para reducir su Ataque."),
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FeatherDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TEETER_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA CAOS"),
        .description = COMPOUND_STRING(
            "Confunde a todos los Pokémon\n"
            "que hay en escena."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .danceMove = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_4,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TeeterDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLAZE_KICK] =
    {
        .name = COMPOUND_STRING("PATADA ÍGNEA"),
        .description = COMPOUND_STRING(
            "Suele ser un golpe crítico y\n"
            "causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_BlazeKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SPORT] =
    {
        .name = COMPOUND_STRING("CHAPOTEO LODO"),
        .description = COMPOUND_STRING(
            "Se cubre de lodo: debilita los\n"
            "ataques eléctricos."),
        // in theory this should mention 5 turns (gen 6+)
        .effect = EFFECT_MUD_SPORT,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MUD_SPORT,
        .contestComboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_MudSport,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_BALL] =
    {
        .name = COMPOUND_STRING("BOLA HIELO"),
        .description = COMPOUND_STRING(
            "Dura 5 turnos y gana fuerza\n"
            "en cada uno."),
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ballisticMove = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_DEFENSE_CURL},
        .battleAnimScript = gBattleAnimMove_IceBall,
    },

    [MOVE_NEEDLE_ARM] =
    {
        .name = COMPOUND_STRING("BRAZO PINCHO"),
        .description = COMPOUND_STRING(
            "Pega con brazos de pinchos y\n"
            "puede causar retroceso."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NeedleArm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLACK_OFF] =
    {
        .name = COMPOUND_STRING("RELAJO"),
        .description = COMPOUND_STRING(
            "Te relaja y restaura la mitad\n"
            "de los PS máximos."),
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SlackOff,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPER_VOICE] =
    {
        .name = COMPOUND_STRING("VOZARRÓN"),
        .description = COMPOUND_STRING(
            "Ondas sonoras de alta\n"
            "frecuencia que hieren."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperVoice,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_FANG] =
    {
        .name = COMPOUND_STRING("COLMILLO VENENO"),
        .description = COMPOUND_STRING(
            "Incisivos colmillos que\n"
            "pueden envenenar al rival."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TOXIC,
            .chance = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonFang,
    },

    [MOVE_CRUSH_CLAW] =
    {
        .name = COMPOUND_STRING("GARRA BRUTAL"),
        .description = COMPOUND_STRING(
            "Hace trizas al enemigo y\n"
            "puede bajar la Defensa."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_CrushClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLAST_BURN] =
    {
        .name = COMPOUND_STRING("ANILLO ÍGNEO"),
        .description = COMPOUND_STRING(
            "Es eficaz, pero deja inmóvil\n"
            "al atacante 1 turno."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_BlastBurn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYDRO_CANNON] =
    {
        .name = COMPOUND_STRING("HIDROCAÑÓN"),
        .description = COMPOUND_STRING(
            "Es eficaz, pero deja inmóvil\n"
            "al atacante 1 turno."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_HydroCannon,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METEOR_MASH] =
    {
        .name = COMPOUND_STRING("PUÑO METEORO"),
        .description = COMPOUND_STRING(
            "Impacta como un meteorito y\n"
            "suele subir el Ataque."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 100,
        .type = TYPE_STEEL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorMash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ASTONISH] =
    {
        .name = COMPOUND_STRING("IMPRESIONAR"),
        .description = COMPOUND_STRING(
            "Ataque que puede hacer\n"
            "retroceder al rival."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Astonish,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WEATHER_BALL] =
    {
        .name = COMPOUND_STRING("METEOROBOLA"),
        .description = COMPOUND_STRING(
            "El tipo y fuerza del ataque\n"
            "varían según el clima."),
        .effect = EFFECT_WEATHER_BALL,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 160 },
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SANDSTORM, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_WeatherBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AROMATHERAPY] =
    {
        .name = COMPOUND_STRING("AROMATERAPIA"),
        .description = COMPOUND_STRING(
            "Cura todos los problemas de\n"
            "estado con un suave aroma."),
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_6,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Aromatherapy,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FAKE_TEARS] =
    {
        .name = COMPOUND_STRING("LLANTO FALSO"),
        .description = COMPOUND_STRING(
            "Lágrimas de cocodrilo que\n"
            "bajan mucho la Def. Esp."),
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FakeTears,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AIR_CUTTER] =
    {
        .name = COMPOUND_STRING("AIRE AFILADO"),
        .description = COMPOUND_STRING(
            "Viento cortante que azota.\n"
            "Suele ser un golpe crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 55,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AirCutter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OVERHEAT] =
    {
        .name = COMPOUND_STRING("SOFOCO"),
        .description = COMPOUND_STRING(
            "Ataque en toda regla que\n"
            "baja mucho tu At. Esp."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = B_UPDATED_MOVE_DATA < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Overheat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ODOR_SLEUTH] =
    {
        .name = COMPOUND_STRING("RASTREO"),
        .description = COMPOUND_STRING(
            "Anula la Evasión y la\n"
            "inmunidad del tipo Fantasma."),
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OdorSleuth,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_TOMB] =
    {
        .name = COMPOUND_STRING("TUMBA ROCAS"),
        .description = COMPOUND_STRING(
            "Tira rocas al rival, lo para y\n"
            "le baja la Velocidad."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROCK_THROW},
        .battleAnimScript = gBattleAnimMove_RockTomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SILVER_WIND] =
    {
        .name = COMPOUND_STRING("VIENTO PLATA"),
        .description = COMPOUND_STRING(
            "Partículas de plata que\n"
            "quizá suban las habilidades."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SilverWind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METAL_SOUND] =
    {
        .name = COMPOUND_STRING("ECO METÁLICO"),
        .description = COMPOUND_STRING(
            "Tremendo chirrido que baja\n"
            "mucho la Def. Esp."),
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_METAL_SOUND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MetalSound,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GRASS_WHISTLE] =
    {
        .name = COMPOUND_STRING("SILBATO"),
        .description = COMPOUND_STRING(
            "Agradable melodía que\n"
            "adormece al rival."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 55,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_GRASS_WHISTLE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassWhistle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TICKLE] =
    {
        .name = COMPOUND_STRING("COSQUILLAS"),
        .description = COMPOUND_STRING(
            "Hace reír para bajar el\n"
            "Ataque y la Defensa."),
        .effect = EFFECT_TICKLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_4,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Tickle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COSMIC_POWER] =
    {
        .name = COMPOUND_STRING("MASA CÓSMICA"),
        .description = COMPOUND_STRING(
            "Sube la Defensa y la Def. Esp.\n"
            "con energía mística."),
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CosmicPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_SPOUT] =
    {
        .name = COMPOUND_STRING("SALPICAR"),
        .description = COMPOUND_STRING(
            "Si tienes muchos PS, el daño\n"
            "que causa es mucho mayor."),
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterSpout,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SIGNAL_BEAM] =
    {
        .name = COMPOUND_STRING("RAYO SEÑAL"),
        .description = COMPOUND_STRING(
            "Extraño ataque con rayo.\n"
            "Puede causar confusión."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SignalBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHADOW_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO SOMBRA"),
        .description = COMPOUND_STRING(
            "Puñetazo ineludible\n"
            "procedente de las sombras."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXTRASENSORY] =
    {
        .name = COMPOUND_STRING("PARANORMAL"),
        .description = COMPOUND_STRING(
            "Energía muy extraña que\n"
            "puede causar retroceso."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Extrasensory,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKY_UPPERCUT] =
    {
        .name = COMPOUND_STRING("GANCHO ALTO"),
        .description = COMPOUND_STRING(
            "Gancho ascendente de gran\n"
            "ímpetu."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .damagesAirborne = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_SkyUppercut,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAND_TOMB] =
    {
        .name = COMPOUND_STRING("BUCLE ARENA"),
        .description = COMPOUND_STRING(
            "Arenas movedizas que\n"
            "atrapan y dañan 4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_GROUND,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_SAND_TOMB,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_SandTomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHEER_COLD] =
    {
        .name = COMPOUND_STRING("FRÍO POLAR"),
        .description = COMPOUND_STRING(
            "Ataque polar que debilita al\n"
            "rival si le alcanza."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .noAffectOnSameTypeTarget = B_SHEER_COLD_IMMUNITY >= GEN_7,
        .accIncreaseByTenOnSameType = B_SHEER_COLD_ACC >= GEN_7,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_SheerCold,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUDDY_WATER] =
    {
        .name = COMPOUND_STRING("AGUA LODOSA"),
        .description = COMPOUND_STRING(
            "Ataque con agua lodosa que\n"
            "puede bajar la Precisión."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_MuddyWater,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BULLET_SEED] =
    {
        .name = COMPOUND_STRING("SEMILLADORA"),
        .description = COMPOUND_STRING(
            "Dispara de 2 a 5 ráfagas\n"
            "consecutivas de semillas."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_BulletSeed,
    },

    [MOVE_AERIAL_ACE] =
    {
        .name = COMPOUND_STRING("GOLPE AÉREO"),
        .description = COMPOUND_STRING(
            "Ataque tremendamente rápido\n"
            "e ineludible."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AerialAce,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICICLE_SPEAR] =
    {
        .name = COMPOUND_STRING("CARÁMBANO"),
        .description = COMPOUND_STRING(
            "Ataca lanzando de 2 a 5\n"
            "ráfagas de carámbanos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IcicleSpear,
    },

    [MOVE_IRON_DEFENSE] =
    {
        .name = COMPOUND_STRING("DEFENSA FÉRREA"),
        .description = COMPOUND_STRING(
            "Te fortalece y sube mucho la\n"
            "Defensa."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronDefense,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLOCK] =
    {
        .name = COMPOUND_STRING("BLOQUEO"),
        .description = COMPOUND_STRING(
            "Bloquea el paso al rival e\n"
            "impide su huida."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BLOCK,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Block,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HOWL] =
    {
        .name = COMPOUND_STRING("AULLIDO"),
        .description = COMPOUND_STRING(
            "Aullido que sube el ánimo y\n"
            "aumenta el Ataque."),
        .power = 0,
        .effect = EFFECT_ATTACK_UP,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_8 ? TARGET_USER_AND_ALLY: TARGET_USER ,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Howl,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_CLAW] =
    {
        .name = COMPOUND_STRING("GARRA DRAGÓN"),
        .description = COMPOUND_STRING(
            "Araña al rival con garras\n"
            "afiladas."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FRENZY_PLANT] =
    {
        .name = COMPOUND_STRING("PLANTA FEROZ"),
        .description = COMPOUND_STRING(
            "Es eficaz, pero deja inmóvil\n"
            "al atacante 1 turno."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_FrenzyPlant,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BULK_UP] =
    {
        .name = COMPOUND_STRING("CORPULENCIA"),
        .description = COMPOUND_STRING(
            "Robustece el cuerpo para\n"
            "subir Ataque y Defensa."),
        .effect = EFFECT_BULK_UP,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BulkUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BOUNCE] =
    {
        .name = COMPOUND_STRING("BOTE"),
        .description = COMPOUND_STRING(
            "1.{SUPER_ER} turno: bota. 2.º: golpea.\n"
            "Puede paralizar."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 85,
        .type = TYPE_FLYING,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNSPRANGUP, .status = STATE_ON_AIR },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bounce,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SHOT] =
    {
        .name = COMPOUND_STRING("DISPARO LODO"),
        .description = COMPOUND_STRING(
            "Dispara lodo al rival y reduce\n"
            "su Velocidad."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_MudShot,
    },

    [MOVE_POISON_TAIL] =
    {
        .name = COMPOUND_STRING("COLA VENENO"),
        .description = COMPOUND_STRING(
            "Puede envenenar y dar un\n"
            "golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_PoisonTail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COVET] =
    {
        .name = COMPOUND_STRING("ANTOJO"),
        .description = COMPOUND_STRING(
            "Pide con ternura al rival el\n"
            "objeto que lleve."),
        .effect = EFFECT_STEAL_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 60 : 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_COVET,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Covet,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VOLT_TACKLE] =
    {
        .name = COMPOUND_STRING("PLACAJE ELÉC"),
        #if B_UPDATED_MOVE_DATA >= GEN_4
        .description = COMPOUND_STRING(
            "Placaje arriesgado que le\n"
            "daña. Puede paralizar."),
        #else
        .description = COMPOUND_STRING(
            "Placaje arriesgado que\n"
            "daña un poco al usuario."),
        #endif
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_PARALYSIS,
                .chance = 10,
            }),
        #endif
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_VoltTackle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGICAL_LEAF] =
    {
        .name = COMPOUND_STRING("HOJA MÁGICA"),
        .description = COMPOUND_STRING(
            "Ataca con una extraña hoja\n"
            "que no se puede esquivar."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_MagicalLeaf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_SPORT] =
    {
        .name = COMPOUND_STRING("HIDROCHORRO"),
        .description = COMPOUND_STRING(
            "Se empapa: debilita los\n"
            "ataques de fuego."),
        // in theory this should mention 5 turns (gen6+)
        .effect = EFFECT_WATER_SPORT,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_WATER_SPORT,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterSport,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CALM_MIND] =
    {
        .name = COMPOUND_STRING("PAZ MENTAL"),
        .description = COMPOUND_STRING(
            "Sube el At. Esp. y la Def. Esp.\n"
            "con concentración."),
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CALM_MIND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CalmMind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LEAF_BLADE] =
    {
        .name = COMPOUND_STRING("HOJA AGUDA"),
        .description = COMPOUND_STRING(
            "Acuchilla con una hoja fina.\n"
            "Suele dar un golpe crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafBlade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA DRAGÓN"),
        .description = COMPOUND_STRING(
            "Danza mística que sube el\n"
            "Ataque y la Velocidad."),
        .effect = EFFECT_DRAGON_DANCE,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_DANCE,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_BLAST] =
    {
        .name = COMPOUND_STRING("PEDRADA"),
        .description = COMPOUND_STRING(
            "Lanza pedruscos al rival de 2\n"
            "a 5 veces consecutivas."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = B_UPDATED_MOVE_FLAGS >= GEN_7,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockBlast,
    },

    [MOVE_SHOCK_WAVE] =
    {
        .name = COMPOUND_STRING("ONDA VOLTIO"),
        .description = COMPOUND_STRING(
            "Ataque eléctrico muy rápido e\n"
            "ineludible."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ShockWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_PULSE] =
    {
        .name = COMPOUND_STRING("HIDROPULSO"),
        .description = COMPOUND_STRING(
            "Ondas ultrasónicas que\n"
            "pueden confundir al rival."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterPulse,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOOM_DESIRE] =
    {
        .name = COMPOUND_STRING("DESEO OCULTO"),
        .description = COMPOUND_STRING(
            "Atrae una luz intensa que\n"
            "ataca 2 turnos después."),
        .effect = EFFECT_FUTURE_SIGHT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 120,
        .type = TYPE_STEEL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST :
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoomDesire,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYCHO_BOOST] =
    {
        .name = COMPOUND_STRING("PSICOATAQUE"),
        .description = COMPOUND_STRING(
            "Ataque en toda regla que\n"
            "baja mucho tu At. Esp."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_PsychoBoost,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROOST] =
    {
        .name = COMPOUND_STRING("RESPIRO"),
        .description = COMPOUND_STRING(
            "Recupera la mitad de los PS\n"
            "máximos."),
        .effect = EFFECT_ROOST,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_BRAVE_BIRD},
        .battleAnimScript = gBattleAnimMove_Roost,
    },

    [MOVE_GRAVITY] =
    {
        .name = COMPOUND_STRING("GRAVEDAD"),
        .description = COMPOUND_STRING(
            "Intensifica la gravedad y\n"
            "anula la levitación."),
        .effect = EFFECT_GRAVITY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Gravity,
    },

    [MOVE_MIRACLE_EYE] =
    {
        .name = COMPOUND_STRING("GRAN OJO"),
        .description = COMPOUND_STRING(
            "Anula la Evasión y la\n"
            "inmunidad del tipo Siniestro."),
        .effect = EFFECT_MIRACLE_EYE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MiracleEye,
    },

    [MOVE_WAKE_UP_SLAP] =
    {
        .name = COMPOUND_STRING("ESPABILA"),
        .description = COMPOUND_STRING(
            "Fuerte contra dormidos, pero\n"
            "los despierta."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 70 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_SLEEP },
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
        }),
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_WakeUpSlap,
    },

    [MOVE_HAMMER_ARM] =
    {
        .name = COMPOUND_STRING("MACHADA"),
        .description = COMPOUND_STRING(
            "Golpe de puño que también\n"
            "baja la Velocidad."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_HammerArm,
    },

    [MOVE_GYRO_BALL] =
    {
        .name = COMPOUND_STRING("GIRO BOLA"),
        .description = COMPOUND_STRING(
            "Giro rápido; más daño a\n"
            "rivales más veloces."),
        .effect = EFFECT_GYRO_BALL,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GyroBall,
    },

    [MOVE_HEALING_WISH] =
    {
        .name = COMPOUND_STRING("DESEO CURA"),
        .description = sHealingWishDescription,
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .healingMove = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealingWish,
    },

    [MOVE_BRINE] =
    {
        .name = COMPOUND_STRING("SALMUERA"),
        .description = COMPOUND_STRING(
            "Doble daño si el rival tiene la\n"
            "mitad de PS o menos."),
        .effect = EFFECT_BRINE,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Brine,
    },

    [MOVE_NATURAL_GIFT] =
    {
        .name = COMPOUND_STRING("DON NATURAL"),
        .description = COMPOUND_STRING(
            "Efecto según la Baya que\n"
            "lleve."),
        .effect = EFFECT_NATURAL_GIFT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturalGift,
    },

    [MOVE_FEINT] =
    {
        .name = COMPOUND_STRING("AMAGO"),
        .description = sFeintDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 30 : 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_6,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Feint,
    },

    [MOVE_PLUCK] =
    {
        .name = COMPOUND_STRING("PICOTEO"),
        .description = sPluckDescription,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BUG_BITE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pluck,
    },

    [MOVE_TAILWIND] =
    {
        .name = COMPOUND_STRING("VIENTO AFÍN"),
        .description = COMPOUND_STRING(
            "Viento que duplica la\n"
            "Velocidad aliada 4 turnos."),
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .snatchAffected = TRUE,
        .windMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Tailwind,
    },

    [MOVE_ACUPRESSURE] =
    {
        .name = COMPOUND_STRING("ACUPRESIÓN"),
        .description = COMPOUND_STRING(
            "Sube mucho una de sus\n"
            "caract."),
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER_OR_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS < GEN_5,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acupressure,
    },

    [MOVE_METAL_BURST] =
    {
        .name = COMPOUND_STRING("REPRESIÓN METAL"),
        .description = COMPOUND_STRING(
            "Devuelve cualquier golpe con\n"
            "más potencia."),
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .reflectDamage.damagePercent = 150,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL | 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .meFirstBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_METAL_SOUND, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_MetalBurst,
    },

    [MOVE_U_TURN] =
    {
        .name = COMPOUND_STRING("IDA Y VUELTA"),
        .description = sUTurnDescription,
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_UTurn,
    },

    [MOVE_CLOSE_COMBAT] =
    {
        .name = COMPOUND_STRING("A BOCAJARRO"),
        .description = sCloseCombatDescription,
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_CloseCombat,
    },

    [MOVE_PAYBACK] =
    {
        .name = COMPOUND_STRING("VENDETTA"),
        .description = COMPOUND_STRING(
            "Más potencia si el usuario\n"
            "ataca el último."),
        .effect = EFFECT_PAYBACK,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_PAYBACK,
        .contestComboMoves = {COMBO_STARTER_REVENGE},
        .battleAnimScript = gBattleAnimMove_Payback,
    },

    [MOVE_ASSURANCE] =
    {
        .name = COMPOUND_STRING("BUENA BAZA"),
        .description = COMPOUND_STRING(
            "Más potencia si el rival ya ha\n"
            "recibido daño."),
        .effect = EFFECT_ASSURANCE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PAYBACK, COMBO_STARTER_REVENGE},
        .battleAnimScript = gBattleAnimMove_Assurance,
    },

    [MOVE_EMBARGO] =
    {
        .name = COMPOUND_STRING("EMBARGO"),
        .description = COMPOUND_STRING(
            "Impide al rival usar objetos."),
        .effect = EFFECT_EMBARGO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Embargo,
    },

    [MOVE_FLING] =
    {
        .name = COMPOUND_STRING("LANZAMIENTO"),
        .description = COMPOUND_STRING(
            "Efecto según el objeto que\n"
            "lleve."),
        .effect = EFFECT_FLING,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Fling,
    },

    [MOVE_PSYCHO_SHIFT] =
    {
        .name = COMPOUND_STRING("PSICOCAMBIO"),
        .description = COMPOUND_STRING(
            "Transfiere sus problemas de\n"
            "estado al rival."),
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_2 },
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychoShift,
    },

    [MOVE_TRUMP_CARD] =
    {
        .name = COMPOUND_STRING("AS OCULTO"),
        .description = COMPOUND_STRING(
            "Cuantos menos PP le queden,\n"
            "más daño hace."),
        .effect = EFFECT_TRUMP_CARD,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrumpCard,
    },

    [MOVE_HEAL_BLOCK] =
    {
        .name = COMPOUND_STRING("ANTICURA"),
        .description = COMPOUND_STRING(
            "Impide a los rivales\n"
            "recuperar PS 5 turnos."),
        .effect = EFFECT_HEAL_BLOCK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_2 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealBlock,
    },

    [MOVE_WRING_OUT] =
    {
        .name = COMPOUND_STRING("ESTRUJÓN"),
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WringOut,
    },

    [MOVE_POWER_TRICK] =
    {
        .name = COMPOUND_STRING("TRUCO FUERZA"),
        .description = COMPOUND_STRING(
            "Intercambia su Ataque y su\n"
            "Defensa."),
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerTrick,
    },

    [MOVE_GASTRO_ACID] =
    {
        .name = COMPOUND_STRING("BILIS"),
        .description = COMPOUND_STRING(
            "Jugo gástrico que anula la\n"
            "habilidad rival."),
        .effect = EFFECT_GASTRO_ACID,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GastroAcid,
    },

    [MOVE_LUCKY_CHANT] =
    {
        .name = COMPOUND_STRING("CONJURO"),
        .description = COMPOUND_STRING(
            "Impide que el rival aseste\n"
            "golpes críticos."),
        .effect = EFFECT_LUCKY_CHANT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_LUCKY_CHANT,
        .contestComboMoves = {COMBO_STARTER_HEAL_BELL},
        .battleAnimScript = gBattleAnimMove_LuckyChant,
    },

    [MOVE_ME_FIRST] =
    {
        .name = COMPOUND_STRING("YO PRIMERO"),
        .description = COMPOUND_STRING(
            "Usa el ataque del rival con\n"
            "más potencia."),
        .effect = EFFECT_ME_FIRST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENT,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeFirst,
    },

    [MOVE_COPYCAT] =
    {
        .name = COMPOUND_STRING("COPIÓN"),
        .description = COMPOUND_STRING(
            "Imita el último ataque usado\n"
            "por un rival."),
        .effect = EFFECT_COPYCAT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Copycat,
    },

    [MOVE_POWER_SWAP] =
    {
        .name = COMPOUND_STRING("CAMBIAFUERZA"),
        .description = COMPOUND_STRING(
            "Intercambia con el rival\n"
            "cambios de Ataque y At. Esp."),
        .effect = EFFECT_POWER_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerSwap,
    },

    [MOVE_GUARD_SWAP] =
    {
        .name = COMPOUND_STRING("CAMBIADEFENSA"),
        .description = COMPOUND_STRING(
            "Intercambia cambios de\n"
            "Defensa y Def. Esp."),
        .effect = EFFECT_GUARD_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GuardSwap,
    },

    [MOVE_PUNISHMENT] =
    {
        .name = COMPOUND_STRING("CASTIGO"),
        .description = COMPOUND_STRING(
            "Más daño cuanto más se haya\n"
            "fortalecido el rival."),
        .effect = EFFECT_PUNISHMENT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Punishment,
    },

    [MOVE_LAST_RESORT] =
    {
        .name = COMPOUND_STRING("ÚLTIMA BAZA"),
        .description = COMPOUND_STRING(
            "Solo puede usarse tras usar\n"
            "los demás ataques."),
        .effect = EFFECT_LAST_RESORT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 130,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LastResort,
    },

    [MOVE_WORRY_SEED] =
    {
        .name = COMPOUND_STRING("ABATIDORAS"),
        .description = COMPOUND_STRING(
            "Planta una semilla que da\n"
            "Insomnio al rival."),
        .effect = EFFECT_OVERWRITE_ABILITY,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .overwriteAbility = ABILITY_INSOMNIA },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_WORRY_SEED,
        .contestComboMoves = {COMBO_STARTER_LEECH_SEED, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_WorrySeed,
    },

    [MOVE_SUCKER_PUNCH] =
    {
        .name = COMPOUND_STRING("GOLPE BAJO"),
        .description = sSuckerPunchDescription,
        .effect = EFFECT_SUCKER_PUNCH,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 70 : 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SuckerPunch,
    },

    [MOVE_TOXIC_SPIKES] =
    {
        .name = COMPOUND_STRING("PÚAS TÓXICAS"),
        .description = COMPOUND_STRING(
            "Esparce púas que envenenan\n"
            "al rival que entra."),
        .effect = EFFECT_TOXIC_SPIKES,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .forcePressure = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TOXIC_SPIKES,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ToxicSpikes,
    },

    [MOVE_HEART_SWAP] =
    {
        .name = COMPOUND_STRING("CAMBIAALMAS"),
        .description = COMPOUND_STRING(
            "Intercambia los cambios de\n"
            "caract. con el rival."),
        .effect = EFFECT_HEART_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeartSwap,
    },

    [MOVE_AQUA_RING] =
    {
        .name = COMPOUND_STRING("ACUA ARO"),
        .description = COMPOUND_STRING(
            "Crea un velo de agua que\n"
            "recupera PS."),
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AquaRing,
    },

    [MOVE_MAGNET_RISE] =
    {
        .name = COMPOUND_STRING("LEVITÓN"),
        .description = COMPOUND_STRING(
            "Levita mediante\n"
            "electromagnetismo."),
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagnetRise,
    },

    [MOVE_FLARE_BLITZ] =
    {
        .name = COMPOUND_STRING("ENVITE ÍGNEO"),
        .description = COMPOUND_STRING(
            "Carga que puede quemar.\n"
            "También daña al usuario."),
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FlareBlitz,
    },

    [MOVE_FORCE_PALM] =
    {
        .name = COMPOUND_STRING("PALMEO"),
        .description = COMPOUND_STRING(
            "Onda de choque que puede\n"
            "paralizar al rival."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_FORCE_PALM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ForcePalm,
    },

    [MOVE_AURA_SPHERE] =
    {
        .name = COMPOUND_STRING("ESFERA AURAL"),
        .description = COMPOUND_STRING(
            "Onda de aura que no se puede\n"
            "esquivar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 90,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AuraSphere,
    },

    [MOVE_ROCK_POLISH] =
    {
        .name = COMPOUND_STRING("PULIMENTO"),
        .description = COMPOUND_STRING(
            "Pule su cuerpo para subir\n"
            "mucho la Velocidad."),
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROCK_POLISH,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockPolish,
    },

    [MOVE_POISON_JAB] =
    {
        .name = COMPOUND_STRING("PUYA NOCIVA"),
        .description = COMPOUND_STRING(
            "Ataque punzante que puede\n"
            "envenenar al rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonJab,
    },

    [MOVE_DARK_PULSE] =
    {
        .name = COMPOUND_STRING("PULSO UMBRÍO"),
        .description = COMPOUND_STRING(
            "Aura horrible. Puede hacer\n"
            "retroceder."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkPulse,
    },

    [MOVE_NIGHT_SLASH] =
    {
        .name = COMPOUND_STRING("TAJO UMBRÍO"),
        .description = COMPOUND_STRING(
            "Golpea lo antes posible.\n"
            "Suele ser crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_NightSlash,
    },

    [MOVE_AQUA_TAIL] =
    {
        .name = COMPOUND_STRING("ACUA COLA"),
        .description = COMPOUND_STRING(
            "Agita la cola como una ola\n"
            "para atacar."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_AquaTail,
    },

    [MOVE_SEED_BOMB] =
    {
        .name = COMPOUND_STRING("BOMBA GERMEN"),
        .description = COMPOUND_STRING(
            "Dispara una ráfaga de\n"
            "semillas duras."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_SeedBomb,
    },

    [MOVE_AIR_SLASH] =
    {
        .name = COMPOUND_STRING("TAJO AÉREO"),
        .description = COMPOUND_STRING(
            "Cuchilla de aire. Puede hacer\n"
            "retroceder."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AirSlash,
    },

    [MOVE_X_SCISSOR] =
    {
        .name = COMPOUND_STRING("TIJERA X"),
        .description = COMPOUND_STRING(
            "Corta en cruz con guadañas,\n"
            "garras, etc."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_XScissor,
    },

    [MOVE_BUG_BUZZ] =
    {
        .name = COMPOUND_STRING("ZUMBIDO"),
        .description = COMPOUND_STRING(
            "Onda sonora dañina. Puede\n"
            "bajar la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTIFUL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BugBuzz,
    },

    [MOVE_DRAGON_PULSE] =
    {
        .name = COMPOUND_STRING("PULSO DRAGÓN"),
        .description = COMPOUND_STRING(
            "Genera una onda de choque\n"
            "que daña al rival."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonPulse,
    },

    [MOVE_DRAGON_RUSH] =
    {
        .name = COMPOUND_STRING("CARGA DRAGÓN"),
        .description = COMPOUND_STRING(
            "Placaje amenazador. Puede\n"
            "hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_RUSH,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonRush,
    },

    [MOVE_POWER_GEM] =
    {
        .name = COMPOUND_STRING("JOYA DE LUZ"),
        .description = COMPOUND_STRING(
            "Rayos de luz que brillan como\n"
            "diamantes."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 70,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerGem,
    },

    [MOVE_DRAIN_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO DRENAJE"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_DrainPunch,
    },

    [MOVE_VACUUM_WAVE] =
    {
        .name = COMPOUND_STRING("ONDA VACÍO"),
        .description = COMPOUND_STRING(
            "Puños que lanzan una onda\n"
            "que golpea primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VacuumWave,
    },

    [MOVE_FOCUS_BLAST] =
    {
        .name = COMPOUND_STRING("ONDA CERTERA"),
        .description = COMPOUND_STRING(
            "Ataque a plena potencia.\n"
            "Puede bajar la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_FocusBlast,
    },

    [MOVE_ENERGY_BALL] =
    {
        .name = COMPOUND_STRING("ENERGIBOLA"),
        .description = COMPOUND_STRING(
            "Poder de la naturaleza. Puede\n"
            "bajar la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_EnergyBall,
    },

    [MOVE_BRAVE_BIRD] =
    {
        .name = COMPOUND_STRING("PÁJARO OSADO"),
        .description = COMPOUND_STRING(
            "Carga a baja altura que\n"
            "también daña al usuario."),
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BRAVE_BIRD,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BraveBird,
    },

    [MOVE_EARTH_POWER] =
    {
        .name = COMPOUND_STRING("TIERRA VIVA"),
        .description = COMPOUND_STRING(
            "Hace estallar el suelo. Puede\n"
            "bajar la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EarthPower,
    },

    [MOVE_SWITCHEROO] =
    {
        .name = COMPOUND_STRING("TRAPICHEO"),
        .description = COMPOUND_STRING(
            "Cambia objetos con el rival a\n"
            "gran velocidad."),
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Switcheroo,
    },

    [MOVE_GIGA_IMPACT] =
    {
        .name = COMPOUND_STRING("GIGAIMPACTO"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GigaImpact,
    },

    [MOVE_NASTY_PLOT] =
    {
        .name = COMPOUND_STRING("MAQUINACIÓN"),
        .description = COMPOUND_STRING(
            "Malos pensamientos que\n"
            "suben mucho el At. Esp."),
        .effect = EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_NASTY_PLOT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NastyPlot,
    },

    [MOVE_BULLET_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO BALA"),
        .description = COMPOUND_STRING(
            "Puñetazo veloz como una\n"
            "bala. Siempre va primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BulletPunch,
    },

    [MOVE_AVALANCHE] =
    {
        .name = COMPOUND_STRING("ALUD"),
        .description = sRevengeDescription,
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -4,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Avalanche,
    },

    [MOVE_ICE_SHARD] =
    {
        .name = COMPOUND_STRING("ESQUIRLA HELADA"),
        .description = COMPOUND_STRING(
            "Lanza un trozo de hielo.\n"
            "Siempre va primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IceShard,
    },

    [MOVE_SHADOW_CLAW] =
    {
        .name = COMPOUND_STRING("GARRA UMBRÍA"),
        .description = COMPOUND_STRING(
            "Garra de sombra. Suele ser\n"
            "crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_ShadowClaw,
    },

    [MOVE_THUNDER_FANG] =
    {
        .name = COMPOUND_STRING("COLMILLO RAYO"),
        .description = COMPOUND_STRING(
            "Puede hacer retroceder o\n"
            "paralizar al rival."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_THUNDER_FANG,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_FANG, COMBO_STARTER_ICE_FANG},
        .battleAnimScript = gBattleAnimMove_ThunderFang,
    },

    [MOVE_ICE_FANG] =
    {
        .name = COMPOUND_STRING("COLMILLO HIELO"),
        .description = COMPOUND_STRING(
            "Puede hacer retroceder o\n"
            "congelar al rival."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_ICE_FANG,
        .contestComboMoves = {COMBO_STARTER_FIRE_FANG, COMBO_STARTER_THUNDER_FANG},
        .battleAnimScript = gBattleAnimMove_IceFang,
    },

    [MOVE_FIRE_FANG] =
    {
        .name = COMPOUND_STRING("COLMILLO ÍGNEO"),
        .description = COMPOUND_STRING(
            "Puede hacer retroceder o\n"
            "quemar al rival."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_FIRE_FANG,
        .contestComboMoves = {COMBO_STARTER_ICE_FANG, COMBO_STARTER_THUNDER_FANG},
        .battleAnimScript = gBattleAnimMove_FireFang,
    },

    [MOVE_SHADOW_SNEAK] =
    {
        .name = COMPOUND_STRING("SOMBRA VIL"),
        .description = COMPOUND_STRING(
            "Extiende su sombra para\n"
            "golpear primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowSneak,
    },

    [MOVE_MUD_BOMB] =
    {
        .name = COMPOUND_STRING("BOMBA FANGO"),
        .description = COMPOUND_STRING(
            "Lanza barro que daña y baja\n"
            "la Precisión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MudBomb,
    },

    [MOVE_PSYCHO_CUT] =
    {
        .name = COMPOUND_STRING("PSICOCORTE"),
        .description = COMPOUND_STRING(
            "Cuchillas psíquicas. Suele\n"
            "ser crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychoCut,
    },

    [MOVE_ZEN_HEADBUTT] =
    {
        .name = COMPOUND_STRING("CABEZAZO ZEN"),
        .description = COMPOUND_STRING(
            "Fuerte cabezazo. Puede hacer\n"
            "retroceder."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ZenHeadbutt,
    },

    [MOVE_MIRROR_SHOT] =
    {
        .name = COMPOUND_STRING("DISPARO ESPEJO"),
        .description = COMPOUND_STRING(
            "Destello de energía que daña\n"
            "y baja la Precisión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MirrorShot,
    },

    [MOVE_FLASH_CANNON] =
    {
        .name = COMPOUND_STRING("CAÑÓN RESPLANDOR"),
        .description = COMPOUND_STRING(
            "Estallido de luz. Puede bajar\n"
            "la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlashCannon,
    },

    [MOVE_ROCK_CLIMB] =
    {
        .name = COMPOUND_STRING("TREPARROCAS"),
        .description = COMPOUND_STRING(
            "Embestida que puede\n"
            "confundir al rival."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockClimb,
    },

    [MOVE_DEFOG] =
    {
        .name = COMPOUND_STRING("DESPEJAR"),
        .description = COMPOUND_STRING(
            "Despeja obstáculos y baja la\n"
            "Evasión."),
        .effect = EFFECT_DEFOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        //.ignoresSubstitute = TRUE, In Gen5+, the evasion drop will no longer bypass Substitute. However, this is tricky to code
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Defog,
    },

    [MOVE_TRICK_ROOM] =
    {
        .name = COMPOUND_STRING("ESPACIO RARO"),
        .description = COMPOUND_STRING(
            "Los Pokémon más lentos\n"
            "atacan primero 5 turnos."),
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrickRoom,
    },

    [MOVE_DRACO_METEOR] =
    {
        .name = COMPOUND_STRING("COMETA DRACO"),
        .description = COMPOUND_STRING(
            "Lanza cometas. Baja mucho su\n"
            "At. Esp."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DracoMeteor,
    },

    [MOVE_DISCHARGE] =
    {
        .name = COMPOUND_STRING("CHISPAZO"),
        .description = COMPOUND_STRING(
            "Electrocuta a los demás\n"
            "Pokémon. Puede paralizar."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Discharge,
    },

    [MOVE_LAVA_PLUME] =
    {
        .name = COMPOUND_STRING("HUMAREDA"),
        .description = sLavaPlumeDescription,
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_LavaPlume,
    },

    [MOVE_LEAF_STORM] =
    {
        .name = COMPOUND_STRING("LLUEVEHOJAS"),
        .description = COMPOUND_STRING(
            "Tormenta de hojas. Baja\n"
            "mucho su At. Esp."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafStorm,
    },

    [MOVE_POWER_WHIP] =
    {
        .name = COMPOUND_STRING("LATIGAZO"),
        .description = COMPOUND_STRING(
            "Azota con lianas o\n"
            "tentáculos."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_PowerWhip,
    },

    [MOVE_ROCK_WRECKER] =
    {
        .name = COMPOUND_STRING("ROMPERROCAS"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockWrecker,
    },

    [MOVE_CROSS_POISON] =
    {
        .name = COMPOUND_STRING("VENENO X"),
        .description = COMPOUND_STRING(
            "Tajo que puede envenenar.\n"
            "Suele ser crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_POISON,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CrossPoison,
    },

    [MOVE_GUNK_SHOT] =
    {
        .name = COMPOUND_STRING("LANZAMUGRE"),
        .description = COMPOUND_STRING(
            "Lanza basura al rival. Puede\n"
            "envenenar."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GunkShot,
    },

    [MOVE_IRON_HEAD] =
    {
        .name = COMPOUND_STRING("CABEZA DE HIERRO"),
        .description = COMPOUND_STRING(
            "Golpe con la cabeza dura.\n"
            "Puede hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronHead,
    },

    [MOVE_MAGNET_BOMB] =
    {
        .name = COMPOUND_STRING("BOMBA IMÁN"),
        .description = COMPOUND_STRING(
            "Lanza un imán que nunca\n"
            "falla."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagnetBomb,
    },

    [MOVE_STONE_EDGE] =
    {
        .name = COMPOUND_STRING("ROCA AFILADA"),
        .description = COMPOUND_STRING(
            "Clava piedras al rival. Suele\n"
            "ser crítico."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_StoneEdge,
    },

    [MOVE_CAPTIVATE] =
    {
        .name = COMPOUND_STRING("SEDUCCIÓN"),
        .description = COMPOUND_STRING(
            "Baja mucho el At. Esp. del\n"
            "sexo opuesto."),
        .effect = EFFECT_CAPTIVATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Captivate,
    },

    [MOVE_STEALTH_ROCK] =
    {
        .name = COMPOUND_STRING("TRAMPA ROCAS"),
        .description = COMPOUND_STRING(
            "Coloca piedras flotantes que\n"
            "dañan a quien entra."),
        .effect = EFFECT_STEALTH_ROCK,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .forcePressure = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK},
        .battleAnimScript = gBattleAnimMove_StealthRock,
    },

    [MOVE_GRASS_KNOT] =
    {
        .name = COMPOUND_STRING("HIERBA LAZO"),
        .description = COMPOUND_STRING(
            "Lazo que hace más daño a\n"
            "rivales más pesados."),
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassKnot,
    },

    [MOVE_CHATTER] =
    {
        .name = COMPOUND_STRING("CHÁCHARA"),
        .description = COMPOUND_STRING(
            "Onda sonora que causa\n"
            "confusión."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_6,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .chance = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .chance = 10,
        #else
            .chance = 31,
        #endif
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Chatter,
    },

    [MOVE_JUDGMENT] =
    {
        .name = COMPOUND_STRING("SENTENCIA"),
        .description = COMPOUND_STRING(
            "El tipo varía según la tabla\n"
            "que lleve."),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .holdEffect = HOLD_EFFECT_PLATE },
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Judgment,
    },

    [MOVE_BUG_BITE] =
    {
        .name = COMPOUND_STRING("PICADURA"),
        .description = sPluckDescription,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BUG_BITE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BugBite,
    },

    [MOVE_CHARGE_BEAM] =
    {
        .name = COMPOUND_STRING("RAYO CARGA"),
        .description = COMPOUND_STRING(
            "Rayo eléctrico. Puede subir\n"
            "el At. Esp."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 70,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ChargeBeam,
    },

    [MOVE_WOOD_HAMMER] =
    {
        .name = COMPOUND_STRING("MAZAZO"),
        .description = COMPOUND_STRING(
            "Golpea con el cuerpo. El\n"
            "usuario también sufre daño."),
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WoodHammer,
    },

    [MOVE_AQUA_JET] =
    {
        .name = COMPOUND_STRING("ACUA JET"),
        .description = COMPOUND_STRING(
            "Embiste a gran velocidad y\n"
            "golpea primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_AquaJet,
    },

    [MOVE_ATTACK_ORDER] =
    {
        .name = COMPOUND_STRING("AL ATAQUE"),
        .description = COMPOUND_STRING(
            "Sus subordinados atacan.\n"
            "Suele ser crítico."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_ATTACK_ORDER,
        .contestComboMoves = {COMBO_STARTER_DEFEND_ORDER, COMBO_STARTER_HEAL_ORDER},
        .battleAnimScript = gBattleAnimMove_AttackOrder,
    },

    [MOVE_DEFEND_ORDER] =
    {
        .name = COMPOUND_STRING("A DEFENDER"),
        .description = COMPOUND_STRING(
            "Escudo viviente que sube\n"
            "Defensa y Def. Esp."),
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_DEFEND_ORDER,
        .contestComboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_HEAL_ORDER},
        .battleAnimScript = gBattleAnimMove_DefendOrder,
    },

    [MOVE_HEAL_ORDER] =
    {
        .name = COMPOUND_STRING("AUXILIO"),
        .description = COMPOUND_STRING(
            "Sus subordinados le curan la\n"
            "mitad de sus PS."),
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HEAL_ORDER,
        .contestComboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_DEFEND_ORDER},
        .battleAnimScript = gBattleAnimMove_HealOrder,
    },

    [MOVE_HEAD_SMASH] =
    {
        .name = COMPOUND_STRING("TESTARAZO"),
        .description = COMPOUND_STRING(
            "Cabezazo temerario que daña\n"
            "mucho al usuario."),
        .effect = EFFECT_RECOIL,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 50 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadSmash,
    },

    [MOVE_DOUBLE_HIT] =
    {
        .name = COMPOUND_STRING("DOBLE GOLPE"),
        .description = COMPOUND_STRING(
            "Golpea con la cola, etc. Ataca\n"
            "dos veces."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleHit,
    },

    [MOVE_ROAR_OF_TIME] =
    {
        .name = COMPOUND_STRING("DISTORSIÓN"),
        .description = COMPOUND_STRING(
            "Es eficaz, pero deja inmóvil\n"
            "al atacante 1 turno."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RoarOfTime,
    },

    [MOVE_SPACIAL_REND] =
    {
        .name = COMPOUND_STRING("CORTE VACÍO"),
        .description = COMPOUND_STRING(
            "Desgarra al rival y el\n"
            "espacio. Suele ser crítico."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpacialRend,
    },

    [MOVE_LUNAR_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA LUNAR"),
        .description = sHealingWishDescription,
        .effect = EFFECT_LUNAR_DANCE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LunarDance,
    },

    [MOVE_CRUSH_GRIP] =
    {
        .name = COMPOUND_STRING("AGARRÓN"),
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CrushGrip,
    },

    [MOVE_MAGMA_STORM] =
    {
        .name = COMPOUND_STRING("LLUVIA ÍGNEA"),
        .description = COMPOUND_STRING(
            "Atrapa al rival en fuego\n"
            "durante 4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 120,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_MAGMA_STORM,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_MagmaStorm,
    },

    [MOVE_DARK_VOID] =
    {
        .name = COMPOUND_STRING("BRECHA NEGRA"),
        .description = COMPOUND_STRING(
            "Sume a los rivales en la\n"
            "oscuridad y los duerme."),
        .effect = EFFECT_DARK_VOID,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 50 : 80,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_DARK_VOID,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkVoid,
    },

    [MOVE_SEED_FLARE] =
    {
        .name = COMPOUND_STRING("FULGOR SEMILLA"),
        .description = COMPOUND_STRING(
            "Onda de choque que baja\n"
            "mucho la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SeedFlare,
    },

    [MOVE_OMINOUS_WIND] =
    {
        .name = COMPOUND_STRING("VIENTO ACIAGO"),
        .description = COMPOUND_STRING(
            "Ataque repulsivo que puede\n"
            "subir todas las caract."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OminousWind,
    },

    [MOVE_SHADOW_FORCE] =
    {
        .name = COMPOUND_STRING("GOLPE UMBRÍO"),
        .description = sShadowForceDescription,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS == GEN_6,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId = STRINGID_VANISHEDINSTANTLY, .status = STATE_PHANTOM_FORCE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowForce,
    },

    [MOVE_HONE_CLAWS] =
    {
        .name = COMPOUND_STRING("AFILAGARRAS"),
        .description = COMPOUND_STRING(
            "Afila sus garras: sube Ataque\n"
            "y Precisión."),
        .effect = EFFECT_ATTACK_ACCURACY_UP,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_HONE_CLAWS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoneClaws,
    },

    [MOVE_WIDE_GUARD] =
    {
        .name = COMPOUND_STRING("VASTA GUARDIA"),
        .description = COMPOUND_STRING(
            "Evita ataques de área\n"
            "durante un turno."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_WIDE_GUARD },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WideGuard,
    },

    [MOVE_GUARD_SPLIT] =
    {
        .name = COMPOUND_STRING("ISOGUARDIA"),
        .description = COMPOUND_STRING(
            "Promedia con el rival su\n"
            "Defensa y Def. Esp."),
        .effect = EFFECT_GUARD_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GuardSplit,
    },

    [MOVE_POWER_SPLIT] =
    {
        .name = COMPOUND_STRING("ISOFUERZA"),
        .description = COMPOUND_STRING(
            "Promedia con el rival su\n"
            "Ataque y At. Esp."),
        .effect = EFFECT_POWER_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerSplit,
    },

    [MOVE_WONDER_ROOM] =
    {
        .name = COMPOUND_STRING("ZONA EXTRAÑA"),
        .description = COMPOUND_STRING(
            "Intercambia Defensa y\n"
            "Def. Esp. durante 5 turnos."),
        .effect = EFFECT_WONDER_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WonderRoom,
    },

    [MOVE_PSYSHOCK] =
    {
        .name = COMPOUND_STRING("PSICOCARGA"),
        .description = sPsyshockDescription,
        .effect = EFFECT_PSYSHOCK,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Psyshock,
    },

    [MOVE_VENOSHOCK] =
    {
        .name = COMPOUND_STRING("CARGA TÓXICA"),
        .description = COMPOUND_STRING(
            "Doble daño si el rival está\n"
            "envenenado."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_PSN_ANY },
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Venoshock,
    },

    [MOVE_AUTOTOMIZE] =
    {
        .name = COMPOUND_STRING("ALIGERAR"),
        .description = COMPOUND_STRING(
            "Se aligera y sube mucho la\n"
            "Velocidad."),
        .effect = EFFECT_AUTOTOMIZE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Autotomize,
    },

    [MOVE_RAGE_POWDER] =
    {
        .name = COMPOUND_STRING("POLVO IRA"),
        .description = COMPOUND_STRING(
            "Esparce polvo: los rivales\n"
            "solo le atacan a él."),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .powderMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RagePowder,
    },

    [MOVE_TELEKINESIS] =
    {
        .name = COMPOUND_STRING("TELEQUINESIS"),
        .description = COMPOUND_STRING(
            "Hace flotar al rival. Es más\n"
            "fácil darle 3 turnos."),
        .effect = EFFECT_TELEKINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Telekinesis,
    },

    [MOVE_MAGIC_ROOM] =
    {
        .name = COMPOUND_STRING("ZONA MÁGICA"),
        .description = COMPOUND_STRING(
            "Los objetos pierden su\n"
            "efecto durante 5 turnos."),
        .effect = EFFECT_MAGIC_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicRoom,
    },

    [MOVE_SMACK_DOWN] =
    {
        .name = COMPOUND_STRING("ANTIAÉREO"),
        .description = COMPOUND_STRING(
            "Lanza una roca que derriba al\n"
            "rival al suelo."),
        .effect = EFFECT_SMACK_DOWN,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesAirborne = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SmackDown,
    },

    [MOVE_STORM_THROW] =
    {
        .name = COMPOUND_STRING("LLAVE CORSÉ"),
        .description = sStormThrowDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_StormThrow,
    },

    [MOVE_FLAME_BURST] =
    {
        .name = COMPOUND_STRING("PIROTECNIA"),
        .description = COMPOUND_STRING(
            "Llamarada que daña a todos\n"
            "los rivales."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLAME_BURST,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlameBurst,
    },

    [MOVE_SLUDGE_WAVE] =
    {
        .name = COMPOUND_STRING("ONDA TÓXICA"),
        .description = COMPOUND_STRING(
            "Ola de lodo contra todos.\n"
            "Puede envenenar."),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SludgeWave,
    },

    [MOVE_QUIVER_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA ALETEO"),
        .description = COMPOUND_STRING(
            "Danza que sube At. Esp.,\n"
            "Def. Esp. y Velocidad."),
        .effect = EFFECT_QUIVER_DANCE,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_QuiverDance,
    },

    [MOVE_HEAVY_SLAM] =
    {
        .name = COMPOUND_STRING("CUERPO PESADO"),
        .description = sHeavySlamDescription,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_7,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeavySlam,
    },

    [MOVE_SYNCHRONOISE] =
    {
        .name = COMPOUND_STRING("SINCRORRUIDO"),
        .description = COMPOUND_STRING(
            "Onda extraña que solo daña a\n"
            "los de su tipo."),
        .effect = EFFECT_SYNCHRONOISE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 120 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Synchronoise,
    },

    [MOVE_ELECTRO_BALL] =
    {
        .name = COMPOUND_STRING("BOLA VOLTIO"),
        .description = COMPOUND_STRING(
            "Lanza una esfera; más daño a\n"
            "rivales lentos."),
        .effect = EFFECT_ELECTRO_BALL,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AGILITY, COMBO_STARTER_CHARGE, COMBO_STARTER_ROCK_POLISH},
        .battleAnimScript = gBattleAnimMove_ElectroBall,
    },

    [MOVE_SOAK] =
    {
        .name = COMPOUND_STRING("EMPAPAR"),
        .description = COMPOUND_STRING(
            "Rocía agua y convierte al\n"
            "rival en tipo Agua."),
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_WATER },
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Soak,
    },

    [MOVE_FLAME_CHARGE] =
    {
        .name = COMPOUND_STRING("NITROCARGA"),
        .description = COMPOUND_STRING(
            "Ataca envuelto en llamas.\n"
            "Sube la Velocidad."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlameCharge,
    },

    [MOVE_COIL] =
    {
        .name = COMPOUND_STRING("ENROSQUE"),
        .description = COMPOUND_STRING(
            "Se enrosca: sube Ataque,\n"
            "Defensa y Precisión."),
        .effect = EFFECT_COIL,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Coil,
    },

    [MOVE_LOW_SWEEP] =
    {
        .name = COMPOUND_STRING("PUNTAPIÉ"),
        .description = COMPOUND_STRING(
            "Ataca las piernas y baja la\n"
            "Velocidad rival."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LowSweep,
    },

    [MOVE_ACID_SPRAY] =
    {
        .name = COMPOUND_STRING("BOMBA ÁCIDA"),
        .description = COMPOUND_STRING(
            "Ácido corrosivo que baja\n"
            "mucho la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AcidSpray,
    },

    [MOVE_FOUL_PLAY] =
    {
        .name = COMPOUND_STRING("JUEGO SUCIO"),
        .description = COMPOUND_STRING(
            "Cuanto mayor sea el Ataque\n"
            "rival, más daño."),
        .effect = EFFECT_FOUL_PLAY,
        .power = 95,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FoulPlay,
    },

    [MOVE_SIMPLE_BEAM] =
    {
        .name = COMPOUND_STRING("ONDA SIMPLE"),
        .description = COMPOUND_STRING(
            "Rayo que cambia la habilidad\n"
            "rival a Simple."),
        .effect = EFFECT_OVERWRITE_ABILITY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .overwriteAbility = ABILITY_SIMPLE },
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SimpleBeam,
    },

    [MOVE_ENTRAINMENT] =
    {
        .name = COMPOUND_STRING("DANZA AMIGA"),
        .description = COMPOUND_STRING(
            "El rival lo imita y obtiene su\n"
            "habilidad."),
        .effect = EFFECT_ENTRAINMENT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_ENTRAINMENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Entrainment,
    },

    [MOVE_AFTER_YOU] =
    {
        .name = COMPOUND_STRING("CEDE PASO"),
        .description = COMPOUND_STRING(
            "Ayuda al objetivo y le deja\n"
            "actuar justo después."),
        .effect = EFFECT_AFTER_YOU,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AfterYou,
    },

    [MOVE_ROUND] =
    {
        .name = COMPOUND_STRING("CANON"),
        .description = COMPOUND_STRING(
            "Canción dañina. Otros pueden\n"
            "unirse a ella."),
        .effect = EFFECT_ROUND,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ROUND,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Round,
    },

    [MOVE_ECHOED_VOICE] =
    {
        .name = COMPOUND_STRING("ECO VOZ"),
        .description = COMPOUND_STRING(
            "Más daño cada turno que se\n"
            "usa."),
        .effect = EFFECT_ECHOED_VOICE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EchoedVoice,
    },

    [MOVE_CHIP_AWAY] =
    {
        .name = COMPOUND_STRING("GUARDIA BAJA"),
        .description = sChipAwayDescription,
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ChipAway,
    },

    [MOVE_CLEAR_SMOG] =
    {
        .name = COMPOUND_STRING("NIEBLA CLARA"),
        .description = COMPOUND_STRING(
            "Niebla blanca que anula los\n"
            "cambios de caract."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CLEAR_SMOG,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClearSmog,
    },

    [MOVE_STORED_POWER] =
    {
        .name = COMPOUND_STRING("PODER RESERVA"),
        .description = COMPOUND_STRING(
            "Cuanto más suba sus caract.,\n"
            "más daño."),
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AMNESIA, COMBO_STARTER_HONE_CLAWS, COMBO_STARTER_CALM_MIND, COMBO_STARTER_NASTY_PLOT},
        .battleAnimScript = gBattleAnimMove_StoredPower,
    },

    [MOVE_QUICK_GUARD] =
    {
        .name = COMPOUND_STRING("ANTICIPO"),
        .description = COMPOUND_STRING(
            "Evita ataques con prioridad\n"
            "durante un turno."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_QUICK_GUARD, },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_QuickGuard,
    },

    [MOVE_ALLY_SWITCH] =
    {
        .name = COMPOUND_STRING("CAMBIO DE BANDA"),
        .description = COMPOUND_STRING(
            "El usuario cambia de sitio con\n"
            "su compañero."),
        .effect = EFFECT_ALLY_SWITCH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_7 ? 2 : 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AllySwitch,
    },

    [MOVE_SCALD] =
    {
        .name = COMPOUND_STRING("ESCALDAR"),
        .description = COMPOUND_STRING(
            "Agua hirviendo contra el\n"
            "rival. Puede quemar."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCALD,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Scald,
    },

    [MOVE_SHELL_SMASH] =
    {
        .name = COMPOUND_STRING("ROMPECORAZA"),
        .description = COMPOUND_STRING(
            "Sube mucho Ataque, At. Esp. y\n"
            "Velocidad; baja defensas."),
        .effect = EFFECT_SHELL_SMASH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellSmash,
    },

    [MOVE_HEAL_PULSE] =
    {
        .name = COMPOUND_STRING("PULSO CURA"),
        .description = COMPOUND_STRING(
            "Recupera hasta la mitad de\n"
            "los PS del objetivo."),
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealPulse,
    },

    [MOVE_HEX] =
    {
        .name = COMPOUND_STRING("INFORTUNIO"),
        .description = COMPOUND_STRING(
            "Doble daño si el rival tiene\n"
            "un problema de estado."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 160 },
        .argument = { .status = STATUS1_ANY },
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_FORCE_PALM, COMBO_STARTER_THUNDER_WAVE, COMBO_STARTER_INFERNO, COMBO_STARTER_WILL_O_WISP, COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES, COMBO_STARTER_GLARE},
        .battleAnimScript = gBattleAnimMove_Hex,
    },

    [MOVE_SKY_DROP] =
    {
        .name = COMPOUND_STRING("CAÍDA LIBRE"),
        .description = COMPOUND_STRING(
            "Sube al rival al cielo y lo\n"
            "suelta al turno siguiente."),
        .effect = EFFECT_SKY_DROP,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNTOOKTARGETHIGH, .status = STATE_ON_AIR },
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SkyDrop,
    },

    [MOVE_SHIFT_GEAR] =
    {
        .name = COMPOUND_STRING("CAMBIO DE MARCHA"),
        .description = COMPOUND_STRING(
            "Gira sus engranajes: sube\n"
            "Ataque y Velocidad."),
        .effect = EFFECT_SHIFT_GEAR,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SHIFT_GEAR,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShiftGear,
    },

    [MOVE_CIRCLE_THROW] =
    {
        .name = COMPOUND_STRING("LLAVE GIRO"),
        .description = sCircleThrowDescription,
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_CircleThrow,
    },

    [MOVE_INCINERATE] =
    {
        .name = COMPOUND_STRING("CALCINACIÓN"),
        .description = COMPOUND_STRING(
            "Quema Bayas y Gemas para que\n"
            "no se usen."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 30,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_INCINERATE,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Incinerate,
    },

    [MOVE_QUASH] =
    {
        .name = COMPOUND_STRING("ÚLTIMO LUGAR"),
        .description = COMPOUND_STRING(
            "Somete al rival y le hace\n"
            "actuar el último."),
        .effect = EFFECT_QUASH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Quash,
    },

    [MOVE_ACROBATICS] =
    {
        .name = COMPOUND_STRING("ACRÓBATA"),
        .description = COMPOUND_STRING(
            "Doble daño si el usuario no\n"
            "lleva objeto."),
        .effect = EFFECT_ACROBATICS,
        .power = 55,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acrobatics,
    },

    [MOVE_REFLECT_TYPE] =
    {
        .name = COMPOUND_STRING("CLONATIPO"),
        .description = COMPOUND_STRING(
            "El usuario refleja y copia el\n"
            "tipo del rival."),
        .effect = EFFECT_REFLECT_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ReflectType,
    },

    [MOVE_RETALIATE] =
    {
        .name = COMPOUND_STRING("REPRESALIA"),
        .description = COMPOUND_STRING(
            "Más daño si un aliado se\n"
            "debilitó."),
        .effect = EFFECT_RETALIATE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Retaliate,
    },

    [MOVE_FINAL_GAMBIT] =
    {
        .name = COMPOUND_STRING("SACRIFICIO"),
        .description = COMPOUND_STRING(
            "Se debilita y causa tanto\n"
            "daño como sus PS."),
        .effect = EFFECT_FINAL_GAMBIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .explosion = B_UPDATED_MOVE_FLAGS <= GEN_5,
        .mirrorMoveBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FinalGambit,
    },

    [MOVE_BESTOW] =
    {
        .name = COMPOUND_STRING("OFRENDA"),
        .description = COMPOUND_STRING(
            "El usuario entrega su objeto\n"
            "al rival."),
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Bestow,
    },

    [MOVE_INFERNO] =
    {
        .name = COMPOUND_STRING("INFIERNO"),
        .description = COMPOUND_STRING(
            "Potente y siempre quema,\n"
            "pero poco preciso."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_INFERNO,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Inferno,
    },

    [MOVE_WATER_PLEDGE] =
    {
        .name = COMPOUND_STRING("VOTO AGUA"),
        .description = COMPOUND_STRING(
            "Columna de agua. Puede\n"
            "formar un arcoíris."),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaterPledge,
    },

    [MOVE_FIRE_PLEDGE] =
    {
        .name = COMPOUND_STRING("VOTO FUEGO"),
        .description = COMPOUND_STRING(
            "Columna de fuego. Puede\n"
            "quemar la hierba."),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FirePledge,
    },

    [MOVE_GRASS_PLEDGE] =
    {
        .name = COMPOUND_STRING("VOTO PLANTA"),
        .description = COMPOUND_STRING(
            "Columna de plantas. Puede\n"
            "crear un pantano."),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassPledge,
    },

    [MOVE_VOLT_SWITCH] =
    {
        .name = COMPOUND_STRING("VOLTIOCAMBIO"),
        .description = sUTurnDescription,
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_VoltSwitch,
    },

    [MOVE_STRUGGLE_BUG] =
    {
        .name = COMPOUND_STRING("ESTOICISMO"),
        .description = COMPOUND_STRING(
            "Ataca resistiéndose. Baja el\n"
            "At. Esp. rival."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 30,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StruggleBug,
    },

    [MOVE_BULLDOZE] =
    {
        .name = COMPOUND_STRING("TERRATEMBLOR"),
        .description = COMPOUND_STRING(
            "Pisotea el suelo. Golpea a\n"
            "todos y baja Velocidad."),
        .effect = EFFECT_EARTHQUAKE,
        .power = 60,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bulldoze,
    },

    [MOVE_FROST_BREATH] =
    {
        .name = COMPOUND_STRING("VAHO GÉLIDO"),
        .description = sStormThrowDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .alwaysCriticalHit = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FrostBreath,
    },

    [MOVE_DRAGON_TAIL] =
    {
        .name = COMPOUND_STRING("COLA DRAGÓN"),
        .description = sCircleThrowDescription,
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_DRAGON_TAIL,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_DragonTail,
    },

    [MOVE_WORK_UP] =
    {
        .name = COMPOUND_STRING("AVIVAR"),
        .description = COMPOUND_STRING(
            "Se motiva. Sube Ataque y\n"
            "At. Esp."),
        .effect = EFFECT_ATTACK_SPATK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WorkUp,
    },

    [MOVE_ELECTROWEB] =
    {
        .name = COMPOUND_STRING("ELECTROTELA"),
        .description = COMPOUND_STRING(
            "Red eléctrica que atrapa y\n"
            "baja la Velocidad."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_Electroweb,
    },

    [MOVE_WILD_CHARGE] =
    {
        .name = COMPOUND_STRING("VOLTIO CRUEL"),
        .description = COMPOUND_STRING(
            "Placaje eléctrico que\n"
            "también daña al usuario."),
        .effect = EFFECT_RECOIL,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WildCharge,
    },

    [MOVE_DRILL_RUN] =
    {
        .name = COMPOUND_STRING("TALADRADORA"),
        .description = COMPOUND_STRING(
            "Gira como un taladro. Suele\n"
            "ser crítico."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_DrillRun,
    },

    [MOVE_DUAL_CHOP] =
    {
        .name = COMPOUND_STRING("GOLPE BIS"),
        .description = COMPOUND_STRING(
            "Golpes brutales que impactan\n"
            "dos veces."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DualChop,
    },

    [MOVE_HEART_STAMP] =
    {
        .name = COMPOUND_STRING("ARRUMACO"),
        .description = COMPOUND_STRING(
            "Golpe tras un gesto tierno.\n"
            "Puede hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeartStamp,
    },

    [MOVE_HORN_LEECH] =
    {
        .name = COMPOUND_STRING("ASTA DRENAJE"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HornLeech,
    },

    [MOVE_SACRED_SWORD] =
    {
        .name = COMPOUND_STRING("ESPADA SANTA"),
        .description = sChipAwayDescription,
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SacredSword,
    },

    [MOVE_RAZOR_SHELL] =
    {
        .name = COMPOUND_STRING("CONCHA FILO"),
        .description = COMPOUND_STRING(
            "Rasga con conchas afiladas.\n"
            "Puede bajar la Defensa."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RazorShell,
    },

    [MOVE_HEAT_CRASH] =
    {
        .name = COMPOUND_STRING("GOLPE CALOR"),
        .description = sHeavySlamDescription,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeatCrash,
    },

    [MOVE_LEAF_TORNADO] =
    {
        .name = COMPOUND_STRING("CICLÓN DE HOJAS"),
        .description = COMPOUND_STRING(
            "Rodea al rival de hojas: daña\n"
            "y baja la Precisión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafTornado,
    },

    [MOVE_STEAMROLLER] =
    {
        .name = COMPOUND_STRING("RODILLO DE PÚAS"),
        .description = COMPOUND_STRING(
            "Aplasta con el cuerpo. Puede\n"
            "hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Steamroller,
    },

    [MOVE_COTTON_GUARD] =
    {
        .name = COMPOUND_STRING("RIZO ALGODÓN"),
        .description = COMPOUND_STRING(
            "Se envuelve en algodón. Sube\n"
            "muchísimo la Defensa."),
        .effect = EFFECT_DEFENSE_UP_3,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CottonGuard,
    },

    [MOVE_NIGHT_DAZE] =
    {
        .name = COMPOUND_STRING("PULSO NOCHE"),
        .description = COMPOUND_STRING(
            "Onda negra como la noche.\n"
            "Puede bajar la Precisión."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NightDaze,
    },

    [MOVE_PSYSTRIKE] =
    {
        .name = COMPOUND_STRING("ONDA MENTAL"),
        .description = sPsyshockDescription,
        .effect = EFFECT_PSYSHOCK,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Psystrike,
    },

    [MOVE_TAIL_SLAP] =
    {
        .name = COMPOUND_STRING("PLUMERAZO"),
        .description = COMPOUND_STRING(
            "Golpea con la cola de 2 a 5\n"
            "veces."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TailSlap,
    },

    [MOVE_HURRICANE] =
    {
        .name = COMPOUND_STRING("VENDAVAL"),
        .description = COMPOUND_STRING(
            "Atrapa en un viento feroz.\n"
            "Puede confundir."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_FLYING,
        .accuracy = 70,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .damagesAirborne = TRUE,
        .alwaysHitsInRain = TRUE,
        .accuracy50InSun = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Hurricane,
    },

    [MOVE_HEAD_CHARGE] =
    {
        .name = COMPOUND_STRING("ARIETE"),
        .description = COMPOUND_STRING(
            "Carga con el pelaje. El\n"
            "usuario sufre algo de daño."),
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadCharge,
    },

    [MOVE_GEAR_GRIND] =
    {
        .name = COMPOUND_STRING("RUEDA DOBLE"),
        .description = COMPOUND_STRING(
            "Lanza dos engranajes de\n"
            "acero. Golpea dos veces."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 180 },
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SHIFT_GEAR},
        .battleAnimScript = gBattleAnimMove_GearGrind,
    },

    [MOVE_SEARING_SHOT] =
    {
        .name = COMPOUND_STRING("BOMBA ÍGNEA"),
        .description = sLavaPlumeDescription,
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SearingShot,
    },

    [MOVE_TECHNO_BLAST] =
    {
        .name = COMPOUND_STRING("TECNO SHOCK"),
        .description = COMPOUND_STRING(
            "El tipo varía según el disco\n"
            "que lleve."),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 120 : 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .holdEffect = HOLD_EFFECT_DRIVE },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TechnoBlast,
    },

    [MOVE_RELIC_SONG] =
    {
        .name = COMPOUND_STRING("CANTO ARCAICO"),
        .description = COMPOUND_STRING(
            "Canción ancestral. Puede\n"
            "dormir al rival."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_SLEEP },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RelicSong,
    },

    [MOVE_SECRET_SWORD] =
    {
        .name = COMPOUND_STRING("SABLE MÍSTICO"),
        .description = COMPOUND_STRING(
            "Corta con un cuerno largo.\n"
            "Causa daño físico."),
        .effect = EFFECT_PSYSHOCK,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SecretSword,
    },

    [MOVE_GLACIATE] =
    {
        .name = COMPOUND_STRING("MUNDO GÉLIDO"),
        .description = COMPOUND_STRING(
            "Aire gélido contra los\n"
            "rivales. Baja su Velocidad."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_Glaciate,
    },

    [MOVE_BOLT_STRIKE] =
    {
        .name = COMPOUND_STRING("ATAQUE FULGOR"),
        .description = COMPOUND_STRING(
            "Descarga de rayos. Puede\n"
            "paralizar."),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BoltStrike,
    },

    [MOVE_BLUE_FLARE] =
    {
        .name = COMPOUND_STRING("LLAMA AZUL"),
        .description = COMPOUND_STRING(
            "Llamas azules que envuelven\n"
            "al rival. Puede quemar."),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BlueFlare,
    },

    [MOVE_FIERY_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA LLAMA"),
        .description = COMPOUND_STRING(
            "Danza envuelto en llamas.\n"
            "Puede subir el At. Esp."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .danceMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FieryDance,
    },

    [MOVE_FREEZE_SHOCK] =
    {
        .name = COMPOUND_STRING("RAYO GÉLIDO"),
        .description = COMPOUND_STRING(
            "Potente ataque de 2 turnos.\n"
            "Puede paralizar."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_CLOAKEDINAFREEZINGLIGHT },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezeShock,
    },

    [MOVE_ICE_BURN] =
    {
        .name = COMPOUND_STRING("LLAMA GÉLIDA"),
        .description = COMPOUND_STRING(
            "Potente ataque de 2 turnos.\n"
            "Puede quemar."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_CLOAKEDINAFREEZINGLIGHT },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IceBurn,
    },

    [MOVE_SNARL] =
    {
        .name = COMPOUND_STRING("ALARIDO"),
        .description = COMPOUND_STRING(
            "Grita e increpa al rival. Baja\n"
            "su At. Esp."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Snarl,
    },

    [MOVE_ICICLE_CRASH] =
    {
        .name = COMPOUND_STRING("CHUZOS"),
        .description = COMPOUND_STRING(
            "Deja caer carámbanos. Puede\n"
            "hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IcicleCrash,
    },

    [MOVE_V_CREATE] =
    {
        .name = COMPOUND_STRING("V DE FUEGO"),
        .description = COMPOUND_STRING(
            "Muy potente, pero baja Def.,\n"
            "Def. Esp. y Velocidad."),
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 220 },
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_V_CREATE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VCreate,
    },

    [MOVE_FUSION_FLARE] =
    {
        .name = COMPOUND_STRING("LLAMA FUSIÓN"),
        .description = COMPOUND_STRING(
            "Invoca una bola de fuego.\n"
            "Combina con un rayo."),
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FusionFlare,
    },

    [MOVE_FUSION_BOLT] =
    {
        .name = COMPOUND_STRING("RAYO FUSIÓN"),
        .description = COMPOUND_STRING(
            "Invoca un rayo. Combina con\n"
            "una bola de fuego."),
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FusionBolt,
    },

    [MOVE_FLYING_PRESS] =
    {
        .name = COMPOUND_STRING("PLANCHA VOLADORA"),
        .description = COMPOUND_STRING(
            "Daña con los tipos Lucha y\n"
            "Volador a la vez."),
        .effect = EFFECT_TWO_TYPED_MOVE,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 100 : 80,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 170 },
        .argument = { .type = TYPE_FLYING },
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .gravityBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlyingPress,
    },

    [MOVE_MAT_BLOCK] =
    {
        .name = COMPOUND_STRING("ESCUDO TATAMI"),
        .description = COMPOUND_STRING(
            "Evita ataques dañinos. Solo\n"
            "en el 1.{SUPER_ER} turno."),
        .effect = EFFECT_MAT_BLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_MAT_BLOCK, },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MatBlock,
    },

    [MOVE_BELCH] =
    {
        .name = COMPOUND_STRING("ERUCTO"),
        .description = COMPOUND_STRING(
            "Un eructo enorme. Solo tras\n"
            "comer una Baya."),
        .effect = EFFECT_BELCH,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Belch,
    },

    [MOVE_ROTOTILLER] =
    {
        .name = COMPOUND_STRING("FERTILIZANTE"),
        .description = COMPOUND_STRING(
            "Sube Ataque y At. Esp. de los\n"
            "Pokémon Planta."),
        .effect = EFFECT_ROTOTILLER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROTOTILLER,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Rototiller,
    },

    [MOVE_STICKY_WEB] =
    {
        .name = COMPOUND_STRING("RED VISCOSA"),
        .description = COMPOUND_STRING(
            "Teje una red pegajosa que\n"
            "frena a quien entra."),
        .effect = EFFECT_STICKY_WEB,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_StickyWeb,
    },

    [MOVE_FELL_STINGER] =
    {
        .name = COMPOUND_STRING("AGUIJÓN LETAL"),
        .description = COMPOUND_STRING(
            "Si debilita al rival, sube su\n"
            "Ataque."),
        .effect = EFFECT_FELL_STINGER,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 50 : 30,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FellStinger,
    },

    [MOVE_PHANTOM_FORCE] =
    {
        .name = COMPOUND_STRING("GOLPE FANTASMA"),
        .description = sShadowForceDescription,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_7,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_VANISHEDINSTANTLY, .status = STATE_PHANTOM_FORCE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PhantomForce,
    },

    [MOVE_TRICK_OR_TREAT] =
    {
        .name = COMPOUND_STRING("HALLOWEEN"),
        .description = COMPOUND_STRING(
            "Truco o trato: añade el tipo\n"
            "Fantasma al rival."),
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_GHOST },
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrickOrTreat,
    },

    [MOVE_NOBLE_ROAR] =
    {
        .name = COMPOUND_STRING("RUGIDO DE GUERRA"),
        .description = COMPOUND_STRING(
            "Intimida al rival y baja su\n"
            "Ataque y At. Esp."),
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NobleRoar,
    },

    [MOVE_ION_DELUGE] =
    {
        .name = COMPOUND_STRING("CORTINA PLASMA"),
        .description = COMPOUND_STRING(
            "Átomos cargados: lo Normal\n"
            "pasa a Eléctrico."),
        .effect = EFFECT_ION_DELUGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 25,
        .target = TARGET_FIELD,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IonDeluge,
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
        .name = COMPOUND_STRING("CARGA PARÁBOLA"),
        .description = COMPOUND_STRING(
            "Daña a los Pokémon cercanos\n"
            "y se cura la mitad."),
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 65 : 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PARABOLIC_CHARGE,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ParabolicCharge,
    },

    [MOVE_FORESTS_CURSE] =
    {
        .name = COMPOUND_STRING("CONDENA SILVANA"),
        .description = COMPOUND_STRING(
            "Maldice al rival y le añade el\n"
            "tipo Planta."),
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_GRASS },
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ForestsCurse,
    },

    [MOVE_PETAL_BLIZZARD] =
    {
        .name = COMPOUND_STRING("TORMENTA FLORAL"),
        .description = COMPOUND_STRING(
            "Tormenta violenta de pétalos\n"
            "contra todos."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PetalBlizzard,
    },

    [MOVE_FREEZE_DRY] =
    {
        .name = COMPOUND_STRING("LIOFILIZACIÓN"),
        .description = COMPOUND_STRING(
            "Muy eficaz contra el tipo\n"
            "Agua. Puede congelar."),
        .effect = EFFECT_SUPER_EFFECTIVE_ON_ARG,
        .power = 70,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .type = TYPE_WATER },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezeDry,
    },

    [MOVE_DISARMING_VOICE] =
    {
        .name = COMPOUND_STRING("VOZ CAUTIVADORA"),
        .description = COMPOUND_STRING(
            "Grito encantador que no se\n"
            "puede esquivar."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DisarmingVoice,
    },

    [MOVE_PARTING_SHOT] =
    {
        .name = COMPOUND_STRING("ÚLTIMA PALABRA"),
        .description = COMPOUND_STRING(
            "Baja Ataque y At. Esp. del\n"
            "rival y se retira."),
        .effect = EFFECT_PARTING_SHOT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESTORE_REPLACEMENT_HP },
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PartingShot,
    },

    [MOVE_TOPSY_TURVY] =
    {
        .name = COMPOUND_STRING("REVERSIÓN"),
        .description = COMPOUND_STRING(
            "Invierte los cambios de\n"
            "caract. del objetivo."),
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TopsyTurvy,
    },

    [MOVE_DRAINING_KISS] =
    {
        .name = COMPOUND_STRING("BESO DRENAJE"),
        .description = sDrainingKissDescription,
        .effect = EFFECT_ABSORB,
        .power = 50,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 75 },
        .makesContact = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DrainingKiss,
    },

    [MOVE_CRAFTY_SHIELD] =
    {
        .name = COMPOUND_STRING("TRUCO DEFENSA"),
        .description = COMPOUND_STRING(
            "Evita ataques de estado\n"
            "durante un turno."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_CRAFTY_SHIELD },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CraftyShield,
    },

    [MOVE_FLOWER_SHIELD] =
    {
        .name = COMPOUND_STRING("DEFENSA FLORAL"),
        .description = COMPOUND_STRING(
            "Sube la Defensa de los\n"
            "Pokémon de tipo Planta."),
        .effect = EFFECT_FLOWER_SHIELD,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlowerShield,
    },

    [MOVE_GRASSY_TERRAIN] =
    {
        .name = COMPOUND_STRING("CAMPO DE HIERBA"),
        .description = COMPOUND_STRING(
            "Campo de hierba 5 turnos.\n"
            "Recupera PS."),
        .effect = EFFECT_GRASSY_TERRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_GRASSY_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassyTerrain,
    },

    [MOVE_MISTY_TERRAIN] =
    {
        .name = COMPOUND_STRING("CAMPO DE NIEBLA"),
        .description = COMPOUND_STRING(
            "Campo de niebla 5 turnos.\n"
            "Evita estados."),
        .effect = EFFECT_MISTY_TERRAIN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_MISTY_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MistyTerrain,
    },

    [MOVE_ELECTRIFY] =
    {
        .name = COMPOUND_STRING("ELECTRIFICACIÓN"),
        .description = COMPOUND_STRING(
            "Electrifica al rival: su\n"
            "próximo ataque es Eléctrico."),
        .effect = EFFECT_ELECTRIFY,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PARABOLIC_CHARGE},
        .battleAnimScript = gBattleAnimMove_Electrify,
    },

    [MOVE_PLAY_ROUGH] =
    {
        .name = COMPOUND_STRING("CARANTOÑA"),
        .description = COMPOUND_STRING(
            "Juega duro con el rival. Puede\n"
            "bajar su Ataque."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PlayRough,
    },

    [MOVE_FAIRY_WIND] =
    {
        .name = COMPOUND_STRING("VIENTO FEÉRICO"),
        .description = COMPOUND_STRING(
            "Desata un viento feérico\n"
            "contra el rival."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FairyWind,
    },

    [MOVE_MOONBLAST] =
    {
        .name = COMPOUND_STRING("FUERZA LUNAR"),
        .description = COMPOUND_STRING(
            "Ataca con el poder lunar.\n"
            "Puede bajar el At. Esp."),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Moonblast,
    },

    [MOVE_BOOMBURST] =
    {
        .name = COMPOUND_STRING("ESTRUENDO"),
        .description = COMPOUND_STRING(
            "Onda sonora destructiva\n"
            "contra todos."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Boomburst,
    },

    [MOVE_FAIRY_LOCK] =
    {
        .name = COMPOUND_STRING("CERROJO FEÉRICO"),
        .description = COMPOUND_STRING(
            "Bloquea el campo: nadie huye\n"
            "el turno siguiente."),
        .effect = EFFECT_FAIRY_LOCK,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FairyLock,
    },

    [MOVE_KINGS_SHIELD] =
    {
        .name = COMPOUND_STRING("ESCUDO REAL"),
        .description = COMPOUND_STRING(
            "Evita daños y baja mucho el\n"
            "Ataque de quien le toque."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_KINGS_SHIELD },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_KingsShield,
    },

    [MOVE_PLAY_NICE] =
    {
        .name = COMPOUND_STRING("CAMARADERÍA"),
        .description = COMPOUND_STRING(
            "Se hace amigo del rival y baja\n"
            "su Ataque sin fallar."),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_PLAY_NICE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PlayNice,
    },

    [MOVE_CONFIDE] =
    {
        .name = COMPOUND_STRING("CONFIDENCIA"),
        .description = COMPOUND_STRING(
            "Cuenta un secreto al rival y\n"
            "baja su At. Esp."),
        .effect = EFFECT_SPECIAL_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Confide,
    },

    [MOVE_DIAMOND_STORM] =
    {
        .name = COMPOUND_STRING("TORM. DIAMANTES"),
        .description = COMPOUND_STRING(
            "Tormenta de diamantes. Puede\n"
            "subir la Defensa."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = B_UPDATED_MOVE_DATA >= GEN_7 ? MOVE_EFFECT_DEF_PLUS_2:  MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DiamondStorm,
    },

    [MOVE_STEAM_ERUPTION] =
    {
        .name = COMPOUND_STRING("CHORRO DE VAPOR"),
        .description = COMPOUND_STRING(
            "Sumerge al rival en vapor\n"
            "ardiente. Puede quemar."),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCALD},
        .battleAnimScript = gBattleAnimMove_SteamEruption,
    },

    [MOVE_HYPERSPACE_HOLE] =
    {
        .name = COMPOUND_STRING("PASO DIMENSIONAL"),
        .description = sHyperspaceHoleDescription,
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HYPERSPACE_HOLE,
        .contestComboMoves = {COMBO_STARTER_HYPERSPACE_FURY},
        .battleAnimScript = gBattleAnimMove_HyperspaceHole,
    },

    [MOVE_WATER_SHURIKEN] =
    {
        .name = COMPOUND_STRING("SHURIKEN DE AGUA"),
        .description = COMPOUND_STRING(
            "Lanza de 2 a 5 estrellas.\n"
            "Siempre va primero."),
        .effect = EFFECT_SPECIES_POWER_OVERRIDE,
        .power = 15,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = B_UPDATED_MOVE_DATA >= GEN_7 ? DAMAGE_CATEGORY_SPECIAL : DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .speciesPowerOverride.species = SPECIES_GRENINJA_ASH,
            .speciesPowerOverride.power = 20,
            .speciesPowerOverride.numOfHits = 3
        },
        .multiHit = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaterShuriken,
    },

    [MOVE_MYSTICAL_FIRE] =
    {
        .name = COMPOUND_STRING("LLAMA EMBRUJADA"),
        .description = COMPOUND_STRING(
            "Aliento de fuego especial.\n"
            "Baja el At. Esp."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 75 : 65,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MysticalFire,
    },

    [MOVE_SPIKY_SHIELD] =
    {
        .name = COMPOUND_STRING("BARRERA ESPINOSA"),
        .description = COMPOUND_STRING(
            "Evita ataques y daña a quien\n"
            "le golpee."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_SPIKY_SHIELD },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpikyShield,
    },

    [MOVE_AROMATIC_MIST] =
    {
        .name = COMPOUND_STRING("NIEBLA AROMÁTICA"),
        .description = COMPOUND_STRING(
            "Sube la Def. Esp. de un aliado."),
        .effect = EFFECT_AROMATIC_MIST,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AromaticMist,
    },

    [MOVE_EERIE_IMPULSE] =
    {
        .name = COMPOUND_STRING("ONDA ANÓMALA"),
        .description = COMPOUND_STRING(
            "Pulso que baja mucho el\n"
            "At. Esp. del rival."),
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EerieImpulse,
    },

    [MOVE_VENOM_DRENCH] =
    {
        .name = COMPOUND_STRING("TRAMPA VENENOSA"),
        .description = COMPOUND_STRING(
            "Baja Ataque, At. Esp. y\n"
            "Velocidad a envenenados."),
        .effect = EFFECT_VENOM_DRENCH,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_VenomDrench,
    },

    [MOVE_POWDER] =
    {
        .name = COMPOUND_STRING("POLVO EXPLOSIVO"),
        .description = COMPOUND_STRING(
            "Daña al rival si usa un ataque\n"
            "de tipo Fuego."),
        .effect = EFFECT_POWDER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .powderMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Powder,
    },

    [MOVE_GEOMANCY] =
    {
        .name = COMPOUND_STRING("GEOCONTROL"),
        .description = COMPOUND_STRING(
            "Sube At. Esp., Def. Esp. y\n"
            "Velocidad al 2.º turno."),
        .effect = EFFECT_GEOMANCY,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKNMABSORBINGPOWER },
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Geomancy,
    },

    [MOVE_MAGNETIC_FLUX] =
    {
        .name = COMPOUND_STRING("AURA MAGNÉTICA"),
        .description = COMPOUND_STRING(
            "Sube las defensas de quien\n"
            "tenga Más o Menos."),
        .effect = EFFECT_MAGNETIC_FLUX,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagneticFlux,
    },

    [MOVE_HAPPY_HOUR] =
    {
        .name = COMPOUND_STRING("PAGA EXTRA"),
        .description = COMPOUND_STRING(
            "Duplica el dinero que se gana\n"
            "en el combate."),
        .effect = EFFECT_HAPPY_HOUR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_HAPPY_HOUR,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HappyHour,
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
        .name = COMPOUND_STRING("CAMPO ELÉCTRICO"),
        .description = COMPOUND_STRING(
            "Electrifica el suelo 5 turnos.\n"
            "Impide dormir."),
        .effect = EFFECT_ELECTRIC_TERRAIN,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_ELECTRIC_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ElectricTerrain,
    },

    [MOVE_DAZZLING_GLEAM] =
    {
        .name = COMPOUND_STRING("BRILLO MÁGICO"),
        .description = COMPOUND_STRING(
            "Emite un destello brillante\n"
            "que daña a los rivales."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DazzlingGleam,
    },

    [MOVE_CELEBRATE] =
    {
        .name = COMPOUND_STRING("CELEBRACIÓN"),
        .description = COMPOUND_STRING(
            "Te felicita en este día tan\n"
            "especial."),
        .effect = EFFECT_CELEBRATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_CELEBRATE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Celebrate,
    },

    [MOVE_HOLD_HANDS] =
    {
        .name = COMPOUND_STRING("MANOS JUNTAS"),
        .description = COMPOUND_STRING(
            "Se dan la mano con un aliado y\n"
            "se alegran."),
        .effect = EFFECT_HOLD_HANDS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoldHands,
    },

    [MOVE_BABY_DOLL_EYES] =
    {
        .name = COMPOUND_STRING("OJITOS TIERNOS"),
        .description = COMPOUND_STRING(
            "Baja el Ataque del rival\n"
            "antes de que actúe."),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BabyDollEyes,
    },

    [MOVE_NUZZLE] =
    {
        .name = COMPOUND_STRING("MOFLETE ESTÁTICO"),
        .description = COMPOUND_STRING(
            "Frota sus mofletes contra el\n"
            "rival y lo paraliza."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Nuzzle,
    },

    [MOVE_HOLD_BACK] =
    {
        .name = COMPOUND_STRING("CLEMENCIA"),
        .description = sFalseSwipeDescription,
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoldBack,
    },

    [MOVE_INFESTATION] =
    {
        .name = COMPOUND_STRING("ACOSO"),
        .description = COMPOUND_STRING(
            "Infesta al rival y lo ataca\n"
            "durante 4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_INFESTATION,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Infestation,
    },

    [MOVE_POWER_UP_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO INCREMENTO"),
        .description = COMPOUND_STRING(
            "Puñetazo duro que sube el\n"
            "Ataque del usuario."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerUpPunch,
    },

    [MOVE_OBLIVION_WING] =
    {
        .name = COMPOUND_STRING("ALA MORTÍFERA"),
        .description = sDrainingKissDescription,
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 75 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OblivionWing,
    },

    [MOVE_THOUSAND_ARROWS] =
    {
        .name = COMPOUND_STRING("MIL FLECHAS"),
        .description = COMPOUND_STRING(
            "Alcanza a voladores y los\n"
            "derriba al suelo."),
        .effect = EFFECT_SMACK_DOWN,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesAirborne = TRUE,
        .ignoreTypeIfFlyingAndUngrounded = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = COMBO_STARTER_THOUSAND_ARROWS,
        .contestComboMoves = {COMBO_STARTER_THOUSAND_WAVES},
        .battleAnimScript = gBattleAnimMove_ThousandArrows,
    },

    [MOVE_THOUSAND_WAVES] =
    {
        .name = COMPOUND_STRING("MIL TEMBLORES"),
        .description = COMPOUND_STRING(
            "Quien recibe la ola ya no\n"
            "puede huir."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_THOUSAND_WAVES,
        .contestComboMoves = {COMBO_STARTER_THOUSAND_ARROWS},
        .battleAnimScript = gBattleAnimMove_ThousandWaves,
    },

    [MOVE_LANDS_WRATH] =
    {
        .name = COMPOUND_STRING("FUERZA TELÚRICA"),
        .description = COMPOUND_STRING(
            "Reúne la energía de la tierra\n"
            "contra los rivales."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LandsWrath,
    },

    [MOVE_LIGHT_OF_RUIN] =
    {
        .name = COMPOUND_STRING("LUZ ANIQUILADORA"),
        .description = COMPOUND_STRING(
            "Gran rayo de luz que también\n"
            "daña al usuario."),
        .effect = EFFECT_RECOIL,
        .power = 140,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .recoilPercentage = 50 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LightOfRuin,
    },

    [MOVE_ORIGIN_PULSE] =
    {
        .name = COMPOUND_STRING("PULSO PRIMIGENIO"),
        .description = COMPOUND_STRING(
            "Rayos de luz azul contra\n"
            "ambos rivales."),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OriginPulse,
    },

    [MOVE_PRECIPICE_BLADES] =
    {
        .name = COMPOUND_STRING("FILO DEL ABISMO"),
        .description = COMPOUND_STRING(
            "Temibles cuchillas de piedra\n"
            "contra ambos rivales."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PrecipiceBlades,
    },

    [MOVE_DRAGON_ASCENT] =
    {
        .name = COMPOUND_STRING("ASCENSO DRACO"),
        .description = sCloseCombatDescription,
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonAscent,
    },

    [MOVE_HYPERSPACE_FURY] =
    {
        .name = COMPOUND_STRING("CERCO DIMENSIÓN"),
        .description = sHyperspaceHoleDescription,
        .effect = EFFECT_HYPERSPACE_FURY,
        .power = 100,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT, // TODO: Is this supposed to happen before the attack animation?
        },
        {
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_HYPERSPACE_FURY,
        .contestComboMoves = {COMBO_STARTER_HYPERSPACE_HOLE},
        .battleAnimScript = gBattleAnimMove_HyperspaceFury,
    },

    [MOVE_SHORE_UP] =
    {
        .name = COMPOUND_STRING("RECOGEARENA"),
        .description = COMPOUND_STRING(
            "Recupera PS. Recupera más en\n"
            "tormenta de arena."),
        .effect = EFFECT_SHORE_UP,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_ShoreUp,
    },

    [MOVE_FIRST_IMPRESSION] =
    {
        .name = COMPOUND_STRING("ESCARAMUZA"),
        .description = COMPOUND_STRING(
            "Golpea fuerte y primero. Solo\n"
            "en el 1.{SUPER_ER} turno."),
        .effect = EFFECT_FIRST_TURN_ONLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .moveProperty = MOVE_FIRST_IMPRESSION },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FirstImpression,
    },

    [MOVE_BANEFUL_BUNKER] =
    {
        .name = COMPOUND_STRING("BÚNKER"),
        .description = COMPOUND_STRING(
            "Se protege y envenena a\n"
            "quien le toque."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_BANEFUL_BUNKER },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BanefulBunker,
    },

    [MOVE_SPIRIT_SHACKLE] =
    {
        .name = COMPOUND_STRING("PUNTADA SOMBRÍA"),
        .description = COMPOUND_STRING(
            "Tras recibir el golpe, el rival\n"
            "no puede huir."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpiritShackle,
    },

    [MOVE_DARKEST_LARIAT] =
    {
        .name = COMPOUND_STRING("LARIAT OSCURO"),
        .description = COMPOUND_STRING(
            "Golpe de brazos que ignora\n"
            "cambios de caract."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkestLariat,
    },

    [MOVE_SPARKLING_ARIA] =
    {
        .name = COMPOUND_STRING("ARIA BURBUJA"),
        .description = COMPOUND_STRING(
            "Canta con burbujas. Cura\n"
            "quemaduras al tocar."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_BURN },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
            .sheerForceOverride = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCALD},
        .battleAnimScript = gBattleAnimMove_SparklingAria,
    },

    [MOVE_ICE_HAMMER] =
    {
        .name = COMPOUND_STRING("MARTILLO HIELO"),
        .description = COMPOUND_STRING(
            "Golpe de puño. Baja la\n"
            "Velocidad del usuario."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IceHammer,
    },

    [MOVE_FLORAL_HEALING] =
    {
        .name = COMPOUND_STRING("CURA FLORAL"),
        .description = COMPOUND_STRING(
            "Recupera PS de un aliado. Más\n"
            "en campo de hierba."),
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .argument = { .moveProperty = MOVE_EFFECT_FLORAL_HEALING },
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FloralHealing,
    },

    [MOVE_HIGH_HORSEPOWER] =
    {
        .name = COMPOUND_STRING("FUERZA EQUINA"),
        .description = COMPOUND_STRING(
            "Embiste con fuerza con todo\n"
            "el cuerpo."),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HighHorsepower,
    },

    [MOVE_STRENGTH_SAP] =
    {
        .name = COMPOUND_STRING("ABSORBEFUERZA"),
        .description = COMPOUND_STRING(
            "Absorbe el Ataque rival para\n"
            "curarse y lo baja."),
        .effect = EFFECT_STRENGTH_SAP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StrengthSap,
    },

    [MOVE_SOLAR_BLADE] =
    {
        .name = COMPOUND_STRING("CUCHILLA SOLAR"),
        .description = COMPOUND_STRING(
            "Carga el 1.{SUPER_ER} turno y corta\n"
            "con una hoja de luz."),
        .effect = EFFECT_SOLAR_BEAM,
        .power = 125,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNTOOKSUNLIGHT, .weather = B_WEATHER_SUN },
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SolarBlade,
    },

    [MOVE_LEAFAGE] =
    {
        .name = COMPOUND_STRING("FOLLAJE"),
        .description = COMPOUND_STRING(
            "Ataca con una lluvia de\n"
            "hojitas."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_Leafage,
    },

    [MOVE_SPOTLIGHT] =
    {
        .name = COMPOUND_STRING("FOCO"),
        .description = COMPOUND_STRING(
            "El rival debe atacar al\n"
            "Pokémon señalado."),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spotlight,
    },

    [MOVE_TOXIC_THREAD] =
    {
        .name = COMPOUND_STRING("HILO VENENOSO"),
        .description = COMPOUND_STRING(
            "Hilo que envenena y baja la\n"
            "Velocidad."),
        .effect = EFFECT_TOXIC_THREAD,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC},
        .battleAnimScript = gBattleAnimMove_ToxicThread,
    },

    [MOVE_LASER_FOCUS] =
    {
        .name = COMPOUND_STRING("AGUZAR"),
        .description = COMPOUND_STRING(
            "Su próximo ataque será un\n"
            "golpe crítico seguro."),
        .effect = EFFECT_LASER_FOCUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LaserFocus,
    },

    [MOVE_GEAR_UP] =
    {
        .name = COMPOUND_STRING("PIÑÓN AUXILIAR"),
        .description = COMPOUND_STRING(
            "Potencia ataques de quien\n"
            "tenga Más o Menos."),
        .effect = EFFECT_GEAR_UP,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GearUp,
    },

    [MOVE_THROAT_CHOP] =
    {
        .name = COMPOUND_STRING("GOLPE MORDAZA"),
        .description = COMPOUND_STRING(
            "Golpe a la garganta: anula\n"
            "sonidos 2 turnos."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THROAT_CHOP,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThroatChop,
    },

    [MOVE_POLLEN_PUFF] =
    {
        .name = COMPOUND_STRING("BOLA DE POLEN"),
        .description = COMPOUND_STRING(
            "Explota contra los rivales,\n"
            "pero cura a aliados."),
        .effect = EFFECT_HIT_ENEMY_HEAL_ALLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PollenPuff,
    },

    [MOVE_ANCHOR_SHOT] =
    {
        .name = COMPOUND_STRING("ANCLAJE"),
        .description = COMPOUND_STRING(
            "Estrangula con una cadena. El\n"
            "rival no puede huir."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AnchorShot,
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
        .name = COMPOUND_STRING("CAMPO PSÍQUICO"),
        .description = COMPOUND_STRING(
            "Campo psíquico 5 turnos.\n"
            "Bloquea la prioridad."),
        .effect = EFFECT_PSYCHIC_TERRAIN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PSYCHIC_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychicTerrain,
    },

    [MOVE_LUNGE] =
    {
        .name = COMPOUND_STRING("PLANCHA"),
        .description = COMPOUND_STRING(
            "Se abalanza y baja el Ataque\n"
            "del rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Lunge,
    },

    [MOVE_FIRE_LASH] =
    {
        .name = COMPOUND_STRING("LÁTIGO ÍGNEO"),
        .description = COMPOUND_STRING(
            "Azota con fuego y baja la\n"
            "Defensa del rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireLash,
    },

    [MOVE_POWER_TRIP] =
    {
        .name = COMPOUND_STRING("CHULERÍA"),
        .description = COMPOUND_STRING(
            "Cuantas más mejoras de\n"
            "caract. tenga, más fuerte."),
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerTrip,
    },

    [MOVE_BURN_UP] =
    {
        .name = COMPOUND_STRING("LLAMA FINAL"),
        .description = COMPOUND_STRING(
            "Lo quema todo y pierde el\n"
            "tipo Fuego."),
        .effect = EFFECT_FAIL_IF_NOT_ARG_TYPE,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .argument = { .type = TYPE_FIRE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_ARG_TYPE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_BurnUp,
    },

    [MOVE_SPEED_SWAP] =
    {
        .name = COMPOUND_STRING("CAMBIAVELOCIDAD"),
        .description = COMPOUND_STRING(
            "Intercambia su Velocidad con\n"
            "la del objetivo."),
        .effect = EFFECT_SPEED_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpeedSwap,
    },

    [MOVE_SMART_STRIKE] =
    {
        .name = COMPOUND_STRING("CUERNO CERTERO"),
        .description = COMPOUND_STRING(
            "Cornada precisa que nunca\n"
            "falla."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SmartStrike,
    },

    [MOVE_PURIFY] =
    {
        .name = COMPOUND_STRING("PURIFICACIÓN"),
        .description = COMPOUND_STRING(
            "Cura el estado del rival para\n"
            "recuperar PS."),
        .effect = EFFECT_PURIFY,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Purify,
    },

    [MOVE_REVELATION_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA DESPERTAR"),
        .description = COMPOUND_STRING(
            "Danza mística. Es del primer\n"
            "tipo del usuario."),
        .effect = EFFECT_REVELATION_DANCE,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RevelationDance,
    },

    [MOVE_CORE_ENFORCER] =
    {
        .name = COMPOUND_STRING("NÚCLEO CASTIGO"),
        .description = COMPOUND_STRING(
            "Rayo que anula la habilidad\n"
            "del rival."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 140 },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CORE_ENFORCER,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CoreEnforcer,
    },

    [MOVE_TROP_KICK] =
    {
        .name = COMPOUND_STRING("PATADA TROPICAL"),
        .description = COMPOUND_STRING(
            "Patada tropical intensa. Baja\n"
            "el Ataque."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TropKick,
    },

    [MOVE_INSTRUCT] =
    {
        .name = COMPOUND_STRING("MANDATO"),
        .description = COMPOUND_STRING(
            "Obliga al objetivo a repetir\n"
            "su último ataque."),
        .effect = EFFECT_INSTRUCT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Instruct,
    },

    [MOVE_BEAK_BLAST] =
    {
        .name = COMPOUND_STRING("PICO CAÑÓN"),
        .description = COMPOUND_STRING(
            "Calienta el pico y ataca\n"
            "último. Quema al tocar."),
        .effect = EFFECT_BEAK_BLAST,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = -3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .ballisticMove = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BeakBlast,
    },

    [MOVE_CLANGING_SCALES] =
    {
        .name = COMPOUND_STRING("FRAGOR ESCAMAS"),
        .description = COMPOUND_STRING(
            "Hace ruido con sus escamas.\n"
            "Baja su Defensa."),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClangingScales,
    },

    [MOVE_DRAGON_HAMMER] =
    {
        .name = COMPOUND_STRING("MARTILLO DRAGÓN"),
        .description = COMPOUND_STRING(
            "Balancea todo el cuerpo como\n"
            "un martillo."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonHammer,
    },

    [MOVE_BRUTAL_SWING] =
    {
        .name = COMPOUND_STRING("GIRO VIL"),
        .description = COMPOUND_STRING(
            "Gira con violencia y daña a\n"
            "todos los cercanos."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BrutalSwing,
    },

    [MOVE_AURORA_VEIL] =
    {
        .name = COMPOUND_STRING("VELO AURORA"),
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING(
            "Debilita todos los ataques,\n"
            "pero solo se usa con nieve."),
        #elif B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_BOTH
        .description = COMPOUND_STRING(
            "Con granizo o nieve, debilita\n"
            "todos los ataques."),
        #else
        .description = COMPOUND_STRING(
            "Debilita todos los ataques,\n"
            "pero solo se usa con granizo."),
        #endif
        .effect = EFFECT_AURORA_VEIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_AuroraVeil,
    },

    [MOVE_SHELL_TRAP] =
    {
        .name = COMPOUND_STRING("CORAZA TRAMPA"),
        .description = COMPOUND_STRING(
            "Coloca una trampa de\n"
            "caparazón que daña al tocar."),
        .effect = EFFECT_SHELL_TRAP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = -3,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellTrap,
    },

    [MOVE_FLEUR_CANNON] =
    {
        .name = COMPOUND_STRING("CAÑÓN FLORAL"),
        .description = COMPOUND_STRING(
            "Rayo potente que baja mucho\n"
            "el At. Esp."),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FleurCannon,
    },

    [MOVE_PSYCHIC_FANGS] =
    {
        .name = COMPOUND_STRING("PSICOCOLMILLO"),
        .description = COMPOUND_STRING(
            "Muerde con colmillos\n"
            "psíquicos. Rompe barreras."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychicFangs,
    },

    [MOVE_STOMPING_TANTRUM] =
    {
        .name = COMPOUND_STRING("PATALETA"),
        .description = COMPOUND_STRING(
            "Pisotea con rabia. Más fuerte\n"
            "tras un fallo."),
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StompingTantrum,
    },

    [MOVE_SHADOW_BONE] =
    {
        .name = COMPOUND_STRING("HUESO SOMBRÍO"),
        .description = COMPOUND_STRING(
            "Golpea con un hueso maldito.\n"
            "Puede bajar Defensa."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SHADOW_BONE,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH},
        .battleAnimScript = gBattleAnimMove_ShadowBone,
    },

    [MOVE_ACCELEROCK] =
    {
        .name = COMPOUND_STRING("ROCA VELOZ"),
        .description = COMPOUND_STRING(
            "Roca a gran velocidad.\n"
            "Siempre va primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Accelerock,
    },

    [MOVE_LIQUIDATION] =
    {
        .name = COMPOUND_STRING("HIDROARIETE"),
        .description = COMPOUND_STRING(
            "Golpea con agua. Puede bajar\n"
            "la Defensa."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Liquidation,
    },

    [MOVE_PRISMATIC_LASER] =
    {
        .name = COMPOUND_STRING("LÁSER PRISMA"),
        .description = COMPOUND_STRING(
            "Láser muy potente. Debe\n"
            "recargar el turno siguiente."),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PrismaticLaser,
    },

    [MOVE_SPECTRAL_THIEF] =
    {
        .name = COMPOUND_STRING("ROBASOMBRA"),
        .description = COMPOUND_STRING(
            "Roba las mejoras de caract.\n"
            "del objetivo y ataca."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEAL_STATS,
            .preAttackEffect = TRUE,
        }),
        .ignoresSubstitute = TRUE,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpectralThief,
    },

    [MOVE_SUNSTEEL_STRIKE] =
    {
        .name = COMPOUND_STRING("METEOIMPACTO"),
        .description = COMPOUND_STRING(
            "Golpe con la energía del sol.\n"
            "Ignora habilidades."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SunsteelStrike,
    },

    [MOVE_MOONGEIST_BEAM] =
    {
        .name = COMPOUND_STRING("RAYO UMBRÍO"),
        .description = COMPOUND_STRING(
            "Rayo con la energía lunar.\n"
            "Ignora habilidades."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MoongeistBeam,
    },

    [MOVE_TEARFUL_LOOK] =
    {
        .name = COMPOUND_STRING("OJOS LLOROSOS"),
        .description = COMPOUND_STRING(
            "Se echa a llorar y baja\n"
            "Ataque y At. Esp."),
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TearfulLook,
    },

    [MOVE_ZING_ZAP] =
    {
        .name = COMPOUND_STRING("ELECTROPUNZADA"),
        .description = COMPOUND_STRING(
            "Impacto electrificado. Puede\n"
            "hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ZingZap,
    },

    [MOVE_NATURES_MADNESS] =
    {
        .name = COMPOUND_STRING("FURIA NATURAL"),
        .description = COMPOUND_STRING(
            "Reduce a la mitad los PS\n"
            "rivales con la naturaleza."),
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 50 },
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturesMadness,
    },

    [MOVE_MULTI_ATTACK] =
    {
        .name = COMPOUND_STRING("MULTIATAQUE"),
        .description = COMPOUND_STRING(
            "Ataque que cambia según el\n"
            "disco."),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 120 : 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .holdEffect = HOLD_EFFECT_MEMORY },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MultiAttack,
    },

    [MOVE_MIND_BLOWN] =
    {
        .name = COMPOUND_STRING("CABEZA SORPRESA"),
        .description = COMPOUND_STRING(
            "Hace explotar su cabeza y\n"
            "daña a todo su alrededor."),
        .effect = EFFECT_MAX_HP_50_RECOIL,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MindBlown,
    },

    [MOVE_PLASMA_FISTS] =
    {
        .name = COMPOUND_STRING("PUÑOS PLASMA"),
        .description = COMPOUND_STRING(
            "Puños eléctricos. Lo Normal\n"
            "pasa a Eléctrico."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ION_DELUGE,
        }),
        .battleAnimScript = gBattleAnimMove_PlasmaFists,
    },

    [MOVE_PHOTON_GEYSER] =
    {
        .name = COMPOUND_STRING("GÉISER FOTÓNICO"),
        .description = COMPOUND_STRING(
            "Su mayor caract. de ataque\n"
            "decide la categoría."),
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PhotonGeyser,
    },

    [MOVE_ZIPPY_ZAP] =
    {
        .name = COMPOUND_STRING("PIKATURBO"),
        .description = COMPOUND_STRING(
            "Descarga que siempre va\n"
            "primero y es crítica."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .alwaysCriticalHit = TRUE,
        .metronomeBanned = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EVS_PLUS_1,
            .self = TRUE,
        }),
        #endif
        .battleAnimScript = gBattleAnimMove_ZippyZap,
    },

    [MOVE_SPLISHY_SPLASH] =
    {
        .name = COMPOUND_STRING("SALPIKASURF"),
        .description = COMPOUND_STRING(
            "Gran ola eléctrica. Puede\n"
            "paralizar a los rivales."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_SplishySplash,
    },

    [MOVE_FLOATY_FALL] =
    {
        .name = COMPOUND_STRING("PIKAPICADO"),
        .description = COMPOUND_STRING(
            "Flota y cae en picado. Puede\n"
            "hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .gravityBanned = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_FloatyFall,
    },

    [MOVE_PIKA_PAPOW] =
    {
        .name = COMPOUND_STRING("PIKATORMENTA"),
        .description = COMPOUND_STRING(
            "El cariño de Pikachu lo\n"
            "potencia. Nunca falla."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_PikaPapow,
    },

    [MOVE_BOUNCY_BUBBLE] =
    {
        .name = COMPOUND_STRING("VAPODRENAJE"),
        .description = COMPOUND_STRING(
            "Absorbe todo el daño\n"
            "causado."),
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 50 },
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .battleAnimScript = gBattleAnimMove_BouncyBubble,
    },

    [MOVE_BUZZY_BUZZ] =
    {
        .name = COMPOUND_STRING("JOLTIOPARÁLISIS"),
        .description = COMPOUND_STRING(
            "Descarga eléctrica que\n"
            "siempre paraliza."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
        }),
        .battleAnimScript = gBattleAnimMove_BuzzyBuzz,
    },

    [MOVE_SIZZLY_SLIDE] =
    {
        .name = COMPOUND_STRING("FLAREMBESTIDA"),
        .description = COMPOUND_STRING(
            "Carga envuelto en fuego.\n"
            "Quema al rival."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
        }),
        .battleAnimScript = gBattleAnimMove_SizzlySlide,
    },

    [MOVE_GLITZY_GLOW] =
    {
        .name = COMPOUND_STRING("ESPEAURA"),
        .description = COMPOUND_STRING(
            "Telequinesis que crea un muro\n"
            "contra lo especial."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 90,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 95 : 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LIGHT_SCREEN,
        }),
        .battleAnimScript = gBattleAnimMove_GlitzyGlow,
    },

    [MOVE_BADDY_BAD] =
    {
        .name = COMPOUND_STRING("UMBREOZONA"),
        .description = COMPOUND_STRING(
            "Ataca con malicia y crea un\n"
            "muro contra lo físico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 90,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 95 : 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REFLECT,
        }),
        .battleAnimScript = gBattleAnimMove_BaddyBad,
    },

    [MOVE_SAPPY_SEED] =
    {
        .name = COMPOUND_STRING("LEAFITOBOMBAS"),
        .description = COMPOUND_STRING(
            "Tallo gigante que siembra\n"
            "semillas que roban PS."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 90,
        .type = TYPE_GRASS,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 90 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .magicCoatAffected = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LEECH_SEED,
        }),
        .battleAnimScript = gBattleAnimMove_SappySeed,
    },

    [MOVE_FREEZY_FROST] =
    {
        .name = COMPOUND_STRING("GLACEOPRISMA"),
        .description = COMPOUND_STRING(
            "Cristal de bruma helada.\n"
            "Anula cambios de caract."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 90,
        .type = TYPE_ICE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 90 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HAZE,
        }),
        .battleAnimScript = gBattleAnimMove_FreezyFrost,
    },

    [MOVE_SPARKLY_SWIRL] =
    {
        .name = COMPOUND_STRING("SYLVEOTORNADO"),
        .description = COMPOUND_STRING(
            "Remolino de aroma. Cura el\n"
            "estado del equipo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 120 : 90,
        .type = TYPE_FAIRY,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 85 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 5 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AROMATHERAPY,
        }),
        .battleAnimScript = gBattleAnimMove_SparklySwirl,
    },

    [MOVE_VEEVEE_VOLLEY] =
    {
        .name = COMPOUND_STRING("EEVIMPACTO"),
        .description = COMPOUND_STRING(
            "El cariño de Eevee lo\n"
            "potencia. Nunca falla."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_VeeveeVolley,
    },

    [MOVE_DOUBLE_IRON_BASH] =
    {
        .name = COMPOUND_STRING("FERROPUÑO DOBLE"),
        .description = COMPOUND_STRING(
            "Gira y golpea con los brazos.\n"
            "Puede hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .strikeCount = 2,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleIronBash,
    },

    [MOVE_DYNAMAX_CANNON] =
    {
        .name = COMPOUND_STRING("CAÑÓN DINAMAX"),
        .description = COMPOUND_STRING(
            "Libera su energía. Doble daño\n"
            "a Dinamax."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mimicBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DynamaxCannon,
    },

    [MOVE_SNIPE_SHOT] =
    {
        .name = COMPOUND_STRING("DISPARO CERTERO"),
        .description = COMPOUND_STRING(
            "Ignora los efectos que\n"
            "atraen ataques."),
        .effect = EFFECT_SNIPE_SHOT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SnipeShot,
    },

    [MOVE_JAW_LOCK] =
    {
        .name = COMPOUND_STRING("PRESA MAXILAR"),
        .description = COMPOUND_STRING(
            "Ni el usuario ni el objetivo\n"
            "pueden huir."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TRAP_BOTH,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JawLock,
    },

    [MOVE_STUFF_CHEEKS] =
    {
        .name = COMPOUND_STRING("ATIBORRAMIENTO"),
        .description = COMPOUND_STRING(
            "Consume su Baya y sube mucho\n"
            "la Defensa."),
        .effect = EFFECT_STUFF_CHEEKS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StuffCheeks,
    },

    [MOVE_NO_RETREAT] =
    {
        .name = COMPOUND_STRING("BASTIÓN FINAL"),
        .description = COMPOUND_STRING(
            "Sube todas sus caract., pero\n"
            "no puede huir."),
        .effect = EFFECT_NO_RETREAT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NoRetreat,
    },

    [MOVE_TAR_SHOT] =
    {
        .name = COMPOUND_STRING("ALQUITRANAZO"),
        .description = COMPOUND_STRING(
            "Baja la Velocidad rival y lo\n"
            "hace débil al fuego."),
        .effect = EFFECT_TAR_SHOT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TarShot,
    },

    [MOVE_MAGIC_POWDER] =
    {
        .name = COMPOUND_STRING("POLVO MÁGICO"),
        .description = COMPOUND_STRING(
            "Polvo mágico que convierte al\n"
            "objetivo en Psíquico."),
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_PSYCHIC },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicPowder,
    },

    [MOVE_DRAGON_DARTS] =
    {
        .name = COMPOUND_STRING("DRACOFLECHAS"),
        .description = COMPOUND_STRING(
            "Ataca dos veces: un golpe a\n"
            "cada uno de dos objetivos."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SMART,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .strikeCount = 2,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonDarts,
    },

    [MOVE_TEATIME] =
    {
        .name = COMPOUND_STRING("HORA DEL TÉ"),
        .description = COMPOUND_STRING(
            "Todos toman el té y se comen\n"
            "sus Bayas."),
        .effect = EFFECT_TEATIME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Teatime,
    },

    [MOVE_OCTOLOCK] =
    {
        .name = COMPOUND_STRING("OCTOPRESA"),
        .description = COMPOUND_STRING(
            "Atrapa al rival y baja Def. y\n"
            "Def. Esp. cada turno."),
        .effect = EFFECT_OCTOLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Octolock,
    },

    [MOVE_BOLT_BEAK] =
    {
        .name = COMPOUND_STRING("ELECTROPICO"),
        .description = COMPOUND_STRING(
            "Doble potencia si actúa\n"
            "antes que el objetivo."),
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BoltBeak,
    },

    [MOVE_FISHIOUS_REND] =
    {
        .name = COMPOUND_STRING("BRANQUIBOCADO"),
        .description = COMPOUND_STRING(
            "Doble potencia si actúa\n"
            "antes que el objetivo."),
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FishiousRend,
    },

    [MOVE_COURT_CHANGE] =
    {
        .name = COMPOUND_STRING("CAMBIO DE CANCHA"),
        .description = COMPOUND_STRING(
            "Intercambia los efectos de\n"
            "ambos lados del campo."),
        .effect = EFFECT_COURT_CHANGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CourtChange,
    },

    [MOVE_CLANGOROUS_SOUL] =
    {
        .name = COMPOUND_STRING("ESTRUENDO ESCAMA"),
        .description = COMPOUND_STRING(
            "Gasta parte de sus PS para\n"
            "subir todas sus caract."),
        .effect = EFFECT_CLANGOROUS_SOUL,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .danceMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClangorousSoul,
    },

    [MOVE_BODY_PRESS] =
    {
        .name = COMPOUND_STRING("PLANCHA CORPORAL"),
        .description = COMPOUND_STRING(
            "Más daño cuanto mayor sea su\n"
            "Defensa."),
        .effect = EFFECT_BODY_PRESS,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BodyPress,
    },

    [MOVE_DECORATE] =
    {
        .name = COMPOUND_STRING("DECORACIÓN"),
        .description = COMPOUND_STRING(
            "Sube mucho el Ataque y\n"
            "At. Esp. del objetivo."),
        .effect = EFFECT_DECORATE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Decorate,
    },

    [MOVE_DRUM_BEATING] =
    {
        .name = COMPOUND_STRING("BATERÍA ASALTO"),
        .description = COMPOUND_STRING(
            "Toca un tambor para atacar.\n"
            "Baja la Velocidad rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DrumBeating,
    },

    [MOVE_SNAP_TRAP] =
    {
        .name = COMPOUND_STRING("CEPO"),
        .description = COMPOUND_STRING(
            "Atrapa al objetivo en un cepo\n"
            "durante 4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_SNAP_TRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SnapTrap,
    },

    [MOVE_PYRO_BALL] =
    {
        .name = COMPOUND_STRING("BALÓN ÍGNEO"),
        .description = COMPOUND_STRING(
            "Lanza una bola de fuego.\n"
            "Puede quemar."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .thawsUser = TRUE,
        .ballisticMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PyroBall,
    },

    [MOVE_BEHEMOTH_BLADE] =
    {
        .name = COMPOUND_STRING("TAJO SUPREMO"),
        .description = COMPOUND_STRING(
            "Ataca como una espada. Doble\n"
            "daño a Dinamax."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BehemothBlade,
    },

    [MOVE_BEHEMOTH_BASH] =
    {
        .name = COMPOUND_STRING("EMBATE SUPREMO"),
        .description = COMPOUND_STRING(
            "Ataca como un escudo. Doble\n"
            "daño a Dinamax."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BehemothBash,
    },

    [MOVE_AURA_WHEEL] =
    {
        .name = COMPOUND_STRING("RUEDA AURAL"),
        .description = COMPOUND_STRING(
            "Sube Velocidad al atacar. El\n"
            "tipo depende de su forma."),
        .effect = EFFECT_AURA_WHEEL,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AuraWheel,
    },

    [MOVE_BREAKING_SWIPE] =
    {
        .name = COMPOUND_STRING("VASTO IMPACTO"),
        .description = COMPOUND_STRING(
            "Ataca con la cola. Baja el\n"
            "Ataque de los golpeados."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BreakingSwipe,
    },

    [MOVE_BRANCH_POKE] =
    {
        .name = COMPOUND_STRING("PUNZADA RAMA"),
        .description = COMPOUND_STRING(
            "Pincha al objetivo con una\n"
            "rama afilada."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BranchPoke,
    },

    [MOVE_OVERDRIVE] =
    {
        .name = COMPOUND_STRING("AMPLIFICADOR"),
        .description = COMPOUND_STRING(
            "Rasga su guitarra y causa\n"
            "fuertes vibraciones."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Overdrive,
    },

    [MOVE_APPLE_ACID] =
    {
        .name = COMPOUND_STRING("ÁCIDO MÁLICO"),
        .description = COMPOUND_STRING(
            "Ácido de manzana. Baja la\n"
            "Def. Esp. del rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AppleAcid,
    },

    [MOVE_GRAV_APPLE] =
    {
        .name = COMPOUND_STRING("FUERZA G"),
        .description = COMPOUND_STRING(
            "Deja caer una manzana. Baja\n"
            "la Defensa del rival."),
        .effect = EFFECT_GRAV_APPLE,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GravApple,
    },

    [MOVE_SPIRIT_BREAK] =
    {
        .name = COMPOUND_STRING("CHOQUE ANÍMICO"),
        .description = COMPOUND_STRING(
            "Fuerza que doblega el\n"
            "espíritu. Baja el At. Esp."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpiritBreak,
    },

    [MOVE_STRANGE_STEAM] =
    {
        .name = COMPOUND_STRING("CAUTIVAPOR"),
        .description = COMPOUND_STRING(
            "Emite un vapor extraño que\n"
            "puede confundir."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StrangeSteam,
    },

    [MOVE_LIFE_DEW] =
    {
        .name = COMPOUND_STRING("GOTA VITAL"),
        .description = COMPOUND_STRING(
            "Esparce agua y recupera PS\n"
            "propios y de aliados."),
        .effect = EFFECT_LIFE_DEW,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LifeDew,
    },

    [MOVE_OBSTRUCT] =
    {
        .name = COMPOUND_STRING("OBSTRUCCIÓN"),
        .description = COMPOUND_STRING(
            "Se protege y baja mucho la\n"
            "Defensa de quien le toque."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_OBSTRUCT },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Obstruct,
    },

    [MOVE_FALSE_SURRENDER] =
    {
        .name = COMPOUND_STRING("IRREVERENCIA"),
        .description = COMPOUND_STRING(
            "Se inclina y pincha con el\n"
            "pelo. Nunca falla."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FalseSurrender,
    },

    [MOVE_METEOR_ASSAULT] =
    {
        .name = COMPOUND_STRING("ASALTO ESTELAR"),
        .description = COMPOUND_STRING(
            "Golpea con un puerro grueso.\n"
            "Luego debe descansar."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorAssault,
    },

    [MOVE_ETERNABEAM] =
    {
        .name = COMPOUND_STRING("RAYO INFINITO"),
        .description = COMPOUND_STRING(
            "El ataque más fuerte de\n"
            "Eternatus. Luego descansa."),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Eternabeam,
    },

    [MOVE_STEEL_BEAM] =
    {
        .name = COMPOUND_STRING("METALÁSER"),
        .description = COMPOUND_STRING(
            "Dispara un rayo de acero que\n"
            "daña al usuario."),
        .effect = EFFECT_MAX_HP_50_RECOIL,
        .power = 140,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelBeam,
    },

    [MOVE_EXPANDING_FORCE] =
    {
        .name = COMPOUND_STRING("VASTA FUERZA"),
        .description = COMPOUND_STRING(
            "Más fuerte y contra todos en\n"
            "campo psíquico."),
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_PSYCHIC_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_USER,
            .hitsBothFoes = TRUE,
        },
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PSYCHIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_ExpandingForce,
    },

    [MOVE_STEEL_ROLLER] =
    {
        .name = COMPOUND_STRING("ALLANADOR FÉRREO"),
        .description = COMPOUND_STRING(
            "Destruye el campo. Falla si no\n"
            "hay ninguno."),
        .effect = EFFECT_STEEL_ROLLER,
        .power = 130,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelRoller,
    },

    [MOVE_SCALE_SHOT] =
    {
        .name = COMPOUND_STRING("RÁFAGA ESCAMAS"),
        .description = COMPOUND_STRING(
            "Dispara escamas de 2 a 5\n"
            "veces. +Vel., -Defensa."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SCALE_SHOT,
        }),
        .battleAnimScript = gBattleAnimMove_ScaleShot,
    },

    [MOVE_METEOR_BEAM] =
    {
        .name = COMPOUND_STRING("RAYO METEÓRICO"),
        .description = COMPOUND_STRING(
            "Ataque de 2 turnos que sube\n"
            "el At. Esp. antes."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 120,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_METEORBEAMCHARGING },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorBeam,
    },

    [MOVE_SHELL_SIDE_ARM] =
    {
        .name = COMPOUND_STRING("MOLUSCAÑÓN"),
        .description = COMPOUND_STRING(
            "Daño físico o especial, el\n"
            "mejor. Puede envenenar."),
        .effect = EFFECT_SHELL_SIDE_ARM,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellSideArm,
    },

    [MOVE_MISTY_EXPLOSION] =
    {
        .name = COMPOUND_STRING("BRUMA EXPLOSIVA"),
        .description = COMPOUND_STRING(
            "Daña a todos y se debilita.\n"
            "Más fuerte con niebla."),
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .explosion = TRUE,
        .dampBanned = TRUE,
        .argument.terrainBoost = {
            .terrain =  STATUS_FIELD_MISTY_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_USER,
        },
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MISTY_TERRAIN},
        .battleAnimScript = gBattleAnimMove_MistyExplosion,
    },

    [MOVE_GRASSY_GLIDE] =
    {
        .name = COMPOUND_STRING("FITOIMPULSO"),
        .description = COMPOUND_STRING(
            "Se desliza y golpea. Primero\n"
            "en campo de hierba."),
        .effect = EFFECT_GRASSY_GLIDE,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 55 : 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GRASSY_TERRAIN},
        .battleAnimScript = gBattleAnimMove_GrassyGlide,
    },

    [MOVE_RISING_VOLTAGE] =
    {
        .name = COMPOUND_STRING("ALTO VOLTAJE"),
        .description = COMPOUND_STRING(
            "Doble potencia en campo\n"
            "eléctrico."),
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_ELECTRIC_TERRAIN,
            .percent = 100,
            .groundCheck = GROUND_CHECK_TARGET,
        },
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_RisingVoltage,
    },

    [MOVE_TERRAIN_PULSE] =
    {
        .name = COMPOUND_STRING("PULSO DE CAMPO"),
        .description = COMPOUND_STRING(
            "Tipo y potencia cambian\n"
            "según el campo."),
        .effect = EFFECT_TERRAIN_PULSE,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN, COMBO_STARTER_MISTY_TERRAIN, COMBO_STARTER_GRASSY_TERRAIN, COMBO_STARTER_PSYCHIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_TerrainPulse,
    },

    [MOVE_SKITTER_SMACK] =
    {
        .name = COMPOUND_STRING("GOLPE RASTRERO"),
        .description = COMPOUND_STRING(
            "Se escurre tras el rival y\n"
            "baja su At. Esp."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkitterSmack,
    },

    [MOVE_BURNING_JEALOUSY] =
    {
        .name = COMPOUND_STRING("ENVIDIA ARDIENTE"),
        .description = COMPOUND_STRING(
            "Quema a los rivales que\n"
            "subieron caract. ese turno."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .onlyIfTargetRaisedStats = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BurningJealousy,
    },

    [MOVE_LASH_OUT] =
    {
        .name = COMPOUND_STRING("DESAHOGO"),
        .description = COMPOUND_STRING(
            "Doble potencia si le bajaron\n"
            "caract. este turno."),
        .effect = EFFECT_LASH_OUT,
        .power = 75,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LashOut,
    },

    [MOVE_POLTERGEIST] =
    {
        .name = COMPOUND_STRING("POLTERGEIST"),
        .description = COMPOUND_STRING(
            "Usa el objeto del rival. Falla\n"
            "si no lleva ninguno."),
        .effect = EFFECT_POLTERGEIST,
        .power = 110,
        .type = TYPE_GHOST,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Poltergeist,
    },

    [MOVE_CORROSIVE_GAS] =
    {
        .name = COMPOUND_STRING("GAS CORROSIVO"),
        .description = COMPOUND_STRING(
            "Gas muy ácido que funde los\n"
            "objetos de los demás."),
        .effect = EFFECT_CORROSIVE_GAS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CorrosiveGas,
    },

    [MOVE_COACHING] =
    {
        .name = COMPOUND_STRING("MOTIVACIÓN"),
        .description = COMPOUND_STRING(
            "Entrena a sus aliados: sube\n"
            "Ataque y Defensa."),
        .effect = EFFECT_COACHING,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Coaching,
    },

    [MOVE_FLIP_TURN] =
    {
        .name = COMPOUND_STRING("VIRAJE"),
        .description = COMPOUND_STRING(
            "Ataca y vuelve rápido para\n"
            "cambiarse."),
        .effect = EFFECT_HIT_ESCAPE,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlipTurn,
    },

    [MOVE_TRIPLE_AXEL] =
    {
        .name = COMPOUND_STRING("TRIPLE AXEL"),
        .description = COMPOUND_STRING(
            "Tres patadas, cada una más\n"
            "fuerte que la anterior."),
        .effect = EFFECT_TRIPLE_KICK,
        .power = 20,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TripleAxel,
    },

    [MOVE_DUAL_WINGBEAT] =
    {
        .name = COMPOUND_STRING("ALA BIS"),
        .description = COMPOUND_STRING(
            "Golpea con las alas dos veces\n"
            "seguidas."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DualWingbeat,
    },

    [MOVE_SCORCHING_SANDS] =
    {
        .name = COMPOUND_STRING("ARENAS ARDIENTES"),
        .description = COMPOUND_STRING(
            "Lanza arena abrasadora.\n"
            "Puede quemar."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ScorchingSands,
    },

    [MOVE_JUNGLE_HEALING] =
    {
        .name = COMPOUND_STRING("CURA SELVÁTICA"),
        .description = COMPOUND_STRING(
            "Cura PS y estado propios y de\n"
            "los aliados."),
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JungleHealing,
    },

    [MOVE_WICKED_BLOW] =
    {
        .name = COMPOUND_STRING("GOLPE OSCURO"),
        .description = COMPOUND_STRING(
            "Domina el estilo Siniestro.\n"
            "Siempre es crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 75 : 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WickedBlow,
    },

    [MOVE_SURGING_STRIKES] =
    {
        .name = COMPOUND_STRING("AZOTE TORRENCIAL"),
        .description = COMPOUND_STRING(
            "Domina el estilo Agua. Tres\n"
            "golpes críticos."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .punchingMove = TRUE,
        .strikeCount = 3,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SurgingStrikes,
    },

    [MOVE_THUNDER_CAGE] =
    {
        .name = COMPOUND_STRING("ELECTROJAULA"),
        .description = COMPOUND_STRING(
            "Atrapa en una jaula eléctrica\n"
            "4 o 5 turnos."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_THUNDER_CAGE,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThunderCage,
    },

    [MOVE_DRAGON_ENERGY] =
    {
        .name = COMPOUND_STRING("DRACOENERGÍA"),
        .description = COMPOUND_STRING(
            "Cuantos más PS tenga el\n"
            "usuario, más daño."),
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonEnergy,
    },

    [MOVE_FREEZING_GLARE] =
    {
        .name = COMPOUND_STRING("MIRADA HELADORA"),
        .description = COMPOUND_STRING(
            "Poder psíquico desde los\n"
            "ojos. Puede congelar."),
        .power = 90,
        .effect = EFFECT_HIT,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezingGlare,
    },

    [MOVE_FIERY_WRATH] =
    {
        .name = COMPOUND_STRING("FURIA CANDENTE"),
        .description = COMPOUND_STRING(
            "Ataque alimentado por la ira.\n"
            "Puede hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FieryWrath,
    },

    [MOVE_THUNDEROUS_KICK] =
    {
        .name = COMPOUND_STRING("PATADA RELÁMPAGO"),
        .description = COMPOUND_STRING(
            "Patada como un rayo. Baja la\n"
            "Defensa del rival."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThunderousKick,
    },

    [MOVE_GLACIAL_LANCE] =
    {
        .name = COMPOUND_STRING("LANZA GLACIAL"),
        .description = COMPOUND_STRING(
            "Lanza de hielo envuelta en\n"
            "ventisca contra rivales."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 130,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GlacialLance,
    },

    [MOVE_ASTRAL_BARRAGE] =
    {
        .name = COMPOUND_STRING("ORBES ESPECTRO"),
        .description = COMPOUND_STRING(
            "Horda de fantasmitas contra\n"
            "los rivales."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AstralBarrage,
    },

    [MOVE_EERIE_SPELL] =
    {
        .name = COMPOUND_STRING("CONJURO FUNESTO"),
        .description = COMPOUND_STRING(
            "Poder psíquico. Quita 3 PP al\n"
            "último ataque rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EERIE_SPELL,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_EerieSpell,
    },

    [MOVE_DIRE_CLAW] =
    {
        .name = COMPOUND_STRING("GARRA NOCIVA"),
        .description = COMPOUND_STRING(
            "Suele ser crítico. Puede\n"
            "causar varios estados."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 80 : 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DIRE_CLAW,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_DireClaw,
    },

    [MOVE_PSYSHIELD_BASH] =
    {
        .name = COMPOUND_STRING("ASALTO BARRERA"),
        .description = COMPOUND_STRING(
            "Energía psíquica. Puede\n"
            "subir la Defensa."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_PsyshieldBash,
    },

    [MOVE_POWER_SHIFT] =
    {
        .name = COMPOUND_STRING("CAMBIAPODER"),
        .description = COMPOUND_STRING(
            "Intercambia su Ataque y su\n"
            "Defensa."),
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_PowerShift,
},

    [MOVE_STONE_AXE] =
    {
        .name = COMPOUND_STRING("HACHAZO PÉTREO"),
        .description = COMPOUND_STRING(
            "Coloca rocas afiladas que\n"
            "dañan al rival."),
        .effect = EFFECT_STONE_AXE,
        .power = 65,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_StoneAxe,
    },

    [MOVE_SPRINGTIDE_STORM] =
    {
        .name = COMPOUND_STRING("CICLÓN PRIMAVERA"),
        .description = COMPOUND_STRING(
            "Envuelve en vientos feroces.\n"
            "Varía según su forma."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_FAIRY,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_SpringtideStorm,
    },

    [MOVE_MYSTICAL_POWER] =
    {
        .name = COMPOUND_STRING("PODER MÍSTICO"),
        .description = COMPOUND_STRING(
            "Un poder misterioso ataca y\n"
            "sube su At. Esp."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_MysticalPower,
    },

    [MOVE_RAGING_FURY] =
    {
        .name = COMPOUND_STRING("ERUPCIÓN DE IRA"),
        .description = COMPOUND_STRING(
            "Dura de 2 a 3 turnos y acaba\n"
            "confundiéndote."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RagingFury,
    },

    [MOVE_WAVE_CRASH] =
    {
        .name = COMPOUND_STRING("ENVITE ACUÁTICO"),
        .description = COMPOUND_STRING(
            "Embestida envuelta en agua.\n"
            "También le daña."),
        .effect = EFFECT_RECOIL,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 75,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaveCrash,
    },

    [MOVE_CHLOROBLAST] =
    {
        .name = COMPOUND_STRING("CLOROFILÁSER"),
        .description = COMPOUND_STRING(
            "Estallido de clorofila que\n"
            "daña al usuario."),
        .effect = EFFECT_CHLOROBLAST,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 150 : 120,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_Chloroblast,
    },

    [MOVE_MOUNTAIN_GALE] =
    {
        .name = COMPOUND_STRING("VIENTO CARÁMBANO"),
        .description = COMPOUND_STRING(
            "Grandes bloques de hielo.\n"
            "Puede hacer retroceder."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 85,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_MountainGale,
    },

    [MOVE_VICTORY_DANCE] =
    {
        .name = COMPOUND_STRING("DANZA TRIUNFAL"),
        .description = COMPOUND_STRING(
            "Danza que sube Ataque,\n"
            "Defensa y Velocidad."),
        .effect = EFFECT_VICTORY_DANCE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VictoryDance,
    },

    [MOVE_HEADLONG_RUSH] =
    {
        .name = COMPOUND_STRING("ARREMETIDA"),
        .description = COMPOUND_STRING(
            "Placaje con todo el cuerpo.\n"
            "Baja sus defensas."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadlongRush,
    },

    [MOVE_BARB_BARRAGE] =
    {
        .name = COMPOUND_STRING("MIL PÚAS TÓXICAS"),
        .description = COMPOUND_STRING(
            "Puede envenenar. Más fuerte\n"
            "contra envenenados."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_PSN_ANY },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_BarbBarrage,
    },

    [MOVE_ESPER_WING] =
    {
        .name = COMPOUND_STRING("ALA AURAL"),
        .description = COMPOUND_STRING(
            "Suele ser crítico. Sube la\n"
            "Velocidad del usuario."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 80 : 75,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 90,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_EsperWing,
    },

    [MOVE_BITTER_MALICE] =
    {
        .name = COMPOUND_STRING("RENCOR REPRIMIDO"),
        .description = COMPOUND_STRING(
            "Rencor escalofriante. Baja el\n"
            "Ataque del rival."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 75 : 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_BitterMalice,
    },

    [MOVE_SHELTER] =
    {
        .name = COMPOUND_STRING("RETRACCIÓN"),
        .description = COMPOUND_STRING(
            "Endurece su piel y sube mucho\n"
            "la Defensa."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_Shelter,
    },

    [MOVE_TRIPLE_ARROWS] =
    {
        .name = COMPOUND_STRING("TRIPLE FLECHA"),
        .description = COMPOUND_STRING(
            "Suele ser crítico. Puede\n"
            "bajar Defensa o retroceder."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 90 : 50,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 15,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_TripleArrows,
    },

    [MOVE_INFERNAL_PARADE] =
    {
        .name = COMPOUND_STRING("MARCHA ESPECTRAL"),
        .description = COMPOUND_STRING(
            "Más daño si el rival sufre un\n"
            "estado. Puede quemar."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_ANY },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_InfernalParade,
    },

    [MOVE_CEASELESS_EDGE] =
    {
        .name = COMPOUND_STRING("TAJO METRALLA"),
        .description = COMPOUND_STRING(
            "Coloca púas que dañan al\n"
            "rival."),
        .effect = EFFECT_CEASELESS_EDGE,
        .power = 65,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_CeaselessEdge,
    },

    [MOVE_BLEAKWIND_STORM] =
    {
        .name = COMPOUND_STRING("VENDAVAL GÉLIDO"),
        .description = COMPOUND_STRING(
            "Viento gélido y brutal. Puede\n"
            "bajar la Velocidad."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_FLYING,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_BleakwindStorm,
    },

    [MOVE_WILDBOLT_STORM] =
    {
        .name = COMPOUND_STRING("ELECTORMENTA"),
        .description = COMPOUND_STRING(
            "Tempestad brutal. Puede\n"
            "paralizar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_ELECTRIC,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_WildboltStorm,
    },

    [MOVE_SANDSEAR_STORM] =
    {
        .name = COMPOUND_STRING("SIMÚN DE ARENA"),
        .description = COMPOUND_STRING(
            "Arena ardiente y brutal.\n"
            "Puede quemar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_GROUND,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_SandsearStorm,
    },

    [MOVE_LUNAR_BLESSING] =
    {
        .name = COMPOUND_STRING("PLEGARIA LUNAR"),
        .description = COMPOUND_STRING(
            "Se cura y sana a sí mismo y a\n"
            "su aliado."),
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_LunarBlessing,
    },

    [MOVE_TAKE_HEART] =
    {
        .name = COMPOUND_STRING("BÁLSAMO OSADO"),
        .description = COMPOUND_STRING(
            "Se anima para curarse y\n"
            "fortalecerse."),
        .effect = EFFECT_TAKE_HEART,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TakeHeart,
    },

    [MOVE_TERA_BLAST] =
    {
        .name = COMPOUND_STRING("TERAEXPLOSIÓN"),
        .description = COMPOUND_STRING(
            "Si se ha teracristalizado,\n"
            "ataca con su teratipo."),
        .effect = EFFECT_TERA_BLAST,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .forcePressure = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TERA_BLAST,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_TeraBlast,
    },

    [MOVE_SILK_TRAP] =
    {
        .name = COMPOUND_STRING("TELATRAMPA"),
        .description = COMPOUND_STRING(
            "Se protege y baja la\n"
            "Velocidad de quien le toque."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_SILK_TRAP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_SilkTrap,
    },

    [MOVE_AXE_KICK] =
    {
        .name = COMPOUND_STRING("PATADA HACHA"),
        .description = COMPOUND_STRING(
            "Si falla, se daña. Puede\n"
            "confundir."),
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_AxeKick,
    },

    [MOVE_LAST_RESPECTS] =
    {
        .name = COMPOUND_STRING("HOMENAJE PÓSTUMO"),
        .description = COMPOUND_STRING(
            "Más daño por cada aliado\n"
            "debilitado."),
        .effect = EFFECT_LAST_RESPECTS,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_LastRespects,
    },

    [MOVE_LUMINA_CRASH] =
    {
        .name = COMPOUND_STRING("FOTOCOLISIÓN"),
        .description = COMPOUND_STRING(
            "Luz que afecta la mente. Baja\n"
            "mucho la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_LuminaCrash,
    },

    [MOVE_ORDER_UP] =
    {
        .name = COMPOUND_STRING("OÍDO COCINA"),
        .description = COMPOUND_STRING(
            "Sube sus caract. según el\n"
            "Tatsugiri que lleve."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ORDER_UP,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_OrderUp,
    },

    [MOVE_JET_PUNCH] =
    {
        .name = COMPOUND_STRING("PUÑO JET"),
        .description = COMPOUND_STRING(
            "Puñetazo a velocidad\n"
            "cegadora que va primero."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JetPunch,
    },

    [MOVE_SPICY_EXTRACT] =
    {
        .name = COMPOUND_STRING("EXTRACTO PICANTE"),
        .description = COMPOUND_STRING(
            "Sube mucho el Ataque del\n"
            "objetivo y baja su Defensa."),
        .effect = EFFECT_SPICY_EXTRACT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_SpicyExtract,
    },

    [MOVE_SPIN_OUT] =
    {
        .name = COMPOUND_STRING("QUEMARRUEDA"),
        .description = COMPOUND_STRING(
            "Fuerza las piernas. Baja\n"
            "mucho su Velocidad."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_2,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_SpinOut,
    },

    [MOVE_POPULATION_BOMB] =
    {
        .name = COMPOUND_STRING("PROLIFERACIÓN"),
        .description = COMPOUND_STRING(
            "Sus compañeros golpean de 1\n"
            "a 10 veces seguidas."),
        .effect = EFFECT_POPULATION_BOMB,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .strikeCount = 10,
        .battleAnimScript = gBattleAnimMove_PopulationBomb,
    },

    [MOVE_ICE_SPINNER] =
    {
        .name = COMPOUND_STRING("PIRUETA HELADA"),
        .description = COMPOUND_STRING(
            "Golpe con patas heladas que\n"
            "destruye el campo."),
        .effect = EFFECT_ICE_SPINNER,
        .power = 80,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_IceSpinner,
    },

    [MOVE_GLAIVE_RUSH] =
    {
        .name = COMPOUND_STRING("ASALTO ESPADÓN"),
        .description = COMPOUND_STRING(
            "El próximo turno no fallará y\n"
            "hará doble daño."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GLAIVE_RUSH,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_GlaiveRush,
    },

    [MOVE_REVIVAL_BLESSING] =
    {
        .name = COMPOUND_STRING("PLEGARIA VITAL"),
        .description = COMPOUND_STRING(
            "Revive a un Pokémon del\n"
            "equipo con la mitad de PS."),
        .effect = EFFECT_REVIVAL_BLESSING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .healingMove = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .battleAnimScript = gBattleAnimMove_RevivalBlessing,
    },

    [MOVE_SALT_CURE] =
    {
        .name = COMPOUND_STRING("SALAZÓN"),
        .description = COMPOUND_STRING(
            "Daña cada turno. Doble daño a\n"
            "tipos Acero y Agua."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SALT_CURE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_SaltCure,
    },

    [MOVE_TRIPLE_DIVE] =
    {
        .name = COMPOUND_STRING("TRIPLE INMERSIÓN"),
        .description = COMPOUND_STRING(
            "Salpica agua al objetivo tres\n"
            "veces seguidas."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .battleAnimScript = gBattleAnimMove_TripleDive,
    },

    [MOVE_MORTAL_SPIN] =
    {
        .name = COMPOUND_STRING("GIRO MORTÍFERO"),
        .description = COMPOUND_STRING(
            "Quita trampas y Drenadoras.\n"
            "Envenena a los rivales."),
        .effect = EFFECT_RAPID_SPIN,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_MortalSpin,
    },

    [MOVE_DOODLE] =
    {
        .name = COMPOUND_STRING("DECALCOMANÍA"),
        .description = COMPOUND_STRING(
            "Su habilidad y la del aliado\n"
            "pasan a ser la del objetivo."),
        .effect = EFFECT_DOODLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_Doodle,
    },

    [MOVE_FILLET_AWAY] =
    {
        .name = COMPOUND_STRING("DESLOME"),
        .description = COMPOUND_STRING(
            "Gasta PS para subir mucho\n"
            "sus ataques y Velocidad."),
        .effect = EFFECT_FILLET_AWAY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_FilletAway,
    },

    [MOVE_KOWTOW_CLEAVE] =
    {
        .name = COMPOUND_STRING("GENUFENDIENTE"),
        .description = COMPOUND_STRING(
            "Hace una reverencia y corta\n"
            "al rival. Nunca falla."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_KowtowCleave,
    },

    [MOVE_FLOWER_TRICK] =
    {
        .name = COMPOUND_STRING("TRUCO FLORAL"),
        .description = COMPOUND_STRING(
            "Ramo trucado. Siempre es\n"
            "crítico y nunca falla."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .alwaysCriticalHit = TRUE,
        .battleAnimScript = gBattleAnimMove_FlowerTrick,
    },

    [MOVE_TORCH_SONG] =
    {
        .name = COMPOUND_STRING("CANTO ARDIENTE"),
        .description = COMPOUND_STRING(
            "Llamas que abrasan al\n"
            "objetivo. Sube su At. Esp."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_TorchSong,
    },

    [MOVE_AQUA_STEP] =
    {
        .name = COMPOUND_STRING("DANZA ACUÁTICA"),
        .description = COMPOUND_STRING(
            "Danza ligera y fluida. Sube la\n"
            "Velocidad."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .danceMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_AquaStep,
    },

    [MOVE_RAGING_BULL] =
    {
        .name = COMPOUND_STRING("FURIA TAURINA"),
        .description = COMPOUND_STRING(
            "Placaje que rompe barreras.\n"
            "Su forma decide el tipo."),
        .effect = EFFECT_RAGING_BULL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_RagingBull,
    },

    [MOVE_MAKE_IT_RAIN] =
    {
        .name = COMPOUND_STRING("FIEBRE DORADA"),
        .description = COMPOUND_STRING(
            "Baja su At. Esp. Luego\n"
            "recupera dinero."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PAYDAY,
        },
        {
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_MakeItRain,
    },

    [MOVE_RUINATION] =
    {
        .name = COMPOUND_STRING("CALAMIDAD"),
        .description = COMPOUND_STRING(
            "Invoca un desastre que quita\n"
            "la mitad de los PS."),
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 50 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Ruination,
    },

    [MOVE_COLLISION_COURSE] =
    {
        .name = COMPOUND_STRING("NITROCHOQUE"),
        .description = COMPOUND_STRING(
            "Explosión prehistórica. Más\n"
            "fuerte si es muy eficaz."),
        .effect = EFFECT_COLLISION_COURSE,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_CollisionCourse,
    },

    [MOVE_ELECTRO_DRIFT] =
    {
        .name = COMPOUND_STRING("ELECTRODERRAPE"),
        .description = COMPOUND_STRING(
            "Electricidad futurista. Más\n"
            "fuerte si es muy eficaz."),
        .effect = EFFECT_COLLISION_COURSE,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_ElectroDrift,
    },

    [MOVE_SHED_TAIL] =
    {
        .name = COMPOUND_STRING("AUTOTOMÍA"),
        .description = COMPOUND_STRING(
            "Crea un sustituto antes de\n"
            "retirarse."),
        .effect = EFFECT_SHED_TAIL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_ShedTail,
    },

    [MOVE_CHILLY_RECEPTION] =
    {
        .name = COMPOUND_STRING("FRÍA ACOGIDA"),
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        .description = COMPOUND_STRING(
            "Bad joke summons hailstorm.\n"
            "The user also switches out."),
        #else
        .description = COMPOUND_STRING(
            "Un chiste malo invoca nieve.\n"
            "Luego se retira."),
        #endif
        .effect = EFFECT_WEATHER_AND_SWITCH,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? BATTLE_WEATHER_HAIL : BATTLE_WEATHER_SNOW },
        .battleAnimScript = gBattleAnimMove_ChillyReception,
    },

    [MOVE_TIDY_UP] =
    {
        .name = COMPOUND_STRING("LIMPIEZA GENERAL"),
        .description = COMPOUND_STRING(
            "Limpia trampas y sube su\n"
            "Ataque y Velocidad."),
        .effect = EFFECT_TIDY_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TidyUp,
    },

    [MOVE_SNOWSCAPE] =
    {
        .name = COMPOUND_STRING("PAISAJE NEVADO"),
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
            .description = COMPOUND_STRING(
                "Tormenta de granizo que\n"
                "golpea en cada turno."),
        #else
            .description = COMPOUND_STRING(
                "Invoca una nevada que dura\n"
                "cinco turnos."),
        #endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? BATTLE_WEATHER_HAIL : BATTLE_WEATHER_SNOW },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? gBattleAnimMove_Hail : gBattleAnimMove_Snowscape,
    },

    [MOVE_POUNCE] =
    {
        .name = COMPOUND_STRING("BRINCO"),
        .description = COMPOUND_STRING(
            "Se abalanza sobre el rival y\n"
            "baja su Velocidad."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_Pounce,
    },

    [MOVE_TRAILBLAZE] =
    {
        .name = COMPOUND_STRING("ABRECAMINOS"),
        .description = COMPOUND_STRING(
            "Ataca por sorpresa y sube su\n"
            "Velocidad."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Trailblaze,
    },

    [MOVE_CHILLING_WATER] =
    {
        .name = COMPOUND_STRING("AGUA FRÍA"),
        .description = COMPOUND_STRING(
            "Ducha de agua helada. Baja el\n"
            "Ataque del objetivo."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ChillingWater,
    },

    [MOVE_HYPER_DRILL] =
    {
        .name = COMPOUND_STRING("HIPERTALADRO"),
        .description = COMPOUND_STRING(
            "Una punta giratoria que\n"
            "atraviesa la Protección."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_HyperDrill,
    },

    [MOVE_TWIN_BEAM] =
    {
        .name = COMPOUND_STRING("LÁSER DOBLE"),
        .description = COMPOUND_STRING(
            "Rayos místicos de los ojos\n"
            "que golpean dos veces."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .strikeCount = 2,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TwinBeam,
    },

    [MOVE_RAGE_FIST] =
    {
        .name = COMPOUND_STRING("PUÑO FURIA"),
        .description = COMPOUND_STRING(
            "Cuantas más veces le hayan\n"
            "golpeado, más fuerte."),
        .effect = EFFECT_RAGE_FIST,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_RageFist,
    },

    [MOVE_ARMOR_CANNON] =
    {
        .name = COMPOUND_STRING("CAÑÓN ARMADURA"),
        .description = COMPOUND_STRING(
            "Ataque fuerte, pero baja sus\n"
            "defensas."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ArmorCannon,
    },

    [MOVE_BITTER_BLADE] =
    {
        .name = COMPOUND_STRING("ESPADA LAMENTO"),
        .description = COMPOUND_STRING(
            "Absorbe la mitad del daño\n"
            "causado."),
        .effect = EFFECT_ABSORB,
        .power = 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .healingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_BitterBlade,
    },

    [MOVE_DOUBLE_SHOCK] =
    {
        .name = COMPOUND_STRING("ELECTROPALMAS"),
        .description = COMPOUND_STRING(
            "Gasta su electricidad y\n"
            "pierde el tipo Eléctrico."),
        .effect = EFFECT_FAIL_IF_NOT_ARG_TYPE,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .argument = { .type = TYPE_ELECTRIC },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_ARG_TYPE,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_DoubleShock,
    },

    [MOVE_GIGATON_HAMMER] =
    {
        .name = COMPOUND_STRING("MARTILLO COLOSAL"),
        .description = COMPOUND_STRING(
            "Golpe con un martillo enorme.\n"
            "No se repite seguido."),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .cantUseTwice = TRUE,
        .battleAnimScript = gBattleAnimMove_GigatonHammer,
    },

    [MOVE_COMEUPPANCE] =
    {
        .name = COMPOUND_STRING("RESARCIMIENTO"),
        .description = COMPOUND_STRING(
            "Contraataca con fuerza a\n"
            "quien le hirió el último."),
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .reflectDamage.damagePercent = 150,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL | 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .makesContact = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Comeuppance,
    },

    [MOVE_AQUA_CUTTER] =
    {
        .name = COMPOUND_STRING("TAJO ACUÁTICO"),
        .description = COMPOUND_STRING(
            "Corte de agua a presión.\n"
            "Suele ser crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_WATER,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_AquaCutter,
    },

    [MOVE_BLAZING_TORQUE] =
    {
        .name = COMPOUND_STRING("PIROCHOQUE"),
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_BlazingTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_WICKED_TORQUE] =
    {
        .name = COMPOUND_STRING("OMINOCHOQUE"),
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance = 10,
        }),
        .battleAnimScript = gBattleAnimMove_WickedTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_NOXIOUS_TORQUE] =
    {
        .name = COMPOUND_STRING("PONZOCHOQUE"),
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_NoxiousTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_COMBAT_TORQUE] =
    {
        .name = COMPOUND_STRING("PUGNACHOQUE"),
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_CombatTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_MAGICAL_TORQUE] =
    {
        .name = COMPOUND_STRING("FEERICHOQUE"),
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_MagicalTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_PSYBLADE] =
    {
        .name = COMPOUND_STRING("PSICOHOJAS"),
        .description = COMPOUND_STRING(
            "Más potencia en campo\n"
            "eléctrico."),
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_ELECTRIC_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_NONE,
        },
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_Psyblade,
    },

    [MOVE_HYDRO_STEAM] =
    {
        .name = COMPOUND_STRING("HIDROVAPOR"),
        .description = COMPOUND_STRING(
            "Más potencia con sol intenso."),
        .effect = EFFECT_HYDRO_STEAM,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .battleAnimScript = gBattleAnimMove_HydroSteam,
    },

    [MOVE_BLOOD_MOON] =
    {
        .name = COMPOUND_STRING("LUNA ROJA"),
        .description = COMPOUND_STRING(
            "Desata la luna de sangre. No\n"
            "se repite seguido."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .cantUseTwice = TRUE,
        .battleAnimScript = gBattleAnimMove_BloodMoon,
    },

    [MOVE_MATCHA_GOTCHA] =
    {
        .name = COMPOUND_STRING("CAÑÓN BATIDOR"),
        .description = COMPOUND_STRING(
            "Absorbe la mitad del daño\n"
            "causado. Puede quemar."),
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .thawsUser = TRUE,
        .healingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_MatchaGotcha,
    },

    [MOVE_SYRUP_BOMB] =
    {
        .name = COMPOUND_STRING("BOMBA CARAMELO"),
        .description = COMPOUND_STRING(
            "Baja la Velocidad rival cada\n"
            "turno durante 3 turnos."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SYRUP_BOMB,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_SyrupBomb,
    },

    [MOVE_IVY_CUDGEL] =
    {
        .name = COMPOUND_STRING("GARROTE LIANA"),
        .description = COMPOUND_STRING(
            "El tipo cambia con la máscara.\n"
            "Suele ser crítico."),
        .effect = EFFECT_IVY_CUDGEL,
        .power = 100,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_IvyCudgel,
    },

    [MOVE_ELECTRO_SHOT] =
    {
        .name = COMPOUND_STRING("ELECTRORRAYO"),
        .description = COMPOUND_STRING(
            "Acumula electricidad y\n"
            "dispara alto voltaje."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_ELECTROSHOTCHARGING, .weather = B_WEATHER_RAIN },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_ElectroShot,
    },

    [MOVE_TERA_STARSTORM] =
    {
        .name = COMPOUND_STRING("TERACLÚSTER"),
        .description = COMPOUND_STRING(
            "En su forma astral, golpea a\n"
            "todos los rivales."),
        .effect = EFFECT_TERA_STARSTORM,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .assistBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .battleAnimScript = gBattleAnimMove_TeraStarstorm,
    },

    [MOVE_FICKLE_BEAM] =
    {
        .name = COMPOUND_STRING("LÁSER VELEIDOSO"),
        .description = COMPOUND_STRING(
            "Dispara un rayo de luz. A\n"
            "veces doble de fuerte."),
        .effect = EFFECT_FICKLE_BEAM,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_FickleBeam,
    },

    [MOVE_BURNING_BULWARK] =
    {
        .name = COMPOUND_STRING("LLAMA PROTECTORA"),
        .description = COMPOUND_STRING(
            "Evita ataques y quema a\n"
            "quien le golpee."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_BURNING_BULWARK },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_BurningBulwark,
    },

    [MOVE_THUNDERCLAP] =
    {
        .name = COMPOUND_STRING("RELÁMPAGO SÚBITO"),
        .description = sSuckerPunchDescription,
        .effect = EFFECT_SUCKER_PUNCH,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Thunderclap,
    },

    [MOVE_MIGHTY_CLEAVE] =
    {
        .name = COMPOUND_STRING("FILO POTENTE"),
        .description = sFeintDescription,
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_MightyCleave,
    },

    [MOVE_TACHYON_CUTTER] =
    {
        .name = COMPOUND_STRING("TAJO TAQUIÓN"),
        .description = COMPOUND_STRING(
            "Cuchillas de partículas.\n"
            "Golpea dos veces."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .strikeCount = 2,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_TachyonCutter,
    },

    [MOVE_HARD_PRESS] =
    {
        .name = COMPOUND_STRING("PRENSA METÁLICA"),
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .battleAnimScript = gBattleAnimMove_HardPress,
    },

    [MOVE_DRAGON_CHEER] =
    {
        .name = COMPOUND_STRING("BRAMIDO DRAGÓN"),
        .description = COMPOUND_STRING(
            "Sube el índice crítico aliado;\n"
            "más si son Dragón."),
        .effect = EFFECT_DRAGON_CHEER,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresSubstitute = TRUE,
        .battleAnimScript = gBattleAnimMove_DragonCheer,
    },

    [MOVE_ALLURING_VOICE] =
    {
        .name = COMPOUND_STRING("CANTO ENCANTADOR"),
        .description = COMPOUND_STRING(
            "Confunde al rival si subió\n"
            "caract. este turno."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .onlyIfTargetRaisedStats = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_AlluringVoice,
    },

    [MOVE_TEMPER_FLARE] =
    {
        .name = COMPOUND_STRING("CÓLERA ARDIENTE"),
        .description = COMPOUND_STRING(
            "Ataque desesperado. Doble si\n"
            "su último ataque falló."),
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .battleAnimScript = gBattleAnimMove_TemperFlare,
    },

    [MOVE_SUPERCELL_SLAM] =
    {
        .name = COMPOUND_STRING("PLANCHA VOLTAICA"),
        .description = COMPOUND_STRING(
            "Golpe electrificado. Si falla,\n"
            "el usuario se daña."),
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SupercellSlam,
    },

    [MOVE_PSYCHIC_NOISE] =
    {
        .name = COMPOUND_STRING("PSICORRUIDO"),
        .description = COMPOUND_STRING(
            "Ondas sonoras que dañan e\n"
            "impiden curarse 2 turnos."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_NOISE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_PsychicNoise,
    },

    [MOVE_UPPER_HAND] =
    {
        .effect = EFFECT_UPPER_HAND,
        .name = COMPOUND_STRING("PALMA RAUDA"),
        .description = COMPOUND_STRING(
            "Hace retroceder si el\n"
            "objetivo prepara prioridad."),
        .power = 65,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_UpperHand,
    },

    [MOVE_MALIGNANT_CHAIN] =
    {
        .name = COMPOUND_STRING("CADENA VIRULENTA"),
        .description = COMPOUND_STRING(
            "Cadena corrosiva. Puede\n"
            "envenenar gravemente."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TOXIC,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_MalignantChain,
    },

    // Z-Moves
    [MOVE_BREAKNECK_BLITZ] =
    {
        .name = COMPOUND_STRING("CARRERA ARROLLADORA"),
        .description = COMPOUND_STRING(
            "Coge impulso y embiste al\n"
            "rival. Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,    //determined from move type
        .battleAnimScript = gBattleAnimMove_BreakneckBlitz,
    },
    [MOVE_ALL_OUT_PUMMELING] =
    {
        .name = COMPOUND_STRING("RÁFAGA DEMOLEDORA"),
        .description = COMPOUND_STRING(
            "Lanza una esfera de energía.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_AllOutPummeling,
    },
    [MOVE_SUPERSONIC_SKYSTRIKE] =
    {
        .name = COMPOUND_STRING("PICADO SUPERSÓNICO"),
        .description = COMPOUND_STRING(
            "Se eleva y cae en picado.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SupersonicSkystrike,
    },
    [MOVE_ACID_DOWNPOUR] =
    {
        .name = COMPOUND_STRING("DILUVIO CORROSIVO"),
        .description = COMPOUND_STRING(
            "Hunde al rival en veneno.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_AcidDownpour,
    },
    [MOVE_TECTONIC_RAGE] =
    {
        .name = COMPOUND_STRING("BARRENA TELÚRICA"),
        .description = COMPOUND_STRING(
            "Excava hondo y embiste.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_TectonicRage,
    },
    [MOVE_CONTINENTAL_CRUSH] =
    {
        .name = COMPOUND_STRING("APLASTAMIENTO GIGALÍTICO"),
        .description = COMPOUND_STRING(
            "Deja caer una montaña de\n"
            "roca. Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_ContinentalCrush,
    },
    [MOVE_SAVAGE_SPIN_OUT] =
    {
        .name = COMPOUND_STRING("GUADAÑA SEDOSA"),
        .description = COMPOUND_STRING(
            "Ata al rival con hilos de seda.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SavageSpinOut,
    },
    [MOVE_NEVER_ENDING_NIGHTMARE] =
    {
        .name = COMPOUND_STRING("PRESA ESPECTRAL"),
        .description = COMPOUND_STRING(
            "Rencores profundos atrapan\n"
            "al rival. Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_NeverEndingNightmare,
    },
    [MOVE_CORKSCREW_CRASH] =
    {
        .name = COMPOUND_STRING("HÉLICE TREPANADORA"),
        .description = COMPOUND_STRING(
            "Gira muy rápido y embiste.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_CorkscrewCrash,
    },
    [MOVE_INFERNO_OVERDRIVE] =
    {
        .name = COMPOUND_STRING("HECATOMBE PÍRICA"),
        .description = COMPOUND_STRING(
            "Lanza un fuego intenso.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_InfernoOverdrive,
    },
    [MOVE_HYDRO_VORTEX] =
    {
        .name = COMPOUND_STRING("HIDROVÓRTICE ABISAL"),
        .description = COMPOUND_STRING(
            "Un gran remolino engulle al\n"
            "rival. Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_HydroVortex,
    },
    [MOVE_BLOOM_DOOM] =
    {
        .name = COMPOUND_STRING("MEGATÓN FLORAL"),
        .description = COMPOUND_STRING(
            "Ataca con energía vegetal.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_BloomDoom,
    },
    [MOVE_GIGAVOLT_HAVOC] =
    {
        .name = COMPOUND_STRING("GIGAVOLTIO DESTRUCTOR"),
        .description = COMPOUND_STRING(
            "Golpea con electricidad\n"
            "intensa. Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GigavoltHavoc,
    },
    [MOVE_SHATTERED_PSYCHE] =
    {
        .name = COMPOUND_STRING("DISRUPTOR PSÍQUICO"),
        .description = COMPOUND_STRING(
            "Controla al objetivo para\n"
            "dañarlo. Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_ShatteredPsyche,
    },
    [MOVE_SUBZERO_SLAMMER] =
    {
        .name = COMPOUND_STRING("CRIOALIENTO DESPIADADO"),
        .description = COMPOUND_STRING(
            "Baja la temperatura y\n"
            "congela. Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SubzeroSlammer,
    },
    [MOVE_DEVASTATING_DRAKE] =
    {
        .name = COMPOUND_STRING("DRACOALIENTO DEVASTADOR"),
        .description = COMPOUND_STRING(
            "Desarrolla su aura y ataca.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_DevastatingDrake,
    },
    [MOVE_BLACK_HOLE_ECLIPSE] =
    {
        .name = COMPOUND_STRING("AGUJERO NEGRO ANIQUILADOR"),
        .description = COMPOUND_STRING(
            "Absorbe al rival en energía\n"
            "oscura. Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_BlackHoleEclipse,
    },
    [MOVE_TWINKLE_TACKLE] =
    {
        .name = COMPOUND_STRING("ARRUMACO SIDERAL"),
        .description = COMPOUND_STRING(
            "Espacio feérico encantador.\n"
            "Potencia variable."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_TwinkleTackle,
    },
    [MOVE_CATASTROPIKA] =
    {
        .name = COMPOUND_STRING("PIKAVOLTIO LETAL"),
        .description = COMPOUND_STRING(
            "Pikachu usa toda su\n"
            "electricidad y se abalanza."),
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_Catastropika,
    },
    [MOVE_10000000_VOLT_THUNDERBOLT] =
    {
        .name = COMPOUND_STRING("GIGARRAYO FULMINANTE"),
        .description = COMPOUND_STRING(
            "Pikachu con gorra desata una\n"
            "descarga. Suele ser crítico."),
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .criticalHitStage = 2,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_10000000VoltThunderbolt,
    },
    [MOVE_STOKED_SPARKSURFER] =
    {
        .name = COMPOUND_STRING("SURFEO GALVÁNICO"),
        .description = COMPOUND_STRING(
            "Raichu de Alola ataca con\n"
            "todo. Paraliza."),
        .effect = EFFECT_HIT,
        .power = 175,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_StokedSparksurfer,
    },
    [MOVE_EXTREME_EVOBOOST] =
    {
        .name = COMPOUND_STRING("NOVENA POTENCIA"),
        .description = COMPOUND_STRING(
            "Eevee recibe energía de sus\n"
            "amigos. Sube caract."),
        .effect = EFFECT_EXTREME_EVOBOOST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .battleAnimScript = gBattleAnimMove_ExtremeEvoboost,
    },
    [MOVE_PULVERIZING_PANCAKE] =
    {
        .name = COMPOUND_STRING("ARROJO INTEMPESTIVO"),
        .description = COMPOUND_STRING(
            "Snorlax se mueve con energía\n"
            "y ataca con todo."),
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_PulverizingPancake,
    },
    [MOVE_GENESIS_SUPERNOVA] =
    {
        .name = COMPOUND_STRING("SUPERNOVA ORIGINAL"),
        .description = COMPOUND_STRING(
            "Mew ataca con todo. Crea un\n"
            "campo psíquico."),
        .effect = EFFECT_HIT,
        .power = 185,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_GenesisSupernova,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_TERRAIN,
            .chance = 100,
        }),
    },
    [MOVE_SINISTER_ARROW_RAID] =
    {
        .name = COMPOUND_STRING("ALUVIÓN DE FLECHAS SOMBRÍAS"),
        .description = COMPOUND_STRING(
            "Decidueye dispara flechas\n"
            "sin fin con todo."),
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SinisterArrowRaid,
    },
    [MOVE_MALICIOUS_MOONSAULT] =
    {
        .name = COMPOUND_STRING("HIPERPLANCHA OSCURA"),
        .description = COMPOUND_STRING(
            "Incineroar embiste al\n"
            "objetivo con todo."),
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .minimizeDoubleDamage = TRUE,
        .battleAnimScript = gBattleAnimMove_MaliciousMoonsault,
    },
    [MOVE_OCEANIC_OPERETTA] =
    {
        .name = COMPOUND_STRING("SINFONÍA DE LA DIVA MARINA"),
        .description = COMPOUND_STRING(
            "Primarina invoca una\n"
            "cantidad enorme de agua."),
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_OceanicOperetta,
    },
    [MOVE_SPLINTERED_STORMSHARDS] =
    {
        .name = COMPOUND_STRING("TEMPESTAD ROCOSA"),
        .description = COMPOUND_STRING(
            "Lycanroc ataca con todo.\n"
            "Elimina el campo."),
        .effect = EFFECT_ICE_SPINNER,
        .power = 190,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SplinteredStormshards,
    },
    [MOVE_LETS_SNUGGLE_FOREVER] =
    {
        .name = COMPOUND_STRING("SOMANTA AMISTOSA"),
        .description = COMPOUND_STRING(
            "Mimikyu golpea al objetivo\n"
            "con todas sus fuerzas."),
        .effect = EFFECT_HIT,
        .power = 190,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_LetsSnuggleForever,
    },
    [MOVE_CLANGOROUS_SOULBLAZE] =
    {
        .name = COMPOUND_STRING("ESTRUENDO IMPLACABLE"),
        .description = COMPOUND_STRING(
            "Kommo-o ataca con todo. Sube\n"
            "todas sus caract."),
        .effect = EFFECT_HIT,
        .power = 185,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_ClangorousSoulblaze,
    },
    [MOVE_GUARDIAN_OF_ALOLA] =
    {
        .name = COMPOUND_STRING("CÓLERA DEL GUARDIÁN"),
        .description = COMPOUND_STRING(
            "El Pokémon Espíritu Tierra\n"
            "reduce mucho los PS."),
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 75 },
        .battleAnimScript = gBattleAnimMove_GuardianOfAlola,
    },
    [MOVE_SEARING_SUNRAZE_SMASH] =
    {
        .name = COMPOUND_STRING("EMBESTIDA SOLAR"),
        .description = COMPOUND_STRING(
            "Solgaleo ataca con todo.\n"
            "Ignora habilidades."),
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_SearingSunrazeSmash,
    },
    [MOVE_MENACING_MOONRAZE_MAELSTROM] =
    {
        .name = COMPOUND_STRING("DEFLAGRACIÓN LUNAR"),
        .description = COMPOUND_STRING(
            "Lunala ataca con todo.\n"
            "Ignora habilidades."),
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_MenacingMoonrazeMaelstrom,
    },
    [MOVE_LIGHT_THAT_BURNS_THE_SKY] =
    {
        .name = COMPOUND_STRING("FOTODESTRUCCIÓN APOCAL."),
        .description = COMPOUND_STRING(
            "Ataque supremo de Necrozma.\n"
            "Ignora habilidades."),
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 200,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_LightThatBurnsTheSky,
    },
    [MOVE_SOUL_STEALING_7_STAR_STRIKE] =
    {
        .name = COMPOUND_STRING("CONSTELACIÓN ROBAALMAS"),
        .description = COMPOUND_STRING(
            "Marshadow golpea y patea con\n"
            "todas sus fuerzas."),
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SoulStealing7StarStrike,
    },

    [MOVE_MAX_GUARD] =
    {
        .name = COMPOUND_STRING("MAXIBARRIERA"),
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_MAX_GUARD },
        .battleAnimScript = gBattleAnimMove_MaxGuard,
    },

    [MOVE_MAX_FLARE] =
    {
        .name = COMPOUND_STRING("MAXIGNICIÓN"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Fuego. Sol\n"
            "intenso 5 turnos."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxFlare,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SUN,
        }),
    },

    [MOVE_MAX_FLUTTERBY] =
    {
        .name = COMPOUND_STRING("MAXINSECTO"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Bicho. Baja el\n"
            "At. Esp. rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxFlutterby,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SP_ATK_SIDE,
        }),
    },

    [MOVE_MAX_LIGHTNING] =
    {
        .name = COMPOUND_STRING("MAXITORMENTA"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Eléctrico.\n"
            "Crea un campo eléctrico."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxLightning,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ELECTRIC_TERRAIN,
        }),
    },

    [MOVE_MAX_STRIKE] =
    {
        .name = COMPOUND_STRING("MAXIATAQUE"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Normal. Baja\n"
            "la Velocidad rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxStrike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SPEED_SIDE,
        }),
    },

    [MOVE_MAX_KNUCKLE] =
    {
        .name = COMPOUND_STRING("MAXIPUÑO"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Lucha. Sube\n"
            "el Ataque aliado."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxKnuckle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_ATTACK,
        }),
    },

    [MOVE_MAX_PHANTASM] =
    {
        .name = COMPOUND_STRING("MAXIESPECTRO"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Fantasma.\n"
            "Baja la Defensa rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxPhantasm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_DEFENSE_SIDE,
        }),
    },

    [MOVE_MAX_HAILSTORM] =
    {
        .name = COMPOUND_STRING("MAXIHELADA"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Hielo. Granizo\n"
            "durante 5 turnos."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxHailstorm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HAIL,
        }),
    },

    [MOVE_MAX_OOZE] =
    {
        .name = COMPOUND_STRING("MAXIÁCIDO"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Veneno. Sube\n"
            "el At. Esp. aliado."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxOoze,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SP_ATK,
        }),
    },

    [MOVE_MAX_GEYSER] =
    {
        .name = COMPOUND_STRING("MAXICHORRO"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Agua. Lluvia\n"
            "durante 5 turnos."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxGeyser,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAIN,
        }),
    },

    [MOVE_MAX_AIRSTREAM] =
    {
        .name = COMPOUND_STRING("MAXICICLÓN"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Volador. Sube\n"
            "la Velocidad aliada."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxAirstream,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SPEED,
        }),
    },

    [MOVE_MAX_STARFALL] =
    {
        .name = COMPOUND_STRING("MAXIESTELA"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Hada. Crea un\n"
            "campo de niebla."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxStarfall,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_MISTY_TERRAIN,
        }),
    },

    [MOVE_MAX_WYRMWIND] =
    {
        .name = COMPOUND_STRING("MAXIDRACO"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Dragón. Baja\n"
            "el Ataque rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxWyrmwind,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_ATTACK_SIDE,
        }),
    },

    [MOVE_MAX_MINDSTORM] =
    {
        .name = COMPOUND_STRING("MAXIONDA"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Psíquico.\n"
            "Crea un campo psíquico."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxMindstorm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_TERRAIN,
        }),
    },

    [MOVE_MAX_ROCKFALL] =
    {
        .name = COMPOUND_STRING("MAXILITO"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Roca. Desata\n"
            "una tormenta de arena."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxRockfall,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SANDSTORM,
        }),
    },

    [MOVE_MAX_QUAKE] =
    {
        .name = COMPOUND_STRING("MAXITEMBLOR"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Tierra. Sube\n"
            "la Def. Esp. aliada."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_MaxQuake,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SP_DEF,
        }),
    },

    [MOVE_MAX_DARKNESS] =
    {
        .name = COMPOUND_STRING("MAXISOMBRA"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Siniestro.\n"
            "Baja la Def. Esp. rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxDarkness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SP_DEF_SIDE,
        }),
    },

    [MOVE_MAX_OVERGROWTH] =
    {
        .name = COMPOUND_STRING("MAXIFLORA"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Planta. Crea\n"
            "un campo de hierba."),
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxOvergrowth,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GRASSY_TERRAIN,
        }),
    },

    [MOVE_MAX_STEELSPIKE] =
    {
        .name = COMPOUND_STRING("MAXIMETAL"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Acero. Sube la\n"
            "Defensa aliada."),
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxSteelspike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_DEFENSE,
        }),
    },

    [MOVE_G_MAX_VINE_LASH] =
    {
        .name = COMPOUND_STRING("GIGALIANAS"),
        .description = COMPOUND_STRING(
            "Gigamax de Venusaur. Daña\n"
            "durante 4 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVineLash,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_VINE_LASH,
        }),
    },

    [MOVE_G_MAX_WILDFIRE] =
    {
        .name = COMPOUND_STRING("GIGALLAMARADA"),
        .description = COMPOUND_STRING(
            "Gigamax de Charizard. Daña\n"
            "durante 4 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxWildfire,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WILDFIRE,
        }),
    },

    [MOVE_G_MAX_CANNONADE] =
    {
        .name = COMPOUND_STRING("GIGACAÑONAZO"),
        .description = COMPOUND_STRING(
            "Gigamax de Blastoise. Daña\n"
            "durante 4 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCannonade,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CANNONADE,
        }),
    },

    [MOVE_G_MAX_BEFUDDLE] =
    {
        .name = COMPOUND_STRING("GIGAESTUPOR"),
        .description = COMPOUND_STRING(
            "Gigamax de Butterfree.\n"
            "Veneno, parálisis o sueño."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxBefuddle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EFFECT_SPORE_SIDE,
        }),
    },

    [MOVE_G_MAX_VOLT_CRASH] =
    {
        .name = COMPOUND_STRING("GIGATRONADA"),
        .description = COMPOUND_STRING(
            "Gigamax de Pikachu. Paraliza\n"
            "a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVoltCrash,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYZE_SIDE,
        }),
    },

    [MOVE_G_MAX_GOLD_RUSH] =
    {
        .name = COMPOUND_STRING("GIGAMONEDAS"),
        .description = COMPOUND_STRING(
            "Gigamax de Meowth. Confunde\n"
            "y da dinero."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxGoldRush,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE,
        }),
    },

    [MOVE_G_MAX_CHI_STRIKE] =
    {
        .name = COMPOUND_STRING("GIGAPUÑICIÓN"),
        .description = COMPOUND_STRING(
            "Gigamax de Machamp. Sube el\n"
            "índice crítico."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxChiStrike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CRIT_PLUS_SIDE,
        }),
    },

    [MOVE_G_MAX_TERROR] =
    {
        .name = COMPOUND_STRING("GIGAAPARICIÓN"),
        .description = COMPOUND_STRING(
            "Gigamax de Gengar. Impide\n"
            "huir a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxTerror,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE_SIDE,
        }),
    },

    [MOVE_G_MAX_FOAM_BURST] =
    {
        .name = COMPOUND_STRING("GIGAESPUMA"),
        .description = COMPOUND_STRING(
            "Gigamax de Kingler. Baja\n"
            "mucho la Velocidad."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxFoamBurst,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SPEED_2_SIDE,
        }),
    },

    [MOVE_G_MAX_RESONANCE] =
    {
        .name = COMPOUND_STRING("GIGAMELODÍA"),
        .description = COMPOUND_STRING(
            "Gigamax de Lapras. Reduce el\n"
            "daño 5 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxResonance,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AURORA_VEIL,
        }),
    },

    [MOVE_G_MAX_CUDDLE] =
    {
        .name = COMPOUND_STRING("GIGATERNURA"),
        .description = COMPOUND_STRING(
            "Gigamax de Eevee. Enamora a\n"
            "los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCuddle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_INFATUATE_SIDE,
        }),
    },

    [MOVE_G_MAX_REPLENISH] =
    {
        .name = COMPOUND_STRING("GIGARRECICLAJE"),
        .description = COMPOUND_STRING(
            "Gigamax de Snorlax. Repone\n"
            "Bayas comidas."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxReplenish,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECYCLE_BERRIES,
        }),
    },

    [MOVE_G_MAX_MALODOR] =
    {
        .name = COMPOUND_STRING("GIGAPESTILENCIA"),
        .description = COMPOUND_STRING(
            "Gigamax de Garbodor.\n"
            "Envenena a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxMalodor,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON_SIDE,
        }),
    },

    [MOVE_G_MAX_MELTDOWN] =
    {
        .name = COMPOUND_STRING("GIGAFUNDIDO"),
        .description = COMPOUND_STRING(
            "Gigamax de Melmetal. Impide\n"
            "repetir ataques."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxMeltdown,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TORMENT_SIDE,
        }),
    },

    [MOVE_G_MAX_DRUM_SOLO] =
    {
        .name = COMPOUND_STRING("GIGARREDOBLE"),
        .description = COMPOUND_STRING(
            "Gigamax de Rillaboom. Ignora\n"
            "habilidades."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxDrumSolo,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_FIREBALL] =
    {
        .name = COMPOUND_STRING("GIGAESFERA ÍGNEA"),
        .description = COMPOUND_STRING(
            "Gigamax de Cinderace. Ignora\n"
            "habilidades."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxFireball,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_HYDROSNIPE] =
    {
        .name = COMPOUND_STRING("GIGADISPARO"),
        .description = COMPOUND_STRING(
            "Gigamax de Inteleon. Ignora\n"
            "habilidades."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxHydrosnipe,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_WIND_RAGE] =
    {
        .name = COMPOUND_STRING("GIGAHURACÁN"),
        .description = COMPOUND_STRING(
            "Gigamax de Corviknight. Quita\n"
            "barreras rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxWindRage,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEFOG,
        }),
    },

    [MOVE_G_MAX_GRAVITAS] =
    {
        .name = COMPOUND_STRING("GIGABÓVEDA"),
        .description = COMPOUND_STRING(
            "Gigamax de Orbeetle. Cambia\n"
            "la gravedad 5 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxGravitas,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GRAVITY,
        }),
    },

    [MOVE_G_MAX_STONESURGE] =
    {
        .name = COMPOUND_STRING("GIGATRAMPA ROCAS"),
        .description = COMPOUND_STRING(
            "Gigamax de Drednaw. Esparce\n"
            "rocas afiladas."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxStonesurge,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEALTH_ROCK,
        }),
    },

    [MOVE_G_MAX_VOLCALITH] =
    {
        .name = COMPOUND_STRING("GIGARROCA ÍGNEA"),
        .description = COMPOUND_STRING(
            "Gigamax de Coalossal. Daña\n"
            "durante 4 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVolcalith,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_VOLCALITH,
        }),
    },

    [MOVE_G_MAX_TARTNESS] =
    {
        .name = COMPOUND_STRING("GIGACORROSIÓN"),
        .description = COMPOUND_STRING(
            "Gigamax de Flapple. Baja la\n"
            "Evasión rival."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxTartness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_EVASIVENESS_SIDE,
        }),
    },

    [MOVE_G_MAX_SWEETNESS] =
    {
        .name = COMPOUND_STRING("GIGANÉCTAR"),
        .description = COMPOUND_STRING(
            "Gigamax de Appletun. Cura el\n"
            "estado aliado."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSweetness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AROMATHERAPY,
        }),
    },

    [MOVE_G_MAX_SANDBLAST] =
    {
        .name = COMPOUND_STRING("GIGAPOLVAREDA"),
        .description = COMPOUND_STRING(
            "Gigamax de Sandaconda.\n"
            "Atrapa en arena."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSandblast,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SANDBLAST_SIDE,
        }),
    },

    [MOVE_G_MAX_STUN_SHOCK] =
    {
        .name = COMPOUND_STRING("GIGADESCARGA"),
        .description = COMPOUND_STRING(
            "Gigamax de Toxtricity.\n"
            "Envenena o paraliza."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxStunShock,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON_PARALYZE_SIDE,
        }),
    },

    [MOVE_G_MAX_CENTIFERNO] =
    {
        .name = COMPOUND_STRING("GIGACIENFUEGOS"),
        .description = COMPOUND_STRING(
            "Gigamax de Centiskorch.\n"
            "Atrapa en llamas."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCentiferno,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIRE_SPIN_SIDE,
        }),
    },

    [MOVE_G_MAX_SMITE] =
    {
        .name = COMPOUND_STRING("GIGACASTIGO"),
        .description = COMPOUND_STRING(
            "Gigamax de Hatterene.\n"
            "Confunde a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSmite,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSE_SIDE,
        }),
    },


    [MOVE_G_MAX_SNOOZE] =
    {
        .name = COMPOUND_STRING("GIGASOPOR"),
        .description = COMPOUND_STRING(
            "Gigamax de Grimmsnarl.\n"
            "Adormece a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSnooze,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_YAWN_FOE,
        }),
    },

    [MOVE_G_MAX_FINALE] =
    {
        .name = COMPOUND_STRING("GIGACOLOFÓN"),
        .description = COMPOUND_STRING(
            "Gigamax de Alcremie. Cura PS\n"
            "aliados."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxFinale,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HEAL_TEAM,
        }),
    },

    [MOVE_G_MAX_STEELSURGE] =
    {
        .name = COMPOUND_STRING("GIGATRAMPA ACERO"),
        .description = COMPOUND_STRING(
            "Gigamax de Copperajah.\n"
            "Esparce púas afiladas."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSteelsurge,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEELSURGE,
        }),
    },

    [MOVE_G_MAX_DEPLETION] =
    {
        .name = COMPOUND_STRING("GIGADESGASTE"),
        .description = COMPOUND_STRING(
            "Gigamax de Duraludon. Reduce\n"
            "los PP."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxDepletion,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPITE,
        }),
    },

    [MOVE_G_MAX_ONE_BLOW] =
    {
        .name = COMPOUND_STRING("GIGAGOLPE BRUSCO"),
        .description = sGMaxOneBlowDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxOneBlow,
    },

    [MOVE_G_MAX_RAPID_FLOW] =
    {
        .name = COMPOUND_STRING("GIGAGOLPE FLUIDO"),
        .description = sGMaxOneBlowDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxRapidFlow,
    },
};
