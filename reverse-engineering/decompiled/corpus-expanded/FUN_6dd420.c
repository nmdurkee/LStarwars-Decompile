/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dd420; label: FUN_006dd420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

