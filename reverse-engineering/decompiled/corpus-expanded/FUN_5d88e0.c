/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d88e0; label: FUN_005d88e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d88e0(int *param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  float10 fVar2;
  undefined1 local_c [12];
  
  if (*(float *)(param_3 + *param_1 * 4) != 0.0) {
    FUN_005b3800(local_c,param_2,&DAT_00973718);
    fVar2 = (float10)FUN_005b3b00(local_c);
    fVar1 = *(float *)(param_3 + *param_1 * 4);
    while ((float)fVar2 < fVar1) {
      *param_1 = *param_1 + 1;
      fVar1 = *(float *)(param_3 + *param_1 * 4);
    }
  }
  return;
}

