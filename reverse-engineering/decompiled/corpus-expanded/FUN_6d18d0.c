/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d18d0; label: FUN_006d18d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

