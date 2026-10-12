/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46fb80; label: FUN_0046fb80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046fb80(int param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(param_1 + 0x5100);
  if ((piVar1 != (int *)0x0) && (iVar4 = 0, 0 < piVar1[1])) {
    iVar5 = 0;
    do {
      iVar3 = *piVar1 + iVar5;
      if ((*(float *)(*piVar1 + 0x1c + iVar5) < 0.5) &&
         (fVar2 = _DAT_00925018 + *(float *)(iVar3 + 0x1c), *(float *)(iVar3 + 0x1c) = fVar2,
         0.5 < fVar2)) {
        *(undefined4 *)(iVar3 + 0x1c) = 0x3f000000;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x2c;
    } while (iVar4 < piVar1[1]);
  }
  return;
}

