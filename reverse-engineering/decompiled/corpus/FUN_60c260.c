/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60c260; label: FUN_0060c260
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060c260(undefined4 param_1,int param_2)

{
  char cVar1;
  
  if ((_DAT_028572a0 & 1) == 0) {
    _DAT_028572a0 = _DAT_028572a0 | 1;
    FUN_006069a0();
    _atexit((_func_4879 *)&LAB_00750430);
  }
  FUN_005fb870(param_1,0,0);
  if ((*(short *)(param_2 + 0x14) == DAT_02857298) && (*(short *)(param_2 + 0x16) == DAT_0285729a))
  {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  FUN_006e5820(DAT_0285728c,0,*(undefined4 *)(param_2 + 8),0,-cVar1 & 2);
  return;
}

