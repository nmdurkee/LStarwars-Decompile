/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x627230; label: FUN_00627230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

