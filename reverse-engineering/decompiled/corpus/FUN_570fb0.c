/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x570fb0; label: FUN_00570fb0
 */

void FUN_00570fb0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  piVar1 = *(int **)(param_1 + 0x5054);
  if ((piVar1 != (int *)0x0) && (PTR_PTR_008033b0[0xb] != -1)) {
    iVar3 = 0;
    if (0 < piVar1[1]) {
      puVar4 = (undefined4 *)(*piVar1 + 0x34);
      do {
        uVar2 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_008033a4,puVar4 + -3);
        *puVar4 = uVar2;
        if ((*(byte *)(puVar4 + 1) & 0x20) != 0) {
          uVar2 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),0xffffffff,puVar4 + -7);
          puVar4[-1] = uVar2;
        }
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 0xf;
      } while (iVar3 < *(int *)(*(int *)(param_1 + 0x5054) + 4));
    }
  }
  return;
}

