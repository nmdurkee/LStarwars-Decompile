/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54b5a0; label: FUN_0054b5a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_0054b5a0(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return PTR_s_japanese_00802358;
  default:
    return PTR_s_english_00802340;
  case 2:
    return PTR_s_french_00802344;
  case 3:
    return PTR_s_spanish_00802350;
  case 4:
    return PTR_s_german_00802348;
  case 5:
    return PTR_s_italian_0080234c;
  case 8:
    return PTR_s_danish_00802354;
  }
}

