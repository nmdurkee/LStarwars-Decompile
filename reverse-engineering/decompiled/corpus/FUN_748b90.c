/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x748b90; label: FUN_00748b90
 */

void FUN_00748b90(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007e9300;
  in_ECX[0x81] = 0;
  in_ECX[0x82] = 0;
  FUN_00746db0(param_1,param_2);
  FUN_00748460(param_1,0x2d000);
  FUN_00740f50(param_1,0x32000);
  *(undefined1 *)(in_ECX + 1) = 0;
  return;
}

