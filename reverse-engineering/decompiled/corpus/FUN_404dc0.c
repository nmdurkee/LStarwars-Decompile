/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x404dc0; label: FUN_00404dc0
 */

void FUN_00404dc0(void)

{
  short *psVar1;
  int iVar2;
  undefined1 local_40 [64];
  
  psVar1 = &DAT_00854944;
  iVar2 = 8;
  do {
    if ((*(char *)((int)psVar1 + -0x2f) != '\0') &&
       (*(char *)(*psVar1 * 0x10 + 0xe + *(int *)(PTR_DAT_00802c54 + 0x2ac0)) != '\0')) {
      FUN_005b4500(local_40,psVar1 + -0x24);
      FUN_005f33b0(*psVar1 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0),local_40);
    }
    psVar1 = psVar1 + 0x5a;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

