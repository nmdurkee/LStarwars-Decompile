/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x5526c0; label: FUN_005526c0
 */

void FUN_005526c0(int *param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 != (int *)0x0) && (param_3 != (undefined4 *)0x0)) {
    iVar1 = FUN_005d0420(param_1);
    if (iVar1 == 0) {
      if ((param_4 != 0) &&
         (puVar2 = (undefined4 *)FUN_005d0370(param_1), puVar2 != (undefined4 *)0x0)) {
        for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
          *param_3 = *puVar2;
          puVar2 = puVar2 + 1;
          param_3 = param_3 + 1;
        }
      }
    }
    else {
      iVar1 = *(int *)(*(int *)(*param_1 + 0x54) + (uint)*(ushort *)(iVar1 + 0x5c) * 4);
      if (((iVar1 != 0) && (FUN_005f3390(iVar1,0,param_2,param_3), param_4 != 0)) &&
         (iVar1 = FUN_005d0370(param_1), iVar1 != 0)) {
        param_3[0xc] = *(float *)(iVar1 + 0x30) + (float)param_3[0xc];
        param_3[0xd] = *(float *)(iVar1 + 0x34) + (float)param_3[0xd];
        param_3[0xe] = *(float *)(iVar1 + 0x38) + (float)param_3[0xe];
        return;
      }
    }
  }
  return;
}

