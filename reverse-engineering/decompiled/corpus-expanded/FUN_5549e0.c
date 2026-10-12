/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x5549e0; label: FUN_005549e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005549e0(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  float *pfVar7;
  
  if ((((in_EAX != 0) && (*(int *)(in_EAX + 0x68) != 0)) &&
      (iVar1 = *(int *)(in_EAX + 0x6c), iVar1 != 0)) && (iVar2 = *(int *)(iVar1 + 0x10), iVar2 != 0)
     ) {
    iVar6 = *(byte *)(in_EAX + 0xa4) - 1;
    iVar5 = 0;
    fVar3 = (*(float *)(iVar1 + 0x1c) - *(float *)(iVar1 + 0x18)) + 1.0;
    fVar4 = fVar3 / 40.0;
    if (0 < iVar6) {
      pfVar7 = (float *)(in_EAX + 0x2e0);
      do {
        if ((*(float *)(iVar2 + 0x4c) < *pfVar7 + fVar4) &&
           (*pfVar7 - fVar4 < *(float *)(iVar2 + 0x4c))) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
        pfVar7 = pfVar7 + 1;
      } while (iVar5 < iVar6);
    }
    if ((*(float *)(iVar2 + 0x4c) < fVar4 + fVar3) && (fVar3 - fVar4 < *(float *)(iVar2 + 0x4c))) {
      return iVar6;
    }
  }
  return -1;
}

