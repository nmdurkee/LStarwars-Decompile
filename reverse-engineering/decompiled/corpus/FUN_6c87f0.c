/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c87f0; label: FUN_006c87f0
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

