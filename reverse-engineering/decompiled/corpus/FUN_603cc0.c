/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x603cc0; label: FUN_00603cc0
 */

void FUN_00603cc0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_005ed540(param_1,0);
  FUN_005db100(&DAT_0080b788);
  FUN_005c1240(&DAT_0080b888,&DAT_0080b808,&DAT_0080b788);
  puVar2 = &DAT_0080b888;
  puVar3 = &DAT_0080b848;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_006e56a0(2,&DAT_0080b708);
  FUN_006e56a0(3,&DAT_0080b748);
  return;
}

