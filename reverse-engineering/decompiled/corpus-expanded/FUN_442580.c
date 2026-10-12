/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442580; label: FUN_00442580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442580(void)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  int in_stack_00000014;
  
  if (((in_stack_00000014 != 0) && ((*(byte *)(in_stack_00000014 + 0x50) & 1) == 0)) &&
     (iVar2 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x13c) + 0x54) +
                      (uint)*(ushort *)(in_stack_00000014 + 0x5c) * 4), iVar2 != 0)) {
    fVar1 = *(float *)(in_stack_00000014 + 0x4c);
    fVar3 = (float10)FUN_005ca4b0(iVar2);
    if (fVar3 < (float10)fVar1 != (fVar3 == (float10)fVar1)) {
      return (float10)1;
    }
  }
  return (float10)0;
}

