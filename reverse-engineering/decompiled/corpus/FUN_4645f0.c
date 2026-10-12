/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x4645f0; label: FUN_004645f0
 */

void FUN_004645f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int local_8;
  uint local_4;
  
  iVar4 = 0;
  local_4 = 0xffffffff;
  bVar3 = 1;
  local_8 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"name=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),&DAT_00758988);
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"FALSE");
          if (iVar1 != 0) {
            bVar3 = 0;
          }
        }
        else {
          iVar2 = FUN_004f1ff0(&DAT_00757cf4);
          local_4 = FUN_004f29a0(iVar1 + 1 + iVar2);
        }
      }
      else {
        iVar2 = FUN_004f1ff0("name=");
        local_8 = FUN_00570090(PTR_DAT_00802c54,iVar1 + iVar2);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_4);
    if (local_8 != 0) {
      *(byte *)(local_8 + 0x17) =
           (bVar3 | bVar3 * '\x02') * '\x02' | *(byte *)(local_8 + 0x17) & 0x79 | bVar3 << 7;
      return;
    }
    if (-1 < (int)local_4) {
      iVar4 = **(int **)(PTR_DAT_00802c54 + 0x50b8);
      for (iVar1 = 0; (iVar4 != 0 && (iVar1 < *(int *)(*(int *)(PTR_DAT_00802c54 + 0x50b8) + 8)));
          iVar1 = iVar1 + 1) {
        if (((*(byte *)(iVar4 + 0x17) & 8) == 0) && (*(byte *)(iVar4 + 0x18) == local_4)) {
          *(byte *)(iVar4 + 0x17) =
               (bVar3 | bVar3 * '\x02') * '\x02' | *(byte *)(iVar4 + 0x17) & 0x79 | bVar3 << 7;
        }
        iVar4 = iVar4 + 0x2c;
      }
    }
  }
  return;
}

