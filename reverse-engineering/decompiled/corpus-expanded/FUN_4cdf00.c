/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cdf00; label: FUN_004cdf00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cdf00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x50c),"flap1");
    if (iVar1 == 0) {
      iVar1 = FUN_005cf5b0(*(undefined4 *)(DAT_00880610 + 0x13c),DAT_00880608 + 0x68,
                           *(undefined4 *)(param_1 + 0x510),1);
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)FUN_005d0330(DAT_00880608 + 0x68);
        puVar3 = (undefined4 *)(DAT_00880608 + 0xbc);
        for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
      }
    }
    else {
      iVar1 = FUN_005cf5b0(*(undefined4 *)(DAT_00880610 + 0x13c),DAT_00880608 + 0x5c,
                           *(undefined4 *)(param_1 + 0x510),1);
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)FUN_005d0330(DAT_00880608 + 0x5c);
        puVar3 = (undefined4 *)(DAT_00880608 + 0x7c);
        for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        return;
      }
    }
  }
  return;
}

