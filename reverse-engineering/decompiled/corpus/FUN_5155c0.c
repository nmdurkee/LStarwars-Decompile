/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x5155c0; label: FUN_005155c0
 */

float10 FUN_005155c0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if ((((param_3 != 0) && (param_1 != 0)) && (*(int *)(param_1 + 0x138c) != 0)) &&
     ((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)))) {
    fVar1 = (float10)FUN_005becc0(*(int *)(param_1 + 0x138c) + 0x5c,param_5 + 0x10,local_c);
    return fVar1;
  }
  return (float10)3.4028235e+38;
}

