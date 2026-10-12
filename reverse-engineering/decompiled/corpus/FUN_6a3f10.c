/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a3f10; label: FUN_006a3f10
 */

void FUN_006a3f10(void)

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
    if (pfVar2[-3] < pfVar1[-1]) {
      pfVar1[-1] = pfVar2[-3];
    }
    if (*(float *)((in_EAX - in_ECX) + (int)pfVar1) < *pfVar1) {
      *pfVar1 = *(float *)((in_EAX - in_ECX) + (int)pfVar1);
    }
    if (pfVar2[-1] < pfVar1[1]) {
      pfVar1[1] = pfVar2[-1];
    }
    if (*pfVar2 < pfVar1[2]) {
      pfVar1[2] = *pfVar2;
    }
    pfVar1 = pfVar1 + 4;
    pfVar2 = pfVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

