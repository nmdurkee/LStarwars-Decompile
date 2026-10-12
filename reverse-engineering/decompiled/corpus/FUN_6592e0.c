/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x6592e0; label: FUN_006592e0
 */

float10 FUN_006592e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  undefined1 local_c [12];
  
  iVar1 = FUN_00617f80();
  if (iVar1 != 0) {
    FUN_005da860(local_c,(&DAT_02947c7c)[(char)(&DAT_029300e8)[param_1 * 0x2d4]],
                 (&DAT_0292fe18)[param_1 * 0xb5]);
    uVar2 = FUN_00617f80(0);
    uVar2 = FUN_005cf9c0(local_c,uVar2);
    fVar3 = (float10)FUN_005becc0(uVar2);
    return fVar3;
  }
  return (float10)0;
}

