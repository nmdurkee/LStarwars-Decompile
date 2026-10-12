/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a4450; label: FUN_005a4450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a4450(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_2 + 0x24;
  uVar2 = FUN_005cffb0(iVar4);
  uVar2 = FUN_0067c760(uVar2);
  *(undefined4 *)(param_2 + 0x34) = uVar2;
  FUN_00553610(iVar4,0x3f800000);
  *(uint *)(param_2 + 200) = *(uint *)(param_2 + 200) & 0xfdfc70f2;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined1 *)(param_2 + 0xd0) = 0;
  iVar3 = FUN_005cfac0(iVar4);
  if (iVar3 == 0) {
    *(undefined4 *)(param_2 + 0xb0) = DAT_0095de88;
    *(undefined4 *)(param_2 + 0xb4) = DAT_0095de8c;
    *(undefined4 *)(param_2 + 0xb8) = DAT_0095de90;
    *(undefined4 *)(param_2 + 0xbc) = DAT_0095de88;
    *(undefined4 *)(param_2 + 0xc0) = DAT_0095de8c;
    *(undefined4 *)(param_2 + 0xc4) = DAT_0095de90;
    *(undefined4 **)(param_2 + 0x58) = &DAT_0095de88;
  }
  else {
    FUN_005d0130(iVar4,param_2 + 0xb0,param_2 + 0xbc);
    iVar4 = FUN_005d0370(iVar4);
    *(undefined4 **)(param_2 + 0x58) = (undefined4 *)(iVar4 + 0x30);
    if (((*(uint *)(param_2 + 200) & 0x7000) != 0) && (DAT_0095de94 == 0)) {
      puVar1 = *(undefined4 **)(param_2 + 0x54);
      *(undefined4 *)(iVar4 + 0x30) = *puVar1;
      *(undefined4 *)(iVar4 + 0x34) = puVar1[1];
      *(undefined4 *)(iVar4 + 0x38) = puVar1[2];
      return;
    }
  }
  return;
}

