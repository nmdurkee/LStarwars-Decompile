/* Ghidra pseudocode, not original source.
 * ev_d64f82d79bd9036ef98f897f1d4209ad19800693bd01752bbb2d417690313147
 * Entry: 0x698520; label: FUN_00698520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00698520(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_02972bf8;
  iVar2 = DAT_00810da8;
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = DAT_00810dac;
    iVar2 = DAT_00810db0;
  }
  if (*(int *)(param_1 + 0x10) == -1) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0xc) + 1;
  }
  if ((iVar1 != -1) && (iVar2 != -1)) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x1c) == 0) {
      uVar3 = 2;
    }
    if ((DAT_02972bc8 != 0) && (*(int *)(DAT_02972bc8 + 8 + *(int *)(param_1 + 0xc) * 0x1c) == 0)) {
      uVar3 = uVar3 | 1;
    }
    FUN_006996b0();
    FUN_00699640(*(int *)(param_1 + 0xc) * 0x40c + 4 + DAT_02973954,*(undefined4 *)(param_1 + 0x20))
    ;
    FUN_00699690(uVar3);
  }
  return;
}

