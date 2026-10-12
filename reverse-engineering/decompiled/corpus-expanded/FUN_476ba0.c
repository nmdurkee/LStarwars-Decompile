/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x476ba0; label: FUN_00476ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476ba0(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  ushort local_4;
  
  iVar8 = 0;
  puVar6 = &DAT_00879b58;
  fVar2 = _DAT_00925018;
  do {
    fVar3 = *(float *)((int)&DAT_00879b60 + iVar8) - fVar2;
    *(float *)((int)&DAT_00879b60 + iVar8) = fVar3;
    if (fVar3 <= 0.0) {
      FUN_0054fa60();
      uVar4 = FUN_006e6b90();
      *(undefined4 *)((int)&DAT_008794f0 + iVar8) = uVar4;
      iVar5 = FUN_0054fa60();
      *(float *)((int)&DAT_00879b60 + iVar8) =
           (float)iVar5 * 1.5259022e-05 + (float)iVar5 * 1.5259022e-05 + 1.0;
      fVar2 = _DAT_00925018;
    }
    piVar1 = (int *)((int)&DAT_008794f0 + iVar8);
    puVar7 = puVar6 + 1;
    iVar8 = iVar8 + 4;
    local_4 = (ushort)(int)ROUND((float)*puVar6 + (float)*piVar1 * fVar2);
    *puVar6 = local_4;
    puVar6 = puVar7;
  } while ((int)puVar7 < 0x879b60);
  return;
}

