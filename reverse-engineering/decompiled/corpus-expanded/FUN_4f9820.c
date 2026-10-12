/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f9820; label: FUN_004f9820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004f9820(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  if (DAT_00915fac == 0) {
    uVar3 = DAT_0297e024 >> 0x10;
    FUN_004f5d00(0x10);
    DAT_00915fac = uVar3;
    FUN_004f9570(0x13,5,3);
    FUN_004f96b0();
    FUN_004f9570(0xe,4,0xffffffff);
  }
  DAT_00915fac = DAT_00915fac - 1;
  uVar3 = (uint)*(ushort *)((int)&DAT_00913fa8 + (DAT_0297e024 >> 0x14) * 2);
  if (0x1fd < uVar3) {
    uVar2 = 0x80000;
    do {
      if ((uVar2 & DAT_0297e024) == 0) {
        uVar1 = *(ushort *)(&DAT_02982740 + uVar3 * 2);
      }
      else {
        uVar1 = *(ushort *)(&DAT_02982f40 + uVar3 * 2);
      }
      uVar3 = (uint)uVar1;
      uVar2 = uVar2 >> 1;
    } while (0x1fd < uVar3);
  }
  FUN_004f5d00((&DAT_0090f598)[uVar3]);
  return uVar3;
}

