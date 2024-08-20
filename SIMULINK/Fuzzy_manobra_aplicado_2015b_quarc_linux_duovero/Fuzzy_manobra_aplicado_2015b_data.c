/*
 * Fuzzy_manobra_aplicado_2015b_data.c
 *
 * Code generation for model "Fuzzy_manobra_aplicado_2015b".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Jul 16 13:21:01 2024
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Fuzzy_manobra_aplicado_2015b.h"
#include "Fuzzy_manobra_aplicado_2015b_private.h"

/* Block parameters (auto storage) */
P_Fuzzy_manobra_aplicado_2015_T Fuzzy_manobra_aplicado_2015b_P = {
  0.1175,
  23.0,
  0.034,
  1.0,
  2.5,

  { 0.0, 0.181818181818182, 0.363636363636364, 0.545454545454545,
    0.727272727272727, 0.909090909090909, 1.09090909090909, 1.27272727272727,
    1.45454545454545, 1.63636363636364, 1.81818181818182, 2.0, 1.81818181818182,
    1.63636363636364, 1.45454545454545, 1.27272727272727, 1.09090909090909,
    0.909090909090909, 0.727272727272727, 0.545454545454545, 0.363636363636364,
    0.181818181818182, 0.0, 0.0, 0.540640817455598, 0.909631995354518,
    0.989821441880933, 0.755749574354258, 0.28173255684143, -0.281732556841429,
    -0.755749574354258, -0.989821441880933, -0.909631995354519,
    -0.540640817455597, -2.44929359829471E-16, 0.540640817455597,
    0.909631995354519, 0.989821441880933, 0.755749574354258, 0.281732556841429,
    -0.28173255684143, -0.755749574354258, -0.989821441880933,
    -0.909631995354518, -0.540640817455597, -0.0 },
  -1.8,
  0.01,
  -0.2,
  0.02,
  0.01,
  7.0,
  0.035,
  0.02,
  7.5,
  4.0,

  { 0.0, 0.0, 1.0 },
  0.0,
  10.0,
  10.0,
  1.0,
  1.0,
  -3.141,
  -2.06323809523809,
  -1.17,
  0.0,
  1.17,
  1.9,
  3.141,
  -0.35,
  0.35,
  -2.97985714285714,
  2.98,
  0.0,
  1.0,
  0.05389,
  0.372,
  0.238558316142804,
  0.09,
  0.2386,
  0.263,
  0.05389,
  0.09175,
  0.09175,
  0.107,
  0.107,
  3.0,
  1.0,
  4U,

  { 8U, 9U, 10U },

  { 2U, 3U },
  1002U,

  { 2000U, 2001U },
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  1,
  0.0,
  1.0,
  0.0,
  1.0,
  0.0,
  0.0,
  0.0,
  1.0,
  0.0,
  0.0,
  0.0,
  1.0,
  1.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  1.0,
  0.0,
  1.0,
  0.0,
  0.0,
  0.0,

  { -0.15, -0.147, -0.144, -0.141, -0.13799999999999998, -0.135, -0.132, -0.129,
    -0.126, -0.123, -0.12, -0.11699999999999999, -0.11399999999999999,
    -0.11099999999999999, -0.10799999999999998, -0.105, -0.102, -0.099, -0.096,
    -0.093, -0.09, -0.087, -0.083999999999999991, -0.081, -0.078, -0.075, -0.072,
    -0.068999999999999992, -0.065999999999999989, -0.063, -0.06,
    -0.057000000000000009, -0.053999999999999992, -0.05099999999999999, -0.048,
    -0.045, -0.04200000000000001, -0.038999999999999993, -0.03599999999999999,
    -0.033, -0.03, -0.02700000000000001, -0.023999999999999994,
    -0.020999999999999991, -0.017999999999999988, -0.014999999999999986,
    -0.012000000000000011, -0.009000000000000008, -0.0060000000000000053,
    -0.0030000000000000027, 0.0, 0.0030000000000000027, 0.0060000000000000053,
    0.00899999999999998, 0.012000000000000011, 0.015000000000000013,
    0.018000000000000016, 0.020999999999999991, 0.023999999999999994,
    0.026999999999999996, 0.03, 0.033, 0.035999999999999976,
    0.038999999999999979, 0.04200000000000001, 0.045000000000000012,
    0.048000000000000015, 0.05099999999999999, 0.053999999999999992,
    0.056999999999999995, 0.06, 0.063, 0.065999999999999975,
    0.068999999999999978, 0.072000000000000008, 0.075000000000000011,
    0.078000000000000014, 0.080999999999999989, 0.083999999999999991, 0.087,
    0.09, 0.093, 0.095999999999999974, 0.099, 0.10200000000000001,
    0.10500000000000001, 0.10800000000000001, 0.11099999999999996,
    0.11400000000000002, 0.11700000000000002, 0.12000000000000002,
    0.12300000000000003, 0.12599999999999997, 0.12899999999999998,
    0.13199999999999998, 0.13499999999999998, 0.13799999999999998, 0.141, 0.144,
    0.147, 0.15 },
  1.0,
  1.0,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0032000000000000058, 0.020000000000000035,
    0.051199999999999912, 0.096800000000000178, 0.15680000000000027,
    0.23120000000000004, 0.32000000000000012, 0.42319999999999974,
    0.53920000000000023, 0.64720000000000033, 0.74080000000000035,
    0.82000000000000028, 0.88479999999999981, 0.93519999999999992, 0.9712,
    0.9928, 1.0, 0.9928, 0.9712, 0.93520000000000025, 0.88479999999999981,
    0.81999999999999962, 0.74079999999999946, 0.64720000000000033,
    0.53920000000000023, 0.42320000000000024, 0.32000000000000012,
    0.23120000000000004, 0.15680000000000058, 0.096800000000000413,
    0.051199999999999912, 0.019999999999999924, 0.0031999999999999611, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 },

  { 0.0, 0.018036072144288592, 0.03807615230460925, 0.058116232464929911,
    0.078156312625250454, 0.098196392785571116, 0.11823647294589178,
    0.13827655310621242, 0.15831663326653309, 0.17835671342685364,
    0.1983967935871743, 0.21843687374749496, 0.23847695390781562,
    0.25851703406813625, 0.27855711422845691, 0.29859719438877758,
    0.31863727454909824, 0.3386773547094189, 0.35871743486973945,
    0.37875751503006011, 0.39879759519038077, 0.41883767535070132,
    0.438877755511022, 0.45891783567134264, 0.47895791583166331,
    0.49899799599198397, 0.51903807615230457, 0.53907815631262523,
    0.5591182364729459, 0.57915831663326645, 0.59919839679358711,
    0.61923847695390777, 0.63927855711422843, 0.65931863727454909,
    0.67935871743486975, 0.6993987975951903, 0.719438877755511,
    0.73947895791583163, 0.75951903807615229, 0.779559118236473,
    0.79959919839679361, 0.81963927855711416, 0.83967935871743482,
    0.85971943887775548, 0.87975951903807614, 0.8997995991983968,
    0.91983967935871747, 0.939879759519038, 0.95991983967935868,
    0.97995991983967934, 1.0, 0.98005584363781406, 0.96011168727562823,
    0.9401675309134423, 0.92022337455125636, 0.90027921818907053,
    0.88033506182688459, 0.86039090546469887, 0.840446749102513,
    0.82050259274032711, 0.80055843637814128, 0.78061428001595534,
    0.7606701236537694, 0.74072596729158358, 0.72078181092939764,
    0.7008376545672117, 0.68089349820502587, 0.66094934184283993,
    0.641005185480654, 0.62106102911846839, 0.60111687275628245,
    0.58117271639409651, 0.56122856003191068, 0.54128440366972475,
    0.52134024730753892, 0.501396090945353, 0.4814519345831671,
    0.46150777822098116, 0.44156362185879527, 0.42161946549660939,
    0.40167530913442345, 0.38173115277223757, 0.36178699641005191,
    0.341842840047866, 0.32189868368568009, 0.3019545273234942,
    0.28201037096130832, 0.26206621459912238, 0.2421220582369365,
    0.22217790187475062, 0.20223374551256471, 0.18228958915037879,
    0.16234543278819291, 0.142401276426007, 0.12245712006382133,
    0.10251296370163543, 0.082568807339449532, 0.062624650977263635,
    0.042680494615077738, 0.022736338252891838, 0.0027921818907059373 },
  1.0,
  0.5,
  2.0,
  -0.5,

  { 0.99998282571196773, 0.99997330693311282, 0.99995851262891455,
    0.99993551929220048, 0.99989978375144883, 0.99984424647461489,
    0.99975793931287171, 0.999623825055823, 0.999415447945572,
    0.99909174798174472, 0.99858904986435493, 0.99780872929986031,
    0.996598325516105, 0.9947228606225621, 0.99182186994723354,
    0.98734641023583358, 0.98046999418562208, 0.9699703419285417,
    0.95409021689258988, 0.93041489017644607, 0.89586298511486384,
    0.84697631272827689, 0.78075644228531271, 0.69616036552798044,
    0.59582041306699651, 0.4867730867159159, 0.37897055158667131,
    0.28192762008907168, 0.20166506504113582, 0.13980385912449572,
    0.094668487955585287, 0.063037114473538866, 0.041490300693449562,
    0.027095454259974391, 0.017603106553320941, 0.011397255457348054,
    0.0073628361381885945, 0.0047496659890786663, 0.0030610852166645473,
    0.00197163214672902, 0.0012694262748374034, 0.000817109501340078,
    0.00052587552703509382, 0.0003384079406554783, 0.00021775547932093546,
    0.00014011316744609673, 9.0152294523075213E-5, 5.8005193583945238E-5,
    3.7320890480684743E-5, 2.40123083155326E-5, 1.5449476331508769E-5,
    9.9401351562045127E-6, 6.3954331319011649E-6, 4.1147844168566749E-6,
    2.6474261676585342E-6, 1.7033362955671795E-6, 1.0959148150918489E-6,
    7.0510387461785E-7, 4.5365880437577823E-7, 2.918808132278889E-7,
    1.87794005966289E-7, 1.2082530186834335E-7, 7.7738121341084822E-8,
    5.0016141680084035E-8, 3.2180021341852271E-8, 2.0704391266305789E-8,
    1.3321054433127758E-8, 8.5706693068497932E-9, 5.5143061393295593E-9,
    3.5478643588317866E-9, 2.2826700552705326E-9, 1.4686532662690523E-9,
    9.4492080049694481E-10, 6.079551515336721E-10, 3.9115391050502409E-10,
    2.51665573201528E-10, 1.6191979430789675E-10, 1.0417801471350957E-10,
    6.70273748544121E-11, 4.3124924123091152E-11, 2.7746261652735716E-11,
    1.7851742382211645E-11, 1.1485680848407516E-11, 7.3898032879202754E-12,
    4.7545455384692913E-12, 3.0590399225253097E-12, 1.9681639752704342E-12,
    1.2663023470295325E-12, 8.1472969439537781E-13, 5.2419114320255251E-13,
    3.3726075838672455E-13, 2.1699111215930883E-13, 1.3961049895446555E-13,
    8.9824376788319024E-14, 5.77923488980673E-14, 3.7183175776736935E-14,
    2.3923384101973014E-14, 1.5392130847752997E-14, 9.9031847260609557E-15,
    6.3716368245923247E-15, 4.09946466187437E-15 },
  1.0,
  -0.5,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.016594960049170288, 0.03708256504814593,
    0.057570170047121567, 0.0780577750460972, 0.098545380045072836,
    0.11903298504404826, 0.13952059004302392, 0.16000819504199953,
    0.18049580004097518, 0.20098340503995082, 0.22147101003892647,
    0.24195861503790211, 0.26244622003687773, 0.2829338250358534,
    0.303421430034829, 0.32390903503380464, 0.34439664003278031,
    0.36488424503175571, 0.38537185003073132, 0.405859455029707,
    0.42634706002868261, 0.44683466502765828, 0.4673222700266339,
    0.48780987502560952, 0.50829748002458519, 0.52878508502356081,
    0.54927269002253643, 0.569760295021512, 0.59024790002048766,
    0.61073550501946328, 0.63122311001843878, 0.6517107150174144,
    0.67219832001639, 0.69268592501536563, 0.71317353001434125,
    0.73366113501331687, 0.7541487400122926, 0.77463634501126821,
    0.79512395001024383, 0.81561155500921945, 0.83609916000819506,
    0.85658676500717079, 0.87707437000614619, 0.8975619750051218,
    0.91804958000409742, 0.938537185003073, 0.95902479000204877,
    0.97951239500102438, 1.0 },
  1.0,
  -0.5,

  { 1.0, 0.97951239500102438, 0.95902479000204877, 0.938537185003073,
    0.91804958000409753, 0.89756197500512191, 0.8770743700061463,
    0.85658676500717068, 0.836099160008195, 0.81561155500921945,
    0.79512395001024383, 0.77463634501126821, 0.7541487400122926,
    0.73366113501331687, 0.71317353001434125, 0.69268592501536563,
    0.67219832001639, 0.6517107150174144, 0.63122311001843889,
    0.61073550501946317, 0.59024790002048755, 0.569760295021512,
    0.54927269002253643, 0.52878508502356081, 0.50829748002458519,
    0.48780987502560952, 0.4673222700266339, 0.44683466502765828,
    0.42634706002868261, 0.40585945502970711, 0.38537185003073143,
    0.36488424503175582, 0.3443966400327802, 0.32390903503380453,
    0.30342143003482891, 0.2829338250358534, 0.26244622003687773,
    0.24195861503790211, 0.22147101003892647, 0.20098340503995082,
    0.18049580004097518, 0.16000819504199967, 0.13952059004302403,
    0.11903298504404837, 0.098545380045072725, 0.0780577750460971,
    0.057570170047121449, 0.03708256504814593, 0.016594960049170288, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,
  -0.5,

  { 2.5944115508991425E-15, 4.0323919192654676E-15, 6.2673882965569864E-15,
    9.7411553356586E-15, 1.5140294933626139E-14, 2.3531965437207112E-14,
    3.6574809127928009E-14, 5.6846788523207947E-14, 8.8354729455983159E-14,
    1.3732628385951394E-13, 2.1344084640153051E-13, 3.3174271983654067E-13,
    5.1561467272999318E-13, 8.0139962337509031E-13, 1.2455839414832728E-12,
    1.9359621717147438E-12, 3.0089899247142721E-12, 4.6767547937195215E-12,
    7.2688961903504257E-12, 1.1297759698021835E-11, 1.7559663923032038E-11,
    2.7292295581641073E-11, 4.2419342498613541E-11, 6.5930717063243948E-11,
    1.0247352260490461E-10, 1.5927056920634294E-10, 2.4754798673525712E-10,
    3.8475410767377352E-10, 5.9800818949460018E-10, 9.2946062830225173E-10,
    1.4446241282003597E-9, 2.2453225103195035E-9, 3.4898165375311344E-9,
    5.4240846921773141E-9, 8.4304416578827064E-9, 1.3103104111010259E-8,
    2.0365639650536953E-8, 3.1653513029593095E-8, 4.919781052983558E-8,
    7.6466221462693361E-8, 1.1884843803900712E-7, 1.8472144461063383E-7,
    2.8710525284327224E-7, 4.4623634092024377E-7, 6.9356743710844579E-7,
    1.0779841975262851E-6, 1.6754674748956309E-6, 2.6041108359864378E-6,
    4.0474612949887307E-6, 6.2907959226033689E-6, 9.7775027973380829E-6,
    1.5196706009655004E-5, 2.361944401076834E-5, 3.67102930505644E-5,
    5.7056204933206436E-5, 8.867741281688539E-5, 0.00013782104396652735,
    0.00021419347061321219, 0.00033287297571781368, 0.00051727594844028061,
    0.0008037512388415106, 0.0012486826921770864, 0.0019394361626281,
    0.00301115256404052, 0.0046723181703951476, 0.0072432428229846331,
    0.011212871978497534, 0.017320084475130563, 0.026663956882820087,
    0.040839186852371728, 0.062069759694704088, 0.09326404146403551,
    0.13783175381926957, 0.19902223002858538, 0.27860000813114494,
    0.37509585421885244, 0.48265279864907579, 0.591841512112312,
    0.6926597236054578, 0.77791953691935489, 0.8448259622815556,
    0.89431388877055518, 0.92933923290363585, 0.953362191554043,
    0.96948608560920824, 0.98015158986628625, 0.987138643874805,
    0.99168696994748318, 0.99463555426425332, 0.99654193946737435,
    0.99777236201896713, 0.99856561450582726, 0.99907665453204453,
    0.99940573058415261, 0.99961757034730347, 0.9997539139901559,
    0.99984165616044418, 0.99989811697551434, 0.99993444682342936,
    0.9999578225783311, 0.9999728629463539 },
  1.0,
  -0.5,
  1.0,
  -0.5,
  1.0,
  -0.5,
  1.0,
  -0.5,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0072000000000000128, 0.028800000000000051,
    0.064799999999999719, 0.11520000000000021, 0.18000000000000033,
    0.25920000000000049, 0.35279999999999967, 0.46079999999999977,
    0.57679999999999976, 0.67999999999999994, 0.76879999999999993,
    0.84319999999999939, 0.90319999999999956, 0.94880000000000009,
    0.98000000000000009, 0.9968, 0.9992, 0.98720000000000008, 0.9608000000000001,
    0.92, 0.8648, 0.79520000000000068, 0.71120000000000072, 0.61279999999999979,
    0.49999999999999978, 0.38719999999999971, 0.2888000000000005,
    0.20480000000000037, 0.13520000000000024, 0.08000000000000014,
    0.039200000000000068, 0.0128000000000002, 0.00080000000000000145, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,
  -0.5,
  1.0,
  -0.5,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.00080000000000000145, 0.012800000000000023, 0.039200000000000068,
    0.08000000000000014, 0.13520000000000024, 0.20480000000000037,
    0.28880000000000011, 0.38720000000000021, 0.50000000000000022,
    0.61280000000000023, 0.71120000000000028, 0.79520000000000035, 0.8648, 0.92,
    0.96079999999999988, 0.98720000000000008, 0.9992, 0.9968, 0.98,
    0.94880000000000009, 0.90319999999999978, 0.84319999999999973,
    0.76879999999999993, 0.67999999999999994, 0.5768000000000002,
    0.46079999999999977, 0.35279999999999967, 0.25919999999999965,
    0.17999999999999966, 0.11520000000000021, 0.064800000000000121,
    0.028800000000000051, 0.0072000000000000128, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,
  -0.5,

  { -0.5, -0.49, -0.48, -0.47, -0.46, -0.45, -0.44, -0.43, -0.42,
    -0.41000000000000003, -0.4, -0.39, -0.38, -0.37, -0.36, -0.35,
    -0.33999999999999997, -0.32999999999999996, -0.32, -0.31, -0.3,
    -0.29000000000000004, -0.28, -0.27, -0.26, -0.25, -0.24,
    -0.22999999999999998, -0.21999999999999997, -0.21000000000000002, -0.2,
    -0.19, -0.18, -0.16999999999999998, -0.15999999999999998,
    -0.15000000000000002, -0.14, -0.13, -0.12, -0.10999999999999999,
    -0.099999999999999978, -0.090000000000000024, -0.080000000000000016, -0.07,
    -0.06, -0.049999999999999989, -0.03999999999999998, -0.030000000000000027,
    -0.020000000000000018, -0.010000000000000009, 0.0, 0.010000000000000009,
    0.020000000000000018, 0.030000000000000027, 0.040000000000000036,
    0.050000000000000044, 0.060000000000000053, 0.069999999999999951,
    0.07999999999999996, 0.089999999999999969, 0.099999999999999978,
    0.10999999999999999, 0.12, 0.13, 0.14, 0.15000000000000002,
    0.16000000000000003, 0.17000000000000004, 0.18000000000000005,
    0.18999999999999995, 0.19999999999999996, 0.20999999999999996,
    0.21999999999999997, 0.22999999999999998, 0.24, 0.25, 0.26, 0.27, 0.28,
    0.29000000000000004, 0.30000000000000004, 0.31000000000000005,
    0.31999999999999995, 0.32999999999999996, 0.33999999999999997, 0.35, 0.36,
    0.37, 0.38, 0.39, 0.4, 0.41000000000000003, 0.42000000000000004,
    0.43000000000000005, 0.43999999999999995, 0.44999999999999996,
    0.45999999999999996, 0.47, 0.48, 0.49, 0.5 },
  0.0,

  { 0.0, 0.0 },
  1.0,
  0.0,
  0.0,
  0.0,
  0.65,
  -0.65,
  0.0,
  0.65,
  -0.65,
  0.1208304866765305,
  0.020168080785264393,
  2.0,
  0.0,
  0.1208304866765305,
  0.020168080785264393,
  2.0,
  0.0,
  0.0,
  1.0,
  0U,
  1,
  1
};