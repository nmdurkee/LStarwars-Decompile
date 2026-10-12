/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x552820; label: FUN_00552820
 */

float10 FUN_00552820(int *param_1)

{
  int iVar1;
  float10 fVar2;
  undefined4 local_4;
  
  local_4 = 0.0;
  iVar1 = FUN_005d0420(param_1);
  if ((iVar1 != 0) &&
     (*(int *)(*(int *)(*param_1 + 0x54) + (uint)*(ushort *)(iVar1 + 0x5c) * 4) != 0)) {
    fVar2 = (float10)FUN_005e9650(param_1);
    fVar2 = (float10)((*(float *)(iVar1 + 0x4c) - 1.0) / ((float)fVar2 - 1.0));
    if ((float10)0 <= fVar2) {
      if ((float10)1 < fVar2) {
        return (float10)(float)(float10)1;
      }
      return fVar2;
    }
    local_4 = (float)(float10)0;
  }
  return (float10)local_4;
}

