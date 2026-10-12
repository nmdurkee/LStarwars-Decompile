/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x612160; label: FUN_00612160
 */

undefined4
FUN_00612160(undefined4 param_1,undefined4 param_2,int param_3,float *param_4,int param_5)

{
  float fVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_5) {
    param_3 = param_3 - (int)param_4;
    do {
      fVar1 = *(float *)(param_3 + (int)param_4) - *param_4;
      if ((*(float *)(in_ECX + 0x18) < fVar1) || (fVar1 < -*(float *)(in_ECX + 0x18))) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      param_4 = param_4 + 1;
    } while (iVar2 < param_5);
  }
  return 0;
}

