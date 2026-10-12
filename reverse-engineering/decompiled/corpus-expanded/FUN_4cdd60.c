/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cdd60; label: FUN_004cdd60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cdd60(int param_1)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 == 0) {
    return;
  }
  psVar3 = (short *)FUN_005b2110(*(undefined4 *)(DAT_00880610 + 0x13c),
                                 *(undefined4 *)(param_1 + 0x510));
  iVar2 = DAT_00880608;
  *(short **)(DAT_00880608 + 0x40) = psVar3;
  if ((psVar3 != (short *)0x0) && (*psVar3 == 4)) {
    iVar1 = *(int *)(DAT_00880610 + 0x4684);
    iVar5 = 0;
    if (0 < iVar1) {
      puVar4 = (undefined4 *)(*(int *)(DAT_00880610 + 0x4680) + 0x40);
      do {
        if ((short *)*puVar4 == psVar3) break;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 0x3f;
      } while (iVar5 < iVar1);
    }
    if (iVar1 <= iVar5) goto LAB_004cdddd;
  }
  *(undefined4 *)(iVar2 + 0x40) = 0;
LAB_004cdddd:
  if (*(int *)(iVar2 + 0x40) != 0) {
    FUN_004f1f10(iVar2,PTR_DAT_007fd1e4);
    FUN_004f1e80(DAT_00880608,*(undefined4 *)(*(int *)(DAT_00880608 + 0x40) + 4));
    FUN_0055aa60(*(undefined4 *)(DAT_00880610 + 0x2ac8),PTR_DAT_007fd1e4,DAT_00880608,DAT_00880608,
                 0x40);
  }
  return;
}

