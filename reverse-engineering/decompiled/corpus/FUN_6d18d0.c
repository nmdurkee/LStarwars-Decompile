/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d18d0; label: FUN_006d18d0
 */

void FUN_006d18d0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 8) == 2) {
    FUN_006d0e70(param_1);
    FUN_006d0fe0(param_1,0);
  }
  if (*(int *)(param_1 + 8) == 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x18);
    uVar2 = FUN_006cf1e0(*(undefined4 *)(param_1 + 0x18));
    FUN_006be450(**(undefined4 **)(param_1 + 0x18),(*(undefined4 **)(param_1 + 0x18))[1],0x32,0x32,
                 10,1);
    FUN_006d0e70(param_1);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    FUN_006d0fe0(param_1,uVar2);
  }
  return;
}

