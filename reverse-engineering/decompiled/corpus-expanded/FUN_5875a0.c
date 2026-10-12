/* Ghidra pseudocode, not original source.
 * ev_aa81935a86a90d95efe1cd13896fafaf1f7525855a34f109f6da8479aa997be3
 * Entry: 0x5875a0; label: FUN_005875a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005875a0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_0057a240(*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00954400 + 0x42) = uVar1;
    if ((*(short *)(DAT_00954400 + 0x42) == -1) && (DAT_009553c8 != 0)) {
      iVar2 = FUN_00579f60(*(undefined4 *)(param_1 + 0x510),3);
      if (iVar2 != 0) {
        uVar1 = FUN_0057a240(*(undefined4 *)(param_1 + 0x510));
        *(undefined2 *)(DAT_00954400 + 0x42) = uVar1;
        FUN_004f1e80(*(undefined4 *)(param_1 + 0x510),&DAT_00763618);
        FUN_00579f60(*(undefined4 *)(param_1 + 0x510),3);
      }
    }
  }
  return;
}

