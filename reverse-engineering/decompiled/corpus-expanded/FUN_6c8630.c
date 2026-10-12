/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c8630; label: FUN_006c8630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_006c8630(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8 [2];
  
  iVar1 = FUN_006c6a10(local_8,param_1,param_2,1);
  if (iVar1 != 0) {
    uVar2 = FUN_006be2d0(local_8[0],param_2,param_3,param_4,param_5);
    return uVar2;
  }
  return 0;
}

