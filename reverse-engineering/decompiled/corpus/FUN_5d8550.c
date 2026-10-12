/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d8550; label: FUN_005d8550
 */

void FUN_005d8550(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  float fVar2;
  int local_8;
  
  if (DAT_0097396c != 0) {
    local_8 = param_3;
    if ((param_1 == -1) && (param_2 == 6)) {
      fVar2 = (float)param_3;
      if (param_3 < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      local_8 = (int)(longlong)ROUND(fVar2 * 63.556);
    }
    iVar1 = (&DAT_009716a4)[param_1];
    *(int *)(*(int *)(iVar1 + (3 - *(int *)(*(int *)(iVar1 + 0x20) + param_2 * 4)) * 4) +
            param_2 * 4) = local_8;
    *(undefined4 *)(*(int *)(iVar1 + 0x24) + param_2 * 4) = param_4;
  }
  return;
}

