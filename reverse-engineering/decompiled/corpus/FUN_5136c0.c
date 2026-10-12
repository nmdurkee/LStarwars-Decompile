/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x5136c0; label: FUN_005136c0
 */

void FUN_005136c0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  if (((DAT_0092221c != 0) && (uVar1 = FUN_004f9e70(param_1), uVar1 < 4)) &&
     (iVar2 = FUN_004f7fb0(param_1), iVar2 != 0)) {
    uVar3 = FUN_00513100(*(undefined4 *)(param_1 + 0x510),DAT_00922218);
    *(undefined4 *)(DAT_0092221c + 0x18 + uVar1 * 8) = uVar3;
    fVar4 = (float10)FUN_004f8100(param_1);
    *(float *)(DAT_0092221c + 0x1c + uVar1 * 8) = (float)fVar4;
  }
  return;
}

