/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c8760; label: FUN_006c8760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c8760(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_8 [2];
  
  if (*(int *)(in_ECX + 8) != 0) {
    iVar1 = FUN_006be2d0(*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3,param_4);
    if (iVar1 != 0) {
      return 1;
    }
  }
  iVar1 = FUN_006c6a10(local_8,*(undefined4 *)(in_ECX + 4),param_1,1);
  if (iVar1 != 0) {
    uVar2 = FUN_006be2d0(local_8[0],param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 0;
}

