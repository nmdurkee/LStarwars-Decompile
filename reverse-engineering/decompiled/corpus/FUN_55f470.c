/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f470; label: FUN_0055f470
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055f470(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != -1) {
    if ((param_1 != param_2) && ((*(byte *)(param_1 * 0x9c + 0x7a + DAT_00951354) & 8) != 0)) {
      PTR_DAT_00802c58 = &DAT_0093d858;
      PTR_DAT_00802c54 = &DAT_0093d858;
      if (DAT_00942b0c <= DAT_0093d960) {
        PTR_DAT_00802c54 = &DAT_0093d858;
        PTR_DAT_00802c58 = &DAT_0093d858;
        return;
      }
      iVar1 = DAT_00942b0c - _DAT_009248b4;
      DAT_00942b0c = DAT_0093d960;
      DAT_0093d960 = iVar1;
      return;
    }
    if ((*(byte *)(param_1 * 0x9c + 0x7a + DAT_00951354) & 8) != 0) {
      return;
    }
  }
  if (DAT_00942b0c < DAT_0093d960) {
    uVar2 = DAT_0093d960 + _DAT_009248b4;
    DAT_0093d960 = DAT_00942b0c;
    DAT_00942b0c = uVar2;
  }
  return;
}

