/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x515160; label: FUN_00515160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00515160(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  if ((((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0xe4), iVar1 != 0)) &&
      (*(int *)(param_3 + 0xd0) != 0)) &&
     (((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa0), param_5 != 0)) &&
      ((*(int *)(param_5 + 0x38) != 0 &&
       (uVar2 = 1 << ((byte)(param_5 - *(int *)(*(int *)(param_5 + 0x38) + 0x38) >> 6) & 0x1f),
       (uVar2 & *(uint *)(iVar1 + 0x2b0)) != 0 ||
       ((int)uVar2 >> 0x1f & *(uint *)(iVar1 + 0x2b4)) != 0)))))) {
    return (float10)1;
  }
  return (float10)0;
}

