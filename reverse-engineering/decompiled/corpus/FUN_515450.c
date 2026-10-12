/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515450; label: FUN_00515450
 */

float10 FUN_00515450(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  
  if (((param_3 != 0) && (param_1 != 0)) && (*(int *)(param_1 + 0x138c) != 0)) {
    if (DAT_00923908 != (code *)0x0) {
      iVar1 = (*DAT_00923908)(param_1,param_3);
      if (iVar1 != 0) {
        fVar2 = (float10)FUN_005becc0(*(int *)(param_1 + 0x138c) + 0x5c,iVar1,0);
        return fVar2;
      }
    }
    if (*(byte *)(param_3 + 0x138) != 0xff) {
      fVar2 = (float10)FUN_005becc0(*(int *)(param_1 + 0x138c) + 0x5c,
                                    (uint)*(byte *)(param_3 + 0x138) * 0xa4 +
                                    *(int *)(param_1 + 0x18) + 0x20,0);
      return fVar2;
    }
  }
  return (float10)3.4028235e+38;
}

