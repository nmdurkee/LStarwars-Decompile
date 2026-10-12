/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x574ee0; label: FUN_00574ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00574ee0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 == 0) {
    return;
  }
  iVar2 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
  if (0x3f < iVar2) {
    return;
  }
  FUN_004f1f10(DAT_00951398,*(undefined4 *)(param_1 + 0x510));
  psVar3 = (short *)FUN_005d0690(*(undefined4 *)(DAT_009513b4 + 0x13c),DAT_00951398);
  puVar1 = DAT_00951398;
  *(short **)(DAT_00951398 + 0xa0) = psVar3;
  if ((psVar3 != (short *)0x0) && (3 < *psVar3)) {
    iVar2 = *(int *)(DAT_009513b4 + 0x469c);
    iVar4 = 0;
    if (0 < iVar2) {
      puVar5 = (undefined4 *)(*(int *)(DAT_009513b4 + 0x4698) + 0xa0);
      do {
        if ((short *)*puVar5 == psVar3) break;
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 0x4a;
      } while (iVar4 < iVar2);
    }
    if (iVar2 <= iVar4) goto LAB_00574f90;
  }
  *(undefined4 *)(puVar1 + 0xa0) = 0;
LAB_00574f90:
  if (*(int *)(puVar1 + 0xa0) == 0) {
    *puVar1 = 0;
  }
  return;
}

