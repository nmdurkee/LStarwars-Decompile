/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c87f0; label: FUN_006c87f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c87f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_8 [2];
  
  if (*(int *)(in_ECX + 8) != 0) {
    iVar1 = FUN_006be380(*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3,param_4);
    if (iVar1 != 0) {
      return 1;
    }
  }
  iVar1 = FUN_006c6a10(local_8,*(undefined4 *)(in_ECX + 4),param_1,1);
  if (iVar1 != 0) {
    uVar2 = FUN_006be380(local_8[0],param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 0;
}

