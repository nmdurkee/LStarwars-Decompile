/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62e6c0; label: FUN_0062e6c0
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

