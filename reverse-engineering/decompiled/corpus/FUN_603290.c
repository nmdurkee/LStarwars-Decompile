/* Ghidra analysis pseudocode, not original source.
 * ev_f0df202184b9720525c4247b3bb30bed7ac4e9212116aa7e13e8156c499e8a94
 * Entry: 0x603290; label: FUN_00603290
 */

void FUN_00603290(undefined4 param_1,float param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  undefined1 local_8;
  
  fVar1 = param_2 * 255.0;
  fVar4 = (float10)FUN_005bfe40(0x437f0000,param_1);
  param_2 = 0.0;
  do {
    iVar2 = (int)param_2;
    fVar5 = (float10)FUN_005bfe40((float)(int)param_2,param_1);
    param_2 = (float)(fVar5 * (float10)(float)((float10)fVar1 / fVar4));
    if (255.0 < param_2) {
      param_2 = 255.0;
    }
    iVar3 = iVar2 + 1;
    local_8 = (undefined1)(int)ROUND(param_2);
    *(undefined1 *)(iVar2 + param_3) = local_8;
    param_2 = (float)iVar3;
  } while (iVar3 < 0x100);
  return;
}

