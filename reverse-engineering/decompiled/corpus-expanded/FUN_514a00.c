/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x514a00; label: FUN_00514a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514a00(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)))) {
    fVar1 = (float10)FUN_005becc0(param_3 + 0x14c,param_5 + 0x10,local_c);
    return fVar1;
  }
  return (float10)3.4028235e+38;
}

