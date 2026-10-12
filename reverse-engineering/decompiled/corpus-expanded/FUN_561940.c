/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x561940; label: FUN_00561940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00561940(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  _sprintf(local_24,"%i/%i",param_2,param_3);
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0x4020;
    param_1 = &DAT_0080250c;
  }
  else {
    uVar2 = 0x4023;
  }
  iVar1 = FUN_00560fa0(local_24,param_1,0x3f19999a,0,0x3f4ccccd,param_4,param_5,param_6,uVar2,
                       0x3f800000);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xd4) = param_7;
  }
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

