/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a4010; label: FUN_006a4010
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

