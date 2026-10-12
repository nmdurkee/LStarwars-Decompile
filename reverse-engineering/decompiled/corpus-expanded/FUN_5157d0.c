/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x5157d0; label: FUN_005157d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_005157d0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4,int param_5,
            int param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_6 != 0) && (param_5 != 0)) {
    uVar1 = FUN_00512fc0(*param_4,*(undefined4 *)(param_2 + 4));
    *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) & 0xfffffffb;
    iVar3 = 1;
    *(undefined4 *)(param_2 + 0x10) = uVar1;
    if (1 < param_5) {
      do {
        iVar2 = FUN_004f8b10(param_4[iVar3],"KeepBlockedMessages");
        if (iVar2 == 0) {
          *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) | 4;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    if (*(int *)(param_2 + 0x10) == 0) {
      if (DAT_00922248 == 1) {
        FUN_00512860(*param_4,*(undefined4 *)(*(int *)(param_2 + 4) + 8),
                     *(undefined4 *)(*(int *)(param_2 + 8) + 0x18));
        return 0;
      }
      FUN_00512850(*param_4,*(undefined4 *)(*(int *)(param_2 + 4) + 8),
                   *(undefined4 *)(*(int *)(param_2 + 8) + 0x18));
    }
  }
  return 0;
}

