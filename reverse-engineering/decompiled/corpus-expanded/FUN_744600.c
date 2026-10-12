/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x744600; label: FUN_00744600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00744600(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *in_ECX;
  uint uVar5;
  
  iVar1 = *in_ECX;
  uVar2 = *(uint *)(iVar1 + 0x13c);
  uVar4 = (uint)((uVar2 >> 0x12 & 1) != 0);
  uVar5 = uVar2 >> 0x10 & 1;
  if (((uVar5 != 0) || ((uVar2 & 0x20000) != 0)) && ((uVar2 & 0x400000) == 0)) {
    uVar4 = uVar4 | 2;
  }
  iVar3 = in_ECX[3];
  if (((iVar3 == 0) || (*(char *)(iVar1 + 0x1b4) != '\0')) && ((uVar2 >> 9 & 3) != 0)) {
    uVar4 = uVar4 | 4;
  }
  if (((iVar3 == 0) || (*(char *)(iVar1 + 0x1b4) != '\0')) && (1 < ((byte)(uVar2 >> 9) & 3))) {
    uVar4 = uVar4 | 8;
  }
  if (((iVar3 == 0) || (*(char *)(iVar1 + 0x1b4) != '\0')) && (2 < ((byte)(uVar2 >> 9) & 3))) {
    uVar4 = uVar4 | 0x10;
  }
  if (((uVar5 != 0) || ((uVar2 & 0x20000) != 0)) && ((uVar2 & 0x400000) != 0)) {
    uVar4 = uVar4 | 0x40;
  }
  if ((uVar2 >> 0x13 & 1) != 0) {
    uVar4 = uVar4 | 0x80;
  }
  if ((uVar2 >> 0x18 & 1) != 0) {
    uVar4 = uVar4 | 0x100;
  }
  if ((uVar2 >> 0x19 & 1) != 0) {
    uVar4 = uVar4 | 0x400;
  }
  if (iVar3 == 0) {
    if (*(int *)(iVar1 + 0x1b8) < 0) {
      uVar4 = uVar4 | 0x800;
    }
  }
  else if (*(char *)(iVar1 + 0x1b4) == '\0') {
    return uVar4;
  }
  if ((uVar2 & 0x100) != 0) {
    uVar4 = uVar4 | 0x1000;
  }
  return uVar4;
}

