/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x56aa40; label: FUN_0056aa40
 */

int FUN_0056aa40(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((-1 < param_2) && (param_2 < DAT_009507a8)) &&
     (&DAT_009507b0 + param_2 * 0x20 != (undefined *)0x0)) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x50bc)) {
      iVar3 = *(int *)(param_1 + 0x50c4) + 0xd8;
      do {
        iVar1 = FUN_004f8b10(iVar3,&DAT_009507b0 + param_2 * 0x20);
        if (iVar1 == 0) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x100;
      } while (iVar2 < *(int *)(param_1 + 0x50bc));
    }
  }
  return -1;
}

