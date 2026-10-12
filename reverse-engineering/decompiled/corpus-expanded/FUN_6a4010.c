/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a4010; label: FUN_006a4010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a4010(float param_1)

{
  int in_EAX;
  float *pfVar1;
  int iVar2;
  
  iVar2 = 7;
  pfVar1 = (float *)(in_EAX + 8);
  do {
    iVar2 = iVar2 + -1;
    pfVar1[-2] = pfVar1[-2] + param_1;
    pfVar1[-1] = pfVar1[-1] + param_1;
    *pfVar1 = *pfVar1 + param_1;
    pfVar1[1] = pfVar1[1] + param_1;
    pfVar1[2] = pfVar1[2] + param_1;
    pfVar1[3] = pfVar1[3] + param_1;
    pfVar1[4] = pfVar1[4] + param_1;
    pfVar1[5] = pfVar1[5] + param_1;
    pfVar1 = pfVar1 + 8;
  } while (iVar2 != 0);
  return;
}

