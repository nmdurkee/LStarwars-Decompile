/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a3f90; label: FUN_006a3f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a3f90(void)

{
  int in_EAX;
  int in_ECX;
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  
  pfVar1 = (float *)(in_ECX + 4);
  pfVar2 = (float *)(in_EAX + 0xc);
  iVar3 = 0xe;
  do {
    if (pfVar1[-1] < pfVar2[-3]) {
      pfVar1[-1] = pfVar2[-3];
    }
    if (*pfVar1 < *(float *)((in_EAX - in_ECX) + (int)pfVar1)) {
      *pfVar1 = *(float *)((in_EAX - in_ECX) + (int)pfVar1);
    }
    if (pfVar1[1] < pfVar2[-1]) {
      pfVar1[1] = pfVar2[-1];
    }
    if (pfVar1[2] < *pfVar2) {
      pfVar1[2] = *pfVar2;
    }
    pfVar1 = pfVar1 + 4;
    pfVar2 = pfVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

