/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d6fd0; label: FUN_004d6fd0
 */

void FUN_004d6fd0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != 0) {
    DAT_00881c38 = 0;
    iVar1 = *(int *)(param_1 + 0x4688);
    if (iVar1 != 0) {
      DAT_00881c38 = FUN_0041a360(0x100000,0xffffffff,0,0);
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x468c)) {
        piVar2 = (int *)(iVar1 + 0x5c);
        do {
          iVar1 = *piVar2;
          if ((iVar1 != 0) && (*(char *)(iVar1 + 0x7b5) == -1)) {
            *(uint *)(iVar1 + 0x7bc) = *(uint *)(iVar1 + 0x7bc) & 0xffffffdf;
            *(ushort *)(piVar2 + 3) = *(ushort *)(piVar2 + 3) & 0xfeff;
            *(undefined4 *)(*piVar2 + 0x798) = 0;
            *piVar2 = 0;
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 0x1f;
        } while (iVar3 < *(int *)(param_1 + 0x468c));
      }
    }
  }
  return;
}

