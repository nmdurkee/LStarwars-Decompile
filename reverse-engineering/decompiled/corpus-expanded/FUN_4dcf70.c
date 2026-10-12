/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dcf70; label: FUN_004dcf70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dcf70(void)

{
  int iVar1;
  size_t _Size;
  float10 extraout_ST0;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_18;
  local_10 = DAT_007f1a20;
  local_e = DAT_007f1a20;
  local_c = DAT_007f1a20;
  local_a = DAT_007f1a20;
  local_8 = DAT_007f1a20;
  local_6 = DAT_007f1a20;
  local_18 = 1;
  local_17 = 1;
  local_16 = 1;
  local_15 = 1;
  local_14 = 1;
  local_13 = 1;
  if ((DAT_00882a84 == 0) || (*(float *)(DAT_00882a84 + 0x28) <= 0.0)) {
    __security_check_cookie(local_4 ^ (uint)&local_18);
    return;
  }
  iVar1 = FUN_006e6b90();
  if (6 < iVar1) {
    iVar1 = 6;
  }
  if ((DAT_00882a88 != 0) && (extraout_ST0 < (float10)*(float *)(DAT_00882a88 + 0x28))) {
    _Size = FUN_006e6b90();
    if (6 < (int)_Size) {
      _Size = 6;
    }
    if (0 < (int)_Size) {
      _memset(&local_18,0,_Size);
    }
    FUN_004baad0(&local_10,&local_18,0,iVar1);
    __security_check_cookie(local_4 ^ (uint)&local_18);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_18);
  return;
}

