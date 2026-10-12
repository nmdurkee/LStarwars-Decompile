/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5d0000; label: FUN_005d0000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005d0000(int *param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  
  iVar4 = 0;
  if (param_1[1] == 0) {
    iVar4 = param_1[2];
    if (iVar4 != 0) {
      pfVar6 = *(float **)(iVar4 + 0xbc);
      iVar7 = 0;
      fVar2 = *pfVar6;
      while (fVar2 != 0.0) {
        pfVar1 = pfVar6 + 1;
        pfVar6 = pfVar6 + 1;
        iVar7 = iVar7 + 1;
        fVar2 = *pfVar1;
      }
      return *(int *)(*(int *)(iVar4 + 0xb0) + iVar7 * 0xc);
    }
  }
  else {
    iVar7 = *(int *)(*(int *)(*param_1 + 0x18) + *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4)
    ;
    for (iVar3 = *(int *)(iVar7 + 0x4c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x4c)) {
      iVar7 = iVar3;
    }
    piVar5 = *(int **)(iVar7 + 0xc);
    if (piVar5 != (int *)0x0) {
      do {
        piVar5 = (int *)*piVar5;
        iVar4 = iVar4 + 1;
      } while (piVar5 != (int *)0x0);
      return iVar4;
    }
  }
  return 0;
}

