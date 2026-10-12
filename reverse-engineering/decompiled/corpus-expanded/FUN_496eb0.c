/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496eb0; label: FUN_00496eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496eb0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  float10 fVar6;
  
  iVar5 = 0;
  iVar4 = DAT_0087b884;
  fVar1 = _DAT_007fafec;
  fVar3 = _DAT_007faff0;
  if (*(char *)(unaff_EDI + 0x1c) != '\0') {
    do {
      if (iVar5 < iVar4) {
        fVar2 = (0.0 - fVar1) - (float)(iVar4 - iVar5) * fVar3;
      }
      else if (iVar5 == iVar4) {
        fVar2 = 0.0;
      }
      else {
        fVar2 = fVar1 + 0.0 + (float)(iVar5 - iVar4) * fVar3;
      }
      (&DAT_0087b830)[iVar5] = fVar2;
      if (param_1 == 0) {
        fVar6 = (float10)FUN_0054fb40((&DAT_0087b7e0)[iVar5],fVar2,0x40a00000);
        iVar4 = DAT_0087b884;
        (&DAT_0087b7e0)[iVar5] = (float)fVar6;
        fVar3 = _DAT_007faff0;
        fVar1 = _DAT_007fafec;
      }
      else {
        (&DAT_0087b7e0)[iVar5] = fVar2;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(byte *)(unaff_EDI + 0x1c));
  }
  return;
}

