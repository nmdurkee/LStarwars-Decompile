/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45e030; label: FUN_0045e030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045e030(int param_1,int param_2,int param_3)

{
  float fVar1;
  undefined4 uVar2;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  if (((param_3 != 0) && (0 < *(int *)(param_1 + 0x14))) && (*(char *)(param_2 + 0xbb) != '\0')) {
    fVar1 = *(float *)(param_1 + 0x18);
    if (0.5 <= *(float *)(param_1 + 0x18)) {
      if (fVar1 < 3.5) goto LAB_0045e095;
      fVar1 = *(float *)(param_1 + 0x18) - 3.5;
      fVar1 = 1.0 - (fVar1 + fVar1);
    }
    else {
      fVar1 = fVar1 + fVar1;
    }
    if (0.0 < fVar1) {
LAB_0045e095:
      uVar2 = FUN_006e6b90();
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880708 * 4),(float)extraout_ST0,
                   _DAT_007f821c,(float)extraout_ST1,_DAT_00876dd0,_DAT_00876dd0,_DAT_00876dd0,0,
                   DAT_007fa4c8,DAT_007fa4cc,DAT_0087a774,0x3fd9999a,1,0,0,uVar2);
      return;
    }
  }
  return;
}

