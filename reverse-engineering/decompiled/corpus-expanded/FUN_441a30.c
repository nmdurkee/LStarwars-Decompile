/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441a30; label: FUN_00441a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441a30(undefined4 param_1,int param_2,float param_3,undefined4 param_4,int param_5)

{
  float10 fVar1;
  float local_10;
  undefined1 local_c [12];
  
  if (((param_3 == 0.0) || (*(int *)((int)param_3 + 0xd0) == 0)) ||
     ((param_5 == 0 && (param_5 = *(int *)(param_2 + 0xa4), param_5 == 0)))) {
    return (float10)(float)0x4e6e6b28;
  }
  param_3 = 1e+09;
  local_10 = 1e+09;
  if (DAT_0093d810 != 0) {
    fVar1 = (float10)FUN_005bed80(DAT_0093d810 + 0x5c,param_5 + 0x10,local_c);
    param_3 = (float)fVar1;
  }
  if (DAT_0093d814 != 0) {
    fVar1 = (float10)FUN_005bed80(DAT_0093d814 + 0x5c,param_5 + 0x10,local_c);
    local_10 = (float)fVar1;
  }
  if (param_3 < local_10) {
    return (float10)param_3;
  }
  return (float10)local_10;
}

