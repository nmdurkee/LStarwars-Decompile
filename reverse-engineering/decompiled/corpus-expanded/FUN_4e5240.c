/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e5240; label: FUN_004e5240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e5240(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  float10 fVar5;
  int local_10 [4];
  
  local_10[2] = 0;
  local_10[3] = 0;
  local_10[0] = 0;
  local_10[1] = 0;
  if (DAT_00951b50 == 0) {
    cVar1 = FUN_006e6b90();
    *DAT_00889638 = cVar1;
  }
  if ((DAT_0087a7f0 == 0) && (*DAT_00889638 == '\0')) {
    DAT_0087a7f0 = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"WASHER_1");
  }
  if ((DAT_0087a7f4 == 0) && (*DAT_00889638 == '\0')) {
    DAT_0087a7f4 = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"WASHER_2");
  }
  piVar3 = &DAT_0087aad8;
  iVar4 = 0;
  do {
    iVar2 = FUN_005d0420(piVar3);
    *(int *)((int)local_10 + iVar4 + 8) = iVar2;
    if (iVar2 != 0) {
      *(undefined4 *)((int)local_10 + iVar4) =
           *(undefined4 *)(*(int *)(*piVar3 + 0x54) + (uint)*(ushort *)(iVar2 + 0x5c) * 4);
    }
    iVar2 = local_10[0];
    piVar3 = piVar3 + 3;
    iVar4 = iVar4 + 4;
  } while ((int)piVar3 < 0x87aaf0);
  if ((local_10[0] != 0) && (local_10[1] != 0)) {
    iVar4 = FUN_005cfd60(&DAT_0087aad8);
    if (iVar4 != 0) {
      _DAT_00876cc4 = (float)*(undefined4 *)(local_10[2] + 0x4c);
      return;
    }
    iVar4 = FUN_005cfd60(&DAT_0087aae4);
    if (iVar4 != 0) {
      fVar5 = (float10)FUN_005ca4b0(iVar2);
      _DAT_00876cc4 = (float)(fVar5 + (float10)*(float *)(local_10[3] + 0x4c));
      return;
    }
    _DAT_00876cc4 = 0.0;
  }
  return;
}

