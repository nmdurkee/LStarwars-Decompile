/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x550fa0; label: FUN_00550fa0
 */

float10 FUN_00550fa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_00550f10(param_1,param_2,param_3);
  fVar2 = (float10)FUN_00550f10(param_1,param_4,param_5);
  return (float10)(float)((float10)(float)fVar1 / (fVar2 + (float10)(float)fVar1));
}

