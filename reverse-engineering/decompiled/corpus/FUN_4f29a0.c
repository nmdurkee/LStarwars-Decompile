/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f29a0; label: FUN_004f29a0
 */

int FUN_004f29a0(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  cVar1 = *param_1;
  iVar4 = 0;
  iVar2 = 0;
  pcVar3 = param_1 + 1;
  if (cVar1 == '-') {
    cVar1 = *pcVar3;
    iVar2 = -1;
    pcVar3 = param_1 + 2;
  }
  while (('/' < cVar1 && (cVar1 < ':'))) {
    iVar4 = cVar1 + -0x30 + iVar4 * 10;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  }
  if (iVar2 != 0) {
    return iVar2 * iVar4;
  }
  return iVar4;
}

