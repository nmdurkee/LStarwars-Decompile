/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x627230; label: FUN_00627230
 */

void FUN_00627230(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_8;
  undefined1 local_7;
  byte local_4 [4];
  
  iVar3 = FUN_006d6940(local_4);
  if (-1 < iVar3) {
    puVar4 = &DAT_0080f5a0;
    iVar2 = DAT_0080f5a0;
    while (iVar2 != 0) {
      if (iVar2 == iVar3) {
        if ((local_4[0] & 1) == 0) {
          local_8 = *(undefined1 *)(puVar4 + 1);
        }
        else {
          local_8 = *(undefined1 *)((int)puVar4 + 5);
        }
        goto LAB_00627264;
      }
      piVar1 = puVar4 + 2;
      puVar4 = puVar4 + 2;
      iVar2 = *piVar1;
    }
    local_8 = 0;
LAB_00627264:
    local_7 = 0;
    FUN_0061f290(param_1,&local_8);
  }
  return;
}

