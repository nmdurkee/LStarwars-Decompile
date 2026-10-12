/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61f440; label: FUN_0061f440
 */

bool FUN_0061f440(void)

{
  int in_EAX;
  int iVar1;
  
  if ((in_EAX != 0) &&
     ((in_EAX == *(int *)(DAT_02912e8c + 0x10) ||
      (*(int *)(in_EAX + 0x40) == *(int *)(DAT_02912e8c + 0x10))))) {
    iVar1 = (**(code **)(DAT_02912e8c + 0x18))(DAT_02912e8c);
    DAT_02912e8c = -(uint)(iVar1 != 0) & DAT_02912e8c;
  }
  return DAT_02912e8c != 0;
}

