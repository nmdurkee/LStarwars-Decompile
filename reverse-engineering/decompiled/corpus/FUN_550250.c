/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x550250; label: FUN_00550250
 */

void FUN_00550250(undefined4 param_1,undefined4 *param_2,undefined4 param_3,float param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *param_2;
  local_8 = param_2[1];
  local_4 = param_2[2];
  iVar2 = 3;
  do {
    FUN_005b3800(param_5,&local_c,param_1);
    fVar3 = (float10)FUN_005bec80(param_5);
    fVar1 = 0.0;
    if (((float)fVar3 != 0.0) && (param_4 != 0.0)) {
      fVar1 = (float)fVar3 / param_4;
    }
    FUN_005b3860(&local_c,param_2,param_3,fVar1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_005b3800(param_5,&local_c,param_1);
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_c;
    param_6[1] = local_8;
    param_6[2] = local_4;
  }
  return;
}

