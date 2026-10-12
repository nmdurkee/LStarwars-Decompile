/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e9000; label: FUN_004e9000
 */

undefined4 FUN_004e9000(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_80 [32];
  
  iVar4 = 0;
  iVar1 = FUN_0051ac70(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_2);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_0051fe60(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar1);
  iVar3 = 0;
  if ('\0' < *(char *)(iVar1 + 0x10)) {
    do {
      if (0x1f < iVar4) break;
      if (*(char *)(iVar3 + *(int *)(iVar1 + 0x18)) == -1) {
        local_80[iVar4] =
             *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x28) +
             (uint)*(byte *)(*(int *)(iVar1 + 0x14) + iVar3) * 0x3c;
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(char *)(iVar1 + 0x10));
  }
  uVar2 = FUN_00440290(local_80,iVar4,param_1,DAT_0093d810 + 0x80,0x4e6e6b28,0,0x4e6e6b28,0x4e6e6b28
                      );
  return uVar2;
}

