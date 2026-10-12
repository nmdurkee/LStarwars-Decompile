/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53ded0; label: FUN_0053ded0
 */

float10 FUN_0053ded0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_0053de40(param_1,param_2,param_3);
  fVar2 = (float10)FUN_0053de40(param_1,param_4,param_5);
  return (float10)(float)((float10)(float)fVar1 / (fVar2 + (float10)(float)fVar1));
}

