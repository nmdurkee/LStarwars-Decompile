/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515290; label: FUN_00515290
 */

float10 FUN_00515290(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float local_c [2];
  float local_4;
  
  if ((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) {
    iVar1 = *(int *)(param_3 + 0xd0);
    local_c[0] = *(float *)(*(int *)(param_3 + 0xe4) + 0x5c) - *(float *)(iVar1 + 0x5c);
    local_4 = *(float *)(*(int *)(param_3 + 0xe4) + 100) - *(float *)(iVar1 + 100);
    FUN_005b3620(local_c,local_c,-(uint)*(ushort *)(iVar1 + 0x27a));
    iVar1 = FUN_005be2d0(local_c[0],local_4);
    return (float10)((float)iVar1 * 0.005493164);
  }
  return (float10)-180.0;
}

