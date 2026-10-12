/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd220; label: FUN_004cd220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cd220(int param_1)

{
  undefined4 uVar1;
  float *pfVar2;
  int iVar3;
  float10 fVar4;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x5078) != 0)) &&
     (iVar3 = 0, 0 < *(int *)(param_1 + 0x507c))) {
    pfVar2 = (float *)(*(int *)(param_1 + 0x5078) + 0x28);
    do {
      if (((uint)pfVar2[5] & 4) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0x3f800000;
      }
      fVar4 = (float10)FUN_0054fad0(*pfVar2,uVar1,_DAT_00925018 * 2.5);
      *pfVar2 = (float)fVar4;
      iVar3 = iVar3 + 1;
      pfVar2 = pfVar2 + 0x1c;
    } while (iVar3 < *(int *)(param_1 + 0x507c));
  }
  return;
}

