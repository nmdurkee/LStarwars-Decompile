/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e3440; label: FUN_004e3440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e3440(void)

{
  int iVar1;
  size_t _Size;
  float10 extraout_ST0;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_10;
  iVar1 = FUN_0058a900(DAT_009553d4);
  if (iVar1 == 0) {
    local_c = DAT_007f18f0;
    local_a = DAT_007f18f0;
    local_8 = DAT_007f18f0;
    local_10 = 1;
    local_f = 1;
    local_e = 1;
    if ((DAT_00889600 != 0) && (0.0 < *(float *)(DAT_00889600 + 0x28))) {
      iVar1 = FUN_006e6b90();
      if (3 < iVar1) {
        iVar1 = 3;
      }
      if ((DAT_00889604 != 0) && (extraout_ST0 < (float10)*(float *)(DAT_00889604 + 0x28))) {
        _Size = FUN_006e6b90();
        if (3 < (int)_Size) {
          _Size = 3;
        }
        if (0 < (int)_Size) {
          _memset(&local_10,0,_Size);
        }
        FUN_004baad0(&local_c,&local_10,0,iVar1);
        __security_check_cookie(local_4 ^ (uint)&local_10);
        return;
      }
      __security_check_cookie(local_4 ^ (uint)&local_10);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_10);
  return;
}

