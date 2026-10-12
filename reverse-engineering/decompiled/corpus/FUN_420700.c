/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x420700; label: FUN_00420700
 */

void FUN_00420700(int param_1,float param_2,float param_3,float *param_4,float *param_5)

{
  float fVar1;
  ushort uVar2;
  
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    uVar2 = FUN_005d0b40(param_1,0x4d);
    if (uVar2 != 0xffff) {
      *param_4 = (param_2 * 7.0) / *(float *)(*(int *)(param_1 + 0x34) + 8 + (uint)uVar2 * 0xc);
      *param_5 = (param_3 * 18.0) / *(float *)(param_1 + 0x14);
      return;
    }
    fVar1 = (param_3 * 18.0) / *(float *)(param_1 + 0x14);
    *param_5 = fVar1;
    *param_4 = fVar1 / param_3;
  }
  return;
}

