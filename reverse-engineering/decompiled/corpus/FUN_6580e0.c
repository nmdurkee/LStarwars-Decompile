/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x6580e0; label: FUN_006580e0
 */

void FUN_006580e0(int param_1,float param_2)

{
  char cVar1;
  int iVar2;
  
  if (((-1 < param_1) && (param_1 < DAT_02962098)) &&
     (iVar2 = *(int *)(DAT_0296209c + param_1 * 4), iVar2 != 0)) {
    *(float *)(iVar2 + 0x154) = param_2 * *(float *)(iVar2 + 0x154);
    *(float *)(iVar2 + 0x194) = *(float *)(iVar2 + 0x194) * param_2;
    *(float *)(iVar2 + 0x15c) = *(float *)(iVar2 + 0x15c) * param_2;
    *(float *)(iVar2 + 0x19c) = *(float *)(iVar2 + 0x19c) * param_2;
    *(float *)(iVar2 + 0x164) = *(float *)(iVar2 + 0x164) * param_2;
    *(float *)(iVar2 + 0x1a4) = *(float *)(iVar2 + 0x1a4) * param_2;
    *(float *)(iVar2 + 0x16c) = *(float *)(iVar2 + 0x16c) * param_2;
    *(float *)(iVar2 + 0x1ac) = *(float *)(iVar2 + 0x1ac) * param_2;
    *(float *)(iVar2 + 0x174) = *(float *)(iVar2 + 0x174) * param_2;
    *(float *)(iVar2 + 0x1b4) = *(float *)(iVar2 + 0x1b4) * param_2;
    *(float *)(iVar2 + 0x17c) = *(float *)(iVar2 + 0x17c) * param_2;
    *(float *)(iVar2 + 0x1bc) = *(float *)(iVar2 + 0x1bc) * param_2;
    *(float *)(iVar2 + 0x184) = *(float *)(iVar2 + 0x184) * param_2;
    *(float *)(iVar2 + 0x1c4) = *(float *)(iVar2 + 0x1c4) * param_2;
    *(float *)(iVar2 + 0x18c) = *(float *)(iVar2 + 0x18c) * param_2;
    *(float *)(iVar2 + 0x1cc) = *(float *)(iVar2 + 0x1cc) * param_2;
    cVar1 = *(char *)(iVar2 + 0x2c);
    *(float *)(iVar2 + 0x148) = *(float *)(iVar2 + 0x148) * param_2;
    *(float *)(iVar2 + 0x14c) = *(float *)(iVar2 + 0x14c) * param_2;
    *(float *)(iVar2 + 0x48) = *(float *)(iVar2 + 0x48) * param_2;
    *(float *)(iVar2 + 0xa0) = *(float *)(iVar2 + 0xa0) * param_2;
    if (((cVar1 == '\0') || (cVar1 == '\b')) || ((cVar1 == '\t' || (cVar1 == '\n')))) {
      *(float *)(iVar2 + 0x58) = *(float *)(iVar2 + 0x58) * param_2;
      *(float *)(iVar2 + 0x5c) = *(float *)(iVar2 + 0x5c) * param_2;
      *(float *)(iVar2 + 0x60) = param_2 * *(float *)(iVar2 + 0x60);
      *(float *)(iVar2 + 0x4c) = param_2 * *(float *)(iVar2 + 0x4c);
      *(float *)(iVar2 + 0x50) = *(float *)(iVar2 + 0x50) * param_2;
      *(float *)(iVar2 + 0x54) = param_2 * *(float *)(iVar2 + 0x54);
    }
    else if (((cVar1 == '\x06') || (cVar1 == '\a')) || ((cVar1 == '\v' || (cVar1 == '\f')))) {
      *(float *)(iVar2 + 0x58) = *(float *)(iVar2 + 0x58) * param_2;
      *(float *)(iVar2 + 0x4c) = param_2 * *(float *)(iVar2 + 0x4c);
    }
    *(float *)(iVar2 + 0xb4) = *(float *)(iVar2 + 0xb4) * param_2;
    *(float *)(iVar2 + 0xbc) = param_2 * *(float *)(iVar2 + 0xbc);
    FUN_00600260(iVar2);
  }
  return;
}

