/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f75f0; label: FUN_004f75f0
 */

int FUN_004f75f0(int param_1,uint param_2)

{
  int iVar1;
  size_t sVar2;
  size_t _Size;
  uint uVar3;
  longlong lVar4;
  undefined1 local_15;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_4;
  
  local_15 = 0xfe;
  local_14 = 0;
  lVar4 = FUN_004f6d10(param_1);
  local_c = (int)param_2 >> 0x1f;
  local_10 = param_2;
  if ((param_2 & (uint)lVar4) == 0 && (local_c & (uint)((ulonglong)lVar4 >> 0x20)) == 0) {
    return 0;
  }
  do {
    uVar3 = (uint)(lVar4 + 1);
    local_4 = (uint)((ulonglong)(lVar4 + 1) >> 0x20);
    local_14 = local_14 + 1;
    if (param_1 < 0x1000) {
      if (param_1 < 0x400) {
        FUN_004ff3f0(param_1 + -1,&local_15,1);
      }
      else {
        iVar1 = param_1 * 5 + -0x1400;
        sVar2 = (*(int *)(&DAT_02983744 + iVar1 * 4) - (int)*(void **)(&DAT_02983748 + iVar1 * 4)) +
                1;
        _Size = 1;
        if ((0 < (int)sVar2) || (_Size = sVar2, sVar2 != 0)) {
          _memcpy(*(void **)(&DAT_02983748 + iVar1 * 4),&local_15,_Size);
          *(size_t *)(&DAT_02983748 + iVar1 * 4) = *(int *)(&DAT_02983748 + iVar1 * 4) + _Size;
        }
      }
    }
    else {
      FUN_006dee60(param_1 + -0x1000,&local_15,1,0);
    }
    lVar4 = CONCAT44(local_4,uVar3);
  } while ((local_10 & uVar3) != 0 || (local_c & local_4) != 0);
  return local_14;
}

