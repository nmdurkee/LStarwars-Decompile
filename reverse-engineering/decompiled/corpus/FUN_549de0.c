/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x549de0; label: FUN_00549de0
 */

void FUN_00549de0(undefined *param_1,float param_2,undefined1 param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_008021b4;
  }
  fVar2 = ABS(param_2);
  if (*(float *)(param_1 + 0x1c8) < fVar2) {
    if (param_4 == 0) {
      *(float *)(param_1 + 0x1cc) = fVar2;
      *(float *)(param_1 + 0x1c8) = fVar2;
    }
    else {
      fVar3 = (float10)FUN_005becc0(param_1 + 0x11c,param_4,0);
      fVar1 = (float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xcd);
      if ((fVar1 <= (float)fVar3) ||
         (fVar2 = ((fVar1 - (float)fVar3) / fVar1) * fVar2, fVar2 <= *(float *)(param_1 + 0x1c8))) {
        param_1[0x229] = param_3;
        return;
      }
      *(float *)(param_1 + 0x1cc) = fVar2;
      *(float *)(param_1 + 0x1c8) = fVar2;
    }
    if (param_2 < 0.0) {
      param_1[0x228] = 1;
      param_1[0x229] = param_3;
      return;
    }
    param_1[0x228] = 0;
    param_1[0x229] = param_3;
    return;
  }
  return;
}

