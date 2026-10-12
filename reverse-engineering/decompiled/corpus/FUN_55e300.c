/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55e300; label: FUN_0055e300
 */

int FUN_0055e300(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x280);
  if ((cVar1 < '\0') || (uVar2 = (uint)cVar1, '\a' < cVar1)) {
    uVar2 = (uint)*(byte *)(param_1 + 0x28d);
  }
  uVar2 = uVar2 & 0x80000007;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
  }
  iVar3 = (&DAT_0093d5a0)[uVar2 * 4];
  if ((&DAT_0093d5a0)[uVar2 * 4] == 0) {
    iVar3 = DAT_0093d5a0;
  }
  return iVar3;
}

