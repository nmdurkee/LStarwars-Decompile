/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x465c60; label: FUN_00465c60
 */

void FUN_00465c60(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = 0;
  cVar3 = '\x01';
  cVar1 = '\x01';
  if (0 < param_4) {
    do {
      cVar3 = cVar1;
      iVar2 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"FALSE");
      if (iVar2 == 0) {
        cVar3 = '\0';
      }
      else {
        iVar2 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),&DAT_00757ebc);
        if (iVar2 == 0) {
          cVar3 = '\x01';
        }
      }
      iVar4 = iVar4 + 1;
      cVar1 = cVar3;
    } while (iVar4 < param_4);
  }
  iVar4 = FUN_0055f450();
  *(int *)(iVar4 + 0x5170) = (int)cVar3;
  return;
}

