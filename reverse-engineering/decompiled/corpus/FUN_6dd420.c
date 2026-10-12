/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6dd420; label: FUN_006dd420
 */

uint FUN_006dd420(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x1c;
  if (DAT_00827620 != 0) {
    uVar1 = 5;
  }
  iVar2 = SHGetFolderPathA(0,uVar1,0,0,&DAT_02975d70);
  return (iVar2 < 0) - 1 & 0x2975d70;
}

