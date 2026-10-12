/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f2050; label: FUN_004f2050
 */

void FUN_004f2050(char *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  if (param_2 == 0) {
    return;
  }
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return;
    }
    iVar5 = iVar5 + 1;
    bVar2 = param_1[iVar3 + 1];
    iVar4 = iVar3;
    while ((iVar3 = iVar4 + 1, 0x7f < bVar2 && (bVar2 < 0xc0))) {
      bVar2 = param_1[iVar4 + 2];
      iVar4 = iVar3;
    }
    if (param_2 == iVar5) break;
    cVar1 = param_1[iVar3];
  }
  return;
}

