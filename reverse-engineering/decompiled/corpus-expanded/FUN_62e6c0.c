/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62e6c0; label: FUN_0062e6c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062e6c0(int param_1,float *param_2)

{
  float10 fVar1;
  float10 fVar2;
  
  if (((param_1 != 0) && (param_2 != (float *)0x0)) &&
     (*(int *)(*(int *)(param_1 + 0xc) + *(short *)((int)param_2 + 0x3a) * 4) != 0)) {
    fVar1 = (float10)FUN_005ca470(*(undefined4 *)
                                   (*(int *)(param_1 + 0xc) + *(short *)((int)param_2 + 0x3a) * 4));
    fVar2 = (float10)FUN_005b9dd0();
    *param_2 = (float)(fVar2 * (float10)(double)(fVar1 - (float10)1.0) + (float10)1.0);
  }
  return;
}

