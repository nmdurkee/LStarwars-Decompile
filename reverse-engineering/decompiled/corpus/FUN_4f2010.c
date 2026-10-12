/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f2010; label: FUN_004f2010
 */

int FUN_004f2010(char *param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar4 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar3 = iVar3 + 1;
    bVar2 = param_1[iVar4 + 1];
    iVar5 = iVar4;
    while ((iVar4 = iVar5 + 1, 0x7f < bVar2 && (bVar2 < 0xc0))) {
      bVar2 = param_1[iVar5 + 2];
      iVar5 = iVar4;
    }
    cVar1 = param_1[iVar4];
  }
  return iVar3;
}

