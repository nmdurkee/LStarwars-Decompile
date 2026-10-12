/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x627f40; label: FUN_00627f40
 */

undefined4 FUN_00627f40(undefined4 param_1)

{
  int *piVar1;
  int in_EAX;
  uint uVar2;
  int unaff_EDI;
  
  if ((in_EAX != 0) && (*(short *)(in_EAX + 0x158) != 0)) {
    if ((*(uint *)(unaff_EDI + 0x78) & 0x4000) != 0) {
      FUN_00619d10();
    }
    if ((*(uint *)(unaff_EDI + 0x78) & 0x1000) != 0) {
      piVar1 = (int *)(in_EAX + 0x150);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 0) {
        *(uint *)(in_EAX + 0x150) = (-(uint)((*(byte *)(in_EAX + 0x164) & 2) != 0) & 2) + 3;
      }
    }
    if ((*(uint *)(unaff_EDI + 0x78) & 0x8000) != 0) {
      FUN_00619d40();
    }
    if ((*(uint *)(unaff_EDI + 0x78) & 0x2000) != 0) {
      FUN_00619d70();
    }
    if (((*(byte *)(unaff_EDI + 0x78) & 0x10) != 0) && (*(code **)(in_EAX + 0x15c) != (code *)0x0))
    {
      (**(code **)(in_EAX + 0x15c))(param_1);
    }
    if (((byte)*(undefined4 *)(unaff_EDI + 0x70) & 0xc) == 0xc) {
      FUN_00619e00();
    }
    if ((((byte)*(undefined4 *)(unaff_EDI + 0x70) & 3) == 3) &&
       ((*(byte *)(in_EAX + 0x164) & 2) != 0)) {
      FUN_004f1f40(&DAT_02912ed8,in_EAX + 0x4c,0x40);
      *(undefined1 *)(in_EAX + 0x8b) = 0;
    }
    if ((*(byte *)(unaff_EDI + 0x78) & 4) != 0) {
      uVar2 = *(int *)(in_EAX + 0x154) - 1;
      *(uint *)(in_EAX + 0x154) = uVar2 & ((int)uVar2 < 0) - 1;
    }
    if ((*(byte *)(unaff_EDI + 0x78) & 8) != 0) {
      FUN_00619ee0();
    }
    if ((*(byte *)(unaff_EDI + 0x78) & 0x40) != 0) {
      FUN_00619e60(*(undefined1 *)
                    ((&DAT_02912118)[*(int *)(in_EAX + 0x150)] + *(int *)(in_EAX + 0x14c)));
    }
    if ((*(byte *)(unaff_EDI + 0x78) & 0x80) != 0) {
      FUN_00619f20();
    }
    if ((*(byte *)(unaff_EDI + 0x78) & 0x20) != 0) {
      FUN_00619f70();
    }
    return 1;
  }
  if ((*(byte *)(unaff_EDI + 0x78) & 0x40) != 0) {
    FUN_00627e60(param_1);
  }
  return 0;
}

